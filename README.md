# 🗳️ Digital Voting Machine using Arduino

This is a simulated **Electronic Voting Machine (EVM)** built using Arduino Uno, push buttons, and an I2C LCD display. It allows users to vote for one of four political parties and displays the result based on vote counts. The project was created and tested using [Tinkercad Circuits](https://www.tinkercad.com/).

---

## 💡 Features

- ✅ 4 Voting Buttons for parties: BJP, INC, AAP, OTH
- 📟 LCD Display to show vote counts and result
- 🔄 Reset after result display
- 🔒 Secure logic to ensure one vote per press
- 🔴 Red LED for result display, 🟢 Green LED for vote confirmation
- 🧪 Fully simulated on Tinkercad

---

## 🧰 Components Used

| Component          | Quantity |
|--------------------|----------|
| Arduino Uno        | 1        |
| Push Buttons       | 5        |
| I2C 16x2 LCD       | 1        |
| Breadboard         | 1        |
| Jumper Wires       | As needed |
| Red & Green LEDs   | 2        |

---

## 💻 Simulation Platform

The project is created using [Tinkercad Circuits](https://www.tinkercad.com/), which allows full simulation without any physical hardware.

🔗 **[Click here to open the simulation](https://www.tinkercad.com/things/8GUR59uuk9Z/editel?returnTo=%2Fdashboard&sharecode=0FnaoimXcOV9dB_1VnzL9TFb49s-Cq9ijkAHWF00loA)**  


---

## 📂 Repository Structure


## 🚀 Getting Started

1. Open the `.ino` file in the Arduino IDE.
2. Upload it to an Arduino Uno (if you're testing on real hardware).
3. Or open the Tinkercad simulation and run it online.
4. Press the buttons to cast votes.
5. Press the result button to view the winner on the LCD.

---

## 🧠 How the Code Works

- Each candidate has a button (`sw1` to `sw4`).
- A fifth button (`sw5`) is used to display the result.
- When a vote is cast, the green LED blinks as confirmation.
- The LCD shows vote counts in real-time.
- Upon pressing the result button:
  - The system determines the winner.
  - If there's a tie, it displays "Tie or No Result".
  - Red LED turns on during result display.
  - System resets after displaying the result.

---

## 👩‍💻 Author

**Poojitha M.**  
Final Year ECE Student |  Simulation Project 2025

---

