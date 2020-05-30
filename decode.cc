
#include <6510.h>


Cpu6510::Fetch() {

  uint16_t pc = GetPc();
  uint8_t opcode = ReadB(pc);

  SetDb(opcode);
  SetPc(pc + 1);
}


Cpu6510::Decode() {

  uint8_t opcode = GetDb();

  switch (opcode) {

  /* ------------------
   * LOGIC + ARITHMETIC
   */

    /* ORA */
    case 0x09: return Immediate(&Ora);
    case 0x05: return ZeroPage(&Ora);
    case 0x15: return ZeroPageX(&Ora);
    case 0x01: return IndirectX(&Ora);
    case 0x11: return IndirectY(&Ora);
    case 0x0D: return Absolute(&Ora);
    case 0x1D: return AbsoluteX(&Ora);
    case 0x19: return AbsoluteY(&Ora);
 
    /* AND */
    case 0x29: return Immediate(&And);
    case 0x25: return ZeroPage(&And);
    case 0x35: return ZeroPageX(&And);
    case 0x21: return IndirectX(&And);
    case 0x31: return IndirectY(&And);
    case 0x2D: return Absolute(&And);
    case 0x3D: return AbsoluteX(&And);
    case 0x39: return AbsoluteY(&And);

    /* EOR */
    case 0x49: return Immediate(&Eor);
    case 0x45: return ZeroPage(&Eor);
    case 0x55: return ZeroPageX(&Eor);
    case 0x41: return IndirectX(&Eor);
    case 0x51: return IndirectY(&Eor);
    case 0x4D: return Absolute(&Eor);
    case 0x5D: return AbsoluteX(&Eor);
    case 0x59: return AbsoluteY(&Eor);

    /* ADC */
    case 0x69: return Immediate(&Adc);
    case 0x65: return ZeroPage(&Adc);
    case 0x75: return ZeroPageX(&Adc);
    case 0x61: return IndirectX(&Adc);
    case 0x71: return IndirectY(&Adc);
    case 0x6D: return Absolute(&Adc);
    case 0x7D: return AbsoluteX(&Adc);
    case 0x79: return AbsoluteY(&Adc);

    /* SBC */
    case 0xE9: return Immediate(&Sbc);
    case 0xE5: return ZeroPage(&Sbc);
    case 0xF5: return ZeroPageX(&Sbc);
    case 0xE1: return IndirectX(&Sbc);
    case 0xF1: return IndirectY(&Sbc);
    case 0xED: return Absolute(&Sbc);
    case 0xFD: return AbsoluteX(&Sbc);
    case 0xF9: return AbsoluteY(&Sbc);

    /* CMP */
    case 0xC9: return Immediate(&Sbc);
    case 0xC5: return ZeroPage(&Sbc);
    case 0xD5: return ZeroPageX(&Sbc);
    case 0xC1: return IndirectX(&Sbc);
    case 0xD1: return IndirectY(&Sbc);
    case 0xCD: return Absolute(&Sbc);
    case 0xDD: return AbsoluteX(&Sbc);
    case 0xD9: return AbsoluteY(&Sbc);

    /* CPX */
    case 0xE0: return Immediate(&Cpx);
    case 0xE4: return ZeroPage(&Cpx);
    case 0xEC: return Absolute(&Cpx);

    /* CPY */
    case 0xC0: return Immediate(&Cpy);
    case 0xC4: return ZeroPage(&Cpy);
    case 0xCC: return Absolute(&Abs);

    /* DEC */
    case 0xC6: return ZeroPage(&Dec);
    case 0xD6: return ZeroPageX(&Dec);
    case 0xCE: return Absolute(&Dec);
    case 0xDE: return AbsoluteX(&Dec);

    /* DEX */
    case 0xCA: return Implied(&Dex);

    /* DEY */
    case 0x88: return Implied(&Dey);

    /* INC */
    case 0xE6: return ZeroPage(&Inc);
    case 0xF6: return ZeroPageX(&Inc);
    case 0xEE: return Absolute(&Inc);
    case 0xFE: return AbsoluteX(&Inc);

    /* INX */
    case 0xE8: return Implied(&IndirectX);

    /* INY */
    case 0xC8: return Implied(&IndirectY);

    /* ASL */
    case 0x0A: return Implied(&Asl);
    case 0x06: return ZeroPage(&Asl);
    case 0x16: return ZeroPageX(&Asl);
    case 0x0E: return Absolute(&Asl);
    case 0x1E: return AbsoluteY(&Asl);

    /* ROL */
    case 0x2A: return Implied(&Rol);
    case 0x26: return ZeroPage(&Rol);
    case 0x36: return ZeroPageX(&Rol);
    case 0x2E: return Absolute(&Rol);
    case 0x3E: return AbsoluteX(&Rol);

    /* LSR */
    case 0x4A: return Implied(&Lsr);
    case 0x46: return ZeroPage(&Lsr);
    case 0x56: return ZeroPageX(&Lsr);
    case 0x4E: return Absolute(&Lsr);
    case 0x5E: return AbsoluteX(&Lsr);

    /* ROR */
    case 0x6A: return Implied(&Ror);
    case 0x66: return ZeroPage(&Ror);
    case 0x76: return ZeroPageX(&Ror);
    case 0x6E: return Absolute(&Ror);
    case 0x7E: return AbsoluteX(&Ror);

    /* -------------
     * MOVE COMMANDS
     */

    /* LDA */
    case 0xA9: return Immediate(&Lda);
    case 0xA5: return ZeroPage(&Lda);
    case 0xB5: return ZeroPageX(&Lda);
    case 0xA1: return IndirectX(&Lda);
    case 0xB1: return IndirectY(&Lda);
    case 0xAD: return Absolute(&Lda);
    case 0xBD: return AbsoluteX(&Lda);
    case 0xB9: return AbsoluteY(&Lda);

    /* STA */
    case 0x85: return ZeroPage(&Sta);
    case 0x95: return ZeroPageX(&Sta);
    case 0x81: return IndirectX(&Sta);
    case 0x91: return IndirectY(&Sta);
    case 0x8D: return Absolute(&Sta);
    case 0x9D: return AbsoluteX(&Sta);
    case 0x99: return AbsoluteY(&Sta);

    /* LDX */
    case 0xA2: return Immediate(&Ldx);
    case 0xA6: return ZeroPage(&Ldx);
    case 0xB6: return ZeroPageY(&Ldx);
    case 0xAE: return Absolute(&Ldx);
    case 0xBE: return AbsoluteY(&Ldx);

    /* STX */
    case 0x86: return ZeroPage(&Stx);
    case 0x96: return ZeroPageY(&Stx);
    case 0x8E: return Absolute(&Stx);

    /* LDY */
    case 0xA0: return Immediate(&Ldy);
    case 0xA4: return ZeroPage(&Ldy);
    case 0xB4: return ZeroPageX(&Ldy);
    case 0xAC: return Absolute(&Ldy);
    case 0xBC: return AbsoluteX(&Ldy);

    /* STY */
    case 0x84: return ZeroPage(&Sty);
    case 0x94: return ZeroPageX(&Sty);
    case 0x8C: return Absolute(&Sty);

    /* TAX */
    case 0xAA: return Implied(&Tax);

    /* TXA */
    case 0x8A: return Implied(&Txa);

    /* TAY */
    case 0xA8: return Implied(&Tay);

    /* TYA */
    case 0x98: return Implied(&Tya);

    /* TSX */
    case 0xBA: return Implied(&Tsx);

    /* TXS */
    case 0x9A: return Implied(&Txs);

    /* PLA */
    case 0x68: return Implied(&Pla);

    /* PHA */
    case 0x48: return Implied(&Pha);

    /* PLP */
    case 0x28: return Implied(&Plp);

    /* PHP */
    case 0x08: return Implied(&Php);

    /* ------------------
     * JUMP/FLAG COMMANDS
     */

    /* BPL */
    case 0x10: return Relative(&Bpl);

    /* BMI */
    case 0x30: return Relative(&Bpl);

    /* BVC */
    case 0x50: return Relative(&Bvc);

    /* BVS */
    case 0x70: return Relative(&Bvs);

    /* BCC */
    case 0x90: return Relative(&Bcc);

    /* BCS */
    case 0xB0: return Relative(&Bcs);

    /* BNE */
    case 0xD0: return Relative(&Bne);

    /* BEQ */
    case 0xF0: return Relative(&Beq);

    /* BRK */
    case 0x00: return Implied(&Brk);

    /* RTI */
    case 0x40: return Implied(&Rti);

    /* JSR */
    case 0x20: return Absolute(&Jsr);

    /* RTS */
    case 0x60: return Implied(&Rts);

    /* JMP */
    case 0x4C: return Absolute(&Jmp);
    case 0x6C: return Indirect(&Jmp);

    /* BIT */
    case 0x24: return ZeroPage(&Bit);
    case 0x2C: return Absolute(&Bit);

    /* CLC */
    case 0x18: return Implied(&Clc);

    /* SEC */
    case 0x38: return Implied(&Sec);

    /* CLD */
    case 0xD8: return Implied(&Cld);

    /* SED */
    case 0xF8: return Implied(&Sed);

    /* CLI */
    case 0x58: return Implied(&Sed);

    /* SEI */
    case 0x78: return Implied(&Sei);

    /* CLV */
    case 0xB8: return Implied(&Clv);

    /* NOP */
    case 0xEA: return Implied(&Nop);
  }
}

