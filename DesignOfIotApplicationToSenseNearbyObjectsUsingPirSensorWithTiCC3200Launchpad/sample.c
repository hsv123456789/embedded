nt pir=4;
int val = LOW;
void setup()
{
pinMode(pir, INPUT);
Serial.begin(9600);
}
void loop() {
val = digitalRead(pir);
if (val = = HIGH)
{
Serial.println(“Motion Detected”);
}
else
{
Serial.println(“Motion NOT Detected”);
}
}
