int trigPin1 = 6; 
int echoPin1 =7; 
int trigPin2 =8; 
int echoPin2 =9;
long duration1, cm1,duration2,cm2;
void setup() {
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);

}
void loop() {
digitalWrite(trigPin1, LOW);
delayMicroseconds(5);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
pinMode(echoPin1, INPUT);
duration1 = pulseIn(echoPin1, HIGH);
cm1 = (duration1/2) / 29.1;
digitalWrite(trigPin2, LOW);
delayMicroseconds(5);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
pinMode(echoPin2, INPUT);
duration2 = pulseIn(echoPin2, HIGH);
cm2= (duration2/2) / 29.1; 
if(cm1<=10 && cm2>=30)
{
Serial.println("back");
delay(1000);
}
if(cm1>=30 && cm2<=10)
{Serial.println("next");
delay(1000);
}
if(cm1<=20 && cm2<=20)
{
Serial.println("space");
delay(1000);
}
}