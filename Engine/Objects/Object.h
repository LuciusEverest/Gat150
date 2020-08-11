#pragma once

namespace bleh
{
	class Object
	{
	public:
		virtual void Create(void* data = nullptr) = 0;
		virtual void Destroy() = 0;
	};

}
