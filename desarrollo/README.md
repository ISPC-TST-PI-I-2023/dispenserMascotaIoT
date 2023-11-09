### Metodología

En la Figura se presenta un esquema general del sistema implementado.   
Está compuesto por tres partes: 
- Sistema de Comunicación  
- Sistema de Control  
- Sistema de Alimentación Eléctrica y Respaldo de Energía.

![figura1](/desarrollo/assets/Figura1.png)
Esquema general del sistema implementado.


El Sistema de Control se basa en un ESP32 que es el dispositivo controlador que administra todos los sensores y ejecuta las acciones de dispensación de alimento y agua a través de distintos actuadores. Todos los datos de nivel de agua y alimento en los reservorios, así como las notificaciones de actividades realizadas y las alertas son enviadas por comunicación serial a la tarjeta Raspberry Pi.

El Sistema de Comunicación está conformado por tres componentes: una aplicación web, un servidor de comunicaciones y una tarjeta Raspberry Pi con su cámara. Su diseño está basado en IoT, para lo cual, se emplea el protocolo MQTT, el mismo que trabaja bajo el modelo de comunicación publicador/suscriptor. En donde los nodos, en este caso la Raspberry Pi, se comunican con la app mediante topics o colas de mensajes a través de un Broker MQTT. Esto permite al usuario el envío de comandos a su dispensador y a la vez la recepción de datos y notificaciones enviados por el sistema de control.

A través de estos sistemas se ha implementado la arquitectura IoT de la siguiente figura, en la cual, los datos generados en el dispensador (niveles de alimento y agua, notificaciones de actividad y alertas) son transportados por el protocolo MQTT a través de Internet, para luego ser procesados y presentados como información al usuario por medio de la app en Android. De la misma manera, los datos de comandos accionados por medio de la app son enviados al dispensador.

![figura2](/desarrollo/assets/Figura2.png)

Adicionalmente, el Sistema de Alimentación Eléctrica y Respaldo de Energía proporciona alta disponibilidad de la energía necesaria para el funcionamiento de todos los dispositivos electrónicos que conforman el dispensador. Para ello cuenta con una UPS (Uninterrumptible Power System) y baterías que brindan un respaldo de energía de aproximadamente 200 minutos en caso de ausencia de energía eléctrica comercial.

## Sistema de Comunicación

El Sistema de Comunicación es un sistema de software distribuido, el cual está definido por un conjunto de funcionalidades de software organizadas en tres capas: la capa de Presentación, la capa de Lógica de Negocio y la capa de Datos como se indica en la siguiente figura. Estas capas lógicas del sistema software se encuentran distribuidas en los tres sistemas de cómputo del sistema: la conexión WEB, el Servidor de Comunicaciones y la Raspberry Pi. El desarrollo de este sistema se basó en la metodología ágil Kanban.

![figura3](/desarrollo/assets/Figura3.png)
Arquitectura del software del Sistema de Comunicación.

La WEB permite al usuario enlazar su dispensador mediante un código TOKEN, registrar una cuenta e ingresar los datos de nombre, raza, peso y tamaño de la mascota. Con base en esta información, se le sugiere al dueño de la mascota una ración diaria adecuada, conforme a las sugerencias del alimento, o se permite crear un perfil personalizado de alimentación; es decir, puede ingresar la cantidad de gramos a dispensar, así como el número de porciones al día. También la WEB permite visualizar los niveles de alimento y agua en los reservorios mediante diagramas circulares dinámicos, activar el recambio de agua fresca, recibir notificaciones, alertas y visualizar el video de la mascota. Por esto la WEB cuenta con:


Una interfaz gráfica de usuario diseñada para su mejor adaptacion de necesidades de la mascota.

Un módulo de software para la comunicación MQTT con la Raspberry Pi aplicando el servicio WEB, lo que permite al usuario el envío de comandos al dispensador y a la vez la recepción de datos enviados por el sistema de control.

Una visualización del video que es proporcionado por el servicio web que se ejecuta en la Raspberry Pi.

El servidor de comunicaciones provee el servicio de Broker MQTT mediante Mosquitto [18] y un Servicio Web mediante Apache; además, alberga un motor de base de datos MongoDB para almacenar información de cuentas de usuarios y dispensadores. La app se comunicará con el Servicio Web para registrar la cuenta del usuario en la base de datos y enlazar con su respectivo dispensador. Una vez que se haya enlazado, la app consultará al Servicio Web los topics MQTT asociados al dispensador, los que servirán para una comunicación directa con el dispensador mediante el Broker MQTT.

La tarjeta Raspberry Pi es la que permite al dispensador la comunicación con la WEB a través de Internet; además, permite la visualización del video mediante su cámara. Es el punto de conexión con el Sistema de Control mediante comunicación serial; recibe las configuraciones del modo de dispensación y ejecuta una rutina de temporización que permite indicar al Sistema de Control que dispense la cantidad de gramos configurada en el momento correcto. El programa que se ejecuta en la Raspberry Pi incluye:


