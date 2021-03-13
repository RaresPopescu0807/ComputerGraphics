#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>



class Tema1 : public SimpleScene
{
	public:
		Tema1();
		~Tema1();
		void M(int t, int xb, float & umflat, float deltaTimeSeconds);
		void F(int t, int xb, float & umflat, float deltaTimeSeconds);
		void B(int t, int xb, float & umflat, float deltaTimeSeconds, int culoare);
		void S(int t, int ys, float & umflat, float deltaTimeSeconds);
		float unghi;
		glm::ivec2 resolution;
		float unghiSageata;
		float time=0;
		bool zboara = false;
		float startZbor;
		float startX;
		float startY;
		float umflate[100];
		float periculoase[100];
		float capturate[100];
		float rai[100];
		float bara = 0;
		float viteza;
		int scor = 0;
		int vieti = 3;
		int vitezaTinte=150;
		float arcX;
		float arcY;
		float lungimeReferinta;


		void Init() override;

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

	protected:
		glm::mat3 modelMatrix;

};
