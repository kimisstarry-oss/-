#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>

class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parent = nullptr);

signals:
    void connectionStatusChanged(bool connected);

public slots:
    void connectDevice();
    void disconnectDevice();

private:
    QSerialPort *m_serialPort;
    bool m_isConnected;
};

#endif // SERIALMANAGER_H
