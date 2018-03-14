#pragma once
#ifndef GLOBAL_PARA_LEPTON_DETECTOR_CUT
#define GLOBAL_PARA_LEPTON_DETECTOR_CUT
#include "TStyle.h"
class CLepton_Detector_Cut{
	public:
		float MinEnergyDepositByMomentum;
		float MaxEnergyDepositByMomentum;
		float MinEcalToHcalFraction;
		float MaxEcalToHcalFraction;
		float MinTrackEnergy;
		float MaxTrackEnergy;
        float MinEyoke; 
        float MaxEyoke;

		float MinD0;
		float MaxD0;
		float MinZ0;
		float MaxZ0;
		float MinR0;
		float MaxR0;
		float MinD0Sig;
		float MaxD0Sig;
		float MinZ0Sig;
		float MaxZ0Sig;
		float MinR0Sig;
		float MaxR0Sig;

		float cosConeAngle;
};
#endif
