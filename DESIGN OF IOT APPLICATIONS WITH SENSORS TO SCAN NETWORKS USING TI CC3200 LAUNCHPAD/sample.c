ifndef CC3200R1M1RGC
// Do not include SPI for CC3200LaunchPad
#include <SPI.h>
#endif
#include <WiFi.h>
void setup() {
//Initialize serial and wait for the port to open:
Serial.begin(115200);
WiFi.init();
Serial.println(WiFi.firmwareVersion());
// Print WiFi MAC address:
printMacAddress();
// scan for existing networks:
Serial.println("Scanning available networks...");
listNetworks();
}
void loop()
{
delay (10000);
// scan for existing networks:
Serial.println("Scanning available networks...");
listNetworks();
40
}
void printMacAddress()
{
// the MAC address of your Wifi
byte mac[6];
// print your MAC address:
WiFi.macAddress(mac);
Serial.print("MAC: ");
Serial.print(mac[5], HEX);
Serial.print(":");
Serial.print(mac[4], HEX);
Serial.print(":");
Serial.print(mac[3], HEX);
Serial.print(":");
Serial.print(mac[2], HEX);
Serial.print(":");
Serial.print(mac[1], HEX);
Serial.print(":");
Serial.println(mac[0], HEX);
}
void listNetworks()
{
// scan for nearby networks:
Serial.println("** Scan Networks**");
int numSsid = WiFi.scanNetworks();
if (numSsid == -1)
{
Serial.println("Couldn't get a wificonnection");
while (true);
}
// print the list of networks seen:
Serial.print("number of available networks:");
Serial.println(numSsid);
// print the network number and name for each network found:
for (int thisNet = 0; thisNet < numSsid; thisNet++)
{
Serial.print(thisNet);
Serial.print(") ");
Serial.print(WiFi.SSID(thisNet));
Serial.print("\tSignal: ");
Serial.print(WiFi.RSSI(thisNet));
Serial.print(" dBm");
Serial.print("\tEncryption: ");
printEncryptionType(WiFi.encryptionType(thisNet));
}
}
41
void printEncryptionType(int thisType) {
// read the encryption type and print out the name:
switch (thisType)
{
case ENC_TYPE_WEP:
Serial.println("WEP");
break;
case ENC_TYPE_TKIP:
Serial.println("WPA");
break;
case ENC_TYPE_CCMP:
Serial.println("WPA2");
break;
case ENC_TYPE_NONE:
Serial.println("None");
break;
case ENC_TYPE_AUTO:
Serial.println("Auto");
break;
}
}