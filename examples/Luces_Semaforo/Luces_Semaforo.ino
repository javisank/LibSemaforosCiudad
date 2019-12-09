#include <LibSemaforosCiudad.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() 
{
  semaforo1.encender(ROJO);
  semaforo1.encender(AMARILLO);  
  semaforo1.encender(VERDE);
  
  delay(1000);    //espera de 1000 mSeg o 1 Seg.

  semaforo1.apagar(ROJO);
  semaforo1.apagar(AMARILLO);
  semaforo1.apagar(VERDE);

  semaforo2.encender(ROJO);
  semaforo2.encender(AMARILLO);
  semaforo2.encender(VERDE);

  delay(1000);    //espera de 1000 mSeg o 1 Seg.

  semaforo2.apagar(ROJO);
  semaforo2.apagar(AMARILLO);
  semaforo2.apagar(VERDE);

  semaforo3.encender(ROJO);
  semaforo3.encender(AMARILLO);
  semaforo3.encender(VERDE);

  delay(1000);    //espera de 1000 mSeg o 1 Seg.

  semaforo3.apagar(ROJO);
  semaforo3.apagar(AMARILLO);
  semaforo3.apagar(VERDE);

  semaforo4.encender(ROJO);
  semaforo4.encender(AMARILLO);
  semaforo4.encender(VERDE);

  delay(1000);    //espera de 1000 mSeg o 1 Seg.

  semaforo4.apagar(ROJO);
  semaforo4.apagar(AMARILLO);
  semaforo4.apagar(VERDE);
}

