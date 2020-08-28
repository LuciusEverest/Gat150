#include "Graphics/Texture.h"
#include "pch.h"
#include <Objects\GameObject.h>
#include "Components/PlayerComponent.h"
#include "Core/Json.h"
#include "Core/Factory.h"
#include <Objects\ObjectFactory.h>
#include <Objects\Scene.h>
#include "TileMap.h"

bleh::Engine engine;
bleh::Scene scene;

int main(int, char**)
{
	engine.Startup();
		
	bleh::ObjectFactory::Instance().Initialize();
	bleh::ObjectFactory::Instance().Register("PlayerComponent", new bleh::Creator<bleh::PlayerComponent, bleh::Object>);
	
	scene.Create(&engine);

	rapidjson::Document document;
	bleh::json::Load("scene.txt", document);
	scene.Read(document);

	bleh::json::Load("tileMap.txt", document);
	bleh::TileMap tileMap;
	tileMap.Read(document);
	tileMap.Create(&scene);

	//for (size_t i = 0; i < 10; i++)
	//{
	//	bleh::GameObject* gameObject = bleh::ObjectFactory::Instance().Create<bleh::GameObject>("ProtoCoin");
	//	gameObject->m_transform.position = { bleh::random(0, 800), bleh::random(300, 500) };
	//	//gameObject->m_transform.angle = bleh::random(0, 360);

	//	scene.AddGameObject(gameObject);
	//}

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		//update
		engine.Update();
		scene.Update();

		if (engine.GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == bleh::InputSystem::eButtonState::PRESSED)
		{
			quit = true;
		}

		//draw 
		engine.GetSystem<bleh::Renderer>()->BeginFrame();

		scene.Draw();

		engine.GetSystem<bleh::Renderer>()->EndFrame();
	}
	scene.Destroy();

	engine.Shutdown();

	return 0;
}
