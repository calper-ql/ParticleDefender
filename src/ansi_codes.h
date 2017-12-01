#ifndef ANSI_CODES_H
#define ANSI_CODES_H

#include <string>

#define ANSI_DEFAULT "\033[0m"
#define ANSI_RED "\033[1;31m"
#define ANSI_GREEN "\033[1;32m"
#define ANSI_YELLOW "\033[1;33m"
#define ANSI_BLUE "\033[1;34m"
#define ANSI_ERASE_LINE "\r\033[K"

namespace ansi {
	std::string red(std::string str);
	std::string green(std::string str);
	std::string yellow(std::string str);
	std::string blue(std::string str);
	std::string erase_line();
}


#endif
