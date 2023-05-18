#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Stepper.h>
#include <AccelStepper.h>

//LiquidCrystal lcd (13, 12, 6 ,4, 3, 2);
LiquidCrystal lcd(53, 52, 46 , 44, 43, 42);
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'#', '0', '*'},
  {'9', '8', '7'},
  {'6', '5', '4'},
  {'3', '2', '1'},
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Definir los pines de salida a los que está conectado el motor


const int pin1N1 = 22;  // Conectado a 1N1
const int pin1N2 = 23;  // Conectado a 1N2
const int pin1N3 = 24;  // Conectado a 1N3
const int pin1N4 = 25;  // Conectado a 1N4


int delayTime = 10; // Tiempo de retardo entre pasos
int stepsPerRevolution = 200; // Número de pasos para una revolución completa


int code = 0;
int lcd_pos = 0;
AccelStepper stepper(AccelStepper::FULL4WIRE, pin1N1, pin1N3, pin1N2, pin1N4);

void setup() {
 
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Motor de paso:");
   // Configurar la velocidad máxima y aceleración del motor
  stepper.setMaxSpeed(500);     // Configura la velocidad máxima en pasos por segundo
  stepper.setAcceleration(500);  // Configura la aceleración en pasos por segundo por segundo
 
}

void loop() {

  lcd.setCursor(0,1);

  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    
    code+=key;
    lcd_pos++;
    lcd.setCursor(lcd_pos,1);
    lcd.print(key);
  }

  if(key == "*"){
      stepper.move(1000);  // Mueve 200 pasos en sentido horario
      stepper.runToPosition();

      delay(1000);  // Espera 1 segundo
  }

  
  
//  // Gira en sentido horario
//  stepper.move(1000);  // Mueve 200 pasos en sentido horario
//  stepper.runToPosition();
//
//  delay(1000);  // Espera 1 segundo
//
//  // Gira en sentido antihorario
//  stepper.move(-1000);  // Mueve 200 pasos en sentido antihorario
//  stepper.runToPosition();
//
//  delay(1000);  // Espera 1 segundo
  
}
