#include "ABTag.h"
void ATagParticle(CDraw &para, TClonesArray *branchParticle,std::vector<fastjet::PseudoJet> &bquark, std::vector<fastjet::PseudoJet> &cquark){
	GenParticle * particle;
	fastjet::PseudoJet     candi_jet;
	para.debug.Message(6,11,"begin findding bquark");
	para.debug.Message(6,11,"particle size",branchParticle->GetEntries());

	for(int j=0;j<branchParticle->GetEntries();j++){
		particle = (GenParticle * ) branchParticle->At(j);
		candi_jet=fastjet::PseudoJet(particle->Px,particle->Py,particle->Pz,particle->E);

		if(particle->Status==2 && abs(particle->PID)==5){
	        para.debug.Message(6,11,"particle Status and PID",particle->Status,particle->PID);
			candi_jet.set_user_index(5);
			bquark.push_back(candi_jet);
		}
		else if(particle->Status==2 && abs(particle->PID)==4){
			candi_jet.set_user_index(4);
			cquark.push_back(candi_jet);
		}
		else{
			candi_jet.set_user_index(0);
			continue;
		}
	}
	para.debug.Message(6,11,"bquark size",bquark.size());
	para.debug.Message(6,11,"bquark is",bquark);
}

bool ATagBJet(CDraw &para,std::vector<fastjet::PseudoJet> bquark, std::vector<fastjet::PseudoJet> cquark, fastjet::PseudoJet input_jet){
	float random;
	int j;
	//for a  b-quark to be regonized as a b quark
	para.debug.Message(6,11,"begin findding TagBJet");
	para.debug.Message(6,11,"bquark is",bquark);
	para.debug.Message(6,11,"input jet is",input_jet);
	para.debug.Message(6,11,"btag.coneR",para.tag.btag.coneR);
	para.debug.Message(6,11,"btag.bquark_ratio",para.tag.btag.bquark_ratio);
	para.debug.Message(6,11,"btag.cquark_ratio",para.tag.btag.cquark_ratio);
	para.debug.Message(6,11,"btag.lightquark_ratio",para.tag.btag.lightquark_ratio);
	for(j=0;j<bquark.size();j++){
	    para.debug.Message(6,11,"input deltaR with bquark j",input_jet.delta_R(bquark[j]));
		if(input_jet.delta_R(bquark[j])<para.tag.btag.coneR)
		{
			random=std::rand()%10000;
			if(random<para.tag.btag.bquark_ratio*10000){
	            para.debug.Message(6,11,"choose the b quark is",j);
	            para.debug.Message(6,11,"choose the b quark is",bquark[j]);
				return(true);
			}
		}
	}

	//for a  c-quark to be regonized as a b quark
	for(j=0;j<cquark.size();j++){
		if(input_jet.delta_R(cquark[j])<para.tag.btag.coneR)
		{
			random=std::rand()%10000;
			if(random<para.tag.btag.cquark_ratio*10000){
				return(true);
			}
		}
	}

	//for a  light-quark to be regonized as a b quark
	random=std::rand()%10000;
	if(random<para.tag.btag.lightquark_ratio*10000){
		return(true);
	}
	return(false);
}


bool ATagCJet(CDraw &para,std::vector<fastjet::PseudoJet> bquark, std::vector<fastjet::PseudoJet> cquark, fastjet::PseudoJet input_jet){
	float random;
	int j;
	//for a  b-quark to be regonized as a b quark
	para.debug.Message(6,11,"begin findding TagBJet");
	para.debug.Message(6,11,"bquark is",bquark);
	para.debug.Message(6,11,"input jet is",input_jet);
	para.debug.Message(6,11,"btag.coneR",para.tag.ctag.coneR);
	para.debug.Message(6,11,"btag.bquark_ratio",para.tag.ctag.bquark_ratio);
	para.debug.Message(6,11,"btag.cquark_ratio",para.tag.ctag.cquark_ratio);
	para.debug.Message(6,11,"btag.lightquark_ratio",para.tag.ctag.lightquark_ratio);
	for(j=0;j<bquark.size();j++){
	    para.debug.Message(6,11,"input deltaR with bquark j",input_jet.delta_R(bquark[j]));
		if(input_jet.delta_R(bquark[j])<para.tag.ctag.coneR)
		{
			random=std::rand()%10000;
			if(random<para.tag.ctag.bquark_ratio*10000){
	            para.debug.Message(6,11,"choose the b quark is",j);
	            para.debug.Message(6,11,"choose the b quark is",bquark[j]);
				return(true);
			}
		}
	}

	//for a  c-quark to be regonized as a b quark
	for(j=0;j<cquark.size();j++){
		if(input_jet.delta_R(cquark[j])<para.tag.ctag.coneR)
		{
			random=std::rand()%10000;
			if(random<para.tag.ctag.cquark_ratio*10000){
				return(true);
			}
		}
	}

	//for a  light-quark to be regonized as a b quark
	random=std::rand()%10000;
	if(random<para.tag.ctag.lightquark_ratio*10000){
		return(true);
	}
	return(false);
}
