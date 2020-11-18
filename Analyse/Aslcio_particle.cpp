
#include "Aslcio_particle.h"


bool GetFinalState_slcio(CDraw &para, AnalyseClass &analyse, AObject &object, MyPlots* plots){
	         
    para.debug.Message(3,80,"in GetFinalState: begin ");

	para.debug.Message(2,80, "in GetFinalState: All",object.OMCParticle);

	object.setParticleSpecies(para);
	para.debug.Message(2,80, "in GetFinalState: Species",0);

	analyse.counter.setCounter(object.OMCSpecies);
    para.debug.Message(2,80, "in GetFinalState: setCounter",0);

    object.setAllLepPool(para);
    para.debug.Message(2,80, "in GetFinalState: setAllLepPool",object.OMCLep.Muon_Pool());

    object.getVisible(para);
    para.debug.Message(2,80, "in GetFinalState: getVisible vec",object.OMCVisible_Vec);
    para.debug.Message(2,96, "in GetFinalState: getVisible",*(object.OMCVisible));

    object.getInVisible(para);
    para.debug.Message(2,96, "in GetFinalState: getInVisible",*(object.OMCInvisible));

    object.findBestLep(para);
    para.debug.Message(2,96, "in GetFinalState: Muon_Pool()->Has_DS_Best",object.OMCLep.Muon_Pool().Has_DS_Best());
	object.getVisibleWOBestLep(para);


	if(object.OMCLep.Muon_Pool().Has_DS_Best()){
		para.debug.Message(2,96, "in GetFinalState: findBestLep",object.OMCLep.Muon_Pool().Choosed_DS_Pair());
		para.debug.Message(2,96, "in GetFinalState: findBestLep photon",object.OMCCombinedPhoton);



		para.debug.Message(2,80, "in GetFinalState: getVisibleWOBestLep vec",object.OMCVisibleWOBestMuon_Vec);
		para.debug.Message(2,96, "in GetFinalState: getVisibleWOBestLep",object.OMCVisibleWOBestMuon);
//    para.debug.Message(2,96, "in GetFinalState: findBestLep ori   ",object.OMCLep.Muon_Pool().Best_DS_Pair_ori());
	}

    object.setJet(para);
    para.debug.Message(2,80, "in GetFinalState: setJet",object.OMCJet.Jets().size());
    para.debug.Message(2,80, "in GetFinalState: setJet",object.OMCJet.Jet_Vec().size());

    object.Fill(para,analyse);
    para.debug.Message(2,80, "in GetFinalState: cut",0);

    analyse.datatrain->Fill();
	analyse.var.Init_Value();
	return(true);
}




bool Combine_Recoil(CDraw &para, AnalyseClass &analyse, AParticleType par1, AParticleType par2, MyPlots* plots, CCombine_cut comb_cut, CRecoil_cut recoil_cut, int choosed1, int choosed2){

	int loop1,loop2, Floop1=-10, Floop2=-10;
	TLorentzVector mom1,mom2;
	int num1 = par1.size();
	int num2 = par2.size();
	float xi,xi_min=1000000.0;
	float Fcomb_m=-100.0,Frecoil_m=-100.0;
	float Rcomb_m=-100.0,Rrecoil_m=-100.0;
	bool judge;


	float Icomb_mc1   = comb_cut.CUT_massr[0];
	float Icomb_md1   = comb_cut.CUT_massd[0];
	float Icomb_mu1   = comb_cut.CUT_massu[0];

	float Icomb_mc2   = comb_cut.CUT_massr[1];
	float Icomb_md2   = comb_cut.CUT_massd[1];
	float Icomb_mu2   = comb_cut.CUT_massu[1];

	float Irecoil_mc  = recoil_cut.CUT_massr[0];
	float Irecoil_md  = recoil_cut.CUT_massd[0];
	float Irecoil_mu  = recoil_cut.CUT_massu[0];

	for(loop1=0;loop1<num1-1;loop1++){
		for(loop2=loop1+1;loop2<num1;loop2++){

			mom1 = par1[loop1]->P();
			mom2 = par2[loop2]->P();
			judge=Combine_Recoil_direct(mom1, mom2,Icomb_md2, Icomb_mu2,Irecoil_md, Irecoil_mu, &Rcomb_m, &Rrecoil_m);
			if(!judge){continue;}

			xi=sqrt(pow(Rcomb_m-Icomb_mc2,2)+pow(Rrecoil_m-Irecoil_mc,2));
			if(xi<xi_min){
				xi_min = xi;
				Fcomb_m = Rcomb_m;
				Frecoil_m= Rrecoil_m;
				Floop1=loop1;
				Floop2=loop2;
			}
		} 
	}

	if(Floop1!=-10&& Floop2!=-10){
		plots->fcomb2M->Fill(Fcomb_m);
		plots->frecoilmass->Fill(Frecoil_m);
		choosed1 = Floop1;
		choosed2 = Floop2;
		return(true);
	}
	else{return(false);}

}
