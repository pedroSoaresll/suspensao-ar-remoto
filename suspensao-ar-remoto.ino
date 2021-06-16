#define relay1 12
#define relay2 11
#define relay3 10
#define relay4 9
#define relay5 8
#define relay6 7
#define relay7 6
#define relay8 5
#define receptor 2

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay7, HIGH);
  digitalWrite(relay8, HIGH);
}

void disableAllRelays() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay7, HIGH);
  digitalWrite(relay8, HIGH);
}

void enableOrDisable(int relay) {
  int pin = digitalRead(relay);
  
  if (pin == 0) {
    digitalWrite(relay, HIGH);
  } else {
    digitalWrite(relay, LOW);  
  }

  delay(800);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (mySwitch.available()) {
    long code = mySwitch.getReceivedValue();
    
    Serial.print("Received ");
    Serial.println( code );

    if (code == 134115637) {
      enableOrDisable(relay1);
    }

    else if (code == 134115781) {
      enableOrDisable(relay2);  
    }

    else if (code == 134115829) {
      enableOrDisable(relay3);
    }

    else if (code == 134115733) {
      enableOrDisable(relay4);
    }
    
    else if (code == 134115717) {
      enableOrDisable(relay5);
    }

    else if (code == 134115605) {
      enableOrDisable(relay6);
    }

    else if (code == 134115653) {
      enableOrDisable(relay7);
    }

    else if (code == 134115621) {
      enableOrDisable(relay8);
    }


    
    mySwitch.resetAvailable();
  }
}
