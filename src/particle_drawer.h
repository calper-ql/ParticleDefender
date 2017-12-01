#ifndef PARTICLE_DRAWER_H_
#define PARTICLE_DRAWER_H_

#include "opengl_settings.h"
#include "shader_program.h"
#include <vector>

class ParticleDrawer {
	private:
		unsigned int VBO, VAO, instanceVBO;
		ShaderProgram program;

	public:
		ParticleDrawer();
		~ParticleDrawer();
		
		bool init();
		bool draw(std::vector<float> positions, float size);
};

#endif 
