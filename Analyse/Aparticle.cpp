#include "Aparticle.h"


bool GetFinalState_particle(CDraw &para, TClonesArray *branchParticle,MyPlots* plots,
		std::vector<fastjet::PseudoJet> & Vjet,
		std::vector<fastjet::PseudoJet> & bquark,
		std::vector<fastjet::PseudoJet> & cquark,
		std::vector<fastjet::PseudoJet> & Velec,
		std::vector<fastjet::PseudoJet> & Vmuon,
		std::vector<fastjet::PseudoJet> & Vphoton,
		std::vector<fastjet::PseudoJet> & Vmet,
		AnalyseClass &analyse){

	int loop1=0,num;

	bool Jparticle    = false;
	bool Jclassify    = false;
	bool Jjet         = false;
	bool Jelec        = true;
	bool Jmuon        = true;
	bool Jmet         = true;

	std::vector<fastjet::PseudoJet> particle;
	std::vector<fastjet::PseudoJet> elec_p;
	std::vector<fastjet::PseudoJet> elec_m;
	std::vector<fastjet::PseudoJet> muon_p;
	std::vector<fastjet::PseudoJet> muon_m;
	std::vector<fastjet::PseudoJet> tau_p;
	std::vector<fastjet::PseudoJet> tau_m;
	std::vector<fastjet::PseudoJet> gamma;
	std::vector<fastjet::PseudoJet> heavyparticle;
	std::vector<fastjet::PseudoJet> hadron;
	std::vector<fastjet::PseudoJet> had_candi ;
	fastjet::PseudoJet missingEt;

	GenParticle* gen;

	Jparticle = GetGenParticle(para, branchParticle, particle);
	if(!Jparticle){
		return(false);
	}

	Jclassify= Class_particle_by_PID(particle,elec_p, elec_m, muon_p, muon_m, tau_p,  tau_m, missingEt, gamma,  heavyparticle, hadron);
	if(!Jclassify){
		return(false);
	}

	if(para.jet.SWITCH && para.jet.jets.SWITCH){
		for(int i=0;i<gamma.size();i++){
			had_candi.push_back(gamma[i]);
		}
		for(int i=0;i<hadron.size();i++){
			had_candi.push_back(hadron[i]);
		}
		//		had_candi = gamma + hadron;
		////	had_candi = had_candi + heavyparticle ;
		////	had_candi = had_candi + hadron; 
		para.debug.Message(3,40,"get PseudoJet ");
		if(had_candi.size()>0){
			if(para.jetsub.SWITCH){
				Vjet = had_candi;
				Jjet=true;
			}
			else{
				Jjet=GetFinalState_cut(para, had_candi, plots,Vjet);
			}
			para.debug.Message(2,40,"Vjet number",Vjet.size());
			para.debug.Message(3,40,"end get PseudoJet ",Jjet);
			if(Jjet){analyse.counter.getCounter("basic_jet");}
			ATagParticle(para,branchParticle,bquark,cquark);
		}
	}
	else{Jjet=true;}



	if(para.lep.SWITCH && para.lep.elec.SWITCH && para.lep.muon.SWITCH){
		para.debug.Message(3,40,"get lepton,  including elec and muon");
		para.debug.Message(3,40,"get elec");
		Jelec=GetFinalState_particle(para,elec_p,elec_m,plots,Velec);
		para.debug.Message(3,40,"end get elec",Jelec);

		para.debug.Message(3,40,"get muon");
		Jmuon=GetFinalState_particle(para,muon_p,muon_m,plots,Vmuon);
		para.debug.Message(3,40,"end get muon",Jmuon);

		if(Jelec || Jmuon){
			analyse.counter.getCounter("basic_lep");
			Jelec=true;
			Jmuon=true;
		}
		else{return(false);}
	}
	else{
		para.debug.Message(3,40,"get elec or muon seperately");
		if(para.lep.SWITCH && para.lep.elec.SWITCH && !para.lep.muon.SWITCH){
			para.debug.Message(3,40,"get elec");
			Jelec=GetFinalState_particle(para,elec_p,elec_m,plots,Velec);
			para.debug.Message(3,40,"end get elec",Jelec);
			if(Jelec){
				analyse.counter.getCounter("basic_elec");
			}
			else{
				return(false);
			}
		}
		else{
			Jelec=true;
		}

		// Analyse muon 
		if(para.lep.SWITCH && para.lep.muon.SWITCH && !para.lep.elec.SWITCH){
			para.debug.Message(3,40,"get muon");
			Jmuon=GetFinalState_particle(para,muon_p,muon_m,plots,Vmuon);
			para.debug.Message(3,40,"end get muon",Jmuon);
			if(Jmuon){
				analyse.counter.getCounter("basic_muon");
			}
			else{return(false);}
		}
		else{
			Jmuon=true;
		}
	}



	if( Jparticle && Jjet && Jelec && Jmuon && Jmet )
	{
		analyse.counter.getCounter("basic");
		return(true);
	}
	else{
		return(false);
	}

}


