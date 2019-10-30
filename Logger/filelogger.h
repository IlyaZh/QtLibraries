#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "abstractlogger.h"
#include <QFile>

class FileLogger : public AbstractLogger
{
public:
    explicit FileLogger(QString filePath, QObject *parent = nullptr);
    ~FileLogger() override;
    void start() override;
    void stop() override;

public slots:
    void write(QByteArray byteArray) final override;

private:
    QFile *file;
    QString filePath;
};

#endif // FILELOGGER_H
