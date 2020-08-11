#pragma once
#include "Object.h"
#include <Math\Transform.h>

namespace bleh
{
	class Component;

	class GameObject : public Object
	{
	public:
		// Inherited via Object
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;

		void Update();
		void Draw();

		template<typename T> 
		T* GetComponent()
		{
			T* result{ nullptr };

			for (auto component : m_components)
			{
				result = dynamic_cast<T*>(component);
				if (result) break;
			}

			return result;
		}

		void AddComponent(Component* component);
		void RemoveComponent(Component* component);
		void RemoveAllComponents();


	public:
		Transform m_transform;

	protected:
		std::vector<Component*> m_components;
	};

}