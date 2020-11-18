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
		else{return(false);}
	}
	else{Jcomb=true;}

	if(para.recoil.SWITCH){
		para.debug.Message(3,2,"begin recoil");
		Jrecoil=Analysis_Recoil(para,plots,object);
		if(Jrecoil){analyse.counter.getCounter("operation_recoil");}
		else{return(false);}
	}
	else{Jrecoil=true;}


	if(para.recoil.comb_SWITCH){
		para.debug.Message(3,2,"begin combine and recoil");
		Jcomb_recoil=Analysis_Combine_Recoil(para,plots,object.Vjet,object.Vbjet,object.Vcjet,object.Vqjet,object.Vuntagjet, object.Velec,object.Vmuon,object.Vcombine_jet1,object.Vcombine_jet2, object.Vcombine_elec1, object.Vcombine_elec2, object.Vcombine_muon1, object.Vcombine_muon2);
		if(Jcomb_recoil){analyse.counter.getCounter("operation_recoil_comb");}
		else{return(false);}
	}
	else{Jcomb_recoil=true;}

	if(Jcomb&&Jrecoil&&Jcomb_recoil){
		Jcombine=true;
		analyse.counter.getCounter("operation");
		return(true);
	}
	else{
		return(false);
	}
}

/*float Combine4_direct(TLorentzVector mom1, TLorentzVector mom2,TLorentzVector mom3, TLorentzVector mom4, 
  float cut_mlow1, float cut_mup1, float obj_mass1, 
  float cut_mlow2, float cut_mup2, float obj_mass2, 
  float *Fmass1, float *Fmass2,int *group){

  float xi_min=10000.0;
  bool judge1=false,judge2=false,judge_xi=false;
  float re_mass1=0.0,re_mass2=0.0;

  judge1=Combine2_direct(mom1, mom2,cut_mlow1,cut_mup1, &re_mass1);
  judge2=Combine2_direct(mom3, mom4,cut_mlow2,cut_mup2, &re_mass2);
  if(judge1&&judge2){
  judge_xi=Find_ximin(&xi_min,re_mass1,obj_mass1,re_mass2,obj_mass2,Fmass1, Fmass2);
  if(judge_xi){*group=1;}
  }

  judge1=Combine2_direct(mom1, mom3,cut_mlow1,cut_mup1, &re_mass1);
  judge2=Combine2_direct(mom2, mom4,cut_mlow2,cut_mup2, &re_mass2);
  if(judge1&&judge2){
  judge_xi=Find_ximin(&xi_min,re_mass1,obj_mass1,re_mass2,obj_mass2,Fmass1, Fmass2);
  if(judge_xi){*group=2;}
  }

  judge1=Combine2_direct(mom1, mom4,cut_mlow1,cut_mup1, &re_mass1);
  judge2=Combine2_direct(mom2, mom3,cut_mlow2,cut_mup2, &re_mass2);
  if(judge1&&judge2){
  judge_xi=Find_ximin(&xi_min,re_mass1,obj_mass1,re_mass2,obj_mass2,Fmass1, Fmass2);
  if(judge_xi){*group=3;}
  }

  judge1=Combine2_direct(mom2, mom3,cut_mlow1,cut_mup1, &re_mass1);
  judge2=Combine2_direct(mom1, mom4,cut_mlow2,cut_mup2, &re_mass2);
  if(judge1&&judge2){
  judge_xi=Find_ximin(&xi_min,re_mass1,obj_mass1,re_mass2,obj_mass2,Fmass1, Fmass2);
  if(judge_xi){*group=4;}
  }

  judge1=Combine2_direct(mom2, mom4,cut_mlow1,cut_mup1, &re_mass1);
  judge2=Combine2_direct(mom1, mom3,cut_mlow2,cut_mup2, &re_mass2);
  if(judge1&&judge2){
  judge_xi=Find_ximin(&xi_min,re_mass1,obj_mass1,re_mass2,obj_mass2,Fmass1, Fmass2);
  if(judge_xi){*group=5;}
  }

  judge1=Combine2_direct(mom3, mom4,cut_mlow1,cut_mup1, &re_mass1);
  judge2=Combine2_direct(mom1, mom2,cut_mlow2,cut_mup2, &re_mass2);
  if(judge1&&judge2){
  judge_xi=Find_ximin(&xi_min,re_mass1,obj_mass1,re_mass2,obj_mass2,Fmass1, Fmass2);
  if(judge_xi){*group=6;}
  }

  return(xi_min);
  }*/

