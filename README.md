```markdown
# ⏱️ Jogo de Tempo de Reação com Arduino

Este é um projeto interativo desenvolvido com Arduino Uno que testa os seus reflexos e a sua percepção de tempo. O jogo possui dois modos: um desafio solo (Singleplayer) com níveis de dificuldade progressiva, e um modo de duelo (Multiplayer) onde dois jogadores competem para ver quem tem a melhor precisão!

Toda a interface do jogo (menus, placar e contagem regressiva) acontece pelo **Serial Monitor** da IDE do Arduino.

## 🎮 Modos de Jogo

### 1️⃣ Singleplayer (Modo Solo)
O jogo diz um intervalo de tempo, inicia uma contagem regressiva e diz "VALENDO". Você deve esperar o tempo passar mentalmente e apertar o botão exatamente dentro da janela de tempo exigida.
* **Nível 1:** Acertar entre 3 e 7 segundos.
* **Nível 2:** Acertar entre 3 e 5 segundos.
* **Nível 3:** Acertar entre 2,5 e 3 segundos.
* **Nível 4:** Acertar cravado em 1 segundo (margem de 10 milissegundos).
* *Feedback:* Se acertar, o LED Verde acende e você avança. Se errar, o LED Vermelho acende e o jogo acaba.

### 2️⃣ Multiplayer (Modo Duo)
Dois jogadores competem! O jogo informa um **Tempo Alvo** (ex: 5 segundos). Após o "VALENDO", ambos os jogadores devem tentar apertar os seus respectivos botões o mais próximo possível desse tempo.
* Quem chegar mais perto do tempo (tiver o menor erro) marca 1 ponto.
* Os tempos alvo diminuem a cada rodada, tornando o jogo mais difícil.
* O sistema aguarda os dois jogadores apertarem para calcular o resultado.

---

## 🛠️ Componentes Necessários

Para montar este projeto, você vai precisar de:
* 1x Placa Arduino (Uno, Mega, Nano, etc.)
* 2x Botões (Push buttons)
* 1x LED Vermelho
* 1x LED Verde
* 2x Resistores para os LEDs (ex: 220Ω ou 330Ω)
* Protoboard e cabos Jumper

*(Nota: O projeto utiliza os resistores de pull-up internos do próprio Arduino para os botões, dispensando o uso de resistores externos para eles).*

---

## 🔌 Esquema de Ligação (Hardware)

Conecte os componentes no Arduino seguindo a tabela abaixo:

| Componente | Pino no Arduino | Observação |
| :--- | :---: | :--- |
| **Botão P1** (Player 1) | Pino Digital `2` | Ligar o outro pino do botão ao GND |
| **Botão P2** (Player 2) | Pino Digital `3` | Ligar o outro pino do botão ao GND |
| **LED Verde** | Pino Digital `7` | Ligar em série com resistor ao GND |
| **LED Vermelho** | Pino Digital `8` | Ligar em série com resistor ao GND |

---

## 🚀 Como Rodar o Projeto

1. Faça a montagem do circuito conforme a tabela acima.
2. Conecte o Arduino ao computador via cabo USB.
3. Abra a IDE do Arduino e cole o código do projeto.
4. Faça o **Upload** do código para a placa.
5. Abra o **Serial Monitor** (Monitor Serial) clicando no ícone da lupa no canto superior direito.
6. **MUITO IMPORTANTE:** Configure o *Baud Rate* do Serial Monitor para **9600 baud**.
7. O menu principal aparecerá na tela.
   * Aperte o botão do **Player 1** para iniciar o Singleplayer.
   * Aperte o botão do **Player 2** para iniciar o Multiplayer.

---

## 🧠 Lógica Principal do Código

O código foi estruturado utilizando uma **Máquina de Estados** (Menu, Singleplayer, Multiplayer), o que impede que regras de um modo interfiram no outro. A função `millis()` é utilizada para medir o tempo decorrido de forma extremamente precisa sem travar o processamento do Arduino (ao contrário da função `delay()`).

Para o cálculo de quem vence no Multiplayer, o código avalia a diferença absoluta entre o tempo em que o jogador apertou e o "Tempo Alvo". Quem tiver a menor diferença, ganha o ponto.

---

Em Desenvolvimento, Adicionar cronometro para usuarios externos assistirem o tempo, impementar a tela de LCD.


*Desenvolvido para fins de estudo de eletrônica, programação em C++ e lógica condicional.*

```
