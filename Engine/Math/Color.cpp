#include "pch.h"
#include "Color.h"
#include <string>

namespace bleh
{
	Color const Color::white{ 1,1,1 };
	Color const Color::green{ 1,0,0 };
	Color const Color::red{ 0,1,0 };
	Color const Color::blue{ 0,0,1 };

    std::istream& operator >> (std::istream& stream, Color& c)
    {
		std::string line;
		std::getline(stream, line);

		//check if line begins with "{"
		if (line.find("{") != std::string::npos)
		{
			//r
			std::string cr = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
			c.r = std::stof(cr);
			
			line = line.substr(line.find(",") + 1, line.find("}") - line.find(","));

			//g
			std::string cg = line.substr(0, line.find(","));
			c.g = std::stof(cg);

			//b
			std::string cb = line.substr(line.find(",") + 1, line.find("}") - line.find(",") - 1);
			c.b = std::stof(cb);
		}

        return stream;
    }

	std::ostream& operator<<(std::ostream& stream, const Color& v)
	{
		stream << v.r << " " << v.b << " " << v.g << " " << v.a;

		return stream;
	}

}
