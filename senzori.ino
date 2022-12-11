int s1trigPin = 13;
int s1echoPin = 12;
int s2trigPin = 11;
int s2echoPin = 10;
int s3trigPin = 9;
int s3echoPin = 8;

int a=3;
int b=4;
int c=5;



void setup() {
Serial.begin(9600);

pinMode(s1trigPin, OUTPUT);
pinMode(s1echoPin, INPUT);
  pinMode(s2trigPin, OUTPUT);
pinMode(s2echoPin, INPUT);
  pinMode(s3trigPin, OUTPUT);
pinMode(s3echoPin, INPUT);

pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);

Serial.begin(9600);
}

void loop() {
  //1
  digitalWrite(s1trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(s1trigPin, LOW);
  long s1pulseLength = pulseIn(s1echoPin, HIGH);
  //2
  digitalWrite(s2trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(s2trigPin, LOW);
  long s2pulseLength = pulseIn(s2echoPin, HIGH);
  //3
  digitalWrite(s3trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(s3trigPin, LOW);
  long s3pulseLength = pulseIn(s3echoPin, HIGH);

  double s1distance = s1pulseLength / 58.0;
  double s2distance = s2pulseLength / 58.0;
  double s3distance = s3pulseLength / 58.0;


  if(s1distance<50)
  {
    digitalWrite(a,HIGH);
    
  }
  else
  {
    digitalWrite(a,LOW);
  }
  if(s2distance<50)
  {
    digitalWrite(b,HIGH);
  }
  else
  {
    digitalWrite(b,LOW);
  }
  if(s3distance<50)
  {
    digitalWrite(c,HIGH);
  }
  else
  {
    digitalWrite(c,LOW);
  }

Serial.print("Sensor1 "),Serial.println(s1distance);
Serial.print("Sensor2 "),Serial.println(s2distance);
Serial.print("Sensor3 "),Serial.println(s3distance);
Serial.println();
delay(500);
}
