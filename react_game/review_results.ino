// --- AVALIAÇÃO DE RESULTADOS ---

void rateSinglePlayer(int time, bool hit){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tempo do P1: ");
    lcd.setCursor(8, 1);
    lcd.print(time/ 1000.0, 3);
    lcd.print(" s")
    delay(2000);
    /*Serial.print("Tempo do P1: ");
    Serial.print(time/ 1000.0, 3);
    Serial.println(" s");*/

    if (hit) {
        digitalWrite(LEDG, HIGH);
        lcd.clear(); lcd.setCursor(0 ,0); lcd.print("ACERTOU!!");
        //Serial.println("ACERTOU!");
        delay(2000);
        currentLevel++;

        if (currentLevel > TOTAL_LEVELS) {
            digitalWrite(LEDR, HIGH);
            digitalWrite(LEDG, HIGH);
            lcd.clear(); 
            lcd.setCursor(0 ,0); lcd.print("PARABENS");
            lcd.setCursor(0, 1); lcd.print("Venceu TUDO!!");
            //Serial.println("\nPARABENS! Voce venceu todos os niveis!");
            delay(4000);
            backMenu();
        } else {
            startRound();
        }
    } else {
        digitalWrite(LEDR, HIGH);
        lcd.clear();
        lcd.setCursor(4, 0); lcd.print("Melhore");
        lcd.setCursor(2, 1); lcd.print("VOCE PERDEU");
        //Serial.println("VOCE PERDEU! Fim de jogo.");
        delay(3000);
        backMenu();
    }
}

void rateMultiplayer() {
    int target = gainTimeTargetDuo(currentLevel);
    int missP1 = diffCalculator(target, timePressP1);
    int missP2 = diffCalculator(target, timePressP2);

    /*Serial.println("\n--- RESULTADO DA RODADA ---");
    Serial.print("Alvo: ");
    Serial.print(target/ 1000.0, 3);
    Serial.println(" s");*/
    lcd.clear(); 
    lcd.setCursor(0, 0); lcd.print("RODADA");
    lcd.setCursor(0, 1); lcd.print("Alvo: "); lcd.print(target/ 1000.0, 3); lcd.print(" s");
    delay(2000);

    lcd.clear(); 
    lcd.setCursor(0, 0); lcd.print("P1: "); lcd.print(timePressP1 / 1000.0, 3); lcd.print(" s");
    lcd.setCursor(0, 1); lcd.print("(Margem"); lcd.print(missP1/ 1000.0, 3); lcd.print(" s)");
    delay(2000);
   /* Serial.print("P1: ");
    Serial.print(timePressP1/ 1000.0, 3);
    Serial.print(" s(Margem: ");
    Serial.print(missP1/ 1000.0, 3);
    Serial.println(" s");*/

    lcd.clear(); 
    lcd.setCursor(0, 0); lcd.print("P2: "); lcd.print(timePressP2 / 1000.0, 3); lcd.print(" s");
    lcd.setCursor(0, 1); lcd.print("(Margem"); lcd.print(missP2/ 1000.0, 3); lcd.print(" s)");
    delay(2000);
    /*Serial.print("P2: ");
    Serial.print(timePressP2/ 1000.0, 3);
    Serial.print(" s(Margem: ");
    Serial.print(missP2/ 1000.0, 3);
    Serial.println(" s");*/

    if (missP1 < missP2) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("P1 mais preciso!");
        lcd.setCursor(0,1);
        lcd.print("Ponto para P1");
        //Serial.println(">>> P1 foi mais preciso! Ponto para P1.");
        pointsP1++;
        delay(2000);
        digitalWrite(LEDG, HIGH);
    } else if (missP2 < missP1) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("P2 mais preciso!");
        lcd.setCursor(0,1);
        lcd.print("Ponto para P2");
        delay(2000);
        //Serial.println(">>> P2 foi mais preciso! Ponto para P2.");
        pointsP2++;
        digitalWrite(LEDR, HIGH);
    } else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(">>> EMPATE!");
        lcd.setCursor(0,1);
        lcd.print("Ninguem PONTUA!");
        //Serial.println(">>> EMPATE! Ninguem pontua.");
        digitalWrite(LEDG, HIGH);
        digitalWrite(LEDR, HIGH);
    }

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PLACAR GERAL");
    lcd.setCursor(0,1);
    lcd.print("P1->");
    lcd.print(pointsP1);
    lcd.setCursor(6, 1);
    lcd.print("P2->");
    lcd.print(pointsP2);
    /*Serial.print("PLACAR GERAL -> P1: ");
    Serial.print(pointsP1);
    Serial.print(" | P2: ");
    Serial.println(pointsP2);*/

    delay(4000);
    currentLevel++;

    //Verificar se o jogo acabou
    if (currentLevel <= TOTAL_LEVELS) {
        startRound();
    } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("RESULTADO FINAL");
        delay(2000);
        //Serial.println("\n=== RESULTADO FINAL DO DUELO ===");
        if (pointsP1 > pointsP2) {
            lcd.clear();
            lcd.setCursor(5 , 0);
            lcd.print("PLAYER 1");
            lcd.setCursor(4, 1);
            lcd.print("VENCEU O JOGO");

        } //Serial.println("PLAYER 1 VENCEU O JOGO");
        else if (pointsP2 > pointsP1) {
            lcd.clear();
            lcd.setCursor(5 , 0);
            lcd.print("PLAYER 2");
            lcd.setCursor(4, 1);
            lcd.print("VENCEU O JOGO");
        }//Serial.println("PLAYER 2 VENCEU O JOGO");
        else {
            lcd.clear();
            lcd.setCursor(1, 0);
            lcd.print("O JOGO TERMINOU");
            lcd.setCursor(5, 1);
            lcd.print("EMPATADO");
        }//Serial.println("O JOGO TERMINOU EMPATADO!");

        delay(5000);
        backMenu();
    }
}