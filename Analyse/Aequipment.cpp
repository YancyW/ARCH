#include "Aequipment.h"


bool GetFinalState(CDraw &para, TClonesArray *branchEFlowTrack,	TClonesArray *branchEFlowNeutralHadron,	TClonesArray *branchEFlowPhoton,TClonesArray *branchElectron ,TClonesArray *branchMuon,TClonesArray *branchMissingET,MyPlots* plots,
		TClonesArray *branchParticle,
		std::vector<fastjet::PseudoJet> & Vjet,
		std::vector<fastjet::PseudoJet> & bquark,
		std::vector<fastjet::PseudoJet> & cquark,
		std::vector<Electron*>& Velec,std::vector<Muon*>& Vmuon,std::vector<Photon*>& Vphoton,std::vector<MissingET*>& Vmet, AnalyseClass &analyse){

	bool Jjet         = false;
	bool Jelec        = false;
	bool Jmuon        = false;
	bool Jmet         = false;
	bool Jbasic       = false;

	std::vector<fastjet::PseudoJet> Vjet_candi;
	if(para.jet.SWITCH && para.jet.jets.SWITCH){
		para.debug.Message(3,30,"get PseudoJet ");
		GetFinalState_equipment(para,branchEFlowNeutralHadron,branchEFlowTrack,branchEFlowPhoton, branchElectron,branchMuon,Vjet_candi);
		para.debug.Message(3,30,"Whether get jet cut",!para.jetsub.SWITCH);
		if(para.jetsub.SWITCH){
			Vjet=Vjet_candi;
			Jjet=true;
		}
		else{
			Jjet=GetFinalState_cut(para, Vjet_candi, plots,Vjet);
		}
		para.debug.Message(3,30,"PseudoJet num",Vjet.size());
		para.debug.Message(3,30,"end get PseudoJet ",Jjet);
		if(Jjet){analyse.counter.getCounter("basic_jet");}
		else{return(false);}

		ATagParticle(para,branchParticle,bquark,cquark);
	}
	else{Jjet=true;}


	if(para.lep.SWITCH && para.lep.elec.SWITCH && para.lep.muon.SWITCH){
		para.debug.Message(3,30,"get lepton,  including elec and muon");
		para.debug.Message(3,30,"get elec");
		Jelec=GetFinalState_detector(para,branchElectron,plots,Velec);
		para.debug.Message(3,30,"end get elec",Jelec);

		para.debug.Message(3,30,"get muon");
		Jmuon=GetFinalState_detector(para,branchMuon,plots,Vmuon);
		para.debug.Message(3,30,"end get muon",Jmuon);

		if(Jelec || Jmuon){
		analyse.counter.getCounter("basic_lep");
			Jelec=true;
			Jmuon=true;
		}
		else{return(false);}
	}
	else{
		para.debug.Message(3,30,"get elec or muon seperately");
		if(para.lep.SWITCH && para.lep.elec.SWITCH && !para.lep.muon.SWITCH){
			para.debug.Message(3,30,"get elec");
			Jelec=GetFinalState_detector(para,branchElectron,plots,Velec);
			para.debug.Message(3,30,"end get elec",Jelec);
			if(Jelec){
		analyse.counter.getCounter("basic_elec");
			}
			else{return(false);}
		}
		else{Jelec=true;}

		// Analyse muon 
		if(para.lep.SWITCH && para.lep.muon.SWITCH && !para.lep.elec.SWITCH){
			para.debug.Message(3,30,"get muon");
			Jmuon=GetFinalState_detector(para,branchMuon,plots,Vmuon);
			para.debug.Message(3,30,"end get muon",Jmuon);
			if(Jmuon){
		analyse.counter.getCounter("basic_muon");
			}
			else{return(false);}
		}
		else{Jmuon=true;}
	}


	// Analyse missing ET
	if(para.met.SWITCH){

		para.debug.Message(3,30,"get met");
		Jmet=GetFinalState_detector(para,branchMissingET,plots,Vmet);
		if(Jmet){
		analyse.counter.getCounter("basic_met");
		}
		else{return(false);}
	}
	else{Jmet=true;}

	//  number pass the all basic cuts;
	para.debug.Message(3,30,"get all basic cuts");
	if(Jjet&&Jelec&&Jmuon&&Jmet){
		Jbasic=true;
		analyse.counter.getCounter("basic");
		return(true);
	}
	else{
		return(false);
	}
}










