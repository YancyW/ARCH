#include "Acombine.h"
bool GetCombine(CDraw &para,MyPlots* plots,AObject &object, AnalyseClass &analyse){

	bool Jcomb        = false;
	bool Jcomb1       = false;
	bool Jcomb2       = false;
	bool Jcomb3       = false;
	bool Jcomb4       = false;
	bool Jcomb5       = false;
	bool Jcomb6       = false;
	bool Jrecoil      = false;
	bool Jcomb_recoil = false;
	bool Jcombine     = false;

	if(para.comb.SWITCH){
		para.debug.Message(3,2,"begin combine");
		Jcomb=Analysis_Combine(para,plots,object, &Jcomb1,&Jcomb2, &Jcomb3, &Jcomb4, &Jcomb5, &Jcomb6);
		if(Jcomb1){analyse.counter.getCounter("operation_combine1");}
		if(Jcomb1&&Jcomb2){analyse.counter.getCounter("operation_combine2");}
		if(Jcomb1&&Jcomb2&&Jcomb3){analyse.counter.getCounter("operation_combine3");}
		if(Jcomb1&&Jcomb2&&Jcomb3&&Jcomb4){analyse.counter.getCounter("operation_combine4");}
		if(Jcomb1&&Jcomb2&&Jcomb3&&Jcomb4&&Jcomb5){analyse.counter.getCounter("operation_combine5");}
		if(Jcomb1&&Jcomb2&&Jcomb3&&Jcomb4&&Jcomb5&&Jcomb6){analyse.counter.getCounter("operation_combine6");}
		else{return(false);}
	}
	else{Jcomb=true;}
}

bool Combine2_direct(TLorentzVector mom1, TLorentzVector mom2,float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, float *mass_re){

	TLorentzVector addm(0,0,0,0);

	addm = mom1+mom2;
	float mass_comb=addm.M();
	float pt_comb  =addm.Pt();

	// mass window cut
	if( mass_comb< cut_mlow  || mass_comb > cut_mup ){
		return(false); 
	}
	if( pt_comb  < cut_ptlow || pt_comb   > cut_ptup ){
		return(false); 
	}
	*mass_re=mass_comb;
	return(true);
}

bool Find_ximin(float *xi_min,float input1,float obj1,float input2,float obj2, 
		float *output1,float *output2)
{
	float xi=sqrt(pow(input1-obj1,2)+pow(input2-obj2,2));

	if(xi<*xi_min){
		*xi_min = xi;
		*output1 = input1;
		*output2 = input2;
		return(true);
	}
	return(false);

}


