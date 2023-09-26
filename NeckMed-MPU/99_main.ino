
// void setup(void) {
//   Serial.begin(115200);
//   setupMPU(); 
// }

// // leher ke depan minimal 14
// // 

// void loop() {
//   /* Get new sensor events with the readings */

//   mpu.getEvent(&a, &g, &temp);

//   convertAccelerationToPitchAndRoll(a.acceleration);
// }


void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens


  setupMPU();
  setupBLE();
} 




void loop() {

  /* Get new sensor events with the readings */
  mpu.getEvent(&a, &g, &temp);

  pitch = convertAccelerationToPitch(a.acceleration) - pitchOffset;
  roll = convertAccelerationToRoll(a.acceleration) - rollOffset;
  Serial.println("Pitch: " + String(pitch) + "\tRoll: " + String(roll));
  if(connected){
    sendData();
  }

  delay(500);
}