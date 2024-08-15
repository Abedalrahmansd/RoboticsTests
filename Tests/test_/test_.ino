#include <RH_ASK.h>
#include <SPI.h>
RH_ASK driver;
void setup()
{
    Serial.begin(9600);      // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
void loop()
{
    const char *msg = "u";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}
