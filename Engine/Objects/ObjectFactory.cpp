#include "pch.h"
#include "Components/PhysicsComponent.h"
#include "Components/SpriteComponent.h"
#include "ObjectFactory.h"
#include <Components\SpriteAnimationComponent.h>
#include <Components/RigidBodyComponent.h>
#include <Components\AudioComponent.h>

namespace bleh
{
	void ObjectFactoryImpl::Initialize()
	{
		bleh::ObjectFactory::Instance().Register("GameObject", new Creator<GameObject, Object>);
		bleh::ObjectFactory::Instance().Register("PhysicsComponent", new Creator<PhysicsComponent, Object>);
		bleh::ObjectFactory::Instance().Register("SpriteComponent", new Creator<SpriteComponent, Object>);
		bleh::ObjectFactory::Instance().Register("SpriteAnimationComponent", new Creator<SpriteAnimationComponent, Object>);
		bleh::ObjectFactory::Instance().Register("RigidBodyComponent", new Creator<RigidBodyComponent, Object>);
		bleh::ObjectFactory::Instance().Register("AudioComponent", new Creator<AudioComponent, Object>);

	}
}