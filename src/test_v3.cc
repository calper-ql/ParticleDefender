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

	float xmax = 1;
	float ymax = 1;

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

			pos.push_back(-((p.position().x()/xmax) * 0.1f - 0.05f));
			pos.push_back(-((p.position().y()/ymax) * 0.1f - 0.05f));
			pos.push_back(0);
			vel.push_back(-p.velocity().x()/10000.0);
			vel.push_back(-p.velocity().y()/10000.0);
			vel.push_back(0);
			color.push_back(random_float(0, 1));
			color.push_back(random_float(0, 1));
			color.push_back(random_float(0, 1));
			color.push_back(1);

			if(pos.size()>1000000){
				pos.erase(pos.begin());
				pos.erase(pos.begin());
				pos.erase(pos.begin());
				vel.erase(vel.begin());
				vel.erase(vel.begin());
				vel.erase(vel.begin());
				color.erase(color.begin());
				color.erase(color.begin());
				color.erase(color.begin());
				color.erase(color.begin());
			}
		}

		for(size_t i = 0; i < pos.size(); i++){
			pos[i] += vel[i];
			vel[i] *= 0.9999;
		}

		for(size_t i = 0; i < color.size(); i++){
			if((i+1) % 4 == 0){
				color[i] *= 0.9999;
			}
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
