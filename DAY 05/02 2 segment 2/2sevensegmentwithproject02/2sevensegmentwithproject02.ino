int segPin[7] = {13, 12, 11, 10, 9, 8, 7};

byte num[10] = {
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

#define ena1 6
#define ena2 5

int count = 0; // Declare count variable

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segPin[i], OUTPUT);
  }

  pinMode(ena1, OUTPUT);
  pinMode(ena2, OUTPUT);
}

void loop() {
  for (int n = 0; n < 100; n++) {
    //delay(1000);
    count++;
    
    int bit1 = count % 10;
    int bit2 = count / 10;

    // Display the first digit
    PN(bit1);
    digitalWrite(ena1, LOW);
    digitalWrite(ena2, HIGH);
    delay(100);

    // Display the second digit
    PN(bit2);
    digitalWrite(ena1, HIGH);
    digitalWrite(ena2, LOW);
    delay(100);
  }
}

void PN(int a) {
  byte b = num[a];
  for (int c = 0; c < 7; c++) {
    bool s = bitRead(b, c);
    digitalWrite(segPin[c], s);
  }
}