const int sensorPin = A0; //reads in the analog input for a photoresistor sensor
const int photoLEDs = 13; //LEDs to output the status of the light in a room. (Green acceptable)(Red unacceptable)
uint8_t inputBuffer[30]; //input buffer to accept user input and only releases inputs after carraige return is accepted <cr>
int charsInBuffer = 0; //used to keep track of how many characters are stored in the buffer
unsigned long prevTime; // storing previous timer value to compare for context switching

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photoLEDs, OUTPUT);
  
  prevTime = millis();
}

void loop() {

  if(millis() - prevTime <= 20)
  {
    if(analogRead(sensorPin) >= 700)
    {
      digitalWrite(photoLEDs, HIGH);
    }
    else
    {
      digitalWrite(photoLEDs, LOW);
    }
  }
  else if(millis() - prevTime <= 40)
  {
    Serial.println(analogRead(sensorPin)); // print out the analog reading every 2 seconds
    delay(5);
  }
  else if(millis() - prevTime <= 45)
  {
    Serial.print("your new time difference is: ");
    Serial.println(millis() - prevTime);
    Serial.write(27); //ESC command
    Serial.print("[2J"); //clear the screen command
    Serial.write(27); //ESC command
    Serial.print("[H"); //Set cursor at home
  }
  else
  {
    prevTime = millis(); // set previous time to store the current time of the system
  }
}

//-----------------------------------------------------------
//Main functions
//-----------------------------------------------------------
void GUI(unsigned long timeDifference, uint8_t photoLEDstatus, uint8_t sensorValue)
{
  Serial.print("Hello how are you doing today? Sike I don't care!");
}