void GetFinalState_equipment(CDraw &para,TClonesArray *branchEFlowNeutralHadron,TClonesArray *branchEFlowTrack,TClonesArray *branchEFlowPhoton, TClonesArray *branchElectron, TClonesArray *branchMuon,  std::vector<fastjet::PseudoJet> &jet_candi){
	int loop1=0,loop2=0,num;

	para.debug.Message(3,32,"get EFlowNeutralHadron into vector");
	int numNeut = branchEFlowNeutralHadron->GetEntries();
	para.debug.Message(3,32,"EFlowNeutralHadronadron size",numNeut);

	for(loop1=0;loop1<numNeut;loop1++){
		Jet *neutralhad = (Jet*) branchEFlowNeutralHadron->At(loop1);
		fastjet::PseudoJet candi=fastjet::PseudoJet(neutralhad->PT*TMath::Cos(neutralhad->Phi),neutralhad->PT*TMath::Sin(neutralhad->Phi),neutralhad->PT*TMath::SinH(neutralhad->Eta),neutralhad->PT*TMath::CosH(neutralhad->Eta));

		if ( candi.perp()>0 )
		{
			jet_candi.push_back(candi);
		}
	}

	para.debug.Message(3,32,"get EFlowTrack into vector");
	int numTrack = branchEFlowTrack->GetEntries();
	int numElec  = branchElectron  ->GetEntries();
	int numMuon  = branchMuon      ->GetEntries();
	para.debug.Message(3,32,"EFlowTrack size",numTrack);
	para.debug.Message(3,32,"Electron size",numElec);
	para.debug.Message(3,32,"Muon size",numMuon);
	if(numTrack>0){
		for(loop1=0;loop1<numTrack;loop1++){
			Track *track= (Track*) branchEFlowTrack->At(loop1);
			fastjet::PseudoJet candi=fastjet::PseudoJet(track->PT*TMath::Cos(track->Phi),track->PT*TMath::Sin(track->Phi),track->PT*TMath::SinH(track->Eta),track->PT*TMath::CosH(track->Eta));
			//fastjet::PseudoJet candi=fastjet::PseudoJet(track->P4().X(),track->P4().Y(),track->P4().Z(),track->P4().T());

			bool judge=true;
			if(judge&&numElec>0){
				for (loop2=0;loop2<branchElectron->GetEntries();loop2++ )
				{
					Electron *electron_mover=(Electron *) branchElectron->At(loop2);
					if ( TMath::Abs(track->Eta-electron_mover->Eta)<0.01 && ( TMath::Abs(track->Phi-electron_mover->Phi)<0.01 || TMath::Abs(track->Phi-electron_mover->Phi)>2*3.1415926-0.01 ) )
					{
						judge=false;break;
					}
				}
			}
			// to remove the muons from the Eflow Tracks
			if(judge&&numMuon>0){
				for (loop2=0;loop2<branchMuon->GetEntries();loop2++ )
				{
					Muon* muon_mover=(Muon *) branchMuon->At(loop2);
					if (TMath::Abs(track->Eta-muon_mover->Eta)<0.01 && ( TMath::Abs(track->Phi-muon_mover->Phi)<0.01 || TMath::Abs(track->Phi-muon_mover->Phi)>2*3.1415926-0.01 ) )
					{
						judge=false;break;
					}
				}
			}
			//
			if ( candi.perp()>0 && judge==true)
			{
				jet_candi.push_back(candi);
			}
		}
	}

	para.debug.Message(3,32,"get EFlowPhoton into vector");
	int numPhoton = branchEFlowPhoton->GetEntries();
	para.debug.Message(3,32,"EFlowPhoton size",numPhoton);
	for(loop1=0;loop1<numPhoton;loop1++){
		Photon *photon= (Photon*) branchEFlowPhoton->At(loop1);
		fastjet::PseudoJet candi=fastjet::PseudoJet(photon->PT*TMath::Cos(photon->Phi),photon->PT*TMath::Sin(photon->Phi),photon->PT*TMath::SinH(photon->Eta),photon->PT*TMath::CosH(photon->Eta));

		if ( candi.perp()>0 )
		{
			jet_candi.push_back(candi);
		}
	}

}

