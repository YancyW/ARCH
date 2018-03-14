#include "Analyse/Acomb_recoil.h"
bool Analysis_Combine_Recoil(CDraw &para, MyPlots *plots,std::vector<Jet*> Vjet,std::vector<Jet*> Vbjet,std::vector<Jet*> Vcjet, std::vector<Jet*> Vqjet, std::vector<Jet*> Vuntagjet, std::vector<Electron*> Velec,std::vector<Muon*> Vmuon, 
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2, std::vector<Electron*> &Vcombined_elec1, 
		std::vector<Electron*> &Vcombined_elec2, std::vector<Muon*> &Vcombined_muon1, std::vector<Muon*> &Vcombined_muon2){

	std::vector<Jet*> Vchoose_jet,Vleft_jet;
	std::vector<Electron*> Vchoose_elec,Vleft_elec;
	std::vector<Muon*> Vchoose_muon,Vleft_muon;

	bool Jcomb_jet_jet  =false  ;  
	bool Jcomb_jet_bjet =false  ;
	bool Jcomb_jet_cjet =false  ;
	bool Jcomb_jet_qjet =false  ;
	bool Jcomb_jet_untagjet=false  ;
	bool Jcomb_jet_elec =false  ;
	bool Jcomb_jet_muon =false  ;

	bool Jcomb_bjet_jet =false  ;  
	bool Jcomb_bjet_bjet=false  ;
	bool Jcomb_bjet_cjet=false  ;
	bool Jcomb_bjet_qjet=false  ;
	bool Jcomb_bjet_untagjet=false  ;
	bool Jcomb_bjet_elec=false  ;
	bool Jcomb_bjet_muon=false  ;

	bool Jcomb_cjet_jet =false  ;  
	bool Jcomb_cjet_bjet=false  ;
	bool Jcomb_cjet_cjet=false  ;
	bool Jcomb_cjet_qjet=false  ;
	bool Jcomb_cjet_untagjet=false  ;
	bool Jcomb_cjet_elec=false  ;
	bool Jcomb_cjet_muon=false  ;

	bool Jcomb_qjet_jet =false  ;
	bool Jcomb_qjet_bjet=false  ;
	bool Jcomb_qjet_cjet=false  ;
	bool Jcomb_qjet_qjet=false  ;
	bool Jcomb_qjet_untagjet=false  ;
	bool Jcomb_qjet_elec=false  ;
	bool Jcomb_qjet_muon=false  ;

	bool Jcomb_elec_jet =false  ;
	bool Jcomb_elec_bjet=false  ;
	bool Jcomb_elec_cjet=false  ;
	bool Jcomb_elec_qjet=false  ;
	bool Jcomb_elec_untagjet=false  ;
	bool Jcomb_elec_elec=false  ;
	bool Jcomb_elec_muon=false  ;

	bool Jcomb_muon_jet =false  ;
	bool Jcomb_muon_bjet=false  ;
	bool Jcomb_muon_cjet=false  ;
	bool Jcomb_muon_qjet=false  ;
	bool Jcomb_muon_untagjet=false  ;
	bool Jcomb_muon_elec=false  ;
	bool Jcomb_muon_muon=false  ;

	if(para.signal.VETO_bjet==true){
		Jcomb_bjet_qjet=true;
	}
	else{
		Jcomb_bjet_untagjet=true;
	}


	bool Judge;

	float Icomb_mc, Icomb_md, Icomb_mu, Irecoil_mc, Irecoil_md, Irecoil_mu;

	Icomb_mc=para.comb.jets.CUT_massr[1];
	Icomb_md=para.comb.jets.CUT_massd[1];
	Icomb_mu=para.comb.jets.CUT_massu[1];
	Irecoil_mc=para.recoil.jets.CUT_massr[0];
	Irecoil_md=para.recoil.jets.CUT_massd[0];
	Irecoil_mu=para.recoil.jets.CUT_massu[0];

	std::vector<Jet*> particle1,particle2;


	if(Jcomb_bjet_untagjet){
		particle1 = Vbjet;
		particle2 = Vuntagjet;
		if(particle1.size()<2||particle1.size()+particle2.size()<4){
			Judge=false;
		}
		else{
			Judge=Combine_Recoil_choosebest_diff(para,plots,particle1,particle2,Icomb_mc, Icomb_md, Icomb_mu,Irecoil_mc,Irecoil_md, Irecoil_mu, Vcombined_jet1, Vcombined_jet2);
		}
		return(Judge);
	}



	if(Jcomb_bjet_qjet){
		particle1 = Vbjet;
		particle2 = Vqjet;
		if(particle1.size()<2 || particle2.size()<2){
			Judge=false;
		}
		else{
			Judge=Combine_Recoil_choosebest_same(para,plots,particle1,particle2,Icomb_mc, Icomb_md, Icomb_mu,Irecoil_mc,Irecoil_md, Irecoil_mu, Vcombined_jet1, Vcombined_jet2);
		}
		return(Judge);
	}


	return(false);


}

