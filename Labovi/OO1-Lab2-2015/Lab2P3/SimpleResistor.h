#ifndef _SIMPLE_RESISTOR_H_
#define _SIMPLE_RESISTOR_H_

#include "Resistor.h"

class SimpleResistor : public Resistor {
public:
	explicit SimpleResistor(res_type resistance = 1) :
		Resistor(resistance)
	{}

protected:
	void writeToStream(std::ostream& os) const override
	{
		os << getResistance();
	}
};

#endif
