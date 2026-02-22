#include "systemlog.h"
#include "ui_systemlog.h"
#include <QScrollBar>
#include <QFileDialog>
#include <QMessageBox>

// LogEntry 的实现
QString LogEntry::toString() const {
    QString timeStr = timestamp.toString("yyyy-MM-dd hh:mm:ss.zzz");
    QString levelStr;

    switch (level) {
        case LOG_INFO:    levelStr = "[INFO]"; break;
        case LOG_WARNING: levelStr = "[WARN]"; break;
        case LOG_ERROR:   levelStr = "[ERROR]"; break;
        case LOG_DEBUG:   levelStr = "[DEBUG]"; break;
        default:          levelStr = "[UNKNOWN]"; break;
    }

    return QString("%1 %2 %3").arg(timeStr).arg(levelStr).arg(message);
}

SystemLog::SystemLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemLog),
    m_maxLines(1000)
{
    ui->setupUi(this);

    // 【新增】注册元类型，必须在 connect 之前调用
    qRegisterMetaType<LogEntry>("LogEntry");

    // 设置标题栏图标和文字
    ui->label->setText("<img src = 'qrc:/image/文件 - 日志.png' width = '25' height = '25'> "
                       "<span style='font-size:20px; font-weight:bold;'>系统运行日志</span>");

    // 连接信号与槽，确保线程安全
    connect(this, &SystemLog::signalAppendLog, this, &SystemLog::onAppendLog, Qt::QueuedConnection);
    connect(this, &SystemLog::signalClearLogs, this, &SystemLog::onClearLogs, Qt::QueuedConnection);
    connect(this, &SystemLog::signalUpdateScroll, this, &SystemLog::onUpdateScroll, Qt::QueuedConnection);

    // 初始化列表样式
    ui->listWidget->setStyleSheet(
        "QListWidget {"
        "   background-color: #f0f0f0;"
        "   border: 1px solid #ccc;"
        "   border-radius: 5px;"
        "   font-family: 'Monospace', 'Courier New', monospace;"
        "   font-size: 12px;"
        "}"
        "QListWidget::item {"
        "   padding: 4px;"
        "   border-bottom: 1px solid #e0e0e0;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: #dceefb;"
        "   color: #333;"
        "}"
    );

    // 添加欢迎日志
    addLog("系统日志模块初始化成功...", LOG_INFO);
    addLog("等待 STM32 设备连接...", LOG_INFO);
}

SystemLog::~SystemLog()
{
    delete ui;
}

void SystemLog::addLog(const QString &message, LogLevel level)
{
    LogEntry entry;
    entry.timestamp = QDateTime::currentDateTime();
    entry.message = message;
    entry.level = level;

    emit signalAppendLog(entry);
}

void SystemLog::clearLogs()
{
    emit signalClearLogs();
}

bool SystemLog::exportLogs(const QString &filePath)
{
    QMutexLocker locker(&m_mutex);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    out << "Timestamp,Level,Message\n";

    for (const auto &entry : m_logEntries) {
        QString safeMessage = entry.message;
        safeMessage.replace(",", ";");
        safeMessage.replace("\n", " ");

        out << entry.timestamp.toString(Qt::ISODate) << ","
            << entry.level << ","
            << safeMessage << "\n";
    }

    file.close();
    return true;
}

void SystemLog::setMaxLines(int maxLines)
{
    QMutexLocker locker(&m_mutex);
    m_maxLines = maxLines;
}

void SystemLog::onAppendLog(const LogEntry &entry)
{
    QMutexLocker locker(&m_mutex);

    m_logEntries.append(entry);

    while (m_logEntries.size() > m_maxLines) {
        m_logEntries.removeFirst();
        if (ui->listWidget->count() > 0) {
            delete ui->listWidget->takeItem(0);
        }
    }

    QListWidgetItem *item = new QListWidgetItem(entry.toString());

    QColor color;
    switch (entry.level) {
        case LOG_INFO:    color = QColor("#333333"); break;
        case LOG_WARNING: color = QColor("#d35400"); break;
        case LOG_ERROR:   color = QColor("#c0392b"); break;
        case LOG_DEBUG:   color = QColor("#7f8c8d"); break;
        default:          color = QColor("#000000"); break;
    }

    item->setForeground(color);
    ui->listWidget->addItem(item);

    emit signalUpdateScroll();
}

void SystemLog::onClearLogs()
{
    QMutexLocker locker(&m_mutex);
    m_logEntries.clear();
    ui->listWidget->clear();
}

void SystemLog::onUpdateScroll()
{
    QScrollBar *scrollBar = ui->listWidget->verticalScrollBar();
    if (scrollBar) {
        scrollBar->setValue(scrollBar->maximum());
    }
}

QString SystemLog::getLevelStyle(LogLevel level) const {
    switch (level) {
        case LOG_ERROR: return "color: red; font-weight: bold;";
        case LOG_WARNING: return "color: orange;";
        case LOG_DEBUG: return "color: gray;";
        default: return "color: black;";
    }
}

QString SystemLog::getLevelIcon(LogLevel level) const {
    switch (level) {
        case LOG_INFO:    return "ℹ️";
        case LOG_WARNING: return "⚠️";
        case LOG_ERROR:   return "❌";
        case LOG_DEBUG:   return "🐞";
        default:          return "";
    }
}
