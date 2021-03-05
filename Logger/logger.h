#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QDateTime>

const QString AbstractLogger::TIMESTAMP_DEFAULT_FORMAT = QString("yyyy.MM.dd HH:mm:ss");

class Logger
{
public:
    Logger(QString filename);
private:
    static QIODevice* m_device;
};

#endif // LOGGER_H
