QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    webrtccontroller.cpp

HEADERS += \
    mainwindow.h \
    webrtccontroller.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += C:/Users/Hot-f/Desktop/Qt_Video_Player_Application/Qt_Video_Player_Application/LIB/libdatachannel/include
LIBS += -LC:/Users/Hot-f/Desktop/Qt_Video_Player_Application/Qt_Video_Player_Application/LIB/libdatachannel/Windows/Mingw64 -ldatachannel.dll
LIBS += -LD:\Qt/Tools/OpenSSLv3/Win_x64/bin -lcrypto-3-x64 -lssl-3-x64
LIBS += -lws2_32
LIBS += -lssp
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
