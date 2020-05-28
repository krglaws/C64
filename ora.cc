
#include "cpu6510.h"

Cpu6510::Ora(uint8_t opcode) {

  unsigned cycles, length;

  switch (opcode) {

    /* imm */
    case 0x09: {

      cycles = 2;
      length = 2;

      uint16_t addr = GetPc() + 1;
      uint8_t arg = Read(addr);
      uint8_t res = GetA();

      res |= arg;
      SetA(res);

      break;
    }

    /* zp */
    case 0x05: {

      cycles = 3;
      length = 2;

      uint16_t addr = GetPc() + 1;
      addr = Read(addr);

      uint8_t arg = Read(addr);
      uint8_t res = GetA();

      res |= arg;
      SetA(res);

      break;
    }

    /* zpx */
    case 0x15: {

      cycles = 4;
      length = 2;

      uint16_t addr = GetPc() + 1;
      addr = Read(addr);

      uint8_t arg = Read(addr);
      uint8_t res = GetA();

      res |= arg;
      SetA(res);

      break;
    }

    /* izx */
    case 0x01: {

      cycles = 6;
      length = 2;

      uint16_t temp = GetPc() + 1;
      temp = Read(temp) + GetX();

      uint16_t addr = Read(temp);
      addr += Read(temp + 1) << 8;

      uint8_t arg = Read(addr);
      uint8_t res = GetA();

      res |= arg;
      SetA(res);

      break;
    }

    /* izy */
    case 0x11: {

      cycles = 5;
      length = 2;

      uint16_t addr = GetPc() + 1;
      uint16_t temp = Read(addr) + GetY();

      if ((temp & 0x00FF) < GetY())
        cycles ++;

      addr = Read(temp);
      addr += Read(temp + 1) << 8;

      uint8_t arg = Read(addr);
      uint8_t res = GetA();

      res |= arg;
      SetA(res);

      break;
    }

    /* abs */
    case 0x0D: {

      cycles = 4;
      length = 3;

      uint16_t temp = GetPc() + 1;
      uint16_t addr = Read(temp);
      addr += Read(temp + 1) << 8;

      uint8_t arg = Read(addr);
      uint8_t res = GetA();

      res |= arg;
      SetA(res);

      break;
    }

    /* abx/aby */
    case 0x1D:
    case 0x19: {

      cycles = 4;
      length = 3;

      uint16_t temp = GetPc() + 1;
      uint16_t addr = Read(temp);
      addr += Read(temp + 1) << 8;

      if (opcode == 0x1D) {
        addr += GetX();
        if ((addr & 0x00FF) < GetX())
          cycles ++;
      }

      else {
        addr += GetY();
        if ((addr & 0x00FF) < GetY())
          cycles ++;
      }

      uint8_t arg = Read(addr);
      uint8_t res = GetA();

      res |= arg;
      SetA(res);

      break;
    }

    default: {
      /* throw an exception or something */
    }
  }

  if (GetA() == 0) SetFlag(Z);
  if (((int8_t) GetA()) <  0) SetFlag(N);

  SetPc(GetPc() + length);

  return cycles;
}

