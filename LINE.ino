// Black Line Follower 
int IL1=3;    
int IL2=4;
int IC=5;     
int IR1=6; 
int IR2=7;  
// motor one
int enA = 11;    //left motor
int MotorAip1=12;
int MotorAip2=13;
// motor two
int enB = 10;    //Right motor
int MotorBip1=8;
int MotorBip2=9;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IL1,INPUT);
  pinMode(IL2,INPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
}
void loop() 
{
   if(digitalRead(IL1)==HIGH && digitalRead(IL2)==HIGH && digitalRead(IC)==HIGH && digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH)
   //IR will not glow on black line
  {
    //Stop both Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
   analogWrite (enA, 0);
   analogWrite (enB, 0);
  }

  else if(digitalRead(IL1)==HIGH && digitalRead(IL2)==HIGH && digitalRead(IC)==LOW &&digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH)  
  {
    //Move both the Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  else if((digitalRead(IL1)==HIGH && digitalRead(IL2)==LOW && digitalRead(IC)==HIGH && digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH)||
  (digitalRead(IL1)==LOW && digitalRead(IL2)==HIGH && digitalRead(IC)==HIGH && digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH)||
  (digitalRead(IL1)==LOW && digitalRead(IL2)==LOW && digitalRead(IC)==HIGH && digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH)||
  (digitalRead(IL1)==LOW && digitalRead(IL2)==LOW && digitalRead(IC)==LOW && digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH)||
  (digitalRead(IL1)==LOW && digitalRead(IL2)==LOW && digitalRead(IC)==LOW && digitalRead(IR1)==LOW && digitalRead(IR2)==HIGH))
  {
     //Tilt robot towards left by stopping the left wheel and moving the right one
    
    digitalWrite(MotorAip1,LOW);     
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 150);
    analogWrite (enB, 200);
   delay(100);
  }

  else if((digitalRead(IL1)==HIGH && digitalRead(IL2)==HIGH && digitalRead(IC)==HIGH && digitalRead(IR1)==LOW && digitalRead(IR2)==HIGH)||
  (digitalRead(IL1)==HIGH && digitalRead(IL2)==HIGH && digitalRead(IC)==HIGH && digitalRead(IR1)==HIGH && digitalRead(IR2)==LOW)||
  (digitalRead(IL1)==HIGH && digitalRead(IL2)==HIGH && digitalRead(IC)==HIGH && digitalRead(IR1)==LOW && digitalRead(IR2)==LOW)||
  (digitalRead(IL1)==HIGH && digitalRead(IL2)==HIGH && digitalRead(IC)==LOW && digitalRead(IR1)==LOW && digitalRead(IR2)==LOW)||
  (digitalRead(IL1)==HIGH && digitalRead(IL2)==LOW && digitalRead(IC)==LOW && digitalRead(IR1)==LOW && digitalRead(IR2)==LOW))
  {
    //Tilt robot towards left by stopping the right wheel and moving the left one
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 150);
    delay(100);

  }
  
  else
  {
    //Stop both the motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
   analogWrite (enB, 0);
  }
}
