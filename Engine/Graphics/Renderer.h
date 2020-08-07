#pragma once
#include "Core/System.h"

namespace bleh
{
	class Renderer : public System
	{
	public:
		// Inherited via System
		virtual bool Startup() override;
		virtual void Shutdown() override;
		virtual void Update() override;

		bool Create(const std::string& name, int width, int height);
		void BeginFrame();
		void EndFrame();

		friend class Texture;

	protected:
		SDL_Window* m_window{ nullptr };
		SDL_Renderer* m_renderer{ nullptr };
	};
}