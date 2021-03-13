#include "Tema1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include "Object2D.h"

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::M(int t, int ys, float& umflat, float deltaTimeSeconds)
{

	if (time > t && time < t + 25)
	{
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(0, 1000 * (1 - umflat))*Transform2D::Translate((t - time) * 2*vitezaTinte + resolution.x + lungimeReferinta, ys)*Transform2D::Scale(1, 1+cos(time)/2);
		RenderMesh2D(meshes["Marcu"], shaders["VertexColor"], modelMatrix);

		if (zboara == true)
		{
			if ((startX + cos(unghiSageata)*lungimeReferinta + cos(unghiSageata) * 300 * (1 + viteza)* (time - startZbor)>= ((t - time) * 2*vitezaTinte + resolution.x + lungimeReferinta-lungimeReferinta))
				&& (startX + cos(unghiSageata)*lungimeReferinta + cos(unghiSageata) * 300 * (1 + viteza)* (time - startZbor) <= ((t - time) *2* vitezaTinte + resolution.x + lungimeReferinta+lungimeReferinta))
				&& ((startY + sin(unghiSageata)*lungimeReferinta + sin(unghiSageata) * (1 + viteza) * 300 * (time - startZbor)) >= ys- (1 + cos(time) / 2)*lungimeReferinta)
				&& ((startY + sin(unghiSageata)*lungimeReferinta + sin(unghiSageata) * (1 + viteza) * 300 * (time - startZbor)) <= ys + (1 + cos(time) / 2)*2*lungimeReferinta)
				&& umflat==1)
			{
				scor = scor + 3;
				printf("Scor: %d\n", scor);
				umflat = 0.99;
			}
		}

		if (((t - time) *2* vitezaTinte + resolution.x + lungimeReferinta <lungimeReferinta) && (umflat == 1))
		{
			vieti--;
			printf("Vieti: %d\n", vieti);

			umflat = 0.99;
		}

		if (umflat < 1)
		{
			umflat = umflat - deltaTimeSeconds;
		}
	}
}

void Tema1::F(int t, int xb, float& umflat, float deltaTimeSeconds)
{

	if (time > t && time < t + 15)
	{
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(1000 * (1 - umflat), 500 * (1 - umflat))*Transform2D::Translate(xb, (time - t) * 2 * vitezaTinte - lungimeReferinta)*Transform2D::Scale(0.5, 0.5);
		RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(xb , (time - t) * 2*vitezaTinte - lungimeReferinta)*Transform2D::Scale(umflat, umflat);
		RenderMesh2D(meshes["balonr"], shaders["VertexColor"], modelMatrix);
		
		if (zboara == true)
		{
			if ((sqrt(pow(startX + cos(unghiSageata)*lungimeReferinta + cos(unghiSageata) *(viteza + 1) * 300 * (time - startZbor) - (xb + 50 * cos(time * 5)), 2) + pow(startY + sin(unghiSageata)*lungimeReferinta + sin(unghiSageata) *(viteza + 1) * 300 * (time - startZbor) - ((time - t) * 2*vitezaTinte - lungimeReferinta), 2)) < lungimeReferinta) && (umflat == 1))
			{

				scor=scor+2;
				printf("Scor: %d\n", scor);



				umflat = 0.99;
			}
		}
		if (umflat < 1)
		{
			if (umflat - deltaTimeSeconds > 0)
				umflat = umflat - deltaTimeSeconds;
			else
				umflat = 0;
		}
	}

}

void Tema1::B(int t, int xb,float& umflat, float deltaTimeSeconds, int culoare)
{
	
	if (time > t && time < t+15)
	{
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(xb+50*cos(time*5), (time - t) * vitezaTinte - lungimeReferinta)*Transform2D::Scale(1*umflat, 1.25*umflat);
		if(culoare==1)
			RenderMesh2D(meshes["balonr"], shaders["VertexColor"], modelMatrix);
		else
			RenderMesh2D(meshes["balong"], shaders["VertexColor"], modelMatrix);

		RenderMesh2D(meshes["sfoara"], shaders["VertexColor"], modelMatrix);
		if (zboara == true)
		{
			if ((sqrt(pow(startX +cos(unghiSageata)*lungimeReferinta+ cos(unghiSageata ) *(viteza+1)* 300 * (time - startZbor) - (xb + 50 * cos(time * 5)), 2) + pow(startY + sin(unghiSageata)*lungimeReferinta + sin(unghiSageata) *(viteza+1)* 300 * (time - startZbor) - ((time - t) * vitezaTinte - lungimeReferinta), 2)) < 1.25*lungimeReferinta)&&(umflat == 1))
			{
				if (culoare == 1)
				{
					scor = scor + 1;
					printf("Scor: %d\n", scor);
				}
					
				else
				{
					scor--;
					printf("Scor: %d\n", scor);
				}
					
				
				umflat = 0.99;
			}
		}
		if (umflat < 1)
		{	
			if (umflat - deltaTimeSeconds > 0)
				umflat = umflat - deltaTimeSeconds;
			else
				umflat = 0;
		}
	}
	
}

