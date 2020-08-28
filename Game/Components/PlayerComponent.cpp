#include "pch.h"
#include "PlayerComponent.h"
#include "Components/PhysicsComponent.h"
#include <Components\AudioComponent.h>

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
		auto contacts = m_owner->GetContactsWithTag("Floor");
		bool onGround = !contacts.empty();

		bleh::Vector2 force{ 0, 0 };

		if (m_owner->m_engine->GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == bleh::InputSystem::eButtonState::HELD)
		{
			force.x = -200;
		}
		if (m_owner->m_engine->GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == bleh::InputSystem::eButtonState::HELD)
		{
			force.x = 200;
		}	
		if (m_owner->m_engine->GetSystem<bleh::InputSystem>()->GetButtonState(SDL_SCANCODE_SPACE) == bleh::InputSystem::eButtonState::PRESSED)
		{
			force.y = -1500;
			AudioComponent* audioComponent = m_owner->GetComponent<AudioComponent>();
			if (audioComponent)
			{
				audioComponent->Play();
			}
		}


		PhysicsComponent* component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->SetForce(force);
		}
		
		auto coinContacts = m_owner->GetContactsWithTag("Coin");
		for (auto contact : coinContacts)
		{
			contact->m_flags[GameObject::eFlags::DESTROY] = true;
		}
	}
}
