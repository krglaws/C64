
#include "cpu6510.h"


Cpu6510::ImmediateRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t arg = ReadByte(pc);

  instr(arg);
}


Cpu6510::ZeroPageRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t addr = ReadByte(pc);
  uint8_t arg = ReadByte(addr);

  instr(arg);
}


Cpu6510::ZeroPageXRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t addr = ReadByte(pc) + GetX();
  uint8_t arg = ReadByte(addr);

  instr(arg);
}


Cpu6510::ZeroPageYRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t addr = ReadByte(pc) + GetY();
  uint8_t arg = ReadByte(addr);

  instr(arg);
}


Cpu6510::IndirectRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t zpaddr = ReadByte(pc);
  uint16_t addr = ReadWord(zpaddr);
  uint8_t arg = ReadByte(addr);

  instr(arg);
}


Cpu6510::IndirectXRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t zpaddr = ReadByte(pc);
  zpaddr += GetX();

  uint16_t addr = ReadWord(zpaddr);
  uint8_t arg = ReadByte(addr);

  instr(arg);
}


Cpu6510::IndirectYRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 1);

  uint8_t zpaddr = ReadByte(pc);
  uint16_t addr = ReadWord(zpaddr);
  addr += GetY();

  uint8_t arg = ReadByte(addr);

  instr(arg);
}


Cpu6510::AbsoluteRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 2);

  uint16_t addr = ReadWord(pc);
  uint8_t arg = ReadByte(addr);

  instr(arg);
}


Cpu6510::AbsoluteXRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 2);

  uint16_t addr = ReadWord(pc);
  addr += GetX();

  uint8_t arg = ReadByte(addr);

  instr(arg);
}


Cpu6510::AbsoluteYRead(void (instr*)(uint8_t)) {

  uint16_t pc = GetPc();
  SetPc(pc + 2);

  uint16_t addr = ReadWord(pc);
  addr += GetY();

  uint8_t arg = ReadByte(addr);

  instr(arg);
}

