int distanceThreshold;
int cm1;
int cm2;
int buzzer;
void setup()
{
  Serial.begin(9600);
  //pinMode(2, INPUT);
  //pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  //pinMode(7, OUTPUT);
  //pinMode(8, OUTPUT);
  //pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);    // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);           // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);        // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
//long readUltrasonicDistance1(int triggerPin1, int echoPin1)
//{
 /*pinMode(triggerPin1, OUTPUT);    // Clear the trigger
  digitalWrite(triggerPin1, LOW);
  delayMicroseconds(2);           // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin1, LOW);
  pinMode(echoPin1, INPUT);        // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin1, HIGH);
}*/

void loop()
{
  // set threshold distance to activate LEDs
  distanceThreshold = 50;
  // measure the ping time in cm
  cm1= 0.01723* readUltrasonicDistance(3, 2);
 // cm2= 0.01723* readUltrasonicDistance1(5, 4);
  Serial.print("cm1=");
  Serial.println(cm1);
  Serial.print("cm2=");
  Serial.println(cm2);

  if (cm1> distanceThreshold && cm2> distanceThreshold) {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }

  if (cm1< distanceThreshold && cm2 < distanceThreshold) {
    // object  at same distance regions to both sensors
    if(cm1>= distanceThreshold-15 && cm2>= distanceThreshold-15){
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH); //GREEN and GREEN
    }
    if(cm1>= distanceThreshold-30 && cm2>= distanceThreshold-30 && cm1<= distanceThreshold-15 && cm2<= distanceThreshold-15){
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW); //YELLOW and YELLOW
    }
    
    if(cm1< distanceThreshold-30 && cm2< distanceThreshold-30){
    tone(6,800);
    delay(1000);
    noTone(6);
    delay(250);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);//RED and RED
    }
    // object  at different distance regions to both sensors
    if(cm1>= distanceThreshold-15 && cm2>= distanceThreshold-30 && cm2<= distanceThreshold-15){
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW); //GREEN and YELLOW
    }
    if(cm1>= distanceThreshold-15 && cm2<= distanceThreshold-30){
    tone(6,800);
    delay(1000);
    noTone(6);
    delay(250);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW); //GREEN and RED
     }
    if(cm1>= distanceThreshold-30 && cm1<= distanceThreshold-15 && cm2<= distanceThreshold-30){
    tone(6,800);
    delay(1000);
    noTone(6);
    delay(250);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW); //YELLOW and RED
    }
    if(cm2>= distanceThreshold-15 && cm1>= distanceThreshold-30 && cm1<= distanceThreshold-15){
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH); //YELLOW and GREEN
    }
    if(cm2>= distanceThreshold-15 && cm1<= distanceThreshold-30){
    tone(6,800);
    delay(1000);
    noTone(6);
    delay(250);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH); // RED and GREEN
    }
    if(cm2>= distanceThreshold-30 && cm2<= distanceThreshold-15 && cm1<= distanceThreshold-30){
    tone(6,800);
    delay(1000);
    noTone(6);
    delay(250);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW); //RED and YELLOW
    }
}
  // object  at different distance regions to each of the sensors
   if (cm1< distanceThreshold && cm2>= distanceThreshold) {
     digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
      if (cm1< distanceThreshold && cm1>= distanceThreshold-15){
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);} // NO LIGHT and GREEN
     if (cm1< distanceThreshold-15 && cm1>= distanceThreshold-30){
       digitalWrite(7, LOW);
       digitalWrite(8, HIGH);
       digitalWrite(9, LOW);} //NO LIGHT and YELLOW 
     if (cm1< distanceThreshold-30){
    tone(6,800);
    delay(1000);
    noTone(6);
    delay(250);
       digitalWrite(7, LOW);
       digitalWrite(8, LOW);
       digitalWrite(9, HIGH);} // NO LIGHT and RED 
  }  
 if (cm1> distanceThreshold && cm2< distanceThreshold) {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
     if (cm2< distanceThreshold && cm2>= distanceThreshold-15){
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);} // GREEN and NO LIGHT
     if (cm2< distanceThreshold-15 && cm2>= distanceThreshold-30){
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);} //YELLOW and NO LIGHT
     if (cm2< distanceThreshold-30){
    tone(6,800);
    delay(1000);
    noTone(6);
    delay(250);
       digitalWrite(10, HIGH);
       digitalWrite(11, LOW);
       digitalWrite(12, LOW);} //RED and NO LIGHT
    }
}