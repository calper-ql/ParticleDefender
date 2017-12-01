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

	ProtoRequest req;
	req.set_count(31);
	req.set_value(ProtoRequest_REQ_HAS_NEW);
	if(!tcp->send(req.SerializeAsString())){
		tcp->close();
		tcp->connect(ip, port);
		return particles;
	}
	auto recv = tcp->receive(500);
	try {
		ProtoAcknowledge ps;
		ps.ParseFromString(recv);
		auto value = ps.state();
		if(value == ProtoAcknowledge_ACK_NEGATIVE){
			return particles;
		}
	} catch (std::exception e) {
		return particles;
	}


	req.set_value(ProtoRequest_REQ_SIZE);
	if(!tcp->send(req.SerializeAsString())){
		tcp->close();
		tcp->connect(ip, port);
		return particles;
	}
	recv = tcp->receive(500);
	uint64_t size;
	try {
		ProtoSize ps;
		ps.ParseFromString(recv);
		size = ps.value();
		if(size == 0){
			return particles;
		}
	} catch (std::exception e) {
		return particles;
	}

	req.set_value(ProtoRequest_REQ_SET);
	if(!tcp->send(req.SerializeAsString())){
		tcp->close();
		tcp->connect(ip, port);
		return particles;
	}
	recv = tcp->receive(size+1);
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
