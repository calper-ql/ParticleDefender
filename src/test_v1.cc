#include <iostream>
#include <fstream>

#include "opengl_settings.h"
#include "shader_loader.h"
#include "shader_program.h"

using namespace std;

float vertices[] = {
	-0.5f, 0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,
	0.0f,  0.5f, 0.0f,
	-0.5f, 0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,
	0.0f, -0.5f, 0.0f
};  

float positions[] = {
	-0.5f, 0.0f, 0.0f,
	0.5f, 0.0f, 0.0f
};

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

	auto vertex_shader = ShaderLoader::load("GL_CODE/particle.vs", GL_VERTEX_SHADER);
	if(vertex_shader == 0) return 1; 

	auto fragment_shader = ShaderLoader::load("GL_CODE/particle.fs", GL_FRAGMENT_SHADER);
	if(fragment_shader == 0) return 2; 

	ShaderProgram prog(vertex_shader, fragment_shader);

	unsigned int instanceVBO;
	glGenBuffers(1, &instanceVBO);
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	while (!glfwWindowShouldClose(window)){
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//BUFFERS
		glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindVertexArray(VAO);	
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, instanceVBO); // this attribute comes from a different vertex buffer
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glVertexAttribDivisor(1, 1); // tell OpenGL this is an instanced vertex attribute.

		prog.use();

		int vertexColorLocation = glGetUniformLocation(prog.get_id(), "color");
		glUniform4f(vertexColorLocation, 0.0f, 1.0f, 0.0f, 1.0f);

		glDrawArraysInstanced(GL_TRIANGLES, 0, 6, 2);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);	

	glfwTerminate();

	return 0;
}

