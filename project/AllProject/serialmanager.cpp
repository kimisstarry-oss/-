#include "serialmanager.h"

SerialManager::SerialManager(QObject *parent)
    : QObject(parent)
    , m_serialPort(new QSerialPort(this))
    , m_isConnected(false)
{
}

void SerialManager::connectDevice()
{
    // 实现连接逻辑
    m_isConnected = true;
    emit connectionStatusChanged(true);
}

void SerialManager::disconnectDevice()
{
    // 实现断开逻辑
    m_isConnected = false;
    emit connectionStatusChanged(false);
}
