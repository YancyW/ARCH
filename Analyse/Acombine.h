#pragma once
#ifndef ACOMBINE_H 
#define ACOMBINE_H 
#include <string> 
#include <iostream>
#include <vector>

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
#include "Function/Fbasic.h"
#include "Function/Fvector.h"
#include "Class/DrawClass.h"
#include "AnalyseClass/AnalyseClass.h"
#include "AnalyseClass/Object.h"

#include "Analyse/Arecoil.h"
#include "Analyse/Abasic.h"
#include "Analyse/Acomb_recoil.h"
#include "Analyse/AN_rc_w_lnu.h"

bool GetCombine(CDraw &para,MyPlots* plots,AObject &object, AnalyseClass &analyse);

bool Combine2_direct(TLorentzVector mom1, TLorentzVector mom2,float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, float *mass_re);

bool Find_ximin(float *xi_min,float input1,float obj1,float input2,float obj2, float *output1,float *output2);


bool Analysis_Combine(CDraw &para, MyPlots *plots, AObject& object,bool *Jcomb1, bool *Jcomb2, bool *Jcomb3, bool *Jcomb4, bool *Jcomb5, bool *Jcomb6);

bool reconstruct_met(CDraw &para, TH1 *comb, AObject& object,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine, TLorentzVector &Vre_met);

bool reconstruct_chargeH(CDraw &para, TH1 *comb, TLorentzVector &VA, TLorentzVector &VW,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine);

bool reconstruct_top(CDraw &para, TH1 *comb, TLorentzVector VchargeH, TLorentzVector Vbjet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine);

bool reconstruct_topj(CDraw &para, TH1 *comb, TLorentzVector Vtop, TLorentzVector Vjet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine);

bool reconstruct_cms_topj(CDraw &para, TH1 *comb, TLorentzVector Vtop, TLorentzVector Vjet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine);

template <typename TParticle>
bool Combine2SameFS(CDraw &para, TH1 *comb, TParticle  &in,float obj_mass, float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, TParticle &choosed, TParticle &left){

	int num = in.size();
	int loop1,loop2;
	int count1 = -10,count2 = -10;
	float massclose=100000;
	float re_mass=100000.0;
	TLorentzVector mom1,mom2;
	bool judge;

	for(loop1=0;loop1<num-1;loop1++){
		for(loop2=loop1+1;loop2<num;loop2++){

			mom1 = in.at(loop1)->P4();
			mom2 = in.at(loop2)->P4();
			judge=Combine2_direct(mom1, mom2,cut_mlow,cut_mup, cut_ptlow, cut_ptup, &re_mass);
			if(judge && std::abs(re_mass-obj_mass)<std::abs(massclose-obj_mass)){
				count1 = loop1;
				count2 = loop2;
				massclose = re_mass;
			}
		}
	} 
	if(count1!=-10&& count2!=-10){
		choosed.push_back(in.at(count1));
		choosed.push_back(in.at(count2));
	}
	else{return(false);}

	for(loop1=0;loop1<num;loop1++){
		if(loop1==count1||loop1==count2){continue;}
		left.push_back(in.at(loop1));
	}
	AFill_Plot(para,comb,massclose);
	return(true);
}


template <typename TParticle>
bool Combine2SameFS_TLorentzvector_Combine(CDraw &para, TH1 *comb, TParticle  &in,float obj_mass, float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, TLorentzVector &choosed){

	int num = in.size();
	int loop1,loop2;
	int count1 = -10,count2 = -10;
	float massclose=100000;
	float re_mass=100000.0;
	TLorentzVector mom1,mom2;
	bool judge;

	for(loop1=0;loop1<num-1;loop1++){
		for(loop2=loop1+1;loop2<num;loop2++){

			mom1 = in.at(loop1)->P4();
			mom2 = in.at(loop2)->P4();
			judge=Combine2_direct(mom1, mom2,cut_mlow,cut_mup, cut_ptlow, cut_ptup, &re_mass);
			if(judge && std::abs(re_mass-obj_mass)<std::abs(massclose-obj_mass)){
				count1 = loop1;
				count2 = loop2;
				massclose = re_mass;
			}
		}
	} 
	if(count1!=-10&& count2!=-10){
		choosed=in.at(count1)->P4()+in.at(count2)->P4();
	}
	else{return(false);}

	AFill_Plot(para,comb,massclose);
	return(true);
}



bool Combine2SameFS_TLorentzvector(CDraw &para, TH1 *comb, std::vector<TLorentzVector> &in,float obj_mass, float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, TLorentzVector &choosed);

bool Combine2DifferentFS_TLorentzvector(CDraw &para, TH1 *comb, std::vector<TLorentzVector> in1,std::vector<TLorentzVector> &in2,float obj_mass, float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, TLorentzVector &choosed);
#endif
