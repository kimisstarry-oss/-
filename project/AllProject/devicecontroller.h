#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <QWidget>
#include <QtSerialPort>
#include <QTimer>

namespace Ui {
class DeviceController;
}

class DeviceController : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceController(QWidget *parent = nullptr);
    ~DeviceController();

    void setSerialPort(QSerialPort *serial);
    bool isConnected() const;

public slots:
    void onDeviceConnected(bool connected);

private slots:
    //电机按钮

    void on_pushButton_forward_clicked();

    void on_pushButton_reverse_clicked();

    //开关切换

    void on_checkBox_led_toggled(bool checked);

    void on_checkBox_motor_toggled(bool checked);

    void on_checkBox_buzzer_toggled(bool checked);

private:
    void setupStyles();
    void sendControlCommand(const QByteArray &command);
    void updateButtonStates();
private:
    Ui::DeviceController *ui;
    QSerialPort *m_serialPort;

    bool m_isConnected;
    bool m_motorRunning;
};

#endif // DEVICECONTROLLER_H
