# Proyecto: 
<img src="desarrollo/assets/line.png" align="center">


# Dispenser automático de comida y agua para Mascotas con ESP32

![dispenser](/desarrollo/assets/dispenser%20final.png)

### Docente
<img src="desarrollo/assets/line.png" align="center">

- 👨‍🏫 **Cristian Gonzalo Vera**. Prof. Instituto Superior Politécnico Córdoba y Desarrolador IoT. [Ver Github](https://github.com/Gona79).

<img src="desarrollo/assets/line.png" align="center">

## Introducción:
Las mascotas son parte fundamental de muchos hogares en nuestro entorno y se las considera como parte de la familia; algunos dueños celebran sus cumpleaños, abren cuentas en redes sociales dedicadas a ellas o incluso las envían a guarderías. Cada vez las mascotas adquieren más derechos y protección mediante leyes. Pero a pesar de que las mascotas tienen un lugar importante en el hogar y en la sociedad, las personas a menudo no tienen el tiempo necesario para cuidarlas, alimentarlas e hidratarlas regularmente, ya sea por motivo de trabajo, viaje o incluso olvido. Por lo cual, el horario de alimentación e hidratación de las mascotas debe adaptarse al tiempo y criterio del dueño, permitiendo inclusive pasar toda una jornada sin los cuidados necesarios. Debido a esto, las personas buscan alternativas tecnológicas que faciliten el cuidado de sus mascotas, creándose así una demanda de soluciones innovadoras.

En páginas de e-commerce como Mercado Libre existe una gran variedad de dispensadores de alimento o agua para mascotas, tales como dispensadores mecánicos, dispensadores automáticos no controlados remotamente, entre otros. En general estos dispensadores, a pesar de brindar ayuda, tienen características limitadas, ya que se los debe programar localmente, no tienen una forma de administración remota a través de Internet, o son soluciones que proporcionan alimento en porciones fijas, sin considerar los requerimientos de cada mascota.

Es por tal razón, que el propósito del presente trabajo es presentar el desarrollo de una solución basada en IoT, que brinde una ayuda en la alimentación e hidratación de mascotas y principalmente pueda ser de gran ayuda a sus dueños. El desarrollo del proyecto ha permitido fusionar varias disciplinas, conceptos y herramientas en un mismo dispositivo, como lo son la automatización, la transmisión y gestión de datos a través de Internet, la integración de diferentes sistemas embebidos y el prototipado mediante impresión 3D.

Por medio del desarrollo de este dispositivo se ha podido dar soluciones a algunas limitaciones de los dispensadores comerciales. El equipo planteado es un dispositivo automático que puede ser monitoreado y controlado a través de Internet. Permite personalizar el tamaño y frecuencia de las porciones de alimento. Además, cuenta con dos reservorios, uno para almacenar alimento y otro para agua; cuenta con los respectivos sensores y actuadores, una tarjeta Arduino, una tarjeta Raspberry Pi e incluye una cámara de video. La pagina web se comunica mediante el protocolo MQTT con la Raspberry Pi del dispensador, lo que facilita el monitoreo de los niveles de alimento y agua en los reservorios, así como notificaciones de actividad y alertas de niveles bajos o atasco de alimento. Por esto, el prototipo implementado es un equipo completo y ofrece la versatilidad a los dueños de mascotas, de que por más lejos que se encuentren, puedan dar una alimentación e hidratación adecuada a su mascota con la ayuda de su dispositivo móvil.


### Componentes:

✔️ *Placa ESP32*

✔️ *Placa Raspberry PI"

✔️ *Sensores de nivel de agua y comida*

✔️ *Servomotores para la dispensación*

✔️ *Contenedores de comida y agua*

✔️ *Fuente de alimentación*

✔️ *Conectividad Wi-Fi*

![prototipo](/desarrollo/assets/dispenser.png)

### Características:

**Monitoreo de Niveles:** Los sensores de nivel detectarán cuándo los niveles de comida y agua estén bajos en los contenedores, activando automáticamente la dispensación.

**Dispensación Automática:** Cuando los sensores detecten niveles bajos, los motores o servomotores dispensarán la cantidad adecuada de comida o agua en los platos correspondientes.

**Conectividad Wi-Fi:** El ESP32 se conectará a tu red Wi-Fi para que puedas controlar y monitorear el dispensador a través de una aplicación móvil o una interfaz web.

**Programación Personalizada:** Podrás establecer horarios de alimentación y ajustar las cantidades de comida y agua según las necesidades de tus mascotas.

**Alertas y Notificaciones:** El sistema enviará notificaciones a tu dispositivo móvil cuando los niveles sean bajos, o cuando se realice una dispensación.

**Diseño Modular:** Los contenedores de comida y agua serán desmontables y fáciles de limpiar y rellenar.


## Resumen  

La búsqueda de alternativas que faciliten el cuidado y alimentación de una mascota ha creado la necesidad de aplicar en este campo el desarrollo tecnológico actual, ya que los dueños de mascotas ven restringido el tiempo disponible para pasar junto a ellas debido a sus ocupaciones diarias, estudios, trabajo o descuido. En la región, adquirir un dispositivo automático que dispense alimento y agua en un mismo equipo e incluya monitoreo remoto mediante una app en un smartphone es difícil y puede resultar costoso. Por tal razón, este trabajo presenta el desarrollo de un dispositivo inteligente basado en MQTT (Message Queuing Telemetry Transport) para dispensar alimento y agua para mascotas, capaz de ser monitoreado y controlado a través de un dispositivo móvil. Mediante la integración de múltiples tecnologías y herramientas como: lenguajes de programación, manejo de sensores y actuadores, Raspberry Pi, Arduino, diseño CAD (Computer-Aided Design) e impresiones 3D, esta solución IoT (Internet of Things) permite implementar un prototipo innovador que contribuye al bienestar de las mascotas no solo en nuestro país sino en toda la región. Las pruebas de funcionalidad validan que el dispositivo desarrollado tiene un tiempo de respuesta corto y permite a los dueños de mascotas mayor independencia y tranquilidad.
