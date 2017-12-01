#include "shader_loader.h"

GLuint ShaderLoader::load(std::string location, GLenum shaderType){
	std::string str = load_file(location);
	return load_from_str(str, shaderType);
}

GLuint ShaderLoader::load_from_str(std::string src, GLenum shaderType){
	if(src.length() == 0){
		status_failure("empty shader source");
		return 0;
	}
	const char* str = src.c_str();
	GLuint shader_id = glCreateShader(shaderType);
	status_waiting("shader", "COMPILING" );
	glShaderSource(shader_id, 1, &str, NULL);
	glCompileShader(shader_id);
	int success;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
	if(!success){
		char infoLog[512];
		glGetShaderInfoLog(shader_id, 512, NULL, infoLog);
		status_failure(infoLog);
		glDeleteShader(shader_id);
		shader_id = 0;
	} else {
		status_success("Compiled shader");
	}
	return shader_id;
}

