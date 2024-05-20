#include "APP.hpp"
#include "DRAWABLEGAMEOBJECT.hpp"

using std::cout;
using std::endl;

double Player::lastX = 0;
double Player::lastY = 0;
Camera Player::camera;

void App::init()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WIDTH, HEIGHT, title, 0, NULL);
	if (window == nullptr)
	{
		glfwTerminate();
		throw "Nem jott letre az ablak";
	}
	glfwMakeContextCurrent(window);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		glfwDestroyWindow(window);
		throw "Nem sikerult kinyerni a function pointereket a driverbol";
	}

	glfwSetCursorPosCallback(window, Player::mouse_callback);

	glEnable(GL_DEPTH_TEST);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
void App::run()
{
	/**
	 * GameObjectek heterogen taroloja.
	 * 
	 */
	std::vector<GameObject*> gos;

	gameInit(gos);
	gameLoop(gos);	
	gameClose(gos);
}
void App::close()
{
	glfwTerminate();
	glfwDestroyWindow(window);
}
void App::gameInit(std::vector<GameObject*>& gameObjects)
{
	//Letrehozza a playert, beallitja a poziciojat es a kamerat hozzaigazitja.
	gameObjects.push_back(new Player());
	gameObjects.at(0)->setPosition(glm::vec3(2.0f, 2.0f, -2.0f));
	Player::setCameraPos(dynamic_cast<Player*>(gameObjects.at(0))->getPosition());
	gameObjects.at(0)->setMoveSpeed(5.0f);

	//Letrehoz egy platformot
	int x = 1, z = 1;
	for (size_t i = 1; i < 64; i++)
	{
		x++;
		if (x*z == 8 * z)
		{
			x = 0;
			z++;
		}

		gameObjects.push_back(new DrawableGameObject("TEXTURED.vert", "TEXTURED.frag", "grass.png", "asd"));
		gameObjects.at(i)->setPosition(glm::vec3(x, -5.0f, z-8));
	}
	glm::vec3 finishGOPos = gameObjects.at(gameObjects.size() - 1)->getPosition();
	finishGOPos.y++;
	gameObjects.at(gameObjects.size() - 1)->setPosition(finishGOPos);
	finishGOPos.y++;
	gameObjects.at(0)->setPosition(finishGOPos);
}
void App::gameLoop(std::vector<GameObject*>& gameObjects)
{
	while (!glfwWindowShouldClose(window))
	{
		//frame kezdetenek ideje
		startofFrame = glfwGetTime();
		//input kezelese
		handleInput(*dynamic_cast<Player*>(gameObjects.at(0)));

		//player frissitese
		dynamic_cast<Player*>(gameObjects.at(0))->move(deltaTime);
		dynamic_cast<Player*>(gameObjects.at(0))->applyPhysics(deltaTime, gameObjects);
		if (gameObjects.at(gameObjects.size() - 1)->getPosition() == glm::vec3(99.0f, 99.0f, 99.0f))
			glfwSetWindowShouldClose(window, true);

		render(gameObjects);

		//buffer csere es polling
		glfwSwapBuffers(window);
		glfwPollEvents();

		//framehossz kiszamolasa
		endofFrame = glfwGetTime();
		deltaTime = endofFrame - startofFrame;
	}
}
void App::render(const std::vector<GameObject*>& gameObjects)
{
	//buffereket kitisztitja
	glClearColor(0.25, 0.45, 0.95, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//a matrixokat kiszamolja
	glm::mat4 view = dynamic_cast<Player*>(gameObjects.at(0))->getCamera().getView();
	glm::mat4 projection = glm::perspective(glm::radians(65.0f), static_cast<float>(WIDTH) / static_cast<float>(HEIGHT), 0.1f, 100.0f);
	//kirajzolja a dGameObjecteket
	for (size_t i = 1; i < gameObjects.size(); i++)
	{
		DrawableGameObject* dgo = dynamic_cast<DrawableGameObject*>(gameObjects.at(i));
		if (dgo != nullptr)
		{
			dgo->draw(view, projection);
		}
	}
}
void App::handleInput(Player& player)
{
	//kilepes
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	//player elore hatra mozgatasa
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		player.setVelocity(glm::vec3(player.getVelocity().x, player.getVelocity().y, 1));
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		player.setVelocity(glm::vec3(player.getVelocity().x, player.getVelocity().y, -1));
	else
		player.setVelocity(glm::vec3(player.getVelocity().x, player.getVelocity().y, 0));
	//player oldalra mozgatasa
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		player.setVelocity(glm::vec3(-1, player.getVelocity().y, player.getVelocity().z));
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		player.setVelocity(glm::vec3(1, player.getVelocity().y, player.getVelocity().z));
	else
		player.setVelocity(glm::vec3(0, player.getVelocity().y, player.getVelocity().z));
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && player.getJumpBool())
	{
		player.setVelocity(glm::vec3(player.getVelocity().x, 7, player.getVelocity().z));
		player.setJumpBool(false);
	}
}
void App::gameClose(std::vector<GameObject*>& gameObjects)
{
	//torli a gameobjecteket
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects.at(i);
	}
}