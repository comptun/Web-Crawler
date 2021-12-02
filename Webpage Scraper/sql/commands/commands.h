#pragma once

#include <string>

namespace swc {
	namespace cmds {
		std::string randstr(unsigned int length);
		void create_table();
		void insert(std::string param1, std::string param2);
		void truncate();
	}
}
