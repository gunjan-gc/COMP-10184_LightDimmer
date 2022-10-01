#include <Arduino.h> 

//  I Gunjan Chaudhary, 000831804 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else.

int buttonState =0;            //initially the led is set to off
int oldButtonState = LOW;
int ledState = LOW;

void setup()                                                          
{
  pinMode(D4, OUTPUT); 
  pinMode(D5, INPUT_PULLUP);                                            
}

void loop()
{ 
  buttonState = digitalRead(D5);   //Reading button state
  int reading=analogRead(A0);      //Reading the voltage out by potentiometer
  int bright=reading/4;  

  //if the old state of button is changed and currently button is high, then do toggle
  if(buttonState != oldButtonState  && buttonState == HIGH)
  {
    //if ledState was low then change it to high and vice versa. This will regulate on/off state
    //i.e., turn on if button clicked, and turn off if button clicked again and so on
    ledState = (ledState == LOW ? HIGH : LOW);
    digitalWrite(D4, ledState);           //digitalWrite on the led based on state
    delay(1000);                          //delay for 1s
  }
//if the ledState is low, then vary the brightness based on potentiometer's value change
//if state is high,  let the light remian turned off i.e., no light
  if( ledState == LOW)
  {  analogWrite(D4, bright);  }  //output brightness on led based on potentiometer's va;ue
oldButtonState = buttonState;    //update states
}  


