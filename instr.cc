
#include "cpu6510.h"

Cpu6510::GetFlag(Flag flag) { return (p_ >> flag) & 1; }

