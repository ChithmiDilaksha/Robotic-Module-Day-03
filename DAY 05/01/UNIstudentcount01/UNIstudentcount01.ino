const int segPins[] = {13, 12, 11, 10, 9, 8, 7};
const int digitPins[] = {6, 5}; // Pins to control which digit is active

// Digit patterns for numbers 0-9 (common cathode)
// A pattern '0b0111111' means segments A, B, C, D, E, F are on and G is off
const byte digitPatterns[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

// Numbers to display
int numbersToDisplay[2] = {0, 0};

void setup() {
  // Set segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  // Set digit control pins as outputs
  for (int i = 0; i < 2; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
}

void loop() {
  // Increment the displayed number
  numbersToDisplay[1]++;
  if (numbersToDisplay[1] > 9) {
    numbersToDisplay[1] = 0;
    numbersToDisplay[0]++;
    if (numbersToDisplay[0] > 9) {
      numbersToDisplay[0] = 0;
    }
  }

  // Display the updated number
  for (int i = 0; i < 2; i++) {
    displayDigit(numbersToDisplay[i], i);
    delay(100);
  }
}

void displayDigit(int number, int digit) {
  // Turn off all digits
  for (int i = 0; i < 2; i++) {
    digitalWrite(digitPins[i], HIGH);
  }
  // Set the segments for the current digit
  byte segments = digitPatterns[number];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], (segments >> i) & 0x01);
  }
  // Turn on the selected digit
  digitalWrite(digitPins[digit], LOW);
}