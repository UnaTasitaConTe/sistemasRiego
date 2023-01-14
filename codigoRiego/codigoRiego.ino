//Dwonload library ds1302 by makuma
//Descargar libreria ds1302 by makuma para correcto funcionamiento de este codigo.

//Inclusión de la librerias a usar.
#include <ThreeWire.h>
#include <RtcDS1302.h>

// inicio de las librerias.
ThreeWire myWire(4, 5, 2); // Pines seleccionado para el reloj por medio de la libreria de arduino
RtcDS1302<ThreeWire> Rtc(myWire);

//variables globales para el programa.
bool activacion;
int segundos = 2;

void setup() {
  Serial.begin(9600);
  Rtc.Begin();
  comprobacionReloj();
  menu();
}

void loop() {
  char caracter = leerCaracter();
  switch (caracter) {
    case 'a':
      activacion = false;
      Serial.println("Riego Automatico");
      while (activacion == false) {
        riegoAuto();
        desactivacion();
      }
      break;
    case 'b':
      activacion = false;
      riegoApagado();
      Serial.println("ingrese una hora");
      int hora = leerEntero();
      Serial.println(hora);
      Serial.println("Ingrese un Minuto");
      int minuto = leerEntero();
      Serial.println(minuto);
      while (activacion == false) {
        RtcDateTime now = Rtc.GetDateTime();
        if (hora == now.Hour() && minuto == now.Minute() && now.Second() <= segundos) {
          riegoEncendido();
          printDateTime(now);
          Serial.println();
          delay(1000);
        }
        else {
          riegoApagado();
          Serial.println("apagado");
          printDateTime(now);
          Serial.println();
          delay(1000);
        }
        desactivacion();
      }
  }
}
