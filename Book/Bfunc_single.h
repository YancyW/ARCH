#pragma once
#include <string> 
#include <iostream>

#include "TH1.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "THStack.h"
#include "TLegend.h"
#include "TClonesArray.h"


#include "classes/DelphesClasses.h"

#include "ExRootTreeReader.h"
#include "ExRootResult.h"


class ExRootResult;
class ExRootTreeReader;

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Class/DrawClass.h"
#include "Function/Fbasic.h"
//------------------------------------------------------------------------------

void BookH_single_number(ExRootResult *result, TH1 **h1, std::string signal_name, std::string class_name);

void BookH_single_observable(ExRootResult *result, TH1 **h2, int plotnum, std::string signal_name, std::string class_name, std::string observe_name, int bin, float low_limit, float high_limit);
void BookH_single_observable_test(ExRootResult *result, MyPlots *plots, int plotnum, std::string signal_name, std::string class_name, std::string observe_name, int bin, float low_limit, float high_limit);

void BookH_single_same_class(ExRootResult *result, TH1 **h3, int num, std::string signal_name, std::string class_name, std::string observe_name);

void PrintHistograms(ExRootResult *result, MyPlots *plots);

void BookH_single_observable_loop(CDraw &para, ExRootResult *result, MyPlots *plots,int plot_num,
		std::string filter_name, std::string class_name, 
		std::string observe_name,int observe_num);


