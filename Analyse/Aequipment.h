#pragma once
#ifndef ANALYSE_EQUIPMENT_H
#define ANALYSE_EQUIPMENT_H
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
#include "Analyse/Abasic.h"
#include "Analyse/Adetector.h"
#include "Analyse/ABTag.h"
#include "Class/DrawClass.h"
#include "Class/debug.h"
#include "AnalyseClass/AnalyseClass.h"


bool GetFinalState(CDraw &para, TClonesArray *branchEFlowTrack,	TClonesArray *branchEFlowNeutralHadron,	TClonesArray *branchEFlowPhoton,TClonesArray *branchElectron ,TClonesArray *branchMuon, TClonesArray *branchMissingET,MyPlots* plots,
		TClonesArray *branchParticle,
		std::vector<fastjet::PseudoJet> & Vjet,
		std::vector<fastjet::PseudoJet> & bquark,
		std::vector<fastjet::PseudoJet> & cquark,
		std::vector<Electron*>& Velec,std::vector<Muon*>& Vmuon,std::vector<Photon*>& Vphoton,std::vector<MissingET*>& Vmet, AnalyseClass &analyse);

void GetFinalState_equipment(CDraw &para,TClonesArray *branchEFlowNeutralHadron,TClonesArray *branchEFlowTrack, TClonesArray *branchEFlowPhoton, TClonesArray *branchElectron, TClonesArray *branchMuon, std::vector<fastjet::PseudoJet> &jet_candi);
bool GetFinalState_cut(CDraw &para, std::vector<fastjet::PseudoJet> &input_jet, MyPlots *plots,std::vector<fastjet::PseudoJet> &jet);

#endif
