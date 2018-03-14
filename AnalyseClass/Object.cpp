
#include "AnalyseClass/Object.h"
void AObject::Read_SLCIO_MCParticle(CDraw &para, ASlcio &var){
	para.debug.Message(2,87,"In AObject::Read_SLCIO_MCParticle,  begin");
	AParticle::Reset_Global_ID();
	int num=var.nmcp;
	para.debug.Message(2,87,"In AObject::Read_SLCIO_MCParticle,  begin to loop for",num,"times");
	for(int i=0;i<num;i++){
		if(var.mcgst[i]==1){
			AParticle MCp(var.mcmox[i],var.mcmoy[i],var.mcmoz[i],var.mcene[i],var.mccha[i],var.mcpdg[i]);
			MCp._Is_MC_Particle.Set();
			OMCParticle_ori.push_back(MCp);
		}
		else if(var.mcgst[i]==2){
			if(std::abs(var.mcpdg[i])==5){
				AParticle MCp(var.mcmox[i],var.mcmoy[i],var.mcmoz[i],var.mcene[i],var.mccha[i],var.mcpdg[i]);
				MCp._Is_MC_Particle.Set();
				OMCbquark_ori.push_back(MCp);
			}
			else if(std::abs(var.mcpdg[i])==4){
				AParticle MCp(var.mcmox[i],var.mcmoy[i],var.mcmoz[i],var.mcene[i],var.mccha[i],var.mcpdg[i]);
				MCp._Is_MC_Particle.Set();
				OMCcquark_ori.push_back(MCp);
			}
		}
	}


	para.debug.Message(2,87,"In AObject::Read_SLCIO_MCParticle,  link to MCParticle ptr");
	for(int i=0;i<OMCParticle_ori.size();i++){
		OMCParticle.push_back(&OMCParticle_ori[i]);
	}
	for(int i=0;i<OMCbquark_ori.size();i++){
		OMCbquark.push_back(&OMCbquark_ori[i]);
	}
	for(int i=0;i<OMCcquark_ori.size();i++){
		OMCcquark.push_back(&OMCcquark_ori[i]);
	}
	IsReadMCPar = true;
	para.debug.Message(2,87,"In AObject::Read_SLCIO_MCParticle,  end");
}

void AObject::Read_SLCIO_ReconstructedParticle(CDraw &para, ASlcio &var){
	AParticle::Reset_Global_ID();
	int num=var.nmcp;
	for(int i=0;i<num;i++){
		if(var.mcgst[i]==1){
			AParticle MCp(var.mcmox[i],var.mcmoy[i],var.mcmoz[i],var.mcene[i],var.mccha[i],var.mcpdg[i]);
			MCp._Is_MC_Particle.Set();
			OMCParticle_ori.push_back(MCp);
		}
	}
	for(int i=0;i<OMCParticle_ori.size();i++){
		OMCParticle.push_back(&OMCParticle_ori[i]);
	}
}

void AObject::Read_STDHep_Particle(CDraw &para, AStdhep &var){
	AParticle::Reset_Global_ID();
	////		int num=var.nmcp;
	////		for(int i=0;i<num;i++){
	////			AParticle MCp(var.mcmox[i],var.mcmoy[i],var.mcmoz[i],var.mcene[i],var.mccha[i],var.mcpdg[i]);
	////			MCp.setIsMCParticle(true);
	////			OMCParticle.push_back(MCp);
	////		}
}

void AObject::Read_Delphes_MCParticle(CDraw &para, ADelphes &var){
	para.debug.Message(2,84,"In AObject::Read_Delphes_MCParticle,  begin");
	AParticle::Reset_Global_ID();
	GenParticle* gen;
	int num=var.branchParticle->GetEntries();
	para.debug.Message(2,84,"In AObject::Read_Delphes_MCParticle,  begin to loop for",num,"times");
	for(int i=0;i<num;i++){
		gen=(GenParticle*) var.branchParticle->At(i);

		if(gen->Status==1){
			AParticle MCp(gen->Px,gen->Py,gen->Pz,gen->E,gen->Charge,gen->PID);
			MCp._Is_MC_Particle.Set();
			OMCParticle_ori.push_back(MCp);
		}
		else if(gen->Status==2){
			if(std::abs(gen->PID)==5){
				AParticle MCp(gen->Px,gen->Py,gen->Pz,gen->E,gen->Charge,gen->PID);
				MCp._Is_MC_Particle.Set();
				OMCbquark_ori.push_back(MCp);
			}
			else if(std::abs(gen->PID)==4){
				AParticle MCp(gen->Px,gen->Py,gen->Pz,gen->E,gen->Charge,gen->PID);
				MCp._Is_MC_Particle.Set();
				OMCcquark_ori.push_back(MCp);
			}
		}
	}
	para.debug.Message(2,84,"In AObject::Read_Delphes_MCParticle,  link to MCParticle ptr");
	for(int i=0;i<OMCParticle_ori.size();i++){
		OMCParticle.push_back(&OMCParticle_ori[i]);
	}
	for(int i=0;i<OMCbquark_ori.size();i++){
		OMCbquark.push_back(&OMCbquark_ori[i]);
	}
	for(int i=0;i<OMCcquark_ori.size();i++){
		OMCcquark.push_back(&OMCcquark_ori[i]);
	}
	IsReadMCPar = true;
	para.debug.Message(2,84,"In AObject::Read_Delphes_MCParticle,  end");
}