void Tema1::S(int t, int ys, float& umflat, float deltaTimeSeconds)
{

	if (time > t && time < t + 25)
	{
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(( t- time) * vitezaTinte +resolution.x+ lungimeReferinta,ys)*Transform2D::Rotate(time*10)*Transform2D::Scale( umflat, umflat);
		RenderMesh2D(meshes["stea"], shaders["VertexColor"], modelMatrix);

		if (zboara==true)
		{
			if ((sqrt(pow(startX + cos(unghiSageata)*lungimeReferinta + cos(unghiSageata) * 300 *(1+viteza)* (time - startZbor) - ((t - time) * vitezaTinte + resolution.x + lungimeReferinta), 2) + pow(startY  + sin(unghiSageata)*lungimeReferinta + sin(unghiSageata) * (1+viteza)*300 * (time - startZbor) - ys, 2)) < lungimeReferinta) && (umflat == 1))
			{
				scor = scor + 1;
				printf("Scor: %d\n", scor);
				umflat = 0.99;
			}
		}

		if ((sqrt(pow(arcX - ((t - time) * vitezaTinte + resolution.x + lungimeReferinta), 2) + pow(arcY - ys, 2)) < 2 * lungimeReferinta) && (umflat == 1))
		{
			vieti--;
			printf("Vieti: %d\n", vieti);

			umflat = 0.99;
		}

		if (umflat < 1)
		{
			if (umflat - deltaTimeSeconds > 0)
				umflat = umflat - deltaTimeSeconds;
			else
				umflat = 0;
		}
	}
}

void Tema1::Init()
{
	resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	lungimeReferinta = 50;


	arcX = lungimeReferinta ;

	for (int i = 0; i <= 99; i++)
	{
		umflate[i] = 1;
		periculoase[i] = 1;
		capturate[i] = 1;
		rai[i] = 1;
	}


	Mesh* Marcu = Object2D::CreateMarcu("Marcu", corner, lungimeReferinta, glm::vec3(1, 0.5, 1));
	AddMeshToList(Marcu);

	Mesh* stea = Object2D::CreateShuriken("stea", corner, lungimeReferinta, glm::vec3(0.5, 0.5, 0.5));
	AddMeshToList(stea);

	Mesh* balonr = Object2D::CreateBalloon("balonr", corner, lungimeReferinta, glm::vec3(1, 0, 0));
	AddMeshToList(balonr);

	Mesh* balong = Object2D::CreateBalloon("balong", corner, lungimeReferinta, glm::vec3(1, 1, 0));
	AddMeshToList(balong);

	Mesh* sfoara = Object2D::CreateRope("sfoara", corner - glm::vec3(0,lungimeReferinta,0), lungimeReferinta/5, glm::vec3(0.5f, 0.35f, 0.05f));
	AddMeshToList(sfoara);

	Mesh* arc = Object2D::CreateBow("arc", corner , lungimeReferinta, glm::vec3(0.5f, 0.35f, 0.05f));
	AddMeshToList(arc);
	arcY = resolution.y / 2;

	Mesh* square1 = Object2D::CreateSquare("square1", corner , lungimeReferinta, glm::vec3(1, 0, 0), true);
	AddMeshToList(square1);

	Mesh* bat = Object2D::CreateStick("bat", corner, lungimeReferinta, glm::vec3(0.5f, 0.35f, 0.05f));
	AddMeshToList(bat);

	Mesh* varf = Object2D::CreateTip("varf", corner + glm::vec3(lungimeReferinta, 0, 0), lungimeReferinta/5, glm::vec3(0.5, 0.5, 0.5));
	AddMeshToList(varf);

	printf("Vieti: %d\n", vieti);
	printf("Scor: %d\n", scor);
}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}




