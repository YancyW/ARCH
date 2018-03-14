#include "Analyse/ALepton.h"
bool Lepton_Isolate(CDraw &para, std::vector<fastjet::PseudoJet> &lep_candi, std::vector<fastjet::PseudoJet> &hadron)
{
	int num_lep = lep_candi.size();
	int num_had = hadron.size();
	float R = para.lep.lep.ISOLATE_cone_had;
	float coef = para.lep.lep.ISOLATE_coef_had;

	std::vector<fastjet::PseudoJet> lepton;

	if(num_lep==0||num_had==0){
		return(false);
	}

	for(int i=0;i<num_lep;i++){
		float sumpt = 0.0;
		for(int j=0;j<num_had;j++){
			float Rij;
			Rij = lep_candi[i].delta_R(hadron[j]);
			if(Rij<R){
				sumpt = sumpt + hadron[j].pt();
			}
		}
		if(sumpt > coef*lep_candi[i].pt()){
			hadron.push_back(lep_candi[i]);
		}
		else{
			lepton.push_back(lep_candi[i]);
		}

	}
	return(true);
}

bool GetFinalState_particle(CDraw &para,std::vector<fastjet::PseudoJet> plus, std::vector<fastjet::PseudoJet> minus, MyPlots* plots,std::vector<fastjet::PseudoJet> &Vlepton)
{
	int loop1=0,loope=0,num;
	float pt,y;

	para.debug.Message(3,21,"in the elec cut function");
	if (para.signal.NUM_elec==0){return(true);} 

    int nump = plus.size();
	int numm = minus.size();
	plots->fElecnum->Fill(nump+numm);

	para.debug.Message(3,21,"begin to loop for n times",num);
	for(loop1=0;loop1<nump;loop1++){
		fastjet::PseudoJet elec= plus[loop1]; 
		pt = elec.perp();
		y  = elec.rap();

		if( para.lep.elec.JCUT_pt  [0] == true && ( pt     < para.lep.elec.CUT_ptd  [0] || pt     > para.lep.elec.CUT_ptu  [0] )){para.debug.Message(4,21,"false: elec pt cut",pt);continue;}//endif
		if( para.lep.elec.JCUT_eta [0] == true && ( std::abs(y) < para.lep.elec.CUT_etad [0] || std::abs(y) > para.lep.elec.CUT_etau [0] )){para.debug.Message(4,21,"false: elec eta cut",y);continue;}//endif
		Vlepton.push_back(elec);
		loope++;
	}//endfor jet_Cindex
	for(loop1=0;loop1<numm;loop1++){
		fastjet::PseudoJet elec= minus[loop1] ;
		pt = elec.perp();
		y  = elec.rap();

		if( para.lep.elec.JCUT_pt  [0] == true && ( pt     < para.lep.elec.CUT_ptd  [0] || pt     > para.lep.elec.CUT_ptu  [0] )){para.debug.Message(4,21,"false: elec pt cut",pt);continue;}//endif
		if( para.lep.elec.JCUT_eta [0] == true && ( std::abs(y) < para.lep.elec.CUT_etad [0] || std::abs(y) > para.lep.elec.CUT_etau [0] )){para.debug.Message(4,21,"false: elec eta cut",y);continue;}//endif
		Vlepton.push_back(elec);
		loope++;
	}//endfor jet_Cindex
	para.debug.Message(3,21,"has selected elec which satisfy the cuts",loope);
	if(loope>=1&&loope>=para.signal.NUM_elec){
	    para.debug.Message(3,21,"set special cut for nth elec");
		for(loop1=1;loop1<para.lep.elec.CUT_num;loop1++){
			pt   = Vlepton[loop1-1].perp();
			y    = Vlepton[loop1-1].rap();
			if( para.lep.elec.JCUT_pt  [loop1] == true && ( pt     < para.lep.elec.CUT_ptd  [loop1] || pt     > para.lep.elec.CUT_ptu  [loop1] )){para.debug.Message(4,21,"false: elec pt cut"  , loop1,pt);return(false);}//endif
			if( para.lep.elec.JCUT_eta [loop1] == true && ( std::abs(y) < para.lep.elec.CUT_etad [loop1] || std::abs(y) > para.lep.elec.CUT_etau [loop1] )){para.debug.Message(4,21,"false: elec eta cut" , loop1 ,y);return(false);}//endif
		}

	    para.debug.Message(3,21,"plot for elec");
		for(loop1=0;loop1<loope;loop1++){
			if(loop1<para.signal.NUM_elec){
				plots->fElectronPT[loop1]->Fill(Vlepton[loop1].perp());
				plots->fElectronY [loop1]->Fill(Vlepton[loop1].rap());
			} 
		}
		return(true);
	}
	else{
		para.debug.Message(3,21,"false: elec num cut",loope);
		return(false);
	}

}
