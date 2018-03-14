/**********************************************************************
 * @file Lepton.cpp
 * @Name: 
 * @Author:Yan Wang - yan.wang@desy.de
 * @version:1
 * @Created:2017-08-08
 * Copyright (C) 2012 All rights reserved
 **********************************************************************/

#include "AnalyseClass/Lepton.h"



/**********************************************************************
 * @Name: setChargeParticle 
 *
 * @Param: input
 * @Param: PDG
 * @Param: lep_cut
 * @Param: left_events
 *
 * @Returns: 
 **********************************************************************/
APool ALepton::Set_Charge_Particle(AParticleType &input, int PDG, CLepton_cut  &lep_cut, AParticleType &left_events){
	int num = input.size();
	APool output;
	for( int i = 0; i < num; i++ ){
		if(std::abs(input[i]->PID())==PDG){
			if(input[i]->Charge()>0){
				if(Cut(input[i],lep_cut)){
					output.Add_First(input[i]);
				}
			}
			else if(input[i]->Charge()<0){
				if(Cut(input[i],lep_cut)){
					output.Add_Second(input[i]);
				}
			}
		}
		else{
			left_events.push_back(input[i]);
		}
	}
	output.Set_DS_Pool();
	return(output);
}

/**********************************************************************
 * @Name: setElecPool 
 *
 * @Param: in_events
 * @Param: para_lep
 * @Param: left_events
 **********************************************************************/
void ALepton::Set_Elec_Pool(AParticleType &in_events, CLepton_cut &para_lep, AParticleType &left_events){
	APool Pnew=Set_Charge_Particle(in_events,11,para_lep, left_events);
	_elec_pool.Equal(Pnew);
	_elec_pool.Get_DS_Pairs();
}




/**********************************************************************
 * @Name:  
 *
 * @Param: in_events
 * @Param: para_lep
 * @Param: left_events
 *
 * @Returns: 
 **********************************************************************/
void ALepton::Set_Muon_Pool  (AParticleType &in_events,  CLepton_cut  &para_lep, AParticleType &left_events){
	APool Pnew=Set_Charge_Particle(in_events,13,para_lep, left_events);
	_muon_pool.Equal(Pnew);
	_muon_pool.Get_DS_Pairs();
}


/**********************************************************************
 * @Name:  
 *
 * @Param: in_events
 * @Param: para_lep
 * @Param: left_events
 *
 * @Returns: 
 **********************************************************************/
void ALepton::Set_Tau_Pool   (AParticleType &in_events,  CLepton_cut  &para_lep, AParticleType &left_events){
	APool Pnew=Set_Charge_Particle(in_events,15,para_lep, left_events);
	_tau_pool=Pnew;
	_tau_pool.Get_DS_Pairs();
}


/**********************************************************************
 * @Name: setLepPool 
 *
 * @Param: in_events
 * @Param: para_lep
 * @Param: left_events
 **********************************************************************/
void ALepton::Set_Lep_Pool(AParticleType &in_events, CLepton_cut  &para_lep,  AParticleType &left_events){
	AParticleType left_events1;
	APool Pnew1=Set_Charge_Particle(in_events   ,11,para_lep, left_events1);
	_lep_pool = Pnew1;
	APool Pnew2=Set_Charge_Particle(left_events1,13,para_lep, left_events);
	APool Pnew3=_lep_pool + Pnew2;
	_lep_pool = Pnew3; 
	_lep_pool._pool.clear();
	_lep_pool.Set_DS_Pool();
	_lep_pool.Get_DS_Pairs();
}

/**********************************************************************
 * @Name: setAllLepPool 
 *
 * @Param: in_events
 * @Param: para_lep
 * @Param: left_events
 **********************************************************************/
void ALepton::Set_All_Lep_Pool(AParticleType &in_events, CLepton &para_lep,  AParticleType &left_events){
	AParticleType left_events1;

	Set_Elec_Pool(in_events   ,para_lep.basic_elec, left_events1);
	Set_Muon_Pool(left_events1,para_lep.basic_muon, left_events);
}


/**********************************************************************
 * @Name: Clear 
 **********************************************************************/
void ALepton::Clear(){
	_elec_pool.Clear();
	_muon_pool.Clear();
	_lep_pool.Clear();
}


void ALepton::Init(){
	_elec_pool.Clear();
	_muon_pool.Clear();
	_lep_pool .Clear();
}

/**********************************************************************
 * @Name: Cut 
 *
 * @Param: par
 * @Param: lep_cut
 *
 * @Returns: whether the cut is succesful or not 
 **********************************************************************/
