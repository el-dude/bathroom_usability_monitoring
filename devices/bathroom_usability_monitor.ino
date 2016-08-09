//
// ---------------------------
//  ______ _   ____  ___
//  | ___ \ | | |  \/  |
//  | |_/ / | | | .  . |
//  | ___ \ | | | |\/| |
//  | |_/ / |_| | |  | |
//  \____/ \___/\_|  |_/
//                                         
// ---------------------------
// Bathroom Usability Monitor
// ---------------------------
//
// This App will monitor the photoresistor and door to determine if the room is being ocupied.
int boardLedPin         = D7; // This is the LED that is already on your device.
int photoresistorPin    = A0; // The Light sensor
int PowerPin            = A5; // Power for the Light sensor
int DoorPin             = D0; // The Door sensor 
int LightVal            = 0;  // Int value for the Light sensor
int DoorVal             = 0;  // Int value for the Door sensor
int RoomVal;                  // Declaring the Var for the door stats to be stored

// Set it up 
void setup() {
    Particle.unsubscribe();
    Particle.variable("LightStats", &LightVal, INT);
    Particle.variable("DoorStats", &DoorVal, INT);
    Particle.variable("RoomStats", &RoomVal, INT);
    pinMode(boardLedPin, OUTPUT);       
    pinMode(PowerPin,OUTPUT);
    pinMode(photoresistorPin, INPUT);
    pinMode(DoorPin,INPUT);
    digitalWrite(boardLedPin, HIGH);
    digitalWrite(PowerPin,HIGH);
    
}

// Now for the loop.
void loop() {
    LightVal    = analogRead(photoresistorPin);
    DoorVal     = digitalRead(DoorPin);
    RoomVal     = 0;
    delay(100);
    if (LightVal > 100 && DoorVal == 1) {
        RoomVal     = 1;
        delay(2000);
        //Particle.publish("LightStats",String(LightVal));
        //Particle.publish("DoorStats",String(DoorVal));
        Particle.publish("RoomStats",String(RoomVal));
        digitalWrite(boardLedPin,HIGH);
    }
    else {
        RoomVal     = 0;
        delay(2000);
        //Particle.publish("LightStats",String(LightVal));
        //Particle.publish("DoorStats",String(DoorVal));
        Particle.publish("RoomStats",String(RoomVal));
        digitalWrite(boardLedPin,LOW);
    }
}

