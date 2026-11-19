// 1. Pins
int carRed = 10, carYellow = 9, carGreen = 8;
int pedRed = 6,  pedGreen = 5;
int button = 2;

// 2. State & Button Memory (0 = not pressed, 1 = pressed)
int state = 1;
int buttonPressed = 0;

// 3. Timers (in milliseconds)
unsigned long timer = 0;
unsigned long t10 = 10000; // 10 seconds
unsigned long t5  = 5000;  // 5 seconds
unsigned long t3  = 3000;  // 3 seconds

// Helper function to turn all 5 LEDs ON (1) or OFF (0) in one line
void setLights(int cR, int cY, int cG, int pR, int pG) {
  digitalWrite(carRed, cR);
  digitalWrite(carYellow, cY);
  digitalWrite(carGreen, cG);
  digitalWrite(pedRed, pR);
  digitalWrite(pedGreen, pG);
}

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT_PULLUP); // Button connected to GND

  // Start in State 1: Car Red + Pedestrian Red
  setLights(1, 0, 0, 1, 0);
  timer = millis();
}

void loop() {
  // Remember if the button is pressed at any time
  if (digitalRead(button) == LOW) {
    buttonPressed = 1;
  }

  switch (state) {
    case 1: // Both RED (3s safety pause)
      if (millis() - timer >= t3) {
        setLights(1, 1, 0, 1, 0); // Car Red+Yellow, Ped Red
        state = 2;
        timer = millis();
      }
      break;

    case 2: // Car RED + YELLOW (3s)
      if (millis() - timer >= t3) {
        setLights(0, 0, 1, 1, 0); // Car Green, Ped Red
        state = 3;
        timer = millis();
      }
      break;

    case 3: // Car GREEN (waits for button + at least 10s)
      if (buttonPressed == 1 && millis() - timer >= t10) {
        setLights(0, 1, 0, 1, 0); // Car Yellow, Ped Red
        buttonPressed = 0;        // Clear button memory
        state = 4;
        timer = millis();
      }
      break;

    case 4: // Car YELLOW (5s)
      if (millis() - timer >= t5) {
        setLights(1, 0, 0, 0, 1); // Car Red, Ped Green
        state = 5;
        timer = millis();
      }
      break;

    case 5: // Pedestrian GREEN (10s crossing time)
      if (millis() - timer >= t10) {
        setLights(1, 0, 0, 1, 0); // Back to Both Red
        state = 1;
        timer = millis();
      }
      break;
  }
}