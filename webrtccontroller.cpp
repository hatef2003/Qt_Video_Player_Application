#include "webrtccontroller.h"

QDebug operator<<(QDebug debug, rtc::PeerConnection::State state) {
    QDebugStateSaver saver(debug);
    switch (state) {
    case rtc::PeerConnection::State::New:
        debug << "New";
        break;
    case rtc::PeerConnection::State::Connecting:
        debug << "Connecting";
        break;
    case rtc::PeerConnection::State::Connected:
        debug << "Connected";
        break;
    case rtc::PeerConnection::State::Disconnected:
        debug << "Disconnected";
        break;
    case rtc::PeerConnection::State::Failed:
        debug << "Failed";
        break;
    case rtc::PeerConnection::State::Closed:
        debug << "Closed";
        break;
    }
    return debug;
}


WebRtcController::WebRtcController(QObject *parent)
    : QObject{parent}
{}

WebRtcController::WebRtcController(QObject *parent, bool _isMaster)
    :QObject{parent}
{
    isMaster = _isMaster;
    rtc::InitLogger(rtc::LogLevel::Warning);
    m_pearConection = new rtc::PeerConnection(m_config);
    m_pearConection->onLocalDescription([](rtc::Description desc)
    {

    }
                                        );
    m_pearConection->onStateChange([](rtc::PeerConnection::State state)
                                   {
        DEBUG << "state changed;" << state;
    });
    /**
     * ======================================================
     * ======================================================
     * ======================================================
     * ======================================================
     * @attention add on local candidate in case of using of this
     * ======================================================
     * ======================================================
     * ======================================================
     * ======================================================
     */
    m_pearConection->onGatheringStateChange([this](rtc::PeerConnection::GatheringState state)
                                            {
        if (state == rtc::PeerConnection::GatheringState::Complete)
            {
                emit gatheringComplete();
                connected = true;
            }
        });

}
