#pragma once
#include "Object.h"
#include <Math\Transform.h>
#include <Engine.h>

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
		T* GetComponent();

		void AddComponent(Component* component);
		void RemoveComponent(Component* component);
		void RemoveAllComponents();

		void Read(const rapidjson::Value& value) override;

	public:
		std::string m_name;
		Transform m_transform;
		Engine* m_engine{ nullptr };

	protected:
		std::vector<Component*> m_components;
	};

	template<typename T>
	T* GameObject::GetComponent()
	{
		T* result{ nullptr };

		for (auto component : m_components)
		{
			result = dynamic_cast<T*>(component);
			if (result) break;
		}

		return result;
	}
}