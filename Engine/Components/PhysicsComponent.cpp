#include "pch.h"
#include "PhysicsComponent.h"
#include "Objects/GameObject.h"

namespace bleh
{

	void PhysicsComponent::Create(void* data)
	{
		m_velocity = bleh::Vector2::forward * 100;
	}

	void PhysicsComponent::Destroy()
	{

	}

	void PhysicsComponent::Update()
	{
		m_velocity = m_velocity + m_force * m_owner->m_engine->GetTimer().DeltaTime();
		m_velocity = m_velocity * m_drag;
		m_owner->m_transform.position = m_owner->m_transform.position + m_velocity * m_owner->m_engine->GetTimer().DeltaTime();
	}

}