 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>
ThreeWire myWire(
  D4, // DAT/IO
  D5, // CLK/SCLK
  D2  // RST/CE
);
RtcDS1302<ThreeWire> Rtc(myWire);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN D3 // Temp sensor D3

// Uncomment the type of sensor in use:
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

    Setup_SenserTemp();
    Setup_SenserTime();
    Setup_Oled();
}

void loop() {
     Output();
}
