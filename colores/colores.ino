#include <Adafruit_NeoPixel.h>

struct COLOR 
{
  uint8_t RED{};
  uint8_t GREEN{};
  uint8_t BLUE{};
};

constexpr int16_t PIXEL_PIN{2};
Adafruit_NeoPixel neopixel(1, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  
  // Initialize pixel to off
  neopixel.begin();
  neopixel.show(); 

  COLOR c1{255,0, 0};

  // Set LED color
  neopixel.setPixelColor(0, c1.RED, c1.GREEN, c1.BLUE);
  neopixel.show();

  delay(2000);

  // Turn off pixel
  neopixel.clear(); 
  neopixel.show();

  std::vector<COLOR> colores{};

  colores.push_back(COLOR{255,0,0});
  colores.push_back(COLOR{0,255,0});
  colores.push_back(COLOR{0,0,255});

  auto cantidad {random(1,20)};

  for (auto i{0}; i < cantidad; cantidad++)
  {
      uint8_t red { random(0,255)};
      uint8_t green { random(0,255)};
      uint8_t blue { random(0,255)};

      colores.push_back(COLOR{red,0,0});
  }

  for (const auto& color : colores)
  {
    neopixel.setPixelColor(0, color.RED, color.GREEN, color.BLUE);
    neopixel.show();

    delay(500);

    // Turn off pixel
    neopixel.clear(); 
    neopixel.show();
  }

}

void loop() {
}