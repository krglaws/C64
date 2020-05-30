
#include "cpu6510.h"

Cpu6510::And(AddrMode mode) {

  unsigned cycles, length;
  uint16_t pc = GetPc();
  uint8_t arg;

  switch (mode) {

    case IMM: {

      cycles = 2;
      length = 2;
      uint16_t addr = pc + 1;
      arg = ReadB(addr);

      break;
    }

    case ZP: {

      cycles = 3;
      length = 2;
      uint16_t addr = pc + 1;
      addr = ReadB(addr);
      arg = ReadB(addr);

      break;
    }

    case ZPX: {

      cycles = 4;
      length = 2;
      uint16_t addr = pc + 1;
      addr = ReadB(addr) + GetX();
      arg = ReadB(addr);

      break;
    }

    case INX: {

      cycles = 6;
      length = 2;
      uint16_t addr = pc + 1;
      
    }

    case INY: {
    }

    case ABS: {
    }

    case ABX: {
    }

    case ABY: {
    }

    default: {
      /* throw exception ?*/
    }
  }

  uint8_t result = GetA() & arg;

  if (result == 0) SetFlag(Z);
  if (0x80 & result) SetFlag(N);

  SetA(result);
  SetPc(pc + length);

  return cycles;
}

