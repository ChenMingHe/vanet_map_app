#ifndef LOGWRITER_H
#define LOGWRITER_H

#include <QDebug>
#include <typeinfo>
#include <QFile>
#include <QTime>
#include <QDate>
#include <QTextStream>

//XXX:��Ϊʱ�����ޣ�����ʱʹ��һ���궨��������ʵ��
#define LogDebug(x) if (x) qDebug(); qDebug() << typeid(*this).name() << __LINE__ << ":"

class LogWriter {

public:
    void debug(const QString &s);
    void info(const QString &s);
    void debug(const QByteArray &array);
    void info(const QByteArray &array);
    virtual ~LogWriter();
    static LogWriter &log();

private:
    QFile *logFile;
    static LogWriter *instance;
    LogWriter();
};

#endif // LOGWRITER_H
