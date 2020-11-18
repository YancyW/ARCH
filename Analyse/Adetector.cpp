#include "Adetector.h"


//bool GetFinalState(CDraw &para, TClonesArray *branchJet      ,TClonesArray *branchElectron ,TClonesArray *branchMuon     ,TClonesArray *branchPhoton   ,TClonesArray *branchMissingET,TClonesArray *branchParticle ,MyPlots* plots,
//		std::vector<Jet*> & Vjet,std::vector<Jet*>& Vbjet,std::vector<Jet*>& Vcjet,std::vector<Jet*>& Vqjet,std::vector<Jet*>& Vtaujet, std::vector<Jet*>& Vtagjet,std::vector<Jet*>& Vuntagjet,
//		std::vector<Electron*>& Velec,std::vector<Muon*>& Vmuon,std::vector<Jet*>& Vtau,std::vector<Photon*>& Vphoton,std::vector<MissingET*>& Vmet, AnalyseClass &analyse){

bool GetFinalState_detector(CDraw &para, AnalyseClass &analyse, AObject &object, MyPlots* plots){

	bool Jjet         = false;
	bool Jtagjet      = false;
	bool Jelec        = false;
	bool Jmuon        = false;
	bool Jmet         = false;
	bool Jbasic       = false;

	if(para.jet.SWITCH && para.jet.jets.SWITCH){
		para.debug.Message(3,20,"get jet");
		Jjet=GetFinalState_detector_jet(para,analyse.delphes.branchJet,plots,object.Vjet);
		if(Jjet){
			analyse.counter.getCounter("basic_jet");
		}
		else{
			return(false);
		}
	}
	else{Jjet=true;}

	// Analyse tagjets
	if(para.jet.SWITCH && para.jet.jets.SWITCH && (para.jet.bjet.SWITCH||para.jet.cjet.SWITCH||para.jet.qjet.SWITCH||para.jet.taujet.SWITCH)){
		para.debug.Message(3,20,"get tagged jet");
		Jtagjet=GetFinalState_detector_jet_classify(para,analyse,object.Vjet,object.Vbjet,object.Vcjet,object.Vqjet,object.Vtaujet, object.Vuntagjet,plots);
		if(Jtagjet){
			analyse.counter.getCounter("basic_bjet");
		}
		else{
			return(false);
		}
	}
	else{Jtagjet=true;}

	// Analyse elec 
	if(para.lep.SWITCH && !para.lep.elec.SWITCH && !para.lep.muon.SWITCH){
		Jelec=GetFinalState_detector_elec(para,analyse.delphes.branchElectron,plots,object.Velec);

		Jmuon=GetFinalState_detector_muon(para,analyse.delphes.branchMuon,plots,object.Vmuon);

		if(object.Velec.size()+object.Vmuon.size()<para.signal.NUM_lep){return(false);}

		if(Jelec || Jmuon){
			analyse.counter.getCounter("basic_lep");
			Jelec = true;
			Jmuon = true;
		}
		else{
			return(false);
		}
	}
	else if(para.lep.SWITCH && (para.lep.elec.SWITCH || para.lep.muon.SWITCH) ){
		para.debug.Message(3,20,"get elec or muon seperately");
		if(para.lep.SWITCH && para.lep.elec.SWITCH){
			para.debug.Message(3,20,"get elec");
			Jelec=GetFinalState_detector_elec(para,analyse.delphes.branchElectron,plots,object.Velec);
			para.debug.Message(3,20,"end get elec",Jelec);
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
		if(para.lep.SWITCH && para.lep.muon.SWITCH){
			para.debug.Message(3,20,"get muon");
			Jmuon=GetFinalState_detector_muon(para,analyse.delphes.branchMuon,plots,object.Vmuon);
			para.debug.Message(3,20,"end get muon",Jmuon);
			if(Jmuon){
				analyse.counter.getCounter("basic_muon");
			}
			else{return(false);}
		}
		else{Jmuon=true;}
	}
	else{
		Jelec = true;
		Jmuon = true;
	}

	// Analyse missing ET
	if(para.met.SWITCH){
		para.debug.Message(3,20,"get met");
		Jmet=GetFinalState_detector_met(para,analyse.delphes.branchMissingET,plots,object.Vmet);
		para.debug.Message(3,20,"end get met",Jmet);
		if(Jmet){
			analyse.counter.getCounter("basic_met");
		}
		else{
			return(false);
		}
	}
	else{
		Jmet=true;
	}


	/*
    if(object.Vtaujet.size()>=2){
    	object.Fill_Particle_A(para,analyse);
    }
    else if(object.Vtaujet.size()==1){
    	bool JPB=object.Fill_Particle_B(para,analyse);
		if(!JPB){
			return(false);
		}
    }
    else if(object.Vtaujet.size()==0){
    	object.Fill_Particle_C(para,analyse);
    }
	*/

	//  number pass the all basic cuts;
	para.debug.Message(3,20,"get all basic cuts");
	if(Jjet&&Jtagjet&&Jelec&&Jmuon&&Jmet){
		Jbasic=true;
		analyse.counter.getCounter("basic");
		return(true);
	}
	else{
		return(false);
	}

}












bool GetFinalState_detector_elec(CDraw &para, TClonesArray *branchElectron, MyPlots *plots,std::vector<Electron*> &elec){
	int loop1=0,loope=0,num;
	float pt,y;

	if (para.signal.NUM_lep==0&&para.signal.NUM_elec==0){return(true);} 

	num = branchElectron->GetEntries();

	if(para.lep.SWITCH && !para.lep.elec.SWITCH && !para.lep.muon.SWITCH){
		AFill_Plot(para,plots->fLepnum,num);
	}
	else if(para.lep.SWITCH &&  para.lep.elec.SWITCH){
		AFill_Plot(para,plots->fElecnum,num);
	}

	for(loop1=0;loop1<num;loop1++){
		Electron *elec_ptr = (Electron*) branchElectron->At(loop1);
		pt = elec_ptr->PT;
		y  = std::abs(elec_ptr->Eta);

  		if( para.lep.elec.JCUT_pt  [0] == true && ( pt  < para.lep.elec.CUT_ptd  [0] || pt  > para.lep.elec.CUT_ptu  [0] )){continue;}
  		if( para.lep.elec.JCUT_eta [0] == true && ( y   < para.lep.elec.CUT_etad [0] || y   > para.lep.elec.CUT_etau [0] )){continue;}
		elec.push_back(elec_ptr);
		loope++;
	}
	if(para.lep.SWITCH && !para.lep.elec.SWITCH && !para.lep.muon.SWITCH){
		if(loope>=1){
			for(loop1=1;loop1<para.lep.elec.CUT_num;loop1++){
				pt   = elec[loop1-1]->PT;
				y    = std::abs(elec[loop1-1]->Eta);
				if( para.lep.elec.JCUT_pt  [loop1] == true && ( pt  < para.lep.elec.CUT_ptd  [loop1] || pt > para.lep.elec.CUT_ptu  [loop1] )){return(false);}
				if( para.lep.elec.JCUT_eta [loop1] == true && ( y   < para.lep.elec.CUT_etad [loop1] || y  > para.lep.elec.CUT_etau [loop1] )){return(false);}
			}

			for(loop1=0;loop1<loope;loop1++){
				if(loop1<para.signal.NUM_lep){
					AFill_Plot(para,plots->fLepPT[loop1],elec[loop1]->PT);
					AFill_Plot(para,plots->fLepY[loop1] ,elec[loop1]->Eta);
				} 
			}
			return(true);
		}
		else{
			return(false);
		}
	}
	else if(para.lep.SWITCH &&  para.lep.elec.SWITCH ){
		if(loope>=1&&loope>=para.signal.NUM_elec){
			for(loop1=1;loop1<para.lep.elec.CUT_num;loop1++){
				pt   = elec[loop1-1]->PT;
				y    = std::abs(elec[loop1-1]->Eta);
				if( para.lep.elec.JCUT_pt  [loop1] == true && ( pt  < para.lep.elec.CUT_ptd  [loop1] || pt > para.lep.elec.CUT_ptu  [loop1] )){return(false);}
				if( para.lep.elec.JCUT_eta [loop1] == true && ( y   < para.lep.elec.CUT_etad [loop1] || y  > para.lep.elec.CUT_etau [loop1] )){return(false);}
			}

			for(loop1=0;loop1<loope;loop1++){
				if(loop1<para.signal.NUM_elec){
					AFill_Plot(para,plots->fElectronPT[loop1],elec[loop1]->PT);
					AFill_Plot(para,plots->fElectronY[loop1] ,elec[loop1]->Eta);
				} 
			}
			return(true);
		}
		else{
			return(false);
		}
	}
	return(true);
}





bool GetFinalState_detector_muon(CDraw &para, TClonesArray *branchMuon, MyPlots *plots,std::vector<Muon*> &muon){
	int loop1=0,loopm=0,num;
	float pt,y;

	para.debug.Message(3,22,"in the muon cut function");
	if (para.signal.NUM_lep==0&&para.signal.NUM_muon==0){return(true);} 

	num = branchMuon->GetEntries();
	if(para.lep.SWITCH && !para.lep.elec.SWITCH && !para.lep.muon.SWITCH){
		AFill_Plot(para,plots->fLepnum,num);
	}
	else if(para.lep.SWITCH &&  para.lep.muon.SWITCH){
		AFill_Plot(para,plots->fMuonnum,num);
	}

	for(loop1=0;loop1<num;loop1++){
		Muon *muon_ptr = (Muon*) branchMuon->At(loop1);
		pt = muon_ptr->PT;
		y  = std::abs(muon_ptr->Eta);
		if( para.lep.muon.JCUT_pt  [0] == true && ( pt     < para.lep.muon.CUT_ptd  [0] || pt     > para.lep.muon.CUT_ptu  [0] )){para.debug.Message(4,22,"false: muon pt cut",pt);continue;}//endif
		if( para.lep.muon.JCUT_eta [0] == true && ( y      < para.lep.muon.CUT_etad [0] || y      > para.lep.muon.CUT_etau [0] )){para.debug.Message(4,22,"false: muon etacut", y);continue;}//endif
		muon.push_back(muon_ptr);
		loopm++;
	}//endfor jet_Cindex

	if(para.lep.SWITCH && !para.lep.elec.SWITCH && !para.lep.muon.SWITCH){
		if(loopm>=1){
			for(loop1=1;loop1<para.lep.muon.CUT_num;loop1++){
				pt   = muon[loop1-1]->PT;
				y    = std::abs(muon[loop1-1]->Eta);
				if( para.lep.muon.JCUT_pt  [loop1] == true && ( pt     < para.lep.muon.CUT_ptd  [loop1] || pt     > para.lep.muon.CUT_ptu  [loop1] )){para.debug.Message(4,22,"false: muon pt cut",loop1,pt);return(false);}//endif
				if( para.lep.muon.JCUT_eta [loop1] == true && ( y      < para.lep.muon.CUT_etad [loop1] || y      > para.lep.muon.CUT_etau [loop1] )){para.debug.Message(4,22,"false: muon etacut",loop1, y);return(false);}//endif
			}
			for(loop1=0;loop1<loopm;loop1++){
				if(loop1<para.signal.NUM_lep){
					AFill_Plot(para,plots->fLepPT[loop1],muon[loop1]->PT);
					AFill_Plot(para,plots->fLepY[loop1] ,muon[loop1]->Eta);
				} 
			}
			return(true);
		}
	}
	else if(para.lep.SWITCH &&  para.lep.muon.SWITCH){
		if(loopm>=1&& loopm>=para.signal.NUM_muon){
			for(loop1=1;loop1<para.lep.muon.CUT_num;loop1++){
				pt   = muon[loop1-1]->PT;
				y    = std::abs(muon[loop1-1]->Eta);
				if( para.lep.muon.JCUT_pt  [loop1] == true && ( pt     < para.lep.muon.CUT_ptd  [loop1] || pt     > para.lep.muon.CUT_ptu  [loop1] )){para.debug.Message(4,22,"false: muon pt cut",loop1,pt);return(false);}//endif
				if( para.lep.muon.JCUT_eta [loop1] == true && ( y      < para.lep.muon.CUT_etad [loop1] || y      > para.lep.muon.CUT_etau [loop1] )){para.debug.Message(4,22,"false: muon etacut",loop1, y);return(false);}//endif
			}
			for(loop1=0;loop1<loopm;loop1++){
				if(loop1<para.signal.NUM_muon){
					AFill_Plot(para,plots->fMuonPT[loop1],muon[loop1]->PT);
					AFill_Plot(para,plots->fMuonY[loop1] ,muon[loop1]->Eta);
				} 
			}
			return(true);
		}
		else{para.debug.Message(3,22,"false: muon num cut",loopm);return(false);}
	}
	return(true);
}




bool GetFinalState_detector_jet(CDraw &para, TClonesArray *branchJet, MyPlots *plots,std::vector<Jet*> &jet){
	int loop1=0,loopj=0,num;
	float pt,y,mass;

	para.debug.Message(3,23,"in the detector jet cut function");
	if (para.signal.NUM_jets==0){return(true);} 

	num = branchJet->GetEntriesFast();
	AFill_Plot(para,plots->fJetnum,num);

	for(loop1=0;loop1<num;loop1++){
		Jet *jet_ptr = (Jet*) branchJet->At(loop1);
		pt = jet_ptr->PT;
		int taujet = jet_ptr->TauTag;
		y  = std::abs(jet_ptr->Eta);
		mass = jet_ptr->Mass;
		//if( para.jet.jets.JCUT_pt  [0] == true && ( pt     < para.jet.jets.CUT_ptd  [0] || pt     > para.jet.jets.CUT_ptu  [0] )){para.debug.ShowMessage(4,23,"false: jets single jet pt",  pt  );continue;}//endif
		if( para.jet.jets.JCUT_pt  [0] == true && ( pt     < 20 || pt     > para.jet.jets.CUT_ptu  [0] )){ShowMessage(4,23,"false: jets single jet pt",  pt  );continue;}//endif
		if( para.jet.jets.JCUT_mass[0] == true && ( mass   < para.jet.jets.CUT_massd[0] || mass   > para.jet.jets.CUT_massu[0] )){para.debug.Message(4,23,"false: jets single jet eta", y   );continue;}//endif
		if( para.jet.jets.JCUT_eta [0] == true && ( y      < para.jet.jets.CUT_etad [0] || y      > para.jet.jets.CUT_etau [0] )){para.debug.Message(4,23,"false: jets single jet mass",mass);continue;}//endif
		loopj++;
		jet.push_back(jet_ptr);
	}//endfor jet_Cindex

	if(loopj>=1&&loopj>=para.signal.NUM_jets){
		for(loop1=1;loop1<para.jet.jets.CUT_num;loop1++){
			pt   = jet[loop1-1]->PT;
			y    = std::abs(jet[loop1-1]->Eta);
			mass = jet[loop1-1]->Mass;
			if( para.jet.jets.JCUT_pt  [loop1] == true && ( pt     < para.jet.jets.CUT_ptd  [loop1] || pt     > para.jet.jets.CUT_ptu  [loop1] )){para.debug.Message(4,23,"false: jets single jet pt  ", loop1,  pt);return(false);}//endif
			if( para.jet.jets.JCUT_mass[loop1] == true && ( mass   < para.jet.jets.CUT_massd[loop1] || mass   > para.jet.jets.CUT_massu[loop1] )){para.debug.Message(4,23,"false: jets single jet mass", loop1,   y);return(false);}//endif
			if( para.jet.jets.JCUT_eta [loop1] == true && ( y      < para.jet.jets.CUT_etad [loop1] || y      > para.jet.jets.CUT_etau [loop1] )){para.debug.Message(4,23,"false: jets single jet eta ", loop1,mass);return(false);}//endif
		}

		for(loop1=0;loop1<loopj;loop1++){
			if(loop1<para.signal.NUM_jets){
				AFill_Plot(para,plots->fJetPT[loop1],jet[loop1]->PT);
				AFill_Plot(para,plots->fJetY[loop1] ,jet[loop1]->Eta);
			} 
		}
		return(true);
	}
	else{para.debug.Message(3,23,"false: jet num is small",loopj); return(false);}
}





bool GetFinalState_detector_met(CDraw &para, TClonesArray *branchMissingET, MyPlots *plots,std::vector<MissingET*> &met){
	float pt;

	para.debug.Message(3,25,"in the missingET cut function");
	MissingET *met_ptr = (MissingET*) branchMissingET->At(0);
	pt = met_ptr->MET;

	if(para.met.JCUT_pt[0] == true && (pt<para.met.CUT_ptd[0] || pt>para.met.CUT_ptu[0])){para.debug.Message(3,25,"false: missingET", pt);return(false);}
	AFill_Plot(para,plots->fMissingET,pt);
	met.push_back(met_ptr);
	return(true);
}




bool GetFinalState_detector_jet_classify(CDraw &para, AnalyseClass& analyse, std::vector<Jet*> &jet,std::vector<Jet*> &bjet, std::vector<Jet*> &cjet, std::vector<Jet*> &qjet, std::vector<Jet*>& taujet, std::vector<Jet*> &untagjet, MyPlots *plots){
	int loop1=0,loopb=0,loopc=0,looptau=0,loopq=0,jnum;
	float pt,mass,y;

	para.debug.Message(3,26,"in the detector tagged jet cut function");
	if (para.signal.NUM_jets==0){para.debug.Message(3,26,"para.signal.NUM_jets=0 in Gettagjet");return(true);}

	jnum = jet.size();
	if (jnum==0){para.debug.Message(3,26,"jet size=0 in Gettagjet");return(false);}

	for(loop1=0;loop1<jnum;loop1++){

		pt   = jet.at(loop1)->PT;
		y    = std::abs(jet.at(loop1)->Eta);
		mass = jet.at(loop1)->Mass;

		if(jet.at(loop1)->BTag==1 &&  para.jet.bjet.SWITCH){
			if( para.jet.bjet.JCUT_pt  [0] == true && ( pt     < para.jet.bjet.CUT_ptd  [0] || pt     > para.jet.bjet.CUT_ptu  [0] )){para.debug.Message(4,26,"false: bjet single jet pt  ", loop1,  pt);continue;}//endif
			if( para.jet.bjet.JCUT_mass[0] == true && ( mass   < para.jet.bjet.CUT_massd[0] || mass   > para.jet.bjet.CUT_massu[0] )){para.debug.Message(4,26,"false: bjet single jet mass", loop1,mass);continue;}//endif
			if( para.jet.bjet.JCUT_eta [0] == true && ( y      < para.jet.bjet.CUT_etad [0] || y      > para.jet.bjet.CUT_etau [0] )){para.debug.Message(4,26,"false: bjet single jet eta ", loop1,   y);continue;}//endif
			loopb++;
			//when write this here, instead of below, it can make untagjet sorted by pt
			if(loopb>para.signal.NUM_bjet){
				untagjet.push_back(jet.at(loop1));
			}
			bjet.push_back(jet.at(loop1));
		}

		else if(jet.at(loop1)->BTag==2 && para.jet.cjet.SWITCH){
			if( para.jet.cjet.JCUT_pt  [0] == true && ( pt     < para.jet.cjet.CUT_ptd  [0] || pt     > para.jet.cjet.CUT_ptu  [0] )){para.debug.Message(4,26,"false: cjet single jet pt  ", loop1,  pt);continue;}//endif
			if( para.jet.cjet.JCUT_mass[0] == true && ( mass   < para.jet.cjet.CUT_massd[0] || mass   > para.jet.cjet.CUT_massu[0] )){para.debug.Message(4,26,"false: cjet single jet mass", loop1,mass);continue;}//endif
			if( para.jet.cjet.JCUT_eta [0] == true && ( y      < para.jet.cjet.CUT_etad [0] || y      > para.jet.cjet.CUT_etau [0] )){para.debug.Message(4,26,"false: cjet single jet eta ", loop1,   y);continue;}//endif
			loopc++;
			if(loopc>para.signal.NUM_cjet){
				untagjet.push_back(jet.at(loop1));
			}
			cjet.push_back(jet.at(loop1));
		}
		else if(jet.at(loop1)->TauTag==1 && para.jet.taujet.SWITCH){
			if( para.jet.taujet.JCUT_pt  [0] == true && ( pt          < para.jet.taujet.CUT_ptd  [0] || pt          > para.jet.taujet.CUT_ptu  [0] )){para.debug.Message(4,26,"false: cjet single jet pt  ", loop1,  pt);continue;}//endif
			if( para.jet.taujet.JCUT_mass[0] == true && ( mass        < para.jet.taujet.CUT_massd[0] || mass        > para.jet.taujet.CUT_massu[0] )){para.debug.Message(4,26,"false: cjet single jet mass", loop1,mass);continue;}//endif
			if( para.jet.taujet.JCUT_eta [0] == true && ( y           < para.jet.taujet.CUT_etad [0] || y           > para.jet.taujet.CUT_etau [0] )){para.debug.Message(4,26,"false: cjet single jet eta ", loop1,   y);continue;}//endif
			looptau++;
			if(looptau>para.signal.NUM_taujet){
				untagjet.push_back(jet.at(loop1));
			}
			taujet.push_back(jet.at(loop1));
		}
		else{
			if( para.jet.qjet.JCUT_pt  [0] == true && ( pt     < para.jet.qjet.CUT_ptd  [0] || pt     > para.jet.qjet.CUT_ptu  [0] )){para.debug.Message(4,26,"false: qjet single jet pt  ", loop1,  pt);continue;}//endif
			if( para.jet.qjet.JCUT_mass[0] == true && ( mass   < para.jet.qjet.CUT_massd[0] || mass   > para.jet.qjet.CUT_massu[0] )){para.debug.Message(4,26,"false: qjet single jet pt  ", loop1,  pt);continue;}//endif
			if( para.jet.qjet.JCUT_eta [0] == true && ( y      < para.jet.qjet.CUT_etad [0] || y      > para.jet.qjet.CUT_etau [0] )){para.debug.Message(4,26,"false: qjet single jet pt  ", loop1,  pt);continue;}//endif
			loopq++;
			untagjet.push_back(jet.at(loop1));
			qjet.push_back(jet.at(loop1));
		}
	}	



	if(loopb>=para.signal.NUM_bjet){
		if(loopb>=1){
			for(loop1=1;loop1<para.jet.bjet.CUT_num;loop1++){
				pt   = bjet[loop1-1]->PT;
				y    = std::abs(bjet[loop1-1]->Eta);
				mass = bjet[loop1-1]->Mass;
				if( para.jet.bjet.JCUT_pt  [loop1] == true && ( pt     < para.jet.bjet.CUT_ptd  [loop1] || pt     > para.jet.bjet.CUT_ptu  [loop1] )){para.debug.Message(4,26,"false: bjet single jet pt  ", loop1,  pt);return(false);}//endif
				if( para.jet.bjet.JCUT_eta [loop1] == true && ( y      < para.jet.bjet.CUT_etad [loop1] || y      > para.jet.bjet.CUT_etau [loop1] )){para.debug.Message(4,26,"false: bjet single jet eta ", loop1,   y);return(false);}//endif
				if( para.jet.bjet.JCUT_mass[loop1] == true && ( mass   < para.jet.bjet.CUT_massd[loop1] || mass   > para.jet.bjet.CUT_massu[loop1] )){para.debug.Message(4,26,"false: bjet single jet mass", loop1,mass);return(false);}//endif
			}
			analyse.counter.getCounter("basic_tagged_bjet");
			for(loop1=0;loop1<loopb;loop1++){
				if(loop1<para.signal.NUM_bjet){
					AFill_Plot(para,plots->fBJetPT[loop1],bjet[loop1]->PT);
					AFill_Plot(para,plots->fBJetY[loop1] ,bjet[loop1]->Eta);
				} 
			}
		}
	}
	else{para.debug. Message(4,26,"bjet");return(false);}

	if(para.signal.NUM_bjet!=0){
		AFill_Plot(para,plots->fBJetnum,loopb);
	}

	if(loopc>=para.signal.NUM_cjet){
		if(loopc>=1){
			for(loop1=1;loop1<para.jet.cjet.CUT_num;loop1++){
				pt   = cjet[loop1-1]->PT;
				y    = std::abs(cjet[loop1-1]->Eta);
				mass = cjet[loop1-1]->Mass;
				if( para.jet.cjet.JCUT_pt  [loop1] == true && ( pt     < para.jet.cjet.CUT_ptd  [loop1] || pt     > para.jet.cjet.CUT_ptu  [loop1] )){para.debug.Message(4,26,"false: cjet single jet pt  ", loop1,  pt);return(false);}//endif
				if( para.jet.cjet.JCUT_eta [loop1] == true && ( y      < para.jet.cjet.CUT_etad [loop1] || y      > para.jet.cjet.CUT_etau [loop1] )){para.debug.Message(4,26,"false: cjet single jet eta ", loop1,   y);return(false);}//endif
				if( para.jet.cjet.JCUT_mass[loop1] == true && ( mass   < para.jet.cjet.CUT_massd[loop1] || mass   > para.jet.cjet.CUT_massu[loop1] )){para.debug.Message(4,26,"false: cjet single jet mass", loop1,mass);return(false);}//endif
			}
			analyse.counter.getCounter("basic_tagged_cjet");
			for(loop1=0;loop1<loopc;loop1++){
				if(loop1<para.signal.NUM_cjet){
					AFill_Plot(para,plots->fCJetPT[loop1],cjet[loop1]->PT);
					AFill_Plot(para,plots->fCJetY[loop1] ,cjet[loop1]->Eta);
				} 
			}
		}
	}
	else{para.debug.Message(4,26,"cjet");return(false);}

	if(para.signal.NUM_cjet!=0){
		AFill_Plot(para,plots->fBJetnum,loopc);
	}

	if(looptau>=para.signal.NUM_taujet){
		if(looptau>=1){
			for(loop1=1;loop1<para.jet.taujet.CUT_num;loop1++){
				pt   = taujet[loop1-1]->PT;
				y    = std::abs(taujet[loop1-1]->Eta);
				mass = taujet[loop1-1]->Mass;
				if( para.jet.taujet.JCUT_pt  [loop1] == true && ( pt          < para.jet.taujet.CUT_ptd  [loop1] || pt          > para.jet.taujet.CUT_ptu  [loop1] )){para.debug.Message(4,26,"false: taujet single jet pt  ", loop1,  pt);return(false);}//endif
				if( para.jet.taujet.JCUT_eta [loop1] == true && ( y           < para.jet.taujet.CUT_etad [loop1] || y           > para.jet.taujet.CUT_etau [loop1] )){para.debug.Message(4,26,"false: taujet single jet eta ", loop1,   y);return(false);}//endif
				if( para.jet.taujet.JCUT_mass[loop1] == true && ( mass        < para.jet.taujet.CUT_massd[loop1] || mass        > para.jet.taujet.CUT_massu[loop1] )){para.debug.Message(4,26,"false: taujet single jet mass", loop1,mass);return(false);}//endif
			}
			analyse.counter.getCounter("basic_tagged_taujet");
			for(loop1=0;loop1<looptau;loop1++){
				if(loop1<para.signal.NUM_taujet){
					AFill_Plot(para,plots->fTauJetPT[loop1],taujet[loop1]->PT);
					AFill_Plot(para,plots->fTauJetY[loop1] ,taujet[loop1]->Eta);
				} 
			}
		}
	}
	else{para.debug.Message(4,26,"taujet");return(false);}

	if(para.signal.NUM_taujet!=0){
		AFill_Plot(para,plots->fTauJetnum,looptau);
	}

	if(loopq>=para.signal.NUM_qjet){
		if(loopq>=1){
			for(loop1=1;loop1<para.jet.qjet.CUT_num;loop1++){
				pt   = qjet[loop1-1]->PT;
				y    = std::abs(qjet[loop1-1]->Eta);
				mass = qjet[loop1-1]->Mass;
				if( para.jet.qjet.JCUT_pt  [loop1] == true && ( pt     < para.jet.qjet.CUT_ptd  [loop1] || pt     > para.jet.qjet.CUT_ptu  [loop1] )){para.debug.Message(4,26,"false: qjet single jet pt  ", loop1,  pt);return(false);}//endif
				if( para.jet.qjet.JCUT_eta [loop1] == true && ( y      < para.jet.qjet.CUT_etad [loop1] || y      > para.jet.qjet.CUT_etau [loop1] )){para.debug.Message(4,26,"false: qjet single jet eta ", loop1,   y);return(false);}//endif
				if( para.jet.qjet.JCUT_mass[loop1] == true && ( mass   < para.jet.qjet.CUT_massd[loop1] || mass   > para.jet.qjet.CUT_massu[loop1] )){para.debug.Message(4,26,"false: qjet single jet mass", loop1,mass);return(false);}//endif
			}
			analyse.counter.getCounter("basic_tagged_qjet");
			for(loop1=0;loop1<loopq;loop1++){
				if(loop1<para.signal.NUM_qjet){
					AFill_Plot(para,plots->fQJetPT[loop1],qjet[loop1]->PT);
					AFill_Plot(para,plots->fQJetY[loop1] ,qjet[loop1]->Eta);
				} 
			}
		}
	}
	else{para.debug.Message(4,26,"qjet",loopq);;return(false);}

	if(para.signal.NUM_qjet!=0){
		AFill_Plot(para,plots->fQJetnum,loopq);
	}

	if(untagjet.size()>=para.signal.NUM_untagjet){
		if(untagjet.size()>=1){
			for(loop1=1;loop1<para.jet.untagjet.CUT_num;loop1++){
				pt   = untagjet[loop1-1]->PT;
				y    = std::abs(untagjet[loop1-1]->Eta);
				mass = untagjet[loop1-1]->Mass;
				if( para.jet.untagjet.JCUT_pt  [loop1] == true && ( pt     < para.jet.untagjet.CUT_ptd  [loop1] || pt     > para.jet.untagjet.CUT_ptu  [loop1] )){para.debug.Message(4,23,"false: untagjet single jet pt  ", loop1,  pt);return(false);}//endif
				if( para.jet.untagjet.JCUT_eta [loop1] == true && ( y      < para.jet.untagjet.CUT_etad [loop1] || y      > para.jet.untagjet.CUT_etau [loop1] )){para.debug.Message(4,23,"false: untagjet single jet eta ", loop1,   y);return(false);}//endif
				if( para.jet.untagjet.JCUT_mass[loop1] == true && ( mass   < para.jet.untagjet.CUT_massd[loop1] || mass   > para.jet.untagjet.CUT_massu[loop1] )){para.debug.Message(4,23,"false: untagjet single jet mass", loop1,mass);return(false);}//endif
			}
			for(loop1=0;loop1<untagjet.size();loop1++){
				if(loop1<para.signal.NUM_untagjet){
					AFill_Plot(para,plots->fUJetPT[loop1],untagjet[loop1]->PT);
					AFill_Plot(para,plots->fUJetY[loop1] ,untagjet[loop1]->Eta);
				} 
			}
		}
	}
	else{para.debug.Message(4,26,"untagjet");return(false);}

	if(para.signal.NUM_bjet!=0||para.signal.NUM_cjet!=0||para.signal.NUM_qjet!=0){
		AFill_Plot(para,plots->fUJetnum,untagjet.size());
	}
	return(true);

}




void GetFinalState_detector_pseudojet(TClonesArray *branchJet, std::vector<fastjet::PseudoJet> &jet){
	int loop1=0,num;
	num = branchJet->GetEntries();


	for(loop1=0;loop1<num;loop1++){
		Jet *jet_ptr = (Jet*) branchJet->At(loop1);
		fastjet::PseudoJet candi=fastjet::PseudoJet(jet_ptr->PT*TMath::Cos(jet_ptr->Phi),jet_ptr->PT*TMath::Sin(jet_ptr->Phi),jet_ptr->PT*TMath::SinH(jet_ptr->Eta),jet_ptr->PT*TMath::CosH(jet_ptr->Eta));
		jet.push_back(candi);
	}//endfor jet_Cindex
}
