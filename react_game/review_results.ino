// --- AVALIAÇÃO DE RESULTADOS ---

void rateSinglePlayer(unsigned long time, bool hit){
    Serial.print("Tempo do P!: ");
    Serial.print(time/ 1000.0, 3);
    Serial.println(" s");

    if (hit) {
        digitalWrite(LEDG, HIGH);
        Serial.println("ACERTOU!");
        delay(2000);
        currentLevel++;

        if (currentLevel > TOTAL_LEVELS) {
            Serial.println("\nPARABENS! Voce venceu todos os niveis!");
            delay(4000);
            backMenu();
        } else {
            startRound();
        }
    } else {
        digitalWrite(LEDR, HIGH);
        Serial.println("VOCE PERDEU! Fim de jogo.");
        delay(3000);
        backMenu();
    }
}

void rateMultiplayer() {
    unsigned long target = gainTimeTargetDuo(currentLevel);
    unsigned long missP1 = diffCalculator(target, timePressP1);
    unsigned long missP2 = diffCalculator(target, timePressP2);

    Serial.println("\n--- RESULTADO DA RODADA ---");
    Serial.print("Alvo: ");
    Serial.print(target/ 1000.0, 3);
    Serial.println(" s");

    Serial.print("P1: ");
    Serial.print(timePressP1/ 1000.0, 3);
    Serial.print(" s(Margem: ");
    Serial.print(missP1/ 1000.0, 3);
    Serial.println(" s");

    Serial.print("P2: ");
    Serial.print(timePressP2/ 1000.0, 3);
    Serial.print(" s(Margem: ");
    Serial.print(missP2/ 1000.0, 3);
    Serial.println(" s");

    if (missP1 < missP2) {
        Serial.println(">>> P1 foi mais preciso! Ponto para P1.");
        pointsP1++;
        digitalWrite(LEDG, HIGH);
    } else if (missP2 < missP1) {
        Serial.println(">>> P2 foi mais preciso! Ponto para P2.");
        pointsP2++;
        digitalWrite(LEDR, HIGH);
    } else {
        Serial.println(">>> EMPATE! Ninguem pontual.");
        digitalWrite(LEDG, HIGH);
        digitalWrite(LEDR, HIGH);
    }

    Serial.print("PLACAR GERAL -> P1: ");
    Serial.print(pointsP1);
    Serial.print(" | P2: ");
    Serial.println(pointsP2);

    delay(4000);
    currentLevel++;

    //Verificar se o jogo acabou
    if (currentLevel <= TOTAL_LEVELS) {
        startRound();
    } else {
        Serial.println("\n=== RESULTADO FINAL DO DUELO ===");
        if (pointsP1 > pointsP2) Serial.println("PLAYER 1 VENCEU O JOGO");
        else if (pointsP2 > pointsP1) Serial.println("PLAYER 2 VENCEU O JOGO");
        else Serial.println("O JOGO TERMINOU EMPATADO!");

        delay(5000);
        backMenu();
    }
}