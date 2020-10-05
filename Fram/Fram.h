#pragma once
#include <string> 
#include <iostream>

#include "TH1.h"
#include "TMath.h"
#include "TLine.h"
#include "TLatex.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TTree.h"

#include "classes/DelphesClasses.h"

#include "ExRootTreeReader.h"
#include "ExRootResult.h"

#include "Book/Book_single.h"
#include "Book/Book_multi.h"
#include "Analyse/Analyse.h"
#include "Analyse/Analyse.h"
#include "Class/DrawClass.h"
	
class ExRootResult;
class ExRootTreeReader;

void Fram(CDraw &para);
void Fillplot(CDraw &para, MyPlots *plot_ptr, ExRootResult *result, std::string sigfile, std::string sampledescrip);
void Fillplot_all(CDraw &para, MyPlots *plot_ptr, ExRootResult *result, std::vector<std::string> sigfile, std::vector<std::string> sampledescrip, Long64_t sample_num[]);
void Analyse_BasicInfo(CDraw &para, ExRootResult *result, std::string sigfile, std::string sampledescrip, Long64_t &sample_num);
