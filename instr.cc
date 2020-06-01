
#include "cpu6510.h"

Cpu6510::Ora(uint8_t arg) {

  SetA(GetA() | arg);
}

Cpu6510::And(uint8_t arg) {

  Set(GetA() & arg);
}

Cpu6510::Eor(uint8_t arg) {

  Set(GetA() ^ arg);
}

Cpu6510::Adc(uint8_t arg) {

  if (GetFlag(D)) {
    
  }

  else {
    uint16_t a = GetA();
    a += arg;

    if (a & 0xFF00) SetFlag(C);
    SetA(a);
  }
}