bool GetGenParticle(CDraw &para, TClonesArray *branchParticle,std::vector<fastjet::PseudoJet> & Vparticle)
{
	int loop1=0,num;

	GenParticle* gen;

	num = branchParticle->GetEntriesFast();
	para.debug.Message(2,49,"particle number",num);
	for(loop1=0;loop1<num;loop1++){
		gen = (GenParticle*) branchParticle->At(loop1);

		int    Status = gen->Status;
		if(Status!=1){
			continue;
		}

		int    PID    = gen->PID;
		int    Charge = gen->Charge;
		int    IsPU   = gen->IsPU;
		float Mass   = gen->Mass;
		float px     = gen->Px;
		float py     = gen->Py;
		float pz     = gen->Pz;
		float E      = gen->E;
		float pT     = gen->PT;
		float eta    = gen->Eta;
		float phi    = gen->Phi;
		int    M1     = gen->M1;
		int    M2     = gen->M2;
		int    D1     = gen->D1;
		int    D2     = gen->D2;
		float t      = gen->T; 
		float x      = gen->X; 
		float y      = gen->Y; 
		float z      = gen->Z; 


		fastjet::PseudoJet candi=fastjet::PseudoJet(px,py,pz,E);
		candi.set_user_info( new PseudoJetInfo(PID, Charge, Status, IsPU, Mass) );
		Vparticle.push_back(candi);
		para.debug.Message(2,49,"particle ",candi);
	}//endfor jet_Cindex
	para.debug.Message(2,49,"Vparticle number",Vparticle.size());
	if(Vparticle.size()>0){
		return(true);
	}
	else{

		return(true);
	}
}


bool Class_particle_by_PID(
		std::vector<fastjet::PseudoJet> &candi,
		std::vector<fastjet::PseudoJet> &elec_p, std::vector<fastjet::PseudoJet> &elec_m, 
		std::vector<fastjet::PseudoJet> &muon_p, std::vector<fastjet::PseudoJet> &muon_m, 
		std::vector<fastjet::PseudoJet> &tau_p,  std::vector<fastjet::PseudoJet> &tau_m, 
		fastjet::PseudoJet &missingEt, 
		std::vector<fastjet::PseudoJet> &gamma,  
		std::vector<fastjet::PseudoJet> &heavyparticle,
		std::vector<fastjet::PseudoJet> &hadron)
{
	if(candi.size()<=0){
		return(false);
	}

	for(int i=0;i<candi.size();i++){
		int    PID    = candi[i].user_info<PseudoJetInfo>().PID;
		if(std::abs(PID)==12 || std::abs(PID)==14 || std::abs(PID)==16 ){   	// neutrino
			missingEt += candi[i];
		}else if(PID == 11 ){  	// e-
			//sequencept((float **)pem, &nem, E, px, py, pz, pT, eta, phi);
			elec_p.push_back(candi[i]); 
		}else if( PID == 13 ){  	// mu-
			//sequencept((float **)pmm, &nmm, E, px, py, pz, pT, eta, phi);
			muon_p.push_back(candi[i]); 
		}else if( PID == 15 ){  	// tau-
			//sequencept((float **)ptm, &ntm, E, px, py, pz, pT, eta, phi);
			tau_p.push_back(candi[i]); 
		}else if( PID == -11 ){  	// e+
			//sequencept((float **)pep, &nep, E, px, py, pz, pT, eta, phi);
			elec_m.push_back(candi[i]); 
		}else if( PID == -13 ){  	// mu+
			//sequencept((float **)pmp, &nmp, E, px, py, pz, pT, eta, phi);
			muon_m.push_back(candi[i]); 
		}else if( PID == -15 ){  	// tau+
			//sequencept((float **)ptp, &ntp, E, px, py, pz, pT, eta, phi);
			tau_m.push_back(candi[i]); 
		}else if(abs(PID)==22){ 	// photon
			//sequencept((float **)pga, &nga, E, px, py, pz, pT, eta, phi);
			gamma.push_back(candi[i]); 
		}else if(std::abs(PID)==23 || std::abs(PID)==24 || std::abs(PID)==25){  	// hadron
			heavyparticle.push_back(candi[i]); 
		}else{
			hadron.push_back(candi[i]); 
		}
	}

	return(true);
}
