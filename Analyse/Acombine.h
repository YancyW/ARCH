#pragma once
#ifndef ACOMBINE_H 
#define ACOMBINE_H 
#include "Analyse/Acomb_func.h"

bool GetCombine(CDraw &para,MyPlots* plots,AObject &object, AnalyseClass &analyse);

bool Analysis_Combine(CDraw &para, MyPlots *plots, AObject& object,bool *Jcomb1, bool *Jcomb2, bool *Jcomb3, bool *Jcomb4, bool *Jcomb5, bool *Jcomb6);

bool reconstruct_met(CDraw &para, TH1 *comb, std::vector<TLorentzVector>& Vlep, std::vector<MissingET*> met, std::vector<TLorentzVector> &Vmet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine);

bool reconstruct_met_threebody(CDraw &para, TH1 *comb, std::vector<TLorentzVector>& Vtau, std::vector<TLorentzVector>& Vlep, std::vector<MissingET*> met, std::vector<TLorentzVector> &Vmet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine);

bool reconstruct_chargeH(CDraw &para, TH1 *comb, TLorentzVector &VA, TLorentzVector &VW,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine);

bool reconstruct_top(CDraw &para, TH1 *comb, TLorentzVector VchargeH, std::vector<TLorentzVector> &Vbjet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine);

bool reconstruct_topj(CDraw &para, TH1 *comb, TLorentzVector Vtop, TLorentzVector Vjet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine);

bool reconstruct_cms_topj(CDraw &para, TH1 *comb, TLorentzVector Vtop, TLorentzVector Vjet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine, float& Vvalue);
#endif

