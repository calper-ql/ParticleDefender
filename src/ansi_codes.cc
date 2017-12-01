#include "ansi_codes.h"

namespace ansi {
	std::string red(std::string str){
		return ANSI_RED + str + ANSI_DEFAULT;
	}

	std::string green(std::string str){
		return ANSI_GREEN + str + ANSI_DEFAULT;
	}

	std::string yellow(std::string str){
		return ANSI_YELLOW + str + ANSI_DEFAULT;
	}

	std::string blue(std::string str){
		return ANSI_BLUE + str + ANSI_DEFAULT;
	}

	std::string erase_line(){
		return ANSI_ERASE_LINE;
	}
}


