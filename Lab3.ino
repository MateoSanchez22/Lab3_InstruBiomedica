#include "semg.h"

uint32_t proximo;      // instante programado para la próxima muestra (µs)
uint32_t resto = 0;    // acumula la parte decimal del periodo
uint32_t i = 0;        // índice de la muestra actual

void setup() {
  proximo = micros();
}

void loop() {
  if ((int32_t)(micros() - proximo) >= 0) {
    dacWrite(25, SEMG[i]);
    i++;
    if (i >= N_SEMG) i = 0;

    proximo += 488;
    resto += 576;
    if (resto >= 2048) { resto -= 2048; proximo += 1; }
  }
}
