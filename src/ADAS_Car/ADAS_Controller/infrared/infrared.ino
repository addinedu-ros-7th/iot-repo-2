void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int light = analogRead(A0);
  if (light != 0){

    Serial.println(light);
  }
}
