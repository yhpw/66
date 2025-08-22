// #include "BLEHandler.h"
// #include <Arduino.h>

// static BLEServer *pServer = NULL;
// static BLECharacteristic *pCharacteristic1 = NULL;
// static BLECharacteristic *pCharacteristic2 = NULL;
// static bool deviceConnected = false;
// static void (*characteristic2WriteCallback)(const std::string &) = nullptr;


// // 在 BLEHandler.cpp 文件中添加
// void sendConnectionSuccessMessage() {
//     if (deviceConnected) {
//         std::string successMessage = "连接成功";
//         pCharacteristic1->setValue(successMessage); // 设置特性值为连接成功消息
//         pCharacteristic1->notify();                 // 发送通知到客户端
//     }
// }


// class MyServerCallbacks: public BLEServerCallbacks {
//     void onConnect(BLEServer *pServer) {
//         Serial.println("蓝牙连接成功");
//         deviceConnected = true;
        
//     }

//     void onDisconnect(BLEServer *pServer) {
//         Serial.println("蓝牙断开连接");
//         deviceConnected = false;
//         pServer->getAdvertising()->start();
//     }
// };

// class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
//     void onWrite(BLECharacteristic *pCharacteristic) override {
//         std::string rxValue = pCharacteristic->getValue();
//         if (rxValue.length() > 0) {
//             Serial.print("Received value: ");
//             Serial.println(rxValue.c_str());

//             // 处理接收到的数据
//             if (characteristic2WriteCallback) {
//                 characteristic2WriteCallback(rxValue);
//             }

//             // 发送回显消息到客户端
//             std::string response = "Echo: " + rxValue; // 生成回显消息
//             pCharacteristic->setValue(response);       // 设置特性值为回显消息
//             pCharacteristic->notify();                  // 发送通知到客户端
//         }
//     }
// };


// void initBLE() {
//     BLEDevice::init("ESP32 BLE Server");
//     pServer = BLEDevice::createServer();
//     pServer->setCallbacks(new MyServerCallbacks());

//     BLEService *pService = pServer->createService(SERVICE_UUID);

//     // 创建两个特征 UUID
//     pCharacteristic1 = pService->createCharacteristic(
//                         CHARACTERISTIC_1_UUID,
//                         BLECharacteristic::PROPERTY_READ |
//                         BLECharacteristic::PROPERTY_WRITE |
//                         BLECharacteristic::PROPERTY_NOTIFY |
//                         BLECharacteristic::PROPERTY_INDICATE
//                       );
//     pCharacteristic1->addDescriptor(new BLE2902());

//     pCharacteristic2 = pService->createCharacteristic(
//                         CHARACTERISTIC_2_UUID,
//                         BLECharacteristic::PROPERTY_READ |
//                         BLECharacteristic::PROPERTY_WRITE |
//                         BLECharacteristic::PROPERTY_NOTIFY |
//                         BLECharacteristic::PROPERTY_INDICATE
//                       );
//     pCharacteristic2->addDescriptor(new BLE2902());
//     pCharacteristic2->setCallbacks(new MyCharacteristicCallbacks());

//     pService->start();
//     pServer->getAdvertising()->start();
//     Serial.println("Bluetooth initialized and started broadcasting");
// }

// bool isDeviceConnected() {
//     return deviceConnected;
// }

// void notifyCharacteristic1(const std::string &value) {
//     if (deviceConnected) {
//         pCharacteristic1->setValue(value);
//         pCharacteristic1->notify();
//     }
// }

// void setCharacteristic2WriteCallback(void (*callback)(const std::string &)) {
//     characteristic2WriteCallback = callback;
// }