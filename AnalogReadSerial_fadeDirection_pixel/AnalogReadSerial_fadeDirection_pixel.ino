#include <FastLED.h>

#define LED_PIN     6
#define COLOR_ORDER GRB
#define CHIPSET     WS2812
#define NUM_LEDS    4

#define BRIGHTNESS  128
#define FRAMES_PER_SECOND 60
CRGB leds[NUM_LEDS];


boolean trigger = false;
boolean last_trigger = false;

boolean fade;
int brightness;
int inc = 5;

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
  int sensorValue = analogRead(A0);



  if (sensorValue > 500 ) {
    // if sensorValue is above certain amount, trigger is true
    trigger = true;
  }
  else {
    // else trigger is false
    trigger = false;
  }

  if (trigger == true && last_trigger == false) {
    // change the fade direction
    fade = !fade;
  }

  if (fade) {
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

  // if you want to change color instead of brightness
  int hue = map (brightness, 0, 255, 129, 176);

  // control the leds, (Hue, Saturation, Value/brightness)
  leds[0] = CHSV( hue, 255, 255);
  leds[1] = CHSV( 128, 255, brightness);

  FastLED.show();


  // save the current status of the trigger to last_trigger for next comparison
  last_trigger = trigger;

  // print out the value you read and mapped brightness value:
  Serial.print("sensorValue: ");
  Serial.print(sensorValue);
  Serial.print("\t fade state: ");
  Serial.print(fade);
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
