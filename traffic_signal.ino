// ============================
// Lane 1 Pins
// ============================
int L1_R = 23;
int L1_Y = 22;
int L1_G = 21;

// ============================
// Lane 2 Pins
// ============================
int L2_R = 19;
int L2_Y = 18;
int L2_G = 5;

// ============================
// Lane 3 Pins
// ============================
int L3_R = 4;
int L3_Y = 2;
int L3_G = 15;

String cmd = "";

// =================================
// Setup
// =================================
void setup() {

  Serial.begin(115200);

  pinMode(L1_R, OUTPUT);
  pinMode(L1_Y, OUTPUT);
  pinMode(L1_G, OUTPUT);

  pinMode(L2_R, OUTPUT);
  pinMode(L2_Y, OUTPUT);
  pinMode(L2_G, OUTPUT);

  pinMode(L3_R, OUTPUT);
  pinMode(L3_Y, OUTPUT);
  pinMode(L3_G, OUTPUT);

  allRed();
}

// =================================
// Set All Red
// =================================
void allRed() {

  digitalWrite(L1_R, HIGH);
  digitalWrite(L1_Y, LOW);
  digitalWrite(L1_G, LOW);

  digitalWrite(L2_R, HIGH);
  digitalWrite(L2_Y, LOW);
  digitalWrite(L2_G, LOW);

  digitalWrite(L3_R, HIGH);
  digitalWrite(L3_Y, LOW);
  digitalWrite(L3_G, LOW);
}

// =================================
// Yellow Transition
// =================================
void yellowTransition() {

  // Turn OFF all green
  digitalWrite(L1_G, LOW);
  digitalWrite(L2_G, LOW);
  digitalWrite(L3_G, LOW);

  // Turn ON all yellow
  digitalWrite(L1_Y, HIGH);
  digitalWrite(L2_Y, HIGH);
  digitalWrite(L3_Y, HIGH);

  delay(2000);

  // Turn OFF yellow
  digitalWrite(L1_Y, LOW);
  digitalWrite(L2_Y, LOW);
  digitalWrite(L3_Y, LOW);

  allRed();
}

// =================================
// Lane 1 Green
// =================================
void lane1Green() {

  yellowTransition();

  digitalWrite(L1_R, LOW);
  digitalWrite(L1_G, HIGH);
}

// =================================
// Lane 2 Green
// =================================
void lane2Green() {

  yellowTransition();

  digitalWrite(L2_R, LOW);
  digitalWrite(L2_G, HIGH);
}

// =================================
// Lane 3 Green
// =================================
void lane3Green() {

  yellowTransition();

  digitalWrite(L3_R, LOW);
  digitalWrite(L3_G, HIGH);
}

// =================================
// Main Loop
// =================================
void loop() {

  if (Serial.available()) {

    cmd = Serial.readStringUntil('\n');

    cmd.trim();

    // ============================
    // Normal Traffic Commands
    // ============================

    if (cmd == "L1") {

      lane1Green();
      Serial.println("Lane 1 Green");
    }

    else if (cmd == "L2") {

      lane2Green();
      Serial.println("Lane 2 Green");
    }

    else if (cmd == "L3") {

      lane3Green();
      Serial.println("Lane 3 Green");
    }

    // ============================
    // Emergency Commands
    // ============================

    else if (cmd == "E1") {

      lane1Green();
      Serial.println("Emergency Lane 1");
    }

    else if (cmd == "E2") {

      lane2Green();
      Serial.println("Emergency Lane 2");
    }

    else if (cmd == "E3") {

      lane3Green();
      Serial.println("Emergency Lane 3");
    }
  }
}
