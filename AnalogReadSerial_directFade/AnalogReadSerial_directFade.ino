/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int LEDpin = 6;
boolean trigger = false;
boolean last_trigger = false;

boolean fade;
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

  // map the minimum (i.e 200) and maximum (i.e 700) of sensorValue to brightness (0-255).
  brightness = map (sensorValue, 200, 700, 0, 255);

  // make sure that the brightness does not go out of the range (0-255)
  brightness = constrain (brightness, 0, 255);

  // control the brightness of the LED with PWM
  analogWrite(LEDpin, brightness);

  // print out the value you read and mapped brightness value:
  Serial.print("sensorValue");
  Serial.print(sensorValue);
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
