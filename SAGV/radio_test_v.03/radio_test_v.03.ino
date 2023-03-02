byte X_PIN = 5;
byte Y_PIN = 11;
 
int x_value;
int y_value;
 
void setup() {
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  x_value = pulseIn(X_PIN, HIGH);
  y_value = pulseIn(Y_PIN, HIGH);
  Serial.println(x_value);
  Serial.println(y_value);
  delay(500);

}
