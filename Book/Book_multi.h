#pragma once
#include <vector> 
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
#include "Function/Fbasic.h"
#include "Book/Bfunc_multi.h"
#include "Class/DrawClass.h"
//------------------------------------------------------------------------------

void BookHistograms_multi(CDraw &para, ExRootResult *result, MyPlots *plots1, int num, std::vector<std::string> sampledescrip);
