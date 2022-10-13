#include <bluefruit.h>

//la función inicializa la placa y establece la configuración basica
//()
void setup() {
  
   Serial.begin(115200);
   //while ( !Serial ) delay(10);

   Serial.println("-----------------------\n");
   Serial.println(" PRUEBAS iBeacon  ");
   Serial.println("-----------------------\n");

   // Initialise the Bluefruit module
   Serial.println("Initialise the Bluefruit nRF52 module");
   Bluefruit.begin();

   
   // Set the advertised device name (keep it short!)
   Serial.println("Setting Device Name to GTI-S0 " );

   //nombre del beacon
   Bluefruit.setName("GTI-S0");
   Bluefruit.ScanResponse.addName();

  
   //startAdvertising();
   Serial.println("\nAdvertising");

} // setup()


//La función congigura el beacon que va a enviar, recibe la id del sensor y el valor que mide y los mete en la trama del beacon y los envia
// N, N ->()
void startAdvertising(int idSensor, int valorMedicion) {
   Serial.println( " startAdvertising() " );
   Serial.println( " Bluefruit.Advertising.stop(); ");
   Bluefruit.Advertising.stop(); 

   // Advertising packet
   
   Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
   Bluefruit.Advertising.addTxPower();

   // Include Name
   Serial.println( " Bluefruit.Advertising.addName(); " );
   Bluefruit.Advertising.addName();

   Serial.println( " Bluefruit.Advertising.setBeacon( elBeacon ); ");

   uint8_t beaconUUID[16] = {
     'E', 'P', 'S', 'G', '-', 'G', 'T', 'I',
     '-', 'P', 'R', 'O', 'Y', '-', 'G', 'G'
     };
   BLEBeacon elBeacon( beaconUUID, idSensor, valorMedicion, 73 );
   elBeacon.setManufacturer( 0x004c ); // aple id
   Bluefruit.Advertising.setBeacon( elBeacon );

   Bluefruit.Advertising.restartOnDisconnect(true);
   Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
   Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
   Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds

   Serial.println( " Bluefruit.Advertising.start(0);" );

} // startAdvertising ()

namespace Loop {
   int cont = 0;
};

//la funcion llama cada 1 segundo a la función startAdvertising pasandole la id del sensor y el valor del contador que simula los valores medidos
//()
void loop() {

   using namespace Loop;

   cont++;

   delay(1000);

   startAdvertising(3,cont);
   
   Serial.print( " ** loop cont=" );
   Serial.println( cont );
} // loop()
