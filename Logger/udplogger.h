#ifndef UDPLOGGER_H
#define UDPLOGGER_H

#include "abstractlogger.h"
#include <QUdpSocket>

class UdpLogger : public AbstractLogger
{
public:
    UdpLogger(quint16 port, QString address = QHostAddress(QHostAddress::Broadcast).toString(), QObject *parent = nullptr);
    ~UdpLogger() override;
    void start() final override;
    void stop() final override;

private:
    uint16_t port;
    QHostAddress address;
    QUdpSocket *udp;

public slots:
    void write(QByteArray byteArray) final override;
};

#endif // UDPLOGGER_H
