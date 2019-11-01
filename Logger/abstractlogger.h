#ifndef ABSTRACTLOGGER_H
#define ABSTRACTLOGGER_H

#include <QObject>
#include <QFile>
#include <QIODevice>
#include <QAbstractSocket>
#include <QSerialPort>
#include <QSerialPortInfo>

class AbstractLogger : public QObject
{
    Q_OBJECT
public:
    const static QString TIMESTAMP_DEFAULT_FORMAT;

    explicit AbstractLogger(QObject *parent = nullptr);
    ~AbstractLogger();
    void setTimestampFormat(QString format);
    virtual void start() = 0;
    virtual void stop() = 0;
    bool isOn();

private:


protected:
    bool enabled = false;
    bool cryptoEnabled;
    QString timestampFormat;
    void setEnabled(bool state);

signals:
    void errorOccuredSignal(QString);


public slots:
    virtual void write(QByteArray byteArray) = 0;

};

#endif // ABSTRACTLOGGER_H
