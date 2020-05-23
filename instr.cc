
#include "cpu6510.h"

Cpu6510::GetFlag(Flag flag) { return p_ & flag; }

Cpu6510::SetFlag(Flag flag) { p_ |= flag; }

Cpu6510::UnsetFlag(Flag flag) { p_ ^= flag; }

Cpu6510::ORA(uint8_t opcode) {

  switch (opcode) {

    /* imm */
    case 0x01: {
      uint8_t arg = RAM[pc_ + 1];
      a_ |= arg;

      PC += 2;
      break;
    }

    /* zp */
    case 0x05: {
      uint8_t ptr = RAM[pc_ + 1];
      uint8_t arg = RAM[ptr];

      PC += 2;
      break;
    }

    case 0x09: {
      uint8_t ptr = RAM[px_ + 1];
      uint8_t arg = RAM[ptr + x_];

      P += 2;
      break;
    }

    case 0x0D: {
      
    }
  }

  if (a_ == 0) SetFlag(Z);
  if (a_ <  0) SetFlag(N);
}

