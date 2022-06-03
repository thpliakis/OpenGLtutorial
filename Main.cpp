#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);



int main()
{ 
	// Initialize GLFW
	glfwInit();
	
	// Tell GLFW what version of OpenGL we are using by giving it hints
	// We are using version OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//GLFW_OPENGL_PROFILE == a package of funtions(2 packages: core(modern functions), compatibility(modern and outdated functions))
	// Tell GLFW we are using CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};


	// Create window object 5 inputs(hight,width,name,fullscreen or not,...)
	// Create a GLFWwindow object of 800 by 800 pixels, naming it "PenfGLtutorial"
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGLtutorial", NULL, NULL);
	// Error check if the window fails to be created
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Tell GLFW to use the window, make the window part of the current context
	// Context == curent object that holds the whole of openGL, abstract
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	// tell glad to load needed configuration for OpenGL
	// Load GLAD so it configures OpenGL
	//gladLoadGL();
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// tell openGL the area of the window to render(bottom left == (0,0), top right == (800,800)
	// Specify the viewport of OpenGL in the window
	// In this case the viewport goes from x=0, y=0 to x=800, y=800
	glViewport(0,0,800,800);

	// prepare a buffer by giving it another color (navy blue)
	//glad_glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	// Tell opengl to execute the command we've told it to prepare for 
	// Clean the back buffer and assign the new color to it
	//glClear(GL_COLOR_BUFFER_BIT);
	// Swap the back budder with the front buffer

	// Keep the window open, close window only when a funtion tells the window to close, ex. close button
	// Main while loop
	while (!glfwWindowShouldClose(window)) {

		processInput(window);

		glfwSwapBuffers(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Tell glfw to proccess all the process all Poll events such as the window appearing or resize
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}