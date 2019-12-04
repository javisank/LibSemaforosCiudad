/*
  LibSemaforosCiudad.h - Libreria para el manejo de la 
  estacion del cruce de calles con semaforos.
  Javier Sankowicz.
*/

#ifndef LibSemaforosCiudad_h
#define LibSemaforosCiudad_h

#include "Arduino.h"

#define ROJO 0
#define AMARILLO 1
#define VERDE 2

#define PRESIONADO LOW
#define NO_PRESIONADO HIGH

#define ACTIVADO LOW
#define DESACTIVADO HIGH

#define NOCHE 0
#define DIA 1

#define REPETIR(X) for(int i=0;i<X;i++)

const int pin_Semaforo1_rojo = 2;
const int pin_Semaforo1_amarillo = 3;
const int pin_Semaforo1_verde = 4;
const int pin_Semaforo2_rojo = 5;
const int pin_Semaforo2_amarillo = 6;
const int pin_Semaforo2_verde = 7;
const int pin_Semaforo3_rojo = 8;
const int pin_Semaforo3_amarillo = 9;
const int pin_Semaforo3_verde = 12;
const int pin_Semaforo4_rojo = 13;
const int pin_Semaforo4_amarillo = A0;
const int pin_Semaforo4_verde = A1;

const int pin_Pulsador = 11;
const int pin_Sensor_Luz = 10;


extern void mostrar_cartel(String);
extern void mostrar_numero(int num);
extern int ingresar_numero();
extern void inicializar_sistema();
extern void finalizar();


//Variables para manejo de sensores y pulsadores
extern int estado_sensor_luz;
extern int estado_pulsador;
extern int numero_ingresado;


//Variable Contador
extern int contador;


class Semaforo
{
  public:
    Semaforo(int pin_rojo,int pin_amarillo,int pin_verde);
    void encender(int luz);
    void apagar(int luz);
  private:
    int _pin_rojo;
	int _pin_amarillo;
	int _pin_verde;
};

class SensorLuz
{
	public:
		SensorLuz(int pin,int valorNoche,int valorDia);
		int leer();
		int leer_analogico();
		void esperar(int estado);
	private:
		int _pin;
		int _valorNoche;
		int _valorDia;
};

class Pulsador
{
	public:
		Pulsador(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
};

//Variables elementos del sistema

extern Pulsador pulsador;
extern SensorLuz sensor_luz;
extern Semaforo semaforo1;
extern Semaforo semaforo2;
extern Semaforo semaforo3;
extern Semaforo semaforo4;



#endif


