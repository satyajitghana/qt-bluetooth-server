#include "chatserver.hpp"

#include <iostream>
#include <chrono>
#include <thread>

#include <QtBluetooth/qbluetoothdeviceinfo.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <QtBluetooth/qbluetoothuuid.h>


int main(int argc, char *argv[])
{

    QList<QBluetoothHostInfo> localAdapters = QBluetoothLocalDevice::allDevices();
    QBluetoothLocalDevice adapter(localAdapters.at(0).address());
    adapter.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

    //! [Create Chat Server]
    ChatServer* server = new ChatServer();
    server->startServer();
    //! [Create Chat Server]

    std::this_thread::sleep_for(std::chrono::minutes(2));

    delete server;

    return 0;
}
