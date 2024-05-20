#ifndef PLAYER_H
#define PLAYER_H
#include "GAMEOBJECT.hpp"
#include <vector>

class Player : public GameObject {
	static Camera camera;
	glm::vec3 frontVelocity;
	glm::vec3 rightVelocity;
	bool readyToJump;

	static double lastX, lastY;

public:
	/**
	 * Parameter nelkuli konstruktor.
	 * 
	 */
	Player()
		:
		GameObject("Player"),
		frontVelocity(glm::vec3(0.0f, 0.0f, 0.0f)),
		rightVelocity(glm::vec3(0.0f, 0.0f, 0.0f)),
		readyToJump(false)
	{}
	/**
	 * Parameteres konstruktor.
	 * 
	 * \param p - pozicio
	 * \param moveS - sebesseg
	 */
	Player(glm::vec3 p, float moveS = 1.0f)
		:
		GameObject("Player",p,moveS),
		frontVelocity(glm::vec3(0.0f, 0.0f, 0.0f)),
		rightVelocity(glm::vec3(0.0f, 0.0f, 0.0f)),
		readyToJump(false)
	{}
	~Player(){}

	/**
	 * fizikat alkalmazza.
	 * 
	 * \param deltaTime - kepkocka idotartama
	 * \param go - gameobject tomb
	 */
	void applyPhysics(float deltaTime, std::vector<GameObject*>& go);
	/**
	 * mozgato metodus.
	 * 
	 * \param deltaTime - kepkocka idotartama
	 */
	void move(float deltaTime);
	/**
	 * getterek setterek.
	 * 
	 * \param newPos
	 */
	void setPosition(glm::vec3 newPos);
	void setJumpBool(bool ready);
	bool getJumpBool();
	Camera getCamera() const;
	static void setCameraPos(glm::vec3 pos);
	
	/**
	 * Callback fuggveny a curzor poziciojahoz.
	 * 
	 * \param window - ablak
	 * \param xposIn - x koordinata
	 * \param yposIn - y koordinata
	 */
	static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);

};
#endif