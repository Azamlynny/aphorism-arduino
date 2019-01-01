#include <Mouse.h>
#include <Keyboard.h>

int buttonAPin = 8;
int buttonAState = 0;
int buttonBPin = 9;
int buttonBState = 0;

boolean triggered = false;
boolean brightness = false;

void setup() {
  pinMode(buttonAPin, INPUT_PULLUP);
  pinMode(buttonBPin, INPUT_PULLUP);
  srand (5);
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  buttonAState = digitalRead(buttonAPin);
  buttonBState = digitalRead(buttonBPin);
  
  if (buttonAState == LOW) {
    breakChromebook();
    triggered = true;
  }

  if (buttonBState == LOW){
    triggered = false;
  }
  
  if(triggered){
    spinScreen();
    invertColors(); 
    moveMouse();
    openPages(1);
    
  }
}

void breakChromebook() {
  openPages(1); 
  delay(1000);
  searchBar("Never going to give you up");
  delay(1000);
  openPages(1);
  delay(1000);
//  chromeVox();
  openTerminal();
  delay(3000);
  dockedMagnifier();
}

void openPages(int num){
   for (int i = 0; i < num; i++) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('t');
    delay(10);
    Keyboard.releaseAll();
  }
}

void moveMouse(){
  Mouse.move(rand() % 200 -199, rand() % 200 -199, 0);
}

void openTerminal(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  Keyboard.releaseAll();
  invertColors();
  spinScreen();
  delay(3000);
  Keyboard.println("help");
  delay(1000);
  Keyboard.println("top");
}

void searchBar(String input){//https://www.youtube.com/watch?v=dQw4w9WgXcQ
  Keyboard.println(input);
  delay(2000);
  for(int i=0; i < 19; i++){
    Keyboard.press(KEY_TAB);
    Keyboard.release(KEY_TAB);
    delay(10);
  }
  Keyboard.press(KEY_RETURN);
  delay(5000);
}

void spinScreen(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F3);
  Keyboard.releaseAll();
  delay(500);
}

void invertColors(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_GUI); 
  Keyboard.press('h'); 
  Keyboard.releaseAll();
}

void chromeVox(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('z');
  Keyboard.releaseAll();
}
void dockedMagnifier(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_GUI); 
  Keyboard.press('d');
}

//no work
//void biosMode(){
//  Keyboard.press(KEY_ESC);
//  Keyboard.press(KEY_F3);
//  Keyboard.press(KEY_F12);
//}

//No work
//void alternateBrightness(){ //16 keypresses to do
//  if(brightness){
//    Keyboard.release(KEY_F7);
//    Keyboard.press(KEY_F6);
//    brightness = false;
//  }
//  else if (brightness == false){
//    Keyboard.release(KEY_F6);
//    Keyboard.press(KEY_F7);
//    brightness == true;    
//  }
//}
