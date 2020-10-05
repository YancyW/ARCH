#include "Class/Detector.h"
void CDetector::Cal_Pol(){
	pol.clear();
	float elecm=(1 - elec_pol)/2;
	float elecp=(1 + elec_pol)/2;
	float posim=(1 - posi_pol)/2;
	float posip=(1 + posi_pol)/2;
	pol.push_back( elecm * posip * lumi);
	pol.push_back( elecp * posim * lumi);
	pol.push_back( elecm * posim * lumi);
	pol.push_back( elecp * posip * lumi);
}
