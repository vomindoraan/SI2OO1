#pragma once

#include <exception>
#include <sstream>

class ZbirkaPuna : public std::exception {
public:
	ZbirkaPuna(/*int i = 0*/)
		: std::exception("Zbirka je puna")
		//, i_(i)
	{}

//	const char* what() const override
//	{
//		std::stringstream ss("Zbirka je puna: ");
//		ss << i_;
//		return ss.str().c_str();
//	}
//
//private:
//	int i_;
};