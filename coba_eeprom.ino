#include <EEPROM.h>

#define ADDR_EEPROM1 0
#define ADDR_EEPROM2 5
#define ADDR_EEPROM3 10


float nilai1,nilai2,nilai3,nilai4;

void setup()
{
    Serial.begin(9600);
    EEPROM.begin(64);

    pinMode(0,INPUT_PULLUP);

    nilai1=EEPROM.readFloat(ADDR_EEPROM1);
    nilai2=EEPROM.readFloat(ADDR_EEPROM2);
    nilai3=EEPROM.readFloat(ADDR_EEPROM3);

    Serial.print("Nilai 1 : ");
    Serial.println(nilai1);
    Serial.print("Nilai 2 : ");
    Serial.println(nilai2);
    Serial.print("Nilai 3 : ");
    Serial.println(nilai3);
}

void loop()
{
    while (digitalRead(0)==LOW)
    {
        while(digitalRead(0)==LOW){;}
        nilai4 = nilai4+32.2;
        EEPROM.writeFloat(ADDR_EEPROM1,nilai4);
        EEPROM.writeFloat(ADDR_EEPROM2,nilai4);
        EEPROM.writeFloat(ADDR_EEPROM3,nilai4);
        EEPROM.commit();
        Serial.print("Nilai Disimpan : ");
        Serial.println(nilai4);
    }
}