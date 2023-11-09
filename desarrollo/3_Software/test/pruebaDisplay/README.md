
# Documentación del código Arduino para un reloj con alarmas usando TM1637  

**Descripción General**  

Este programa está diseñado para ser ejecutado en un microcontrolador ESP32 y utiliza la librería TM1637Display para controlar un módulo de visualización TM1637. El programa muestra la hora actual en el display, permite al usuario configurar la hora, el brillo del display y dos alarmas, y cambiar entre modos de 12 y 24 horas.  

### Bibliotecas  

<Arduino.h>: Biblioteca estándar de Arduino.
<TM1637Display.h>: Biblioteca para controlar el módulo de visualización TM1637.  
  
TM1637 by Avishay
Arduino library for TM1637 (LED Driver)

**Variables Globales**
hours, minutes, seconds: Variables para almacenar la hora actual.
is24Hour: Variable booleana para establecer el modo de 24 horas o 12 horas.
alarm1Hour, alarm1Minute, alarm2Hour, alarm2Minute: Variables para almacenar la hora de las dos alarmas.  

**Setup**
Se inicializan la comunicación serial y el display. Se muestra un menú en el monitor serial que presenta las opciones disponibles al usuario.

**Loop**
En cada ciclo del loop, el programa:

Actualiza y muestra la hora en el display.
Verifica si alguna de las alarmas debe activarse.
Actualiza la hora interna.
Lee y procesa cualquier entrada del usuario desde la comunicación serial.  

**Funciones**
displayTime(int hours, int minutes, bool colon)
Muestra la hora en el display TM1637. La variable colon indica si se debe mostrar el carácter de dos puntos entre las horas y los minutos.

setAlarm(int &alarmHour, int &alarmMinute)
Permite al usuario establecer la hora de una alarma. Las variables alarmHour y alarmMinute son pasadas por referencia y se modifican con los valores introducidos por el usuario.

checkAlarm(int alarmHour, int alarmMinute)
Verifica si la hora actual coincide con la hora de la alarma y, de ser así, imprime un mensaje en el monitor serial.  

**Observaciones**
El código incluye una variable brightness que se mueve fuera del bloque switch para evitar errores de compilación.
Se ha corregido el error de lectura de la hora mediante el uso de Serial.read() para capturar el espacio entre las horas y los minutos.  

**Notas sobre usabilidad**
Debido al uso de delay(1000), el código no es muy eficiente para leer la entrada del usuario.
Este código ofrece una forma sencilla de construir un reloj digital con alarmas utilizando un módulo de visualización TM1637 y un microcontrolador ESP32.