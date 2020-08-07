#include "Graphics/Texture.h"
#include "Graphics/Renderer.h"

#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
#include <Resources/ResourceManager.h>
#include <Input\InputSystem.h>
#include <Math\Transform.h>

bleh::ResourceManger resourceManager;
bleh::Renderer renderer;
bleh::InputSystem inputSystem;

int main(int, char**)
{
	renderer.Startup();
	renderer.Create("GAT150", 800, 600);
	inputSystem.Startup();

	bleh::Texture* texture1 = resourceManager.Get<bleh::Texture>("sf2.png", &renderer);
	bleh::Texture* texture2 = resourceManager.Get<bleh::Texture>("sf2.png", &renderer);
	float angle{ 0 };
	bleh::Vector2 position{ 400, 300 };
	bleh::Vector2 position1{ 100, 300 };

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

		renderer.BeginFrame();
		inputSystem.Update();

		if (inputSystem.GetButtonState(SDL_SCANCODE_RIGHT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x - 5.0f;
			}
		if (inputSystem.GetButtonState(SDL_SCANCODE_LEFT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x + 5.0f;
			}
		
		if (inputSystem.GetButtonState(SDL_SCANCODE_D) == bleh::InputSystem::eButtonState::HELD)
			{
				position1.x = position1.x - 5.0f;
			}
		if (inputSystem.GetButtonState(SDL_SCANCODE_A) == bleh::InputSystem::eButtonState::HELD)
			{
				position1.x = position1.x + 5.0f;
			}
		
		if (inputSystem.GetButtonState(SDL_SCANCODE_DOWN) == bleh::InputSystem::eButtonState::HELD)
			{
				position.y = position.y - 5.0f;
			}
		if (inputSystem.GetButtonState(SDL_SCANCODE_UP) == bleh::InputSystem::eButtonState::HELD)
			{
				position.y = position.y + 5.0f;
			}
		
		if (inputSystem.GetButtonState(SDL_SCANCODE_S) == bleh::InputSystem::eButtonState::HELD)
			{
				position1.y = position1.y - 5.0f;
			}
		if (inputSystem.GetButtonState(SDL_SCANCODE_W) == bleh::InputSystem::eButtonState::HELD)
			{
				position1.y = position1.y + 5.0f;
			}

		//draw 
		angle = angle + 1;
		texture1->Draw(position, { 2, 2 }, angle);
		texture2->Draw(position1, { 2, 2 }, angle + angle);

		renderer.EndFrame();
	}

	inputSystem.Shutdown();
	renderer.Shutdown();
	SDL_Quit();

	return 0;
}
