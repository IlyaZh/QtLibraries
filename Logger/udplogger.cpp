#include "udplogger.h"

#include <QNetworkDatagram>
#include <QDateTime>

UdpLogger::UdpLogger(quint16 port, QString address, QObject *parent) : AbstractLogger(parent),
    udp(nullptr)
{
    this->port = port;
    this->address = QHostAddress(address);
    udp = new QUdpSocket(this);
    start();
}

UdpLogger::~UdpLogger() {
    stop();
    udp->disconnect();
    udp->deleteLater();
    qDebug() << "[UdpLogger]" << "Desctructor";
}

void UdpLogger::start() {
    AbstractLogger::enabled = true;
    qDebug() << QString("[UdpLogger] Successfully started! %1 : %2").arg(address.toString()).arg(port);
}

void UdpLogger::stop() {
    if(udp->isOpen()) {
        udp->close();
    }
    AbstractLogger::enabled = false;
}

// slot
void UdpLogger::write(QByteArray byteArray) {
    if(isOn()) {
        QDateTime currTime;
        QByteArray time = QString("[%1] ").arg(currTime.currentDateTime().toString(AbstractLogger::timestampFormat)).toUtf8();
        QByteArray dataGram = time.append(byteArray);
        udp->writeDatagram(dataGram.data(), dataGram.size(), address, port);
    }
}
