#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() { 
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,// top right
		 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,// bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,// bottom left
		-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,// top left 
	};
	unsigned int indices[] = {
		0, 1, 3,
	};

	//float vertices2[] = {
	//	 0.5f,  0.5f, 0.0f,  // top right
	//	 0.5f, -0.5f, 0.0f,  // bottom right
	//	-0.5f, -0.5f, 0.0f,  // bottom left
	//	-0.5f,  0.5f, 0.0f   // top left 
	//};
	unsigned int indices2[] = {
		1, 2, 3
	};

	unsigned int VAOs[2], VBOs[2], EBOs[2];
	glGenVertexArrays(2, VAOs);
	glGenBuffers(2, VBOs);
	glGenBuffers(2, EBOs);

	glBindVertexArray(VAOs[0]);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	// second triangle
	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	Shader ourShader("src/shaders/shader.vs", "src/shaders/shader.fs");
	ourShader.use();
	ourShader.setFloat("hoffset", 0.0f);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();
		
		glBindVertexArray(VAOs[0]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);


		//glBindVertexArray(VAOs[1]);
		//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// de-allocate all resources 
	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);
	glDeleteBuffers(2, EBOs);

	glfwTerminate();

	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

	std::cout << "OK" << std::endl;

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}