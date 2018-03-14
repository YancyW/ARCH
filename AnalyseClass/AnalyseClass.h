#pragma once
#ifndef ANALYSE_CLASS
#define ANALYSE_CLASS
#include "TTree.h"
#include "TChain.h"
#include "AnalyseClass/Counter.h"
#include "AnalyseClass/Stdhep.h"
#include "AnalyseClass/Slcio.h"
#include "AnalyseClass/Delphes.h"
#include "AnalyseClass/Variable.h"
class AnalyseClass{
	private:
		bool               IsRecord     ;
		bool               IsBDTTrain   ;
	public:
		ACounter           counter      ;
		AStdhep            stdhep       ;
		ASlcio             slcio        ;
		ADelphes           delphes      ;
		AVariable          var          ;

    	TFile*             otfile       ;
    	TTree*             datatrain    ;
    	TTree*             datatest     ;
    	float              out_weight   ;

    	AnalyseClass(CDraw &para, ExRootTreeReader* treeReader, TChain* tree){
    		para.debug.Message(2,91,"in AnalyseClass::AnalyseClass begin init");
    		Init(para,treeReader,tree);
    		para.debug.Message(2,91,"in AnalyseClass::AnalyseClass end init");
    	}

    	~AnalyseClass(){
    		counter.Clear();
    		stdhep.Clear();
    		slcio.Clear();
    		delphes.Clear();
    	    if(IsRecord){
    	    	otfile->cd();
    	    	datatrain->Write();
    	    	if(IsBDTTrain){
    	    		datatest->Write();
    	    	}
    	    	otfile->Close();
    	    }
		}

		void Init(CDraw &para, ExRootTreeReader* treeReader, TChain* tree);
};
#endif
