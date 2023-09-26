// Reference: https://randomnerdtutorials.com/esp32-bluetooth-low-energy-ble-arduino-ide/
 
// // BLE SECTION
// BLEServer *pServer = NULL;

// BLECharacteristic *message_characteristic = NULL;
// BLECharacteristic *degree_characteristic = NULL;

// #define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
// #define DEGREE_UUID "6982c700-c237-11ec-9d64-0242ac120002"

// #define MESSAGE_CHARACTERISTIC_UUID "6d68efe5-04b6-4a85-abc4-c2670b7bf7fd"

// bool connected = false;

// class MyServerCallbacks : public BLEServerCallbacks
// {
//   void onConnect(BLEServer *pServer)
//   {
//     Serial.println("Connected");
//     connected = true;
//     digitalWrite(22, HIGH);
//   };

//   void onDisconnect(BLEServer *pServer)
//   {
//     Serial.println("Disconnected");
//     pServer->getAdvertising()->start();
//     connected = false;
//     digitalWrite(22, LOW);
//   }
// };

// class CharacteristicsCallbacks : public BLECharacteristicCallbacks
// {
//   void onWrite(BLECharacteristic *pCharacteristic)
//   {
//     Serial.print("Value Written ");
//     Serial.println(pCharacteristic->getValue().c_str());
//   }
// };

// void setup()
// {
//   Serial.begin(115200);
//   pinMode(13, INPUT);
//   pinMode(22, OUTPUT);

//   // Create the BLE Device
//   BLEDevice::init("Spine Flex");
//   // Create the BLE Server
//   pServer = BLEDevice::createServer();
//   pServer->setCallbacks(new MyServerCallbacks());
//   // Create the BLE Service
//   BLEService *pService = pServer->createService(SERVICE_UUID);
//   delay(100);

//   // Create a BLE Characteristic
//   degree_characteristic = pService->createCharacteristic(
//       DEGREE_UUID,
//       BLECharacteristic::PROPERTY_READ |
//           BLECharacteristic::PROPERTY_WRITE |
//           BLECharacteristic::PROPERTY_NOTIFY |
//           BLECharacteristic::PROPERTY_INDICATE);
//   message_characteristic = pService->createCharacteristic(
//       MESSAGE_CHARACTERISTIC_UUID,
//       BLECharacteristic::PROPERTY_READ |
//           BLECharacteristic::PROPERTY_WRITE |
//           BLECharacteristic::PROPERTY_NOTIFY |
//           BLECharacteristic::PROPERTY_INDICATE);

//   // Start the BLE service
//   pService->start();

//   // Start advertising
//   pServer->getAdvertising()->start();

//   degree_characteristic->setCallbacks(new CharacteristicsCallbacks());

//   message_characteristic->setValue("SAFE");
//   message_characteristic->setCallbacks(new CharacteristicsCallbacks());
//   Serial.println("Waiting for a client connection to notify...");
// }

// int minVal = 3000;
// int maxVal = 0;

// int duration = 0;
// bool on = true;
// bool aman = true;
// int i = 0;
// void loop()
// {
//   if (!connected) {
//     delay(100);
//     return;
//   }
//   int flex = analogRead(13);
//   int degree = map(flex, 2830, 3800, 0, 90);
//   degree = min(degree, 90);
//   degree = max(degree, 0);
//   if (degree >= 30) {
//     duration += 50;
//     if (duration >= 5000 && aman) {
//       aman = false;
//       message_characteristic->setValue("WARNING");
//       message_characteristic->notify();
//     }
//   }
//   else {
//     duration = 0;
//     if (!aman) {
//       aman = true;
//       message_characteristic->setValue("SAFE");
//       message_characteristic->notify();
//     }
//   }
//   if (i == 0) {
//     char degreeStr[3];
//     itoa(degree, degreeStr, 10);
//     degree_characteristic->setValue(degreeStr);
//     degree_characteristic->notify();
//   }
  
//   delay(50);
//   i++;
//   i %= 10;
// }