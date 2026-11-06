// -- PINOS --

const int BTN_P1 = 2;
const int BTN_P2 = 3;
const int LEDR = 9;
const int LEDG = 8;

// -- CONSTANTES DO JOGO ---

const int TOTAL_LEVELS = 4;

// Estados possíveis para o jogo (facilita a leitura em vez de usar 0, 1, 2)
enum gameState {
    MENU,
    SINGLEPLAYER,
    MULTIPLAYER
};

// -- VARIÁVEIS GLOBAIS --
gameState currentState = MENU;
int currentLevel = 1;
unsigned long startTime = 0;

// Variãveis Singleplayer
int pointsP1 = 0; // Usado em ambos

// Varíáveis Multiplayer
int pointsP2 = 0;
bool p1AlreadyPlay = false, p2AlreadyPlay = false;
unsigned long timePressP1 = 0, timePressP2 = 0;

// Estado anterior dos botões (para detectar apenas o clique, não se está segurando)
 bool p1PreviousState = false, p2PreviousState = false;

 void setup() {
    Serial.begin(9600);

    pinMode(LEDG, OUTPUT);
    pinMode(LEDR, OUTPUT);
    pinMode(BTN_P1, INPUT_PULLUP);
    pinMode(BTN_P2, INPUT_PULLUP);

    showMenu();
 }

 void loop() {
    bool p1Press = (digitalRead(BTN_P1) == LOW);
    bool p2Press = (digitalRead(BTN_P2) == LOW);

    // Detecta se houve um mudança de estado (botão acabou de ser apertado)

    bool clickP1 = p1Press && !p1PreviousState;
    bool clickP2 = p2Press && !p2PreviousState;

    // Atualiza o histoórico

    p1PreviousState = p1Press;
    p2PreviousState = p2Press;

    // --- ESTADO ---

    if(currentState == MENU) {
        if (clickP1 && clickP2) {
            Serial.println("Escolha um modo de jogo.");
        } else if (clickP1) {
            currentState = SINGLEPLAYER;
            Serial.println("\nModo SINGLEPLAYER selecionado!");
            startRound();
        } else if (clickP2) {
            currentState = MULTIPLAYER;
            Serial.println("\nModo MULTIPLAYER selecionado!");
            startRound();
        }
    }

    else if (currentState == SINGLEPLAYER) {
        unsigned long timePass = millis() - startTime;

        if (clickP1) {
            rateSinglePlayer(timePass, 
            checkHitSingle(timePass, currentLevel));
        } else if ( timePass > limFinalSingle(currentLevel)) {
            Serial.println("Tempo esgotado!");
            checkHitSingle(timePass, false);
            delay(2000);
            backMenu();
        }
    }

    else if (currentState == MULTIPLAYER) {
        unsigned long currentTime = millis();
        unsigned long timePass = currentTime - startTime;

        // Registra o tempo do p1 se ele apertar e ainda não tiver jogado
        if (clickP1 && !p1AlreadyPlay) {
            timePressP1 = timePass;
            p1AlreadyPlay = true;
            Serial.println("P1 apertou!");
        }
        // Registra o tempo do p2 se ele apertar e ainda não tiver jogado
        if (clickP2 && !p2AlreadyPlay) {
            timePressP2 = timePass;
            p2AlreadyPlay = true;
            Serial.println("P2 apertou!");
        }

        // Se ambos já apertaram, finaliza a rodada e compara
        if (p1AlreadyPlay && p2AlreadyPlay) {
            rateMultiplayer();
        }

        unsigned long target = gainTimeTargetDuo(currentLevel);
        if (timePass > target + 10000 && (!p1AlreadyPlay || !p2AlreadyPlay)) {
            Serial.println("Alguem dormiu no ponto! Rodada Cancelada.");
            delay(2000);
            backMenu();
        }
    }

 }