#include "pch.h"
#include "PhysicsSystem.h"
#include "ContactListener.h"

bool bleh::PhysicsSystem::Startup()
{
    b2Vec2 gravity{0.0f, 10.0f};
    m_world = new b2World{ gravity };
    m_contactListener = new ContactListener;
    m_world->SetContactListener(m_contactListener);

    return true;
}

void bleh::PhysicsSystem::Shutdown()
{
    delete m_world;
    m_world = nullptr;
    delete m_contactListener;
    m_contactListener = nullptr;
}

void bleh::PhysicsSystem::Update()
{
    float timeStep(1.0f / 60.0f);
    m_world->Step(timeStep, 8, 3);
}

b2Body* bleh::PhysicsSystem::CreateBody(const Vector2& position, float angle, const RigidBodyData& data, GameObject* gameObject)
{
    b2BodyDef bodyDef;

    Vector2 worldPosition = ScreenToWorld(position);

    bodyDef.type = (data.isDynamic) ? b2_dynamicBody : b2_staticBody;
    bodyDef.position.Set(worldPosition.x, worldPosition.y);
    bodyDef.angle = bleh::DegreesToRadians(angle);
    bodyDef.fixedRotation = data.lockAngle;
    b2Body* body = m_world->CreateBody(&bodyDef);

    Vector2 worldSize = ScreenToWorld(data.size);
    b2PolygonShape shape;
    shape.SetAsBox(worldSize.x, worldSize.y);

    b2FixtureDef fixtureDef;
    fixtureDef.density = data.density;
    fixtureDef.friction = data.friction;
    fixtureDef.restitution = data.restitution;
    fixtureDef.userData = gameObject;
    fixtureDef.shape = &shape;
    fixtureDef.isSensor = data.isSensor;

    body->CreateFixture(&fixtureDef);

    return body;
}

void bleh::PhysicsSystem::DestroyBody(b2Body* body)
{
    m_world->DestroyBody(body);
}
