#pragma once
#ifndef ANALYSE_DETECTOR_H
#define ANALYSE_DETECTOR_H
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
#include "Class/DrawClass.h"
#include "Class/debug.h"
#include "AnalyseClass/AnalyseClass.h"
#include "AnalyseClass/Object.h"


//bool GetFinalState(CDraw &para, TClonesArray *branchJet      ,TClonesArray *branchElectron ,TClonesArray *branchMuon     ,TClonesArray *branchPhoton   ,TClonesArray *branchMissingET,TClonesArray *branchParticle ,MyPlots* plots,
//		std::vector<Jet*> & Vjet,std::vector<Jet*>& Vbjet,std::vector<Jet*>& Vcjet,std::vector<Jet*>& Vqjet,std::vector<Jet*>& Vtaujet, std::vector<Jet*>& Vtagjet,std::vector<Jet*>& Vuntagjet,
//		std::vector<Electron*>& Velec,std::vector<Muon*>& Vmuon,std::vector<Jet*>& Vtau,std::vector<Photon*>& Vphoton,std::vector<MissingET*>& Vmet, AnalyseClass &analyse);
bool GetFinalState_detector(CDraw &para, AnalyseClass &analyse, AObject &object, MyPlots* plots);

bool GetFinalState_detector_jet(CDraw &para, TClonesArray *branchJet, MyPlots *plots,std::vector<Jet*> &jet);
bool GetFinalState_detector_elec(CDraw &para, TClonesArray *branchElectron, MyPlots *plots,std::vector<Electron*> &elec);
bool GetFinalState_detector_muon(CDraw &para, TClonesArray *branchMuon, MyPlots *plots,std::vector<Muon*> &muon);
bool GetFinalState_detector_met(CDraw &para, TClonesArray *branchMissingET, MyPlots *plots,std::vector<MissingET*> &met);
bool GetFinalState_detector_jet_classify(CDraw &para, AnalyseClass& analyse, std::vector<Jet*> &jet,std::vector<Jet*> &bjet, std::vector<Jet*> &cjet, std::vector<Jet*> &qjet, std::vector<Jet*>& taujet, std::vector<Jet*> &untagjet, MyPlots *plots);
void GetFinalState_detector_pseudojet(TClonesArray *branchJet, std::vector<fastjet::PseudoJet> &jet);

#endif