void AObject::Read_Delphes_ReconstructedParticle(CDraw &para, ADelphes &var){
	AParticle::Reset_Global_ID();
	Track* track;
	int num1=var.branchEFlowTrack->GetEntries();
	int num2=var.branchElectron->GetEntries();
	int num3=var.branchMuon->GetEntries();
	int num4=var.branchEFlowNeutralHadron->GetEntries();
	int num5=var.branchPhoton->GetEntries();
	for(int i=0;i<num1;i++){
		track=(Track*) var.branchEFlowTrack->At(i);
		AParticle MCp(track->PT*TMath::Cos(track->Phi),track->PT*TMath::Sin(track->Phi),track->PT*TMath::SinH(track->Eta),track->PT*TMath::CosH(track->Eta),track->Charge,track->PID);
		MCp._Is_MC_Particle.Set();
		OMCParticle_ori.push_back(MCp);
	}
	for(int i=0;i<OMCParticle_ori.size();i++){
		OMCParticle.push_back(&OMCParticle_ori[i]);
	}
}

void AObject::Read_Delphes_AnalysedParticle(CDraw &para, ADelphes &var){
	AParticle::Reset_Global_ID();
	Jet* jet;
	int num=var.branchJet->GetEntries();
	for(int i=0;i<num;i++){
		jet=(Jet*) var.branchJet->At(i);
		AParticle MCp(jet->PT*TMath::Cos(jet->Phi),jet->PT*TMath::Sin(jet->Phi),jet->PT*TMath::SinH(jet->Eta),jet->PT*TMath::CosH(jet->Eta),jet->Charge,100001);
		MCp._Is_MC_Particle.Set();
		OMCParticle_ori.push_back(MCp);
	}
	for(int i=0;i<OMCParticle_ori.size();i++){
		OMCParticle.push_back(&OMCParticle_ori[i]);
	}
}


void AObject::Init(AnalyseClass &analysis, CDraw &para){
	IsReadMCPar = false;
	OMCSpecies              .Init();

	OMCLep                  .Init();

	OMCVisible_ori          .Init();
	OMCVisible              = NULL ;

	OMCInvisible_ori        .Init();
	OMCInvisible            = NULL ; 

	OMCVisibleWOBestMuon_ori.Init();
	OMCVisibleWOBestMuon    = NULL ;
	OMCVisibleWOBestElec_ori.Init();
	OMCVisibleWOBestElec    = NULL ;
	OMCVisibleWOBestLep_ori .Init();
	OMCVisibleWOBestLep     = NULL ;

	OMCJet                  .Init();

	info                    .Init();


	para.debug.Message(2,83,"In AObject::Init,  begin to choose mode",para.flow.begin_object);
	if(para.flow.begin_object=="slcio_particle"){
		para.debug.Message(2,83,"In AObject::Init,  begin to Read Particle","slcio MCparticle");
		Read_SLCIO_MCParticle(para,analysis.slcio); 
	}
	else if(para.flow.begin_object=="slcio_equipment"){
		para.debug.Message(2,83,"In AObject::Init,  begin to Read Particle","slcio reconstructed particle");
		Read_SLCIO_ReconstructedParticle(para,analysis.slcio); 
	}
	else if(para.flow.begin_object=="stdhep"){
		para.debug.Message(2,83,"In AObject::Init,  begin to Read Particle","stdhep");
		Read_STDHep_Particle(para,analysis.stdhep); 
	}
	else if(para.flow.begin_object=="delphes_particle"){
		para.debug.Message(2,83,"In AObject::Init,  begin to Read Particle","delphes particle");
		Read_Delphes_MCParticle(para,analysis.delphes); 
	}
	else if(para.flow.begin_object=="delphes_equipment"){
		para.debug.Message(2,83,"In AObject::Init,  begin to Read Particle","delphes equipment ");
		Read_Delphes_ReconstructedParticle(para,analysis.delphes); 
	}
	else if(para.flow.begin_object=="delphes_detector"){
		para.debug.Message(2,83,"In AObject::Init,  begin to Read Particle","delphes detector ");
		Read_Delphes_AnalysedParticle(para,analysis.delphes); 
	}
	else{
		ShowMessage(2,"wrong para for para.flow.begin_object",para.flow.begin_object);
	}
	para.debug.Message(2,83,"In AObject::Init,  end");
}



