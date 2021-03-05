#include "logger.h"

Logger::Logger(QString filename) : m_device(nullptr)
{
    QFile *file = new QFile(filename, this);
}
