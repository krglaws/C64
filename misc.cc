
#include "cpu6510.h"


Cpu6510::GetDb() {
  return db_;
}


Cpu6510::SetDb(uint8_t data) {
  db_ = data;
}


Cpu6510::GetAb() {
  return ab_;
}


Cpu6510::SetAb(uint16_t addr) {
  ab_ = addr;
}


Cpu6510::Write(uint16_t addr, uint8_t byte) {

  mem_[addr] = byte;
}


Cpu6510::Read() {

  uint16_t addr = GetAb();
  uint8_t data = mem_[addr];

  SetDb(data);
}


Cpu6510::GetFlag(Flag flag) {
  return p_ & flag;
}


Cpu6510::SetFlag(Flag flag) {
  p_ |= flag;
}


Cpu6510::UnsetFlag(Flag flag) {
  p_ ^= flag;
}

