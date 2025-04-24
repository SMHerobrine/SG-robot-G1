# WRO 2025 Future Engineers - Raspberry & Arduino self-driving robot

## Projekti lühikirjeldus
Robot, mis oskab:
- läbida rada iseseisvalt,
- reageerida liiklusmärkidele (roheline/punane),
- vältida takistusi,
- parkida paralleelselt õigesse tsooni.

## Tehniline arhitektuur
- Raspberry Pi 4 (põhilogiika)
- Arduino Uno (sensorite lugemine ja mootorijuhtimine)
- ESP32-CAM (märgituvastus)
- Ultraheliandurid (takistused ja parkimine)
- DC ja servomootorid (liikumine + roolimine)

## Kataloogistruktuur
- `/code/`
  - `movement/`
  - `vision/`
  - `sensors/`
- `/design/` – TinkerCAD mudelid
- `/docs/` – pildid, logid, juhendid
- `/media/` – videod ja turundus

## Installatsioon
1. Lae kood Raspberry ja Arduino peale
2. Ühenda komponendid vastavalt /docs/schematics.png
3. Käivita `main.py` Raspberry peal

## Video
[YouTube link siia]

## Meeskond
Nimekiri kõikidest 6 grupist ja nende ülesannetest

Grupp 1 - Liikumine
- Emma Tarus
- Liisa Naulainen
- Hanna Paju

Grupp 2 - Märgituvastus
- Boden Iam Greenwood
- Mirko Antti Vikat
- Karel Pagil

Grupp 3 - Parkimine ja Sensorid
- Mathias Mägi 
- Indrek Reisko
- Gert-Marol Kuris
- Herko Tamm

Grupp 4 - Kommunikatstioon
- Tarel Lakovitš
- Kert-Kristjan Rahu
- Karl Artur Sipelgas
- Ruudi Nellis
  
Grupp 5 - Testimine ja Analüüs
- Hubert Spitsõn
- Roven Reigo
- Sander Veel
- Artur Teller

Grupp 6 - Dokumentatsioon ja turundus
- Sten Markus Pihlas
- Marek Meinberg
- Henri Poopuu
