
void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens


  setupMPU();
  setupBLE();
} 

void loop() {

  pitch = getPitch();
  roll = getRoll();

  switch(neck_state){
    case SAFE_STATE:
      if(roll > dangerousNeckAngle){
        danger_timer_start = millis(); // in ms
        neck_state = DANGEROUS_STATE;
      }
      break;
    case INTERMEDIATE_STATE:
      if(roll > dangerousNeckAngle){
        neck_state = DANGEROUS_STATE;
      }
      if(millis() - stretch_timer_start > MINIMAL_STRETCH_DURATION){
        neck_state = SAFE_STATE;
        danger_duration = 0;
      }
      break;
    case DANGEROUS_STATE:
        danger_duration = (float)(millis() - danger_timer_start)/1000.0; // in ms
        if(roll < dangerousNeckAngle){
          neck_state = INTERMEDIATE_STATE;
          stretch_timer_start = millis();
        }
      break;
  }

  if(connected){
    sendData();
    sendStateAndDurationData();
  }

  

  delay(50);
}