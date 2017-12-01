#include "status_logger.h"
#include "ansi_codes.h"

void status_failure(std::string msg){
	std::string out;
	out += ANSI_ERASE_LINE;
	out += ANSI_DEFAULT;
	out += "[" + ansi::red("FAILURE") + "] - " + msg + "\n";
	std::cout << out;
}

void status_success(std::string msg){
	std::string out;
	out += ANSI_ERASE_LINE;
	out += ANSI_DEFAULT;
	out += "[" + ansi::green("SUCCESS") + "] - " + msg + "\n";
	std::cout << out;
}

void status_waiting(std::string msg, std::string waiting_msg){
	std::string out;
	out += ANSI_ERASE_LINE;
	out += ANSI_DEFAULT;
	out += "[" + ansi::blue(waiting_msg) + "] - " + msg;
	std::cout << out;
}

