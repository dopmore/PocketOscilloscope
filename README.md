# Pocket Oscilloscope!
<img width="420" height="595" alt="Untitled" src="https://github.com/user-attachments/assets/4f73a7a2-328a-4860-8048-791fc74f7176" />


A custom tiny oscilloscope using a small oled display connected to an esp32. 
The objective isn't to make the best oscilloscope ever but to make it functional!
The case includes two buttons to use the RESET and BOOTSEL button of the esp32.
I wanted to make one because i currently don't own a real one :)!

## Wiring and assembly

The Assembly of the PocketOscilloscope consists of first soldering the components (Oled Screen and Probes):

Oled Display - ESP32:
- GND - GND (obv)
- VCC - 3V3
- SDA - GPIO21
- SCL - GPIO22

Testing Cables (Probes):
- GPIO 35
- GND
  
<img width="750" height="1024" alt="WhatsApp Image 2026-05-06 at 16 27 06" src="https://github.com/user-attachments/assets/10268cd0-23a9-4d23-be25-381c8b470c52" />

When soldering the screen you should see that the cables from D22 to SCL and D21 to SDA should cross aswell as the ones from GND to GND and VCC to 3V3.
Note that some cheap oled screens might not have high quality pads for soldering, then you might need to either solder to the header pins and cut them to the right length, so they fit into the case or you can scratch of the silicon on top of the electrical lines and solder to them directly. But this is quite hard and might lead to broken screens :/. So I highly recommend to just avoid the really cheap aliexpress knockoffs :)

For the Case Assymbly start by pushing the oled display into the pins on the backside of the top cover

<img width="903" height="487" alt="image" src="https://github.com/user-attachments/assets/8ec808dd-8ac8-4935-84fc-35db8316e9a7" />

Next push the buttons throught the holes on the frontside of the topcover and secure them with the rings on the backside

<img width="623" height="404" alt="image" src="https://github.com/user-attachments/assets/217cfd3d-26f5-4c47-a839-d4d2397fcb43" />

Finally push the testing cables through the holes on the backside of the back cover and put on the top cover.

<img width="1537" height="2048" alt="WhatsApp Image 2026-05-06 at 16 35 43" src="https://github.com/user-attachments/assets/9689f7e3-0abc-4fe2-beac-6df1c1fc10f8" />

## Flashing

For flahsing the esp32 and changing the code i recommend platfromio (https://platformio.org/install/ide?install=vscode)

After installing it on VSCode (as an extension), you can simply import the project by using the code folder

<img width="378" height="288" alt="image" src="https://github.com/user-attachments/assets/3cb305d7-e4bc-4f88-a1d3-041a7715c333" />

<img width="841" height="848" alt="image" src="https://github.com/user-attachments/assets/03a22ed0-fe3c-4bfb-a84a-3702acf0775f" />

Don't forget to connect your esp32 via USB-C!

Next open the main.cpp file under the src/ directory and you should see an option to upload the code to the esp32.
<img width="368" height="236" alt="image" src="https://github.com/user-attachments/assets/83882e43-9273-49c5-8e5a-6aeef2f0c8b5" />

If you get no errors then you're done and can use the PocketOscilloscope by powering it through a usb-c cable and connecting the probes to the signal you want to analyze.

## Code Explanation
<img width="1007" height="651" alt="image" src="https://github.com/user-attachments/assets/aacac403-3bca-4322-9bc5-a2ea22aa33a5" />

To display a graph on the screen we're using the Adafruit_SSD1306 lib.
The Oscilloscope will continuously store the signal data in adc_data and then Plot it on a XY-Graph.
For this we first define our X-Values that are evenly spread between 0 and the Screen Width. In total we will always have 50 Samples but since we're using analogRead (Vals between 0 and 4095) we first have to norm the measured data to display it evenly between 0 and the screen height for this we're using normY.

The main loop consist of reading the signal, norming the data and then refreshing the display.

<img width="283" height="169" alt="image" src="https://github.com/user-attachments/assets/b794a59c-1a1e-4bd0-bf71-c9db235fab19" />

<img width="516" height="304" alt="image" src="https://github.com/user-attachments/assets/f732beee-bbeb-4b6a-8361-9277a1f3a48b" />

The measured data is stored by using a scrolling window. This means that we're only updating one entry in adc_data and then moving to the next in line. When reaching the end of the list we wrap around to the start.

<img width="713" height="817" alt="image" src="https://github.com/user-attachments/assets/d8ca0f99-5451-4853-a723-05c931dda4f2" />

The data is normed by deviding through the maximum value of 4096 and then multiplying the result by the Screenheight. This means that a maximum measurement of 4096 will return 62. 

Then the Graph can be drawn by first drawing the two axes and then plotting the normed data by drawing lines between each data point.

## Showcase
https://youtube.com/shorts/uV1PsHpPy40?feature=share

<img width="779" height="690" alt="image" src="https://github.com/user-attachments/assets/56bd50b8-a392-4c7a-abfc-0395b88ac47f" />

## CAD
<img width="779" height="690" alt="image" src="https://github.com/user-attachments/assets/5920f65d-fa33-452f-8373-53e764070ca1" />


## BOM
| Component | Price | Link |
| ---- | ---- | ---- |
| ESP32 | ~5USD | [aliexpress] https://www.aliexpress.com/item/3256808703453847.html|
| OLED display 0.96 inch | ~4USD | [aliexpress] https://www.aliexpress.com/item/3256810342142918.html|

(Aliexpress prices change frequently)

# Showcase

https://youtube.com/shorts/uV1PsHpPy40?feature=share

