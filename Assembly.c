const int sensor_pin = A1;

  const int trigPin=8;

  const int echoPin=9;

  const int motor1=2;

  const int motor2=3;

  const int pir1=4;

  const int buzzer=10;

  long duration;

  int distance;

  float moisture;

  int ultrasonic;

  int pir_sensor;

  

void setup() {

  // put your setup code here, to run once:

  pinMode(buzzer,OUTPUT);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(motor1, OUTPUT);

  pinMode(motor2, OUTPUT);

  pinMode(pir1,INPUT);

  Serial.begin(9600);

}

void loop() {

  // put your main code here, to run repeatedly:

  digitalWrite(trigPin,LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin ,LOW);

  duration=pulseIn(echoPin,HIGH);

  distance=duration*0.034/2;

  Serial.print("Distance: ");

  Serial.println(distance);

  delay(100);

  int   sensor_analog = analogRead(sensor_pin);

  float moisture=(100-((sensor_analog/1023.00)*100));

  Serial.print("Moisture_Sensor:");

  Serial.print(moisture);

  Serial.print("%");

  Serial.println(" ");

  int pir_sensor=digitalRead(pir1);

  Serial.print("PIR_Sensor:");

  Serial.print(pir_sensor);

  Serial.println(" ");

  

  if(moisture>=30)

  {

    digitalWrite(motor1,HIGH);

    digitalWrite(motor2,LOW);

    delay(1000);

  }

  else

  {

    digitalWrite(motor1,LOW);

    digitalWrite(motor2,LOW);

    delay(1000);

  }

  if(distance<=100)

  {

  digitalWrite(buzzer,HIGH);

  delay(1000);

  digitalWrite(buzzer,LOW);

  delay(1000);

  } 

 if (pir_sensor==1)

  {

    digitalWrite(motor1,HIGH);

    digitalWrite(motor2,LOW);

    delay(1000);

  }

  else

  {

    digitalWrite(motor1,LOW);

    digitalWrite(motor2,LOW);

    delay(1000);

  }

}
