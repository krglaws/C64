
#include "cpu6510.h"

Cpu6510::Implied(void (*instr)());

Cpu6510::Immediate(void (instr*)()) {

  uint16_t pc = GetPc();
  uint8_t data = ReadB(pc);
  SetPc(pc + 1);

  instr(data);
}

Cpu6510::Absolute(void (instr*)());
Cpu6510::AbsoluteX(void (instr*)());
Cpu6510::AbsoluteY(void (instr*)());
Cpu6510::ZeroPage(void (instr*)());
Cpu6510::ZeroPageX(void (instr*)());
Cpu6510::ZeroPageY(void (instr*)());
Cpu6510::Relative(void (instr*)());
Cpu6510::Indirect(void (instr*)());
Cpu6510::IndirectX(void (instr*)());
Cpu6510::Indirecty(void (instr*)());


