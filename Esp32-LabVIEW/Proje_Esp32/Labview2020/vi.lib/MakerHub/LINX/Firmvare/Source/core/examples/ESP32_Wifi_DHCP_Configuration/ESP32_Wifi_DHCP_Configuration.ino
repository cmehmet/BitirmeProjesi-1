#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
//#include <Servo.h>
#include <WiFi.h>

#include <LinxESP32.h>
#include <LinxESP32WifiListener.h>
 
/*Setup metodunda objesini oluşturacağım
 Linx Aygıtı için pointer oluşturdum.*/
LinxESP32* LinxDevice;


void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);      //STA(Station) ve AP(Access Point) olmak üzere 2 adet Wifi moduna sahip.Ben STA modunu kullandım.Bu mod Esp32'yi bir wifi erişim nıktasına bağlamak için kullanılıyor.
  WiFi.disconnect(true);    //Anladığım kadarıyla ağa tekrar bağlanırken sıkıntı olmaması için.
  
  
  LinxDevice = new LinxESP32();

  LinxWifiConnection.SetSsid("Redmi 7A");           //Ağ Adı
  LinxWifiConnection.SetSecurity(WPA2_PASSPHRASE);  //Güvenlik Türü (NONE, WPA2_PASSPHRASE, WPA2_KEY, WEP40, WEO104)
  LinxWifiConnection.SetPassphrase("ESP32_PROJE");  //Ağ Şifresi
  LinxWifiConnection.Start(LinxDevice, 44300);      //İstediğim IP ve Port için bağlantıyı başlattım.
}

void loop()
{ 
  //(Aslında amacım IP bilgisini öğrenmek)
  LinxWifiConnection.CheckForCommands();
  delay(1000);
}

