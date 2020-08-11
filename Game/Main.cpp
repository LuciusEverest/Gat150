#include "Graphics/Texture.h"
#include "Graphics/Renderer.h"
#include "pch.h"
#include "Core/Timer.h"

#include <SDL_image.h>
#include <Resources/ResourceManager.h>
#include <Input\InputSystem.h>
#include <Math\Transform.h>
#include <Math\Math.h>


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
	//bleh::Vector2 position1{ 100, 300 };
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
		timer.Tick();
		resourceManager.Update();
		inputSystem.Update();

		quit = (inputSystem.GetButtonState(SDL_SCANCODE_ESCAPE) == bleh::InputSystem::eButtonState::PRESSED);


		//player controller
		/*if (inputSystem.GetButtonState(SDL_SCANCODE_RIGHT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x - 200.0f * timer.DeltaTime();
			}

		if (inputSystem.GetButtonState(SDL_SCANCODE_LEFT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x + 200.0f * timer.DeltaTime();
			}*/
		
		if (inputSystem.GetButtonState(SDL_SCANCODE_A) == bleh::InputSystem::eButtonState::HELD)
			{
				angle = angle - 200.0f * timer.DeltaTime();
			}
		if (inputSystem.GetButtonState(SDL_SCANCODE_D) == bleh::InputSystem::eButtonState::HELD)
			{
				angle = angle + 200.0f * timer.DeltaTime();
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
		if (inputSystem.GetButtonState(SDL_SCANCODE_W) == bleh::InputSystem::eButtonState::HELD)
		{
			force = bleh::Vector2::forward * 1000.0f;
		}
		force = bleh::Vector2::Rotate(force, bleh::DegreesToRadians(angle));

		//physics
		velocity = velocity + force * timer.DeltaTime();
		velocity = velocity * 0.95f;
		position = position + velocity * timer.DeltaTime();

		//draw 
		renderer.BeginFrame();

		background->Draw({ 0, 0 });

		//player sprite draw
		car->Draw({ 64, 110, 60, 112 }, position, { 1, 1 }, angle);

		renderer.EndFrame();
	}

	inputSystem.Shutdown();
	renderer.Shutdown();
	SDL_Quit();

	return 0;
}
