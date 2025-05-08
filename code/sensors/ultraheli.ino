// Ultraheliandurite Trig ja Echo pinni määramine 

const int trigPins[3] = {
  8,
  4,
  3
};
const int echoPins[3] = {
  7,
  5,
  2
};

long duration;
float distance;

void setup() {
  Serial.begin(9600);

  // Määrame iga anduri Trig väljundiks ja Echo sisendiks 

  for (int i = 0; i < 3; i++) {

    pinMode(trigPins[i], OUTPUT);

    pinMode(echoPins[i], INPUT);

  }

}

void loop() {

  for (int i = 0; i < 3; i++) {

    // Saatmissignaal Trig'ile 

    digitalWrite(trigPins[i], LOW);

    delayMicroseconds(2);

    digitalWrite(trigPins[i], HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPins[i], LOW);

    // Vastuvõetav kestus Echo kaudu 

    duration = pulseIn(echoPins[i], HIGH);

    // Kauguse arvutamine (cm) 

    distance = duration * 0.034 / 2;

    // Tulemuste kuvamine Serial Monitoris 

    Serial.print("Andur ");

    Serial.print(i + 1);

    Serial.print(" kaugus: ");

    Serial.print(distance);

    Serial.println(" cm");

    delay(100); // Lühike paus iga anduri järel 

  }

  Serial.println("----------------------");

  delay(500); // Paus enne järgmist tsüklit 

}
