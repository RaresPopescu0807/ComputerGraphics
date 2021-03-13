#include "Laborator3.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include "Object2D.h"

using namespace std;

int xp1 = 150;
int yp1 = 250;
float sxp2 = 0.5;
float syp2 = 0.5;
float rp3 = 0;
int cx, cy;
float pbx = 500;
float pby = 500;
float o = 0;


Laborator3::Laborator3()
{
}

Laborator3::~Laborator3()
{
}

void Laborator3::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;

	// compute coordinates of square center
	cx = corner.x + squareSide / 2;
	cy = corner.y + squareSide / 2;
	
	// initialize tx and ty (the translation steps)
	translateX = 0;
	translateY = 0;

	// initialize sx and sy (the scale factors)
	scaleX = 1;
	scaleY = 1;
	
	// initialize angularStep
	angularStep = 0;
	

	Mesh* square1 = Object2D::CreateSquare("square1", corner, squareSide, glm::vec3(1, 0, 0), true);
	AddMeshToList(square1);
	
	Mesh* square2 = Object2D::CreateSquare("square2", corner, squareSide, glm::vec3(0, 1, 0));
	AddMeshToList(square2);

	Mesh* square3 = Object2D::CreateSquare("square3", corner, squareSide, glm::vec3(0, 0, 1));
	AddMeshToList(square3);

	Mesh* body = Object2D::CreateSquare("body", corner, squareSide, glm::vec3(0, 1, 1));
	AddMeshToList(body);

	Mesh* front = Object2D::CreateSquare("front", corner, squareSide, glm::vec3(1, 0, 1));
	AddMeshToList(front);
}

void Laborator3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}




void Laborator3::Update(float deltaTimeSeconds)
{
	// TODO: update steps for translation, rotation, scale, in order to create animations

	
	xp1 = (int)(xp1 + deltaTimeSeconds*100)%1280;
	yp1 = (int)(yp1 + deltaTimeSeconds * 100) % 720;
	sxp2 = fmod(sxp2+deltaTimeSeconds,1);
	syp2 = fmod(syp2 + deltaTimeSeconds, 1);
	rp3 = rp3 + deltaTimeSeconds;


	

	
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(xp1, yp1)*Transform2D::Translate(-cx, -cy);
	// TODO: create animations by multiplying current transform matrix with matrices from Transform 2D

	RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(400, 250)*Transform2D::Scale(sxp2,syp2)*Transform2D::Translate(-cx,-cy);
	//TODO create animations by multiplying current transform matrix with matrices from Transform 2D
	
	RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(650, 250)*Transform2D::Rotate(rp3)*Transform2D::Translate(-cx, -cy);

	//TODO create animations by multiplying current transform matrix with matrices from Transform 2D
	RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);

	//body

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(pbx, pby)*Transform2D::Rotate(o)*Transform2D::Translate(-cx, -cy);
	RenderMesh2D(meshes["body"], shaders["VertexColor"], modelMatrix);

	//front

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(cos(o)*65+pbx,sin(o)*65+ pby)*Transform2D::Rotate(o)*Transform2D::Translate(-cx*0.3, -cy)*Transform2D::Scale(0.3, 1);
	RenderMesh2D(meshes["front"], shaders["VertexColor"], modelMatrix);
}

void Laborator3::FrameEnd()
{

}

void Laborator3::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_A)) {
		o = o + deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_W)) {
		pbx = pbx + deltaTime*200 * cos(o);
		pby = pby + deltaTime * 200 * sin(o);
	}
	if (window->KeyHold(GLFW_KEY_D)) {
		o = o - deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_S)) {
		pbx = pbx - deltaTime*80*cos(o);
		pby = pby - deltaTime * 80 * sin(o);
	}
}

void Laborator3::OnKeyPress(int key, int mods)
{
	// add key press event
}

void Laborator3::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Laborator3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Laborator3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Laborator3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Laborator3::OnWindowResize(int width, int height)
{
}