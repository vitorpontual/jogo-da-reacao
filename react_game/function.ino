// --- FUNÇÕES UTILS --- 

// Calcula a diferença absoluta de tempo sem risco de números negativos
int diffCalculator(int target, int gain) {
    if (target > gain) return target - gain;
    else return gain - target;
}
 
// --- LÓGICA DE TEMPOS ---

// Retorna os limtes para o Singleplayer
int limFinalSingle(int level) { 
    switch(level) {
        case 1: return 8000;
        case 2: return 6000;
        case 3: return 4000;
        case 4: return 4000;
        default: return 10000;
    }
}

bool checkHitSingle(int time, int level) {
    switch (level) {
    case 1: return time >= 3000 && time <= 7000;
    case 2: return 3000 <= time && time <= 5000;
    case 3: return 2500 <= time && time <= 3000;
    case 4: return 1000 == time ;
    default: return false;
  }
}

// Retorna o tmepo alvo exato para o Multiplayer
int gainTimeTargetDuo(int level) {
    switch (level) {
        case 1: return 5000;
        case 2: return 4000;
        case 3: return 3000;
        case 4: return 1000;
        default: return 10000;
    } 
}

