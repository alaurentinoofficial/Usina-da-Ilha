#define tempPin 4
#define co2Pin A0

#define velaPin 5
#define queimaLedPin 6
#define duracaoQueima 1000

void setup() {
  pinMode(velaPin, OUTPUT);
  pinMode(queimaLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float temp = (5.0 * analogRead(tempPin) * 100.0) / 1024;
  float co2 = map(analogRead(co2Pin), 0, 1023, 0, 100);

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C\n");

  Serial.print("Nivel de CO2: ");
  Serial.print(co2);
  Serial.println("%\n");

  pulseTime(velaPin, 300);
  digitalWrite(queimaLedPin, HIGH);
  delay(duracaoQueima);
  digitalWrite(queimaLedPin, LOW);

  // Apagar()
}

void pulseTime(int port, int mili) {
  digitalWrite(port, HIGH);
  delay(mili);
  digitalWrite(port, LOW);
}
