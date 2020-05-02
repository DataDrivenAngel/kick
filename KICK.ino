#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN    10
#define LED_COUNT 150

int threshold = 800;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t pink = strip.gamma32(strip.Color(235, 54, 201));

void setup() {
  pinMode(A7, INPUT);
  strip.begin();           
  strip.show();            
  strip.setBrightness(250); 
  Serial.begin(9600);
  for (int i=0; i<4; i++){
    strip.setPixelColor(i, pink); 
    strip.show(); 
    delay(5);
  }
}

void loop() {
  if (analogRead(A7)>800){
    for(int i=1; i<75; i++){
      strip.setPixelColor(i, 0,0,0);
      strip.show(); 
      delay(5 + (75%i)/4);
      strip.setPixelColor((i+4), pink);
      strip.show(); 
      delay(5+ (75%i)/4);
    }
    for(int i=79; i>4; i--){
      strip.setPixelColor(i, 0,0,0);
      strip.show(); 
      delay(5 + (75%i)/4);
      strip.setPixelColor((i-4), pink);
      strip.show(); 
      delay(5 + (75%i)/4);
    }
  }

}
