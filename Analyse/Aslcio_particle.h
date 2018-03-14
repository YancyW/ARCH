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
#include "Class/Event.h"
#include "Class/debug.h"
#include "Class/lepton.h"
#include "AnalyseClass/Object.h"
#include "AnalyseClass/Pool.h"
#include "Analyse/Acomb_recoil.h"

bool GetFinalState(CDraw &para, AnalyseClass &analyse, AObject &object, MyPlots* plots);
bool Combine_Recoil(CDraw &para, AnalyseClass &analyse, AParticleType par1, AParticleType par2, MyPlots* plots, CCombine_cut comb_cut, CRecoil_cut recoil_cut, int choosed1, int choosed2);
#endif
