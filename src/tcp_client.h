#ifndef TCP_CLIENT_H_
#define TCP_CLIENT_H_

#include <iostream> 
#include <stdio.h> 
#include <string.h>  
#include <string>  
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netdb.h>
#include <unistd.h>

class TCPClient {
	private:
		int sock;
		std::string address;
		int port;
		struct sockaddr_in server;
		bool alive;

	public:
		TCPClient();
		bool connect(std::string address, int port);
		void close();
		bool send(std::string data);
		std::string receive(size_t size);
		bool isAlive();
};

#endif 
