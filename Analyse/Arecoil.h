#pragma once
#include <string> 
#include <iostream>
#include <vector>

#include "TH1.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TClonesArray.h"


#include "classes/DelphesClasses.h"

#include "ExRootTreeReader.h"
#include "ExRootResult.h"


class ExRootResult;
class ExRootTreeReader;

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Class/DrawClass.h"



bool Analysis_Recoil(CDraw &para, MyPlots *plots,std::vector<Jet*> Vjet,std::vector<Jet*> Vbjet,std::vector<Jet*> Vcjet, std::vector<Jet*> Vqjet,std::vector<Electron*> Velec,std::vector<Muon*> Vmuon,
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2, std::vector<Electron*> &Vcombined_elec1, std::vector<Electron*> &Vcombined_elec2, std::vector<Muon*> &Vcombined_muon1, std::vector<Muon*> &Vcombined_muon2);

template<typename TRecoil>
bool Analysis_Recoil(CDraw &para, MyPlots *plots, TRecoil particle){

		float Irecoilcut_min,Irecoilcut_max;
		Irecoilcut_min=para.recoil.jets.CUT_massd[0];
		Irecoilcut_max=para.recoil.jets.CUT_massu[0];

	TLorentzVector collider(0,0,0,250);
	TLorentzVector fermion(0,0,0,0);

	if(particle.size()>0){
		for(int num=0;num<particle.size();num++){
			fermion+=particle.at(num)->P4();
		}
	}

	float mass=(collider-fermion).M();
	if(mass>Irecoilcut_min && mass<=Irecoilcut_max){
		plots->frecoilmass->Fill(mass);
		return(true);
	}
	return(false);
}
