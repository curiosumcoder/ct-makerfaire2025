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
  Serial.begin(115200);
  Serial.println("READY!");
  
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

  auto cantidad {random(1,100)};
  Serial.println("Cantidad: " + String(cantidad));

  uint8_t red{};
  uint8_t green{};
  uint8_t blue{};

  for (auto i{0}; i < cantidad; i++)
  {
      red = random(0,255);
      green = random(0,255);
      blue = random(0,255);

      colores.push_back(COLOR{red,green,blue});
  }

  for (const auto& color : colores)
  {
    Serial.println("R: " + String(color.RED) + ", G: " + String(color.GREEN) + ", B: "+ String(color.BLUE));

    neopixel.setPixelColor(0, color.RED, color.GREEN, color.BLUE);
    neopixel.show();

    delay(100);

    // Turn off pixel
    neopixel.clear(); 
    neopixel.show();
  }

}

void loop() {
}