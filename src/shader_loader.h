#ifndef SHADER_LOADER_H_
#define SHADER_LOADER_H_

#include "opengl_settings.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "file_loader.h"
#include "status_logger.h"

class ShaderLoader {
	public:
	static GLuint load(std::string location, GLenum shaderType);
	static GLuint load_from_str(std::string src, GLenum shaderType);
};

#endif
