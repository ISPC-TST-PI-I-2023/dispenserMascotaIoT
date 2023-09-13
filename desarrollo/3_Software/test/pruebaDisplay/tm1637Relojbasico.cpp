#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

int hours = 15;     //Configurar la hora inicial (en formato 24h)
int minutes = 30;   //Configurar los minutos iniciales

// prototipos
void displayTime(int hours, int minutes);

void setup()
{
    display.setBrightness(0x0f); // Máximo brillo
}

void loop()
{
    displayTime(hours, minutes);

    //Incrementar los minutos
    minutes++;
    if (minutes >= 60)
    {
        minutes = 0;
        hours++;
    }

    // Si la hora es mayor a 23, reiniciar a 0
    if (hours >= 24)
    {
        hours = 0;
    }

    delay(60000); // Esperar un minuto (60000 milisengundos)
}

void displayTime(int hours, int minutes)
{
    uint8_t timeData[] = {
        display.encodeDigit(hours / 10),
        display.encodeDigit(hours % 10),
        display.encodeDigit(minutes / 10),
        display.encodeDigit(minutes % 10)};
    display.setSegments(timeData);
}
