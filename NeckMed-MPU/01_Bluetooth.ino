#include <string>
using namespace std;

#define SERVICE_UUID "81721cb1-d932-4846-b9f4-862e34258388"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define STATE_AND_DURATION_CHARACTERISTIC_UUID "1387dc17-e9c4-4447-bfeb-019be5eb269e"



BLECharacteristic *pCharacteristic;
BLECharacteristic *pStateAndDurationCharacteristic;

BLEServer *pServer;


bool connected = false;

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    Serial.println("Connected");
    connected = true;
    digitalWrite(22, HIGH);
  };

  void onDisconnect(BLEServer *pServer) {
    Serial.println("Disconnected");
    pServer->getAdvertising()->start();
    connected = false;
    digitalWrite(22, LOW);
  }
};


class CharacteristicsCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    Serial.print("Value Written ");
    Serial.println(pCharacteristic->getValue().c_str());
    calibrateAccelerometer();
  }

  // void onRead(BLECharacteristic *pCharacteristic) {
  //   Serial.println("READING");
  // 	Serial.println(pCharacteristic->getValue().c_str());
  // }
};

void setupBLE() {
  Serial.println("Starting BLE work!");

  BLEDevice::init("Neckmed-baikhati");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());


  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_NOTIFY);

  pStateAndDurationCharacteristic = pService->createCharacteristic(
    STATE_AND_DURATION_CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_NOTIFY);


  pCharacteristic->setCallbacks(new CharacteristicsCallbacks());
  pService->start();
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}


// leher ke depan minimal 14
//

void sendData() {
  string data = to_string(pitch) + " " + to_string(roll);
  pCharacteristic->setValue(data);
  pCharacteristic->notify();
}

void sendStateAndDurationData(){
  string data = to_string(neck_state) + " " + to_string(danger_duration);
  Serial.println(data.c_str());

  pStateAndDurationCharacteristic->setValue(data);
  pStateAndDurationCharacteristic->notify();
}