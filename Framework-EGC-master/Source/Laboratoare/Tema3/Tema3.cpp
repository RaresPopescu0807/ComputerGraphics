#include "Tema3.h"

#include <vector>
#include <string>
#include <iostream>

#include <Core/Engine.h>
#include "Transform3D.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <random>

using namespace std;


Tema3::Tema3()
{
}

Tema3::~Tema3()
{
}

void Tema3::Init()
{
	renderCameraTarget = false;
	const string textureLoc = "Source/Laboratoare/Laborator9/Textures/";

	camera = new Laborator::Camera3();
	camera->Set(glm::vec3(0, 1, 0), glm::vec3(10, 0, 0), glm::vec3(0, 1, 0));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 2); // distribution in range [1, 6]
	std::uniform_int_distribution<std::mt19937::result_type> dist19(4, 9); // distribution in range [1, 6]
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
		pepeni[i] = 1;
		//std::cout << harta[i][0] << ' ' << harta[i][1] << ' ' << harta[i][2] <<std::endl;
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
		shader->AddShader("Resources/Shaders/Tema3/Red.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema3/Red.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("galben");//1
		shader->AddShader("Resources/Shaders/Tema3/Yellow.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema3/Yellow.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("portocaliu");//2
		shader->AddShader("Resources/Shaders/Tema3/Orange.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema3/Orange.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("verde");//3
		shader->AddShader("Resources/Shaders/Tema3/Green.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema3/Green.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	{
		Shader* shader = new Shader("mov");//5
		shader->AddShader("Resources/Shaders/Tema3/Purple.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema3/Purple.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	{
		Shader* shader = new Shader("roz");//6
		shader->AddShader("Resources/Shaders/Tema3/Pink.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema3/Pink.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	{
		Shader* shader = new Shader("rezervor");
		shader->AddShader("Resources/Shaders/Tema3/Rezervor.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema3/Rezervor.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("benzina");
		shader->AddShader("Resources/Shaders/Tema3/Benzina.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema3/Benzina.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
	{
		Shader* shader = new Shader("viata");
		shader->AddShader("Resources/Shaders/Tema3/Viata.FS.glsl", GL_FRAGMENT_SHADER);
		shader->AddShader("Resources/Shaders/Tema3/Viata.VS.glsl", GL_VERTEX_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	{
		Mesh* mesh = new Mesh("trunk");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("leaves");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("watermellon");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Resources/Textures/Tema3/trunk.jpg", GL_REPEAT);
		mapTextures["trunk"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Resources/Textures/Tema3/leaves.jpg", GL_REPEAT);
		mapTextures["leaves"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Resources/Textures/Tema3/birch.jpg", GL_REPEAT);
		mapTextures["birch"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Resources/Textures/Tema3/leaves2.jpg", GL_REPEAT);
		mapTextures["leaves2"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Resources/Textures/Tema3/stone.jpg", GL_REPEAT);
		mapTextures["stone"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D("Resources/Textures/Tema3/watermellon.jpg", GL_REPEAT);
		mapTextures["watermellon"] = texture;
	}



	{
		Shader *shader = new Shader("ShaderLab9");
		shader->AddShader("Source/Laboratoare/Laborator9/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Laborator9/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}




	projectionMatrix = glm::perspective(RADIANS(fov), window->props.aspectRatio, 0.01f, 200.0f);

	/*for (std::unordered_map<std::string, Shader*>::iterator it = shaders.begin(); it != shaders.end(); ++it) {

		std::cout <<  it->first << " ";
	}*/
}

void Tema3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}






void Tema3::Update(float deltaTimeSeconds)
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
		std::uniform_int_distribution<std::mt19937::result_type> dist19(4, 9); // distribution in range [1, 6]
		std::uniform_int_distribution<std::mt19937::result_type> dist04(0, 4); // distribution in range [1, 6]
		harta[(platformaActuala+9)%10][0] = dist2(rng);
		harta[(platformaActuala+9) % 10][1] = dist19(rng);
		harta[(platformaActuala + 9) % 10][3] = dist04(rng);
		harta[(platformaActuala + 9) % 10][2] = harta[(platformaActuala + 9-1) % 10][2] + harta[(platformaActuala + 9 - 1) % 10][1];
		pepeni[(platformaActuala + 9) % 10] = 1;
		if (harta[(platformaActuala + 9) % 10][3] == 0)
		{
			harta[(platformaActuala + 9) % 10][1] = 1;
		}
		if ((harta[(platformaActuala + 9) % 10][3] == 3)&& (harta[(platformaActuala + 9) % 10][1] == 9))
		{
			harta[(platformaActuala + 9) % 10][3] = 6;
		}
	}
	

	//copaci dreapta

	for (int i = 0; i <= 9; i++)
	{
		int index = (i + platformaActuala) % 10;
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(harta[index][2] + harta[index][1] / 2, 0.05, -0.5);
		modelMatrix *= Transform3D::Translate(-locatie, 0, 0);
		modelMatrix *= Transform3D::Translate(0, 0.3, 4);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 5, 1));
		RenderSimpleMesh(meshes["trunk"], shaders["ShaderLab9"], modelMatrix, mapTextures["trunk"], nullptr);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 0.2, 1));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(5));
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 1, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 2, 1));
		RenderSimpleMesh(meshes["leaves"], shaders["ShaderLab9"], modelMatrix, mapTextures["leaves"], nullptr);

	}

	//copaci stanga

	for (int i = 0; i <= 9; i++)
	{
		int index = (i + platformaActuala) % 10;
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(harta[index][2] + harta[index][1] / 2, 0.05, -0.5);
		modelMatrix *= Transform3D::Translate(-locatie, 0, 0);
		modelMatrix *= Transform3D::Translate(0, 0.3, -3);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 5, 1));
		RenderSimpleMesh(meshes["trunk"], shaders["ShaderLab9"], modelMatrix, mapTextures["birch"], nullptr);
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 0.2, 1));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(5));
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.5, 0));
		//modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 1, 1));
		RenderSimpleMesh(meshes["leaves"], shaders["ShaderLab9"], modelMatrix, mapTextures["leaves2"], nullptr);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.5, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.8));
		RenderSimpleMesh(meshes["leaves"], shaders["ShaderLab9"], modelMatrix, mapTextures["leaves2"], nullptr);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0, 0.5, 0));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.8));
		RenderSimpleMesh(meshes["leaves"], shaders["ShaderLab9"], modelMatrix, mapTextures["leaves2"], nullptr);

	}


	//obstacole

	


	for (int i = 0; i <= 9; i++)
	{
		int index = (i + platformaActuala) % 10;
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(harta[index][2] + harta[index][1] / 2, 0.05, -0.5);
		modelMatrix *= Transform3D::Translate(-locatie, 0, 0);
		if (harta[index][0] == 2)
		{
			RenderSimpleMesh(meshes["trunk"], shaders["ShaderLab9"], modelMatrix*Transform3D::Translate(0, 0.20, 0)*Transform3D::Scale(0.3, 0.3, 1), mapTextures["stone"], nullptr);
			if ((-1 +0 < poz) && (0 + 0 > poz)&& (harta[index][2] + harta[index][1] / 2 - 0.15 < locatie + 2) && (harta[index][2] + harta[index][1] / 2 + 0.15 > locatie + 2) && (inaltime < 0.3))
				gameOver = true;
		}
		else
		{
			RenderSimpleMesh(meshes["trunk"], shaders["ShaderLab9"], modelMatrix*Transform3D::Translate(0, 0.20, 1 + harta[index][0])*Transform3D::Scale(0.3, 0.3, 1), mapTextures["stone"], nullptr);
			if ((-1 + 1 + harta[index][0] < poz) && (0 + 1 + harta[index][0] > poz) && (harta[index][2] + harta[index][1] / 2 - 0.15 < locatie + 2) && (harta[index][2] + harta[index][1] / 2 + 0.15 > locatie + 2) && (inaltime < 0.3))
				gameOver = true;
		}
		

	}

	//pepenosii

	for (int i = 0; i <= 9; i++)
	{
		int index = (i + platformaActuala) % 10;
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(harta[index][2] + harta[index][1] / 2, 0.05, -0.5);
		modelMatrix *= Transform3D::Translate(-locatie, 0, 0);
		if (harta[index][0] == 0)
		{
			RenderSimpleMesh(meshes["watermellon"], shaders["ShaderLab9"], modelMatrix*Transform3D::Translate(0, 0.20, 2)*Transform3D::Scale(0.4, 0.4, 0.4)*Transform3D::Scale(pepeni[index], pepeni[index], pepeni[index]), mapTextures["watermellon"], nullptr);
			if ((-1 + 2 < poz) && (0 + 2 > poz) && (harta[index][2] + harta[index][1] / 2 - 0.15 < locatie + 2) && (harta[index][2] + harta[index][1] / 2 + 0.15 > locatie + 2) && (inaltime < 0.3)&&(pepeni[index]==1))
			{
				pepeni[index] = 0;
				scor++;
				cout << scor << endl;
				
			}
		}
		else
		{
			RenderSimpleMesh(meshes["watermellon"], shaders["ShaderLab9"], modelMatrix*Transform3D::Translate(0, 0.20, -1 + harta[index][0])*Transform3D::Scale(0.4,0.4,0.4)*Transform3D::Scale(pepeni[index], pepeni[index], pepeni[index]), mapTextures["watermellon"], nullptr);
			if ((-1 - 1 + harta[index][0] < poz) && (0 - 1 + harta[index][0] > poz) && (harta[index][2] + harta[index][1] / 2 - 0.15 < locatie + 2) && (harta[index][2] + harta[index][1] / 2 + 0.15 > locatie + 2) && (inaltime < 0.3) && (pepeni[index] == 1))
			{
				pepeni[index] = 0;
				scor++;
				cout << scor << endl;
				
			}
		}


	}


	for (int i = 0; i <= 9; i++)
	{
		int index = (i + platformaActuala)%10;
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(harta[index][2]+harta[index][1]/2, 0.05, -0.5);
		modelMatrix *= Transform3D::Translate(-locatie, 0, 0);
		
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

void Tema3::FrameEnd()
{
	DrawCoordinatSystem(camera->GetViewMatrix(), projectionMatrix);
}

void Tema3::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix)
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

