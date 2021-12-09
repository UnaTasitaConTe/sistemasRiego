char leerCaracter() { // funcion de leer un caracter
  if (Serial.available() > 0) {
    char caracter = Serial.read();
    return caracter;
  }
  else {
    return 0;
  }
}
int leerEntero() { // funcion de leer un entero
  int num;
  while (Serial.available() == 0) {
  }
  num = Serial.parseInt();
  return num;
}

void riegoApagado() {
  int rele = 7;
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
}
void riegoEncendido() {
  int rele = 7;
  pinMode(rele, OUTPUT);
  digitalWrite(rele, LOW);
}
void menu() {
  Serial.println("MENU DE MANEJO");
  Serial.println("Elija una opcion\na.Riego Automatico\nb.Riego Cronometrado");
  Serial.println("Para desactivar oprima c");
}
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
void desactivacion() {
  char caracter = leerCaracter();
  if (caracter == 'c') {
    activacion = true;
    menu();
  }
}
