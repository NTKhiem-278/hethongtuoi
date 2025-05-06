#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Cấu hình LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Cấu hình DHT11
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Cảm biến độ ẩm đất
#define SOIL_MOISTURE_PIN A0

// Relay
#define RELAY_PIN D6

void setup() {
  Serial.begin(115200);
  
  // Khởi động LCD
  lcd.init();
  lcd.backlight();
  
  // Khởi động DHT11
  dht.begin();

  // Khởi động relay
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Smart Garden");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Đọc dữ liệu DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Đọc giá trị độ ẩm đất
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);



  // Hiển thị lên LCD
  lcd.setCursor(0, 0);
  lcd.print("NhietKK: ");
  lcd.print(t);
  lcd.print("doC");

  lcd.setCursor(0, 1);
  lcd.print("AmKK: ");
  lcd.print(h);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("AmDat:");
  lcd.print(soilMoisture);

  // Ngưỡng độ ẩm
  if (soilMoisture > 500) {
    digitalWrite(RELAY_PIN, HIGH); // Bật máy bơm (kích bằng H)
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Tắt máy bơm
  }

  delay(2000); 
}


