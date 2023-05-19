
// practica sensor de temperatura
#include <Keypad.h>
#include <LiquidCrystal.h>

//LiquidCrystal lcd = (13, 12, 6 ,4, 3, 2);
LiquidCrystal lcd(53, 52, 46 ,44, 43, 42);
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = { 
  {'#','0','*'},                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
  {'9','8','7'},
  {'6','5','4'},
  {'3','2','1'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const int temperature = A0; //A0 is the analog pin  
const int Data = 28; // Vo of LCD is connected to pin 28 of the Arduino 

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  
  pinMode(Data, OUTPUT);  
}
  
void loop(){

  
  digitalWrite(Data,LOW);  
  int Temp = analogRead(temperature);  
  float volts = (Temp / 1023) * 5;  
  float celcius = (volts - 0.5) * 100;  
  float fahrenheit = (celcius * 9 / 5 + 32);  
  Serial.println(celcius);  
  lcd.setCursor(5, 0);  
  lcd.print(celcius);  
  delay(1500);  
   



 }
