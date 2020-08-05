#pragma once
#include <Math\Vector2.h>
#include <string>
#include <SDL.h>

namespace bleh
{
	class Texture
	{
	public:
		bool Create(const std::string& name, SDL_Renderer* renderer);
		void Destroy();

		void Draw(const Vector2& postition, const Vector2& scale, float angle);

		Vector2 GetSize() const;

	protected:
		SDL_Texture* m_texture{ nullptr };
		SDL_Renderer* m_renderer{ nullptr };
	};
}
