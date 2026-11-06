// --- FUNÇÕES UTILS --- 

// Calcula a diferença absoluta de tempo sem risco de números negativos
unsigned long diffCalculator(unsigned long target, unsigned long gain) {
    if (target > gain) return target - gain;
    else return gain - target;
}
 
// --- LÓGICA DE TEMPOS ---

// Retorna os limtes para o Singleplayer
unsigned long limFinalSingle(int level) { 
    switch(level) {
        case 1: return 7000;
        case 2: return 5000;
        case 3: return 3010;
        case 4: return 1010;
        default: return 7000;
    }
}

bool checkHitSingle(unsigned long time, int level) {
    switch (level) {
    case 1: return time >= 3000 && time <= 7000;
    case 2: return 3000 <= time && time <= 5000;
    case 3: return 3000 <= time && time <= 3010;
    case 4: return 1000 == time ;
    default: return false;
  }
}

// Retorna o tmepo alvo exato para o Multiplayer
unsigned long gainTimeTargetDuo(int level) {
    switch (level) {
        case 1: return 5000;
        case 2: return 4000;
        case 3: return 3000;
        case 4: return 1000;
        default: return 5000;
    }
}

