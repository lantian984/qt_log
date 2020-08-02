# qt_log
这是一个QT的模块软件代码，用于生成log文件


#如何使用？

## 下载
复制该命令
```
git@github.com:lantian984/qt_log.git
```

## 将下目录logtest复制到工程目录下

## 在工程的.pro文件内编辑如下内容
````
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

include($$PWD/logtest/log.pri)
````
这样新的模块就加入到你的工程中


## 如何使用

在logtest/include/define.h文件
```// 开发过程中暂时使用qDebug替代 1-使用debug打印输出  0-使用日志输出
#if 0
.....
#eles
.....
#end
```
通过改变这个预处理开关，在需要日志功能时写0，不用时写1

在启用日志功能前还需要一些配置
```
#include "inc/test.h"
#include <QApplication>
+#include "logTest/config.h"
+#include "logTest/define.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

 +   Config conffig;
 +   LOG_DEBUG("debug测试");
    test w;
    w.show();

    return a.exec();
}

```
只需要添加两个头文件和一个类定义就行