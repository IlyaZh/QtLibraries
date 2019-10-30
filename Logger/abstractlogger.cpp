#include "abstractlogger.h"

AbstractLogger::AbstractLogger(QObject *parent) : QObject(parent)
{

}


// SLOTS
void write(QString str) {}

void write(QByteArray array) {}
