#include <iostream>
#include <fstream>

#include "particle_drawer.h"

using namespace std;

float random_float(float min, float max);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(){
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
	GLFWwindow* window = glfwCreateWindow(500, 500, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return 3;
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, framebuffer_size_callback);

	ParticleDrawer pd;
	if(!pd.init()) return 1;


	while (!glfwWindowShouldClose(window)){
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		vector<float> pos;
		for(int i = 0; i < 100; i++){
			pos.push_back(random_float(-1.0, 1.0));
			pos.push_back(random_float(-1.0, 1.0));
			pos.push_back(random_float(-1.0, 1.0));
		}

		pd.draw(pos, 0.4);

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
	glViewport(0, 0, width, height);
} 
