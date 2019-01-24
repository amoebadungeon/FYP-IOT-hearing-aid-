
#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <Servo.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " 665ee52ea4b74ceb9eb7bab18f6c0f4b";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "redmi";
char pass[] = "amin1233";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);
Servo servo;

void setup()
{
  // Debug console
  Serial.begin(9600);

 // delay(10);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
 

  Blynk.begin(auth, wifi, ssid, pass);
  servo.attach(9,0,180);
}
BLYNK_WRITE(V3)
{
    
   int  SrvoPos = param.asInt();  // Get slider value
  servo.write(SrvoPos);  // Move servo to value
   delay(50);// Set minimum delay for servo to reach desired position, keep as low as possible.
  
}
void loop()
{

  Blynk.run();
  
}

