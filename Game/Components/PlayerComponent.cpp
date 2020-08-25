#include "pch.h"
#include "PlayerComponent.h"
#include "Components/PhysicsComponent.h"

namespace bleh
{
	void PlayerComponent::Create(void* data)
	{
		m_owner = static_cast<GameObject*>(data);
	}

	void PlayerComponent::Destroy()
	{

	}

	void PlayerComponent::Update()
	{
		bleh::Vector2 force{ 0, 0 };

		if (m_owner->m_engine->GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == bleh::InputSystem::eButtonState::HELD)
		{
			force.x = -20000;
		}
		if (m_owner->m_engine->GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == bleh::InputSystem::eButtonState::HELD)
		{
			force.x = 20000;
		}	
		if (m_owner->m_engine->GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_W) == bleh::InputSystem::eButtonState::PRESSED)
		{
			force.y = -400000;
		}

		PhysicsComponent* component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->SetForce(force);
		}
	}
}