bool Analysis_Combine(CDraw &para, MyPlots *plots, AObject& object,bool *Jcomb1, bool *Jcomb2, bool *Jcomb3, bool *Jcomb4, bool *Jcomb5, bool *Jcomb6){

	std::vector<Jet*> Vchoose_jet,Vleft_jet;
	std::vector<Electron*> Vchoose_elec,Vleft_elec;
	std::vector<Muon*> Vchoose_muon,Vleft_muon;
	std::vector<Jet*> Vparticle1;

	bool Jrecomb1_jet =false,Jrecomb2_jet =false;
	bool Jrecomb1_bjet=false,Jrecomb2_bjet=false;
	bool Jrecomb1_cjet=false,Jrecomb2_cjet=false;
	bool Jrecomb1_qjet=false,Jrecomb2_qjet=false;
	bool Jrecomb1_elec=false,Jrecomb2_elec=false;
	bool Jrecomb1_muon=false,Jrecomb2_muon=false;

	if(para.signal.NUM_elec==2){
		Jrecomb2_elec=true;
	}
	else if(para.signal.NUM_muon==2){
		Jrecomb2_muon=true;
	}

	////if(para.signal.NUM_bjet==2){
	////	Jrecomb1_bjet=true ,Jrecomb2_bjet=false;
	////	Jrecomb1_cjet=false,Jrecomb2_cjet=false;
	////	Jrecomb1_qjet=false,Jrecomb2_qjet=true ;
	////	Jrecomb1_elec=false,Jrecomb2_elec=false;
	////	Jrecomb1_muon=false,Jrecomb2_muon=false;
	////}
	////if(para.signal.NUM_cjet==2){
	////	Jrecomb1_bjet=false,Jrecomb2_bjet=false;
	////	Jrecomb1_cjet=true ,Jrecomb2_cjet=true;
	////	Jrecomb1_qjet=false,Jrecomb2_qjet=false;
	////	Jrecomb1_elec=false,Jrecomb2_elec=false;
	////	Jrecomb1_muon=false,Jrecomb2_muon=false;
	////}
	////else if(para.signal.NUM_elec==2){
	////	if(para.signal.VETO_bjet && para.signal.VETO_cjet){
	////		Jrecomb1_qjet=true, Jrecomb2_elec=true;
	////	}
	////	else if(!para.signal.VETO_bjet && para.signal.VETO_cjet){
	////        Jrecomb1_bjet=true, Jrecomb1_qjet=true , Jrecomb2_elec=true;
	////	}
	////	else if(para.signal.VETO_bjet && !para.signal.VETO_cjet){
	////        Jrecomb1_cjet=true, Jrecomb1_qjet=true , Jrecomb2_elec=true;
	////	}
	////	else{
	////		Jrecomb1_jet=true ,Jrecomb2_elec=true;
	////	}
	////}
	////else if(para.signal.NUM_muon==2){
	////	if(para.signal.VETO_bjet ){
	////		Jrecomb1_qjet=true ,Jrecomb2_muon=true;
	////	}
	////	else{
	////		Jrecomb1_jet=true ,Jrecomb2_muon=true;
	////	}
	////}

	float Icomb1_m,Icomb2_m;
	float cut_mlow1, cut_mup1, cut_mlow2, cut_mup2,cut_ptlow2,cut_ptup2;
	////Icomb1_m = para.comb.jets.CUT_massr[0];

	////cut_mlow1 = para.comb.jets.CUT_massd[0];
	////cut_mup1  = para.comb.jets.CUT_massu[0];

	Icomb2_m  = para.comb.jets.CUT_massr[0];
	cut_mlow2 = para.comb.jets.CUT_massd[0];
	cut_mup2  = para.comb.jets.CUT_massu[0];


	cut_ptlow2 = para.comb.jets.CUT_ptd[0];
	cut_ptup2  = para.comb.jets.CUT_ptu[0];

	////if(Jrecomb1_bjet && Jrecomb2_bjet){
	////	*Jcomb1 = Combine4SameFS(plots, Vbjet, cut_mlow1, cut_mup1, Icomb1_m, cut_mlow2, cut_mup2, Icomb2_m, Vcombined_jet1, Vcombined_jet2);
	////	*Jcomb2 = *Jcomb1;
	////}

	////if(Jrecomb1_elec&& Jrecomb2_elec){
	////	*Jcomb1 = Combine4SameFS(plots, Velec, cut_mlow1, cut_mup1, Icomb1_m, cut_mlow2, cut_mup2, Icomb2_m, Vcombined_elec1, Vcombined_elec2);
	////	*Jcomb2 = *Jcomb1;
	////}

	////if(Jrecomb1_muon && Jrecomb2_muon){
	////	*Jcomb1 = Combine4SameFS(plots, Vmuon, cut_mlow1, cut_mup1, Icomb1_m, cut_mlow2, cut_mup2, Icomb2_m, Vcombined_muon1, Vcombined_muon2);
	////	*Jcomb2 = *Jcomb1;
	////}

	////if(Jrecomb1_jet){
	////	*Jcomb1=Combine2SameFS(plots->fcomb1M,Vjet,Icomb1_m,cut_mlow1, cut_mup1, Vcombined_jet1,Vleft_jet);
	////	if(!*Jcomb1){return(false);}
	////	Vjet = Vleft_jet;
	////}
	////if(Jrecomb2_jet){
	////	*Jcomb2=Combine2SameFS(plots->fcomb2M,Vjet,Icomb2_m,cut_mlow2, cut_mup2, Vcombined_jet2,Vleft_jet);
	////	if(!*Jcomb2){return(false);}
	////	Vjet = Vleft_jet;
	////}


	////if(Jrecomb1_bjet && Jrecomb1_qjet && !Jrecomb1_cjet){

	////	Vparticle1 = Vbjet + Vqjet;	
	////	*Jcomb1=Combine2SameFS(plots->fcomb1M,Vparticle1,Icomb1_m,cut_mlow1, cut_mup1, Vcombined_jet1,Vleft_jet);
	////	if(!*Jcomb1){return(false);}
	////	Vbjet = Vleft_jet;
	////}
	////else if(Jrecomb1_bjet && !Jrecomb1_qjet && !Jrecomb1_cjet){
	////	*Jcomb1=Combine2SameFS(plots->fcomb1M,Vbjet,Icomb1_m,cut_mlow1, cut_mup1, Vcombined_jet1,Vleft_jet);
	////	if(!*Jcomb1){return(false);}
	////	Vbjet = Vleft_jet;
	////}
	////else if(!Jrecomb2_bjet && Jrecomb1_cjet && Jrecomb1_qjet){
	////	Vparticle1 = Vcjet + Vqjet;	
	////	*Jcomb1=Combine2SameFS(plots->fcomb1M,Vparticle1,Icomb1_m,cut_mlow1, cut_mup1, Vcombined_jet1,Vleft_jet);
	////	if(!*Jcomb1){return(false);}
	////	Vcjet = Vleft_jet;
	////}
	////else if(!Jrecomb1_bjet && !Jrecomb1_qjet && Jrecomb1_cjet){
	////	*Jcomb1=Combine2SameFS(plots->fcomb1M,Vcjet,Icomb1_m,cut_mlow1, cut_mup1, Vcombined_jet1,Vleft_jet);
	////	if(!*Jcomb1){return(false);}
	////	Vcjet = Vleft_jet;
	////}
	////else if(!Jrecomb1_bjet &&  Jrecomb1_qjet && !Jrecomb1_cjet){
	////	*Jcomb1=Combine2SameFS(plots->fcomb1M,Vqjet,Icomb1_m,cut_mlow1, cut_mup1, Vcombined_jet1,Vleft_jet);
	////	if(!*Jcomb1){return(false);}
	////	Vqjet = Vleft_jet;
	////}


	////if(Jrecomb2_bjet){
	////	*Jcomb2=Combine2SameFS(plots->fcomb2M,Vbjet,Icomb1_m,cut_mlow2, cut_mup2, Vcombined_jet2,Vleft_jet);
	////	if(!*Jcomb2){return(false);}
	////}

	////if(Jrecomb2_cjet){
	////	*Jcomb2=Combine2SameFS(plots->fcomb2M,Vcjet,Icomb1_m,cut_mlow2, cut_mup2, Vcombined_jet2,Vleft_jet);
	////	if(!*Jcomb2){return(false);}
	////}

	////if(Jrecomb2_qjet){
	////	*Jcomb2=Combine2SameFS(plots->fcomb2M,Vqjet,Icomb1_m,cut_mlow2, cut_mup2, Vcombined_jet2,Vleft_jet);
	////	if(!*Jcomb2){return(false);}
	////}
	////if(Jrecomb1_elec){
	////	*Jcomb1=Combine2SameFS(plots->fcomb1M,Velec,Icomb1_m,cut_mlow1, cut_mup1, Vcombined_elec1,Vleft_elec);
	////	if(!*Jcomb1){return(false);}
	////	Velec= Vleft_elec;
	////}
	if(Jrecomb2_elec){
		*Jcomb2=Combine2SameFS(para,plots->fcomb2M,object.Velec,Icomb1_m,cut_mlow2, cut_mup2, cut_ptlow2, cut_ptup2, object.Vcombine_elec2,Vleft_elec);
		if(!*Jcomb2){return(false);}
	}
	////if(Jrecomb1_muon){
	////	*Jcomb1=Combine2SameFS(plots->fcomb1M,Vmuon,Icomb1_m,cut_mlow1, cut_mup1, Vcombined_muon1,Vleft_muon);
	////	if(!*Jcomb1){return(false);}
	////	Vmuon= Vleft_muon;
	////}
	if(Jrecomb2_muon){
		*Jcomb2=Combine2SameFS(para,plots->fcomb2M,object.Vmuon,Icomb1_m,cut_mlow2, cut_mup2, cut_ptlow2, cut_ptup2, object.Vcombine_muon2,Vleft_muon);
		if(!*Jcomb2){return(false);}
	}

	*Jcomb1=true;
	if(Jcomb1&&Jcomb2){
		return(true);
	}
	return(false);
}

