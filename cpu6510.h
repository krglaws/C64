
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

typedef enum { N=128, V=64, X=32, B=16, D=8, I=2, Z=1, C=0 } Flag;

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

  uint32_t Fetch();

  void Decode();

  int GetFlag(Flag flag);
  void SetFlag(Flag flag);
  void UnsetFlag(Flag flag);

  void ORA(uint32_t instr);

 public:

  Cpu6510();

  start();
};

