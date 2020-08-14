#pragma once
#include "Core/Json.h"

namespace bleh
{
	class Object
	{
	public:
		virtual void Create(void* data = nullptr) = 0;
		virtual void Destroy() = 0;
		virtual void Read(const rapidjson::Value& value) {}
	};

}
