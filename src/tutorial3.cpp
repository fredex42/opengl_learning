#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "loadshader.h"
using namespace glm;

int main(int argc,char *argv[]){
	if(!glfwInit()){
		std::cerr << "Failed to initialise GLFW" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow *window;
	int width=1024;
	int height=768;
	window = glfwCreateWindow(width, height, "Tutorial 3", NULL, NULL);
	if(window==NULL){
		std::cerr << "Failed to open GLFW window. Note, Intel GPUs are not OGL 3.3 compatible." << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental=true;
	if(glewInit()!=GLEW_OK){
		std::cerr << "Failed to initialise GLEW" << std::endl;
		return -1;
	}

	GLuint programID;

	try {
		 programID = LoadShaders("SimpleVertexShader.vertexshader","SimpleFragmentShader.fragmentshader");
	} catch(const char *param){
		std::cerr << "Shaders not found in default location. Trying src/..." << std::endl;
		try{
			programID = LoadShaders("src/SimpleVertexShader.vertexshader","src/SimpleFragmentShader.fragmentshader");
		} catch(const char *param){
			std::cerr << param << std::endl;
			return -1;
		}
	}

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const GLfloat g_vertex_buffer_data[] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f, 1.0f, 0.0f
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


	/*set up projection, view and model matrices*/
	mat4 Projection = glm::perspective(radians(45.0f), (float)width/(float)height, 0.1f, 100.0f);
	mat4 View = glm::lookAt(
		vec3(4,3,3), // Camera is at (4,3,3), in World Space
		vec3(0,0,0), // and looks at the origin
		vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	mat4 Model = glm::mat4(1.0f);

	//ModelViewProjection combined matrix: watch the order!
	mat4 mvp = Projection * View * Model;

	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);

		GLuint MatrixID = glGetUniformLocation(programID, "MVP");
		// Send our transformation to the currently bound shader, in the "MVP" uniform
		// This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
		   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		   3,                  // size
		   GL_FLOAT,           // type
		   GL_FALSE,           // normalized?
		   0,                  // stride
		   (void*)0            // array buffer offset
		);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	} while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(window)==0);

}
