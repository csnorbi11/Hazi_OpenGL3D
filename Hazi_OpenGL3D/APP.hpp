#ifndef APP_H
#define APP_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "PLAYER.hpp"

class App {
	GLFWwindow* window;
	const unsigned int WIDTH;
	const unsigned int HEIGHT;
	const char* title;
	float deltaTime;
	float startofFrame;
	float endofFrame;



public:

	/**
	 * Parameter nelkuli kontstruktor
	 * 
	 */
	App()
		:
		window(nullptr),
		WIDTH(800),
		HEIGHT(600),
		title("OpenGL"),
		deltaTime(0),
		startofFrame(0),
		endofFrame(0)
	{}
	/**
	 * Parameteres konstruktor
	 * 
	 * \param w ablak szelessege
	 * \param h ablak magassaga
	 * \param t ablak neve
	 */
	App(const unsigned int w, const unsigned int h, const char* t)
		:
		window(nullptr),
		WIDTH(w),
		HEIGHT(h),
		title(t),
		deltaTime(0),
		startofFrame(0),
		endofFrame(0)
	{}

	/**
	 * Inicializálja GLFW-t és megadja a kontextust az OPENGL-nek.
	 * Létrehozza az ablakot.
	 * GLAD kinyeri a grafikus illesztõprogramból a funkciókat az OPENGL-nek
	 * Bekapcsolja a mélységi tesztet és beállítja az egér figyelését az ablakra
	 */
	void init();
	/**
	 * Meghívja a GameInit function, ami inicializálja és létrehozza az adott pályára a GameObjecteket, Materialokat
	 * Meghívja a GameLoopot a GameInit után
	 * 
	 */
	void run();
	void close();

private:
	/**
	 * Elokeszeti a palyan levo GameObjecteket.
	 * 
	 * \param gameObjects
	 */
	void gameInit(std::vector<GameObject*>& gameObjects);
	/**
	 * Ez maga a jatek futasa, ami egeszen addig fut, amig vege nem lesz.
	 * 
	 * \param gameObjects
	 */
	void gameLoop(std::vector<GameObject*>& gameObjects);
	/**
	 * Render fazis.
	 * 
	 * \param gameObjectsToRender
	 */
	void render(const std::vector<GameObject*>& gameObjectsToRender);
	/**
	 * Bemenetet kezeli le.
	 * 
	 * \param player
	 */
	void handleInput(Player& player);
	/**
	 * A jatekhoz szukseges dinamikus memoriat felszabaditja.
	 * 
	 * \param gameObjects
	 */
	void gameClose(std::vector<GameObject*>& gameObjects);

};


#endif // !APP_H
