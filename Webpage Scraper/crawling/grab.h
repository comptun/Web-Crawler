#pragma once

#include <windows.h>
#include <tchar.h>
#include <wininet.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

namespace swc {
	std::string grab(std::string address);
	std::string getWebsiteTitle(std::string address);
}
