#include "Arecoil.h"
bool Analysis_Recoil(CDraw &para, MyPlots *plots,AObject& object){

	bool judge;
	if(para.signal.NUM_elec==2){
       judge=Analysis_Recoil_For_Special_Particles(para, plots, object.Velec);
	}

	if(para.signal.NUM_muon==2){
       judge=Analysis_Recoil_For_Special_Particles(para, plots, object.Vmuon);
	}

	if(para.signal.NUM_bjet==4){
       judge=Analysis_Recoil_For_Special_Particles(para, plots, object.Vcombine_jet2);
	}

	return(judge);
}
