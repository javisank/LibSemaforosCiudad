/*
  LibSemaforosCiudad.cpp - Libreria para el manejo de la 
  estacion del cruce de calles con semaforos.
  Javier Sankowicz.
*/

#include "Arduino.h"
#include "LibSemaforosCiudad.h"

/* ************ Funciones de la clase Semaforo ************ */

Semaforo::Semaforo(int pin_rojo,int pin_amarillo,int pin_verde)
{
  pinMode(pin_rojo, OUTPUT);
  pinMode(pin_amarillo, OUTPUT);
  pinMode(pin_verde, OUTPUT);
  _pin_rojo = pin_rojo;
  _pin_amarillo = pin_amarillo;
  _pin_verde = pin_verde;
  digitalWrite(_pin_rojo,LOW);
  digitalWrite(_pin_amarillo,LOW);
  digitalWrite(_pin_verde,LOW);
}

void Semaforo::encender(int luz)
{
  switch(luz)
  {
	  case ROJO:
	  digitalWrite(_pin_rojo,HIGH);
	  break;
	  case AMARILLO:
	  digitalWrite(_pin_amarillo,HIGH);
	  break;
	  case VERDE:
	  digitalWrite(_pin_verde,HIGH);
	  break;
	  default:
	  break;
  }
}

void Semaforo::apagar(int luz)
{
	switch(luz)
	{
		case ROJO:
		digitalWrite(_pin_rojo,LOW);
		break;
		case AMARILLO:
		digitalWrite(_pin_amarillo,LOW);
		break;
		case VERDE:
		digitalWrite(_pin_verde,LOW);
		break;
		default:
		break;
  }
}

/* ********************************************************** */

/* ************ Funciones de la clase Sensor ************ */

Sensor::Sensor(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int Sensor::leer()
{
	return(digitalRead(_pin));
}

void Sensor::esperar(int estado)
{
	while(leer()!=estado);
} 

/* ********************************************************** */

/* ************ Funciones de la clase Pulsador ************** */

Pulsador::Pulsador(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int Pulsador::leer()
{
	return(digitalRead(_pin));
}

void Pulsador::esperar(int estado)
{
	while(leer()!=estado);
}

/* ********************************************************* */

/* ************Ingresar numero por puerto serie************** */

int ingresar_numero()   //devuelve un entero que va de -32768 a 32767
{
  String readString;
  
  while(!(Serial.available()>0));

  while(Serial.available()>0)
  {
    char c = Serial.read();
    readString += c;
    delay(2);
  }

  int number = readString.toInt();

  return number;
}

/* ********************************************************* */

/* ************Funciones imprimir texto********************* */

void mostrar_cartel(String text)
{
	Serial.print(text);
	Serial.print(" ");
}

void mostrar_numero(int num)
{
	Serial.println(num);
}

/* ********************************************************* */

/* *****************Inicializacion************************** */
void inicializar_sistema()
{
	Serial.begin(9600);
	
}
/* ********************************************************* */

/* ******************Finalizacion*************************** */
void finalizar()
{
	while(1);
}
/* ********************************************************* */

//Variables para manejo de sensores y pulsadores
int estado_sensor_luz=DIA;
int estado_pulsador=NO_PRESIONADO;
int numero_ingresado=0;

//Variable para contador
int contador=0;

//Variables elementos del sistema
Semaforo semaforo1(pin_Semaforo1_rojo,pin_Semaforo1_amarillo,pin_Semaforo1_verde);
Semaforo semaforo2(pin_Semaforo2_rojo,pin_Semaforo2_amarillo,pin_Semaforo2_verde);
Semaforo semaforo3(pin_Semaforo3_rojo,pin_Semaforo3_amarillo,pin_Semaforo3_verde);
Semaforo semaforo4(pin_Semaforo4_rojo,pin_Semaforo4_amarillo,pin_Semaforo4_verde);

Sensor sensor_luz(pin_sensor_ldr);

Pulsador pulsador(pin_Pulsador);