void AObject::Clear(){
	if(!Vneutralhad      .empty()){Vneutralhad      .clear();}
	if(!Vjet             .empty()){Vjet             .clear();}
	if(!VPseudoJet       .empty()){VPseudoJet       .clear();}
	if(!VPseudoElec      .empty()){VPseudoElec      .clear();}
	if(!VPseudoMuon      .empty()){VPseudoMuon      .clear();}
	if(!VPseudoPhoton    .empty()){VPseudoPhoton    .clear();}
	if(!VPseudoMet       .empty()){VPseudoMet       .clear();}
	if(!Vbjet            .empty()){Vbjet            .clear();}
	if(!Vcjet            .empty()){Vcjet            .clear();}
	if(!Vqjet            .empty()){Vqjet            .clear();}
	if(!Vtaujet          .empty()){Vtaujet          .clear();}
	if(!Vtagjet          .empty()){Vtagjet          .clear();}
	if(!Vuntagjet        .empty()){Vuntagjet        .clear();}
	if(!Vbquark          .empty()){Vbquark          .clear();}
	if(!Vcquark          .empty()){Vcquark          .clear();}
	if(!Velec            .empty()){Velec            .clear();}
	if(!Vmuon            .empty()){Vmuon            .clear();}
	if(!Vtau             .empty()){Vtau             .clear();}
	if(!Vphoton          .empty()){Vphoton          .clear();}
	if(!Vmet             .empty()){Vmet             .clear();}
	if(!Vcombine_jet1    .empty()){Vcombine_jet1    .clear();}
	if(!Vcombine_jet2    .empty()){Vcombine_jet2    .clear();}
	if(!Vcombine_elec1   .empty()){Vcombine_elec1   .clear();}
	if(!Vcombine_elec2   .empty()){Vcombine_elec2   .clear();}
	if(!Vcombine_muon1   .empty()){Vcombine_muon1   .clear();}
	if(!Vcombine_muon2   .empty()){Vcombine_muon2   .clear();}
	if(!Vcombine_photon1 .empty()){Vcombine_photon1 .clear();}
	if(!Vcombine_photon2 .empty()){Vcombine_photon2 .clear();}

	IsReadMCPar          =false;
	/**********************************************************************
	 * @name variable from reading the file 
	**********************************************************************/
    if(!OMCWOIsoLep      .empty()){
    	OMCWOIsoLep      .clear();
    }
    if(!OMCWOBestLep     .empty()){
    	OMCWOBestLep     .clear();
    }
    if(!OMCCombinedPhoton.empty()){
    	OMCCombinedPhoton.clear();
    }
    
    OMCSpecies.Clear();

    if(!OMCbquark        .empty()){
    	OMCbquark        .clear();
    }
    if(!OMCbquark_ori    .empty()){
    	OMCbquark_ori    .clear();
    }
    if(!OMCcquark        .empty()){
    	OMCcquark        .clear();
    }
    if(!OMCcquark_ori    .empty()){
    	OMCcquark_ori    .clear();
    }
    if(!OMCParticle      .empty()){
    	OMCParticle      .clear();
    }
    if(!OMCParticle_ori  .empty()){
    	OMCParticle_ori  .clear();
    }
    IsReadMCPar          =false;


    /**********************************************************************
     * @name variable new generated  
    **********************************************************************/
    if(!OMCVisible_Vec         .empty()){
    	OMCVisible_Vec         .clear();
    }

    if(!OMCVisibleWOBestElec_Vec.empty()){
    	OMCVisibleWOBestElec_Vec.clear();
    }

    if(!OMCVisibleWOBestMuon_Vec.empty()){
    	OMCVisibleWOBestMuon_Vec.clear();
    }


    if(!OMCVisibleWOBestLep_Vec.empty()){
    	OMCVisibleWOBestLep_Vec.clear();
    }

    /**********************************************************************
     * @name variable mixed   
    **********************************************************************/
	if(OMCLep.Elec_Pool().Is_DS_Used()){
		OMCLep.Elec_Pool().Clear_Ptr();
	}
	if(OMCLep.Muon_Pool().Is_DS_Used()){
		OMCLep.Muon_Pool().Clear_Ptr();
	}
	if(OMCJet.Jets_Pool().Is_SS_Used()){
		OMCJet.Jets_Pool().Clear_Ptr();
	}
	OMCJet.Clear_Ptr();
	OMCJet.Clear();
    OMCLep.Clear();
}


