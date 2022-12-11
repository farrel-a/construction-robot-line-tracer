// Motor 1 = Left
int motor1pin1 = 8;
int motor1pin2 = 9;
int motor1pinEN_PWM = 4;

// Motor 2 = Right
int motor2pin1 = 10;
int motor2pin2 = 11;
int motor2pinEN_PWM = 5;

// Motor PWM value from 0 to 255
int PWM = 80;

// IR Sensor
int IR1pin = 39; // IR1 = left
int IR2pin = 37; // IR2 = right

// Sensor Input Variables
bool IR1TouchesBlack, IR2TouchesBlack;

void setup() {
  //Motor PIN CONFIG
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor1pinEN_PWM, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT); 
  pinMode(motor2pinEN_PWM, OUTPUT);

  //IR PIN CONFIG
  pinMode(IR1pin, INPUT);
  pinMode(IR2pin, INPUT);

//  Serial.begin(9600);
}

void loop() {
    bool IR1TouchesBlack = digitalRead(IR1pin) == 1 ? true : false;
    bool IR2TouchesBlack = digitalRead(IR2pin) == 1 ? true : false;
    if (!IR1TouchesBlack && !IR2TouchesBlack){
//      Serial.println("MoveForward");
      moveForward();
    }
    else if (IR1TouchesBlack && !IR2TouchesBlack) {
//      Serial.println("MoveLeft");
      moveLeft();
    }
    else if (!IR1TouchesBlack && IR2TouchesBlack) {
//      Serial.println("MoveRight");
      moveRight();
    }
    else {
      idle();
    }
}

void moveForward(){
  //Motor 1 direction
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  //Motor 1 pwm
  analogWrite(motor1pinEN_PWM,PWM);

  //Motor 2 direction
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  //Motor 2 pwm
  analogWrite(motor2pinEN_PWM, PWM); 
}

void moveLeft(){
  //Motor 1 direction
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  //Motor 1 pwm
  analogWrite(motor1pinEN_PWM,PWM);

  //Motor 2 direction
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  //Motor 2 pwm
  analogWrite(motor2pinEN_PWM, PWM); 
}

void moveRight(){
  //Motor 1 direction
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  //Motor 1 pwm
  analogWrite(motor1pinEN_PWM,PWM);

  //Motor 2 direction
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  //Motor 2 pwm
  analogWrite(motor2pinEN_PWM, PWM); 
}

void idle(){
  //Motor 1 pwm
  analogWrite(motor1pinEN_PWM, 0);
  
  //Motor 2 pwm
  analogWrite(motor2pinEN_PWM, 0); 
}