bool ALepton::Cut(AParticle* par, CLepton_cut &lep_cut){
	if(lep_cut.JCUT_pt.size()>0){
		float pt = par->Pt();
		if( lep_cut.JCUT_pt  [0] == true ){
			if( pt     < lep_cut.CUT_ptd  [0] || pt     > lep_cut.CUT_ptu  [0] ){return(false);}//endif
		}
	}
	if(lep_cut.JCUT_e.size()>0){
		float e  = par->E();
		if( lep_cut.JCUT_e   [0] == true ){
			if( e      < lep_cut.CUT_ed   [0] || e      > lep_cut.CUT_eu   [0] ){return(false);}//endif
		}
	}
	if(lep_cut.JCUT_eta.size()>0){
		float eta= std::abs(par->Eta());
		if( lep_cut.JCUT_eta [0] == true ){
			if( eta    < lep_cut.CUT_etad [0] || eta    > lep_cut.CUT_etau [0] ){return(false);}//endif
		} 
	}
	if(lep_cut.JCUT_theta.size()>0){
		float costheta= std::abs(par->CosTheta());
		if( lep_cut.JCUT_theta[0] == true ){
			if( costheta < lep_cut.CUT_thetad [0] || costheta > lep_cut.CUT_thetau [0] ){return(false);}//endif
		} 
	}
	return(true);
}


void ALepton::Find_All_Best_Lep(CDraw &para){
	para.debug.Message(2,101,"in ALepton::Find_All_Best_Lep, begin");
	FloatVecVec in_value;


    in_value.push_back(para.comb.elec.CUT_massr);
    in_value.push_back(para.comb.elec.CUT_mass_relate);
    _elec_pool.Set_Detector_Para(para.detector.energy,para.detector.collider_angle);
    _elec_pool.Get_Best_DS_Pair(in_value,"mass_recoil","sort");
    para.debug.Message(2,101,"in ALepton::Find_All_Best_Lep, finish elec, begin muon");


    in_value.clear();
    in_value.push_back(para.comb.elec.CUT_massr);
    in_value.push_back(para.comb.elec.CUT_mass_relate);
    _muon_pool.Set_Detector_Para(para.detector.energy,para.detector.collider_angle);
    _muon_pool.Get_Best_DS_Pair(in_value,"mass_recoil","sort");
    para.debug.Message(2,101,"in ALepton::Find_All_Best_Lep, end");
}

void ALepton::All_Photon_Recovery(CLepton &lep_info, AParticleType &WOIsoLep, AParticleType &CombinedPhoton){
	for(int i=0;i<_elec_pool._ds_pair_choosed.size();i++){
	//	Photon_Recovery(lep_info.elec, _elec_pool._ds_pair_choosed[i], WOIsoLep, CombinedPhoton);
	}
	for(int i=0;i<_muon_pool._ds_pair_choosed.size();i++){
		Photon_Recovery(lep_info.muon, _muon_pool._ds_pair_choosed[i], WOIsoLep, CombinedPhoton);
	}
}


void ALepton::Photon_Recovery(CLepton_cut &lep_info, APair &lepton,  AParticleType &WOIsoLep, AParticleType &CombinedPhoton){
	////ShowMessage(2,"WOIsoLep",WOIsoLep);
	////ShowMessage(2,"Lepton",lepton);
	if(lepton.Has_Pair()){
		AParticleType::iterator it = WOIsoLep.begin();
		AParticle* P1=lepton.First();
		AParticle* P2=lepton.Second();
		while (it!=WOIsoLep.end()){
			if (Is_In_Lep_Cone(lep_info, P1, *it)) {
				P1->AddEqual(*it);
				CombinedPhoton.push_back(*it);
				WOIsoLep.erase(it);
			}
			else if (Is_In_Lep_Cone(lep_info, P2, *it)) {
				P2->AddEqual(*it);
				CombinedPhoton.push_back(*it);
				WOIsoLep.erase(it);
			}
			else{
				it++;
			}
		}
		lepton.Add_Pair(P1,P2);
	}
	////ShowMessage(2,"cone size",lep_info.ISOLATE_cone_photon);
	////ShowMessage(2,"WOIsoLep after",WOIsoLep);
	////ShowMessage(2,"Lepton after",lepton);
	////ShowMessage(2,"Combine Photon",CombinedPhoton);
}


bool ALepton::Is_In_Lep_Cone( CLepton_cut &info, AParticle* lep, AParticle* pfo ) {
	float coneE = 0;
	if(pfo->PID()!=22){
		return(false);
	}

	float cosTheta = lep->V().Dot( pfo->V())/(lep->V().Mag()*pfo->V().Mag());
	if ( cosTheta >= info.ISOLATE_cone_photon )
	{
		return true;
	}
	return false;
}


std::ostream & operator<<(std::ostream & ostr, ALepton* lep){
	ostr<<"\n Elec_Pool is";
	//ostr<<lep->Elec_Pool();
	ostr<<"\n Muon_Pool is";
	//ostr<<lep->Muon_Pool();
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, ALepton& lep){
	ostr<<"\n Elec_Pool is";
	//ostr<<lep.Elec_Pool();
	ostr<<"\n Muon_Pool is";
	//ostr<<lep.Muon_Pool();
	return ostr;
}
