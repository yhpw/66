// #include "BLEHandler.h"
// #include <Arduino.h>

// static BLEServer *pServer = NULL;
// static BLECharacteristic *pCharacteristic1 = NULL;
// static BLECharacteristic *pCharacteristic2 = NULL;
// static bool deviceConnected = false;
// static void (*characteristic2WriteCallback)(const std::string &) = nullptr;


// // �� BLEHandler.cpp �ļ������
// void sendConnectionSuccessMessage() {
//     if (deviceConnected) {
//         std::string successMessage = "���ӳɹ�";
//         pCharacteristic1->setValue(successMessage); // ��������ֵΪ���ӳɹ���Ϣ
//         pCharacteristic1->notify();                 // ����֪ͨ���ͻ���
//     }
// }


// class MyServerCallbacks: public BLEServerCallbacks {
//     void onConnect(BLEServer *pServer) {
//         Serial.println("�������ӳɹ�");
//         deviceConnected = true;
        
//     }

//     void onDisconnect(BLEServer *pServer) {
//         Serial.println("�����Ͽ�����");
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

//             // ������յ�������
//             if (characteristic2WriteCallback) {
//                 characteristic2WriteCallback(rxValue);
//             }

//             // ���ͻ�����Ϣ���ͻ���
//             std::string response = "Echo: " + rxValue; // ���ɻ�����Ϣ
//             pCharacteristic->setValue(response);       // ��������ֵΪ������Ϣ
//             pCharacteristic->notify();                  // ����֪ͨ���ͻ���
//         }
//     }
// };


// void initBLE() {
//     BLEDevice::init("ESP32 BLE Server");
//     pServer = BLEDevice::createServer();
//     pServer->setCallbacks(new MyServerCallbacks());

//     BLEService *pService = pServer->createService(SERVICE_UUID);

//     // ������������ UUID
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