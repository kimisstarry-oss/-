#include "devicecontroller.h"
#include "ui_devicecontroller.h"
#include <QMessageBox>
#include <QDebug>

DeviceController::DeviceController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceController),
    m_serialPort(nullptr),
    m_isConnected(false),
    m_motorRunning(false)
{
    ui->setupUi(this);

    ui->label->setText("<img src = 'qrc:/image/设置.png' width = '27' height = '27'>"
                         "<span style='font-size:35px;'>硬件外设控制</span>");

    // 设置样式
    setupStyles();

    // 初始状态
    updateButtonStates();


}

DeviceController::~DeviceController()
{
    delete ui;
}

void DeviceController::setupStyles()
{
    // 窗口背景改为纯白
    this->setStyleSheet("background-color: white;");
    //#e0e0e0
    QString switchStyle =
        "QCheckBox {"
        "    spacing: 0px;"
        "    min-width: 60px;"
        "    max-width: 60px;"
        "    min-height: 34px;"
        "    max-height: 34px;"
        "}"
        "QCheckBox::indicator {"
        "    width: 60px;"
        "    height: 34px;"
        "    border-radius: 17px;"
        "    background-color: #dfe1e5;"
        "    border: 1px solid #c0c4c8;"
        "}"
        "QCheckBox::indicator:checked {"
        "    background-color: #34c759;"
        "    border: 1px solid #2da84a;"
        "}"
        "QCheckBox::indicator:disabled {"
        "    background-color: #e9e9ea;"
        "    border: 1px solid #d1d1d6;"
        "}"
        "QCheckBox::indicator:unchecked {"
        "    image: none;"
        "    background-color: white;"
        "    border: 1px solid #d1d1d6;"
        "    border-radius: 15px;"
        "    width: 30px;"
        "    height: 30px;"
        "    margin: 2px 2px 2px 2px;"
        "}"
        "QCheckBox::indicator:checked {"
        "    image: none;"
        "    background-color: white;"
        "    border: 1px solid #d1d1d6;"
        "    border-radius: 15px;"
        "    width: 30px;"
        "    height: 30px;"
        "    margin: 2px 2px 2px 28px;"
        "}";

    ui->checkBox_led->setStyleSheet(switchStyle);
    ui->checkBox_motor->setStyleSheet(switchStyle);
    ui->checkBox_buzzer->setStyleSheet(switchStyle);

    ui->checkBox_led->setChecked(false);
    ui->checkBox_motor->setChecked(false);
    ui->checkBox_buzzer->setChecked(false);
}


void DeviceController::sendControlCommand(const QByteArray &command)
{
    if (m_serialPort && m_serialPort->isOpen()) {
           m_serialPort->write(command);
       }
}

void DeviceController::updateButtonStates()
{
    // 调试时临时忽略连接状态
    bool enabled = true;  // 改为 true 用于测试
    // bool enabled = m_isConnected;  // 实际使用时改回来

    ui->checkBox_led->setEnabled(enabled);
    ui->checkBox_motor->setEnabled(enabled);
    ui->checkBox_buzzer->setEnabled(enabled);

    bool motorPowerOn = ui->checkBox_motor->isChecked() && enabled;
    ui->pushButton_forward->setEnabled(motorPowerOn);
    ui->pushButton_reverse->setEnabled(motorPowerOn);
}

void DeviceController::setSerialPort(QSerialPort *serial)
{
    m_serialPort = serial;
    m_isConnected = (serial && serial->isOpen());
    updateButtonStates();
}

void DeviceController::onDeviceConnected(bool connected)
{
    m_isConnected = connected;
    updateButtonStates();

    if (!connected) {
            ui->checkBox_led->setChecked(false);
            ui->checkBox_motor->setChecked(false);
            ui->checkBox_buzzer->setChecked(false);
            m_motorRunning = false;
        }
}


void DeviceController::on_pushButton_forward_clicked()
{
//    if (!m_isConnected || !ui->checkBox_motor->isChecked()) {
//           QMessageBox::warning(this, "警告", "请先打开电机电源！");
//           return;
//       }

//       m_motorRunning = true;
//       sendControlCommand("MOTOR_FWD\n");
//       qDebug() << "正向旋转";
}

void DeviceController::on_pushButton_reverse_clicked()
{
//    if (!m_isConnected || !ui->checkBox_motor->isChecked()) {
//            QMessageBox::warning(this, "警告", "请先打开电机电源！");
//            return;
//        }

//        m_motorRunning = true;
//        sendControlCommand("MOTOR_REV\n");
//        qDebug() << "反向旋转";
}

void DeviceController::on_checkBox_led_toggled(bool checked)
{
    //    if (!m_isConnected) {
    //           ui->pushButton_led->setChecked(false);
    //           QMessageBox::warning(this, "警告", "设备未连接！");
    //           return;
    //       }

    //       sendControlCommand(checked ? "LED_ON\n" : "LED_OFF\n");
    //       qDebug() << "LED" << (checked ? "开启" : "关闭");


}

void DeviceController::on_checkBox_motor_toggled(bool checked)
{
//    if (!m_isConnected) {
//            ui->checkBox_motor->setChecked(false);
//            QMessageBox::warning(this, "警告", "设备未连接！");
//            return;
//        }

//        if (!checked) {
//            // 关闭电机电源时，自动停止电机
//            m_motorRunning = false;
//            sendControlCommand("MOTOR_STOP\n");
//        }

//        ui->pushButton_forward->setEnabled(checked && m_isConnected);
//        ui->pushButton_reverse->setEnabled(checked && m_isConnected);
//        qDebug() << "电机电源" << (checked ? "开启" : "关闭");
}

void DeviceController::on_checkBox_buzzer_toggled(bool checked)
{
//    if (!m_isConnected) {
//            ui->checkBox_buzzer->setChecked(false);
//            QMessageBox::warning(this, "警告", "设备未连接！");
//            return;
//        }

//        sendControlCommand(checked ? "BUZZER_ON\n" : "BUZZER_OFF\n");
//        qDebug() << "蜂鸣器" << (checked ? "开启" : "关闭");

//        // 安全保护：3秒后自动关闭
//        if (checked) {
//            QTimer::singleShot(3000, this, [this]() {
//                if (ui->checkBox_buzzer->isChecked()) {
//                    ui->checkBox_buzzer->setChecked(false);
//                }
//            });
//        }
}
