#include "pch.h"
#include "PlayerComponent.h"
#include "Components/PhysicsComponent.h"

namespace bleh
{
	void PlayerComponent::Create(void* data)
	{

	}

	void PlayerComponent::Destroy()
	{

	}

	void PlayerComponent::Update()
	{
		//player controller
		/*if (inputSystem.GetButtonState(SDL_SCANCODE_RIGHT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x - 200.0f * timer.DeltaTime();
			}

		if (inputSystem.GetButtonState(SDL_SCANCODE_LEFT) == bleh::InputSystem::eButtonState::HELD)
			{
				position.x = position.x + 200.0f * timer.DeltaTime();
			}*/

		if (m_owner->m_engine->GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == bleh::InputSystem::eButtonState::HELD)
		{
			m_owner->m_transform.angle = m_owner->m_transform.angle - 200.0f * m_owner->m_engine->GetTimer().DeltaTime();
		}
		if (m_owner->m_engine->GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == bleh::InputSystem::eButtonState::HELD)
		{
			m_owner->m_transform.angle = m_owner->m_transform.angle + 200.0f * m_owner->m_engine->GetTimer().DeltaTime();
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
		if (m_owner->m_engine->GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_W) == bleh::InputSystem::eButtonState::HELD)
		{
			force = bleh::Vector2::forward * 1000.0f;
		}
		force = bleh::Vector2::Rotate(force, bleh::DegreesToRadians(m_owner->m_transform.angle));

		PhysicsComponent* component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->SetForce(force);
		}
	}
}
