// --- TELAS E FLUXOS ---

void showMenu(){
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, LOW);

    Serial.println("=== JOGO DA REACAO ===");
    Serial.println("P1: Iniciar Singleplayer");
    Serial.println("P2: Iniciar Multiplayer");
    Serial.println("Escolha um modo apertando o botão correspondente");
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

    Serial.println();
    Serial.print("=== LEVEL ");
    Serial.print(currentLevel);
    Serial.println(" ===");

    if (currentState == SINGLEPLAYER) {
        if (currentLevel == 1) Serial.println("Acerte no intervalo entre 3 e 7 segundos.");
        else if (currentLevel == 2) Serial.println("Acerte no intervalo entre 3 e 5 segundos");
        else if (currentLevel == 3) Serial.println("Acerte no intervalo entre 2,5 e 3 segundos");
        else Serial.println("Acerte exatemente em 1 segundo");
    }  else if (currentState == MULTIPLAYER) {
        unsigned long target = gainTimeTargetDuo(currentLevel);
        Serial.print("TEMPO ALVO: ");
        Serial.print(target/ 1000.0, 2);
        Serial.println(" segundos.");
        Serial.println("Quem apertar mais proximo do tempo ganha 1 ponto!");
    }

    Serial.println("Prepare-se...");
    for (int i = 5; i >= 1; i--){
        Serial.println(i);
        delay(1000);
    }

    Serial.println("Valendo! Aperte o botao!");
    startTime = millis();

   // Reset das váriaveis para a rodada
   p1AlreadyPlay = false;
   p2AlreadyPlay = false;
   p1PreviousState = (digitalRead(BTN_P1) == LOW);
   p2PreviousState = (digitalRead(BTN_P2) == LOW);  
}

