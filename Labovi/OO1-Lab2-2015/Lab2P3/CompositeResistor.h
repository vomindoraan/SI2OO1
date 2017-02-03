#ifndef _COMPOSITE_RESISTOR_H_
#define _COMPOSITE_RESISTOR_H_

#include "Resistor.h"

#include <cstddef>
#include <vector>

class CompositeResistor : public Resistor {
public:
	typedef std::vector<Resistor*>::size_type size_type;

	explicit CompositeResistor(size_type init_capacity = 10) :
		Resistor(0), capacity_(init_capacity)
	{
		components_.reserve(init_capacity);
	}
	
	CompositeResistor(const CompositeResistor&) = default;

	virtual bool addComponent(Resistor& comp) // parametar nije const
	{
		if (components_.size() == capacity_) {
			return false;
		}
		components_.push_back(&comp);
		updateResistance(comp);
		return true;
	}

	virtual bool operator+=(Resistor& res)
	{
		return addComponent(res);
	}

protected:
	virtual void updateResistance(Resistor& res) = 0;

	void writeToStream(std::ostream& os) const override
	{
		os << "(";
		for (auto pcomp : components_) {
			os << *pcomp;
			if (pcomp != components_.back()) {
				os << ",";
			}
		}
		os << ")";
	}

private:
	size_type capacity_;
	std::vector<Resistor*> components_;
};

#endif
