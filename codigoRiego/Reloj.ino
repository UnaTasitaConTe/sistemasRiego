#define countof(a) (sizeof(a) / sizeof(a[0]))

//imprime la fecha que tiene almacenada el reloj.
void printDateTime(const RtcDateTime& dt) {
  char datestring[20];
  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Month(),
             dt.Day(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  Serial.print(datestring);
}

/*comprobacion de hora, esta función es parte de la documentación de los ejemplos proporcionados por la librerias
   la neta no se que hace xd, en su momento solo Dios y yo sabiamos como funcionaba esto ahora solo Dios.
   Pero esta con comentarios que traduje y eso :D
*/
void comprobacionReloj() {
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);// Le manda la informacion al Reloj para que configure la fecha y hora
  printDateTime(compiled);
  if (!Rtc.IsDateTimeValid())
  {
    // Common Causes:
    //    1) first time you ran and the device wasn't running yet
    //    2) the battery on the device is low or even missing

    Serial.println("RTC lost confidence in the DateTime!");
    Rtc.SetDateTime(compiled);
  }

  if (Rtc.GetIsWriteProtected())
  {
    Serial.println("RTC was write protected, enabling writing now");
    Rtc.SetIsWriteProtected(false);
  }

  if (!Rtc.GetIsRunning())
  {
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }

  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled)
  {
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(compiled);
  }
  else if (now > compiled)
  {
    Serial.println("RTC is newer than compile time. (this is expected)");
  }
  else if (now == compiled)
  {
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }
}
