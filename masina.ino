#include <SoftwareSerial.h>
SoftwareSerial HM10(2, 3); 
char appData;  
String inData = "";

int ox = A1;
int oy = A0;
int but = 2;
int motor1pin3 = 12;
int motor1pin4 = 13;
int steer1pin1 = 9;
int steer1pin2 = 8;
int ENA=10;
int ENB=11;

void setup() {
  pinMode(motor1pin3, OUTPUT);
  pinMode(motor1pin4, OUTPUT);
  pinMode(ENB, OUTPUT); 
  
  pinMode(ox, INPUT);
  pinMode(oy, INPUT);
  pinMode(but, INPUT_PULLUP);

  Serial.begin(9600);
}

void joystick(int & mapX,int & mapY)
{
  int xAxis = analogRead(ox);
  int yAxis = analogRead(oy);
  int Buton = !digitalRead(but);
   mapX = -map(analogRead(ox), 0, 1023, -500, 500);
   mapY = map(analogRead(oy), 0, 1023, -500, 500);
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(Buton);
}


void motor_steer(int x,int y,int & a)
{
  if(x>50)
  {
    a=map(x,0,500,80,255);
    analogWrite(ENB, a);
    digitalWrite(motor1pin3, HIGH);
    digitalWrite(motor1pin4, LOW);
  }
  if(x<-50)
  {
    int a=map(x,0,-500,80,255);
    analogWrite(ENB, a);
    digitalWrite(motor1pin3, LOW);
    digitalWrite(motor1pin4, HIGH);
  }
  if(x>-50 && x<50)
  {
    digitalWrite(motor1pin3, LOW);
    digitalWrite(motor1pin4, LOW);
  }

  //steer
  if(y>70)
  {
    analogWrite(ENA, 255);
    digitalWrite(steer1pin1, HIGH);
    digitalWrite(steer1pin2, LOW);
  }
  if(y<-70)
  {
    analogWrite(ENA, 255);
    digitalWrite(steer1pin1, LOW);
    digitalWrite(steer1pin2, HIGH);
  }
  if(y>-70 && y<70)
  {
    digitalWrite(steer1pin1, LOW);
    digitalWrite(steer1pin2, LOW);
  }
}

void loop() {
  /*
  analogWrite(ENB, 255); //ENA pin

  digitalWrite(motor1pin3, HIGH);
  digitalWrite(motor1pin4, LOW);
  delay(2000);

  digitalWrite(motor1pin3, LOW);
  digitalWrite(motor1pin4, HIGH);

  delay(2000);
  */
  int x,y,a;
  joystick(x,y);
  motor_steer(x,y,a);
  Serial.print("     ");
  Serial.println(a);
  delay(10);
}
