#include "Object2D.h"

#include <Core/Engine.h>

Mesh* Object2D::CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, length, 0), color),
		VertexFormat(corner + glm::vec3(0, length, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };
	
	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

Mesh* Object2D::CreateShuriken(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill)
{

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(length/2, length, 0), color),
		//VertexFormat(center + glm::vec3(length, length, 0), color),
		VertexFormat(center + glm::vec3(-length / 2, length, 0), color),
		VertexFormat(center + glm::vec3(-length, length/2, 0), color),
		VertexFormat(center + glm::vec3(-length, -length / 2, 0), color),


		VertexFormat(center + glm::vec3(-length / 2, -length, 0), color),
		//VertexFormat(center + glm::vec3(length, length, 0), color),
		VertexFormat(center + glm::vec3(length / 2, -length, 0), color),
		VertexFormat(center + glm::vec3(length, -length / 2, 0), color),
		VertexFormat(center + glm::vec3(length, length / 2, 0), color)
	};

	Mesh* shuriken = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2,0,3,4,0,5,6,0,7,8 };


	shuriken->InitFromData(vertices, indices);
	return shuriken;


}

Mesh* Object2D::CreateBalloon(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill)
{

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(center, color)
	};

	Mesh* balloon = new Mesh(name);
	std::vector<unsigned short> indices = {0 };

	int ind = 1;
	for (float i = 0; i <= 2*3.5; i=i+0.2)
	{
		vertices.push_back(VertexFormat(glm::vec3(length*cos(i), length*sin(i),  0 )+center,  color));
		indices.push_back(ind);
		ind++;
	}

	balloon->InitFromData(vertices, indices);
	balloon->SetDrawMode(GL_TRIANGLE_FAN);
	return balloon;


}

Mesh* Object2D::CreateRope(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill)
{

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(-length , -length, 0), color),
		VertexFormat(center + glm::vec3(length , -2 * length, 0), color),
		VertexFormat(center + glm::vec3(0, -3 * length, 0), color)
	};

	Mesh* rope = new Mesh(name);
	std::vector<unsigned short> indices = { 0,1,2,3 };

	rope->InitFromData(vertices, indices);
	rope->SetDrawMode(GL_LINE_STRIP);
	return rope;


}

Mesh* Object2D::CreateMarcu(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill)
{

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(-length , -length, 0), color),
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(length , -length, 0), color),
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(0, 1.3*length, 0), color),
		VertexFormat(center + glm::vec3(0, 1.3*length, 0), color),
		VertexFormat(center + glm::vec3(-0.3*length, 1.6*length, 0), color),
		VertexFormat(center + glm::vec3(-0.3*length, 1.6*length, 0), color),
		VertexFormat(center + glm::vec3(0.3*length, 1.6*length, 0), color),
		VertexFormat(center + glm::vec3(0.3*length, 1.6*length, 0), color),
		VertexFormat(center + glm::vec3(0, 1.3*length, 0), color),
		VertexFormat(center + glm::vec3(0, length, 0), color),
		VertexFormat(center + glm::vec3(-length, 2*length, 0), color),
		VertexFormat(center + glm::vec3(0, length, 0), color),
		VertexFormat(center + glm::vec3(length, 2 * length, 0), color)
	};

	Mesh* rope = new Mesh(name);
	//std::vector<unsigned short> indices = { 0,1,0,2,0,3,4,5,4,6 };
	std::vector<unsigned short> indices = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	rope->InitFromData(vertices, indices);
	rope->SetDrawMode(GL_LINES);
	return rope;


}

Mesh* Object2D::CreateBow(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill)
{
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(0 , -2*length, 0), color)
	};
	Mesh* bow = new Mesh(name);
	std::vector<unsigned short> indices = { 0,1 };
	int ind = 2;
	for (float i = 3.14*3/2; i <= 3.14*5/2; i = i + 0.2)
	{
		vertices.push_back(VertexFormat(glm::vec3(length*cos(i), length*sin(i), 0) + center+glm::vec3(0,-length,0), color));
		indices.push_back(ind);
		ind++;
	}
	bow->InitFromData(vertices, indices);
	bow->SetDrawMode(GL_LINE_LOOP);
	return bow;
}

Mesh* Object2D::CreateStick(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill)
{
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(center, color),
		VertexFormat(center + glm::vec3(length , 0, 0), color)
	};
	Mesh* stick = new Mesh(name);
	std::vector<unsigned short> indices = { 0,1 };
	stick->InitFromData(vertices, indices);
	stick->SetDrawMode(GL_LINE_STRIP);
	return stick;
}

Mesh* Object2D::CreateTip(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill)
{
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(center + glm::vec3(length , 0, 0), color),
		VertexFormat(center + glm::vec3(0 , length/2, 0), color),
		VertexFormat(center + glm::vec3(0 , -length / 2, 0), color)
	};
	Mesh* tip = new Mesh(name);
	std::vector<unsigned short> indices = { 0,1,2 };
	tip->InitFromData(vertices, indices);
	return tip;
}
