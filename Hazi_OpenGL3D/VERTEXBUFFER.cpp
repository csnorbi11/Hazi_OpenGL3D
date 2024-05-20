#include "VERTEXBUFFER.hpp"

void VertexBuffer::bindVAO() const
{
	glBindVertexArray(VAO);
}

void VertexBuffer::unbindVAO() const
{
	glBindVertexArray(0);
}

void VertexBuffer::createVertexBuffer()
{
	float box[] =
	{
		//hatulja
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,//jobb lent
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,//jobb fent
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,//bal fent
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,//bal lent

		//eleje
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,//jobb lent
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,//jobb fent
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,//bal fent
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,//bal lent

		//bal
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,//bal fent
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,//bal lent
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,//jobb lent
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,//job fent

		//jobb
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,//bal lent
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,//bal fent
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,//jobb lent
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,//jobb fent

		 //lent
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,//bal fent
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,//jobb fent
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,//jobb lent
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,//bal lent

		//fent
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,//bal lent
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,//jobb lent
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,//jobb fent
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,//bal fent
	};

	//vertex kirajzolas sorrendje
	unsigned int indices[] =
	{
		0,1,3,
		1,2,3,
		4,5,6,
		6,7,4,
		8,9,10,
		8,10,11,
		12,13,14,
		12,14,15,
		16,17,18,
		16,19,18,
		20,21,22,
		20,22,23


	};

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(box), box, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}
