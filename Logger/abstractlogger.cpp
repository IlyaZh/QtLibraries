#include "abstractlogger.h"

const QString AbstractLogger::TIMESTAMP_DEFAULT_FORMAT = QString("yyyy.MM.dd HH:mm:ss");

AbstractLogger::AbstractLogger(QObject *parent) : QObject(parent) {
    this->timestampFormat = TIMESTAMP_DEFAULT_FORMAT;
    qDebug() << "AbstractLogger constructor";
}

AbstractLogger::~AbstractLogger() {
    qDebug() << "AbstractLogger Destructor";
}

void AbstractLogger::setTimestampFormat(QString format) {
    this->timestampFormat = format;
}

bool AbstractLogger::isOn() {
    return enabled;
}

void AbstractLogger::setEnabled(bool state) {
    enabled = state;
}
