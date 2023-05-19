
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
int limite = 3; // limite de caracteres
String password = "321";
String input = "";
int pos = 0;
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Enter password");
}
  
void loop(){

  char key = keypad.getKey();
  
  if (key){
    if ( pos < limite){
       Serial.println(key);
       input+= key;
       lcd.setCursor(pos,1);
       lcd.print(key);
       pos++;

       if(pos == 3){
          if(strcmp(input,password) == 0){
            lcd.setCursor(0,1);
            lcd.print("correcto");
            
          }else{
            lcd.setCursor(0,1);
            lcd.print("incorrecto");
          }
       }
       
    } else {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("enter passwod");
      pos = 0;
      input = "";
    }
   
    
  }
}