bool GetFinalState_cut(CDraw &para, std::vector<fastjet::PseudoJet> &input_jet, MyPlots *plots,std::vector<fastjet::PseudoJet> &jet){

	int loop1=0,loopj=0,num;
	float pt,y,mass;

	if (para.signal.NUM_jets==0){return(true);} 

	num = input_jet.size();
	plots->fJetnum->Fill(num);

	para.debug.Message(3,33,"get cut for PseudoJet");
	for(loop1=0;loop1<num;loop1++){
		pt   = input_jet[loop1].perp();
		y    = input_jet[loop1].rap() ;
		mass = input_jet[loop1].m()   ;
		if( para.jet.jets.JCUT_pt  [0] == true && ( pt     < para.jet.jets.CUT_ptd  [0] || pt     > para.jet.jets.CUT_ptu  [0] )){para.debug.Message(3,3,"jets single jet pt",  pt  );continue;}//endif
		if( para.jet.jets.JCUT_mass[0] == true && ( mass   < para.jet.jets.CUT_massd[0] || mass   > para.jet.jets.CUT_massu[0] )){para.debug.Message(3,3,"jets single jet eta", y   );continue;}//endif
		if( para.jet.jets.JCUT_eta [0] == true && ( std::abs(y) < para.jet.jets.CUT_etad [0] || std::abs(y) > para.jet.jets.CUT_etau [0] )){para.debug.Message(3,3,"jets single jet mass",mass);continue;}//endif
		loopj++;
		jet.push_back(input_jet[loop1]);
	}//endfor jet_Cindex

	if(loopj>=1&&loopj>=para.signal.NUM_jets){
		for(loop1=1;loop1<para.jet.jets.CUT_num;loop1++){
			pt   = jet[loop1].perp();
			y    = jet[loop1].rap() ;
			mass = jet[loop1].m()   ;
			if( para.jet.jets.JCUT_pt  [loop1] == true && ( pt     < para.jet.jets.CUT_ptd  [loop1] || pt     > para.jet.jets.CUT_ptu  [loop1] )){para.debug.Message(3,3,"jets single jet pt  ", loop1,  pt);return(false);}//endif
			if( para.jet.jets.JCUT_mass[loop1] == true && ( mass   < para.jet.jets.CUT_massd[loop1] || mass   > para.jet.jets.CUT_massu[loop1] )){para.debug.Message(3,3,"jets single jet mass", loop1,   y);return(false);}//endif
			if( para.jet.jets.JCUT_eta [loop1] == true && ( std::abs(y) < para.jet.jets.CUT_etad [loop1] || std::abs(y) > para.jet.jets.CUT_etau [loop1] )){para.debug.Message(3,3,"jets single jet eta ", loop1,mass);return(false);}//endif
		}

		for(loop1=0;loop1<loopj;loop1++){
			if(loop1<para.signal.NUM_jets){
				plots->fJetPT[loop1]->Fill(jet[loop1].perp());
				plots->fJetY [loop1]->Fill(jet[loop1].rap());
			} 
		}
		return(true);
	}
	else{para.debug.Message(3,33,"jet num is small",loopj); return(false);}
}

