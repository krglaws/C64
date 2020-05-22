
#include <6510.h>


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

    /* ASL */
    case 0x0A:   /* imp */
    case 0x06:   /* zp  */
    case 0x16:   /* zpx */
    case 0x0E:   /* abs */
    case 0x1E: { /* aby */
      break;
    }

    /* ROL */
    case 0x2A:   /* imp */
    case 0x26:   /* zp  */
    case 0x36:   /* zpx */
    case 0x2E:   /* abs */
    case 0x3E: { /* abx */
      break;
    }

    /* LSR */
    case 0x4A:   /* imp */
    case 0x46:   /* zp  */
    case 0x56:   /* zpx */
    case 0x4E:   /* abs */
    case 0x5E: { /* abx */
      break;
    }

    /* ROR */
    case 0x6A:   /* imp */
    case 0x66:   /* zp  */
    case 0x76:   /* zpx */
    case 0x6E:   /* abs */
    case 0x7E: { /* abx */
      break;
    }

    /* -------------
     * MOVE COMMANDS
     */

    /* LDA */
    case 0xA9:   /* imm */
    case 0xA5:   /* zp  */
    case 0xB5:   /* zpx */
    case 0xA1:   /* izx */
    case 0xB1:   /* izy */
    case 0xAD:   /* abs */
    case 0xBD:   /* abx */
    case 0xB9: { /* aby */
      break;
    }

    /* STA */
    case 0x85:   /* zp  */
    case 0x95:   /* zpx */
    case 0x81:   /* izx */
    case 0x91:   /* izy */
    case 0x8D:   /* abs */
    case 0x9D:   /* abx */
    case 0x99: { /* aby */
      break;
    }

    /* LDX */
    case 0xA2:   /* imm */
    case 0xA6:   /* zp  */
    case 0xB6:   /* zpy */
    case 0xAE:   /* abs */
    case 0xBE: { /* aby */
      break;
    }

    /* STX */
    case 0x86:   /* 96  */
    case 0x96:   /* zpy */
    case 0x8E: { /* abs */
      break;
    }

    /* LDY */
    case 0xA0:   /* imm */
    case 0xA4:   /* zp  */
    case 0xB4:   /* zpx */
    case 0xAC:   /* abs */
    case 0xBC: { /* abx */
      break;
    }

    /* STY */
    case 0x84:   /* zp  */
    case 0x94:   /* zpx */
    case 0x8C: { /* abs */
      break;
    }

    /* TAX */
    case 0xAA: { /* imp */
      break;
     }

    /* TXA */
    case 0x8A: { /* imp */
      break;
    }

    /* TAY */
    case 0xA8: { /* imp */
      break;
    }

    /* TYA */
    case 0x98: { /* imp */
      break;
    }

    /* TSX */
    case 0xBA: { /* imp */
      break;
    }

    /* TXS */
    case 0x9A: { /* imp */
      break;
    }

    /* PLA */
    case 0x68: { /* imp */
      break;
    }

    /* PHA */
    case 0x48: { /* imp */
      break;
    }

    /* PLP */
    case 0x28: { /* imp */
      break;
    }

    /* PHP */
    case 0x08: { /* imp */
      break;
    }

    /* ------------------
     * JUMP/FLAG COMMANDS
     */

    /* BPL */
    case 0x10: { /* rel */
      break;
    }

    /* BMI */
    case 0x30: { /* rel */
      break;
    }

    /* BVC */
    case 0x50: { /* rel */
      break;
    }

    /* BVS */
    case 0x70: { /* rel */
      break;
    }

    /* BCC */
    case 0x90: { /* rel */
      break;
    }

    /* BCS */
    case 0xB0: { /* rel */
      break;
    }

    /* BNE */
    case 0xD0: { /* rel */
      break;
    }

    /* BEQ */
    case 0xF0: { /* rel */
      break;
    }

    /* BRK */
    case 0x00: { /* imp */
      break;
    }

    /* RTI */
    case 0x40: { /* imp */
      break;
    }

    /* JSR */
    case 0x20: { /* abs */
      break;
    }

    /* RTS */
    case 0x60: { /* imp */
      break;
    }

    /* JMP */
    case 0x4C:   /* abs */
    case 0x6C: { /* ind */
      break;
    }

    /* BIT */
    case 0x24:   /* zp  */
    case 0x2C: { /* abs */
      break;
    }

    /* CLC */
    case 0x18: { /* imp */
      break;
    }

    /* SEC */
    case 0x38: { /* imp */
      break;
    }

    /* CLD */
    case 0xD8: { /* imp */
      break;
    }

    /* SED */
    case 0xF8: { /* imp */
      break;
    }

    /* CLI */
    case 0x58: { /* imp */
      break;
    }

    /* SEI */
    case 0x78: { /* imp */
      break;
    }

    /* CLV */
    case 0xB8: { /* imp */
      break;
    }

    /* NOP */
    case 0xEA: { /* imp */
      break;
    }
  }
