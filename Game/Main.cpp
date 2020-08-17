#include "Graphics/Texture.h"
#include "pch.h"
#include <Objects\GameObject.h>
#include "Components/PhysicsComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/PlayerComponent.h"
#include "Core/Json.h"
#include "Core/Factory.h"

bleh::Engine engine;

bleh::Factory<bleh::Object, std::string> objectFactory;

int main(int, char**)
{
	engine.Startup();

	objectFactory.Register("GameObject", bleh::Object::Instantiate<bleh::GameObject>);
	objectFactory.Register("PhysicsComponent", bleh::Object::Instantiate<bleh::PhysicsComponent>);
	objectFactory.Register("SpriteComponent", bleh::Object::Instantiate<bleh::SpriteComponent>);
	objectFactory.Register("PlayerComponent", bleh::Object::Instantiate<bleh::PlayerComponent>);

	bleh::GameObject* player = objectFactory.Create<bleh::GameObject>("GameObject");
	
	player->Create(&engine);

	rapidjson::Document document;
	bleh::json::Load("player.txt", document);
	player->Read(document);

	bleh::Component* component;
	component = objectFactory.Create<bleh::Component>("PhysicsComponent");
	player->AddComponent(component);
	component->Create();
	
	component = objectFactory.Create<bleh::Component>("SpriteComponent");
	player->AddComponent(component);
	bleh::json::Load("sprite.txt", document);
	component->Read(document);
	component->Create();
	
	component = objectFactory.Create<bleh::Component>("PlayerComponent");
	player->AddComponent(component);
	component->Create();

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
		player->Update();

		if (engine.GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == bleh::InputSystem::eButtonState::PRESSED)
		{
			quit = true;
		}

		//draw 
		engine.GetSystem<bleh::Renderer>()->BeginFrame();

		background->Draw({ 0, 0 });

		//player sprite draw
		player->Draw();

		engine.GetSystem<bleh::Renderer>()->EndFrame();
	}
	engine.Shutdown();

	return 0;
}
