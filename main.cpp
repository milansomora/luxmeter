#include <LCD5110_Graph.h>
#include <Wire.h>
#include <BH1750.h>

LCD5110 lcd(8,9,10,12,11);
extern unsigned char BigNumbers[];
extern unsigned char SmallFont[];

BH1750 lightSensor;
String light;
void setup() {

 lightSensor.begin();
 lcd.InitLCD();
 lcd.clrScr();
 lcd.update();
 delay(3000);
}

void loop() {

 uint16_t lux = lightSensor.readLightLevel();

 light = String(lux);

 lcd.clrScr();

 lcd.setFont(SmallFont);
 lcd.print("Luxmeter",CENTER,0);
 lcd.print("lx",RIGHT,40);
              
 lcd.setFont(BigNumbers);
 lcd.print(light,RIGHT,12);
 
 lcd.update();

 delay(150);
}
