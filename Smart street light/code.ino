int buld = 3;
int senor = A5;
int senor_val;
  
void setup()
{
  Serial.begin(9600);
  pinMode(buld,OUTPUT);
  pinMode(senor,INPUT);
}
void loop()
{
  senor_val = analogRead(senor);
  Serial.println(senor_val);
  if(senor_val>512)
    digitalWrite(buld,LOW);
  else
    digitalWrite(buld,HIGH);
}
