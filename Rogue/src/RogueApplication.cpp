
#include "pch.h"
#include "RogueApplication.h"
#include "RogueWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Image.h"
#include "Shader.h"
#include "codeOpenGL/ShaderOpenGL.h"
#include "Renderer.h"

#include "RogueKeys.h"

namespace Rogue {
	RogueApplication::RogueApplication()
	{
		RogueWindow::Init();
		RogueWindow::GetWindow()->Create(792, 1080);

		Renderer::Init();

		SetWindowCloseCallback([this]() { this->DefaultWindowCloseHandler(); });
	}
	void RogueApplication::Initialize()
	{
		
	}
	void RogueApplication::OnUpdate()
	{

	}
	void RogueApplication::Shutdown()
	{
	}
	void RogueApplication::Run()
	{
	
		

		Initialize();
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		
		while (mShouldContinue) {
			Renderer::ClearScreen();

			OnUpdate();
		
			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			RogueWindow::GetWindow()->SwapBuffers();
			RogueWindow::GetWindow()->PollEvents();

		}
		Shutdown();
		RogueWindow::Shutdown();

	}
	void RogueApplication::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		RogueWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}
	void RogueApplication::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		RogueWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}
	void RogueApplication::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		RogueWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void RogueApplication::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}
	
}


/*
#include "pch.h"
#include "RogueApplication.h"
#include "RogueWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Image.h"
#include "Shader.h"
#include "codeOpenGL/ShaderOpenGL.h"

namespace Rogue {
	void RogueApplication::Initialize()
	{
	}
	void RogueApplication::OnUpdate()
	{

	}
	void RogueApplication::Shutdown()
	{
	}
	void RogueApplication::Run()
	{

		RogueWindow::Init();
		RogueWindow::GetWindow()->Create(1980, 1080);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			ROGUE_ERROR("Failed to initialize Glad");
			return;
		}

		////////Blending ///////////

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//////// Vertx date ////////

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		float vertices[] = {
			-0.5f, -0.5f, 0.0, 0.0, //left
			 0.5f, -0.5f, 1.0, 0.0, //right
			-0.5f,  0.5f, 0.0, 1.0, // top
			 0.5f,  0.5f, 1.0, 1.0 //left
		};

		unsigned int indices[] = {
			0, 1, 2, //first trigangle
			1, 2, 3  //second trigangle
		};

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		/////// Shaders //////////////////////

		Shader sProg{ "C:\\Users\\Riyuan Liu\\Documents\\GameEngine\\S24_Riyuan_Liu\\Rogue\\Assets\\Shaders\\DefaultVertexShader.glsl","C:\\Users\\Riyuan Liu\\Documents\\GameEngine\\S24_Riyuan_Liu\\Rogue\\Assets\\Shaders\\DefaultFragmentShader.glsl" };

		////// Texture  ///////
		Rogue::Image pic{ "C:\\Users\\Riyuan Liu\\Documents\\GameEngine\\S24_Riyuan_Liu\\Rogue\\Assets\\Textures\\Text.png" };
		Rogue::Image pic1{ "C:\\Users\\Riyuan Liu\\Documents\\GameEngine\\S24_Riyuan_Liu\\Rogue\\Assets\\Textures\\.png" };
		///// Application start /////
		Initialize();

		while (true) {
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// draw our first triangle
			sProg.Bind();
			glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time
			pic.Bind();
			pic1.Bind();
			//glBindTexture(GL_TEXTURE_2D,mTexture);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			RogueWindow::GetWindow()->SwapBuffers();
			RogueWindow::GetWindow()->PollEvents();

		}
		Shutdown();
		RogueWindow::Shutdown();

	}
}
*/