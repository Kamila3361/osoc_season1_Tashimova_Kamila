#ifndef SORTING_
#define SORTING_

#include <iostream>
#include <vector>

class BittyProc
{
public:
	BittyProc();
	uint32_t Evaluate(uint32_t instruction);
	uint32_t GetRegister(uint32_t reg_num);

private:
	std::vector<uint32_t> registers;
};

#endif
