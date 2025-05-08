# 🎨 Värvituvastus Raspberry Pi kaameraga

**Failitee:** [`code/vision/color.py`](https://github.com/SMHerobrine/SG-robot-G1/blob/main/code/vision/color.py)

## 🧾 Ülevaade

See Python-programm tuvastab punased ja rohelised alad kaamerapildis, kasutades:
- Raspberry Pi kaamerat
- OpenCV-d
- HSV-värviruumi

Tuvastatud värvialad kuvatakse eraldi akendes.

---

## ⚙️ Eeldused

- Raspberry Pi koos töötava kaameraga
- Python 3
- Järgmised moodulid:
  - `picamera`
  - `opencv-python` (cv2)
  - `numpy`

---

## 🔄 Koodi töövoog

### 1. Kaamera seadistamine

```python
camera = picamera.PiCamera()
camera.resolution = (640, 480)
```

Määratakse kaamera resolutsiooniks 640x480 pikslit.

---

### 2. Pildi jäädvustamine

```python
image = np.empty((480, 640, 3), dtype=np.uint8)
camera.capture(image, "bgr")
```

Kaader salvestatakse NumPy massiivina BGR-vormingus (OpenCV standard).

---

### 3. Pildi teisendamine HSV-värviruumi

```python
hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
```

HSV-värviruum sobib hästi värvide eraldamiseks erinevates valgustingimustes.

---

### 4. Värvimaskide loomine

#### Punane

```python
lower_red = np.array([0, 120, 70])
upper_red = np.array([10, 255, 255])
red_mask = cv2.inRange(hsv_image, lower_red, upper_red)
```

#### Roheline

```python
lower_green = np.array([35, 100, 50])
upper_green = np.array([85, 255, 255])
green_mask = cv2.inRange(hsv_image, lower_green, upper_green)
```

---

### 5. Maskide rakendamine originaalpildile

```python
red_result = cv2.bitwise_and(image, image, mask=red_mask)
green_result = cv2.bitwise_and(image, image, mask=green_mask)
```

---

### 6. Tulemuste kuvamine

```python
cv2.imshow("Red Areas", red_result)
cv2.imshow("Green Areas", green_result)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

---

## ✅ Oodatud tulemus

Avanevad kaks akent:
- **Red Areas** – kuvab punased piirkonnad
- **Green Areas** – kuvab rohelised piirkonnad

---

## 💡 Märkused

- HSV piirväärtusi võib olla vaja muuta sõltuvalt valgusest ja kaamera tüübist.
- Teiste värvide jaoks saab lisada uusi HSV-vahemikke.
- Kood töötab Raspberry Pi Camera mooduliga, kuid kohandatav ka USB-kaamerale.