bool Analysis_Combine(CDraw &para, MyPlots *plots, AObject& object,bool *Jcomb1, bool *Jcomb2, bool *Jcomb3, bool *Jcomb4, bool *Jcomb5, bool *Jcomb6){

	float Icomb1_m,Icomb2_m, Icomb3_m, Icomb4_m, Icomb5_m, Icomb6_m;
	float cut_mlow1, cut_mup1, cut_mlow2, cut_mup2, cut_mlow3, cut_mup3, cut_mlow4, cut_mup4, cut_mlow5, cut_mup5, cut_mlow6, cut_mup6;
	float cut_ptlow1, cut_ptup1, cut_ptlow2,cut_ptup2, cut_ptlow3,cut_ptup3, cut_ptlow4,cut_ptup4, cut_ptlow5,cut_ptup5, cut_ptlow6,cut_ptup6;

	Icomb1_m  = para.comb.jets.CUT_massr[0];
	cut_mlow1 = para.comb.jets.CUT_massd[0];
	cut_mup1  = para.comb.jets.CUT_massu[0];

	cut_ptlow1= para.comb.jets.CUT_ptd[0];
	cut_ptup1 = para.comb.jets.CUT_ptu[0];



	Icomb2_m  = para.comb.jets.CUT_massr[1];
	cut_mlow2 = para.comb.jets.CUT_massd[1];
	cut_mup2  = para.comb.jets.CUT_massu[1];
	cut_ptlow2= para.comb.jets.CUT_ptd[1];
	cut_ptup2 = para.comb.jets.CUT_ptu[1];

	Icomb3_m  = para.comb.jets.CUT_massr[2];
	cut_mlow3 = para.comb.jets.CUT_massd[2];
	cut_mup3  = para.comb.jets.CUT_massu[2];
	cut_ptlow3= para.comb.jets.CUT_ptd[2];
	cut_ptup3 = para.comb.jets.CUT_ptu[2];

	Icomb4_m  = para.comb.jets.CUT_massr[3];
	cut_mlow4 = para.comb.jets.CUT_massd[3];
	cut_mup4  = para.comb.jets.CUT_massu[3];
	cut_ptlow4= para.comb.jets.CUT_ptd[3];
	cut_ptup4 = para.comb.jets.CUT_ptu[3];

	Icomb5_m  = para.comb.jets.CUT_massr[4];
	cut_mlow5 = para.comb.jets.CUT_massd[4];
	cut_mup5  = para.comb.jets.CUT_massu[4];
	cut_ptlow5= para.comb.jets.CUT_ptd[4];
	cut_ptup5 = para.comb.jets.CUT_ptu[4];

	Icomb6_m  = para.comb.jets.CUT_massr[5];
	cut_mlow6 = para.comb.jets.CUT_massd[5];
	cut_mup6  = para.comb.jets.CUT_massu[5];
	cut_ptlow6= para.comb.jets.CUT_ptd[5];
	cut_ptup6 = para.comb.jets.CUT_ptu[5];


	object.Vcombine1.resize(1);
	object.Vcombine2.resize(1);
	object.Vcombine3.resize(1);
	object.Vcombine4.resize(1);
	object.Vcombine5.resize(1);
	object.Vcombine6.resize(1);

	if(para.signal.NUM_taujet>=2){
		std::vector<TLorentzVector> Vtau;
		for(int i=0;i<object.Vtaujet.size();i++){
			Vtau.push_back(object.Vtaujet[i]->P4());
		}
		*Jcomb1=Combine2SameFS_TLorentzvector(para,plots->fcomb1M,Vtau,Icomb1_m,cut_mlow1, cut_mup1, cut_ptlow1, cut_ptup1, object.Vcombine1[0]);
	}
	else if(para.signal.NUM_taujet==1){
		std::vector<TLorentzVector> Vtau;
		for(int i=0;i<object.Vtaujet.size();i++){
			Vtau.push_back(object.Vtaujet[i]->P4());
		}
		std::vector<TLorentzVector> Vlep;
		for(int i=0;i<object.Velec.size();i++){
			Vlep.push_back(object.Velec[i]->P4());
		}
		for(int i=0;i<object.Vmuon.size();i++){
			Vlep.push_back(object.Vmuon[i]->P4());
		}
		
		*Jcomb1=Combine2DifferentFS_TLorentzvector(para,plots->fcomb1M,Vtau,Vlep,Icomb1_m,cut_mlow1, cut_mup1, cut_ptlow1, cut_ptup1, object.Vcombine1[0]);
	}
	else if(para.signal.NUM_taujet==0){
		std::vector<TLorentzVector> Vlep;
		for(int i=0;i<object.Velec.size();i++){
			Vlep.push_back(object.Velec[i]->P4());
		}
		for(int i=0;i<object.Vmuon.size();i++){
			Vlep.push_back(object.Vmuon[i]->P4());
		}
		
		*Jcomb1=Combine2SameFS_TLorentzvector(para,plots->fcomb1M,Vlep,Icomb1_m,cut_mlow1, cut_mup1, cut_ptlow1, cut_ptup1, object.Vcombine1[0]);
	}
	if(!*Jcomb1){return(false);}

	*Jcomb2=reconstruct_met(para,plots->fcomb2M,object,Icomb2_m,cut_mlow2,cut_mup2, object.Vcombine2[0],object.Vre_met);
	if(!*Jcomb2){return(false);}

	if(*Jcomb1 && *Jcomb2){
		*Jcomb3=reconstruct_chargeH(para,plots->fcomb3M,object.Vcombine1[0],object.Vcombine2[0],Icomb3_m,cut_mlow3,cut_mup3, object.Vcombine3[0]);
		if(*Jcomb3){
////		if(para.){
////			TLorentzVector Vtjet = object.Vjet[1]->P4();
////		}
//			*Jcomb4=reconstruct_top(para,plots->fcomb4M,object.Vcombine3[0],Vtjet,Icomb4_m,cut_mlow4,cut_mup4, object.Vcombine4[0]);
			if(*Jcomb4){
				*Jcomb5=reconstruct_topj(para,plots->fcomb5M,object.Vcombine4[0],object.Vjet[0]->P4(),Icomb5_m,cut_ptlow5,cut_ptup5, object.Vcombine5[0]);
				*Jcomb6=reconstruct_cms_topj(para,plots->fcomb6M,object.Vcombine4[0],object.Vjet[0]->P4(),Icomb6_m,cut_ptlow6,cut_ptup6,object.Vcombine6[0]);
				if(*Jcomb5 && *Jcomb6){
					return(true);
				}
			}
		}
	}
	return(false);
}


