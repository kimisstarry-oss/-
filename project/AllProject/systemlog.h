#ifndef SYSTEMLOG_H
#define SYSTEMLOG_H

#include <QWidget>
#include <QString>
#include <QListWidget>
#include <QMutex>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QMetaType>  // 【新增】需要包含这个头文件

namespace Ui {
class SystemLog;
}

// 日志等级枚举
enum LogLevel {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_DEBUG
};

// 日志条目结构
struct LogEntry {
    QDateTime timestamp;
    LogLevel level;
    QString message;

    QString toString() const;
};

// 【新增】注册元类型，使 LogEntry 可用于信号槽
Q_DECLARE_METATYPE(LogEntry)

class SystemLog : public QWidget
{
    Q_OBJECT

public:
    explicit SystemLog(QWidget *parent = nullptr);
    ~SystemLog();

    void addLog(const QString &message, LogLevel level = LOG_INFO);
    void clearLogs();
    bool exportLogs(const QString &filePath);
    void setMaxLines(int maxLines);

signals:
    void signalAppendLog(const LogEntry &entry);
    void signalClearLogs();
    void signalUpdateScroll();

private slots:
    void onAppendLog(const LogEntry &entry);
    void onClearLogs();
    void onUpdateScroll();

private:
    Ui::SystemLog *ui;
    QList<LogEntry> m_logEntries;
    QMutex m_mutex;
    int m_maxLines;

    QString getLevelStyle(LogLevel level) const;
    QString getLevelIcon(LogLevel level) const;
};

#endif // SYSTEMLOG_H
