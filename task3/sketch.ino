// 1. Pins for the LEDs
int redPin = 10;
int yellowPin = 9;
int greenPin = 8;

// 2. State variable (1 = Red, 2 = Red+Yellow, 3 = Green, 4 = Yellow)
int state = 1;

// 3. Timer variables
int timer = 0;
int t20 = 20000; // 20 seconds
int t3  = 3000;  // 3 seconds

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Start with Red light ON
  digitalWrite(redPin, HIGH);
  timer = millis();
}

void loop() {
  // Switch-case state machine
  switch (state) {
    
    case 1: // RED
      if (millis() - timer >= t20) {
        digitalWrite(redPin, HIGH);
        digitalWrite(yellowPin, HIGH);
        digitalWrite(greenPin, LOW);
        
        state = 2;        // Move to Red+Yellow
        timer = millis(); // Reset timer
      }
      break;

    case 2: // RED + YELLOW
      if (millis() - timer >= t3) {
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, HIGH);
        
        state = 3;        // Move to Green
        timer = millis(); // Reset timer
      }
      break;

    case 3: // GREEN
      if (millis() - timer >= t20) {
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, HIGH);
        digitalWrite(greenPin, LOW);
        
        state = 4;        // Move to Yellow
        timer = millis(); // Reset timer
      }
      break;

    case 4: // YELLOW
      if (millis() - timer >= t3) {
        digitalWrite(redPin, HIGH);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
        
        state = 1;        // Back to Red
        timer = millis(); // Reset timer
      }
      break;
  }
}