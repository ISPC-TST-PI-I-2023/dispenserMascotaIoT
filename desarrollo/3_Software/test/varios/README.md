ok, volviendo al dispenser de mascota, vamos a ir haciendo el test del hardware. Por un lado tenemos un control remoto infrarojo, cuyo programa de control es el siguiente: 

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#define RECV_PIN 13 // define el pin de entrada para el receptor IR

IRrecv irrecv(RECV_PIN);

decode_results results;

// Almacena el último valor de la tecla presionada
uint64_t lastValue = 0;

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
        case 0xFF629D:
            Serial.println("CH presionado");
            break;
        case 0xFFE21D:
            Serial.println("CH+ presionado");
            break;
        case 0xFF22DD:
            Serial.println("<< presionado");
            break;
        case 0xFF02FD:
            Serial.println(">> presionado");
            break;
        case 0xFFC23D:
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
        case 0xFF42BD:
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

        irrecv.resume(); // Recibe la siguiente trama
    }
}

//

Bibliotecas
#include <Arduino.h>: Es la biblioteca principal para la programación de Arduino y provee las funciones básicas como digitalWrite(), Serial.begin(), etc.

#include <IRremoteESP8266.h>: Esta biblioteca es específica para el manejo de señales infrarrojas (IR) en dispositivos ESP8266. Facilita la recepción y decodificación de señales IR.

#include <IRrecv.h>: Esta biblioteca es parte del paquete IRremoteESP8266 y se utiliza para recibir señales IR.

#include <IRutils.h>: Esta biblioteca también es parte del paquete IRremoteESP8266 y proporciona utilidades adicionales, aunque en este código en particular no parece ser usada.

Variables y Constantes
#define RECV_PIN 13: Define el pin 13 como el pin de entrada para el receptor IR.

IRrecv irrecv(RECV_PIN): Crea una instancia de la clase IRrecv para manejar el pin de recepción.

decode_results results: Crea una estructura para almacenar los resultados decodificados de las señales IR recibidas.

uint64_t lastValue = 0: Almacena el último valor de la señal IR recibida.

Funciones
void setup(): Función de configuración inicial.
Serial.begin(115200): Inicia la comunicación serial con una tasa de baudios de 115200.
irrecv.enableIRIn(): Habilita la recepción de señales IR.
void loop(): Función principal que se ejecuta en un bucle infinito.
if (irrecv.decode(&results)): Verifica si se ha recibido una señal IR.
if (results.value != 0xFFFFFFFF): Verifica si la señal recibida es una señal de repetición. Si no lo es, guarda el valor en lastValue.

switch (lastValue): Un switch-case que compara lastValue con códigos predefinidos para realizar acciones correspondientes. Por ejemplo, si el código es 0xFFA25D, imprime "CH- presionado" en el monitor serial.

irrecv.resume(): Reinicia la recepción para capturar la siguiente señal IR.

En resumen, este programa se usa para decodificar señales IR recibidas y actuar en función del código de señal decodificado. Los códigos se imprimen en el monitor serial para depuración o futura referencia.

/*

SERVO

*/


Ejemplo básico de un programa de Arduino que controla un servomotor con un ESP32:


#include <Servo.h>

Servo myservo;  // crea un objeto servo para controlar el servomotor

int pos = 0;    // variable para almacenar la posición del servomotor

void setup() {
  myservo.attach(13);  // conecta el servomotor al pin GPIO 13 del ESP32
}

void loop() {
  // mueve el servomotor desde 0 grados hasta 180 grados
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);  // le dice al servomotor que vaya a la posición en la variable 'pos'
    delay(15);           // espera 15 ms para que el servomotor alcance la posición
  }
  // mueve el servomotor desde 180 grados hasta 0 grados
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);  // le dice al servomotor que vaya a la posición en la variable 'pos'
    delay(15);           // espera 15 ms para que el servomotor alcance la posición
  }
}


Explicación del código:
Bibliotecas
#include <Servo.h>: La biblioteca Servo se utiliza para controlar servomotores.
Variables
Servo myservo;: Declara un objeto Servo llamado myservo.
int pos = 0;: Declara una variable entera llamada pos para almacenar la posición actual del servomotor.

Funciones
void setup():
myservo.attach(13);: Conecta el objeto myservo al pin GPIO 13 del ESP32.
void loop():

El primer bucle for mueve el servomotor desde 0 grados hasta 180 grados incrementando 1 grado en cada iteración y esperando 15 ms en cada posición.

El segundo bucle for mueve el servomotor desde 180 grados hasta 0 grados disminuyendo 1 grado en cada iteración y esperando 15 ms en cada posición.
En este programa, el servomotor se conecta al pin GPIO 13 del ESP32 y se mueve de un extremo al otro. Puedes ajustar el código según tus necesidades.



