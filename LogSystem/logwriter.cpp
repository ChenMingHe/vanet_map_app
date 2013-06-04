#include "logwriter.h"

void LogWriter::debug(const QString &s) {
    QTextStream out(logFile);
    out << QTime::currentTime().toString("hh:mm:ss ") << " - Debug - " << s;
}

void LogWriter::info(const QString &s) {
    QTextStream out(logFile);
    out << QTime::currentTime().toString("hh:mm:ss ") << " - Info - " << s;
}

void LogWriter::debug(const QByteArray &array)
{
    logFile->write(QTime::currentTime().toString("hh:mm:ss ").toAscii() +
                   QByteArray(" - Debug - ") + array);
}

void LogWriter::info(const QByteArray &array)
{
    logFile->write(QTime::currentTime().toString("hh:mm:ss ").toAscii() +
                   QByteArray(" - Info - ") + array);
}

LogWriter::~LogWriter()
{
    logFile->close();
    delete logFile;
}

LogWriter *LogWriter::instance = NULL;
LogWriter &LogWriter::log()
{
    if (instance == NULL)
        instance = new LogWriter;
    return *instance;
}

LogWriter::LogWriter() {
    logFile = new QFile("./log/vanetapp.log");
    if (!logFile->open(QIODevice::ReadWrite|QIODevice::Append))
        return;

    QTextStream out(logFile);
    out << "\n\n\n************************VANET MAP TEST************************\n";
    out << "\tDate " << QDate::currentDate().toString("dd/MM/yyyy dddd ")
        << QTime::currentTime().toString("hh:mm a") << endl;
}
