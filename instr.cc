
#include "cpu6510.h"

Cpu6510::GetFlag(Flag flag) { return p_ & flag; }

Cpu6510::SetFlag(Flag flag) { p_ |= flag; }

Cpu6510::UnsetFlag(Flag flag) { p_ ^= flag; }

Cpu6510::ORA(uint8_t opcode) {

  int cycles;

  switch (opcode) {

    /* imm */
    case 0x09: {
      uint8_t arg = RAM[pc_ + 1];
      a_ |= arg;

      cycles = 2;
      PC += 2;
      break;
    }

    /* zp */
    case 0x05: {
      uint8_t ptr = RAM[pc_ + 1];
      uint8_t arg = RAM[ptr];
      a_ |= arg;

      cycles = 3;
      PC += 2;
      break;
    }

    /* zpx */
    case 0x15: {
      uint8_t ptr = RAM[pc_ + 1];
      uint8_t arg = RAM[ptr + x_];
      a_ |= arg;

      cycles = 4;
      PC += 2;
      break;
    }

    /* izx */
    case 0x01: {
      
    }

    /* izy */
    case 0x11: {

    }

    /* abs */
    case 0x0D: {
      
    }

    /* abx */
    case 0x1D: {

    }

    /* aby */
    case 0x19: {

    }
  }

  if (a_ == 0) SetFlag(Z);
  if (a_ <  0) SetFlag(N);
}

