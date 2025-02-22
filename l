#include <QDebug>

// Define your enum class
enum class State : int {
    New = RTC_NEW,
    Connecting = RTC_CONNECTING,
    Connected = RTC_CONNECTED,
    Disconnected = RTC_DISCONNECTED,
    Failed = RTC_FAILED,
    Closed = RTC_CLOSED
};

// Define a custom operator<< for the enum class


int main() {
    State currentState = State::Connected;
    qDebug() << "Current state:" << currentState;
    return 0;
}
