#pragma once
#include <string> 
#include <iostream>
#include "TH1.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
//#include "classes/DelphesClasses.h"
//#include "ExRootTreeReader.h"
//#include "ExRootResult.h"
#endif

#include "fastjet/ClusterSequence.hh"
#include "yaml-cpp/yaml.h"

//class ExRootResult;
//class ExRootTreeReader;
#include "Class/DrawClass.h"
#include "Lib/PlotSetting.h"
#include "Lib/MessageFormat.h"

void StartProcess();
void LoadFile(CDraw &para);
void LoadLibrary(CDraw &para);
void SetPlot();
void EndProcess();
