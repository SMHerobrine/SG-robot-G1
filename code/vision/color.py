import time
import picamera
import cv2
import numpy as np
 
camera = picamera.PiCamera()
camera.resolution = (640, 480)
image = np.empty((480, 640, 3), dtype=np.uint8)
camera.capture(image, "bgr")
 
hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
 
# Punase värvi vahemik
lower_red = np.array([0, 120, 70])
upper_red = np.array([10, 255, 255])
red_mask = cv2.inRange(hsv_image, lower_red, upper_red)
 
# Rohelise värvi vahemik
lower_green = np.array([35, 100, 50])
upper_green = np.array([85, 255, 255])
green_mask = cv2.inRange(hsv_image, lower_green, upper_green)
 
# Rakenda maskid
red_result = cv2.bitwise_and(image, image, mask=red_mask)
green_result = cv2.bitwise_and(image, image, mask=green_mask)
 
# Kuvamine
cv2.imshow("Red Areas", red_result)
cv2.imshow("Green Areas", green_result)
cv2.waitKey(0)
cv2.destroyAllWindows()
