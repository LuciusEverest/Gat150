#include "pch.h"
#include "Components/PhysicsComponent.h"
#include "Components/SpriteComponent.h"
#include "ObjectFactory.h"

namespace bleh
{
	void ObjectFactoryImpl::Initialize()
	{
		bleh::ObjectFactory::Instance().Register("GameObject", bleh::Object::Instantiate<bleh::GameObject>);
		bleh::ObjectFactory::Instance().Register("PhysicsComponent", bleh::Object::Instantiate<bleh::PhysicsComponent>);
		bleh::ObjectFactory::Instance().Register("SpriteComponent", bleh::Object::Instantiate<bleh::SpriteComponent>);

	}
}