void Tema3::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, Texture2D* texture1, Texture2D* texture2)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));

	// Bind projection matrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// BONUS: Deciding wether to rotate the mesh or not
	GLint locTime = glGetUniformLocation(shader->program, "time");

	if (mesh == meshes["watermellon"])
	{
		glUniform1f(locTime, (GLfloat)Engine::GetElapsedTime());
	}
	else
	{
		glUniform1f(locTime, -1.f);
	}

	glUniform1i(glGetUniformLocation(shader->program, "mix_textures"), mixTextures);

	if (texture1)
	{
		// Activate texture location 0
		glActiveTexture(GL_TEXTURE0);

		// Bind the texture1 ID
		glBindTexture(GL_TEXTURE_2D, texture1->GetTextureID());

		// Send texture uniform value
		glUniform1i(glGetUniformLocation(shader->program, "texture_1"), 0);
	}

	if (texture2)
	{
		// Activate texture location 1
		glActiveTexture(GL_TEXTURE1);

		// Bind the texture2 ID
		glBindTexture(GL_TEXTURE_2D, texture2->GetTextureID());

		// Send texture uniform value
		glUniform1i(glGetUniformLocation(shader->program, "texture_2"), 1);
	}

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}


void Tema3::OnInputUpdate(float deltaTime, int mods)
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

void Tema3::OnKeyPress(int key, int mods)
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

void Tema3::OnKeyRelease(int key, int mods)
{
	if (key==GLFW_KEY_SPACE)
	{
		if (cazatura == false)
			cazatura = true;
	}
}

void Tema3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
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

void Tema3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema3::OnWindowResize(int width, int height)
{
}
