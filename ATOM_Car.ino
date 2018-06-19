//Car controlled by voice commands through bluetooth module for arduino
#include<string.h>
//Initialize the pins in the Arduino for controlling motor driver
void setup() 
{
  //Pins 6 and 11 support PWM (Pulse Width Modulation)
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

//A function which will take the voice commands and controls the motor driver
void control_car(String message)
{
  //If the pin connection is as above
  //This will rotate both the front wheels in the car
  if(message=="forward")
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(6,255);
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    analogWrite(11,255);
    delay(5000); //Delay is given by default for 5 sec
  }
  //This will rotate both the back wheels in the car
  else if(message=="backward")
  {
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(6,255);
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    analogWrite(11,255);
    delay(5000);
  }
  //This will rotate only the right wheel
  else if(message=="left")
  {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    analogWrite(11,255);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    analogWrite(6,0);
    delay(5000);
  }
  //This will rotate only the left wheel
  else if(message=="right")
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(6,255);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    analogWrite(11,0);
    delay(5000); 
  }
  //This will stop the wheels
  else if(message=="stop")
  {
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    analogWrite(6,0);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    analogWrite(11,0); 
  }
}
//Voice control statements
String voice;
void loop() 
{
  while (Serial.available()) //Check if bluetooth module is connected and if bytes(characters) can be read from it
   {  
      delay(10); 
      char c = Serial.read(); //Read from the bluetooth module
      voice += c; 
      //Read character by character and append it to form a string
    } 
   
  if (voice.length() > 0) 
    { 
    Serial.println(voice); 
    
    /* Remove the above statement if you don't want it. 
    This is to print the message in the command-line interface for testing purposes */
    
    voice = string.toLowerCase(); //Convert the message to lower case for easy control in the function
    control_car(voice);
    voice = ""; //Make the existing string empty for new message
    }
}
