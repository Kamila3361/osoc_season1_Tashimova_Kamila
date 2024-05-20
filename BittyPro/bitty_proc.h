#ifndef BITTY_PROC_H_
#define BITTY_PROC_H_

#include <iostream>
#include <vector>

class BittyProc
{
public:
	BittyProc();
	uint16_t Evaluate(uint16_t instruction);
	uint16_t GetRegister(int reg_num);

private:
	std::vector<uint16_t> registers_;
};

#endif
