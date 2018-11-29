#include "SahovskaTabla.h"

SahovskaTabla::SahovskaTabla(const SahovskaTabla& st)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			figure_[i][j] = st.figure_[i][j]->kloniraj();
		}
	}
}

SahovskaTabla::SahovskaTabla(SahovskaTabla&& st)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			figure_[i][j] = std::exchange(st.figure_[i][j], nullptr);
		}
	}
}

SahovskaTabla::~SahovskaTabla()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete figure_[i][j];
		}
	}
}

void swap(SahovskaTabla& st1, SahovskaTabla& st2)
{
	using std::swap;
	swap(st1.figure_, st2.figure_);
}

bool SahovskaTabla::operator()(const Polje& p1, const Polje& p2)
{
	auto*& fig1 = (*this)[p1];
	if (!fig1) return false;

	auto*& fig2 = (*this)[p2];
	if (fig2) {
		if (fig1->mozePojesti(*fig2)) {
			(*fig1)(p2);
			fig2 = std::exchange(fig1, nullptr); // fig2 = fig1; fig1 = nullptr;
			return true;
		}
		return false;
	} else {
		if (fig1->mozeSePomeriti(p2)) {
			(*fig1)(p2);
			fig2 = std::exchange(fig1, nullptr);
		}
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const SahovskaTabla& st)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (st.figure_[i][j]) {
				os << *st.figure_[i][j];
			} else {
				os << '_';
			}
			os << ' ';
		}
		os << '\n';
	}
	return os;
}