bool Combine_Recoil_choosebest_same(CDraw &para, MyPlots *plots, std::vector<Jet*> particle1,std::vector<Jet*> particle2, float Icomb_mc, float Icomb_md, float Icomb_mu,float Irecoil_mc, float Irecoil_md, float Irecoil_mu,
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2){

	int loop1,loop2, Floop1=10000, Floop2=10000;
	TLorentzVector mom1,mom2;
	int num1 = particle1.size();
	float xi,xi_min=10000.0;
	float Fcomb_m=0.0,Frecoil_m=0.0;
	float Rcomb_m=0.0,Rrecoil_m=0.0;
	bool judge,Jcomb1;
	std::vector<Jet*> Vleft_jet;

	for(loop1=0;loop1<num1-1;loop1++){
		for(loop2=loop1+1;loop2<num1;loop2++){

			mom1 = particle1.at(loop1)->P4();
			mom2 = particle1.at(loop2)->P4();
			judge=Combine_Recoil_direct(mom1, mom2,Icomb_md, Icomb_mu,Irecoil_md, Irecoil_mu, &Rcomb_m, &Rrecoil_m);
			if(!judge){continue;}

			xi=sqrt(pow(Rcomb_m-Icomb_mc,2)+pow(Rrecoil_m-Irecoil_mc,2));
			if(xi<xi_min){
				xi_min = xi;
				Fcomb_m = Rcomb_m;
				Frecoil_m= Rrecoil_m;
				Floop1=loop1;
				Floop2=loop2;
			}
		} 
	}

	float Icomb_mc1=para.comb.jets.CUT_massr[0];
	float Icomb_md1=para.comb.jets.CUT_massd[0];
	float Icomb_mu1=para.comb.jets.CUT_massu[0];
//	Jcomb1=Combine2SameFS(plots->fcomb1M,particle2,Icomb_mc1,Icomb_md1,Icomb_mu1, Vcombined_jet1,Vleft_jet);

	if(Fcomb_m!=0.0 && Frecoil_m!=0.0 && Jcomb1){
		plots->fcomb2M->Fill(Fcomb_m);
		plots->frecoilmass->Fill(Frecoil_m);
		Vcombined_jet2.push_back(particle1[Floop1]);
		Vcombined_jet2.push_back(particle1[Floop2]);

		return(true);
	}
	else{return(false);}

}

bool Combine_Recoil_choosebest_diff(CDraw &para, MyPlots *plots, std::vector<Jet*> particle1,std::vector<Jet*> particle2, float Icomb_mc, float Icomb_md, float Icomb_mu,float Irecoil_mc, float Irecoil_md, float Irecoil_mu,
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2){
	std::vector<Jet*> particle2_with1;
	int loop1,loop2, Floop1=10000, Floop2=10000;
	TLorentzVector mom1,mom2;
	int num1 = para.signal.NUM_bjet;
	float xi,xi_min=10000.0;
	float Fcomb_m=0.0,Frecoil_m=0.0;
	float Rcomb_m=0.0,Rrecoil_m=0.0;
	bool judge,Jcomb1;
	std::vector<Jet*> Vleft_jet;

	for(loop1=0;loop1<num1-1;loop1++){
		for(loop2=loop1+1;loop2<num1;loop2++){

			mom1 = particle1.at(loop1)->P4();
			mom2 = particle1.at(loop2)->P4();
			judge=Combine_Recoil_direct(mom1, mom2,Icomb_md, Icomb_mu,Irecoil_md, Irecoil_mu, &Rcomb_m, &Rrecoil_m);
			if(!judge){continue;}

			xi=sqrt(pow(Rcomb_m-Icomb_mc,2)+pow(Rrecoil_m-Irecoil_mc,2));
			if(xi<xi_min){
				xi_min = xi;
				Fcomb_m = Rcomb_m;
				Frecoil_m= Rrecoil_m;
				Floop1=loop1;
				Floop2=loop2;
			}
		} 
	}

	//put the left jet in particle1 into particle2
	particle2_with1 = particle2;
	if(num1!=2){
		for(loop1=0;loop1<num1;loop1++){
			if(loop1!=Floop1 && loop1!=Floop2) {
				particle2_with1.push_back(particle1[loop1]);
			}
		}
	}

	for( auto loop1 = particle2_with1.begin(); loop1!= particle2_with1.end()-1; ++loop1) {
		Jet* ptlarge= *loop1;
		for( auto loop2 = particle2_with1.begin()+1; loop2!= particle2_with1.end(); ++loop2) {
			if( (*loop2)->PT > ptlarge->PT ) {
				ptlarge= *loop2;
				*loop2 = *loop1;
				*loop1 = ptlarge;
			}//endif
		}//endfor iter
	}

	float Icomb_mc1=para.comb.jets.CUT_massr[0];
	float Icomb_md1=para.comb.jets.CUT_massd[0];
	float Icomb_mu1=para.comb.jets.CUT_massu[0];
//	Jcomb1=Combine2SameFS(plots->fcomb1M,particle2,Icomb_mc1,Icomb_md1,Icomb_mu1, Vcombined_jet1,Vleft_jet);

	if(Fcomb_m!=0.0 && Frecoil_m!=0.0 && Jcomb1){
		plots->fcomb2M->Fill(Fcomb_m);
		plots->frecoilmass->Fill(Frecoil_m);
		Vcombined_jet2.push_back(particle1[Floop1]);
		Vcombined_jet2.push_back(particle1[Floop2]);

		return(true);
	}
	else{return(false);}

}


bool Combine_Recoil_direct(TLorentzVector mom1, TLorentzVector mom2,float Icomb_md, float Icomb_mu,float Irecoil_md, float Irecoil_mu, float *Rcomb_m, float *Rrecoil_m){

	TLorentzVector addm(0,0,0,0), collider(0,0,0,250);

	addm = mom1+mom2;
	float mass_comb=addm.M();
	// mass window cut
	if(mass_comb< Icomb_md || mass_comb>Icomb_mu){
		return(false); 
	}

	//recoil mass cut
	float mass_recoil=(collider-addm).M();
	if(mass_recoil< Irecoil_md || mass_recoil>Irecoil_mu){
		return(false); 
	}

	*Rcomb_m=mass_comb;
	*Rrecoil_m=mass_recoil;
	return(true);
}




