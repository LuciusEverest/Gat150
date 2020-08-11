#pragma once
#include "Objects/GameObject.h"

namespace bleh
{
	class GameObject;

	class Component : public Object
	{
	public: 
		virtual void Update() = 0;

		friend class GameObject;

	protected:
		GameObject* m_owner{ nullptr };
	};
}
