//#define size 5ABC

// Int Types
// Inicializadores
constexpr uint8_t size{5};

void setup() {
  Serial.begin(115200);
  Serial.println("READY!");

  int arr1[size]{};
  int n {arr1[5]};

  // Contenedores
  // Plantillas (templates)
  //std::array<uint8_t, 10> arr2{1,2,3};
  std::vector<int> arr2{1,2,3};

  arr2.push_back(random(255));
  arr2.push_back(random(255));
  arr2.push_back(random(255));

  Serial.println(arr2.size());

  // Algoritmos
  std::sort(arr2.begin(),arr2.end());

  // Inferencia de tipos
  //auto n2 {arr2.at(4)};

  // Range based loops
  // Iteradores
  for (const auto& m : arr2)
  {
    Serial.println(m);
    //m = 7;
  }

  for (auto& m : arr2)
  {
    Serial.println(m);
  }


  // for (int i = 0; i < size; i++)
  // {
  //   Serial.println(arr1[i], BIN);
  // }
}

void loop() {

}
