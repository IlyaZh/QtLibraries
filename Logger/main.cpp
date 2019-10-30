#include <QCoreApplication>

#include "abstractlogger.h"
#include "seriallogger.h"
#include "filelogger.h"
#include "udplogger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AbstractLogger* logger = new FileLogger("e://log.txt");
    logger->write("Hello!");

    logger->deleteLater();

    return a.exec();
}
