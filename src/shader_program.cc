#include "shader_program.h"
#include "status_logger.h"

ShaderProgram::ShaderProgram(std::string vertex_loc, std::string fragment_loc){
	GLuint vertex = ShaderLoader::load(vertex_loc, GL_VERTEX_SHADER);
	if(vertex == 0) throw std::exception();
	GLuint fragment = ShaderLoader::load(fragment_loc, GL_FRAGMENT_SHADER);
	if(fragment == 0) throw std::exception();
	
	status_waiting("creating gl program", "LINKING");
	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	
	int success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if(!success){
		status_failure(infoLog);
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		throw std::exception();
	}
	status_success("gl program linked");
}

ShaderProgram::ShaderProgram(GLuint vertex, GLuint fragment){
	if(vertex == 0) throw std::exception();
	if(fragment == 0) throw std::exception();
	
	status_waiting("creating gl program", "LINKING");
	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	
	int success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if(!success){
		status_failure(infoLog);
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		throw std::exception();
	}
	status_success("gl program linked");
}



void ShaderProgram::use(){
	glUseProgram(program);
}

GLuint ShaderProgram::get_id(){
	return program;
}
