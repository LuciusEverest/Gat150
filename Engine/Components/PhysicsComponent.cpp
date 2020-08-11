#include "pch.h"
#include "PhysicsComponent.h"
#include "Objects/GameObject.h"

namespace bleh
{

	void PhysicsComponent::Create(void* data)
	{

	}

	void PhysicsComponent::Destroy()
	{

	}

	void PhysicsComponent::Update()
	{
		m_velocity = m_velocity + m_force; //* timer.DeltaTime();
		m_velocity = m_velocity * m_drag;
		m_owner->m_transform.position = m_owner->m_transform.position + m_velocity; //* timer.DeltaTime();
	}

}