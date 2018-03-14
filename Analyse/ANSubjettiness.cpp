#include "ANSubjettiness.h"

bool AGetNSubjettiness(CDraw &para, fastjet::PseudoJet &jet){
	CNSubjettiness::CAxesStruct Axes_choose = para.NSubjettiness.GetAxes();
	CNSubjettiness::CMeasureStruct Measure_choose = para.NSubjettiness.GetMeasure(); 
	const fastjet::contrib::AxesDefinition & axes = Axes_choose.def();
	const fastjet::contrib::MeasureDefinition & measure= Measure_choose.def();
	float tau21=0,tau32=0;
	float tau1=0,tau2=0,tau3=0;
	bool JNS1,JNS2,JNS3,JNS21,JNS32;

	para.debug.Message(2,8,"input higgs jet constituents size",jet.constituents().size());
	para.debug.Message(2,8,"input  higgs jet",jet);

	JNS1  = ANSubjettiness(1,para,axes,measure,jet,tau1);
	if(!JNS1){para.debug.Message(2,8,"tau1 is wrong",tau1);return(false);}
	JNS2  = ANSubjettiness(2,para,axes,measure,jet,tau2);
	if(!JNS2){para.debug.Message(2,8,"tau1 is wrong",tau2);return(false);}
	JNS3  = ANSubjettiness(3,para,axes,measure,jet,tau3);
	if(!JNS3){para.debug.Message(2,8,"tau1 is wrong",tau3);return(false);}
	JNS21 = ANSubjettiness_ratio(2,1,para,axes,measure,jet,tau21);
	if(!JNS21){para.debug.Message(2,8,"tau1 is wrong",tau21);return(false);}
	JNS32 = ANSubjettiness_ratio(3,2,para,axes,measure,jet,tau32);
	if(!JNS32){para.debug.Message(2,8,"tau1 is wrong",tau32);return(false);}

	if(std::abs(tau21 - tau2/tau1) > para.NSubjettiness.epsilon)
	{para.debug.Message(6,8,"tau21 is wrong",tau21);return(false);}
	if(std::abs(tau32 - tau3/tau2) > para.NSubjettiness.epsilon)
	{para.debug.Message(6,8,"tau32 is wrong:",tau32);return(false);}
	return(true);
}

bool ANSubjettiness(int N, CDraw &para, const fastjet::contrib::AxesDefinition &axes, const fastjet::contrib::MeasureDefinition &measure, fastjet::PseudoJet &jet, float &tauN){

	fastjet::contrib::Nsubjettiness  nSub(N,axes,measure);
	tauN = nSub(jet);
	if(N==1){
		if(para.NSubjettiness.JCUT_tau1==true && (tauN<para.NSubjettiness.CUT_tau1d || tauN>para.NSubjettiness.CUT_tau1u)){return(false);}
	}
	else if(N==2){
		if(para.NSubjettiness.JCUT_tau2==true && (tauN<para.NSubjettiness.CUT_tau2d || tauN>para.NSubjettiness.CUT_tau2u)){return(false);}
	}
	else if(N==3){
		if(para.NSubjettiness.JCUT_tau3==true && (tauN<para.NSubjettiness.CUT_tau3d || tauN>para.NSubjettiness.CUT_tau3u)){return(false);}
	}
	return(true);
}


bool ANSubjettiness_ratio(int N, int M, CDraw &para,const  fastjet::contrib::AxesDefinition &axes, const fastjet::contrib::MeasureDefinition &measure, fastjet::PseudoJet &jet, float &tauNM){

	fastjet::contrib::NsubjettinessRatio nSubRatio(N,M,axes,measure);
	tauNM = nSubRatio(jet);
	if(N==2 && M==1){
		if(para.NSubjettiness.JCUT_tau21==true && (tauNM<para.NSubjettiness.CUT_tau21d || tauNM>para.NSubjettiness.CUT_tau21u)){return(false);}
	}
	else if(N==3 && M==2){
		if(para.NSubjettiness.JCUT_tau32==true && (tauNM<para.NSubjettiness.CUT_tau32d || tauNM>para.NSubjettiness.CUT_tau32u)){return(false);}
	}
	return(true);
}