bool reconstruct_met(CDraw &para, TH1 *comb, AObject& object,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine, TLorentzVector &Vre_met){
	if(object.Vmet.size()<1){
		return(false);
	}
	if(object.Velec.size()<1&&object.Vmuon.size()<1){
		return(false);
	}
	bool J_w=false;
	if(object.Velec.size()>0&&object.Vmuon.size()>0){
    	if(object.Velec[0]->PT>object.Vmuon[0]->PT){
			J_w=AN_RC_w_lnu(obj_mass,cut_mlow,cut_mup,object.Velec[0],object.Vmet[0],Vcombine,Vre_met);
    	}
    	else{
    		J_w=AN_RC_w_lnu(obj_mass,cut_mlow,cut_mup,object.Vmuon[0],object.Vmet[0],Vcombine,Vre_met);
    	}
	}
	else if(object.Velec.size()>0&&object.Vmuon.size()==0){
		J_w=AN_RC_w_lnu(obj_mass,cut_mlow,cut_mup,object.Velec[0],object.Vmet[0],Vcombine,Vre_met);
	}
	else if(object.Velec.size()==0&&object.Vmuon.size()>0){
		J_w=AN_RC_w_lnu(obj_mass,cut_mlow,cut_mup,object.Vmuon[0],object.Vmet[0],Vcombine,Vre_met);
	}


	if(J_w){
		AFill_Plot(para,comb,Vcombine.M());
		return(true);
	}
	else{
		return(false);
	}

}

bool reconstruct_chargeH(CDraw &para, TH1 *comb, TLorentzVector &VA, TLorentzVector &VW,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine){
	TLorentzVector pchargeH = VA+VW;
	bool Jre_cut=false;
	float re_mass=pchargeH.M();
	if(re_mass>cut_mlow&&re_mass<cut_mup){
		Jre_cut=true;
	}
	if(Jre_cut){
		Vcombine = pchargeH; 
		AFill_Plot(para,comb,Vcombine.M());
		return(true);
	}
	else{
		return(false);
	}

}


bool reconstruct_top(CDraw &para, TH1 *comb, TLorentzVector VchargeH, TLorentzVector Vbjet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine){
	TLorentzVector ptop= VchargeH+Vbjet;
	bool Jre_cut=false;
	float re_mass=ptop.M();
	if(re_mass>cut_mlow&&re_mass<cut_mup){
		Jre_cut=true;
	}
	if(Jre_cut){
		Vcombine = ptop; 
		AFill_Plot(para,comb,Vcombine.M());
		return(true);
	}
	else{
		return(false);
	}
}


