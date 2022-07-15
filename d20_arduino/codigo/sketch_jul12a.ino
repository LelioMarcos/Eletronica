#include <LedControl.h> // Está sendo usada uma biblioteca externa para facilitar o uso do display 8x8

typedef unsigned long long int ulli;

#define DIN_PIN 12
#define CS_PIN 11
#define CLK_PIN 10

#define BUTTON_PIN 2
#define PIEZO_PIN 9

const ulli NUMBERS[] = {
  0x0000000000000000,
  0x0010101014181000,
  0x003c041820241800,
  0x001c203c201c0000,
  0x002020203c242400,
  0x003c20203c043c00,
  0x0018243c04043800,
  0x0008081010203c00,
  0x0018243c3c241800,
  0x001820203c241800,
  0x0074545456740000,
  0x0024242436240000,
  0x0034143446340000,
  0x0034443446340000,
  0x0044447456540000,
  0x0034443416740000,
  0x0034547416740000,
  0x0044444456740000,
  0x0074547456740000,
  0x0034447456740000,
  0x0000765254760000
};

const ulli BORDER[] = {
  0xc3810000000081c3,
  0x87808000000101e1,
  0x0e80808001010170,
  0x1c00808181010038,
  0x380001818180001c,
  0x700101018080800e,
  0xe101010000808087
};

const int ANIM_LEN = sizeof(BORDER)/8;

LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);

void setup() {
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 5);

  pinMode(BUTTON_PIN, INPUT_PULLUP); // Com o INPUT_PULLUP, é adicionada uma resistência interna de 20kohms, para não danificar o botão,
  pinMode(PIEZO_PIN, OUTPUT);
  
  randomSeed(analogRead(0)); // Quanto não tem algo conectado no pino analógico 0, será lido um valor aleatório de tensão.
}

// Função para combinar duas imagens.
void displayCombined(ulli image1, ulli image2) {
  for (int i = 0; i < 8; i++) {
    char row1 = (image1 >> i * 8) & 0xFF;
    char row2 = (image2 >> i * 8) & 0xFF;
    char fin = row1 | row2;
    
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(fin, j));
    }
  }
}

void playSound(int freq, int dur) {
    tone(PIEZO_PIN, freq);
    delay(dur);
    noTone(PIEZO_PIN);
}

char rando = 0;
char animation_time = 0;

void loop() {
  displayCombined(NUMBERS[rando], BORDER[0]);
  
  if (digitalRead(BUTTON_PIN) == LOW) {
    rando = random(1, 21); // Escolhe um número entre 1 e 20 para ser o número que sairá.

    // Animação de rodada do dado
    while (animation_time < 50) {
       displayCombined(BORDER[animation_time % ANIM_LEN], NUMBERS[random(1,21)]);
       animation_time++;
       delay(39);

       playSound(659, 10);       
    }

    playSound(1319, 100);
    animation_time = 0;
  }
}
