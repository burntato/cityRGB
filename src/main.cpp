#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN D7          // Pin which is connected to the DHT sensor.
#define DHTTYPE DHT11      // DHT 11

DHT dht(DHTPIN, DHTTYPE);

const int redPin = D6;    // Pin which is connected to the red LED.
const int greenPin = D5;  // Pin which is connected to the green LED.
const int bluePin = D4;   // Pin which is connected to the blue LED.

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  delay(2000);
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println("Failed to read temperature from DHT sensor!");
    return;
  }
  Serial.print("Temperature: ");
  Serial.println(temperature);
  
  // Set the color of the RGB LED based on the temperature.
  if (temperature < 20.0) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  } else if (temperature < 30.0) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}
