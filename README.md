# C++ Moderno con Arduino IDE
Se llama C++ Moderno al estándar de C++ 11 o superior. Es posible con la plataforma Arduino hacer uso de C++ Moderno. Vamos a conocer
que es C++ Moderno, y como es posible aplicarlo en programas de Arduino C, hoy, buscando construir código: eficiente, seguro e interoperable.

#### Taller impartido en el Maker Faire 2025 (https://makerfaire.ucenfotec.ac.cr/) en la Universidad Cenfotec (https://ucenfotec.ac.cr/).
---
## Taller
![QR](qrcode_github.com.png)

### https://github.com/curiosumcoder/ct-makerfaire2025
- Validación del ambiente de desarrollo Arduino IDE.
  - Suporte de placa IdeaBoard basada en ESP32 (https://www.crcibernetica.com/crcibernetica-ideaboard/) en el Arduino IDE.
  - Configuración del Arduino IDE.
    - Seleccionar ESP32-WROOM-DA Module, y el puerto serial correspondiente.
    - Flash sise: 8MB (64 Mb).
    - Partition Scheme: 8MB with spiffs.
  - Biblioteca
    - Adafruit NeoPixel.
- Ejemplo #1
  ```c++
  #define size 5
  
  void setup() {
    Serial.begin(115200);
    Serial.println("READY!");
  
    int arr1[size];
  
    for (int i = 0; i < size; i++)
    {
      Serial.println(arr1[i], BIN);
    }
  }
  
  void loop() {
  
  }
  ```
- Ejemplo #2
  ```c++
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
  }
  
  void loop() {
  }
  ```
