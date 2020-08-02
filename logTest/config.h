#ifndef CONFIG_H
#define CONFIG_H

#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QDir>
#include <QFileInfo>

#include "include/logtest.h"
#include <QApplication>
#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QCoreApplication>
#include <QThread>
#include <QTextCodec>
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QDir>

class Config
{

private:
    QString fileName = "./logconf/log.conf";
public:
    Config();

    bool isFileExist(QString fullFileName);
    void saveData(QString data);

    QString getLogConfigPath();
};

#endif // CONFIG_H
