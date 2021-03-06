#include "tcp_client.h"
#include "status_logger.h"
#include <signal.h>

TCPClient::TCPClient(){
	sock = -1;
	port = 0;
	address = "";
	alive = false;
}

bool TCPClient::connect(std::string address , int port) {
	usleep(100000);
	signal (SIGPIPE, SIG_IGN);
	alive = false;
	status_waiting(address + ":" + std::to_string(port), "CONNECTING");
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1) {
		status_failure("Socket create error");
		return false;
	}

	struct timeval tv;
	tv.tv_sec = 5;  
	tv.tv_usec = 0;
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv,sizeof(struct timeval));

	struct in_addr addr;
	if(!inet_aton(address.c_str(), &addr)){
		status_failure("address interpret error: " + address);
	}

	server.sin_addr = addr;
	server.sin_family = AF_INET;
	server.sin_port = htons( port );

	if (::connect(sock, (struct sockaddr *)&server, sizeof(sockaddr))){
		status_failure("connect error: " + address + ":" + std::to_string(port));
		return false;
	}

	status_success("connected to: " + address + ":" + std::to_string(port));
	alive = true;
	return true;
}

bool TCPClient::send(std::string data){
	ssize_t n = -1;
	if(alive) n = write(sock, data.c_str(), data.length());
	if(n < 0) {
		alive = false;
		return false;
	}
	return true;
}

std::string TCPClient::receive(size_t size){
	ssize_t n = -1;
	char read_buf[size];
	if(alive) n = read(sock, read_buf, size);
	if(n < 0){
		alive = false;
		return "";
	}	
	return std::string(read_buf, n);
}

void TCPClient::close(){
	::close(sock);
}

bool TCPClient::isAlive(){
	return alive;
}
