// LED Pins
int redPin    = 10;
int yellowPin = 9;
int greenPin  = 8;

// States: 1 = Red, 2 = Red+Yellow, 3 = Green, 4 = Yellow
int state = 1;

// Timer
unsigned long timer = 0;
unsigned long t20   = 20000; // 20 seconds (use 5000 for fast testing)
unsigned long t3    = 3000;  // 3 seconds

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Start with Red ON
  digitalWrite(redPin, HIGH);
  timer = millis();
}

void loop() {
  switch (state) {
    
    case 1: // RED
      if (millis() - timer >= t20) {
        digitalWrite(redPin, HIGH);
        digitalWrite(yellowPin, HIGH);
        digitalWrite(greenPin, LOW);
        state = 2;
        timer = millis();//millis() acts like checking a stopwatch while keeping the Arduino awake.
      }
      break;

    case 2: // RED + YELLOW
      if (millis() - timer >= t3) {
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, HIGH);
        state = 3;
        timer = millis();
      }
      break;

    case 3: // GREEN
      if (millis() - timer >= t20) {
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, HIGH);
        digitalWrite(greenPin, LOW);
        state = 4;
        timer = millis();
      }
      break;

    case 4: // YELLOW
      if (millis() - timer >= t3) {
        digitalWrite(redPin, HIGH);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
        state = 1;
        timer = millis();
      }
      break;
  }
}
//Immediately after uploading, the Red LED turns on, then Red + Yellow, 
//then Green, then Yellow, and repeats.
// If an LED doesn't light up, flip that LED around (its long and short legs were reversed).