void AObject::setParticleSpecies(CDraw &para){
	if(IsReadMCPar){
		OMCSpecies.get_particle_species(OMCParticle);
		para.debug.Message(2,96,"in AObject::setParticleSpecies",OMCSpecies._species);
	}
}

void AObject::getVisible(CDraw &para){
	OMCVisible_Vec.clear();
	for( int i = 0; i < OMCParticle.size(); i++ ){
		if(std::abs(OMCParticle[i]->PID())==12||std::abs(OMCParticle[i]->PID())==14||std::abs(OMCParticle[i]->PID())==16){
		}
		else{
			OMCVisible_Vec.push_back(OMCParticle[i]);
		}
	}
	AParticle pnew=Get_Sum(OMCVisible_Vec);
	OMCVisible_ori.Equal(pnew);
	OMCVisible = &OMCVisible_ori;
}

void AObject::getInVisible(CDraw &para){
	OMCInvisible_ori       = Get_Left(para.detector.energy, para.detector.collider_angle, OMCVisible_Vec);
	OMCInvisible           = &OMCInvisible_ori;
}

void AObject::setAllLepPool(CDraw &para){
	OMCLep.Set_All_Lep_Pool(OMCParticle,para.lep,OMCWOIsoLep);
}

void AObject::findBestLep(CDraw &para){
	para.debug.Message(2,98,"in AObject::findBestLep, begin");
	OMCLep.Find_All_Best_Lep(para);
	para.debug.Message(2,98,"in AObject::findBestLep, finishing find all best lep, begin to photon recovery");
	//OMCLep.All_Photon_Recovery(para.lep,OMCWOIsoLep, OMCCombinedPhoton);
	para.debug.Message(2,98,"in AObject::findBestLep, end");
}

