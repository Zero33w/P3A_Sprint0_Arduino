# P3A_Sprint0_Arduino
Toda la parte del sprint relacionada con el arduino y el envio de beacons desde este



//******************************************************  DESCRIPCIÓN  ****************************************************** 

El programa permite enviar beacons, monta su trama y reiteradamente va enviando beacons

//******************************************************  INSTALACIÓN  ****************************************************** 

Para poder ejecutar el programa correctamente es necesario seguir una serie de pasos que explicaré a continuación.

Primero configuraremos arduino para añadirle las bibliotecas del sparkfun nRF52840 Mini Breakout y que pueda usar Bluefruit.
<img src="/_imgReadme/ar1.jpg" alt=""/>

Lo principal es disponer de un sparkfun nRF52840 Mini Breakout y conectarlo mediante un puerto USB al ordenador que le cargará el programa.
Una vez conectado y encendido (activando la pestaña de la placa OFF-ON dejandola en ON), y en arduino buscar ese tipo de placa.
<img src="/_imgReadme/ar2.png" alt=""/>

Después tenemos que comprobar que el puerto seleccionado es el correcto, en caso de no estar seguro mirar los puertos que hay disponibles cuando el sensor esté conectado y retirar el sensor del puerto usb, tras eso volver a revisar los puertos disponibles, el que haya desaparecido es el puerto que nos interesa.

<img src="/_imgReadme/ar3.png" alt=""/>


Tras tener el puerto conectado y la placa correcta seleccionada, hay que ejecutar el programa. 
<img src="/_imgReadme/ar4.jpg" alt=""/>
