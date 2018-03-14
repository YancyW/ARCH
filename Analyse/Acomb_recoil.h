#pragma once
#ifndef ACOMB_RECOIL_H
#define ACOMB_RECOIL_H
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
#include "Acombine.h"
#include "Class/DrawClass.h"



bool Analysis_Combine_Recoil(CDraw &para, MyPlots *plots,std::vector<Jet*> Vjet,std::vector<Jet*> Vbjet, std::vector<Jet*> Vcjet, std::vector<Jet*> Vqjet, std::vector<Jet*> Vuntagjet, std::vector<Electron*> Velec,std::vector<Muon*> Vmuon, 
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2, std::vector<Electron*> &Vcombined_elec1, 
		std::vector<Electron*> &Vcombined_elec2, std::vector<Muon*> &Vcombined_muon1, std::vector<Muon*> &Vcombined_muon2);

bool Combine_Recoil_choosebest_same(CDraw &para, MyPlots *plots, std::vector<Jet*> particle1, std::vector<Jet*> particle2,float Icomb_mc, float Icomb_md, float Icomb_mu,float Irecoil_mc, float Irecoil_md, float Irecoil_mu,
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2);

bool Combine_Recoil_choosebest_diff(CDraw &para, MyPlots *plots, std::vector<Jet*> particle1, std::vector<Jet*> particle2,float Icomb_mc, float Icomb_md, float Icomb_mu,float Irecoil_mc, float Irecoil_md, float Irecoil_mu,
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2);

bool Combine_Recoil_direct(TLorentzVector mom1, TLorentzVector mom2,float Icomb1_mc, float Icomb_mbin,float Irecoil_mc, float Irecoil_mbin, float *Rcomb_m, float *Rrecoil_m);
#endif
