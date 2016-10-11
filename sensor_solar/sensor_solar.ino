
/*
***** Pregutas *****
* Son compatibles las interrupciones con los delays
*/

/*Analog pressure sensor
* Es necesario adaptar la señal analógica de 0-10 voltios de continua
* Es necesario enviar el dato de presión al servidor
* Es necesario calcular el dato de presión mediante tablas o fórmulas
*/
int pre_sen = A0; //connect presure sensor to analogic pin A0
int buzzer = 7;//connect buzzer to digital pin 7
int red_ld_pr = 8;//connect red led to digital pin 8 
int green_ld_pr = 9;//connect green led to digital pin 9
int threshold =300; //change the threshold value for your use
void setup(){

  /*Analog pressure sensor*/
   Serial.begin(9600); //initialize serial comunication at 9600 bps
   pinMode(red_ld_pr, OUTPUT);//define red_ld_pr as output
   pinMode(green_ld_pr, OUTPUT); //define green_ld_pr as output
   pinMode(buzzer, OUTPUT); //define buzzer as output
   digitalWrite(red_ld_pr, LOW);//red_ld_pr off
   digitalWrite(green_ld_pr, LOW);//green_ld_pr off
}
 
void loop()
{
    /*Analog pressure sensor*/
    int pre_sen = analogRead(pre_sen);//read pressure sensor value
    Serial.println(pre_sen);//print on serial monitor the sensor value
    if(pre_sen>=threshold){//check if it is exceeded the threshold value
        digitalWrite(red_ld_pr,HIGH);//red_ld_pr on
        digitalWrite(green_ld_pr,LOW);//green_ld_pr off
        tone(buzzer,200);//play buzzer
        Serial.println(" Attention threhold exceeded!!!");//print on serial monitor the overcoming threshold notice
        delay(500);
    }
    else{
        digitalWrite(red_ld_pr,LOW);//red_ld_pr off
        digitalWrite(green_ld_pr,HIGH);//green_red on
        noTone(buzzer); //no play buzzer 
    }
    delay(100); //slow down the output





    
}
