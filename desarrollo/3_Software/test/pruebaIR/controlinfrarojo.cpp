#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
// #include <IRutils.h>

#define RECV_PIN 13  // define el pin de entrada para el receptor IR

IRrecv irrecv(RECV_PIN);

decode_results results;

// Almacena el último valor de la tecla presionada
uint16_t lastValue = 0;

void setup()
{
    Serial.begin(115200);
    irrecv.enableIRIn(); // Inicia el receptor
}

void loop()
{
    if (irrecv.decode(&results))
    {
        if (results.value != 0xFFFFFFFF)
        { // Si no es repetición
            lastValue = results.value;
        }

        switch (lastValue)
        {
        case 0xFFA25D:
            Serial.println("CH- presionado");
            break;
        case 0xFF6290:
            Serial.println("CH presionado");
            break;
        case 0xFFE21D:
            Serial.println("CH+ presionado");
            break;
        case 0xFF2200:
            Serial.println("<< presionado");
            break;
        case 0xFF02FD:
            Serial.println(">> presionado");
            break;
        case 0xFFC230:
            Serial.println(">= presionado");
            break;
        case 0xFFE01F:
            Serial.println("- presionado");
            break;
        case 0xFFA857:
            Serial.println("+ presionado");
            break;
        case 0xFF906F:
            Serial.println("EQ presionado");
            break;
        case 0xFF6897:
            Serial.println("0 presionado");
            break;
        case 0xFF9867:
            Serial.println("100+ presionado");
            break;
        case 0xFFB04F:
            Serial.println("200+ presionado");
            break;
        case 0xFF30CF:
            Serial.println("1 presionado");
            break;
        case 0xFF18E7:
            Serial.println("2 presionado");
            break;
        case 0xFF7A85:
            Serial.println("3 presionado");
            break;
        case 0xFF10EF:
            Serial.println("4 presionado");
            break;
        case 0xFF38C7:
            Serial.println("5 presionado");
            break;
        case 0xFF5AA5:
            Serial.println("6 presionado");
            break;
        case 0xFF4280:
            Serial.println("7 presionado");
            break;
        case 0xFF4AB5:
            Serial.println("8 presionado");
            break;
        case 0xFF52AD:
            Serial.println("9 presionado");
            break;
        case 0xFFFFFFFFFFFFFFFF: // Ignora el código de repetición
            break;
        default:
            Serial.println("Tecla desconocida presionada");
            break;
        }

        irrecv.resume(); //Recibe la siguiente trama
    }
}
