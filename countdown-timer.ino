#include <LiquidCrystal.h>

// Defining pins and variables
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buzzer = 9, button = 7;
int run;

// Setting LCD start message
void setup() {
  lcd.begin(16, 2);
  lcd.print("Press to start");
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // Reads pushbutton input
  if(digitalRead(button) == HIGH){
    if(run == 0){
      run = 255;
    }
  }    
  else{
    run = 0;
  }
  // When pushed once, run the code below
  if(run > 0){
    //
    for (int i=5; i>0; i--){
      lcd.setCursor(0,0);
      lcd.print("Counting down...");
      lcd.setCursor(0, 1);
      lcd.print(i);
      delay(1000);
      lcd.clear();
    }
    lcd.print("Time's UP!");
    int x = 0;
    while (x<3){
      tone(buzzer, 1000);
      delay(700);        
      noTone(buzzer);     
      delay(700); 
      x += 1;
    }
  }
}

