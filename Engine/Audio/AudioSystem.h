#pragma once
#include "Core/System.h"
#include <fmod.hpp>

namespace bleh
{
	class AudioSystem : public System
	{
		virtual bool Startup() override;
		virtual void Shutdown() override;
		virtual void Update() override;

	public:

		friend class Sound;

	protected:
		FMOD::System* m_system{ nullptr };

	};
}
