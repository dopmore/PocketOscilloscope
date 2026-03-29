#include <Wire.h>

#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels
#define adcPin 35
#define SAMPLES 50

volatile uint8_t cnt;
u_int16_t adc_data[SAMPLES];
u_int16_t X[SAMPLES] = {1, 4, 6, 9, 11, 14, 16, 19, 21, 24,
                        26, 29, 31, 34, 36, 39, 41, 44, 46, 49,
                        51, 54, 56, 59, 61, 64, 66, 69, 71, 74,
                        76, 79, 81, 84, 86, 89, 91, 94, 96, 99,
                        101, 104, 106, 109, 111, 114, 116, 119, 121, 127};
u_int16_t normY[SAMPLES];

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
    oled.drawLine(X[i], normY[i], X[i + 1], normY[i + 1], WHITE);
  }
}

void refreshDisplay()
{
  oled.clearDisplay();
  normData();
  plotGraph();
  oled.display();
}

void adcRead()
{
  adc_data[cnt] = analogRead(adcPin);
  cnt++;
  if (cnt > 50)
  {
    cnt = 0;
  }
}

void setup()
{
  Serial.begin(9600);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1)
      ;
  }

  delay(2000);
  oled.clearDisplay();

  oled.setTextSize(3);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 32);
  oled.println("Matthias");
  oled.display();
  delay(2000);
  oled.clearDisplay();
}

void loop()
{
  adcRead();
  refreshDisplay();
}
// yippie