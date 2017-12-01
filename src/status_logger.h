#ifndef STATUS_LOGGER_H
#define STATUS_LOGGER_H

#include <iostream>

void status_failure(std::string msg);
void status_success(std::string msg);
void status_waiting(std::string msg, std::string waiting_msg);

#endif
