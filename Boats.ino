//This sketch is also the final for CSC 235
//This sketch is for propellor moving a boat via a dc motor

//Global Variables
int motorPin1 = 6;
int motorPin2 = 3;
int butPin1 = 4; // white button
int butPin2 = 2;//small button
boolean debouncedButState1 = false;
boolean debouncedButState2 = false;
boolean prevButState1 = false;
boolean prevButState2 = false;
boolean motorOn1 = false;
boolean motorOn2 = false;
//Variables for timer
int startTime;
int interval;
int endtime;
//Second timer
int startTime2;
int interval2;
int endtime2;

boolean swirl = false; //// This is meant to be switch  but no can do. This turns propellors off in timer two :/



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  startTime = millis();
  interval = 8000;

  startTime2 = millis();
  interval2 = 8000;
}

void loop() {
  // put your main code here, to run repeatedly:


  //For Button 1
  debouncedButState1 = debounce(butPin1, prevButState1);


  if (debouncedButState1 == HIGH && prevButState1 == LOW) {
    //Serial.println("
    motorOn1 = !motorOn1;
    analogWrite(motorPin1, 255);
    startTime = millis();
    startTime2 = millis();


  }
  digitalWrite(motorPin1, motorOn1);

  prevButState1 = debouncedButState1;
  //For Button 2
  debouncedButState2 = debounce(butPin2, prevButState2);


  if (debouncedButState2 == HIGH && prevButState2 == LOW) {
    Serial.println("test");
    motorOn2 = !motorOn2;
    analogWrite(motorPin1, 255);
    startTime = millis();
    startTime2 = millis();
  }
  digitalWrite(motorPin2, motorOn2);

  prevButState2 = debouncedButState2;




  //fIRST TIMER- hi shaina
  if (swirl == false) {

    endtime = millis();
    if (endtime - startTime >= interval) {

      startTime2 = millis();
      swirl = true;
      Serial.println("go to state 2");
    }

    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
  }

  //Second Timer- 
  if (swirl == true) {

    endtime2 = millis();
    if (endtime2 - startTime2 >= interval2) {
      swirl = false;
      startTime = millis();
      Serial.println("go to state 1");
    }
    digitalWrite(motorPin1, LOW );
    digitalWrite(motorPin2, LOW);
  }


}



//Boolean Function to "bounce " the button
boolean debounce ( int aButtPin, int aPrevState) {
  boolean bouncyButState = digitalRead(aButtPin);
  if (bouncyButState == HIGH && aPrevState == LOW) {
    delay(200);
  }
  return bouncyButState;
}
