#include "particle_request.h"

ParticleRequest::ParticleRequest(std::string ip, int port){
	tcp = new TCPClient();
	this->ip = ip;
	this->port = port;
	tcp->connect(ip, port);
}

ParticleRequest::~ParticleRequest(){
	delete tcp;
}

std::vector<ProtoParticle> ParticleRequest::get_new_particles(){
	std::vector<ProtoParticle> particles;

	ProtoAcknowledge ack;
	ack.set_state(ProtoAcknowledge_ACK_CONTINUE);

	if(!tcp->send(ack.SerializeAsString())){
		tcp->close();
		tcp->connect(ip, port);
		return particles;
	}

	auto recv = tcp->receive(500);
	uint64_t size;
	try {
		ProtoSize ps;
		ps.ParseFromString(recv);
		size = ps.value();
	} catch (std::exception e) {
		return particles;
	}


	if(!tcp->send(ack.SerializeAsString())){
		tcp->close();
		tcp->connect(ip, port);
		return particles;
	}

	recv = tcp->receive(size);
	try {
		ProtoParticleSet pps;
		pps.ParseFromString(recv);
		for(int i = 0; i < pps.particles_size(); i++){
			particles.push_back(pps.particles(i));
		}
	} catch (std::exception e) {
		return particles;
	}

	return particles;
}
