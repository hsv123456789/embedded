const int buttonPin = 8;
const int ledPin = 2;
int buttonState = 0;
void setup()
{
pinMode(ledPin,OUTPUT);
pinMode(buttonPin, INPUT);
Serial.begin(9600);
}
36
void loop()
{
buttonState = digitalRead(buttonPin);
if(buttonState == HIGH)
{
digitalWrite(ledPin,HIGH);
Serial.println(“LEDglows”);
}
else
{
digitalWrite(ledPin, LOW);
}
}