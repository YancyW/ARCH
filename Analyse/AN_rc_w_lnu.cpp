#include "AN_rc_w_lnu.h"
bool AN_RC_w_lnu(float wmass, float mw_d, float mw_u, Electron* Vlep, MissingET* Vmet, TLorentzVector &re_w, TLorentzVector &re_nu){
	int lnum,mnum,key;


	TLorentzVector pneutrino=TLorentzVector(Vmet->MET*std::cos(Vmet->Phi),Vmet->MET*std::sin(Vmet->Phi),0,0);
	TLorentzVector plepton=Vlep->P4();
	TLorentzVector pw;
	TLorentzVector pnu;


    bool Jre_w=AN_RC_lnu_TLorentvector(wmass, plepton, pneutrino, pw, pnu);
	bool Jre_cut=false;
    float re_mass=pw.M();
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

bool AN_RC_w_lnu(float wmass, float mw_d, float mw_u, Muon* Vlep, MissingET* Vmet, TLorentzVector &re_w, TLorentzVector &re_nu){
	int lnum,mnum,key;


	TLorentzVector pneutrino=TLorentzVector(Vmet->MET*std::cos(Vmet->Phi),Vmet->MET*std::sin(Vmet->Phi),0,0);
	TLorentzVector plepton=Vlep->P4();
	TLorentzVector pw;
	TLorentzVector pnu;


    bool Jre_w=AN_RC_lnu_TLorentvector(wmass, plepton, pneutrino, pw, pnu);
	bool Jre_cut=false;
    float re_mass=pw.M();
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

bool AN_RC_lnu_TLorentvector(float re_mass, TLorentzVector &plepton, TLorentzVector &pneutrino, TLorentzVector &pw, TLorentzVector &pnu){

	TLorentzVector pneu_plus = pneutrino;
	TLorentzVector pneu_minus= pneutrino;

	float neu_t = pneutrino.Pt();
	float lep_t = plepton.Pt();
	float lep_l = plepton.Pz();
	float lep_e = plepton.E();

	float var1 = std::pow(re_mass,2)/2.0-plepton.Dot(pneutrino);
	float var2 = std::pow(var1,2)-std::pow(neu_t,2)*std::pow(lep_t,2);
	if(var2 < 0.0){
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
	return(true);

}
