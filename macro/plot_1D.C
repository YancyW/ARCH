#include "TCanvas.h"
#include "TDirectory.h"
#include "TF1.h"
#include "TFile.h"
#include "TFitter.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH2.h"
#include "TH2F.h"
#include "TH3.h"
#include "THStack.h"
#include "TImage.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TLine.h"
#include "TMath.h"
#include "TMatrix.h"
#include "TMatrixT.h"
#include "TMinuit.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TStyle.h"
#include "TTree.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <sstream>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string> 
#include <time.h> 
#include <vector>


void plot_1D(std::vector<std::string> input_name) {

	std::vector<std::string> filename;

	int num=input_name.size();
	for(int i=0;i<num;i++){
		filename.push_back(input_name[i] );
	}
	std::vector<TFile*> in_file;

	for(int i=0;i<filename.size();i++){
		TFile* in_file_tmp=new TFile(filename[i].c_str());
		in_file.push_back(in_file_tmp);
	}

	std::cout << "The file numbers are: " << std::endl;
    for(int i=0;i<filename.size();i++){
    	TTree *MyLCTuple=(TTree*)in_file[i]->Get("datatrain");

    	int nevent = MyLCTuple->GetEntries();
		std::cout << "      " << input_name[i] << " : " << nevent << std::endl;
    }

}
