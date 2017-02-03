#ifndef _SKLADISTE_H_
#define _SKLADISTE_H_

#include "Kupa.h"

class Skladiste {
public:
	Skladiste() : prvi_(nullptr), posl_(nullptr) {}

	Skladiste(const Skladiste& s) = delete;
	Skladiste(Skladiste&& s) { premesti(s); }
	~Skladiste() { brisi(); }

	Skladiste& operator=(const Skladiste& s) = delete;
	Skladiste& operator=(Skladiste&& s)
	{
		if (this != &s) {
			brisi();
			premesti(s);
		}
		return *this;
	}

	Skladiste& operator+=(const Kupa& k)
	{
		Elem *e = new Elem(k.kloniraj());
		if (prvi_ == nullptr) {
			prvi_ = e;
		} else {
			posl_->sled = e;
		}
		posl_ = e;
		return *this;
	}

	unsigned operator()(double v1, double v2) const;

	friend std::ostream& operator<<(std::ostream& os, const Skladiste& s);

private:
	struct Elem {
		Kupa* kupa;
		Elem* sled;
		Elem(Kupa* kupa, Elem* sled = nullptr) : kupa(kupa), sled(sled) {}
	};

	Elem* prvi_;
	Elem* posl_;

	void premesti(Skladiste& s)
	{
		prvi_ = s.prvi_;
		posl_ = s.posl_;
		s.prvi_ = s.posl_ = nullptr;
	}

	void brisi();
};

#endif // !_SKLADISTE_H_
