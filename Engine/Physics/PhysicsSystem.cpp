#include "pch.h"
#include "PhysicsSystem.h"

bool bleh::PhysicsSystem::Startup()
{
    b2Vec2 gravity{0.0f, 150.0f};
    m_world = new b2World{ gravity };

    return true;
}

void bleh::PhysicsSystem::Shutdown()
{
    delete m_world;
    m_world = nullptr;
}

void bleh::PhysicsSystem::Update()
{
    float timeStep(1.0f / 60.0f);
    m_world->Step(timeStep, 8.0f, 3.0f);
}

b2Body* bleh::PhysicsSystem::CreateBody(const Vector2& position, const Vector2& size, float density, bool isDynamic)
{
    b2BodyDef bodyDef;

    bodyDef.type = (isDynamic) ? b2_dynamicBody : b2_staticBody;
    bodyDef.position.Set(position.x, position.y);
    b2Body* body = m_world->CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(size.x, size.y);

    body->CreateFixture(&shape, density);

    return body;

}

b2Body* bleh::PhysicsSystem::CreateBody(const Vector2& position, RigidBodyData data, GameObject* gameObject)
{
    b2BodyDef bodyDef;

    bodyDef.type = (data.isDynamic) ? b2_dynamicBody : b2_staticBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.fixedRotation = data.lockAngle;
    b2Body* body = m_world->CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(data.size.x, data.size.y);

    b2FixtureDef fixtureDef;
    fixtureDef.density = data.density;
    fixtureDef.friction = data.friction;
    fixtureDef.restitution = data.restitution;
    fixtureDef.shape = &shape;

    body->CreateFixture(&fixtureDef);

    return body;
}
