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

int state;

boolean fadeIn;
int brightness;
int inc = 5;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(LEDpin, OUTPUT);
  // set the pin with the sensor as input
  pinMode(3, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on digital pin 3. 
  int sensorValue = digitalRead(3);



  if (sensorValue == 1 ) {
    // if sensorValue is above certain amount, trigger is true
    trigger = true;
  }
  else {
    // else trigger is false
    trigger = false;
  }

// if triggered the first time
  if (trigger == true && last_trigger == false) {
    state = state +1;
    state = state %2;
  }

  if (state == 1) {
    // if state is 1, turn on the LED
    digitalWrite(LEDpin, HIGH);
  } 
  if (state == 0) {
    // if state is 1, turn off the LED
    digitalWrite(LEDpin, LOW);
  }

 

  // print out the value you read and mapped brightness value:
  Serial.print("sensorValue");
  Serial.print(sensorValue);


  //limitter for serial plotter
  Serial.print("\t ");
  Serial.print(0);
  Serial.print(" ");
  Serial.print(1);

  // Carriage return
  Serial.println();

  delay(10);        // delay in between reads for stability

}
