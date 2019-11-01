#include <QCoreApplication>

#include "abstractlogger.h"
#include "seriallogger.h"
#include "filelogger.h"
#include "udplogger.h"

#include <QTimer>
#include <QObject>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AbstractLogger* logger = new UdpLogger(12345);
    logger->write("Hello!");

    int i =0;

//    logger->deleteLater();
    QTimer *tmr = new QTimer();
    tmr->setSingleShot(false);
    tmr->connect(tmr, &QTimer::timeout, [&]{
        QByteArray msg = QString::number(i++).toUtf8();
        logger->write(msg);
        qDebug() << msg;
    });
    tmr->start(1000);


    return a.exec();
}
