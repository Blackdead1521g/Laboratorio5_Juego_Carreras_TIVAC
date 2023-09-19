/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +3.3V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 modified Apr 27 2012
 by Robert Wessels
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = PUSH2;     //Usamos el botón2 de la tiva para iniciar la secuencia
const int Button1 = 2; //Para el jugador 1
const int Button2 = 18; //Para el jugador 2
const int ledPinV =  GREEN_LED;      //Pin verde de la tiva
const int ledPinR =  RED_LED;      //Pin rojo de la tiva
//const int ledPinA =  BLUE_LED;      //Pin azul de la tiva


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int contador1 = 0;         // variable for reading the pushbutton status
int contador2 = 0;         // variable for reading the pushbutton status
int antirebote1 = 0;         // variable for reading the pushbutton status
int antirebote2 = 0;         // variable for reading the pushbutton status
bool inicio = false;

//Definimos como variables los pines de los contadores
#define J1_L1 3
#define J1_L2 4
#define J1_L3 5
#define J1_L4 6
#define J1_L5 7
#define J1_L6 8
#define J1_L7 9
#define J1_L8 10

#define J2_L1 23
#define J2_L2 24
#define J2_L3 25
#define J2_L4 26
#define J2_L5 27
#define J2_L6 28
#define J2_L7 29
#define J2_L8 19



void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinV, OUTPUT);      
  pinMode(ledPinR, OUTPUT); 

//Inicializamos los pines donde estarán los contadores
  pinMode(J1_L1, OUTPUT); 
  pinMode(J1_L2, OUTPUT); 
  pinMode(J1_L3, OUTPUT); 
  pinMode(J1_L4, OUTPUT); 
  pinMode(J1_L5, OUTPUT); 
  pinMode(J1_L6, OUTPUT); 
  pinMode(J1_L7, OUTPUT); 
  pinMode(J1_L8, OUTPUT); 

 pinMode(J2_L1, OUTPUT); 
 pinMode(J2_L2, OUTPUT); 
 pinMode(J2_L3, OUTPUT); 
 pinMode(J2_L4, OUTPUT); 
 pinMode(J2_L5, OUTPUT); 
 pinMode(J2_L6, OUTPUT); 
 pinMode(J2_L7, OUTPUT); 
 pinMode(J2_L8, OUTPUT); 
 
  // initialize the pushbutton pin que serán entradas:
  pinMode(buttonPin, INPUT_PULLUP);    
  pinMode(Button1, INPUT_PULLUP);     
  pinMode(Button2, INPUT_PULLUP);      
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {    //Si el boton de la secuencia se aprime 
    // turn LED on:    
    //Iniciamos la secuencia del RGB de la TIVA
    digitalWrite(ledPinR, HIGH);  
    delay(3000);
    digitalWrite(ledPinV, HIGH);  
    delay(3000);
    digitalWrite(ledPinR, LOW );  
    digitalWrite(ledPinV, HIGH);  
    delay(3000);
    digitalWrite(ledPinR, LOW); 
    digitalWrite(ledPinV, LOW); 
    inicio = true; //Al finalizar la secuencia ponemos en TRUE nuestra bandera
  } 
  else {
    // turn LED off:
    digitalWrite(ledPinR, LOW); 
    digitalWrite(ledPinV, LOW); 
  }

  if(inicio == true){ //Si la bandera se habilita mandamos a llamar a nuestras funciones para cada jugador
    jugador1();
    jugador2();
  }

}

void jugador1(){
  //Para antirebote
  if(digitalRead(Button1) == LOW){
    antirebote1 = 1;
  }

  if(antirebote1 == 1 && digitalRead(Button1) == HIGH){
     antirebote1 = 0;
     contador1 = contador1 + 1; //Incrementamos el contador
  }

   //Revisamos en que numero esta el contador para encender solo el led correspondiente y mantener apagados los demas
  switch(contador1){
    case 1:
      digitalWrite(J1_L1, HIGH);  
      break;
    case 2:
      digitalWrite(J1_L1, LOW);  
      digitalWrite(J1_L2, HIGH);
      break;  
    case 3:
      digitalWrite(J1_L2, LOW);
      digitalWrite(J1_L3, HIGH);
      break;  
    case 4:
      digitalWrite(J1_L3, LOW);
      digitalWrite(J1_L4, HIGH);
      break;  
    case 5:
      digitalWrite(J1_L4, LOW);
      digitalWrite(J1_L5, HIGH);
      break;  
    case 6:
      digitalWrite(J1_L5, LOW);
      digitalWrite(J1_L6, HIGH);
      break;  
    case 7:
      digitalWrite(J1_L6, LOW);
      digitalWrite(J1_L7, HIGH);
      break;  
    case 8:
      digitalWrite(J1_L7, LOW);
      digitalWrite(J1_L8, HIGH);  
      digitalWrite(ledPinR, HIGH);
      delay(5000);
      inicio = false; //Deshabilitamos nuestra bandera
      contador1 = 0;
      contador2 = 0;
      break;  
    default:
      digitalWrite(J1_L1, LOW);  
      digitalWrite(J1_L2, LOW); 
      digitalWrite(J1_L3, LOW); 
      digitalWrite(J1_L4, LOW); 
      digitalWrite(J1_L5, LOW); 
      digitalWrite(J1_L6, LOW); 
      digitalWrite(J1_L7, LOW); 
      digitalWrite(J1_L8, LOW); 
      break;
  }
  return;
}

void jugador2(){
  //Para antirebote
  if(digitalRead(Button2) == LOW){
    antirebote2 = 1;
  }

  if(antirebote2 == 1 && digitalRead(Button2) == HIGH){
     antirebote2 = 0;
     contador2 = contador2 + 1; //Incrementamos el contador
  }
  //Revisamos en que numero esta el contador para encender solo el led correspondiente y mantener apagados los demas 
  switch(contador2){
    case 1:
      digitalWrite(J2_L1, HIGH);  
      break;
    case 2:
      digitalWrite(J2_L1, LOW);  
      digitalWrite(J2_L2, HIGH); 
      break; 
    case 3:
      digitalWrite(J2_L2, LOW);
      digitalWrite(J2_L3, HIGH);  
      break;
    case 4:
      digitalWrite(J2_L3, LOW);
      digitalWrite(J2_L4, HIGH);  
      break;
    case 5:
      digitalWrite(J2_L4, LOW);
      digitalWrite(J2_L5, HIGH);  
      break;
    case 6:
      digitalWrite(J2_L5, LOW);
      digitalWrite(J2_L6, HIGH);  
      break;
    case 7:
      digitalWrite(J2_L6, LOW);
      digitalWrite(J2_L7, HIGH);  
      break;
    case 8:
      digitalWrite(J2_L7, LOW);
      digitalWrite(J2_L8, HIGH);  
      digitalWrite(ledPinV, HIGH); 
      delay(5000);
      inicio = false; //Deshabilitamos nuestra bandera
      contador2 = 0;
      contador1 = 0;
      break; 
    default:
      digitalWrite(J2_L1, LOW);  
      digitalWrite(J2_L2, LOW); 
      digitalWrite(J2_L3, LOW); 
      digitalWrite(J2_L4, LOW); 
      digitalWrite(J2_L5, LOW); 
      digitalWrite(J2_L6, LOW); 
      digitalWrite(J2_L7, LOW); 
      digitalWrite(J2_L8, LOW); 
      break;
  }
  return;
}
