#include "logger.h"
#include <QDebug>

Logger::Logger(QString filename)
{
    QFile *file = new QFile(filename);
    if(file->open(QIODevice::ReadWrite)) {
        Logger::m_device.setDevice(file);
    } else {
        qDebug() << "[LOGGER] file \"" << filename << "\" is not open!";
    }
}

Logger::~Logger() {
    write(nullptr, "Logger is closed!");
}

void Logger::addSource(void* pSource, QString name) {
    for(uint8_t i = 0; i < Logger::m_sources.size(); i++) {
        if(Logger::m_sources.at(i).first == pSource) {
            Logger::m_sources[i].second = name;
            return;
        }
    }
    Logger::m_sources.append(qMakePair(pSource, name));
    qDebug() << "[LOGGER] Add source:  \"" << pSource;
}

void Logger::removeSource(void* pSource) {
    for(uint8_t i = 0; i < Logger::m_sources.size(); i++) {
        if(Logger::m_sources.at(i).first == pSource) {
            Logger::m_sources.removeAt(i);
            return;
        }
    }
}

void Logger::write(void* pSource, QString msg) {
//    if(Logger::m_device == nullptr) {
//        qDebug() << "[LOGGER] Write to log is not available!";
//        return;
//    }

    QDateTime currTime = QDateTime::currentDateTime();

    QString strLine = QString("[%s][%s] %s \n")
                    .arg(currTime.toString(TIMESTAMP_DEFAULT_FORMAT))
                    .arg(sourceName(pSource))
                    .arg(msg);

    Logger::m_device << strLine;

}

QString Logger::sourceName(void* pSource) {
    if(pSource == nullptr) {
        return "";
    }

    for(QPair<void*, QString> item : m_sources) {
        if(item.first == pSource) {
            return item.second;
        }
    }
    return "UNKNOWN";
}
