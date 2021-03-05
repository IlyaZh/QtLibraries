#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

const QString TIMESTAMP_DEFAULT_FORMAT = QString("yyyy.MM.dd HH:mm:ss");

class Logger
{
public:
    Logger(QString filename);
    ~Logger();
    static void addSource(void* pSource, QString name);
    static void removeSource(void* pSource);
    static void write(void* pSource, QString msg);
private:
    static QTextStream m_device;
    static QVector<QPair<void*, QString>> m_sources;
    static QString sourceName(void* pSource);
};

#endif // LOGGER_H
