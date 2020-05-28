
/*
Notes:

- addressing modes:

    implied -

    zeropage - [BYTE[PC + 1]]
     zeropagex - [BYTE[PC + 1] + X]
     zeropagey - [BYTE[PC + 1] + Y]

    absolute - [WORD[PC + 1]]
     absolutex - [WORD[PC + 1] + X]
     absolutey - [WORD[PC + 1] + Y]

    immediate - [PC + 1]
    relative - [PC + SIGNED[PC + 1]]

    indirectx -   [WORD[BYTE[PC + 1] + X]]
    indirecty - [[WORD[PC + 1]] + Y]
*/

typedef enum { N=128, V=64, X=32, B=16, D=8, I=4, Z=2, C=1 } Flag;

class Cpu6510 {

 private:

/* -----------
 * main memory
 */
  uint8_t *mem_;

/* ---------
 * registers
 */
  uint16_t pc_; // program counter
  uint16_t GetPc();
  uint16_t SetPc(unsigned num);

  uint8_t s_; // stack pointer

  uint8_t p_; // processor status

  uint8_t a_; // accumulator
  uint8_t GetA();
  void SetA(uint8_t num);

  uint8_t x_; // index register x

  uint8_t y_; // index register y

/* ------------
 * misc methods
 */
  void Write(uint16_t addr, uint8_t byte);

  uint8_t ReadB(uint16_t addr);
  uint16_t ReadW(uint16_t addr);

  uint8_t Fetch();

  int Decode();

  int GetFlag(Flag flag);

  void SetFlag(Flag flag);

  void UnsetFlag(Flag flag);

/* ------------
 * instructions
 */
  int Nop(uint8_t opcode);
  int Ora(uint8_t opcode);


 public:

  Cpu6510();

  start();
};

