// --- TELAS E FLUXOS ---
bool stateLED = false;

void showMenu(){
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, LOW);


    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("JOGO DA REACAO");
    lcd.setCursor(0, 1);
    lcd.print("P1:Solo  P2:Duo"); 
    //Serial.println("=== JOGO DA REACAO ===");
    //Serial.println("P1: Iniciar Singleplayer");
    //Serial.println("P2: Iniciar Multiplayer");
    //Serial.println("Escolha um modo apertando o botão correspondente");
}

void backMenu(){
    currentState = MENU;
    currentLevel = 1;
    pointsP1 = 0;
    pointsP2 = 0;

    // Evita que segurar o botão reinicie imediatamente
    p1PreviousState = (digitalRead(BTN_P1) == LOW);
    p2PreviousState = (digitalRead(BTN_P2) == LOW);

    showMenu();
}

void startRound() {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, LOW);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("==== Level ");
    lcd.print(currentLevel);
    lcd.print(" ====");
    delay(1500);
    /*Serial.println();
    Serial.print("=== LEVEL ");
    Serial.print(currentLevel);
    Serial.println(" ===");*/

    if (currentState == SINGLEPLAYER) {
        if (currentLevel == 1) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Intervalo 3 a 7");

        } // Serial.println("Acerte no intervalo entre 3 e 7 segundos.");
        else if (currentLevel == 2) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Invertvalo 3 a 5");
        }//Serial.println("Acerte no intervalo entre 3 e 5 segundos");
        else if (currentLevel == 3) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Invertvalo entre");  
            lcd.setCursor(0, 1);
            lcd.print("2,5 a 3s");    
        }//Serial.println("Acerte no intervalo entre 2,5 e 3 segundos");
        else {
            lcd.clear();
            lcd.setCursor(0 ,0);
            lcd.print("APERTO PERFEITO");
            lcd.setCursor(4,1);
            lcd.print("1 SEGUNDO");
        }///Serial.println("Acerte exatemente em 1 segundo");
    }  else if (currentState == MULTIPLAYER) {
        unsigned long target = gainTimeTargetDuo(currentLevel);
        lcd.clear();
        lcd.setCursor(0 ,0);
        lcd.print("TEMPO ALVO: "); lcd.print(target/ 1000.2); lcd.print(" s");
        lcd.setCursor(0, 1);
        lcd.print("APERTO PRECISO!");
        /*Serial.print("TEMPO ALVO: ");
        Serial.print(target/ 1000.0, 2);
        Serial.println(" segundos.");
        Serial.println("Quem apertar mais proximo do tempo ganha 1 ponto!");*/
    }

    // Contagem Regressiva
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Prepare-se...");
    delay(1000);
    lcd.clear();
    // Serial.println("Prepare-se...");

    int count = 0;
    for (int i = 5; i >= 1; i--){
        lcd.setCursor(count, 0);
        count+=2;
        lcd.print(i);      
        //Serial.println(i);
        if (stateLED == false) {
            digitalWrite(LEDG, HIGH);
            stateLED = true;
        } else {
            digitalWrite(LEDG, LOW);
            stateLED = false;
        }
        delay(1000);
    }

    digitalWrite(LEDG, LOW);
    lcd.clear();
    lcd.setCursor(0 ,0);
    lcd.print("Valendo");
    //Serial.println("Valendo! Aperte o botao!");
    startTime = millis();

   // Reset das váriaveis para a rodada
   p1AlreadyPlay = false;
   p2AlreadyPlay = false;
   p1PreviousState = (digitalRead(BTN_P1) == LOW);
   p2PreviousState = (digitalRead(BTN_P2) == LOW);  
}

