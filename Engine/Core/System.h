#pragma once

namespace bleh
{
	class System
	{
	public:
		virtual bool Startup() = 0;
		virtual void Shutdown() = 0;
		virtual void Update() = 0;
	};
 }
