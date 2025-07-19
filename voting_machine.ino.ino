#include <Adafruit_LiquidCrystal.h>

// LCD object using I2C address 0
Adafruit_LiquidCrystal lcd_1(0);

// Button Pins
#define sw1 2  // BJP
#define sw2 3  // INC
#define sw3 4  // AAP
#define sw4 5  // OTH
#define sw5 6  // Show Result

// LED Pins
#define GREEN_LED 12
#define RED_LED 13

int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0;

void setup() {
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  lcd_1.begin(16, 2);
  lcd_1.setCursor(0, 0);
  lcd_1.print("     EVM ");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Circuit Design");
  delay(1000);

  // Pull-up resistors for buttons (if not external)
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
  digitalWrite(sw4, HIGH);
  digitalWrite(sw5, HIGH);

  lcd_1.clear();
  lcd_1.print("BJP INC AAP OTH");
}

void loop() {
  // Display vote counts
  lcd_1.setCursor(0, 1);
  lcd_1.print(vote1);
  lcd_1.setCursor(4, 1);
  lcd_1.print(vote2);
  lcd_1.setCursor(8, 1);
  lcd_1.print(vote3);
  lcd_1.setCursor(12, 1);
  lcd_1.print(vote4);

  // Voting conditions
  if (digitalRead(sw1) == 0) {
    vote1++;
    digitalWrite(GREEN_LED, HIGH);
    delay(500);
    while (digitalRead(sw1) == 0);
    digitalWrite(GREEN_LED, LOW);
    delay(1000);
  }

  if (digitalRead(sw2) == 0) {
    vote2++;
    digitalWrite(GREEN_LED, HIGH);
    delay(500);
    while (digitalRead(sw2) == 0);
    digitalWrite(GREEN_LED, LOW);
    delay(1000);
  }

  if (digitalRead(sw3) == 0) {
    vote3++;
    digitalWrite(GREEN_LED, HIGH);
    delay(500);
    while (digitalRead(sw3) == 0);
    digitalWrite(GREEN_LED, LOW);
    delay(1000);
  }

  if (digitalRead(sw4) == 0) {
    vote4++;
    digitalWrite(GREEN_LED, HIGH);
    delay(500);
    while (digitalRead(sw4) == 0);
    digitalWrite(GREEN_LED, LOW);
    delay(1000);
  }

  // Display result
  if (digitalRead(sw5) == 0) {
    digitalWrite(RED_LED, HIGH);
    int totalVotes = vote1 + vote2 + vote3 + vote4;

    lcd_1.clear();
    if (totalVotes == 0) {
      lcd_1.print("No Voting...");
    } else if (vote1 > vote2 && vote1 > vote3 && vote1 > vote4) {
      lcd_1.print("BJP Wins");
    } else if (vote2 > vote1 && vote2 > vote3 && vote2 > vote4) {
      lcd_1.print("INC Wins");
    } else if (vote3 > vote1 && vote3 > vote2 && vote3 > vote4) {
      lcd_1.print("AAP Wins");
    } else if (vote4 > vote1 && vote4 > vote2 && vote4 > vote3) {
      lcd_1.print("OTH Wins");
    } else {
      lcd_1.print("Tie or No Result");
    }

    delay(5000);

    // Reset
    vote1 = vote2 = vote3 = vote4 = 0;
    lcd_1.clear();
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }
}
