int red1=13;
int orange1=12;
int green1=11;
int red2=10;
int orange2=9;
int green2=8;
int red3=7;
int orange3=6;
int green3=5;
int red4=4;
int orange4=3;
int green4=2;
void route1GREEN(void)
{
  digitalWrite(red1,LOW);
  digitalWrite(orange1,LOW);
  digitalWrite(green1,HIGH);
  digitalWrite(red2,HIGH);
  digitalWrite(orange2,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(red3,HIGH);
  digitalWrite(orange3,LOW);
  digitalWrite(green3,LOW);
  digitalWrite(red4,HIGH);
  digitalWrite(orange4,LOW);
  digitalWrite(green4,LOW);
}
void route2ORANGE(void)
{
  digitalWrite(red1,HIGH);
  digitalWrite(orange1,LOW);
  digitalWrite(green1,LOW);
  digitalWrite(red2,LOW);
  digitalWrite(orange2,HIGH);
  digitalWrite(green2,LOW);
  digitalWrite(red3,HIGH);
  digitalWrite(orange3,LOW);
  digitalWrite(green3,LOW);
  digitalWrite(red4,HIGH);
  digitalWrite(orange4,LOW);
  digitalWrite(green4,LOW);
}
void route2GREEN(void)
{
  digitalWrite(red1,HIGH);
  digitalWrite(orange1,LOW);
  digitalWrite(green1,LOW);
  digitalWrite(red2,LOW);
  digitalWrite(orange2,LOW);
  digitalWrite(green2,HIGH);
  digitalWrite(red3,HIGH);
  digitalWrite(orange3,LOW);
  digitalWrite(green3,LOW);
  digitalWrite(red4,HIGH);
  digitalWrite(orange4,LOW);
  digitalWrite(green4,LOW);
}
void route3ORANGE(void)
{
  digitalWrite(red1,HIGH);
  digitalWrite(orange1,LOW);
  digitalWrite(green1,LOW);
  digitalWrite(red2,HIGH);
  digitalWrite(orange2,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(red3,LOW);
  digitalWrite(orange3,HIGH);
  digitalWrite(green3,LOW);
  digitalWrite(red4,HIGH);
  digitalWrite(orange4,LOW);
  digitalWrite(green4,LOW);
}
void route3GREEN(void)
{
  digitalWrite(red1,HIGH);
  digitalWrite(orange1,LOW);
  digitalWrite(green1,LOW);
  digitalWrite(red2,HIGH);
  digitalWrite(orange2,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(red3,LOW);
  digitalWrite(orange3,LOW);
  digitalWrite(green3,HIGH);
  digitalWrite(red4,HIGH);
  digitalWrite(orange4,LOW);
  digitalWrite(green4,LOW);
}
void route4ORANGE(void)
{
  digitalWrite(red1,HIGH);
  digitalWrite(orange1,LOW);
  digitalWrite(green1,LOW);
  digitalWrite(red2,HIGH);
  digitalWrite(orange2,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(red3,HIGH);
  digitalWrite(orange3,LOW);
  digitalWrite(green3,LOW);
  digitalWrite(red4,LOW);
  digitalWrite(orange4,HIGH);
  digitalWrite(green4,LOW);
}
void route4GREEN(void)
{
  digitalWrite(red1,HIGH);
  digitalWrite(orange1,LOW);
  digitalWrite(green1,LOW);
  digitalWrite(red2,HIGH);
  digitalWrite(orange2,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(red3,HIGH);
  digitalWrite(orange3,LOW);
  digitalWrite(green3,LOW);
  digitalWrite(red4,LOW);
  digitalWrite(orange4,LOW);
  digitalWrite(green4,HIGH);
}
void route1ORANGE(void)
{
  digitalWrite(red1,LOW);
  digitalWrite(orange1,HIGH);
  digitalWrite(green1,LOW);
  digitalWrite(red2,HIGH);
  digitalWrite(orange2,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(red3,HIGH);
  digitalWrite(orange3,LOW);
  digitalWrite(green3,LOW);
  digitalWrite(red4,HIGH);
  digitalWrite(orange4,LOW);
  digitalWrite(green4,LOW);
}
void setup()
{
  for(int i=2;i<=13;i++)
    pinMode(i,OUTPUT);
}
void loop()
{
  route1GREEN();
  delay(3000);
  route2ORANGE();
  delay(3000);
  route2GREEN();
  delay(3000);
  route3ORANGE();
  delay(3000);
  route3GREEN();
  delay(3000);
  route4ORANGE();
  delay(3000);
  route4GREEN();
  delay(3000);
  route1ORANGE();
  delay(3000);
}
