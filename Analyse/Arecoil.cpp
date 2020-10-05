#include "Arecoil.h"
bool Analysis_Recoil(CDraw &para, MyPlots *plots,std::vector<Jet*> Vjet,std::vector<Jet*> Vbjet,std::vector<Jet*> Vcjet, std::vector<Jet*> Vqjet,std::vector<Electron*> Velec,std::vector<Muon*> Vmuon,
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2, std::vector<Electron*> &Vcombined_elec1, std::vector<Electron*> &Vcombined_elec2, std::vector<Muon*> &Vcombined_muon1, std::vector<Muon*> &Vcombined_muon2){

	bool judge;
	if(para.signal.NUM_elec==2){
       judge=Analysis_Recoil(para, plots, Velec);
	}

	if(para.signal.NUM_muon==2){
       judge=Analysis_Recoil(para, plots, Vmuon);
	}

	if(para.signal.NUM_bjet==4){
       judge=Analysis_Recoil(para, plots, Vcombined_jet2);
	}

	return(judge);
}
