#include <iostream>
#include <fstream>

#include "particle_drawer.h"
#include "particle_request.h"

using namespace std;

float random_float(float min, float max);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(int argc, char* argv[]){
	if(argc < 2) { 
		status_failure("Please enter IP...");
		return 1;
	}

	cout << "--START--" << endl;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// glfw window creation
	// --------------------
	//glfwWindowHint(GLFW_VISIBLE, false);
	GLFWwindow* window = glfwCreateWindow(500, 500, "ParticleDefender", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return 3;
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, framebuffer_size_callback);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	ParticleDrawer pd;
	if(!pd.init()) return 1;

	ParticleRequest pr(argv[1], 32323);

	vector<float> pos;
	vector<float> vel;
	vector<float> color;

	for(int i = 0; i < 1000000; i++){
		pos.push_back(0);
		pos.push_back(0);
		pos.push_back(0);
		vel.push_back(0);
		vel.push_back(0);
		vel.push_back(0);
		color.push_back(random_float(0, 1));
		color.push_back(random_float(0, 1));
		color.push_back(random_float(0, 1));
		color.push_back(1.0);
	}

	float xmax = 1;
	float ymax = 1;

	size_t cursor = 0;

	while (!glfwWindowShouldClose(window)){
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		auto particles = pr.get_new_particles();
		for(auto p: particles){

			if(xmax < p.position().x()){
				xmax = p.position().x();
			}

			if(ymax < p.position().y()){
				ymax = p.position().y();
			}

			for(int i = 0; i < 20; i++){
				pos[cursor*3] = (-((p.position().x()/xmax) * 0.2f - 0.1f));
				pos[cursor*3+1] = (-((p.position().y()/ymax) * 0.2f - 0.1f));
				pos[cursor*3+2] = (0);
				vel[cursor*3] = (-p.velocity().x()/2000.0 + random_float(-0.001, 0.001));
				vel[cursor*3+1] = (-p.velocity().y()/2000.0 + random_float(-0.001, 0.001));
				vel[cursor*3+2] = (0);
				//color[cursor*3+3] = (1);
				cursor++;
				if(pos.size()/3 <= cursor){
					std::cout << "CURSOR REWIND: " << pos.size()/3 << std::endl;
					cursor = 0;
				}
			}
		}

		for(size_t i = 0; i < pos.size(); i++){
			pos[i] += vel[i];
			vel[i] *= 0.9999;
		}

		pd.draw(pos, color, 0.005);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

float random_float(float min, float max) {
	return min + static_cast<float>(rand()) / (RAND_MAX / (max - min));
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
#ifdef __APPLE__	
	glViewport(0, 0, width*2, height*2);
#else
	glViewport(0, 0, width, height);
#endif
} 
