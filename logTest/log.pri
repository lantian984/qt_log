

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

include($$PWD/log4qt/src/log4qt/log4qt.pri)

SOURCES += \
         $$PWD/config.cpp \
         $$PWD/src/logtest.cpp

HEADERS += \
         $$PWD/config.h \
         $$PWD/define.h \
         $$PWD/include/logtest.h




