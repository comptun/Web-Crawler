#include <iostream>
#include <vector>

#include "crawling/grab.h"
#include "crawling/tokenize.h"
#include "sql/commands/commands.h"
#include "swc.h"

int main(int argc, char* argv[])
{
	swc::cmds::create_table();
	swc::rootDomain = "en.wikipedia.org";
	std::srand(time(NULL));
	swc::tokenizer(swc::grab("en.wikipedia.org/wiki/Main_Page"));
	std::cout << "DONE";
	std::cin.get();
}