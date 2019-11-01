#include "seriallogger.h"

SerialLogger::SerialLogger(QString portName, qint32 baud, QObject *parent) : AbstractLogger(parent)
{
    this->portName = portName;
    this->baudRate = baud;
    serialPort = new QSerialPort(this);
    serialPort->setBaudRate(baudRate);
    serialPort->setPortName(portName);
    start();
}

SerialLogger::~SerialLogger() {
    stop();
    serialPort->deleteLater();
    qDebug() << "[SerialLogger]" << "Desctructor";
}

void SerialLogger::start() {
    if(serialPort->isOpen()) {
        setEnabled(true);
    } else {
        if(serialPort->open(QIODevice::ReadWrite)) {
            setEnabled(true);
            qDebug() << QString("Com port %1, %2 is open!").arg(portName).arg(baudRate);
        } else {
            QString error = QString("[FileLogger] Can't open port %1, %2").arg(portName).arg(baudRate);
            emit errorOccuredSignal(error);
        }
    }
}
void SerialLogger::stop() {
    if(serialPort->isOpen()) {
        serialPort->close();
    }
    setEnabled(false);
}

// public slots
void SerialLogger::write(QByteArray byteArray) {
    if(isOn()) {
        if(serialPort->isOpen()) {
            serialPort->write(byteArray);
        }
    }
}
