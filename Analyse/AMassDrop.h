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
#include "fastjet/contribs/Nsubjettiness/Nsubjettiness.hh"
#include "fastjet/contribs/Nsubjettiness/Njettiness.hh"
#include "fastjet/contribs/Nsubjettiness/NjettinessPlugin.hh"

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "Function/Ffastjet.h"
#include "Function/Fdelphes.h"
#include "Analyse/ABTag.h"
#include "Analyse/Ajet_function.h"
#include "Class/DrawClass.h"


class ExRootResult;
class ExRootTreeReader;

using namespace fastjet;

bool  AMassDrop(CDraw &para, MyPlots *plots, fastjet::ClusterSequence &cs, fastjet::PseudoJet subjet, std::vector<fastjet::PseudoJet> Vbquark,std::vector<fastjet::PseudoJet> Vcquark,  fastjet::PseudoJet &tagjet);





