//deklarasi pin sensor
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;
int dataSensor[6];

//deklarasi pin enable
int leftEN = 4;
int rightEN = 2;

//deklarasi pin motor kiri
int leftMotor1 = 5;
int leftMotor2 = 6;

//deklarasi pin motor kanan
int rightMotor1 = 3;
int rightMotor2 = 11;

void setup()
{
  //inisialisasi pin sensor
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  
  //inisialisasi pin enable
  pinMode(leftEN, OUTPUT);
  pinMode(rightEN, OUTPUT);
  
  //inisialisasi pin motor kiri
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  
  //inisialisasi pin motor kanan
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  
  Serial.begin(9600);
}

void readSensor(){
  dataSensor[0] = analogRead(sensor1);
  dataSensor[1] = analogRead(sensor2);
  dataSensor[2] = analogRead(sensor3);
  dataSensor[3] = analogRead(sensor4);
  dataSensor[4] = analogRead(sensor5);
  dataSensor[5] = analogRead(sensor6);
}

void loop()
{
  //maxData = 686
  //minData = 33
  readSensor();
 
  //sensor 1 & 2 mendeteksi gelap
  if(dataSensor[0] < 35 && dataSensor[1] < 35 && dataSensor[2] > 35 && dataSensor[3] > 35 && dataSensor[4] > 35 && dataSensor[5] > 35){
    digitalWrite(rightEN, HIGH);
  	digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    
    digitalWrite(leftEN, HIGH);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
  }
  
  //sensor 3 & 4 mendeteksi gelap
  if(dataSensor[0] > 35 && dataSensor[1] > 35 && dataSensor[2] < 35 && dataSensor[3] < 35 && dataSensor[4] > 35 && dataSensor[5] > 35){
   	digitalWrite(rightEN, HIGH);
  	digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    
    digitalWrite(leftEN, HIGH);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
  }
  
  //sensor 5 & 6 mendeteksi gelap
  if(dataSensor[0] > 35 && dataSensor[1] > 35 && dataSensor[2] > 35 && dataSensor[3] > 35 && dataSensor[4] < 35 && dataSensor[5] < 35){
    digitalWrite(rightEN, HIGH);
  	digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    
    digitalWrite(leftEN, HIGH);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
  }
  
  //semua sensor tidak mendeteksi gelap
  if(dataSensor[0] >35 && dataSensor[1] > 35 && dataSensor[2] > 35 && dataSensor[3] > 35 && dataSensor[4] > 35 && dataSensor[5] > 35){
   digitalWrite(rightEN, HIGH);
  	digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    
    digitalWrite(leftEN, HIGH);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW); 
  }
}