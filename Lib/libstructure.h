#pragma once
#ifndef MYPLOT_DEF
#define MYPLOT_DEF
#include "TH2.h"
#include "TH1.h"
#include "fastjet/PseudoJet.hh"
#include "Lib/MessageFormat.h"
#include "Class/DrawClass.h"

struct MyPlots
{
  TH1 *fJetnum;
  TH1 *fJetPT[10];
  TH1 *fJetY [10];

  TH1 *fBJetnum;
  TH1 *fBJetPT[10];
  TH1 *fBJetY [10];

  TH1 *fCJetnum;
  TH1 *fCJetPT[10];
  TH1 *fCJetY [10];

  TH1 *fQJetnum;
  TH1 *fQJetPT[10];
  TH1 *fQJetY [10];

  TH1 *fTauJetnum;
  TH1 *fTauJetPT[10];
  TH1 *fTauJetY [10];

  TH1 *fUJetnum;
  TH1 *fUJetPT[10];
  TH1 *fUJetY [10];

  TH1 *fLepnum;
  TH1 *fLepPT[10];
  TH1 *fLepY [10];
 
  TH1 *fElecnum;
  TH1 *fElectronPT[10];
  TH1 *fElectronY [10];
 
  TH1 *fMuonnum;
  TH1 *fMuonPT[10];
  TH1 *fMuonY [10];

  TH1 *fTaunum;
  TH1 *fTauPT[10];
  TH1 *fTauY [10];

  TH1 *fMissingET;

  TH1 *fHT;
  TH1 *fcomb1M;
  TH1 *fcomb2M;
  TH1 *fcomb3M;
  TH1 *fcomb4M;
  TH1 *fcomb5M;
  TH1 *fcomb6M;

  TH1 *frecoilmass;

  TH1 *fJEPr;
  TH1 *fJEPR;

  TH1 *fJEPr2;
  TH1 *fJEPR2;

  TH1 * fmassdrop;
};


TH1* Get_Class_ptr(CDraw &para, MyPlots *plots, std::string class_name, std::string observe_name,int array_num);

template <typename TParticle>
void Get_ClassName(TParticle in){
	std::vector<fastjet::PseudoJet> particles;
	std::cout << in->ClassName() << std::endl;
}
#endif
