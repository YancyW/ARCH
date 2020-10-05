#include "Analyse/APhoton.h"
bool Photon_Isolate(CDraw &para, std::vector<fastjet::PseudoJet> &photon_candi, std::vector<fastjet::PseudoJet> &hadron)
{
	int num_a          = photon_candi.size();
	int num_had        = hadron.size();
	float R           = para.photon.photon.isolate_cone_photon;
	float R2          = para.photon.photon.isolate_coneR_had;
	float coef_a      = para.photon.ISOLATE_coef_phoeon;
	float coef_had    = para.photon.ISOLATE_coef_had;
	float remainder_a = para.photon.ISOLATE_remainder_photon;

	std::vector<fastjet::PseudoJet> photon;

	if(num_a==0||num_had==0){
		return(false);
	}

	for(int i=0;i<num_a;i++){
		float sumpt_a   = 0.0;
		float sumpt_had = 0.0;
		for(int j=0;j<num_had;j++){
			float Rij;
			Rij = photon_candi[i].delta_R(hadron[j]);
			if(Rij<R){
				sumpt_a = sumpt_a + hadron[j].pt();
			}
			if(Rij<R2){
				if(phad[j].pt() > ptmin){
					sumpt_had = sumpt_had + phad[j].pt(); 
				}
			}
		}
		if((sumpt_a < coef_a*photon_candi[i].pt()+remander_a)&&(sumpt_had<coef_had*photon_candi[i].pt())){
			photon.push_back(photon_candi[i])
		}
		else{
			hadron.push_back(photon_candi[i]);
		}

	}
	return(true);
}

