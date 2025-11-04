#include <Arduino.h>
#include <esp_system.h>

namespace
{
  constexpr uint32_t kSerialBaud = 115200;

  String buildDeviceId()
  {
    uint8_t mac[6] = {0};
    esp_read_mac(mac, ESP_MAC_WIFI_STA);

    char suffix[7]; // six hex digits + null terminator
    snprintf(suffix, sizeof(suffix), "%02X%02X%02X", mac[3], mac[4], mac[5]);

    return String("OLEO_") + suffix;
  }
} // namespace

void setup()
{
  Serial.begin(kSerialBaud);
  delay(500); // give USB CDC time to enumerate

  const String deviceId = buildDeviceId();
  Serial.println();
  Serial.print("Device ID: ");
  Serial.println(deviceId);
}

void loop()
{
  // Nothing else to do; keep the MCU alive.
  delay(1000);
}
