#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Object2D
{

	// Create square with given bottom left corner, length and color
	Mesh* CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
	Mesh* CreateShuriken(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
	Mesh* CreateBalloon(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill=false);
	Mesh* CreateRope(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
	Mesh * CreateMarcu(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill=false);
	Mesh* CreateBow(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
	Mesh* CreateStick(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
	Mesh* CreateTip(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);

}

