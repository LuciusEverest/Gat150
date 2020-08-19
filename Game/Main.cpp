#include "Graphics/Texture.h"
#include "pch.h"
#include <Objects\GameObject.h>
#include "Components/PlayerComponent.h"
#include "Core/Json.h"
#include "Core/Factory.h"
#include <Objects\ObjectFactory.h>
#include <Objects\Scene.h>

bleh::Engine engine;
bleh::Scene scene;

int main(int, char**)
{
	engine.Startup();
		
	bleh::ObjectFactory::Instance().Initialize();
	bleh::ObjectFactory::Instance().Register("PlayerComponent", bleh::Object::Instantiate<bleh::PlayerComponent>);
	
	scene.Create(&engine);

	rapidjson::Document document;
	bleh::json::Load("scene.txt", document);
	scene.Read(document);

	/*rapidjson::Document document;
	bleh::json::Load("player.txt", document);
	player->Read(document);

	bleh::Component* component;
	component = bleh::ObjectFactory::Instance().Create<bleh::Component>("PhysicsComponent");
	component->Create(player);
	player->AddComponent(component);
	
	component = bleh::ObjectFactory::Instance().Create<bleh::Component>("SpriteComponent");
	component->Create(player);
	bleh::json::Load("sprite.txt", document);
	component->Read(document);
	player->AddComponent(component);
	
	component = bleh::ObjectFactory::Instance().Create<bleh::Component>("PlayerComponent");
	component->Create(player);
	player->AddComponent(component);

	std::string str;
	bleh::json::Get(document, "string", str);
	std::cout << str << std::endl;

	bool b;
	bleh::json::Get(document, "boolean", b);
	std::cout << b << std::endl;

	int i1;
	bleh::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	bleh::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f;
	bleh::json::Get(document, "float", f);
	std::cout << f << std::endl;

	bleh::Vector2 v2;
	bleh::json::Get(document, "vector2", v2);
	std::cout << v2 << std::endl;

	bleh::Color color;
	bleh::json::Get(document, "color", color);
	std::cout << color << std::endl;*/

	//bleh::Texture* background = engine.GetSystem<bleh::ResourceManger>()->Get<bleh::Texture>("background.png", engine.GetSystem<bleh::Renderer>());

	//bleh::Vector2 velocity{ 0, 0};

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
	engine.Shutdown();
	scene.Destroy();

	return 0;
}
