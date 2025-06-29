#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>


Servo monServo;

LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte ROWS = 4; // Nombre de lignes
const byte COLS = 4; // Nombre de colonnes

// Définir les touches du clavier
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Définir les broches des lignes et des colonnes
byte rowPins[ROWS] = {2, 3, 4, 5}; // Connecté aux broches numériques 2-5
byte colPins[COLS] = {6, 7, 8, 9}; // Connecté aux broches numériques 6-9

// Initialiser le clavier
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Variable pour stocker l'entrée
char inputNumber[9]; // Longueur de 9 pour les 8 chiffres + 1 pour le caractère nul
int inputIndex = 0; // Indice actuel pour l'insertion des caractères
bool isProcessing = false; // Drapeau pour indiquer si le traitement est en cours

void setup() {
    // Initialiser le moniteur série à 9600 bauds
    Serial.begin(9600);
    lcd.init();
    
    // Activez le rétroéclairage de l'écran LCD
    lcd.backlight();
    
    // Placez le curseur au début de la première ligne
    lcd.setCursor(0, 0);
    
    // Affichez un message sur la première ligne de l'écran LCD
    lcd.print("porte est fermee");
    
    // Placez le curseur au début de la deuxième ligne
    lcd.setCursor(0, 1);
    monServo.attach(10);
    monServo.write(0);

}

void loop() {



     if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        if(command.indexOf("porte") != -1){
            clearLCD();
             lcd.setCursor(0, 0);
            lcd.print("porte est ouverte");
            monServo.write(95);
            delay(3000);
            monServo.write(0);
            clearLCD();
             lcd.setCursor(0, 0);
            lcd.print("porte est fermee");
            clearLCD();
             lcd.setCursor(0, 0);
            lcd.print("votre code:");
        }
        int separatorIndex = command.indexOf(';');

        if (separatorIndex != -1) {
            // Extraire le nom du participant
            String nomParticipant = command.substring(0, separatorIndex);
            // Extraire le nom de l'événement
            String nomEvenement = command.substring(separatorIndex + 1);
            clearLCD();
            lcd.setCursor(0, 0);
            lcd.print("nom: "+nomParticipant);
            lcd.setCursor(0, 1);
            lcd.print("event: "+nomEvenement);
            delay(1000);
        }
        if (command.equals("aucune_participation")) {
            clearLCD();
            lcd.setCursor(0, 0);
            lcd.print("aucun");
            lcd.setCursor(0, 1);
            lcd.print("participation");
            delay(1000);
             clearLCD();
             lcd.setCursor(0, 0);
    
          // Affichez un message sur la première ligne de l'écran LCD
          lcd.print("votre code:");
        }
    }

    char key = keypad.getKey();
    if (key != NO_KEY && !isProcessing) {
        // Gérer la touche '#' pour réinitialiser l'entrée
        if (key == '#') {
            // Effacer l'afficheur LCD et afficher "votre code"
            clearLCD();
            lcd.print("votre code:");
            inputIndex = 0; // Réinitialiser l'index d'entrée
            lcd.setCursor(0, 1);
        } else {
            // Ajouter le caractère saisi à l'entrée si c'est un chiffre
            if (isdigit(key)) { // Vérifier si le nombre de chiffres est inférieur à 8
                // Ajouter le chiffre à l'entrée
                inputNumber[inputIndex] = key;
                inputIndex++;

                // Afficher le caractère saisi sur l'écran LCD
                lcd.print(key);

                if (inputIndex == 8) {
                    processInput();
                }
            }
        }
    }
}

void clearLCD() {
    lcd.clear();
}

void processInput() {
    isProcessing = true;
    for (int i = 0; i < 8; i++) {
        Serial.print(inputNumber[i]);
    }
    Serial.println("");
    isProcessing = false;

    // Réinitialiser les variables pour la prochaine saisie
    inputIndex = 0;
}