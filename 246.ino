const byte led = 19;
#define pot 15

void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  ledcAttachPin(led, 0);
  ledcSetup(0, 4000, 8);
}

void loop() {
  int analogValue = analogRead(pot);
  int brightness = map(analogValue, 0, 4095, 0, 255);
  ledcWrite(0, brightness);
  Serial.println(brightness);
  delay(30);
}
