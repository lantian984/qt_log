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


#include "config.h"
#include "define.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QThread::currentThread()->setObjectName("主线程");

    QTextCodec *codec = QTextCodec::codecForName("GBK");  //GBK//utf-8
    QTextCodec::setCodecForLocale(codec);

    qDebug() << "==== " <<  QApplication::applicationDirPath();

    Config config;
    Log::instance()->init(config.getLogConfigPath());

    Log::instance()->debug("调试日志信息测试中。。。。");
    Log::instance()->info("信息测试日志系统当中...");
    Log::instance()->warn("警告测试日志系统当中...");
    Log::instance()->error("错误测试日志系统当中...");
    LOG_DEBUG("你好啊");
    LOG_INFO("怎么了");
    LOG_WARN("hahahh")
    LOG_ERROR("22222");
    return a.exec();
}
