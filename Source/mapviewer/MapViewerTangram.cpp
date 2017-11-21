#include <iostream>
#include "MapViewerTangram.hpp"
#include <GLFW/glfw3.h>

namespace
{
	GLFWwindow* main_window = nullptr;

	void error_callback(int error, const char* description)
	{
		std::cerr << "lg error: " << error << " " << description;
		std::abort();
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
	    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	        glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	void framebufferResizeCallback(GLFWwindow* window, int fWidth, int fHeight) {

//	    int wWidth = 0, wHeight = 0;
//	    glfwGetWindowSize(main_window, &wWidth, &wHeight);
//	    float new_density = (float)fWidth / (float)wWidth;
//	    if (new_density != density) {
//	        recreate_context = true;
//	        density = new_density;
//	    }
//	    map->setPixelScale(density);
//	    map->resize(fWidth, fHeight);
	}


}

MapViewerTangram::MapViewerTangram(std::shared_ptr<Tangram::Platform> platform)
	: map(platform)
 {}

MapViewerTangram::~MapViewerTangram()
{
}

bool MapViewerTangram::Init(int width, int height)
{
    const std::string& apiKey = "vector-tiles-tyHL4AY";

    if (!glfwInit())
    	return false;

    main_window = glfwCreateWindow(width, height, "Tangram Mapviewer", NULL, NULL);

    if (!main_window) {
    	Exit();
    	return false;
    }

    glfwMakeContextCurrent(main_window);
    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(main_window, key_callback);
    glfwSetFramebufferSizeCallback(main_window, framebufferResizeCallback);

    return true;
}

void MapViewerTangram::UpdatePosition(double longitude, double latitude)
{

}

void MapViewerTangram::Run()
{
}

void MapViewerTangram::Exit()
{
	glfwTerminate();
}

