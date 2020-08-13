#include "Graphics/Texture.h"
#include "pch.h"
#include <Objects\GameObject.h>
#include "Components/PhysicsComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/PlayerComponent.h"
#include "Core/Json.h"

bleh::Engine engine;
bleh::GameObject player;

int main(int, char**)
{
	engine.Startup();

	player.Create(&engine);
	player.m_transform.position = { 400, 300 };
	player.m_transform.angle = 45;

	bleh::Component* component;
	component = new bleh::PhysicsComponent;
	player.AddComponent(component);
	component->Create();
	
	component = new bleh::SpriteComponent;
	player.AddComponent(component);
	component->Create();
	
	component = new bleh::PlayerComponent;
	player.AddComponent(component);
	component->Create();

	rapidjson::Document document;
	bleh::json::Load("json.txt", document);

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
	std::cout << color << std::endl;


	bleh::Texture* background = engine.GetSystem<bleh::ResourceManger>()->Get<bleh::Texture>("background.png", engine.GetSystem<bleh::Renderer>());

	bleh::Vector2 velocity{ 0, 0};

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
		player.Update();

		if (engine.GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == bleh::InputSystem::eButtonState::PRESSED)
		{
			quit = true;
		}

		//draw 
		engine.GetSystem<bleh::Renderer>()->BeginFrame();

		background->Draw({ 0, 0 });

		//player sprite draw
		player.Draw();

		engine.GetSystem<bleh::Renderer>()->EndFrame();
	}
	engine.Shutdown();

	return 0;
}
