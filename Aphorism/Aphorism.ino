#include <Mouse.h>
#include <Keyboard.h>

int buttonAPin = 9;
int buttonAState = 0;
char ctrlKey = KEY_LEFT_GUI;
boolean triggered = false;
boolean brightness = false;

void setup() {
  pinMode(buttonAPin, INPUT_PULLUP);

  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  buttonAState = digitalRead(buttonAPin);

  if (buttonAState == LOW) {
    
    breakChromebook();
    triggered = true;
  }

  if(triggered){
    spinScreen();
    alternateBrightness();
  }
}

void breakChromebook() {
  for (int i = 0; i < 10; i++) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('t');
    delay(10);
    Keyboard.releaseAll();
  }
}

void spinScreen(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F3);
  Keyboard.releaseAll();
  delay(500);
}

void alternateBrightness(){ //16 keypresses to do
  if(brightness){
    for(int i = 0; i < 16; i++){
      Keyboard.press(KEY_F6); 
      delay(10);
    }
    brightness = false;
  }
  else if (brightness == false){
    for(int i = 0; i < 16; i++){
      Keyboard.press(KEY_F7);
      delay(10);
    }
    brightness == true;
  }
}
