# 🧭 HMC5883L Kompassi Näidiskood (Arduino)

**Failitee:** [`docs/color.py`](https://github.com/SMHerobrine/SG-robot-G1/blob/main/docs/kompassi_n%C3%A4idiskood.ino)

## Ülevaade

See näidiskood võimaldab määrata suuna (kompassi suuna) kraadides, kasutades **HMC5883L magnetomeetrit** ja **Adafruit HMC5883_Unified** teeki. Kood rakendab eelnevalt mõõdetud offsetid (kalibreerimisandmed), et parandada täpsust.

---

## Riistvaranõuded

- Arduino (nt UNO, Nano, Mega)
- HMC5883L magnetomeetri andur
- Juhtmed anduri ühendamiseks I²C kaudu

---

## Tarkvaranõuded

- **Adafruit HMC5883L Unified Sensor Library**
- **Adafruit Sensor Library**

Installitavad Arduino IDE kaudu:  
**Sketch → Include Library → Manage Libraries…**

---

## Ühendused (I²C)

| HMC5883L pin | Arduino pin |
|--------------|-------------|
| VCC          | 3.3V või 5V |
| GND          | GND         |
| SDA          | A4 (Uno)    |
| SCL          | A5 (Uno)    |

> ⚠️ Muudel Arduinodel võivad I²C pin'id olla teised!

---

## Koodi töövoog

### 1. Teekide import ja anduri initsialiseerimine

```cpp
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

Adafruit_HMC5883_Unified compass = Adafruit_HMC5883_Unified(12345);
```

### 2. Kalibreerimisandmed

```cpp
const float x_offset = -12.955;
const float y_offset = 26.545;
```

> Need väärtused põhinevad varasematel mõõtmistel ja võivad iga anduri puhul erineda.

### 3. `setup()` funktsioon

```cpp
void setup() {
  Serial.begin(115200);
  if (!compass.begin()) {
    Serial.println("HMC5883L ei leitud! Kontrolli ühendusi.");
    while (1);
  }
  Serial.println("Korrigeeritud kompass töötab.");
  delay(1000);
}
```

### 4. `loop()` funktsioon

```cpp
void loop() {
  sensors_event_t event;
  compass.getEvent(&event);

  float x = event.magnetic.x - x_offset;
  float y = event.magnetic.y - y_offset;

  float heading = atan2(y, x);
  float headingDegrees = heading * 180.0 / PI;
  if (headingDegrees < 0) {
    headingDegrees += 360.0;
  }

  Serial.print("Suund: ");
  Serial.print(headingDegrees, 2);
  Serial.println("°");

  delay(200);
}
```

---

## Seriaalväljund (näide)

```
Korrigeeritud kompass töötab.
Suund: 87.34°
Suund: 88.12°
Suund: 89.45°
```

---

## Offsetide määramine (kalibreerimine)

1. Keera andurit ümber oma telje 360° ja salvesta maksimaalsed ja minimaalsed väärtused X- ja Y-teljel.
2. Arvuta offset:
   ```
   offset = (max + min) / 2
   ```

---
