#include "Graphics/Texture.h"
#include "Graphics/Renderer.h"
#include "pch.h"
#include "Core/Timer.h"

#include <SDL_image.h>
#include <Resources/ResourceManager.h>
#include <Input\InputSystem.h>
#include <Math\Transform.h>


bleh::ResourceManger resourceManager;
bleh::Renderer renderer;
bleh::InputSystem inputSystem;
bleh::FrameTimer timer;

int main(int, char**)
{

	/*bleh::Timer timer;
	for (size_t i = 0; i < 100; i++) { std::sqrt(rand() % 100); }

	std::cout << timer.ElapsedTicks() << std::endl;
	std::cout << timer.ElapsedTicks() << std::endl;*/

	renderer.Startup();
	renderer.Create("GAT150", 800, 600);
	inputSystem.Startup();

	bleh::Texture* background = resourceManager.Get<bleh::Texture>("background.png", &renderer);
	bleh::Texture* car = resourceManager.Get<bleh::Texture>("cars.png", &renderer);

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

		//update
		timer.Tick();
		resourceManager.Update();
		inputSystem.Update();

		quit = (inputSystem.GetButtonState(SDL_SCANCODE_ESCAPE) == bleh::InputSystem::eButtonState::PRESSED);

		/*if (inputSystem.GetButtonState(SDL_SCANCODE_RIGHT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x - 200.0f * timer.DeltaTime();
			}

		if (inputSystem.GetButtonState(SDL_SCANCODE_LEFT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x + 200.0f * timer.DeltaTime();
			}*/
		
		if (inputSystem.GetButtonState(SDL_SCANCODE_D) == bleh::InputSystem::eButtonState::HELD)
			{
				position1.x = position1.x - 200.0f * timer.DeltaTime();
			}
		if (inputSystem.GetButtonState(SDL_SCANCODE_A) == bleh::InputSystem::eButtonState::HELD)
			{
				position1.x = position1.x + 200.0f * timer.DeltaTime();
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
		if (inputSystem.GetButtonState(SDL_SCANCODE_S) == bleh::InputSystem::eButtonState::HELD)
			{
				position1.y = position1.y - 200.0f * timer.DeltaTime();
			}
		if (inputSystem.GetButtonState(SDL_SCANCODE_W) == bleh::InputSystem::eButtonState::HELD)
			{
				position1.y = position1.y + 200.0f * timer.DeltaTime();
			}

		//draw 
		renderer.BeginFrame();

		angle = angle + 90 * timer.DeltaTime();
		background->Draw({ 0, 0 });
		car->Draw({ 0, 16, 64, 144 }, position1);

		renderer.EndFrame();
	}

	inputSystem.Shutdown();
	renderer.Shutdown();
	SDL_Quit();

	return 0;
}
