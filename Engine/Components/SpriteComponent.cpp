#include "pch.h"
#include "SpriteComponent.h"
#include "Graphics/Texture.h"

namespace bleh
{

	void SpriteComponent::Create(void* data)
	{
		m_owner = static_cast<GameObject*>(data);

		//m_texture = m_owner->m_engine->GetSystem<bleh::ResourceManger>()->Get<bleh::Texture>(m_textureName, m_owner->m_engine->GetSystem<Renderer>());
		//ASSERT_MSG((m_texture != nullptr), "Error texture: " + m_textureName + " not loaded.");
	}

	void SpriteComponent::Destroy()
	{
	}

	void SpriteComponent::Read(const rapidjson::Value& value)
	{
		json::Get(value, "texture", m_textureName);
		json::Get(value, "origin", m_origin);
		json::Get(value, "rect", m_rect);
	}

	void SpriteComponent::Update()
	{
	}

	void SpriteComponent::Draw()
	{
		//{ 64, 110, 60, 112 }
		Texture* texture = m_owner->m_engine->GetSystem<bleh::ResourceManger>()->Get<bleh::Texture>(m_textureName, m_owner->m_engine->GetSystem<Renderer>());
		texture->Draw(m_rect, m_owner->m_transform.position, m_owner->m_transform.angle, Vector2::one * m_owner->m_transform.scale, m_origin, m_flip);
	}

}