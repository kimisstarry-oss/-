#include "title.h"
#include "ui_title.h"
#include <QStyle>
#include <QDebug>

Title::Title(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Title),
    m_isConnected(false),
    m_animationStep(0),
    m_animationTimer(new QTimer(this))
{
    ui->setupUi(this);

    //设置标题栏样式
    this->setStyleSheet("background-color: #F0F0F0;color:black;");

    //设置固定高度
    this->setFixedHeight(60);

    //设置字体样式
    ui->label_title->setStyleSheet("font-size:18px;font-weight:bold;");

    //设置状态标签样式
    ui->label_status->setStyleSheet("font-size: 14px;");

    //设置状态图标初始样式
    //ui->label_statusIcon->setStyleSheet("border-radius: 6px;background-color: #e74c3c;border: 1px solid #c0392b;");


    ui->label_statusIcon->setFixedSize(12, 12);

    //链接信号槽
    connect(m_animationTimer,&QTimer::timeout,this,&Title::updateConnectionAnimation);

    // 初始状态
    updateStatusIcon();


//    ui->label_statusIcon->setAttribute(Qt::WA_StyledBackground, true);  // 强制使用样式表背景

//    // 然后设置样式表：
//    ui->label_statusIcon->setStyleSheet(
//        "QLabel#label_statusIcon {"
//        "    background-color: #2c3e50 !important;"  // 使用!important强制生效
//        "    border-radius: 6px;"
//        "    border: 2px solid #c0392b;"
//        "    min-width: 12px;"
//        "    max-width: 12px;"
//        "    min-height: 12px;"
//        "    max-height: 12px;"
//        "    padding: 0px;"
//        "    margin: 0px;"
//        "}"
//    );

//    // 确保背景绘制
//    ui->label_statusIcon->setAutoFillBackground(true);
}

Title::~Title()
{
    delete ui;
}

void Title::setConnectionStatus(bool connected)
{
    if (m_isConnected != connected) {
        m_isConnected = connected;
        updateStatusIcon();
        emit connectionStatusChanged(connected);
    }
}

//保存网关名称并设置标题文本
void Title::setGatewayName(const QString &name)
{
    m_gatewayName = name;
    ui->label_title->setText(name + " 智能网关控制系统");
}

void Title::updateStatusIcon()
{
    if (m_isConnected) {
        ui->label_status->setText("设备已连接");
        ui->label_statusIcon->setStyleSheet(
            "border-radius: 6px;"
            "background-color: #2ecc71;"
            "border: 1px solid #27ae60;"
        );
        m_animationTimer->stop();
    } else {
        ui->label_status->setText("设备未连接");
        m_animationTimer->start(500);
    }
}

void Title::updateConnectionAnimation()
{
    m_animationStep = (m_animationStep + 1) % 2;

    if (m_animationStep == 0) {
        ui->label_statusIcon->setStyleSheet(
            "border-radius: 6px;"
            "background-color: #e74c3c;"
            "border: 1px solid #c0392b;"
        );
    } else {
        ui->label_statusIcon->setStyleSheet(
            "border-radius: 6px;"
            "background-color: #f39c12;"
            "border: 1px solid #d35400;"
        );
    }
}
