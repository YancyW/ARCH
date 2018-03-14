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
#include "Function/Fbasic.h"
#include "Book/Bfunc_single.h"
#include "Class/DrawClass.h"
//------------------------------------------------------------------------------

void BookHistograms_single(CDraw &para, ExRootResult *result, MyPlots *plots, std::string name);
