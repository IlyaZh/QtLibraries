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

    explicit AbstractLogger(QString filePath, QObject *parent = nullptr);
    explicit AbstractLogger(QString host, quint16 port, QObject *parent = nullptr);
    explicit AbstractLogger(QString comPort, qint32 baud, QObject *parent = nullptr);
    virtual ~AbstractLogger();
    void setMaxQueueSize(quint16 size);
    void setTimestampFormat(QString format);
    void start();
    void stop();

private:
    bool cryptoEnabled;
    QString filePath;
    QString socketHost;
    quint16 socketPort;
    QString comPort;
    qint32 comBaud;
    QFile *file;
    QIODevice *device;
    QString errorString;
    quint16 queueSize;
    QString timestampFormat;

signals:
    void errorOccuredSignal(QString);


public slots:
    void write(QString str);
    void write(QByteArray array);

signals:

public slots:
};

#endif // ABSTRACTLOGGER_H
