#include <Arduino.h>
#include <TM1637Display.h>

// Definir los pines CLK y DIO
#define CLK 4
#define DIO 5

// Crear una instancia del objeto TM1637Display
TM1637Display display(CLK, DIO);

void setup() {
    // Inicializar el display
    display.setBrightness(0x0a); // establecer el brillo (0x00 a 0x0f)
}

void loop() {
    // Contador de ejemplo
    for(int i = 0; i <= 9999; i++) {
        display.showNumberDec(i, false); // mostrar el numero `i`
        delay(100); // retraso de 100 ms
    }
}