bool reconstruct_topj(CDraw &para, TH1 *comb, TLorentzVector Vtop, TLorentzVector Vjet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine){
	TLorentzVector ptopj= Vtop+Vjet;
	bool Jre_cut=false;
	float re_pt=ptopj.Pt();
	if(re_pt>cut_mlow&&re_pt<cut_mup){
		Jre_cut=true;
	}
	if(Jre_cut){
		Vcombine = ptopj; 
		AFill_Plot(para,comb,Vcombine.Pt());
		return(true);
	}
	else{
		return(false);
	}
}

bool reconstruct_cms_topj(CDraw &para, TH1 *comb, TLorentzVector Vtop, TLorentzVector Vjet,float obj_mass, float cut_mlow, float cut_mup,  TLorentzVector &Vcombine){
	TLorentzVector ptopj= Vtop+Vjet;
	TVector3 boostvec=-ptopj.BoostVector();
	TLorentzVector ptopj_cms = ptopj;
	TLorentzVector ptop_cms = Vtop;
	TLorentzVector pj_cms = Vjet;

	ptopj_cms.Boost(boostvec);
	ptop_cms.Boost(boostvec);
	pj_cms.Boost(boostvec);


	bool Jre_cut=false;
	//float re_angle=Vtop.Angle(ptop_cms.Vect());
	float re_angle=ptop_cms.Angle(Vtop.Vect());
	float cos_re_angle=std::cos(re_angle);

	if(cos_re_angle>cut_mlow&& cos_re_angle<cut_mup){
		Jre_cut=true;
	}
	if(Jre_cut){
		Vcombine = ptopj_cms; 
		AFill_Plot(para,comb,cos_re_angle);
		return(true);
	}
	else{
		return(false);
	}
}


bool Combine2SameFS_TLorentzvector(CDraw &para, TH1 *comb, std::vector<TLorentzVector> &in,float obj_mass, float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, TLorentzVector &choosed){

	int num = in.size();
	int loop1,loop2;
	int count1 = -10,count2 = -10;
	float massclose=100000;
	float re_mass=100000.0;
	TLorentzVector mom1,mom2;
	bool judge;

	for(loop1=0;loop1<num-1;loop1++){
		for(loop2=loop1+1;loop2<num;loop2++){

			mom1 = in[loop1];
			mom2 = in[loop2];
			judge=Combine2_direct(mom1, mom2,cut_mlow,cut_mup, cut_ptlow, cut_ptup, &re_mass);
			if(judge && std::abs(re_mass-obj_mass)<std::abs(massclose-obj_mass)){
				count1 = loop1;
				count2 = loop2;
				massclose = re_mass;
			}
		}
	} 
	if(count1!=-10&& count2!=-10){
		choosed=in[count1]+in[count2];
	}
	else{return(false);}

	AFill_Plot(para,comb,massclose);
	return(true);
}


bool Combine2DifferentFS_TLorentzvector(CDraw &para, TH1 *comb, std::vector<TLorentzVector> in1,std::vector<TLorentzVector> &in2,float obj_mass, float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, TLorentzVector &choosed){

	int num1 = in1.size(), num2=in2.size();
	int loop1,loop2;
	int count1 = -10,count2 = -10;
	float massclose=100000;
	float re_mass=100000.0;
	TLorentzVector mom1,mom2;
	bool judge;

	for(loop1=0;loop1<num1;loop1++){
		for(loop2=1;loop2<num2;loop2++){

			mom1 = in1[loop1];
			mom2 = in2[loop2];
			judge=Combine2_direct(mom1, mom2,cut_mlow,cut_mup, cut_ptlow, cut_ptup, &re_mass);
			if(judge && std::abs(re_mass-obj_mass)<std::abs(massclose-obj_mass)){
				count1 = loop1;
				count2 = loop2;
				massclose = re_mass;
			}
		}
	} 
	if(count1!=-10&& count2!=-10){
		choosed=in1[count1]+in2[count2];
	}
	else{return(false);}

	AFill_Plot(para,comb,massclose);
	return(true);
}
