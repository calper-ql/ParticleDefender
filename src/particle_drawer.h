#ifndef PARTICLE_DRAWER_H_
#define PARTICLE_DRAWER_H_

#include "opengl_settings.h"
#include "shader_program.h"
#include <vector>

class ParticleDrawer {
	private:
		GLuint VBO, colorVBO, VAO, instanceVBO;
		ShaderProgram program;
		GLuint vertex_size_location, vertex_color_location;

	public:
		ParticleDrawer();
		~ParticleDrawer();
		
		bool init();
		bool draw(std::vector<float> positions, std::vector<float> color, float size);
};

#endif 
