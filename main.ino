/**
 * switch list and real positions
 * 0 = entry left
 * 1 = entry right
 * 2 = sleep north left
 * 3 = sleep north right
 * 4 = sleep south left
 * 5 = sleep south right
 * 
 * light list and real position
 * 0 = entry 1
 * 1 = entry 2
 * 2 = living 1
 * 3 = living 2
 * 4 = living 3
 * 5 = living 4
 * 6 = sleeping 1
 * 7 = sleeping 2
 */
boolean arrrSwitchGroups[6][8] = {
  {true, true, true, true, true, true, false, false}, //Switch 0, Light 0 ... 8
  {false, false, false, false, false, false, false, true}, //Switch 1, Light 0 ... 8
  {true, true, true, true, true, true, false, false}, //Switch 2, Light 0 ... 8
  {false, false, false, false, false, false, true, false}, //Switch 3, Light 0 ... 8
  {true, true, true, true, true, true, false, false}, //Switch 4, Light 0 ... 8
  {false, false, false, false, false, false, false, true}  //Switch 5, Light 0 ... 8
};

/*
 * Wiring: 
 *  8 Solid State Relay Board: DC- => GND, DC+ => +5V, CH1...CH8 => Arduino: D5...D12
 *  Switching: GND => Switch in; A0...A5 => Switch out
 */
boolean arrrSwitch[6] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};

static const uint8_t analogPins[6] = {A0,A1,A2,A3,A4,A5};

boolean switchUsed = false;

int i, j, currentSwitch;

boolean lightStatus[8] = {HIGH,HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

void setup() {
  // put your setup code here, to run once:
  for(i=0;i<6;i++){
    pinMode(analogPins[i], INPUT_PULLUP);
  }
  
  for(i=0; i<8;i++){
    pinMode(i+5, OUTPUT); //use d5...d12, offset
    digitalWrite(i+5, lightStatus[i]); //use d5...d12, offset
  }
}

boolean switchChanged(int num){
  return (digitalRead(analogPins[num]) != arrrSwitch[num]);
}

void triggerSwitchStatus(int num){
  arrrSwitch[num] = !arrrSwitch[num];
}

void checkAndSwitch(int num){
  if(switchChanged(num)){
    triggerSwitchStatus(num);

    for(j=0;j<8;j++){
      if(arrrSwitchGroups[num][j]){
        lightStatus[j] = !lightStatus[j];
      }
    }

    switchUsed = true;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for(i=0;i<6;i++){
    checkAndSwitch(i);
  }

  //Apply all changes
  if(switchUsed){
    for(i=0; i<8;i++){
      digitalWrite(i+5, lightStatus[i]); //use d5...d12, offset
    }
    switchUsed = false;
  }
}
