/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

int LEDpin = 6; // pin to connect LED
int LightIntensity = 0;
int pitch=100;
int speakerPin=9; // pin to connect speaker

// adjust your sensor reading range
int sensorMin = 350;
int sensorMax = 750;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // LEDpin is output
  pinMode(LEDpin, OUTPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);

  //   print out the value you read:
  Serial.print(0);  // To freeze the lower limit
  Serial.print("\t");
  Serial.print(1023);  // To freeze the upper limit
  Serial.print("\t");
  Serial.print(sensorValue);
  Serial.println();


  // make sure the sensorValue stays within the min and max range
  sensorValue = constrain(sensorValue, sensorMin, sensorMax);

  // map the sensorValue to light intensity (0-255) to control the LEDpin
  LightIntensity = map(sensorValue, sensorMin, sensorMax, 0, 255);
  // control the LEDpin with the LightIntensity
  analogWrite(LEDpin, LightIntensity);

  //generate sound according to the sensorValue. the pitch changes
  pitch = map(sensorValue, sensorMin, sensorMax, 200, 1500);
  if (pitch>210){
  // play out the sound from the speakerPin
  tone(speakerPin,pitch);
  }
  else noTone(speakerPin);

  delay(10);        // delay in between reads for stability
}
