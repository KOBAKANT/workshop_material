
#include <FastLED.h>

#define LED_PIN     6
#define COLOR_ORDER GRB
#define CHIPSET     WS2812
#define NUM_LEDS    4

#define BRIGHTNESS  128
#define FRAMES_PER_SECOND 60
CRGB leds[NUM_LEDS];

int sensorValue;
int brightness;


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
  // read the input on analog pin 10:
  sensorValue = analogRead(A10);

  // map the minimum (i.e 200) and maximum (i.e 700) of sensorValue to brightness (0-255).
  brightness = map (sensorValue, 200, 700, 0, 255);

  // make sure that the brightness does not go out of the range (0-255)
  brightness = constrain (brightness, 0, 255);

    // control the leds, (Hue, Saturation, Value/brightness)
  leds[0] = CHSV( 255, 255, brightness);

  // send the color information to LEDs
  FastLED.show();

  
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
