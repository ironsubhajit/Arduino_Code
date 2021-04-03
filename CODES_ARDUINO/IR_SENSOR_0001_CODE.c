// First the line following (IR) sensors
const int irLeft = 2; //Left line sensor is on pin A2
const int irRight = 3; //Right line sensor is on pin A3

//Motor A (Right)
int enableA = 11;
int pinA1 = 10;
int pinA2 = 9;

//Motor B (Left)
int enableB = 7;
int pinB1 = 6;
int pinB2 = 5;
//Define Run variable
boolean run;
void setup() {
pinMode(enableA, OUTPUT);
pinMode(pinA1, OUTPUT);
pinMode(pinA2, OUTPUT);
pinMode(enableB, OUTPUT);
pinMode(pinB1, OUTPUT);
pinMode(pinB2, OUTPUT);
}
void loop(){
  int valleft= analogRead(irLeft);
   int leftsensor = analogRead(A2);  //in the side of motor B
  int rightsensor = analogRead(A3);  //in the side of motor A

   if ((leftsensor >= 700) && (rightsensor >= 700))
     forward();
        else if((leftsensor <= 150) && (rightsensor <= 150))
     backward();
     else if((leftsensor <= 150) && (rightsensor >= 700))
     turnright();
     else if((leftsensor >= 700) && (rightsensor <= 150))
     turnleft();
}
//Motors Foward
void forward(){
  digitalWrite(pinA1,HIGH);
  digitalWrite(pinA2,LOW);
  digitalWrite(pinB1,HIGH);
  digitalWrite(pinB2,LOW);
}
// Motors Backward
void backward(){
  digitalWrite(pinA1,LOW);
  digitalWrite(pinA2,HIGH);
  digitalWrite(pinB1,LOW);
  digitalWrite(pinB2,HIGH);
}
// turn left
void turnleft(){
  digitalWrite(pinA1,HIGH);
  digitalWrite(pinA2,LOW);
  digitalWrite(pinB1,LOW);
  digitalWrite(pinB2,HIGH);
}
// turn right
void turnright(){
  digitalWrite(pinA1,LOW);
  digitalWrite(pinA2,HIGH);
  digitalWrite(pinB1,HIGH);
  digitalWrite(pinB2,LOW);
}
