#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>

RTC_DS3231 rtc;

const int SDA_PIN = 21; // Cambia estos valores según tu placa ESP32
const int SCL_PIN = 22;

void setup()
{
    Wire.begin(SDA_PIN, SCL_PIN); // Inicializa I2C con pines específicos para SDA y SCL
    Serial.begin(115200);

#ifndef ESP8266
    while (!Serial)
        ; // Espera a que el puerto serie se conecte. Necesario para USB nativo
#endif

    if (!rtc.begin())
    {
        Serial.println("No se encontró el módulo RTC. Verifique las conexiones.");
        while (1)
            ;
    }

    // Para configurar la hora y la fecha en el RTC (descomentar y ajustar la fecha y hora)
    // DateTime dt(2023, 8, 29, 12, 34, 56);
    // rtc.adjust(dt);

    // Establecer fecha y hora desde el systema
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

}

void loop()
{
    DateTime now = rtc.now(); // Obtiene la hora y la fecha actuales del RTC

    Serial.print("Fecha y Hora: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    delay(1000);
}