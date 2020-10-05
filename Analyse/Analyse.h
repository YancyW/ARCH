#pragma once
#include <string> 
#include <iostream>

#include "TH1.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TClonesArray.h"
#include "TTree.h"


#include "classes/DelphesClasses.h"

#include "ExRootTreeReader.h"
#include "ExRootResult.h"


class ExRootResult;
class ExRootTreeReader;

#include "Lib/PlotSetting.h"
#include "Lib/MessageFormat.h"
#include "Analyse/Abasic.h"
#include "Analyse/Aparticle.h"
#include "Analyse/Adetector.h"
#include "Analyse/Aequipment.h"
#include "Analyse/Acombine.h"
#include "Analyse/Ajep.h"
#include "Analyse/AJetSubStructure.h"
#include "Analyse/Aslcio_particle.h"
#include "Function/Fvector.h"
#include "Class/DrawClass.h"
#include "Class/debug.h"
#include "AnalyseClass/Object.h"
#include "AnalyseClass/Particle.h"
#include "AnalyseClass/Counter.h"
//------------------------------------------------------------------------------
void AnalyseEvents(CDraw &para, ExRootTreeReader *treeReader, TChain* tree, MyPlots *plots);


