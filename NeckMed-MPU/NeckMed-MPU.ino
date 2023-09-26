// Basic demo for accelerometer readings from Adafruit MPU6050

// ESP32 Guide: https://RandomNerdTutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/
// ESP8266 Guide: https://RandomNerdTutorials.com/esp8266-nodemcu-mpu-6050-accelerometer-gyroscope-arduino/
// Arduino Guide: https://RandomNerdTutorials.com/arduino-mpu-6050-accelerometer-gyroscope/
#include <iostream>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
// #include "BluetoothSerial.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <string>
using namespace std;
float pitch, roll;

// BluetoothSerial SerialBT;

Adafruit_MPU6050 mpu;

float accelXOffset = 0.0;
float accelYOffset = 0.0;
float accelZOffset = 0.0;

float rollOffset = 0.0;
float pitchOffset = 0.0;
float convertAccelerationToPitch(sensors_vec_t accel){
  // Calculate pitch and roll angles from accelerometer data
  float accelX = accel.x;
  float accelY = accel.y;
  float accelZ = accel.z;
  float Pitch = atan2(-accelX, sqrt(accelY * accelY + accelZ *accelZ));
  Pitch = Pitch*180/M_PI;
  // Serial.println("KNTL: " +String(Pitch));
  delay(100);
  return Pitch;
}
float convertAccelerationToRoll(sensors_vec_t accel){
  // SerialBT.println(St+ring(pitch*180/M_PI) + "\t" + String(roll*180/M_PI));
  // Calculate pitch and roll angles from accelerometer data
  float accelX = accel.x;
  float accelY = accel.y;
  float accelZ = accel.z;
  float Roll = atan2(accelY, accelZ);
  Roll = Roll*180/M_PI;
  Serial.println("KNTL2: " + String(Roll));
  delay(100);
  return Roll;
}
void calibrateAccelerometer() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  pitchOffset = convertAccelerationToPitch(a.acceleration);
  rollOffset  = convertAccelerationToRoll(a.acceleration);
  Serial.println("pitchOffset: " + String(pitchOffset) + "\trollOffset: " + String(rollOffset));
}


#define SERVICE_UUID        "81721cb1-d932-4846-b9f4-862e34258388"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLECharacteristic *pCharacteristic;
BLEServer *pServer;

bool connected = false;

class MyServerCallbacks : public BLEServerCallbacks
{
  void onConnect(BLEServer *pServer)
  {
    Serial.println("Connected");
    connected = true;
    digitalWrite(22, HIGH);
    
  };

  void onDisconnect(BLEServer *pServer)
  {
    Serial.println("Disconnected");
    pServer->getAdvertising()->start();
    connected = false;
    digitalWrite(22, LOW);
  }
};

void setupMPU(){
    Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("");
  delay(100);

}
class CharacteristicsCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    Serial.print("Value Written ");
    Serial.println(pCharacteristic->getValue().c_str());
    calibrateAccelerometer();
  }

	// void onRead(BLECharacteristic *pCharacteristic) {
  //   Serial.println("READING");
	// 	Serial.println(pCharacteristic->getValue().c_str());
	// }
};

void setupBLE(){
  Serial.println("Starting BLE work!");

  BLEDevice::init("Neckmed-kntl");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  

  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE |
                                         BLECharacteristic::PROPERTY_NOTIFY
                                       );

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



void setup(void) {
  Serial.begin(115200);
  // SerialBT.begin("NeckMed");
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens


  setupMPU();
  setupBLE();
} 



// leher ke depan minimal 14
// 

void sendData(){
  // string data = std::format("Pitch: {}\tRoll: {}", pitch, roll);
  // Serial.println("data: " + data);
  string data = to_string(pitch) + " " + to_string(roll);
  // Serial.println(data.c_str());
  // pCharacteristic->setValue("neckmed-gblg");
  pCharacteristic->setValue(data);
  pCharacteristic->notify();
}
void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  pitch = convertAccelerationToPitch(a.acceleration) - pitchOffset;
  roll = convertAccelerationToRoll(a.acceleration) - rollOffset;
  Serial.println("Pitch: " + String(pitch) + "\tRoll: " + String(roll));
  if(connected){
    sendData();
  }

  delay(500);
}