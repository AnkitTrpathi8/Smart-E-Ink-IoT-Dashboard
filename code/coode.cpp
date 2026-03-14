#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_BME280.h>
#include <BH1750.h>
#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

// Weather API
String apiKey = "YOUR_API_KEY";
String city = "Lucknow";
String countryCode = "IN";

// E-Ink display pins
#define EPD_CS 5
#define EPD_DC 17
#define EPD_RST 16
#define EPD_BUSY 4

// Sensors
Adafruit_BME280 bme;
BH1750 lightMeter;

// Display object
GxEPD2_BW<GxEPD2_420, GxEPD2_420::HEIGHT> display(GxEPD2_420(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

// Weather variables
float weatherTemp;
int weatherHumidity;

// Sensor variables
float roomTemp;
float roomHumidity;
float lightLevel;

// PIR sensor
#define PIR_PIN 27

// Buttons
#define BTN_PAGE 32
#define BTN_REFRESH 33

// WiFi connect
void connectWiFi()
{
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
}

// Fetch weather
void getWeather()
{
  if(WiFi.status()==WL_CONNECTED)
  {
    HTTPClient http;

    String url = "http://api.openweathermap.org/data/2.5/weather?q=" 
                 + city + "," + countryCode + 
                 "&appid=" + apiKey + "&units=metric";

    http.begin(url);

    int httpCode = http.GET();

    if(httpCode>0)
    {
      String payload = http.getString();

      DynamicJsonDocument doc(2048);
      deserializeJson(doc, payload);

      weatherTemp = doc["main"]["temp"];
      weatherHumidity = doc["main"]["humidity"];
    }

    http.end();
  }
}

// Read sensors
void readSensors()
{
  roomTemp = bme.readTemperature();
  roomHumidity = bme.readHumidity();
  lightLevel = lightMeter.readLightLevel();
}

// Draw dashboard
void drawDashboard()
{
  display.setRotation(1);
  display.setFullWindow();
  display.firstPage();

  do
  {
    display.fillScreen(GxEPD_WHITE);

    display.setTextColor(GxEPD_BLACK);

    display.setCursor(10,20);
    display.print("SMART DASHBOARD");

    display.setCursor(10,60);
    display.print("Weather:");

    display.setCursor(10,80);
    display.print(weatherTemp);
    display.print(" C");

    display.setCursor(10,100);
    display.print("Humidity:");
    display.print(weatherHumidity);

    display.setCursor(10,140);
    display.print("Room Temp:");
    display.print(roomTemp);

    display.setCursor(10,160);
    display.print("Room Hum:");
    display.print(roomHumidity);

    display.setCursor(10,200);
    display.print("Light:");
    display.print(lightLevel);

  } while(display.nextPage());
}

// Deep sleep
void goToSleep()
{
  esp_sleep_enable_timer_wakeup(30 * 60 * 1000000);
  esp_deep_sleep_start();
}

void setup()
{
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(BTN_PAGE, INPUT_PULLUP);
  pinMode(BTN_REFRESH, INPUT_PULLUP);

  Wire.begin(21,22);

  bme.begin(0x76);
  lightMeter.begin();

  display.init();

  connectWiFi();

  getWeather();

  readSensors();

  drawDashboard();

  delay(5000);

  goToSleep();
}

void loop()
{
}