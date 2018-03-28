#include "demoApp.h"

//int main(int argc, char* args[])
//{
//	/*Clock *clock;
//	clock->init();
//
//	float seconds = 0;
//
//	LogManager::getInstance(LogManager::LOG_INFO, "FileTest.log").info("INFO");
//	LogManager::getInstance().warn("WARN");
//	LogManager::getInstance().setSeverity(LogManager::LOG_ERROR);
//	LogManager::getInstance().trace("TRACE"); //wont print because severity filter has been increased
//	LogManager::getInstance().error("ERROR");
//
//
//	if (clock->isReady())
//	{
//	LogManager::getInstance().error("is ready");
//	}
//	else
//	{
//	LogManager::getInstance().error("NOT ready");
//	}
//
//	LogManager::getInstance().error(std::to_string(clock->getCurrentMinutes()));
//
//	LogManager::getInstance().error(
//	"Time since clock init =  " +
//	std::to_string(clock->getCurrentHours()) + "hr"
//	+ " : " +
//	(std::to_string(60 - (((clock->getCurrentHours() + 1) * 60) - clock->getCurrentMinutes()))) + "min"
//	);
//
//	while(true)
//	std::cout << clock->getCurrentSeconds() << std::endl;
//
//
//	//seconds = clock->getCurrentTime;
//
//	LogManager::getInstance().close();*/
//
//	demoApp GAME = demoApp();
//
//	while (true)
//	{
//		GAME.render();
//	}
//
//	return 0;
//}

#include <iostream>

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(int argc, char* args[])
{
	demoApp GAME = demoApp();
	
	return 0;
}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow *window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}

demoApp::demoApp()
{
	onStart();
	while (!GLrender->window->isClosed())
	{
		render();
	}
	
	// window = new Window("Rob HUMDINGER", 800, 600);
	////Initialize glew and get the error message from the initialize function
	//if (GLEW_OK != glewInit()) {
	//	std::cerr << "Failed to initialize GLEW. \n";
	//}

	// build and compile our shader zprogram
	// ------------------------------------
	//Shader ourShader("../RobEngine/Shaders/textureShader.vs", "../RobEngine/Shaders/textureShader.fs");
	//// set up vertex data (and buffer(s)) and configure vertex attributes
	//// ------------------------------------------------------------------
	//float vertices[] = {
	//	// positions          // colors           // texture coords
	//	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
	//	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
	//	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
	//	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
	//};
	//unsigned int indices[] = {
	//	0, 1, 3, // first triangle
	//	1, 2, 3  // second triangle
	//};
	//unsigned int VBO, VAO, EBO;
	//glGenVertexArrays(1, &VAO);
	//glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);
	//glBindVertexArray(VAO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	//// position attribute
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);
	//// color attribute
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);
	//// texture coord attribute
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	//glEnableVertexAttribArray(2);

	//MaterialManager::GetInstance()->Get(std::string("trapMat"))->Init();
	
	//// load and create a texture 
	//// -------------------------
	//unsigned int texture1;
	//// texture 1
	//// ---------
	//glGenTextures(1, &texture1);
	//glBindTexture(GL_TEXTURE_2D, texture1);
	//// set the texture wrapping parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//// set texture filtering parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//// load image, create texture and generate mipmaps
	//texture = new SDL_Surface();
	//texture = IMG_Load("../Resources/itsa.jpg");
	//if (texture == NULL)
	//{
	//	std::cerr << "Unable to load image + " << std::endl;
	//	printf(IMG_GetError());
	//}
	//else
	//{
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->w, texture->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->pixels);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//}
	//SDL_FreeSurface(texture);

	//MaterialManager::GetInstance()->Get(std::string("trapMat"))->PreRender();
	//// tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
	//// -------------------------------------------------------------------------------------------
	//ourShader.use(); // don't forget to activate/use the shader before setting uniforms!
	//				 // either set it manually like so:
	//glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);

	// render loop
	// -----------
	//while (true)
	//{
	//	// render
	//	// ------
	//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//	glClear(GL_COLOR_BUFFER_BIT);
	//	//// bind textures on corresponding texture units
	//	glActiveTexture(GL_TEXTURE0);
	//	glBindTexture(GL_TEXTURE_2D, texture1);
	//	// render container
	//	ourShader.use();
	//	glBindVertexArray(VAO);
	//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//	glBindVertexArray(0);
	//	glBindTexture(GL_TEXTURE_2D, 0);
	//	SDL_GL_SwapWindow(window->getWindow());
	//	window->clear();
	//}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	//glDeleteBuffers(1, &EBO);
}

demoApp::~demoApp()
{
	onEnd();
}

void demoApp::onStart()
{
	GLrender = new OpenGLRenderer();
	ShaderManager::GetInstance()->Put(std::string("myShader"), "../RobEngine/Shaders/coordsEX.vs", "../RobEngine/Shaders/textureShader.fs");
	ImageManager::GetInstance()->Put(std::string("trapImg"), "../Resources/itsa.jpg");
	MaterialManager::GetInstance()->Put(std::string("trapMat"), new Material(
		ImageManager::GetInstance()->Get(std::string("trapImg")), ShaderManager::GetInstance()->Get(std::string("myShader"))
		));
	MeshManager::GetInstance()->Put(std::string("myShape"), new SingleMesh(Mesh_Style::CUBE, MaterialManager::GetInstance()->Get(std::string("trapMat"))));
	MeshManager::GetInstance()->Get(std::string("myShape"))->meshPos = glm::vec3(0.0f, 0.0f, 0.0f);
	MeshManager::GetInstance()->Put(std::string("myShape2"), new SingleMesh(Mesh_Style::CUBE, MaterialManager::GetInstance()->Get(std::string("trapMat"))));
	MeshManager::GetInstance()->Get(std::string("myShape2"))->meshPos = glm::vec3(-1.5f, -2.2f, -2.5f);

	matrixStack = MatrixStack();
	matrixStack.translateBy(0.0f, 0.0f, 0.0f);

	matrixStack.pushModelView();
	matrixStack.translateBy(-1.5f, -2.2f, -2.5f);
	//set model to matrix stack

	GLrender->shapeList.push_back(MeshManager::GetInstance()->Get(std::string("myShape")));
	GLrender->shapeList.push_back(MeshManager::GetInstance()->Get(std::string("myShape2")));

	/*box1 = new AABB();
	box1->surround(GLrender->shapeList[0]);
	box2 = new AABB();
	box2->surround(GLrender->shapeList[1]);*/

	//GLrender->RenderPrimitive(2);
}

void demoApp::onEnd()
{
	GLrender->~OpenGLRenderer();
}

void demoApp::render()
{	GLrender->PreRender();	GLrender->Render();
	GLrender->PostRender();

	/*if (box1->intersects(*box2))
	{
		std::cout << "intersecting" << std::endl;
	}*/
}

