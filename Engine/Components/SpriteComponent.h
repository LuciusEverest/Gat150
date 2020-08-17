#pragma once
#include "RenderComponent.h"

namespace bleh
{
	class SpriteComponent : public RenderComponent
	{
	public:
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;

		void Read(const rapidjson::Value& value) override;

		virtual void Update() override;
		virtual void Draw() override;

	protected:
		class Texture* m_texture{ nullptr };
		std::string m_textureName;
		SDL_Rect m_rect;
	};
}