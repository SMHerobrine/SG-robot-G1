Path to Code: code/vision/color.py 

## Ülevaade 
See Python-programm tuvastab punased ja rohelised alad kaamerapildis, kasutades Raspberry Pi Camera, OpenCV-d ja HSV-värviruumi. Tuvastatud värvialad kuvatakse eraldi akendes. 


## Eeldused

- Raspberry Pi koos ühendatud ja seadistatud kaameraga
- Python 3 
- Järgmised moodulid peavad olema installitud: 
  -  picamera 
  - cv2 (OpenCV) 
  - numpy 

## Koodi töövoog 

1. Kaamera seadistamine: 

`camera = picamera.PiCamera()`

`camera.resolution = (640, 480)`


Seadistab kaamera resolutsiooniks 640x480 pikslit. 

<br/><br/>


2. Pildi jäädvustamine: 

`image = np.empty((480, 640, 3), dtype=np.uint8)`

`camera.capture(image, "bgr")`


Kaader salvestatakse NumPy massiivina BGR-vormingus (OpenCV eelistatud värvijärjestus). 



3. Pildi teisendamine HSV-värviruumi: 

`hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)`

`HSV (Hue, Saturation, Value) värviruum sobib paremini värvituvastuseks.`



4. Värvimaskide loomine: 

a) Punane: 

`lower_red = np.array([0, 120, 70])`

`upper_red = np.array([10, 255, 255])`

`red_mask = cv2.inRange(hsv_image, lower_red, upper_red)`


b) Roheline: 

`lower_green = np.array([35, 100, 50])`

`upper_green = np.array([85, 255, 255])`

`green_mask = cv2.inRange(hsv_image, lower_green, upper_green)`
 


5. Maskide rakendamine originaalpildile: 

`red_result = cv2.bitwise_and(image, image, mask=red_mask)`

`green_result = cv2.bitwise_and(image, image, mask=green_mask)`



6. Tulemuste kuvamine: 

`cv2.imshow("Red Areas", red_result)`

`cv2.imshow("Green Areas", green_result)`

`cv2.waitKey(0)`

`cv2.destroyAllWindows()`


## Oodatud Tulemus:
Avanevad kaks akent: 
- "Red Areas" näitab punaseid piirkondi 
- "Green Areas" näitab rohelisi piirkondi 

## Märkused:

Värviväärtused võivad sõltuda valgustingimustest — neid võib vajadusel kohandada. 
Kui soovid ka teisi värve tuvastada, saad lisada uusi värvivahemikke HSV-vormingus. 
See kood töötab Raspberry Pi keskkonnas, kuid vajadusel saab kohandada ka USB-kaamerale. 
