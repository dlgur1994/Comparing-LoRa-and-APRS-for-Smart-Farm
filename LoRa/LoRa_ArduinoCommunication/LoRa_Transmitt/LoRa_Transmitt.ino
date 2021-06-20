#include <SPI.h>
#include <LoRa.h>
int counter = 0;
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Sender");
if (!LoRa.begin(915E6)) { /*LoRa.begin(frequency)*/
    Serial.println("Starting LoRa failed!");
    while (1);
  }else{
   LoRa.setTxPower(13);
    LoRa.setSignalBandwidth(125E3);
    LoRa.setCodingRate4(5);
}

}
void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);
  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();
  counter++;
  delay(5000);
}
