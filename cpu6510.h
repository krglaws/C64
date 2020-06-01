
#ifndef CPU6510_H_
#define CPU6510_H_

typedef enum { N=128, V=64, X=32, B=16, D=8, I=4, Z=2, C=1 } Flag;

class Cpu6510 {

 public:

  Cpu6510();
  ~Cpu6510();

 private:

  int Decode(uint8_t opcode);

/* -----------
 * main memory
 */
  uint8_t *mem_;
  void Write();
  void Read();

/* ----------
 * buses
 */
  uint8_t db_; /* data bus */
  uint8_t GetDb();
  void SetDb(uint8_t d);

  uint16_t ab_; /* address bus */
  uint16_t GetAb();
  void SetAb(uint8_t d);

/* ---------
 * registers
 */
  uint16_t pc_; // program counter
  uint16_t GetPc();
  uint16_t SetPc(uint16_t addr);

  uint8_t s_; // stack pointer
  uint8_t GetS();
  void SetS(uint8_t n);

  uint8_t p_; // processor status
  int GetFlag(Flag flag);
  void SetFlag(Flag flag);
  void UnsetFlag(Flag flag);

  uint8_t a_; // accumulator
  uint8_t GetA();
  void SetA(uint8_t n);

  uint8_t x_; // index register x
  uint8_t GetX();
  void SetX(uint8_t n);

  uint8_t y_; // index register y
  uint8_t GetY();
  void SetY(uint8_t n);

/* ----------------
 * addressing modes
 */
  int Implied(void (instr*)());
  int Immediate(void (instr*)());
  int Absolute(void (instr*)());
  int AbsoluteX(void (instr*)());
  int AbsoluteY(void (instr*)());
  int ZeroPage(void (instr*)());
  int ZeroPageX(void (instr*)());
  int ZeroPageY(void (instr*)());
  int Relative(void (instr*)());
  int Indirect(void (instr*)());
  int IndirectX(void (instr*)());
  int Indirecty(void (instr*)());

/* ------------
 * instructions
 */
  void Adc();
  void And();
  void Asl();
  void Bcc();
  void Bcs();
  void Beq();
  void Bit();
  void Bmi();
  void Bne();
  void Bpl();
  void Brk();
  void Bvc();
  void Bvs();
  void Clc();
  void Cld();
  void Cli();
  void Clv();
  void Cmp();
  void Cpx();
  void Cpy();
  void Dec();
  void Dex();
  void Dey();
  void Eor();
  void Inc();
  void Inx();
  void Iny();
  void Jmp();
  void Jsr();
  void Lda();
  void Ldx();
  void Ldy();
  void Lsr();
  void Nop();
  void Ora(uint8_t arg);
  void Pha();
  void Php();
  void Pla();
  void Plp();
  void Rol();
  void Ror();
  void Rti();
  void Rts();
  void Sbc();
  void Sec();
  void Sed();
  void Sei();
  void Sta();
  void Stx();
  void Sty();
  void Tax();
  void Tay();
  void Tsx();
  void Txa();
  void Txs();
  void Tya();
};

#endif

