#include <QCoreApplication>

#include "abstractlogger.h"
#include "seriallogger.h"
#include "filelogger.h"
#include "udplogger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AbstractLogger* udpLogger = new UdpLogger(12345);
    AbstractLogger* fileLogger = new FileLogger("log.txt");
    AbstractLogger* serialLogger = new SerialLogger("COM1", 921600);

    udpLogger->write("Hello, udp!");
    fileLogger->write("Hello, txt!");
    serialLogger->write("Hi, serial!");

    udpLogger->deleteLater();
    fileLogger->deleteLater();
    serialLogger->deleteLater();

    return a.exec();
}
