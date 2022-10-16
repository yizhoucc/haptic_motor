// close loop simpel vibration given freq in 1/hz

// vibration is good when only changing 1 phase and let the other two phase stay at a pulling eq voltage.
// this depends on the motor but currently i only have one. rated 5-14.8v and kv==800. 
// need to check with more motors to get a calibration profile.
// or, can be used with hall and magnet sensors, but depends on the sampling rate, might not be good for high freq vibs.

#include <math.h>

int Output1 = 11;
int Output2 = 10;
int Output3 = 9;
int potVal = 1;

float A = 0;
float B = 0.104; // increment angle per update
int betweenviddelay = 999;
int Freq_IN = A0;
int var1 = 0;
int var2 = 0;
int var3 = 0;
int var4 = 0;
int var5 = 0;
int var6 = 0;
float Phase1 = 2 * PI / 3;
float Phase2 = 4 * PI / 3;
float Phase3 = 2 * PI;


void setup()
{
    Serial.begin(9600);
    pinMode(Output1, OUTPUT);
    pinMode(Output2, OUTPUT);
    pinMode(Output3, OUTPUT);
    pinMode(Freq_IN, INPUT);
}
void loop()
{
    A += B;


    var4 = 126 * sin(A + Phase1);
    var1 = var4 + 128;
    var5 = 126 * sin(A + Phase2);
    var2 = var5 + 128;
    var6 = 126 * sin(A + Phase3);
    var3 = var6 + 128;
    if (A >= 2 * PI)
    {
        A = 0;
    }
    analogWrite(Output1, var1);
    analogWrite(Output2, var2);
    analogWrite(Output3, var3);

    Serial.print(var1);
    Serial.print(" ");
    Serial.print(var2);
    Serial.print(" ");
    Serial.println(var3);

    potVal = analogRead(Freq_IN);
    delay(potVal);
    analogWrite(Output3, var6);

    Serial.print(var1);
    Serial.print(" ");
    Serial.print(var2);
    Serial.print(" ");
    Serial.println(var3);

    // long delay between vibs
    analogWrite(Output1, 0);
    analogWrite(Output2, 0);
    analogWrite(Output3, 0);
    delay(betweenviddelay);
}

