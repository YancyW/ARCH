#pragma once
#ifndef ANALYSE_CLASS_DELPHES_H
#define ANALYSE_CLASS_DELPHES_H
#include "TSystem.h"
#include "TTree.h"
#include "TChain.h"
#include "ExRootTreeReader.h"
#include "Lib/MessageFormat.h"

class ADelphes{
	private:
	public:
		//for delphes
		TClonesArray *branchJet                ;
		TClonesArray *branchElectron           ;
		TClonesArray *branchMuon               ;
		TClonesArray *branchPhoton             ;
		TClonesArray *branchMissingET          ;

		TClonesArray *branchParticle           ;

		TClonesArray *branchEvent              ;
		TClonesArray *branchEFlowTrack         ;
		TClonesArray *branchEFlowPhoton        ;
		TClonesArray *branchEFlowNeutralHadron ;

		void Clear();

		void Init(ExRootTreeReader* treeReader, bool judge);
};


#endif
