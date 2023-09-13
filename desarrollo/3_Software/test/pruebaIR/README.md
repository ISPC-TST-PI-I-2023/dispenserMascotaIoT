
# Comentarios sobre el codigo  

## Conexion de hardware**  

verde - out, al pin 13
lila - VCC, a 3.3V
azul - GND, a GND  

## Código para decodificación de señales IR en ESP32  

Este código está diseñado para recibir y decodificar señales de infrarrojos (IR) 
de un control remoto IR y mostrar el nombre de la tecla presionada en el Monitor Serial.

**Incluye las siguientes bibliotecas:**

Arduino.h: La biblioteca principal de Arduino.
IRremoteESP8266.h, IRrecv.h, IRutils.h: Bibliotecas para recibir y decodificar señales 
de infrarrojos (IR).  
  
IRremoteESP8266 by David Conran
Send and receive infrared signals with multiple protocols (ESP8266/ESP32)  


**Variables globales:**

RECV_PIN: Definición del pin de entrada para el receptor IR.
irrecv: Objeto para recibir señales de infrarrojos.
results: Estructura para almacenar los resultados de la decodificación de señales de infrarrojos.
lastValue: Almacena el último valor de la tecla presionada.

### void setup()  

Esta función se ejecuta una vez cuando el programa comienza. Inicia el puerto serial a una 
velocidad de 115200 baudios y habilita el receptor de infrarrojos.

### void loop()  

Esta función se ejecuta repetidamente después de setup(). Si se recibe y decodifica una señal
de infrarrojos, comprueba si el valor no es una repetición. Luego, mediante una declaración switch,
compara el valor de la tecla presionada con los códigos predefinidos de las teclas del control remoto.
Imprime el nombre de la tecla presionada en el Monitor Serial.

**Códigos de teclas del control remoto**  

El código actual utiliza códigos predefinidos para las teclas de un control remoto específico. Estos
códigos son únicos para cada tecla en el control remoto y son usados para identificar qué tecla ha 
sido presionada.

### Aquí están los códigos y las teclas asociadas utilizadas en este código:

0xFFA25D: CH-
0xFF629D: CH
0xFFE21D: CH+
0xFF22DD: <<
0xFF02FD: >>
0xFFC23D: >=
0xFFE01F: -
0xFFA857: +
0xFF906F: EQ
0xFF6897: 0
0xFF9867: 100+
0xFFB04F: 200+
0xFF30CF: 1
0xFF18E7: 2
0xFF7A85: 3
0xFF10EF: 4
0xFF38C7: 5
0xFF5AA5: 6
0xFF42BD: 7
0xFF4AB5: 8
0xFF52AD: 9

### Importante  

Los códigos de las teclas de su control remoto pueden ser diferentes. En este caso, deberá capturar 
y reemplazar los códigos en la declaración switch.

Además, este código no considera las situaciones en las que se presionan múltiples teclas al mismo 
tiempo. Si este es un caso de uso relevante para su aplicación, deberá ajustar el código para 
manejarlo.
