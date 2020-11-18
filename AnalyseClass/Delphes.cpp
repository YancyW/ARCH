
#include "AnalyseClass/Delphes.h"
void ADelphes::Clear(){
	branchJet               = NULL;
	branchElectron          = NULL;
	branchMuon              = NULL;
	branchPhoton            = NULL;
	branchMissingET         = NULL;

	branchParticle          = NULL;

	branchEvent             = NULL;
	branchEFlowTrack        = NULL;
	branchEFlowPhoton       = NULL;
	branchEFlowNeutralHadron= NULL;
}


void ADelphes::Init(ExRootTreeReader* treeReader, bool judge){
	if(!judge){
		return;
	}
	ShowMessage(2,"ADelphes::Init","begin");
	branchJet                = treeReader->UseBranch("Jet"               );
	branchElectron           = treeReader->UseBranch("Electron"          );
	branchMuon               = treeReader->UseBranch("Muon"              );
	branchPhoton             = treeReader->UseBranch("Photon"            );
	branchMissingET          = treeReader->UseBranch("MissingET"         );

	branchParticle           = treeReader->UseBranch("Particle"          );

	branchEvent              = treeReader->UseBranch("Event"             );
	branchEFlowTrack         = treeReader->UseBranch("EFlowTrack"        );
	branchEFlowPhoton        = treeReader->UseBranch("EFlowPhoton"       );
	branchEFlowNeutralHadron = treeReader->UseBranch("EFlowNeutralHadron");
}

