#pragma once
#ifndef ANALYSE_ALEPTON_H 
#define ANALYSE_ALEPTON_H 
#include <string> 
#include <iostream>

#include "TH1.h"
#include "TSystem.h"
#include "TStyle.h"


#include "classes/DelphesClasses.h"
#include "ExRootTreeReader.h"
#include "ExRootResult.h"


class ExRootResult;
class ExRootTreeReader;

#include "Lib/MessageFormat.h"
#include "Function/Fvector.h"
#include "Class/DrawClass.h"
#include "Class/debug.h"
#include "Lib/libstructure.h"
//------------------------------------------------------------------------------
bool Lepton_Isolate(CDraw &para, std::vector<fastjet::PseudoJet> &lep_candi, std::vector<fastjet::PseudoJet> &hadron);
bool GetFinalState_particle(CDraw &para,std::vector<fastjet::PseudoJet> plus, std::vector<fastjet::PseudoJet> minus, MyPlots* plots,std::vector<fastjet::PseudoJet> &Vlepton);
#endif
