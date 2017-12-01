#include "particle_drawer.h"

ParticleDrawer::ParticleDrawer(){
	glGenBuffers(1, &instanceVBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &colorVBO);
}

ParticleDrawer::~ParticleDrawer(){
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &instanceVBO);
	glDeleteBuffers(1, &colorVBO);
}

bool ParticleDrawer::init(){
	status_waiting("Creating particle drawer", "CREATING");

	auto vertex_shader = ShaderLoader::load("GL_CODE/particle.vs", GL_VERTEX_SHADER);
	if(vertex_shader == 0) {
		status_failure("couldn't load particle vertex shader");
		return false;
	}

	auto fragment_shader = ShaderLoader::load("GL_CODE/particle.fs", GL_FRAGMENT_SHADER);
	if(vertex_shader == 0) {
		status_failure("couldn't load particle fragment shader");
		return false;
	}

	try {
		status_waiting("if segfaults: No open gl context(No window open?)", "SHADER COMPILE");
		this->program = ShaderProgram(vertex_shader, fragment_shader);   
		status_success("successfuly created shader program");

	} catch (std::exception e) {
		status_failure("couldn't create the ShaderProgram");
		return false;
	}

	status_success("Created particle drawer");

	float vertices[] = { 
		-0.5f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.0f,  0.5f, 0.0f,
		-0.5f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.0f, -0.5f, 0.0f
	};

	glBindBuffer(GL_ARRAY_BUFFER, VBO); 
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW); 

	glBindVertexArray(VAO);  

	glBindBuffer(GL_ARRAY_BUFFER, VBO); 	
	glEnableVertexAttribArray(0); 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); 

	glEnableVertexAttribArray(1); 
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO); // this attribute comes from a different vertex buffer 
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); 
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glVertexAttribDivisor(1, 1); // tell OpenGL this is an instanced vertex attribute. 
	
	glEnableVertexAttribArray(2); 
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO); // this attribute comes from a different vertex buffer 
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0); 
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glVertexAttribDivisor(2, 1); // tell OpenGL this is an instanced vertex attribute. 
	
	return true;
}

bool ParticleDrawer::draw(std::vector<float> positions, std::vector<float> color, float size){	
	if(positions.size() % 3) return false;

	//BUFFERS 
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO); 
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*positions.size(), positions.data(), GL_DYNAMIC_DRAW); 
	
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO); 
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*color.size(), color.data(), GL_DYNAMIC_DRAW); 

	program.use(); 

	vertex_size_location = glGetUniformLocation(program.get_id(), "size"); 
	glUniform1f(vertex_size_location, size); 

	glDrawArraysInstanced(GL_TRIANGLES, 0, 6, positions.size()/3); 
	return true;
}
