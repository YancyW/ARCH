#pragma once
#ifndef ABASIC_H
#define ABASIC_H
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



class ExRootResult;
class ExRootTreeReader;

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Function/Fclass.h"
#include "Class/DrawClass.h"




//bool ABasicCut_Observable(float observable,bool cut_sign, float low_limit, float high_limit);


template <typename Fill_type>
void AFill_Plot(CDraw &para, TH1* plots, Fill_type data){
	if(para.flow.plot){
		plots->Fill(data);
	}
}


template <typename ACut_type>
bool ABasic_Cut(CDraw &para, ACut_type observable,bool cut_sign, ACut_type low_limit, ACut_type high_limit, int mode = 0){
	if(para.flow.cut){
		if(mode==0){
			if( cut_sign  && ( observable < low_limit || observable > high_limit)) {return(false);}
		}
		else if(mode==1){
			ACut_type abs_observable  = std::abs(observable);
			if( cut_sign  && ( abs_observable < low_limit || abs_observable > high_limit)) {return(false);}
		}
	}
	return(true);
}


template <typename ACut_obs_type, typename ACut_cut_type>
bool AKinematic_Cut(CDraw &para, ACut_obs_type observable,ACut_cut_type cut, int mode = 0){
	if(para.flow.cut){
		if(mode==0){
			if( cut.cut_sign  && ( observable < cut.low_limit || observable > cut.high_limit)) {return(false);}
		}
		else if(mode==1){
			ACut_obs_type abs_observable  = std::abs(observable);
			if( cut.cut_sign  && ( observable < cut.low_limit || observable > cut.high_limit)) {return(false);}
		}
	}
	return(true);
}
#endif
