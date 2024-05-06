#define LED 5
void setup()
{
pinMode(LED,OUTPUT);
}
void loop()
{
digitalWrite(LED, HIGH);
delay(1000):
digitalWrite(LED,LOW);
delay(1000);
}
34
//For Multiple LED Bulb:
#define RLED 9
#define GLED 10
#define YLED 29
void setup()
{
pinMode(RLED,OUTPUT);
pinMode(GLED,OUTPUT);
pinMode(YLED,OUTPUT);
}
void loop()
{
digitalWrite(RLED, HIGH);
digitalWrite(GLED, HIGH);
digitalWrite(YLED, HIGH);
delay(1000):
digitalWrite(RLED,LOW);
digitalWrite(GLED,LOW);
digitalWrite(YLED,LOW);
delay(1000);
}