# Documentación del Código de Test para el Servo SG90 con ESP32  


## Descripción General

Este documento proporciona una descripción detallada del código de prueba para controlar un servo SG90 utilizando un ESP32. El servo SG90 es un motor de corriente continua utilizado comúnmente para controlar el movimiento angular en proyectos de robótica y automatización. En este caso, el ESP32 se utiliza como la plataforma de control para mover el servo a posiciones específicas.

## Requisitos Previos

* Librerias a utilizar: ESP32Servo by Kevin Harrington
* Hardware necesario: ESP32, servo SG90, cables de conexión, fuente de alimentacion de 5V.

## Configuración del Hardware

Asegúrese de que el hardware esté configurado correctamente antes de cargar el código de prueba. Esto incluye conectar el servo SG90 al ESP32 de la siguiente manera:

* GND: Cable marron (lila) a GND del ESP32
* 5V: Cable rojo (azul) a 5V del ESP32
* S: Cable naranja (verde) a pin 33 del ESP32

## Estructura del Código

El código de prueba para controlar el servo SG90 con el ESP32 se divide en varias secciones principales:

1. Inclusión de bibliotecas:
    * Incluye las bibliotecas necesarias para controlar el servo y utilizar el ESP32 (ESP32Servo by Kevin     Harrington).
2. Definición de pines:
    * Define el pin al que está conectado el servo como una constante (por ejemplo, const int servoPin = 33;).
3. Configuración inicial:
    * En la función setup(), realiza la configuración inicial del servo y otros componentes si es necesario.
4. Función de control del servo:
    * Implementa una función que controla el servo y mueve el servo a una posición específica. Puede ser necesario ajustar el ángulo de destino según las necesidades.
5. Función principal (`loop()`):
    * En la función principal, se llama a la función de control del servo para realizar movimientos.

## Uso del Código

* Cargue el código en el ESP32 utilizando el entorno de desarrollo de Arduino.

* Asegúrese de que el hardware esté correctamente conectado.

* Ejecute el código y observe cómo el servo se mueve a las posiciones especificadas.