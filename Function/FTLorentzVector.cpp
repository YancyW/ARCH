#include "Function/FTLorentzVector.h"

bool TLV_compare_PT(const TLorentzVector &a, const TLorentzVector &b)
{
	return a.Pt() > b.Pt();
}
