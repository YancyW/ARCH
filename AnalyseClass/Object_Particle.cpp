#include "AnalyseClass/Object.h"

bool AObject::Fill_Particle_A(CDraw &para, AnalyseClass &analyse){
	analyse.var.var[0 ].variable =  Vjet   .size(); 
	if( Vjet.size()>1){
		analyse.var.var[1 ].variable =  Vjet   [0]->PT; 
		analyse.var.var[2 ].variable =  Vjet   [0]->Eta; 
		analyse.var.var[3 ].variable =  Vjet   [1]->PT; 
		analyse.var.var[4 ].variable =  Vjet   [1]->Eta; 
	}
	analyse.var.var[5 ].variable =  Vbjet  .size(); 
	if( Vbjet.size()>0){
		analyse.var.var[6 ].variable =  Vbjet  [0]->PT; 
		analyse.var.var[7 ].variable =  Vbjet  [0]->Eta; 
	}
	analyse.var.var[8 ].variable =  Vtaujet.size(); 
	if( Vtaujet.size()>1){
		analyse.var.var[9 ].variable =  Vtaujet[0]->PT; 
		analyse.var.var[10].variable =  Vtaujet[0]->Eta; 
		analyse.var.var[11].variable =  Vtaujet[1]->PT; 
		analyse.var.var[12].variable =  Vtaujet[1]->Eta; 
	}

	std::vector<TLorentzVector> leps;
	for(unsigned int i=0;i< Velec.size();i++){
		TLorentzVector this_lep;
		float pt = Velec[i]->PT;
		float Eta= Velec[i]->Eta;
		float Phi= Velec[i]->Phi;
		float M=0;
		this_lep.SetPtEtaPhiM(pt,Eta,Phi,M);
		leps.push_back(this_lep);
	}
	for(unsigned int i=0;i< Vmuon.size();i++){
		TLorentzVector this_lep;
		float pt = Vmuon[i]->PT;
		float Eta= Vmuon[i]->Eta;
		float Phi= Vmuon[i]->Phi;
		float M=0.113;
		this_lep.SetPtEtaPhiM(pt,Eta,Phi,M);
		leps.push_back(this_lep);
	}

	std::sort(leps.begin(),leps.end(),TLV_compare_PT);
	Vlep   = leps;

	analyse.var.var[13].variable = leps.size() ;
	if(leps.size()>0){
		analyse.var.var[14].variable = leps[0].Pt();
		analyse.var.var[15].variable = leps[0].Eta();
	}
	analyse.var.var[32].variable = Vmet[0]->MET;
	return(true);
}

