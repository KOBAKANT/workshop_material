#include <FastLED.h>

#define LED_PIN     6
#define COLOR_ORDER GRB
#define CHIPSET     WS2812
#define NUM_LEDS    4

#define BRIGHTNESS  128
#define FRAMES_PER_SECOND 60
CRGB leds[NUM_LEDS];


int brightness = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  FastLED.show();
  delay(200);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A10);

  // if sensorValue is 0 turn on the light
if ( sensorValue >500  ){
  // turn on the light
  brightness = brightness + 5;
}

  // if not, turn off the light
else{
  // turn off the light
  brightness = brightness - 5;
}

  brightness= constrain(brightness, 0,255);

  // control the leds, (Hue, Saturation, Value/brightness)
  leds[0] = CHSV( 255, 255, brightness);

  FastLED.show();



  // print out the value you read and mapped brightness value:
  Serial.print("sensorValue: ");
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

  delay(5);        // delay in between reads for stability

}
