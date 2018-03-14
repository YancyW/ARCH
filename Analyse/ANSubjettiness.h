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
#include "fastjet/contribs/Nsubjettiness/Nsubjettiness.hh"
#include "fastjet/contribs/Nsubjettiness/Njettiness.hh"
#include "fastjet/contribs/Nsubjettiness/NjettinessPlugin.hh"

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "Function/Ffastjet.h"
#include "Analyse/Ajet_function.h"
#include "Class/DrawClass.h"
#include "Class/NSubjettiness.h"


class ExRootResult;
class ExRootTreeReader;

using namespace fastjet;

bool AGetNSubjettiness(CDraw &para, fastjet::PseudoJet &jet);
bool ANSubjettiness(int N, CDraw &para, const fastjet::contrib::AxesDefinition &axes, const fastjet::contrib::MeasureDefinition &measure, fastjet::PseudoJet &jet, float &tauN);
bool ANSubjettiness_ratio(int N, int M, CDraw &para, const fastjet::contrib::AxesDefinition &axes, const fastjet::contrib::MeasureDefinition &measure, fastjet::PseudoJet &jet, float &tauNM);


