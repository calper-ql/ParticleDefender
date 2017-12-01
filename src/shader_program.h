#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <string>
#include "shader_loader.h"

class ShaderProgram {
	private:
		GLuint program;
	public:
		ShaderProgram();
		ShaderProgram(std::string vertex_loc, std::string fragment_loc);
		ShaderProgram(GLuint vertex, GLuint fragment);
		void use();
		GLuint get_id();
};

#endif 
