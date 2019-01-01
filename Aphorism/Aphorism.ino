#include <Mouse.h>
#include <Keyboard.h>

int buttonAPin = 9;
int buttonAState = 0;
char ctrlKey = KEY_LEFT_GUI;
boolean triggered = false;

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

void alternateBrightness(){

}
}
