/*
  Arduino burglar alarm
  
  Arduino based burglar alarm with a pin for siren, pin for arm/unarm and 4 pins for sensors.
  
  created   Oct 2017
  by CheapskateProjects

  ---------------------------
  The MIT License (MIT)

  Copyright (c) 2017 CheapskateProjects

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

const int enablePin = 8;
const int sirenPin = 9;
const int sensorPin1 = 10;
const int sensorPin2 = 11;
const int sensorPin3 = 12;
const int sensorPin4 = 13;

void setup()
{
  // Turn siren off when booting
  pinMode(sirenPin, OUTPUT);
  digitalWrite(sirenPin, LOW);

  // Other pins should be input pins
  pinMode(sensorPin1, INPUT_PULLUP); // Pullup for switch type sensors (no need for external resistors)
  pinMode(sensorPin2, INPUT_PULLUP);
  pinMode(sensorPin3, INPUT);
  pinMode(sensorPin4, INPUT);

  Serial.begin ( 115200 );
}

int enabled = 0;
void loop()
{
  enabled = digitalRead(enablePin);
  if(enabled == HIGH)
  {
    if(digitalRead(sensorPin1) == HIGH || digitalRead(sensorPin2) == HIGH)
    {
      Serial.println("Alarm 1");
      digitalWrite(sirenPin, HIGH);
    }
    if(digitalRead(sensorPin3) == HIGH || digitalRead(sensorPin4) == HIGH)
    {
      Serial.println("Alarm 2");
      digitalWrite(sirenPin, HIGH);
    }
  }
  else
  {
    digitalWrite(sirenPin, LOW);
  }
}
