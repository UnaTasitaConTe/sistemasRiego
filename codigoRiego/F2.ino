
//captura de caracter por consola.
char leerCaracter() {
  if (Serial.available() > 0) {
    char caracter = Serial.read();
    return caracter;
  }
  else {
    return 0;
  }
}

//captura de entero por consola.
int leerEntero() {
  int num;
  while (Serial.available() == 0) {
  }
  num = Serial.parseInt();
  return num;
}

//función de apagado de riego.
void riegoApagado() {
  int rele = 7;
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
}

//funcion de encendido de riego.
void riegoEncendido() {
  int rele = 7;
  pinMode(rele, OUTPUT);
  digitalWrite(rele, LOW);
}

//encendido de riego y apagado de riego
void riego(boolean dato) {
  int rele = 7;
  if (dato) {
    pinMode(rele, OUTPUT);
    digitalWrite(rele, LOW);
  }
  else {
    pinMode(rele, OUTPUT);
    digitalWrite(rele, HIGH);
  }
}

//despligue de menu
void menu() {
  Serial.println("MENU DE MANEJO");
  Serial.println("Elija una opcion\na.Riego Automatico\nb.Riego Cronometrado");
  Serial.println("Para desactivar oprima c");
}

//funcion para riego automatico
void riegoAuto() {
  int rele = 7;
  pinMode(rele, OUTPUT);
  int sensorHumedad = analogRead(A0);
  if (sensorHumedad >= 600 && sensorHumedad > 1000) {
    digitalWrite(rele, LOW);
    delay(1000);
    Serial.println(sensorHumedad);
  }
  else {
    digitalWrite(rele, HIGH);
    delay(1000);
    Serial.println(sensorHumedad);
  }
  return;
}

// funcion para desactivar el riego.
void desactivacion() {
  char caracter = leerCaracter();
  if (caracter == 'c') {
    activacion = true;
    menu();
  }
}
