#include "config.h"

Config::Config()
{
    QString data = "\
log4j.logger.debug=CONSOLE,debug0\n\
log4j.appender.debug=org.apache.log4j.RollingFileAppender\n\
log4j.appender.debug.Threshold=DEBUG\n\
log4j.appender.debug.appendFile=true\n\
log4j.appender.debug.Encoding=UTF-8\n\
log4j.appender.debug.File=log/debug.txt\n\
log4j.appender.debug.MaxFileSize=4096KB\n\
log4j.appender.debug.MaxBackupIndex=7\n\
log4j.appender.debug.layout=org.apache.log4j.PatternLayout\n\
log4j.appender.debug.layout.ConversionPattern=%d{yyyy-MM-dd HH:mm:ss.zzz}[%t][%p] %m%n\n\
\n\
log4j.logger.info=CONSOLE,info,debug\n\
log4j.appender.info=org.apache.log4j.RollingFileAppender\n\
log4j.appender.info.Threshold=DEBUG\n\
log4j.appender.info.appendFile=true\n\
log4j.appender.info.Encoding=UTF-8\n\
log4j.appender.info.File=log/info.txt\n\
log4j.appender.info.MaxFileSize=4096KB\n\
log4j.appender.info.MaxBackupIndex=7\n\
log4j.appender.info.layout=org.apache.log4j.PatternLayout\n\
log4j.appender.info.layout.ConversionPattern=%d{yyyy-MM-dd HH:mm:ss.zzz}[%t][%p] %m%n\n\
\n\
log4j.logger.warn=CONSOLE,info,debug,warn\n\
log4j.appender.warn=org.apache.log4j.RollingFileAppender\n\
log4j.appender.warn.Threshold=DEBUG\n\
log4j.appender.warn.appendFile=true\n\
log4j.appender.warn.Encoding=GBK\n\
log4j.appender.warn.File=log/warn.txt\n\
log4j.appender.warn.MaxFileSize=4096KB\n\
log4j.appender.warn.MaxBackupIndex=2\n\
log4j.appender.warn.layout=org.apache.log4j.PatternLayout\n\
log4j.appender.warn.layout.ConversionPattern=%d{yyyy-MM-dd HH:mm:ss.zzz}[%t][%p] %m%n\n\
\n\
\n\
log4j.logger.error=CONSOLE,info,debug,warn,error\n\
log4j.appender.error=org.apache.log4j.RollingFileAppender\n\
log4j.appender.error.Threshold=DEBUG\n\
log4j.appender.error.appendFile=true\n\
log4j.appender.error.Encoding=UTF-8\n\
log4j.appender.error.File=log/error.txt\n\
log4j.appender.debug.MaxFileSize=4096KB\n\
log4j.appender.debug.MaxBackupIndex=7\n\
log4j.appender.debug.layout=org.apache.log4j.PatternLayout\n\
log4j.appender.debug.layout.ConversionPattern=%d{yyyy-MM-dd HH:mm:ss.zzz}[%t][%p] %m%n";
    saveData(data);
    QThread::currentThread()->setObjectName("主线程");

    QTextCodec *codec = QTextCodec::codecForName("GBK");  //GBK//utf-8
    QTextCodec::setCodecForLocale(codec);

    qDebug() << "==== " <<  QApplication::applicationDirPath();


    Log::instance()->init(this->getLogConfigPath());

    /*Log::instance()->debug("调试日志信息测试中。。。。");
    Log::instance()->info("信息测试日志系统当中...");
    Log::instance()->warn("警告测试日志系统当中...");
    Log::instance()->error("错误测试日志系统当中...");*/
}

void Config::saveData(QString data){
    //保存为TXT文件
    bool exist;

    QDir *folder = new QDir;
    exist = folder->exists("./logconf");//查看目录是否存在（例子是保存到桌面）

    if(!exist){//不存在就创建
        folder->mkdir("./logconf");

    }
    if(!isFileExist(fileName)){     //文件则创建

        QFile f(fileName);
        if(!f.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)){//追加写入 添加结束符\r\n
             //QMessageBox::warning(this,tr("错误"),tr("打开文件失败,数据保存失败"));
            return ;
        }else{
            f.write(data.toUtf8());
        }
        f.close();
    }


}

QString Config::getLogConfigPath()
{
    return fileName;
}



bool Config::isFileExist(QString fullFileName)
{
    QFileInfo fileInfo(fullFileName);
    if(fileInfo.isFile())
    {
        return true;
    }
    return false;
}
