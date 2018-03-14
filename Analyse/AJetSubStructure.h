#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string> 
#include <complex>

#include "TCanvas.h"
#include "TChain.h"
#include "TH1.h"
#include "TH2.h"
#include "TClonesArray.h"
#include "TStyle.h"
#include "TSystem.h"

#include "classes/DelphesClasses.h"

#include "ExRootTreeReader.h"
#include "ExRootResult.h"

#include "fastjet/PseudoJet.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/tools/MassDropTagger.hh"
#include "fastjet/tools/Filter.hh"

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "Function/Ffastjet.h"
#include "Analyse/Ajet_function.h"
#include "Analyse/AMassDrop.h"
#include "Analyse/ANSubjettiness.h"
#include "Analyse/AHiggsTag.h"
#include "Analyse/Ajep.h"
#include "Class/DrawClass.h"


class ExRootResult;
class ExRootTreeReader;

using namespace fastjet;

bool AJetSubStructure(CDraw &para, MyPlots *plots,std::vector<Jet*> Vjet,
		std::vector<fastjet::PseudoJet> VPseudoJet, std::vector<fastjet::PseudoJet> Vbquark, std::vector<fastjet::PseudoJet> cquark, 
		std::vector<Jet*> Vbjet, std::vector<Jet*> Vcjet, std::vector<Jet*> Vqjet,std::vector<Electron*> Velec,std::vector<Muon*> Vmuon,
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2, std::vector<Electron*> &Vcombined_elec1, std::vector<Electron*> &Vcombined_elec2, 
		std::vector<Muon*> &Vcombined_muon1, std::vector<Muon*> &Vcombined_muon2,
		float *Phi_r, float *Phi_r_test, int nr,AnalyseClass& analyse);



bool AJetSubStructure_SingleJet(CDraw &para, MyPlots *plots,std::vector<fastjet::PseudoJet> VPseudoJet,std::vector<fastjet::PseudoJet> Vbquark,std::vector<fastjet::PseudoJet> Vcquark,
		float *Phi_r, float *Phi_r_test, int nr,AnalyseClass& analyse);
