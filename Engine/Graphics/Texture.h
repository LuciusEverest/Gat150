#pragma once
#include <Math\Vector2.h>
#include <Resources/Resource.h>
#include <string>
#include <SDL.h>

namespace bleh
{
	class Texture : public Resource
	{
	public:
		bool Create(const std::string& name, void* renderer) override;
		void Destroy() override;

		void Draw(const Vector2& postition, const Vector2& scale, float angle);
		Vector2 GetSize() const;

	protected:
		SDL_Texture* m_texture{ nullptr };
		SDL_Renderer* m_renderer{ nullptr };
	};
}