Un módulo de software para la comunicación MQTT con la app mediante la librería MQTT para Python. Permite recibir comandos como las configuraciones de dispensación y recambio de agua, además envía los niveles de alimento y agua, notificaciones de actividad y alertas del Sistema de Control.

Un servicio web mediante MJPG-streamer para transmitir el video que captura la cámara de la Raspberry Pi.

Los topics que se emplean en la comunicación MQTT se resumen en la Tabla 1.

![tabla](/desarrollo/assets/tabla.png)

## Sistema de Control

Este sistema es el encargado de ejecutar las acciones de dispensación de alimento y agua, así como de enviar datos de niveles, actividad y alertas. Está conformado por un ESP32, sensores de nivel y peso, y actuadores, como servoválvulas y un motor DC. Los drivers se seleccionaron para que el ESP32 pueda administrar los sensores y controlar los actuadores del prototipo.

Entre los sensores y actuadores se tienen: un sensor de peso con una celda de carga de 5 Kg, sensores de nivel continuo (ultrasónico) y discreto (infrarrojo), un sensor de corriente de efecto Hall, un motor DC, servomotores y válvulas. El sensor de corriente cumple la función de proteger el motor en caso de que se produzca un atasco durante la dispensación; además, el motor será controlado a través de un driver L293D.

La estructura del dispensador está constituida por dos reservorios, uno para agua y el otro para el alimento seco. Estos reservorios y demás piezas fueron diseñadas empleando Autodesk Inventor y posteriormente implementadas en acrílico (reservorios) e impresiones 3D. El mecanismo dispensador de agua está conformado por sensores de nivel en el reservorio y en el plato de la mascota, y tres servoválvulas. La primera para el ingreso automático de agua al reservorio, la segunda para dispensar agua al plato y la tercera para evacuar el agua que la mascota no ha consumido por algún tiempo. El mecanismo dispensador de alimento se basa en un tornillo sin fin; este tornillo es accionado por un motor DC que, en conjunto con un sensor de peso permiten dosificar el alimento de manera adecuada. El nivel de alimento en el reservorio es determinado a través de cinco sensores infrarrojos de presencia dispuestos en la respectiva tolva.

![Figura4](/desarrollo/assets/dispenser.png)

El ESP32 ejecuta un programa de control, cuyo proceso de automatización funciona de acuerdo con el diagrama de flujo de la siguiente figura; este programa se encarga de la coordinación de los elementos de control y de la adquisición de datos, así como el procesamiento e interpretación tanto de datos como de comandos que envía la aplicación móvil, para su posterior ejecución en el dispensador.

![Figura5](/desarrollo/assets/Figura5.png)

## Sistema de Alimentación Eléctrica y Respaldo de Energía

Este sistema se diseñó con el objetivo de proporcionar la energía necesaria a todos los dispositivos de control que trabajan con voltajes de 12 y 5 voltios DC. Todos estos elementos se encuentran alimentados por una fuente de poder para garantizar su correcta polarización y protección a los pines del sistema de control.

El prototipo cuenta con respaldo de energía de tal modo que pueda seguir operando en caso de ausencia de energía eléctrica. Con esto, se busca que el dispensador se mantenga en funcionamiento hasta que se recupere la energía eléctrica. Se realizaron mediciones del prototipo y en funcionamiento normal el consumo es de 24 watts. Para el prototipo desarrollado se empleó el UPS APC Power Saving Back-UPS Pro 1000, que tiene una potencia de 1000 VA, modo de transferencia on-line y cuenta con dos baterías internas de 24 V. Este UPS, para el consumo del prototipo, brinda una independencia aproximada de 206 minutos.

# Conclusiones

El dispensador desarrollado es un equipo fácil de configurar y controlar mediante la aplicación WEB, ha permitido al usuario una mayor independencia en el cuidado de su mascota. Además, se ha comprobado que IoT puede ser aplicado en áreas comunes de un hogar permitiendo mejorar la calidad de vida de las mascotas y sus dueños mediante la conexión de dispositivos inteligentes.

Por medio de este proyecto, se han mostrado soluciones a algunos problemas de los dispensadores comerciales. El equipo puede ser controlado remotamente por el usuario mediante una WEB y en el mismo equipo se cuenta tanto con dispensación de alimento como de agua. Adicionalmente, las porciones van acorde al tamaño, peso y raza de las mascotas. En base a esto, el equipo pesa la cantidad de gramos necesarios al dispensar y permite mantener el número de raciones recomendadas o preestablecidas por el usuario. También, se recambia el agua del plato de la mascota para proporcionarle agua siempre fresca. El usuario por medio de la aplicación WEB puede visualizar los niveles de alimento y agua en los reservorios, de la misma manera puede observar por medio de una cámara si su mascota toma agua o come su porción. También cuenta con un sistema de respaldo de energía para que siga funcionando cuando haya ausencia de energía eléctrica.