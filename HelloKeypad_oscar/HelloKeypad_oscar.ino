/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {18, 17, 16, 15}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {14, 13, 12}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


// Configuracion
void setup(){
  Serial.begin(9600);

}
void configuraLed()
{//La configuración depende de como hemos conectado nuestros leds.
for (byte i=2;i<12;i++)
{
pinMode(i,OUTPUT);
apaga(i);
}
}

switch (key)
  {
    case '#':
      for (byte i=2;i<12;i++)
      {
        enciende(i);
        delay(100);
      }
      break;
    case '*':
      for (byte i=2;i<12;i++)
      {
        apaga(i);
        delay(100);
      }
      break;
    default:
      byte led= key - '0' + 2;
      estaEncendido(led) ? apaga(led):enciende(led);
      break;
  }


// funciones
void enciende(byte pin)
{
   digitalWrite(pin,LOW);
}
void apaga(byte pin)
{
   digitalWrite(pin,HIGH);
}

boolean estaEncendido(byte led)
{
  return !digitalRead(led);
}

  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
  
}


