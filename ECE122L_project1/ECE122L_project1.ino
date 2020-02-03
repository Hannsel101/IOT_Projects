const int sensorPin = A0; //reads in the analog input for a photoresistor sensor
const int photoLEDs = 13; //LEDs to output the status of the light in a room. (Green acceptable)(Red unacceptable)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photoLEDs, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(sensorPin));
  delay(2000);

  photoStatusLED(analogRead(sensorPin));
}
