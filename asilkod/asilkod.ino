byte leftMotor[] = {4, 5, 6, 7};
byte rightMotor[] = {8, 9, 10, 11};

byte route[][9] = {
  {0, 0, 0, 0},
  {0, 0, 0, 1},
  {0, 0, 1, 1},
  {0, 0, 1, 0},
  {0, 1, 1, 0},
  {0, 1, 0, 0},
  {1, 1, 0, 0},
  {1, 0, 0, 0},
  {1, 0, 0, 1}
};

byte leftMotorDirection = 1;
byte leftStep = 1;
byte rightMotorDirection = 2;
byte rightStep = 1;

int Steps = 0;
boolean Direction = true;// gre
unsigned long last_time;
unsigned long currentMillis ;
long time;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leftMotor[i], OUTPUT);
    pinMode(rightMotor[i], OUTPUT);
  }
}

void loop() {
  driveMotors();
}

void driveMotors(){
  currentMillis = micros();
  if (currentMillis - last_time >= 1000) {
    stepper();
    time = time + micros() - last_time;
    last_time = micros();
  }
}

void stepper() {
  if (leftStep > 8)
    leftStep = 1;
  else if(leftStep == 1)
    leftStep = 8;
  if (rightStep > 8)
    rightStep = 1;
  else if(rightStep == 1)
    rightStep = 8;
  
  if(leftMotorDirection == 1)
    leftStep++;
  else if(leftMotorDirection == 0)
    leftStep = 0;
  else if(leftMotorDirection == 2)
    leftStep--;
    
  if(rightMotorDirection == 1)
    rightStep++;
  else if(rightMotorDirection == 0)
    rightStep = 0;
  else if(rightMotorDirection == 2)
    rightStep--;
  
  for (int j = 0; j < 4; j++) {
    digitalWrite(leftMotor[j], route[leftStep][j]);
    digitalWrite(rightMotor[j], route[rightStep][j]);
  }
}
