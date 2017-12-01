#include "file_loader.h"
#include <fstream>
#include "status_logger.h"

std::string load_file(std::string location) {
	status_waiting("opening file: " + location,"LOADING");
	std::ifstream stream(location.c_str());
	if (!stream.is_open()){
		status_failure("couldn't open file: " + location);
		return "";	
	}
	status_success("opened file: " + location);
	std::string data = std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
	stream.close();
	return data;
}

