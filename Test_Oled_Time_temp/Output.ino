void Output() {
 delay(5000);
  // clear display
  display.clearDisplay();

  // Headline
  display.setTextSize(1);
  display.setCursor(32,0); // ปรับการแสดงผลบนหน้าจอ WIDTH,HEIGHT
  display.print("Air control");
  display.setTextSize(1);
  display.setCursor(32,7); // ปรับการแสดงผลบนหน้าจอ WIDTH,HEIGHT
  display.print("server room");
  
  // Senser Time
  //read Time
  RtcDateTime now = Rtc.GetDateTime();
  // Print TimeNow
  printDateTime(now);

  // display Time
    display.setTextSize(1);
  display.setCursor(0,20); // ปรับการแสดงผลบนหน้าจอ WIDTH,HEIGHT
  display.print("Time : ");
  display.setTextSize(1); // ปรับขนาดตัวอักษร 
  //display.print( printDateTime() ); // แสดงผลค่าจาก Senser
  
  //read Temperature and humidity
  float t = dht.readTemperature();
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  }
  
  // display Temperature
  display.setTextSize(1); // ปรับขนาดตัวอักษร
  display.setCursor(0, 35); // ปรับการแสดงผลบนหน้าจอ WIDTH,HEIGHT
  display.print("Temperature : ");
  display.setTextSize(1); // ปรับขนาดตัวอักษร
  display.print(t); // แสดงผลค่าองศาจาก Senser
  display.print(" ");
  display.print("C"); 

  
  // Print Temperature
  Serial.print(" Temperature : ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.println();

  // Refresh Oled
  display.display(); 
}

//Senser Time
#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt)
{
char datestring[20];
snprintf_P(datestring, 
  countof(datestring),
  PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Day(),            
            dt.Month(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
Serial.print(datestring);
}