bool AObject::Fill_Particle_B(CDraw &para, AnalyseClass &analyse){
	analyse.var.var[0 ].variable =  Vjet   .size(); 
	if( Vjet.size()>1){
		analyse.var.var[1 ].variable =  Vjet   [0]->PT; 
		analyse.var.var[2 ].variable =  Vjet   [0]->Eta; 
		analyse.var.var[3 ].variable =  Vjet   [1]->PT; 
		analyse.var.var[4 ].variable =  Vjet   [1]->Eta; 
	}
	analyse.var.var[5 ].variable =  Vbjet  .size(); 
	if( Vbjet.size()>0){
		analyse.var.var[6 ].variable =  Vbjet  [0]->PT; 
		analyse.var.var[7 ].variable =  Vbjet  [0]->Eta; 
	}
	analyse.var.var[8 ].variable =  Vtaujet.size(); 
	if( Vtaujet.size()>0){
		analyse.var.var[9 ].variable =  Vtaujet[0]->PT; 
		analyse.var.var[10].variable =  Vtaujet[0]->Eta; 
	}

	std::vector<TLorentzVector> lep_p,lep_m;
	for(unsigned int i=0;i< Velec.size();i++){
		TLorentzVector this_lep;
		float pt = Velec[i]->PT;
		float Eta= Velec[i]->Eta;
		float Phi= Velec[i]->Phi;
		float M=0;
		this_lep.SetPtEtaPhiM(pt,Eta,Phi,M);
		if(Velec[i]->Charge>0){
			lep_p.push_back(this_lep);
		}
		else{
			lep_m.push_back(this_lep);
		}
	}
	for(unsigned int i=0;i< Vmuon.size();i++){
		TLorentzVector this_lep;
		float pt = Vmuon[i]->PT;
		float Eta= Vmuon[i]->Eta;
		float Phi= Vmuon[i]->Phi;
		float M=0.113;
		this_lep.SetPtEtaPhiM(pt,Eta,Phi,M);
		if(Vmuon[i]->Charge>0){
			lep_p.push_back(this_lep);
		}
		else{
			lep_m.push_back(this_lep);
		}
	}

	std::sort(lep_p.begin(),lep_p.end(),TLV_compare_PT);
	std::sort(lep_m.begin(),lep_m.end(),TLV_compare_PT);

	if(Vtaujet.size()>=1){
		if(Vtaujet[0]->Charge>0){
			Vlep   = lep_m;
		}
		else if(Vtaujet[0]->Charge<0){
			Vlep   = lep_p;
		}
		else{
		//	ShowMessage(2,"no tau jet charge");
			Vlep = lep_p;
		}
	}

	if(Vlep.size()<2){
		return(false);
	}
	analyse.var.var[11].variable = Vlep.size() ;
  	analyse.var.var[12].variable = Vlep[0].Pt();
  	analyse.var.var[13].variable = Vlep[0].Eta();
  	analyse.var.var[14].variable = Vlep[1].Pt();
  	analyse.var.var[15].variable = Vlep[1].Eta();

	analyse.var.var[32].variable = Vmet[0]->MET;
	return(true);
}

bool AObject::Fill_Particle_C(CDraw &para, AnalyseClass &analyse){
	analyse.var.var[0 ].variable =  Vjet   .size(); 
	if( Vjet.size()>1){
		analyse.var.var[1 ].variable =  Vjet   [0]->PT; 
		analyse.var.var[2 ].variable =  Vjet   [0]->Eta; 
		analyse.var.var[3 ].variable =  Vjet   [1]->PT; 
		analyse.var.var[4 ].variable =  Vjet   [1]->Eta; 
	}
	analyse.var.var[5 ].variable =  Vbjet  .size(); 
	if( Vbjet.size()>0){
		analyse.var.var[6 ].variable =  Vbjet  [0]->PT; 
		analyse.var.var[7 ].variable =  Vbjet  [0]->Eta; 
	}
	analyse.var.var[8 ].variable =  Vtaujet.size(); 

	std::vector<TLorentzVector> lep_p;
	for(unsigned int i=0;i< Velec.size();i++){
		TLorentzVector this_lep;
		float pt = Velec[i]->PT;
		float Eta= Velec[i]->Eta;
		float Phi= Velec[i]->Phi;
		float M=0;
		this_lep.SetPtEtaPhiM(pt,Eta,Phi,M);
		lep_p.push_back(this_lep);
	}
	for(unsigned int i=0;i< Vmuon.size();i++){
		TLorentzVector this_lep;
		float pt = Vmuon[i]->PT;
		float Eta= Vmuon[i]->Eta;
		float Phi= Vmuon[i]->Phi;
		float M=0.113;
		this_lep.SetPtEtaPhiM(pt,Eta,Phi,M);
		lep_p.push_back(this_lep);
	}

	std::sort(lep_p.begin(),lep_p.end(),TLV_compare_PT);

	if(lep_p.size()>2){
		analyse.var.var[ 9].variable = lep_p.size() ;
		analyse.var.var[10].variable = lep_p[0].Pt();
		analyse.var.var[11].variable = lep_p[0].Eta();
		analyse.var.var[12].variable = lep_p[1].Pt();
		analyse.var.var[13].variable = lep_p[1].Eta();
		analyse.var.var[14].variable = lep_p[2].Pt();
		analyse.var.var[15].variable = lep_p[2].Eta();
	}
	Vlep   = lep_p;

	analyse.var.var[32].variable = Vmet[0]->MET;
	return(true);
}

