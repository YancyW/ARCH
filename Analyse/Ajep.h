#pragma once

#include <iostream>
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

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "Analyse/Ajet_function.h"
#include "Class/DrawClass.h"


class ExRootResult;
class ExRootTreeReader;

bool JEP(CDraw &para, TH1 *hr, TH1 *hR, std::vector<fastjet::PseudoJet> jet_constituents, fastjet::PseudoJet input_jet, float *Phir, float *Phir_test, float coneR ,int nr);
float JEP_quark_1(float pt, int r);
float JEP_quark_2(float pt, int r);