/*

RTC DS3231

*/

Ejemplo de cómo manejar un RTC DS3231 con un ESP32 utilizando Arduino. Primero, necesitarás instalar la biblioteca "RTClib" para el DS3231 desde el administrador de bibliotecas de Arduino. Una vez hecho esto, podrás utilizar el siguiente código:


#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

void setup () {
  Serial.begin(115200);

  // Inicializa I2C
  Wire.begin();
  
  // Inicializa RTC DS3231
  if (! rtc.begin()) {
    Serial.println("No se encuentra un modulo RTC valido");
    while (1);
  }

  // Descomente la siguiente línea si desea establecer la fecha y hora. Una vez hecho, coméntelo de nuevo.
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop () {
  DateTime now = rtc.now();

  Serial.print("Fecha: ");
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  
  Serial.print(" Hora: ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  delay(1000);
}


Explicación del código:
Bibliotecas
#include <Wire.h>: Biblioteca para el manejo del bus I2C.
#include <RTClib.h>: Biblioteca para el manejo del RTC DS3231.
Variables
RTC_DS3231 rtc;: Declara un objeto RTC_DS3231 llamado rtc.
Funciones
void setup():
Inicializa la comunicación serial y el bus I2C.
Verifica que el RTC DS3231 esté conectado correctamente.
(Opcional) Establece la hora del RTC con el tiempo de compilación.
void loop():
Obtiene la hora actual desde el RTC.
Imprime la hora y fecha actuales.
Puedes descomentar la línea rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); para establecer la fecha y hora del RTC la primera vez que ejecutes el código. Luego, vuelve a comentarla para evitar que se restablezca la hora cada vez que se reinicie el ESP32.

/*
TM1637
*/


Controlar un módulo de visualización TM1637 con un ESP32, puedes utilizar la biblioteca TM1637Display, la cual está disponible en el administrador de bibliotecas de Arduino.


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
    display.showNumberDec(i, false); // mostrar el número 'i'
    delay(100); // retraso de 100 ms
  }
}
Explicación del código:
Bibliotecas
#include <TM1637Display.h>: Incluye la biblioteca necesaria para controlar el TM1637.
Variables y Constantes
#define CLK 4 y #define DIO 5: Estos definen los pines a los cuales el TM1637 está conectado.
TM1637Display display(CLK, DIO);: Esto crea una instancia de la clase TM1637Display, y se conecta a los pines CLK y DIO.
Funciones
void setup():
Inicializa el display con un brillo específico usando display.setBrightness(0x0a);.
void loop():
Cuenta del 0 al 9999 y muestra cada número en el display, con un retraso de 100 ms entre cada número.
Recuerda instalar la biblioteca TM1637Display antes de cargar este código en tu ESP32.

/* 
Componentes

*/

Hoja de Datos para Control de Componentes en Proyecto de Alimentador de Mascotas
Contenido
TM1637 Display de 4 Dígitos
RTC DS3231 - Reloj en Tiempo Real
Control Remoto Infrarrojo
1. TM1637 Display de 4 Dígitos
Descripción
Display LED de 4 dígitos.
Comunicación a través del protocolo I2C.
Compatible con ESP32.
Bibliotecas
TM1637Display.h
Conexiones
VCC a 3.3V del ESP32
GND a GND del ESP32
CLK a pin definido en el código (Ejemplo: D2)
DIO a pin definido en el código (Ejemplo: D3)
Código de Ejemplo
arduino
Copy code
#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);
2. RTC DS3231 - Reloj en Tiempo Real
Descripción
Reloj en tiempo real de alta precisión.
Comunicación I2C.
Compatible con ESP32.
Bibliotecas
RTClib.h
Conexiones
VCC a 3.3V del ESP32
GND a GND del ESP32
SDA a SDA del ESP32
SCL a SCL del ESP32
Código de Ejemplo
arduino
Copy code
#include <RTClib.h>
RTC_DS3231 rtc;

void setup() {
  rtc.begin();
}
3. Control Remoto Infrarrojo
Descripción
Control remoto infrarrojo para interacción inalámbrica.
Compatible con ESP32.
Bibliotecas
IRremoteESP8266.h
IRrecv.h
IRutils.h
Conexiones
VCC a 3.3V del ESP32
GND a GND del ESP32
Señal a pin definido en el código (Ejemplo: D13)
Código de Ejemplo
arduino
Copy code
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#define RECV_PIN 13
IRrecv irrecv(RECV_PIN);
Para mayor información, consulte la documentación de cada biblioteca y componente.