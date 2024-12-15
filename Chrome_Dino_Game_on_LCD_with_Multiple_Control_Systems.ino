#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C LCD initialization (Adjust address as needed)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Custom characters (Dino, branches, bird)
byte DINO_STANDING_PART_1[8]   = {B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00001};
byte DINO_STANDING_PART_2[8]   = {B00111, B00111, B00111, B00100, B11100, B11100, B11000, B01000};
byte DINO_RIGHT_FOOT_PART_1[8] = {B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00001};
byte DINO_RIGHT_FOOT_PART_2[8] = {B00111, B00111, B00111, B00100, B11100, B11100, B11000, B00000};
byte DINO_LEFT_FOOT_PART_1[8]  = {B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00000};
byte DINO_LEFT_FOOT_PART_2[8]  = {B00111, B00111, B00111, B00100, B11100, B11100, B11000, B01000};
byte DOUBLE_BRANCH_PART_1[8]   = {B00000, B00100, B00100, B10100, B10100, B11100, B00100, B00100};
byte DOUBLE_BRANCH_PART_2[8]   = {B00100, B00101, B00101, B10101, B11111, B00100, B00100, B00100};
byte BIRD_WINGS_PART_1[8]      = {B00001, B00001, B00001, B00001, B01001, B11111, B00000, B00000};
byte BIRD_WINGS_PART_2[8]      = {B00000, B10000, B11000, B11100, B11110, B11111, B00000, B00000};

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

int melody[] = {

  // Super Mario Bros theme
  // Score available at https://musescore.com/user/2123/scores/2145
  // Theme by Koji Kondo
  
  
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  
  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
  REST,1, 
  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
  NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19
  
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
  REST,1,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
  NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
  
  //game over sound
  NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
  NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
  NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,  

};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int tempo = 200;
int wholenote = (60000 * 4) / tempo;
int currentNote = 0;
unsigned long musicTimer = 0;

// Variables
int dino_col_1 = 1;
int dino_col_2 = 2;
int dino_row = 1;

unsigned long timer = 0;    // Using millis instead of delay
int period = 100;           // Period in milliseconds
int flag = 1;

int branch_row = 0;
int branch_col = 13;
int period2 = 100;
unsigned long timer2 = 0;
int a = 0;
int b = 1;
int c = 2;
int d = 0;
unsigned long timer3 = 0;
int period3 = 100;
int points = 0;
int points2 = 0;
int randomNumber = 0;
int bird_col = 13;
int e = 0;
int bird_row = 1;
int currentSignal = 0;
int oldSignal = 0;
int f = 13;
int acceleration = 1;
unsigned long timer4 = 0;
int period4 = 800;
int button = 11; // Pushbutton pin for jumping
int buzzer = 10; // Buzzer pin for sound effects
int tiltPin = 12;


// Added for potentiometer
int potPin = A0;       // Potentiometer input pin
int potValue = 0;      // To store the potentiometer reading
int jumpThreshold = 512; // Adjust this threshold as needed (0-1023 scale)

int ldrPin = A1;          // LDR input pin
int ldrValue = 0;         // To store the LDR reading
int ldrThreshold = 100;   // Adjust this after testing LDR values in light and dark conditions

bool gameOver = false;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);

  Serial.begin(9600);
  // No need to set pinMode for A0 as analog pins don't require pinMode for input
  
  lcd.init();        // Initialize the LCD for I2C
  lcd.backlight();   // Turn on the LCD backlight

  // Create custom characters
  lcd.createChar(0, DINO_STANDING_PART_1);
  lcd.createChar(1, DINO_STANDING_PART_2);
  lcd.createChar(2, DINO_RIGHT_FOOT_PART_1);
  lcd.createChar(3, DINO_RIGHT_FOOT_PART_2);
  lcd.createChar(4, DINO_LEFT_FOOT_PART_1);
  lcd.createChar(5, DINO_LEFT_FOOT_PART_2);
  lcd.createChar(6, DOUBLE_BRANCH_PART_1);
  lcd.createChar(7, DOUBLE_BRANCH_PART_2);
}

void playMusic() {
  if (millis() - musicTimer > wholenote / abs(melody[currentNote * 2 + 1])) {
    // Play the current note
    int note = melody[currentNote * 2];
    int duration = melody[currentNote * 2 + 1];

    if (note != REST) {
      tone(buzzer, note, (wholenote / duration) * 0.9); // Play for 90% of the duration
    }

    // Advance to the next note
    currentNote++;
    if (currentNote >= notes) {
      currentNote = 0; // Restart the melody
    }

    musicTimer = millis();
  }
}

void playGameOverSound() {
  int gameOverMelody[] = {NOTE_C5, -4, NOTE_G4, -4, NOTE_E4, 4, NOTE_A4, -8, NOTE_B4, -8, NOTE_A4, -8, NOTE_GS4, -8};
  int gameOverNotes = sizeof(gameOverMelody) / sizeof(gameOverMelody[0]);

  for (int i = 0; i < gameOverNotes; i += 2) {
    tone(buzzer, gameOverMelody[i], wholenote / abs(gameOverMelody[i + 1]) * 0.9);
    delay(wholenote / abs(gameOverMelody[i + 1]));
  }
  noTone(buzzer);
}

