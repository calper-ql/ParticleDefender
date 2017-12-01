#ifndef PARTICLE_REQUEST_H_
#define PARTICLE_REQUEST_H_

#include "status_logger.h"
#include "tcp_client.h"
#include <vector>
#include "particles.pb.h"

class ParticleRequest {
	private:
		std::string ip;
		int port;
		TCPClient *tcp;
	public:
		ParticleRequest(std::string ip, int port);
		~ParticleRequest();
		std::vector<ProtoParticle> get_new_particles();

};

#endif 
