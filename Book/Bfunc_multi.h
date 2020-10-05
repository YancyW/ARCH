#pragma once
#include <string> 
#include <vector> 
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
#include "Function/Fbasic.h"
#include "Class/DrawClass.h"
//------------------------------------------------------------------------------

void BookH_multi_observable(CDraw &para, ExRootResult *result, MyPlots *plots,int plot_num,std::string filter_name, std::string class_name, std::string observe_name, int observe_num, std::vector<std::string> sampledescrip);

void BookH_multi_observable_loop(CDraw &para, ExRootResult *result, MyPlots *plots,int plot_num,std::string filter_name, std::string class_name, std::string observe_name, int observe_num, std::vector<std::string> sampledescrip);
