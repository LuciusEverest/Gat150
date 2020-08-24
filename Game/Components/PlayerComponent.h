#pragma once
#include "Components/Component.h"

namespace bleh
{
	class PlayerComponent : public Component
	{
	public:
		virtual void Create(void* data = nullptr) override;
		virtual void Destroy() override;
		virtual Object* Clone() const override { return new PlayerComponent{ *this }; }

		virtual void Update() override;
	};

}

