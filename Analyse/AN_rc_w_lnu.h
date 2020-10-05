#pragma once
#ifndef AN_RC_W_LNU_H 
#define AN_RC_W_LNU_H 
#include <string> 
#include <iostream>
#include <vector>

#include "TH1.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TClonesArray.h"
#include "TLorentzVector.h"


#include "classes/DelphesClasses.h"

#include "ExRootTreeReader.h"
#include "ExRootResult.h"


class ExRootResult;
class ExRootTreeReader;

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "Function/Fvector.h"
#include "Class/DrawClass.h"
#include "AnalyseClass/AnalyseClass.h"

bool AN_RC_w_lnu(float wmass, float mw_d, float mw_u, TLorentzVector& Vlep, MissingET* Vmet, TLorentzVector &re_w, TLorentzVector &re_nu);
bool AN_RC_lnu(float re_mass, TLorentzVector &plepton, TLorentzVector &pneutrino, TLorentzVector &re_w, TLorentzVector &re_nu);

#endif


