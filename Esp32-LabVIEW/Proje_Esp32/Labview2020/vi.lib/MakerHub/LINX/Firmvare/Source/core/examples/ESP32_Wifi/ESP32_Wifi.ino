#include <LinxESP32.h>


LinxESP32* LinxDevice;


void setup()
{
  
  LinxDevice = new LinxESP32();

  // PWM & Servo Setup
  uint8_t pwmList[] = {};         // Max16Ch {0, 26, ...}   PWM kanalı seçimi
  uint16_t pwmFrequency = 12000;  // LED:12000, Servo:50    PWM sinyal frekansı
  for (int i = 0; i < sizeof(pwmList); i++) {
    ledcSetup(i, pwmFrequency, 8);                          //ledcSetup(ledChannel,freq,resolution)
    pinMode(pwmList[i], OUTPUT);                            //pinlerin giriş çıkış durumu ayarlandı.
    ledcAttachPin(pwmList[i], i);                           //ledcAttachPin(Sinyali veren GPIO, Sinyali üreten kanal);
  }

  LinxWifiConnection.Start(LinxDevice, 44300);
}

void loop()
{
  //Labviewden gelen paketleri dinler.
  LinxWifiConnection.CheckForCommands();
  delay(1);
}