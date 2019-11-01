#ifndef SERIALLOGGER_H
#define SERIALLOGGER_H

#include "abstractlogger.h"
#include <QSerialPort>

class SerialLogger : public AbstractLogger
{
public:
    SerialLogger(QString portName, qint32 baud = 115200, QObject *parent = nullptr);
    ~SerialLogger() override;
    void start() override;
    void stop() override;

public slots:
    void write(QByteArray byteArray) final override;

private:
    QSerialPort *serialPort;
    QString portName;
    qint32 baudRate;
};

#endif // SERIALLOGGER_H
