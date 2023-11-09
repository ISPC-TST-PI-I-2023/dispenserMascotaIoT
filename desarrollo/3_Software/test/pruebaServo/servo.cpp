#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo;  // Crea un objeto servo para controlar un servo

int pos = 0;    // Variable para almacenar la posición del servo

// Selecciona un pin PWM compatible para el ESP32. En este caso, usamos el pin 18.
int servoPin = 33;

void setup() {
	// Permite la asignación de todos los temporizadores
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
  
	myservo.setPeriodHertz(50);    // Configura el servo a 50 Hz
	myservo.attach(servoPin, 500, 2400); // Conecta el servo al pin seleccionado
}

void loop() {
	for (pos = 0; pos <= 180; pos += 1) { // Va de 0 a 180 grados en incrementos de 1 grado
		myservo.write(pos);  // Mueve el servo a la posición almacenada en 'pos'
		delay(15);           // Espera 15ms para que el servo alcance la posición
	}
	for (pos = 180; pos >= 0; pos -= 1) { // Va de 180 grados a 0 en decrementos de 1 grado
		myservo.write(pos);  // Mueve el servo a la posición almacenada en 'pos'
		delay(15);           // Espera 15ms para que el servo alcance la posición
	}
}


/*
Conexion Hardware: 

GND: Cable marron (lila) a GND del ESP32
5V: Cable rojo (azul) a 5V del ESP32
S: Cable naranja (verde) a pin 33 del ESP32

Explicación del Código

#include <ESP32Servo.h>: Incluye la biblioteca ESP32Servo.  
  
ESP32Servo by Kevin Harrington

Allows ESP32 boards to control servo, tone and analogWrite motors using Arduino semantics. 
This library can control a many types of servos.<br />It makes use of the ESP32 PWM timers: 
the library can control up to 16 servos on individual channels<br />No attempt has been made 
to support multiple servos per channel.<br />

Servo myservo;: Crea una variable myservo del tipo Servo.

myservo.attach(33);: Conecta el servo al pin 33 del ESP32 en la función setup().

En el bucle loop(), hay dos bucles for que mueven el servo desde 0 hasta 180 grados y viceversa. Se utiliza el método myservo.write(pos); para mover el servo a la posición pos.

delay(15);: Espera 15 milisegundos para darle tiempo al servo para alcanzar la posición deseada.

*/