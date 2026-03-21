#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels
#define adcPin 34
#define SAMPLES 50

volatile uint8_t cnt;
u_int16_t adc_data[SAMPLES] = {
    4095,
    4095,
    4095,
    4095,
    4095,
    0,
    0,
    0,
    0,
    0,
    4095,
    4095,
    4095,
    4095,
    4095,
    0,
    0,
    0,
    0,
    0,
    4095,
    4095,
    4095,
    4095,
    4095,
    0,
    0,
    0,
    0,
    0,
    4095,
    4095,
    4095,
    4095,
    4095,
    0,
    0,
    0,
    0,
    0,
    4095,
    4095,
    4095,
    4095,
    4095,
};
;
u_int16_t X[SAMPLES] = {1, 4, 6, 9, 11, 14, 16, 19, 21, 24,
                        26, 29, 31, 34, 36, 39, 41, 44, 46, 49,
                        51, 54, 56, 59, 61, 64, 66, 69, 71, 74,
                        76, 79, 81, 84, 86, 89, 91, 94, 96, 99,
                        101, 104, 106, 109, 111, 114, 116, 119, 121, 127};
u_int16_t normY[SAMPLES];

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, 23);

void normData()
{
  for (int i = 0; i < SAMPLES; i++)
  {
    normY[i] = ((adc_data[i] * 62) / 4095) + 1;
  }
}

void plotGraph()
{
  oled.drawLine(1, 1, 1, 63, WHITE);    // X axes
  oled.drawLine(1, 63, 127, 63, WHITE); // Y axes

  for (int i = 0; i < SAMPLES - 1; i++)
  {
    oled.drawLine(X[i], normY[i], X[i+1], normY[i+1], WHITE);
  }
}

void refreshDisplay() {
  normData();
  plotGraph();
  oled.display();
}

void adcRead() {
  adc_data[cnt] = analogRead(adcPin);
  cnt++;
  if (cnt>50) {cnt=0;}
}

void setup()
{
  Serial.begin(9600);

  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1)
      ;
  }

  delay(2000);         // wait two seconds for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(3);      // set text size
  oled.setTextColor(WHITE); // set text color
  oled.setCursor(0, 32);    // set position to display (x,y)
  oled.println("Matthias"); // set text
  oled.display();           // display on OLED
  delay(2000);
  oled.clearDisplay(); // wait two seconds for initializing
}

void loop()
{
  adcRead();
  refreshDisplay();
}
// yippie