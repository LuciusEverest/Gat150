#include "pch.h"
#include "Texture.h"
#include <Math\Transform.h>
#include <Graphics/Renderer.h>

bool bleh::Texture::Create(const std::string& name, void* renderer)
{   
	m_renderer = static_cast<Renderer*>(renderer)->m_renderer;

	SDL_Surface* surface = IMG_Load(name.c_str());
	if (surface == nullptr)
	{
		std::cout << "Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_FreeSurface(surface); //delete surface
	if (m_texture== nullptr)
	{
		std::cout << "Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true; 
}

void bleh::Texture::Destroy()
{
	SDL_DestroyTexture(m_texture);
}

void bleh::Texture::Draw(const Vector2& position, float angle, const Vector2& scale, const Vector2& origin, bool flip)
{
	Vector2 size = GetSize();
	size = size * scale;

	Vector2 newPosition = position - (size * origin);

	SDL_Rect rect;
	rect.x = static_cast<int>(newPosition.x);
	rect.y = static_cast<int>(newPosition.y);
	rect.w = static_cast<int>(size.x);
	rect.h = static_cast<int>(size.y);

	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &rect, angle, nullptr, (flip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void bleh::Texture::Draw(const SDL_Rect& source, const Vector2& position, float angle, const Vector2& scale, const Vector2& origin, bool flip)
{
	Vector2 size = { source.w, source.h };
	size = size * scale;

	Vector2 newPosition = position - (size * origin);

	SDL_Rect rect;
	rect.x = static_cast<int>(newPosition.x);
	rect.y = static_cast<int>(newPosition.y);
	rect.w = static_cast<int>(size.x);
	rect.h = static_cast<int>(size.y);

	SDL_RenderCopyEx(m_renderer, m_texture, &source, &rect, angle, nullptr, (flip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

bleh::Vector2 bleh::Texture::GetSize() const
{
	SDL_Point point;
	SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);

	return Vector2{ point.x, point.y };
}
