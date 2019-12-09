#include <LibSemaforosCiudad.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() {

  //leer pulsador 1 y guardarlo en valor_pulsador1.
  estado_pulsador = pulsador.leer();
  
  if(estado_pulsador == PRESIONADO)
  {
    mostrar_cartel("Pulsador PRESIONADO\n");
  }
  else
  {
    mostrar_cartel("Pulsador NO PRESIONADO\n");
  }

  mostrar_cartel("----------------------------------\n");
  //espera 500 mSeg.
  delay(500);
}
