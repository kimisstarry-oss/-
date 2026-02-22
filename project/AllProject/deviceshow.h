#ifndef DEVICESHOW_H
#define DEVICESHOW_H

#include <QWidget>
#include <QSerialPort>
#include <QTimer>

namespace Ui {
class DeviceShow;
}

class DeviceShow : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceShow(QWidget *parent = nullptr);
    ~DeviceShow();

    // 设置串口
    void setSerialPort(QSerialPort *serial);

    // 更新数据显示
    void updateTemperature(float value);
    void updateHumidity(float value);
    void updateLight(int value);
    void updateIR(bool detected);

public slots:
    void onDeviceConnected(bool connected);
    void processSerialData();

private:
    void setupStyles();
    void parseData(const QString &data);

private:
    Ui::DeviceShow *ui;
    QSerialPort *m_serialPort;
    QTimer *m_readTimer;
    bool m_isConnected;

    // 数据缓存
    float m_temperature;
    float m_humidity;
    int m_light;
    bool m_irDetected;
};

#endif // DEVICESHOW_H
