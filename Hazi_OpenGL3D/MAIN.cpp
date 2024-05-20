#include <iostream>

#include "APP.hpp"
#include "SHADER.hpp"
#include "DRAWABLEGAMEOBJECT.hpp"
#include "gtest_lite.h"

#define CPORTA

using std::endl;
using std::cout;

int main()
{
#ifdef CPORTA

	std::vector<GameObject*> go;

	Player player(glm::vec3(0.0f, 0.0f, 0.0f), 10.0f);

	TEST("Shader letrehozasa", "hibas; hibamentes")
	{

		//EXPECT_NO_THROW(Shader s1 = Shader()) << "Nem dobhat kivetelt" << endl;
		//EXPECT_THROW(Shader s2 = Shader("asd", "dsa"), const char*) << "Kivetelt varok" << endl;
	}
	END

		TEST("Textura letrehozasa", "ures; hibas; hibamentes")
	{
		EXPECT_NO_THROW(Texture t1 = Texture()) << "ures textura" << endl;
		EXPECT_THROW(Texture t2 = Texture("grasss.png"), const char*) << "nincs ilyen textura" << endl;
		EXPECT_NO_THROW(Texture t3 = Texture("grass.png")) << "nem dobhat kivetelt, mert van ilyen textura" << endl;
	}
	END

		player.setVelocity(glm::vec3(0.0f, 0.0f, 1.0f));
	player.move(1.0f);
	TEST("Egyszer elore", "Player mozgatasa")
	{
		EXPECT_EQ(10.0f, player.getPosition().z) << "Nem jó helyen van a player";
	}
	END
		player.setVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
	player.setPosition(glm::vec3(2.0f, 0.0f, -2.0f));
	TEST("ESES", "Gravitacio hatasa")
	{
		player.applyPhysics(1.0f, go);
		EXPECT_EQ(-2 * 9.81f, player.getVelocity().y) << "Nem jó a fuggoleges sebesseg";
	}
	END

		TEST("Interakcio a player es egy drawablegameobject kozott", "Fizika hatasa a 2mp után")
	{
		go.push_back(new DrawableGameObject("DEFAULT.vert", "DEFAULT.frag", "grass.png", "go0", glm::vec3(0.0f, 0.0f, 0.0f)));
		go.push_back(new DrawableGameObject("DEFAULT.vert", "DEFAULT.frag", "grass.png", "go0", glm::vec3(0.0f, -20.0f, 0.0f)));
		for (size_t i = 0; i < 2000; i++)
		{
			player.move(0.001f);
			player.applyPhysics(0.001f, go);
		}
		EXPECT_EQ(-18.0f, glm::round(player.getPosition().y)) << "Nincs jó helyen, mert hibas az utkozes erzekeles" << endl;
		EXPECT_EQ(0.0f, player.getVelocity().y) << "Nem jo a fuggoleges sebesseg, mert hibas az utkozes erzekeles" << endl;
	}
	END
		TEST("Cel elerese", "Elerte a celt")
	{
		glm::vec3 finishGOPos = go.at(go.size() - 1)->getPosition();
		finishGOPos.y++;
		go.at(go.size() - 1)->setPosition(finishGOPos);
		finishGOPos.y++;
		player.setPosition(finishGOPos);
		player.applyPhysics(0.01f, go);
		EXPECT_EQ(99.0f, go.at(go.size() - 1)->getPosition().x)<<"Nem erte el a celt, mert nem allitodik be jo helyre a cel"<<endl;
	}
	END

	for (size_t i = 0; i < go.size(); i++)
	{
		delete go.at(i);
	}
#else
	App app(1280, 720, "Opengl nagyhazi");
	try {
		app.init();
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}
	app.run();
	app.close();
#endif // !CPORTA




	return 0;
}