void Tema1::Update(float deltaTimeSeconds)
{
	// TODO: update steps for translation, rotation, scale, in order to create animations
	time = time + deltaTimeSeconds;
	//vitezaTinte = 500;
	if (time > 30)
		vitezaTinte = 450;

	//baieti rai

	//if(hardcore==true)
		for (int i = 2; i <= 99; i++)
			if ((i < 20) || (i >= 30) )
				if(i%5==0)
					M( i  , 100 + 50 * i % 500, rai[i], deltaTimeSeconds);

	//fluturi

	for (int i = 2; i <= 99; i++)
		if ((i <= 20) || (i >= 30))
			F( (i+1)+3, 400 + 200 * i % 700, capturate[i], deltaTimeSeconds);

	//balon
	
	for(int i=2;i<=99;i++)
		if((i<=20)||(i>=30))
			B((i+1), 500+200*i%700,umflate[i],deltaTimeSeconds,i%2);
	//surichen
	
	for(int i=2;i<=99;i++)
		if((i<=20)||(i>=30))
			S(i+1, 100+200*i%500, periculoase[i], deltaTimeSeconds);

	//arc
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(arcX, arcY)*Transform2D::Rotate(unghi)        *Transform2D::Translate(0, +lungimeReferinta);
	RenderMesh2D(meshes["arc"], shaders["VertexColor"], modelMatrix);
	modelMatrix *= Transform2D::Translate(0, -3*lungimeReferinta)*Transform2D::Scale(bara,0.5)  ;
	RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

	//Marcu
	modelMatrix = glm::mat3(1);
	if (unghi<3.14 / 2 && unghi>-3.14 / 2)
		modelMatrix *= Transform2D::Translate(arcX-0.5*lungimeReferinta, arcY- lungimeReferinta)*Transform2D::Scale(0.5, 0.7);
	else
		modelMatrix *= Transform2D::Translate(arcX + 0.5*lungimeReferinta, arcY - lungimeReferinta)*Transform2D::Scale(0.5, 0.7);
	RenderMesh2D(meshes["Marcu"], shaders["VertexColor"], modelMatrix);


	//sageata
	if (zboara == false)
	{
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(arcX, arcY)*Transform2D::Rotate(unghi);
		RenderMesh2D(meshes["bat"], shaders["VertexColor"], modelMatrix);
		RenderMesh2D(meshes["varf"], shaders["VertexColor"], modelMatrix);
	}
	else
	{
		modelMatrix = glm::mat3(1);
		float xaux, yaux;
		xaux = startX + cos(unghiSageata) * 300 * (1 + viteza)*(time - startZbor);
		yaux=startY + sin(unghiSageata) * 300 * (1 + viteza)*(time - startZbor);
		modelMatrix *= Transform2D::Translate(xaux, yaux)*Transform2D::Rotate(unghiSageata);
		RenderMesh2D(meshes["bat"], shaders["VertexColor"], modelMatrix);
		RenderMesh2D(meshes["varf"], shaders["VertexColor"], modelMatrix);
		if ((startZbor + 5 < time)||(xaux<-lungimeReferinta)||(yaux<-lungimeReferinta)||(xaux>resolution.x+lungimeReferinta)||(yaux>resolution.y+lungimeReferinta))
		{
			zboara = false;
		}
		
	}

	if (zboara == true)
		bara = 0;

	if (vieti <= 0)
		exit(1);
	
	

}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_W)) {
		arcY = arcY + deltaTime*100;
		if (arcY > resolution.y)
			arcY = resolution.y;
	}
	if (window->KeyHold(GLFW_KEY_S)) {
		arcY = arcY - deltaTime * 100;
		if (arcY < 0)
			arcY = 0;
	}

	if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT)) {
		if (bara >= 1)
			bara = 1;
		else
			bara = bara + deltaTime;
	}
}

void Tema1::OnKeyPress(int key, int mods)
{
	
	// add key press event
}

void Tema1::OnKeyRelease(int key, int mods)
{
	

	
		
	// add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
		unghi = atan2(resolution.y-mouseY-arcY,mouseX-arcX);
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{

	// add mouse button press event

}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	if (IS_BIT_SET(button,GLFW_MOUSE_BUTTON_LEFT) && zboara == false)
	{
		if (unghi<3.14 / 2 && unghi>-3.14 / 2)
		{

			unghiSageata = unghi;
			zboara = true;
			startZbor = time;
			startX = arcX;
			startY = arcY;
			viteza = bara;
			bara = 0;
		}
		else
		{
			bara = 0;
		}
	}
	// add mouse button release event
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
