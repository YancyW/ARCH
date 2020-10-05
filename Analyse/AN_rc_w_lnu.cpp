#include "AN_rc_w_lnu.h"
bool AN_RC_w_lnu(float wmass, float mw_d, float mw_u, TLorentzVector &Vlep, MissingET* Vmet, TLorentzVector &re_w, TLorentzVector &re_nu){
	int lnum,mnum,key;


	TLorentzVector pneutrino=TLorentzVector(Vmet->MET*std::cos(Vmet->Phi),Vmet->MET*std::sin(Vmet->Phi),0,0);
	TLorentzVector pw;
	TLorentzVector pnu;



	float re_mass=0;
	bool Jre_w=false;

	float wmass_tmp = wmass;
	for(float wmass_tmp=35;wmass_tmp>0;wmass_tmp=wmass_tmp-1){
		Jre_w=AN_RC_lnu(wmass_tmp, Vlep, pneutrino, pw, pnu);
		re_mass=pw.M();
  		if(Jre_w){
  			break;
  		}
  	}

	bool Jre_cut=false;

	if(re_mass>mw_d&&re_mass<mw_u){
		Jre_cut=true;
	}
	if(Jre_w&&Jre_cut){
		re_w .SetPxPyPzE(pw.Px(),pw.Py(),pw.Pz(),pw.E());
		re_nu.SetPxPyPzE(pnu.Px(),pnu.Py(),pnu.Pz(),pnu.E());
		return(true);
	}
	else{
		return(false);
	}
}

bool AN_RC_lnu(float re_mass, TLorentzVector &plepton, TLorentzVector &pneutrino, TLorentzVector &pw, TLorentzVector &pnu){
	TLorentzVector pneu_plus = pneutrino;
	TLorentzVector pneu_minus= pneutrino;

//  ShowMessage(1,"remass",re_mass);
//  ShowMessage(1,"Vlep",plepton);
//  ShowMessage(1,"Vneu",pneutrino);

	float neu_t = pneutrino.Pt();
	float lep_t = plepton.Pt();
	float lep_l = plepton.Pz();
	float lep_e = plepton.E();

	float var1 = std::pow(re_mass,2)/2.0-plepton.Dot(pneutrino);
	float var2 = std::pow(var1,2)-std::pow(neu_t,2)*std::pow(lep_t,2);


	if(var2 < 0.0){
//		ShowMessage(2,"var",var2);
		return(false);
	}
	float var3 = lep_e*std::sqrt(var2);

	float neu_l_plus  = (lep_l*var1 + var3)/std::pow(lep_t,2);
	float neu_l_minus = (lep_l*var1 - var3)/std::pow(lep_t,2);

	pneu_plus (2) = neu_l_plus;
	pneu_plus (3) = std::sqrt(std::pow(neu_t,2)+std::pow(neu_l_plus,2));

	pneu_minus(2) = neu_l_minus;
	pneu_minus(3) = std::sqrt(std::pow(neu_t,2)+std::pow(neu_l_minus,2));

	TLorentzVector pw_plus  = plepton+pneu_plus;
	TLorentzVector pw_minus = plepton+pneu_minus;


	if(std::abs(pw_plus.M()-re_mass) < std::abs(pw_minus.M()-re_mass) ){
		pw =pw_plus;
		pnu=pneu_plus;
	} 
	else{ 
		pw =pw_minus;
		pnu=pneu_minus;
	}

//  ShowMessage(2,"pneu_plus",pneu_plus);
//  ShowMessage(2,"pneu_minus",pneu_minus);
//  ShowMessage(2,"pw_plus",pw_plus);
//  ShowMessage(2,"pw_minus",pw_minus);
//  ShowMessage(2,"final pw ", pw);
//  ShowMessage(2,"final pnu ", pnu);

	return(true);

}
