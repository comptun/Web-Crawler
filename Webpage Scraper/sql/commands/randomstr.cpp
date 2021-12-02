#include <iostream>
#include <string>
#include <random>
#include "commands.h"

std::string swc::cmds::randstr(unsigned int length)
{
	std::string str;
	for (size_t i = 0; i < length; ++i)
		str += std::string(1, static_cast<char>(65 + (rand() % 57)));
	return str;
}
