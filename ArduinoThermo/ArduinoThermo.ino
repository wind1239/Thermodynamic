// THERMODYNAMIC
// An installation art piece

// Gaby Clarke, Spring 2017
// Parsons Paris, Art Media and Technology Core Spatial Studio
// https://github.com/gabyclarke/Thermodynamic

// Powered by Dark Sky, https://darksky.net/poweredby/

int LED1 = 9; // PWM pin
int LED2 = 10;
float brightness; // LED brightness
float locationBounds[] = {-25.0, 50.0}; // Record {low, high} temperatures for location

// PARAMETERS TO BE EDITED
float SanDiego[] = {-4.0, 44.0}; // Record {low, high} temperatures in San Diego


void setup() {
  Serial.begin(9600); // set the baud rate to 9600
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  getLocationBounds(SanDiego); // select location here
}

void loop() {
  String data = "";
  float value = 0.0;
  
  if (Serial.available()) {
    data = Serial.readString();
    value = data.toFloat();
    Serial.println(data);
  }

  float brightness = map(value, locationBounds[0], locationBounds[1], 0.0, 255.0);
  analogWrite(LED1, brightness);
  analogWrite(LED2, brightness);
  
//  delay(10);
}

void getLocationBounds(float location[]) {
  // set global location[] based on input location
  locationBounds[0] = location[0];
  locationBounds[1] = location[1];
}

