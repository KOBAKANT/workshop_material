/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int LEDpin = 6;


boolean fadeIn;
int brightness;
int inc = 5;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(LEDpin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);



  if (sensorValue > 500 ) {
    // if sensorValue is above certain amount, trigger is true
    fadeIn = true;
  }
  else {
    // else trigger is false
    fadeIn = false;
  }


  if (fadeIn) {
    // if fade in, then increment is +5
    inc = 5;
  } else {
    // if fade out, then increment is -5
    inc = -5;
  }

  // add increment to the brightness
  brightness = brightness + inc;

  // make sure that the brightness does not go out of the range (0-255)
  brightness = constrain (brightness, 0, 255);

  // control the brightness of the LED with PWM
  analogWrite(LEDpin, brightness);


  // print out the value you read and mapped brightness value:
  Serial.print("sensorValue");
  Serial.print(sensorValue);
  Serial.print("\t fade state: ");
  Serial.print(fadeIn);
  Serial.print("\t brightness: ");
  Serial.print(brightness);

  //limitter for serial plotter
  Serial.print("\t ");
  Serial.print(0);
  Serial.print(" ");
  Serial.print(1023);

  // Carriage return
  Serial.println();

  delay(10);        // delay in between reads for stability

}
