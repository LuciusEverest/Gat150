#include "Graphics/Texture.h"
#include "pch.h"
#include <Objects\GameObject.h>
#include "Components/PhysicsComponent.h"
#include "Components/SpriteComponent.h"

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

		quit = (engine.GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == bleh::InputSystem::eButtonState::PRESSED);

		//player controller
		/*if (inputSystem.GetButtonState(SDL_SCANCODE_RIGHT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x - 200.0f * timer.DeltaTime();
			}

		if (inputSystem.GetButtonState(SDL_SCANCODE_LEFT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x + 200.0f * timer.DeltaTime();
			}*/
		
		if (engine.GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == bleh::InputSystem::eButtonState::HELD)
			{
				player.m_transform.angle = player.m_transform.angle - 200.0f * engine.GetTimer().DeltaTime();
			}
		if (engine.GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == bleh::InputSystem::eButtonState::HELD)
			{
			player.m_transform.angle = player.m_transform.angle + 200.0f * engine.GetTimer().DeltaTime();
			}
		
		/*if (inputSystem.GetButtonState(SDL_SCANCODE_DOWN) == bleh::InputSystem::eButtonState::HELD)
			{
				position.y = position.y - 200.0f * timer.DeltaTime();
			}
		if (inputSystem.GetButtonState(SDL_SCANCODE_UP) == bleh::InputSystem::eButtonState::HELD)
			{
				position.y = position.y + 200.0f * timer.DeltaTime();
			}
		*/
		/*if (inputSystem.GetButtonState(SDL_SCANCODE_S) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x - 200.0f * timer.DeltaTime();
			}
		if (inputSystem.GetButtonState(SDL_SCANCODE_W) == bleh::InputSystem::eButtonState::HELD)
			{
				position.y = position.y + 200.0f * timer.DeltaTime();
			}*/

		bleh::Vector2 force{ 0,0 };
		if (engine.GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_W) == bleh::InputSystem::eButtonState::HELD)
		{
			force = bleh::Vector2::forward * 1000.0f;
		}
		force = bleh::Vector2::Rotate(force, bleh::DegreesToRadians(player.m_transform.angle));

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
