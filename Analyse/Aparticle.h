#pragma once
#ifndef ANALYSE_PARTICLE_H_
#define ANALYSE_PARTICLE_H
#include <string> 
#include <iostream>

#include "TH1.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TClonesArray.h"


#include "classes/DelphesClasses.h"

#include "ExRootTreeReader.h"
#include "ExRootResult.h"


#include "fastjet/PseudoJet.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/ClusterSequence.hh"

class ExRootResult;
class ExRootTreeReader;

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Function/Fclass.h"
#include "Function/Fvector.h"
#include "Analyse/Abasic.h"
#include "Analyse/Adetector.h"
#include "Analyse/Aequipment.h"
#include "Analyse/ABTag.h"
#include "Analyse/ALepton.h"
#include "Class/DrawClass.h"
#include "Class/debug.h"
#include "AnalyseClass/AnalyseClass.h"


bool GetFinalState_particle(CDraw &para, TClonesArray *branchParticle,MyPlots* plots,
		std::vector<fastjet::PseudoJet> & Vjet,
		std::vector<fastjet::PseudoJet> & bquark,
		std::vector<fastjet::PseudoJet> & cquark,
		std::vector<fastjet::PseudoJet> & Velec,
		std::vector<fastjet::PseudoJet> & Vmuon,
		std::vector<fastjet::PseudoJet> & Vphoton,
		std::vector<fastjet::PseudoJet> & Vmet,
		AnalyseClass &analyse);

bool GetGenParticle(CDraw &para, TClonesArray *branchParticle,std::vector<fastjet::PseudoJet> & Vjet);

bool Class_particle_by_PID(
		std::vector<fastjet::PseudoJet> &candi,
		std::vector<fastjet::PseudoJet> &elec_p, std::vector<fastjet::PseudoJet> &elec_m, 
		std::vector<fastjet::PseudoJet> &muon_p, std::vector<fastjet::PseudoJet> &muon_m, 
		std::vector<fastjet::PseudoJet> &tau_p,  std::vector<fastjet::PseudoJet> &tau_m, 
		fastjet::PseudoJet &missingET, 
		std::vector<fastjet::PseudoJet> &gamma,  
		std::vector<fastjet::PseudoJet> &heavyparticle,
		std::vector<fastjet::PseudoJet> &hadron);
#endif
