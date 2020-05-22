
/*
Notes:

- addressing modes:
    implied - A
    immediate - BYTE[PC + 1]
    relative - BYTE[PC + SIGNED[PC + 1]]

    zeropage - [BYTE[PC + 1]]
     zeropagex - [BYTE[PC + 1] + X]
     zeropagey - [BYTE[PC + 1] + Y]

    absolute - [WORD[PC + 1]]
     absolutex - [WORD[PC + 1] + X]
     absolutey - [WORD[PC + 1] + Y]

    indirect - [[WORD[PC + 1]]]
     indirectx - [[WORD[PC + 1]] + X]
     indirecty - [[WORD[PC + 1]] + Y]
*/

typedef enum { N, V, X, B, D, I, Z, C } Flag;

class Cpu6510 {

 private:

/* ---------
 * registers
 */
  uint16_t pc_; // program counter
  uint8_t s_; // stack pointer
  uint8_t p_; // processor status
  uint8_t a_; // accumulator
  uint8_t x_; // index register x
  uint8_t y_; // index register y

  Flag IsSet(Flag flag);

  uint32_t Fetch();

  void Decode();

 public:
  Cpu6510();
  start();
};

Cpu6510::IsSet(Flag flag) { return (p_ >> flag) & 1; }

Cpu6510::Decode(uint32_t instr) {

  uint8_t opcode = instr >> 24;

  switch (opcode) {

    /* ------------------
     * LOGIC + ARITHMETIC
     */

    /* ORA */
    case 0x01:   /* imm */
    case 0x05:   /* zp  */
    case 0x09:   /* zpx */
    case 0x0D:   /* izx */
    case 0x11:   /* izy */
    case 0x15:   /* abs */
    case 0x19:   /* abx */
    case 0x1D: { /* aby */
      break;
    }

    /* AND */
    case 0x29:   /* imm */
    case 0x25:   /* zp  */
    case 0x35:   /* zpx */
    case 0x21:   /* izx */
    case 0x31:   /* izy */
    case 0x2D:   /* abs */
    case 0x3D:   /* abx */
    case 0x39: { /* aby */
      break;
    }

    /* EOR */
    case 0x49:   /* imm */
    case 0x45:   /* zp  */
    case 0x55:   /* zpx */
    case 0x41:   /* izx */
    case 0x51:   /* izy */
    case 0x4D:   /* abs */
    case 0x5D:   /* abx */
    case 0x59: { /* aby */
      break;
    }

    /* ADC */
    case 0x69:   /* imm */
    case 0x65:   /* zp  */
    case 0x75:   /* zpx */
    case 0x61:   /* izx */
    case 0x71:   /* izy */
    case 0x6D:   /* abs */
    case 0x7D:   /* abx */
    case 0x79: { /* aby */
      break;
    }

    /* SBC */
    case 0xE9:   /* imm */
    case 0xE5:   /* zp  */
    case 0xF5:   /* zpx */
    case 0xE1:   /* izx */
    case 0xF1:   /* izy */
    case 0xED:   /* abs */
    case 0xFD:   /* abx */
    case 0xF9: { /* aby */
      break;
    }

    /* CMP */
    case 0xC9:   /* imm */
    case 0xC5:   /* zp  */
    case 0xD5:   /* zpx */
    case 0xC1:   /* izx */
    case 0xD1:   /* izy */
    case 0xCD:   /* abs */
    case 0xDD:   /* abx */
    case 0xD9: { /* aby */
      break;
    }

    /* CPX */
    case 0xE0:   /* imm */
    case 0xE4:   /* zp  */
    case 0xEC: { /* abs */
      break;
    }

    /* CPY */
    case 0xC0:   /* imm */
    case 0xC4:   /* zp  */
    case 0xCC: { /* abs */
      break;
    }

    /* DEC */
    case 0xC6:   /* zp  */
    case 0xD6:   /* zpx */
    case 0xCE:   /* abs */
    case 0xDE: { /* abx */
      break;
    }

    /* DEX */
    case 0xCA: { /* CA  */
      break;
    }

    /* DEY */
    case 0x88: { /* imp */
      break;
    }

    /* INC */
    case 0xE6:   /* zp  */
    case 0xF6:   /* zpx */
    case 0xEE:   /* abs */
    case 0xFE: { /* abx */
      break;
    }

    /* INX */
    case 0xE8: { /* imp */
      break;
    }

    /* INY */
    case 0xC8: { /* imp */
      break;
    }

  }
}

