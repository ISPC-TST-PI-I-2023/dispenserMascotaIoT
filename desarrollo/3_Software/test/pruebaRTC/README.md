# Documentación del Código de Test para el RTC DS3231 con ESP32  

## Descripción General  

Este código de test se utiliza para verificar el funcionamiento del módulo de reloj en tiempo real (RTC) DS3231 con un ESP32. El test inicializa la comunicación I2C entre el ESP32 y el RTC, y luego muestra la hora y fecha actuales en el monitor serie.

## Dependencias  

Bibliotecas: Wire.h, SPI.h, RTClib.h
Hardware: ESP32, módulo RTC DS3231
Configuración de Pines
SDA_PIN = 21: Pin para la línea de datos serie (SDA) de I2C.
SCL_PIN = 22: Pin para la línea de reloj serie (SCL) de I2C.

## Funciones y Procedimientos  

setup()
Inicializa la comunicación I2C con pines específicos para SDA y SCL.
Inicializa la comunicación serie a una velocidad de 115200 baudios.
Verifica la presencia del módulo RTC.
Configura la hora y la fecha en el RTC usando el sistema de tiempo y fecha. (Opcional: ajuste manual)

loop()
Obtiene la hora y la fecha actuales del RTC.
Muestra la hora y la fecha en el monitor serie.
Introduce un retraso de 1 segundo antes de repetir el ciclo.

**Uso**
Conecta el módulo RTC a tu ESP32.
Sube el código a tu ESP32.
Abre el monitor serie.
Deberías ver la hora y la fecha actuales mostradas cada segundo.