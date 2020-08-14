#include "pch.h"
#include "SpriteComponent.h"
#include "Graphics/Texture.h"

namespace bleh
{

	void SpriteComponent::Create(void* data)
	{
		m_texture = m_owner->m_engine->GetSystem<bleh::ResourceManger>()->Get<bleh::Texture>(m_textureName, m_owner->m_engine->GetSystem<Renderer>());
		ASSERT_MSG((m_texture != nullptr), "Error texture: " + m_textureName + " not loaded.");
	}

	void SpriteComponent::Destroy()
	{
	}

	void SpriteComponent::Read(const rapidjson::Value& value)
	{
		json::Get(value, "texture", m_textureName);
		json::Get(value, "rect", m_rect);
	}

	void SpriteComponent::Update()
	{
	}

	void SpriteComponent::Draw()
	{
		//{ 64, 110, 60, 112 }
		m_texture->Draw(m_rect, m_owner->m_transform.position, Vector2::one * m_owner->m_transform.scale, m_owner->m_transform.angle);
	}

}