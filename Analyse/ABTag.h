#pragma once
#ifndef ANALYSE_BTAG_H
#define ANALYSE_BTAG_H
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
#include "Class/DrawClass.h"
#include "Class/Tag.h"



void ATagParticle(CDraw &para,TClonesArray *branchParticle, std::vector<fastjet::PseudoJet> &bquark, std::vector<fastjet::PseudoJet> &cquark);

bool ATagBJet(CDraw &para,std::vector<fastjet::PseudoJet> bquark, std::vector<fastjet::PseudoJet> cquark, fastjet::PseudoJet input_jet);

bool ATagCJet(CDraw &para,std::vector<fastjet::PseudoJet> bquark, std::vector<fastjet::PseudoJet> cquark, fastjet::PseudoJet input_jet);
#endif
