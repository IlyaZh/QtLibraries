#include "filelogger.h"

#include <QDateTime>

FileLogger::FileLogger(QString filePath, QObject *parent) : AbstractLogger(parent), file(nullptr) {
    this->filePath = filePath;
    file = new QFile(filePath);
    start();
}

FileLogger::~FileLogger() {
    stop();
    file->deleteLater();
    qDebug() << "[FileLogger]" << "Desctructor";
}

void FileLogger::start() {
    if(file->isOpen()) {
        AbstractLogger::enabled = true;
    } else {
        if(file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            AbstractLogger::enabled = true;
            qDebug() << QString("[FileLogger] Successfully started! Log file: %1").arg(filePath);
        } else {
            QString error = QString("[FileLogger] Can't open file \"%1\"").arg(filePath);
            emit errorOccuredSignal(error);
        }
    }
}

void FileLogger::stop() {
    if(file->isOpen()) {
        file->close();
    }
    AbstractLogger::enabled = false;
}

// SLOTS
void FileLogger::write(QByteArray byteArray) {
    if(isOn()) {
        QDateTime currTime;
        QTextStream out(file);
        QByteArray time = QString("[%1] ").arg(currTime.currentDateTime().toString(AbstractLogger::timestampFormat)).toUtf8();
        out << time << byteArray << endl;
    }
}
