#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "draw_scene.hpp"
#include "tools/shaders.hpp"
#include <iostream>

using namespace glbasimac;
using namespace STP3D;

/* Window properties */
static const unsigned int WINDOW_WIDTH = 1200;
static const unsigned int WINDOW_HEIGHT = 800;
static const char WINDOW_TITLE[] = "Pole express";
static float aspectRatio = 1.0f;

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 30.;

/* Error handling function */
void onError(int error, const char *description)
{
	std::cout << "GLFW Error (" << error << ") : " << description << std::endl;
}

void onWindowResized(GLFWwindow * /*window*/, int width, int height)
{
	aspectRatio = width / (float)height;

	glViewport(0, 0, width, height);
	std::cerr << "Setting 3D projection" << std::endl;
	myEngine.set3DProjection(90.0, aspectRatio, Z_NEAR, Z_FAR);
	// TO DO EX01 part 2
}

void onKey(GLFWwindow *window, int key, int /*scancode*/, int action, int /*mods*/)
{
	int is_pressed = (action == GLFW_PRESS);
	switch (key)
	{
	case GLFW_KEY_Q:
	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(window, GLFW_TRUE);
		break;
	case GLFW_KEY_L:
		if (is_pressed)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case GLFW_KEY_P:
		if (is_pressed)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		// TO DO EX01 part 3

	case GLFW_KEY_R:
		//> EXO 3
		if (is_pressed)
		{
			dist_zoom -= 1.0f;
			if (dist_zoom < 2.0f)
				dist_zoom = 2.0f;
		}
		//< FIN EXO 3
		break;

	case GLFW_KEY_T:
		//> EXO 3
		if (is_pressed)
		{
			dist_zoom += 1.0f;
			if (dist_zoom > 100.0f)
				dist_zoom = 100.0f;
		}
		//< FIN EXO 3
		break;
	case GLFW_KEY_UP:
		if (!camPOV)
			angle_phy += 1.0;
		break;
	case GLFW_KEY_DOWN:
		if (!camPOV)
			angle_phy -= 1.0;
		break;
	case GLFW_KEY_LEFT:
		if (!camPOV)
			angle_theta += 1.0;
		else
			anglePOV += 0.05;
		break;
	case GLFW_KEY_RIGHT:
		if (!camPOV)
			angle_theta -= 1.0;
		else
			anglePOV -= 0.05;
		break;

	case GLFW_KEY_C:
		if (is_pressed)
		{
			camPOV = !camPOV;
		}
		break;
	case GLFW_KEY_W:
		if (camPOV)
		{
			xPOV += cos(anglePOV);
			yPOV += sin(anglePOV);
		}
		break;

	case GLFW_KEY_S:
		if (camPOV)
		{
			xPOV -= cos(anglePOV);
			yPOV -= sin(anglePOV);
		}
		break;

	case GLFW_KEY_A:
		if (camPOV)
		{
			xPOV -= sin(anglePOV);
			yPOV += cos(anglePOV);
		}
		break;

	case GLFW_KEY_D:
		if (camPOV)
		{
			xPOV += sin(anglePOV);
			yPOV -= cos(anglePOV);
		}
		break;

	case GLFW_KEY_E :		
	if (is_pressed)
		{
			animLight = !animLight;
		}
		break;

	default:
		std::cerr << "Touche non gérée " << key << std::endl;
	}
}

void onMouseButton(GLFWwindow *window, int button, int action, int /*mods*/)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		std::cout << "Pressed in " << xpos << " " << ypos << std::endl;
	}
}

int main(int argc, char **argv)
{
	/* GLFW initialisation */
	GLFWwindow *window;
	myEngine.mode2D = false; // Set engine to 3D mode

	if (!glfwInit())
		return -1;

	/* Try to uncomment this for MAC OS if it did not work */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	/* Callback to a function if an error is rised by GLFW */
	glfwSetErrorCallback(onError);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	if (!window)
	{
		// If no context created : exit !
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	std::cout << "Loading GL extension" << std::endl;
	// Intialize glad (loads the OpenGL functions)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return -1;
	}

	glfwSetWindowSizeCallback(window, onWindowResized);
	glfwSetKeyCallback(window, onKey);
	glfwSetMouseButtonCallback(window, onMouseButton);

	std::cout << "Engine init" << std::endl;
	// TO DO EX01 part 2

	myEngine.initGL();
	onWindowResized(window, WINDOW_WIDTH, WINDOW_HEIGHT);
	CHECK_GL;

	initScene();
	double elapsedTime{0.0};

	std::string pars_path;
	if (argc > 1)
	{
		pars_path = argv[1];
	}
	else pars_path = "config.json"; // pour faciliter le debug

	std::vector<Rail> path;

	GridParam parameters = readJson("../src/"+pars_path);
    path = CreateRailPath(parameters);

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
	{
		/* Get time (in second) at loop beginning */
		double startTime = glfwGetTime();

		/* Render begins here */
		glClearColor(0.f, 0.0f, 0.2f, 0.0f);

		// TO DO EX01 part 2
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		drawScene(path);

		// TO DO EX01 part 3
		/* Fix camera position */
		myEngine.mvMatrixStack.loadIdentity();
		if (!camPOV)
		{

			Vector3D pos_camera =
				Vector3D(dist_zoom * cos(deg2rad(angle_theta)) * cos(deg2rad(angle_phy)),
						 dist_zoom * sin(deg2rad(angle_theta)) * cos(deg2rad(angle_phy)),
						 dist_zoom * sin(deg2rad(angle_phy)));
			Vector3D viewed_point = Vector3D(0.0, 0.0, 0.0);
			Vector3D up_vector = Vector3D(0.0, 0.0, 1.0);
			Matrix4D viewMatrix = Matrix4D::lookAt(pos_camera, viewed_point, up_vector);
			myEngine.setViewMatrix(viewMatrix);
		}
		else
		{
			Vector3D pos_camera = Vector3D(xPOV, yPOV, 5);
			float dirX = cos(anglePOV);
			float dirY = sin(anglePOV);

			Vector3D viewed_point(
				xPOV + dirX,
				yPOV + dirY,
				5.0f);
			Vector3D up_vector = Vector3D(0.0, 0.0, 1.0);
			Matrix4D viewMatrix = Matrix4D::lookAt(pos_camera, viewed_point, up_vector);
			myEngine.setViewMatrix(viewMatrix);
		}

		myEngine.updateMvMatrix();

		drawScene(path);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		/* Elapsed time computation from loop begining */
		elapsedTime = glfwGetTime() - startTime;
		/* If to few time is spend vs our wanted FPS, we wait */
		while (elapsedTime < FRAMERATE_IN_SECONDS)
		{
			glfwWaitEventsTimeout(FRAMERATE_IN_SECONDS - elapsedTime);
			elapsedTime = glfwGetTime() - startTime;
		}
	}

	glfwTerminate();

	return 0;
}
