#pragma once
#include <string>
#include <list>
#include "Object.h"

namespace bleh
{
	class Engine;
	class GameObject;

	class Scene : public Object
	{
	public:
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;

		void Read(const rapidjson::Value& value) override;

		void Update() override;
		void Draw();

		GameObject* Find(const std::string& name);

		void AddGameObject(GameObject* gameObject);
		void RemoveGameObject(GameObject* gameObject);
		void RemoveAllGameObjects();

		void ReadGameObjects(const rapidjson::Value& value);

	protected:
		Engine* m_engine{ nullptr };
		std::list<GameObject*> m_gameObjects;
	};

}