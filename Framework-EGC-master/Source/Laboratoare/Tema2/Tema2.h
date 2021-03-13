#pragma once
#include <Component/SimpleScene.h>
#include <map>
#include "LabCamera.h"



class Tema2 : public SimpleScene
{
	public:
		Tema2();
		~Tema2();
		float right=10;
		float left=0;
		float bottom=0;
		float top=10;
		float fov=50;
		bool projectionType;
		float harta[10][4];
		float time = 0;
		float viteza = 1;
		float locatie=0;
		int platformaActuala=0;
		bool saritura = false;
		bool cazatura = false;
		float inaltime = 0;
		float poz;
		bool gameOver = false;
		float jos = 0;
		int disparitie = 1;
		std::map<int, std::string> culori{{0,"rosu"}, {1,"galben"}, {2,"portocaliu"} , {3,"verde"} ,{4,"Color"}, {5,"mov"} , {6,"roz"} };
		float combustibil = 100;
		float superViteza = 0;
		float timer = -1;
		bool fp = false;
		bool viataExtra = false;

		void Init() override;

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix) override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

	protected:
		Laborator::Camera *camera;
		glm::mat4 projectionMatrix;
		bool renderCameraTarget;
};
