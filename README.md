**Pocket Oscilloscope!**

A custom tiny oscilloscope using a small oled display connected to an esp32. The objective isn't to make the best oscilloscope ever but to make it functional!
The case includes two buttons to use the RESET and BOOTSEL button of the esp32.
To analyse any wave you only need to connect the testing cable GND to GND and GPIO 35 (red cable) to the source input. The normalized data will then be display on the display. ([Showcase with PWM](https://youtube.com/shorts/uV1PsHpPy40?feature=share))


<img width="420" height="595" alt="Untitled" src="https://github.com/user-attachments/assets/4f73a7a2-328a-4860-8048-791fc74f7176" />

![WhatsApp Image 2026-04-01 at 18 45 37](https://github.com/user-attachments/assets/bf537768-9224-401d-91b0-2fb2e36562bb)


# CAD
<img width="779" height="690" alt="image" src="https://github.com/user-attachments/assets/5920f65d-fa33-452f-8373-53e764070ca1" />

# Wiring

- Oled Display - ESP32:
- GND - GND (obv)
- VCC - 3V3
- SDA - GPIO21
- SCL - GPIO22

Testing Cables (Probes):
- GPIO 35
- GND

# BOM
| Component | Price | Link |
| ---- | ---- | ---- |
| ESP32 | ~5USD | [aliexpress] https://www.aliexpress.com/item/3256808703453847.html|
| OLED display 0.96 inch | ~4USD | [aliexpress] https://www.aliexpress.com/item/3256810342142918.html|

(Aliexpress prices change frequently)

# Showcase

https://youtube.com/shorts/uV1PsHpPy40?feature=share

