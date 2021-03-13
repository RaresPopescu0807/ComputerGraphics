#include "Tema2.h"

#include <vector>
#include <string>
#include <iostream>

#include <Core/Engine.h>
#include "Transform3D.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <random>

using namespace std;


Tema2::Tema2()
{
}

Tema2::~Tema2()
{
}

void Tema2::Init()
{
	renderCameraTarget = false;

	camera = new Laborator::Camera();
	camera->Set(glm::vec3(0, 1, 0), glm::vec3(10, 0, 0), glm::vec3(0, 1, 0));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 2); // distribution in range [1, 6]
	std::uniform_int_distribution<std::mt19937::result_type> dist19(1, 9); // distribution in range [1, 6]
	std::uniform_int_distribution<std::mt19937::result_type> dist04(0, 4); // distribution in range [1, 6]

	harta[0][0] = 4;
	harta[0][1] = 9;
	harta[0][3] = 4;
	harta[0][2] = 0;
	for (int i = 1; i <= 9; i++)
	{
		harta[i][0] = dist2(rng);
		harta[i][1] = dist19(rng);
		harta[i][3] = dist04(rng);
		harta[i][2] = harta[i - 1][2] + harta[i-1][1];
		if (harta[i][3] == 0)
		{
			harta[i][1] = 1;
		}
		std::cout << harta[i][0] << ' ' << harta[i][1] << ' ' << harta[i][2] <<std::endl;
	}
	


	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("quad");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "quad.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("circle");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "circle.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Shader* shader = new Shader("rosu");//0
		shader->AddShader("Resources/Shaders/Tema2/Red.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema2/Red.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("galben");//1
		shader->AddShader("Resources/Shaders/Tema2/Yellow.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema2/Yellow.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("portocaliu");//2
		shader->AddShader("Resources/Shaders/Tema2/Orange.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema2/Orange.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("verde");//3
		shader->AddShader("Resources/Shaders/Tema2/Green.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema2/Green.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	{
		Shader* shader = new Shader("mov");//5
		shader->AddShader("Resources/Shaders/Tema2/Purple.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema2/Purple.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	{
		Shader* shader = new Shader("roz");//6
		shader->AddShader("Resources/Shaders/Tema2/Pink.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema2/Pink.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	{
		Shader* shader = new Shader("rezervor");
		shader->AddShader("Resources/Shaders/Tema2/Rezervor.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema2/Rezervor.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("benzina");
		shader->AddShader("Resources/Shaders/Tema2/Benzina.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema2/Benzina.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("viata");
		shader->AddShader("Resources/Shaders/Tema2/Viata.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema2/Viata.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	projectionMatrix = glm::perspective(RADIANS(fov), window->props.aspectRatio, 0.01f, 200.0f);

	/*for (std::unordered_map<std::string, Shader*>::iterator it = shaders.begin(); it != shaders.end(); ++it) {

		std::cout <<  it->first << " ";
	}*/
}

void Tema2::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}






void Tema2::Update(float deltaTimeSeconds)
{
	if (fp == true)
		camera->Set(glm::vec3(2 - jos * 3, inaltime + 1+jos, poz), glm::vec3(10, 0, poz), glm::vec3(0, 1, 0));
	//cout << shaders.size()<<" ";
	if (gameOver == true)
	{
		jos = jos - deltaTimeSeconds;
	}
	else
	{
		time = time + deltaTimeSeconds;
		timer = timer - deltaTimeSeconds;
		if (timer < 0)
		{
			locatie = locatie + deltaTimeSeconds * viteza;
			combustibil = combustibil - deltaTimeSeconds * viteza;
		}
			
		else
		{
			locatie = locatie + deltaTimeSeconds * 5;
			combustibil = combustibil - deltaTimeSeconds * 5;
		}
			

		
		if (combustibil <= 0)
		{
			if (viataExtra == false)
				gameOver = true;
			else
			{
				viataExtra = false;
				combustibil = 50;
			}
		}
			
	}
	if (jos < -3)
	{
		disparitie = 0;
	}
	
	
	if (inaltime >= 1)
		cazatura = true;
	if (cazatura == true)
	{
		inaltime = inaltime - deltaTimeSeconds;
		if (inaltime <= 0)
		{
			cazatura = false;
		}
	}

	if ((cazatura == false)&&(inaltime<=0))
	{
		if (harta[platformaActuala % 10][2] + harta[platformaActuala % 10][1] > locatie+2)
		{
			if ((-1 + harta[platformaActuala % 10][0] < poz) && (0 + harta[platformaActuala % 10][0] > poz))
				gameOver = true;
			if (harta[platformaActuala % 10][3] != 5)
			{
				if (culori[harta[platformaActuala % 10][3]] == "rosu")
				{
					gameOver = true;
				}
				if (culori[harta[platformaActuala % 10][3]] == "galben")
				{
					combustibil = combustibil - 10;

				}
				if (culori[harta[platformaActuala % 10][3]] == "portocaliu")
				{
					timer = 3;
				}
				if (culori[harta[platformaActuala % 10][3]] == "verde")
				{
					combustibil = 100;
				}
				if (culori[harta[platformaActuala % 10][3]] == "roz")
				{
					viataExtra = true;
				}
				harta[platformaActuala % 10][3] = 5;
				
				
			}
				
		}
		else
		{


			if ((-1 + harta[(platformaActuala + 1) % 10][0] < poz) && (0 + harta[(platformaActuala + 1) % 10][0] > poz))
				gameOver = true;
			if (harta[(platformaActuala + 1) % 10][3] != 5)
			{
				if (culori[harta[(platformaActuala + 1) % 10][3]] == "rosu")
				{
					gameOver = true;
				}
				if (culori[harta[(platformaActuala + 1) % 10][3]] == "galben")
				{
					combustibil = combustibil - 10;

				}
				if (culori[harta[(platformaActuala + 1) % 10][3]] == "portocaliu")
				{
					timer = 3;
				}
				if (culori[harta[(platformaActuala + 1) % 10][3]] == "verde")
				{
					combustibil = 100;
				}
				if (culori[harta[(platformaActuala + 1) % 10][3]] == "roz")
				{
					viataExtra = true;
				}
				harta[(platformaActuala + 1) % 10][3] = 5;
			}
				

		}
		
	}



	glm::mat4 modelMatrix = glm::mat4(1);

	modelMatrix = glm::mat4(1);
	modelMatrix *= Transform3D::Translate(-0.75, 0.75, 0);
	modelMatrix *= Transform3D::Scale(0.1*combustibil/100, 0.1, 0.1);
	RenderMesh(meshes["quad"], shaders["benzina"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix *= Transform3D::Translate(-0.75, 0.75, 0);
	modelMatrix *= Transform3D::Scale(0.1, 0.1, 0.1);
	RenderMesh(meshes["quad"], shaders["rezervor"], modelMatrix);

	if (viataExtra == true)
	{
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0.75, 0.75, 0);
		//modelMatrix *= Transform3D::Scale(0.1, 0.1, 0.1);
		RenderMesh(meshes["circle"], shaders["viata"], modelMatrix);
	}
	

	modelMatrix = glm::mat4(1);
	modelMatrix *= Transform3D::Translate(2, 0.25+0.05, 0 );
	modelMatrix *= Transform3D::Translate(0, inaltime, poz);
	modelMatrix *= Transform3D::Translate(-jos*3, jos, 0);
	modelMatrix *= Transform3D::Scale(0.5*disparitie, 0.5*disparitie,0.5*disparitie);
	if(timer<=0)
		RenderMesh(meshes["sphere"], shaders["VertexNormal"], modelMatrix);
	else
		RenderMesh(meshes["sphere"], shaders["roz"], modelMatrix);
	

	if (harta[platformaActuala % 10][2] + harta[platformaActuala % 10][1] < locatie)
	{
		platformaActuala++;
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 2); // distribution in range [1, 6]
		std::uniform_int_distribution<std::mt19937::result_type> dist19(1, 9); // distribution in range [1, 6]
		std::uniform_int_distribution<std::mt19937::result_type> dist04(0, 4); // distribution in range [1, 6]
		harta[(platformaActuala+9)%10][0] = dist2(rng);
		harta[(platformaActuala+9) % 10][1] = dist19(rng);
		harta[(platformaActuala + 9) % 10][3] = dist04(rng);
		harta[(platformaActuala + 9) % 10][2] = harta[(platformaActuala + 9-1) % 10][2] + harta[(platformaActuala + 9 - 1) % 10][1];
		if (harta[(platformaActuala + 9) % 10][3] == 0)
		{
			harta[(platformaActuala + 9) % 10][1] = 1;
		}
		if ((harta[(platformaActuala + 9) % 10][3] == 3)&& (harta[(platformaActuala + 9) % 10][1] == 9))
		{
			harta[(platformaActuala + 9) % 10][3] = 6;
		}
	}
	


	for (int i = 0; i <= 9; i++)
	{
		int index = (i + platformaActuala)%10;
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(harta[index][2]+harta[index][1]/2, 0.05, -0.5);
		modelMatrix *= Transform3D::Translate(-locatie, 0, 0);
		//modelMatrix *= Transform3D::Scale(harta[i][1], 0.1, 1);
		for (int j = 0; j <= 2; j++)
		{
			if (harta[index][0] != j)
			{
				RenderMesh(meshes["box"], shaders[culori[harta[index][3]]], modelMatrix*Transform3D::Translate(0, 0, j)*Transform3D::Scale(harta[index][1], 0.1, 1));
			}
		}
		
	}

	// Render the camera target. Useful for understanding where is the rotation point in Third-person camera movement
	if (renderCameraTarget)
	{
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, camera->GetTargetPosition());
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f));
		RenderMesh(meshes["sphere"], shaders["VertexNormal"], modelMatrix);
	}
}

void Tema2::FrameEnd()
{
	DrawCoordinatSystem(camera->GetViewMatrix(), projectionMatrix);
}

void Tema2::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix)
{
	if (!mesh || !shader || !shader->program)
		return;

	// render an object using the specified shader and the specified position
	shader->Use();
	glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
	glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	mesh->Render();
}


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		float cameraSpeed = 2.0f;

		if (window->KeyHold(GLFW_KEY_W)) {
			camera->TranslateForward(deltaTime * cameraSpeed);
			// TODO : translate the camera forward
		}

		if (window->KeyHold(GLFW_KEY_A)) {
			camera->TranslateRight(-deltaTime * cameraSpeed);
			// TODO : translate the camera to the left
		}

		if (window->KeyHold(GLFW_KEY_S)) {
			camera->TranslateForward(-deltaTime * cameraSpeed);
			// TODO : translate the camera backwards
		}

		if (window->KeyHold(GLFW_KEY_D)) {
			camera->TranslateRight(deltaTime * cameraSpeed);
			// TODO : translate the camera to the right
		}
	}
	else
	{


		if (window->KeyHold(GLFW_KEY_W)) {
			viteza = viteza + deltaTime;
			if (viteza >= 3)
				viteza = 3;
		}
		if (window->KeyHold(GLFW_KEY_S)) {
			viteza = viteza - deltaTime;
			if (viteza <= 1)
				viteza = 1;
			// TODO : translate the camera forward
		}
		if (window->KeyHold(GLFW_KEY_D)) {
			poz = poz + deltaTime;
			if (poz >= 2)
				poz = 2;

			// TODO : translate the camera forward
		}
		if (window->KeyHold(GLFW_KEY_A)) {
			poz = poz - deltaTime;

			if (poz <= -1)
				poz = -1;

			// TODO : translate the camera forward
		}
	}
	if (window->KeyHold(GLFW_KEY_SPACE)) {
		if (cazatura==false)
			inaltime = inaltime + deltaTime;

		// TODO : translate the camera forward
	}
}

void Tema2::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_C)
	{
		fp = !fp;
	}
	if (fp == true)
	{

	}
	else
		camera->Set(glm::vec3(0, 1, 0), glm::vec3(10, 0, 0), glm::vec3(0, 1, 0));

}

void Tema2::OnKeyRelease(int key, int mods)
{
	if (key==GLFW_KEY_SPACE)
	{
		if (cazatura == false)
			cazatura = true;
	}
}

void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event

	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		float sensivityOX = 0.001f;
		float sensivityOY = 0.001f;

		if (window->GetSpecialKeyState() == 0) {
			renderCameraTarget = false;
			// TODO : rotate the camera in First-person mode around OX and OY using deltaX and deltaY
			// use the sensitivity variables for setting up the rotation speed
			camera->RotateFirstPerson_OX(sensivityOX * -deltaY);
			camera->RotateFirstPerson_OY(sensivityOY * -deltaX);
		}

		if (window->GetSpecialKeyState() && GLFW_MOD_CONTROL) {
			renderCameraTarget = true;
			// TODO : rotate the camera in Third-person mode around OX and OY using deltaX and deltaY
			// use the sensitivity variables for setting up the rotation speed
			camera->RotateThirdPerson_OX(sensivityOX * -deltaY);
			camera->RotateThirdPerson_OY(sensivityOY * -deltaX);
		}

	}
}

void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}