void AObject::getVisibleWOBestLep(CDraw &para){
	para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, begin");
	para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, OMCLep.Muon_Pool().Has_DS_Best()",OMCLep.Muon_Pool().Has_DS_Best());
	if(OMCLep.Muon_Pool().Has_DS_Best()&& !OMCLep.Elec_Pool().Has_DS_Best()&& !OMCLep.Lep_Pool().Has_DS_Best()){
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, begin muon");
		AParticleType vis_tmp= OMCVisible_Vec- OMCCombinedPhoton;
		for(int i=0;i<OMCLep.Muon_Pool().Choosed_DS_Pair().size();i++){
			vis_tmp = vis_tmp - OMCLep.Muon_Pool().Best_DS_Pair_ori()[i];
		}
		OMCVisibleWOBestMuon_Vec = vis_tmp;
                OMCVisibleWOBestLep_Vec  = vis_tmp;
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get Vec",OMCVisibleWOBestMuon_Vec);
		OMCVisibleWOBestMuon_ori= Get_Sum(OMCVisibleWOBestMuon_Vec);
                OMCVisibleWOBestLep_ori= Get_Sum(OMCVisibleWOBestLep_Vec);
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get ori",OMCVisibleWOBestMuon_ori);
		OMCVisibleWOBestMuon = &OMCVisibleWOBestMuon_ori;
		OMCVisibleWOBestLep  = &OMCVisibleWOBestLep_ori;
                para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get pointer",*OMCVisibleWOBestMuon);
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, end muon");
                return;
	}



	para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, OMCLep.Elec_Pool().Has_DS_Best()",OMCLep.Elec_Pool().Has_DS_Best());
	if(OMCLep.Elec_Pool().Has_DS_Best()&& !OMCLep.Muon_Pool().Has_DS_Best()&& !OMCLep.Lep_Pool().Has_DS_Best()){
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, begin elec");
		AParticleType vis_tmp= OMCVisible_Vec- OMCCombinedPhoton;
		for(int i=0;i<OMCLep.Elec_Pool().Choosed_DS_Pair().size();i++){
			vis_tmp = vis_tmp - OMCLep.Elec_Pool().Best_DS_Pair_ori()[i];
		}
		OMCVisibleWOBestElec_Vec = vis_tmp;
                OMCVisibleWOBestLep_Vec  = vis_tmp;
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get Vec",OMCVisibleWOBestElec_Vec);
		OMCVisibleWOBestElec_ori= Get_Sum(OMCVisibleWOBestElec_Vec);
                OMCVisibleWOBestLep_ori= Get_Sum(OMCVisibleWOBestLep_Vec);
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get ori",OMCVisibleWOBestElec_ori);
		OMCVisibleWOBestElec = &OMCVisibleWOBestElec_ori;
                OMCVisibleWOBestLep  = &OMCVisibleWOBestLep_ori;
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get pointer",*OMCVisibleWOBestElec);
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, end elec");
                return;
	}


	if(OMCLep.Muon_Pool().Has_DS_Best()&&OMCLep.Elec_Pool().Has_DS_Best()&& !OMCLep.Lep_Pool().Has_DS_Best()){
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, combine left particles after elec and muon");
		AParticleType vis_tmp= OMCVisible_Vec- OMCCombinedPhoton;
                AParticleType vis_elec_tmp= OMCVisible_Vec- OMCCombinedPhoton;
		for(int i=0;i<OMCLep.Muon_Pool().Choosed_DS_Pair().size();i++){
			vis_tmp = vis_tmp - OMCLep.Muon_Pool().Best_DS_Pair_ori()[i];
		}
                OMCVisibleWOBestMuon_Vec = vis_tmp;
                OMCVisibleWOBestMuon_ori= Get_Sum(OMCVisibleWOBestMuon_Vec);
                OMCVisibleWOBestMuon = &OMCVisibleWOBestMuon_ori;
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, has remove muon");
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, elec choosed pair num",OMCLep.Elec_Pool().Choosed_DS_Pair().size());
		for(int i=0;i<OMCLep.Elec_Pool().Choosed_DS_Pair().size();i++){
			vis_tmp = vis_tmp - OMCLep.Elec_Pool().Best_DS_Pair_ori()[i];
                        vis_elec_tmp = vis_elec_tmp - OMCLep.Muon_Pool().Best_DS_Pair_ori()[i];
		}
                OMCVisibleWOBestElec_Vec = vis_elec_tmp;
                OMCVisibleWOBestElec_ori= Get_Sum(OMCVisibleWOBestElec_Vec);
                OMCVisibleWOBestElec = &OMCVisibleWOBestElec_ori;
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, has remove elec");
		OMCVisibleWOBestLep_Vec = vis_tmp; 
                OMCVisibleWOBestLep_ori= Get_Sum(OMCVisibleWOBestLep_Vec);
                OMCVisibleWOBestLep  = &OMCVisibleWOBestLep_ori;
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get all lep");
                return;
	}

	para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, OMCLep.Lep_Pool().Has_DS_Best()",OMCLep.Lep_Pool().Has_DS_Best());
	if(OMCLep.Lep_Pool().Has_DS_Best()){
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, begin lep");
		OMCVisibleWOBestLep_Vec = OMCVisible_Vec- OMCLep.Elec_Pool().Best_DS_Pair_ori()[0]-OMCLep.Muon_Pool().Best_DS_Pair_ori()[0] - OMCCombinedPhoton;
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get Vec",OMCVisibleWOBestLep_Vec);
		OMCVisibleWOBestLep_ori= Get_Sum(OMCVisibleWOBestLep_Vec);
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get ori",OMCVisibleWOBestLep_ori);
		OMCVisibleWOBestLep = &OMCVisibleWOBestLep_ori;
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, get pointer",*OMCVisibleWOBestLep);
		para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, end lep");
                return;
	}
	para.debug.Message(2,97,"in AObject::getVisibleWOBestLep, end");
        
        OMCVisibleWOBestLep_Vec = OMCVisible_Vec;
        
}

void AObject::setJet(CDraw &para){
	OMCJet.Set_Jet(para,OMCVisibleWOBestLep_Vec, OMCbquark, OMCcquark);	
}

bool AObject::Fill(CDraw &para, AnalyseClass &analyse){
	if(para.flow.record_object=="jet"){
		Fill_Jet(para,analyse);
	}
	else if(para.flow.record_object=="lepton"){
		Fill_Lepton(para,analyse);
	}
	else{
		return(false);
	}
}