void loop() {
  playMusic();
  
  // Read potentiometer value
  potValue = analogRead(potPin);
   // Read LDR value
  ldrValue = analogRead(ldrPin);
  // Serial.println(ldrValue);
  int tiltState = digitalRead(tiltPin);
  // If the tilt sensor is tilted, it will connect the pin to GND, so tiltState will be LOW.
  // If not tilted, tiltState will be HIGH.

  bool isTilted = (tiltState == HIGH);
  Serial.println(tiltState);

  bool isJumping = (digitalRead(button) == LOW)      // button pressed
               || (potValue > jumpThreshold)       // potentiometer above threshold
               || (ldrValue < ldrThreshold)        // LDR indicates dark
               || isTilted;                        // tilt sensor activated

  // Handle dinosaur foot switching using millis
  if (millis() > timer + period) {
    timer = millis();
    if (flag == 1) {
      flag = 2;
    } else if (flag == 2) {
      flag = 1;
    }
  }

  // Control the speed of the branches
  if (millis() > timer2 + period2) {
    timer2 = millis();
    branch_col = branch_col - 1;
    if (branch_col < 0) {
      branch_col = 13;
      period2 = period2 - acceleration; // Increasing speed over time
      randomNumber = random(0, 3);     // Generate random obstacle
    }

    // Clear old obstacle positions
    f = branch_col + 1;
    lcd.setCursor(f, 1);
    lcd.print(" ");
    f = branch_col + 1;
    lcd.setCursor(f, 0);
    lcd.print(" ");

    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(0, 0);
    lcd.print(" ");

    a = 1;
  }

  // Display dinosaur
  if (d == 0) {
    if (flag == 1) {
      lcd.setCursor(dino_col_1, dino_row);
      lcd.write(byte(2));
      lcd.setCursor(dino_col_2, dino_row);
      lcd.write(byte(3));
    } else if (flag == 2) {
      lcd.setCursor(dino_col_1, dino_row);
      lcd.write(byte(4));
      lcd.setCursor(dino_col_2, dino_row);
      lcd.write(byte(5));
    }
  }

  // Display obstacles
  if (a == 1) {
    if (randomNumber == 1) {
      branch_row = 1;
      lcd.createChar(6, DOUBLE_BRANCH_PART_1);
      lcd.setCursor(branch_col, branch_row);
      lcd.write(byte(6));
    } else if (randomNumber == 2) {
      branch_row = 1;
      lcd.createChar(7, DOUBLE_BRANCH_PART_2);
      lcd.setCursor(branch_col, branch_row);
      lcd.write(byte(7));
    } else {
      // Bird obstacle
      bird_col = branch_col - 1;
      branch_row = 0;
      lcd.createChar(6, BIRD_WINGS_PART_1);
      lcd.setCursor(bird_col, branch_row);
      lcd.write(byte(6));

      lcd.createChar(7, BIRD_WINGS_PART_2);
      lcd.setCursor(branch_col, branch_row);
      lcd.write(byte(7));
    }
    a = 0;
  }

  // Collision conditions
  // If jumping and obstacles are at collision positions (bird at top level)
  if (isJumping && (branch_col == 1 || branch_col == 2 || bird_col == 1 || bird_col == 2) && branch_row == 0) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("GAME OVER");
    playGameOverSound();
    delay(2000);
    lcd.clear();
    gameOver = false;
    branch_col = 15;
    period2 = 100;
    points = 0;
    points2 = 0;
    period2 = 100;
  }

  // Branch collision condition (when on the ground)
  if ((branch_col == b || branch_col == c) && branch_row == 1) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("GAME OVER");
    playGameOverSound();
    delay(2000);
    lcd.clear();
    gameOver = false;
    branch_col = 15;
    period2 = 100;
    points = 0;
    points2 = 2;
    period2 = 100;
  }

  // Jumping logic
  if (isJumping) {
    // Move dinosaur up
    b = 50; // Assign large values so they don't coincide with obstacle columns
    c = 50;

    if (d == 0) {
      lcd.setCursor(0, 1);  // CLEAR BELOW
      lcd.print("    ");
    }
    d = 1;

    lcd.setCursor(dino_col_1, 0);
    lcd.write(byte(2));
    lcd.setCursor(dino_col_2, 0);
    lcd.write(byte(3));

    // Points accumulation delay
    if (millis() > timer4 + period4) {
      timer4 = millis();
      int note[] = {600};
      // You could potentially add a sound effect for the jump here if desired
    }
  } else {
     // Clear the top row where the dinosaur was drawn
    lcd.setCursor(dino_col_1, 0);
    lcd.print(" ");
    lcd.setCursor(dino_col_2, 0);
    lcd.print(" ");
    // Dinosaur goes down
    b = 1;
    c = 2;
    d = 0;

     // Redraw the dinosaur at the bottom row (you likely already have this code)
    if (flag == 1) {
      lcd.setCursor(dino_col_1, dino_row);
      lcd.write(byte(2));
      lcd.setCursor(dino_col_2, dino_row);
      lcd.write(byte(3));
    } else if (flag == 2) {
      lcd.setCursor(dino_col_1, dino_row);
      lcd.write(byte(4));
      lcd.setCursor(dino_col_2, dino_row);
      lcd.write(byte(5));
    }
  }

  // Points accumulation over time
  if (millis() > timer3 + period3) {
    timer3 = millis();
    lcd.setCursor(14, 1);
    lcd.print(points);

    points = points + 1;

    if (points == 100) {
      points = 0;
      points2 = points2 + 1;
      if (points2 == 100) {
        points2 = 0;
      }
    }

    lcd.setCursor(14, 1);
    lcd.print(points);
    lcd.setCursor(14, 0);
    lcd.print(points2);

    // State change detector for the button
    currentSignal = digitalRead(button);
    if (currentSignal != oldSignal) {
      lcd.setCursor(1, 0);
      lcd.print("  ");
    }
    oldSignal = currentSignal;
  }
}