#include <Adafruit_Fingerprint.h>
#include <Keypad.h>

//Buzzer/Keypad
  const byte ROWS = 5; //5 rows
  const byte COLS = 4; //4 columns
  char* specialKeys[] ={
              "LEFT",  "0", "RIGHT", "ENTER",
              "7",  "8", "9", "ESC",
              "4",  "5", "6", "DOWN",
              "1",  "2", "3", "UP",
              "F1",  "F2", "#", "*"  
                      };

                      
  char specialKeysID[] = {
          '0',  'B', '#', '*',
          '1',  '2', '3', 'C',
          '4',  '5', '6', 'D',
          '7',  '8', '9', 'E',
          'F',  'i', 'G', 'H'
        };                    

  char keys[ROWS][COLS] = {
  {specialKeysID[0],  specialKeysID[1], specialKeysID[2], specialKeysID[3]},
  {specialKeysID[4],  specialKeysID[5], specialKeysID[6], specialKeysID[7]},
  {specialKeysID[8],  specialKeysID[9], specialKeysID[10], specialKeysID[11]},
  {specialKeysID[12],  specialKeysID[13], specialKeysID[14], specialKeysID[15]},
  {specialKeysID[16],  specialKeysID[17], specialKeysID[18], specialKeysID[19]}
  };


  byte rowPins[ROWS] = {6,7,8,9,10}; //connect to the row pinouts of the kpd
  byte colPins[COLS] = {2,3,4,5}; //connect to the column pinouts of the kpd

  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

  unsigned long loopCount;
  unsigned long startTime;
//Buzzer/Keypad
#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// Set up the serial port to use softwareserial..
SoftwareSerial mySerial(12, 11);

#else
// On Leonardo/M0/etc, others with hardware serial, use hardware serial!
// #0 is green wire, #1 is white
#define mySerial Serial1

#endif


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);




void setup()
{
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit Fingerprint sensor enrollment");

  // set the data rate for the sensor serial port
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  //Buzzer/Keypad
  pinMode(13, OUTPUT);
  //Buzzer/Keypad

}
int ok = 0;
String code = "";
void loop() { 
  char key = keypad.getKey();
  if (key){
    Serial.print(getKey(key));
    if(ok == 0){
      tone(13, 1); // allume le buzzer actif arduino
      delay(300);
      noTone(13);  // désactiver le buzzer actif arduino
      delay(500);
    }else{
      
      if (code.length() < 4){
        code.concat(getKey(key));
      }
      if(code.length() == 4){
        Serial.println("the code is : "+ code);
        code = "";
      }
    }
  } 
  
  // Check if there's data available to read from the serial port
  if (Serial.available() > 0) {
   
    String command = Serial.readStringUntil('\n');
    Serial.println(command);
    if (command.indexOf("Delete") != -1) {
      int delimiterIndex = command.indexOf(",");
      if ( delimiterIndex!= -1) {
        String idStr = command.substring(delimiterIndex+1,-1);
        uint8_t id = idStr.toInt();
        deleteFingerprint(id);
        
      }
    }
    if(command.indexOf("Buzzer") != -1){
      int p=getFingerprintID();
      Serial.println(p);
      if(p == 255 ){
        ok = 1;
        tone(13, 1000);
        Serial.println("notCode");

      }
      else{
          tone (13, 10000); // allume le buzzer actif arduino
          delay(50);
          noTone(13);  // désactiver le buzzer actif arduino
          delay(50);
          tone(13, 10000); // allume le buzzer actif arduino
          delay(50);
          noTone(13);
          delay(50);
          tone(13, 10000); // allume le buzzer actif arduino
          delay(50);
          noTone(13);
      }
    }
    if (command.indexOf("Ajouter") != -1) {
      int delimiterIndex = command.indexOf(",");
      if ( delimiterIndex!= -1) {
        String idStr = command.substring(delimiterIndex+1,-1);
        int8_t id = idStr.toInt();
        delay (3000);
        getFingerprintEnroll(id);
      }
    }
    if (command.indexOf("Check") != -1) {
      Serial.println("Put Put your Finger ");
      delay (3000);
      int p=getFingerprintID();
      Serial.println(p);
      if(p == 255 ){
        ok = 1;
        tone(13, 1000);

      }
      else{
          tone (13, 10000); // allume le buzzer actif arduino
          delay(50);
          noTone(13);  // désactiver le buzzer actif arduino
          delay(50);
          tone(13, 10000); // allume le buzzer actif arduino
          delay(50);
          noTone(13);
          delay(50);
          tone(13, 10000); // allume le buzzer actif arduino
          delay(50);
          noTone(13);
      }
    }


    if(command.indexOf("ToneOff") != -1){
      noTone(13);
      ok = 0;
    }
  }
}


uint8_t getFingerprintEnroll(uint8_t id) {

  int p = -1;
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  while (p != FINGERPRINT_OK) {
    switch (p) {
      case FINGERPRINT_OK:
        Serial.println("Image converted");
        break;
      case FINGERPRINT_IMAGEMESS:
        Serial.println("Image too messy");
        return p;
      case FINGERPRINT_PACKETRECIEVEERR:
        Serial.println("Communication error");
        return p;
      case FINGERPRINT_FEATUREFAIL:
        Serial.println("Could not find fingerprint features");
        return p;
      case FINGERPRINT_INVALIDIMAGE:
        Serial.println("Could not find fingerprint features");
        return p;
      default:
        Serial.println("Unknown error");
        return p;
    }
  }

  Serial.println("Remove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  p = -1;
  Serial.println("Place same finger again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("Prints matched!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Fingerprints did not match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("Stored!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  return true;
}

uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;

  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK) {
    Serial.println("Deleted!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not delete in that location");
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
  } else {
    Serial.print("Unknown error: 0x"); Serial.println(p, HEX);
  }

  return p;
}

uint8_t getFingerprintID() {
  int p = -1;
  p = finger.getImage();
  //while (p != FINGERPRINT_OK) {
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  //}

  // OK success!

  p = finger.image2Tz();
  while (p != FINGERPRINT_OK) {
    switch (p) {
      case FINGERPRINT_OK:
        Serial.println("Image converted");
        break;
      case FINGERPRINT_IMAGEMESS:
        Serial.println("Image too messy");
        return p;
      case FINGERPRINT_PACKETRECIEVEERR:
        Serial.println("Communication error");
        return p;
      case FINGERPRINT_FEATUREFAIL:
        Serial.println("Could not find fingerprint features");
        return p;
      case FINGERPRINT_INVALIDIMAGE:
        Serial.println("Could not find fingerprint features");
        return p;
      default:
        Serial.println("Unknown error");
        return p;
    }
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return -1;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}

//getKey
char* getKey(char *k)
{
 //Robojax.com 5x4 keypad detecting string value
  for(int i=0; i<20; i++)
  {
    if(specialKeysID[i] ==k) return specialKeys[i];
  }
 
}//getKey