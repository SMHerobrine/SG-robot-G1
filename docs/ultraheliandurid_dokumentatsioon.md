
# 📡 Ultraheliandurite Kaugusemõõtmine (3 andurit)

**Failitüüp:** `.ino` (Arduino sketch)  
**Keel:** Arduino C++

## 🧾 Ülevaade

See kood mõõdab kolme ultrahelianduri (nt HC-SR04) abil kaugusi, kasutades `Trig` ja `Echo` pinne. Iga anduri kaugus kuvatakse Serial Monitoris.

---

## ⚙️ Riistvaralised eeldused

- Arduino (nt Uno, Nano)
- 3x HC-SR04 ultraheliandurit
- Juhtmed ühendamiseks
- Serial Monitor arvutis

---

## 🔌 Pinniühendused

| Andur | Trig Pin | Echo Pin |
|-------|----------|----------|
| 1     | 8        | 7        |
| 2     | 4        | 5        |
| 3     | 3        | 2        |

---

## 🧠 Koodi tööloogika

### 1. Trig- ja Echo-pinide määramine

```cpp
const int trigPins[3] = {8, 4, 3};
const int echoPins[3] = {7, 5, 2};
```

---

### 2. Seadistus (`setup()`)

```cpp
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }
}
```

---

### 3. Peatsüklis mõõtmine (`loop()`)

```cpp
for (int i = 0; i < 3; i++) {
  digitalWrite(trigPins[i], LOW);
  delayMicroseconds(2);
  digitalWrite(trigPins[i], HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPins[i], LOW);

  duration = pulseIn(echoPins[i], HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Andur ");
  Serial.print(i + 1);
  Serial.print(" kaugus: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);
}
Serial.println("----------------------");
delay(500);
```

---

## ✅ Väljund

Serial Monitoris kuvatakse iga anduri mõõdetud kaugus, näiteks:

```
Andur 1 kaugus: 23.45 cm
Andur 2 kaugus: 45.32 cm
Andur 3 kaugus: 18.91 cm
----------------------
```

---

## 💡 Märkused

- Kauguse valem: `kaugus = kestus * 0.034 / 2`, kus 0.034 cm/µs on heli kiirus.
- Veendu, et andurid ei häiriks üksteist — vajadusel kasuta pikemaid pause.
- Koodi on lihtne kohandada rohkematele või vähematele anduritele.
