#pragma once
#include <QObject>
#include <rtc/rtc.hpp>
#include "qdebug.h"
#define DEBUG qDebug()

class WebRtcController : public QObject
{
    Q_OBJECT
public:
    explicit WebRtcController(QObject *parent = nullptr);
    explicit WebRtcController(QObject *parent, bool _isMaster );
private:
    bool isMaster = false;
    bool connected = false;
    rtc::PeerConnection *m_pearConection;
    rtc::Track * m_track;
    QString m_localDescription;
    rtc::Description * m_pearSdp;
    rtc::DataChannel * m_pearDataChanal;
    rtc::Configuration m_config;

signals:
    void gatheringComplete();
};


