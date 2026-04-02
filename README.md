**Pocket Oscilloscope!**

A custom tiny oscilloscope using a small oled display connected to an esp32. The objective isn't to make the best oscilloscope ever but to make it functional!
The case includes two buttons to use the RESET and BOOTSEL button of the esp32.
To analyse any wave you only need to connect the testing cable GND to GND and GPIO 35 (red cable) to the source input. The normalized data will then be display on the display.

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
| ESP32 | ~5USD | [aliexpress] https://de.aliexpress.com/item/1005008889768599.html?spm=a2g0o.productlist.main.4.37d432efWmt8ey&aem_p4p_detail=202604010949411141532102808680004602880&algo_pvid=c0b16687-eb1d-4447-a4b9-be2f1f8fce06&algo_exp_id=c0b16687-eb1d-4447-a4b9-be2f1f8fce06-3&pdp_ext_f={%22order%22%3A%228442%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22}&pdp_npi=6%40dis!EUR!2.48!0.99!!!19.25!7.66!%40211b6c1917750621809857413eab86!12000047095028658!sea!DE!0!ABX!1!0!n_tag%3A-29910%3Bd%3Ae0188e57%3Bm03_new_user%3A-29895%3BpisId%3A5000000197700208&curPageLogUid=ab0puvtSoNPo&utparam-url=scene%3Asearch|query_from%3A|x_object_id%3A1005008889768599|_p_origin_prod%3A&search_p4p_id=202604010949411141532102808680004602880_2 |
| OLED display 0.96 inch | ~4USD | [aliexpress] https://de.aliexpress.com/item/1005010528457670.html?spm=a2g0o.productlist.main.36.109a4953EF29OL&algo_pvid=55d9bae1-c626-4897-8aa5-5d54475c2464&algo_exp_id=55d9bae1-c626-4897-8aa5-5d54475c2464-33&pdp_ext_f={%22order%22%3A%224%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22}&pdp_npi=6%40dis!EUR!7.65!3.59!!!59.50!27.96!%40211b6a7a17750623147704885edd34!12000052707956650!sea!DE!0!ABX!1!0!n_tag%3A-29910%3Bd%3Ae0188e57%3Bm03_new_user%3A-29895&curPageLogUid=0NjDjhU3IAvh&utparam-url=scene%3Asearch|query_from%3A|x_object_id%3A1005010528457670|_p_origin_prod%3A |

(Aliexpress prices change frequently)

# Showcase

https://github.com/user-attachments/assets/90064cc6-2fdd-47bd-9d3b-f28d7ec7607c

# Zine

<img width="420" height="595" alt="Untitled" src="https://github.com/user-attachments/assets/4f73a7a2-328a-4860-8048-791fc74f7176" />

