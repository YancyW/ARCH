#include "AHiggsTag.h"


bool AHiggsTag(CDraw &para, MyPlots *plots, fastjet::ClusterSequence &cs, std::vector<fastjet::PseudoJet> &subjets, std::vector<fastjet::PseudoJet> Vbquark,std::vector<fastjet::PseudoJet> Vcquark, fastjet::PseudoJet &HiggsJet, AnalyseClass &analyse){

	bool JMD=false,JNS=false;
	if(para.MassDrop.SWITCH){
		para.debug.Message(1,6,"begin MassDrop");
		for(int i=0;i<subjets.size();i++){
			JMD = AMassDrop(para,plots,cs,subjets[i], Vbquark, Vcquark,HiggsJet);
			if (JMD){break;}
		}
		if (!JMD){return(false);}
		else{
			//	pass_massdrop++;
			analyse.counter.getCounter("JSS_Massdrop");
			if(para.MassDrop.PLOT){
				plots->fmassdrop->Fill(HiggsJet.m());
			}
		}
	}
	else{JMD=true;}

	if(para.NSubjettiness.SWITCH){
		para.debug.Message(1,6,"begin ANSubjettiness");
		JNS = AGetNSubjettiness(para,HiggsJet);
		if (!JNS){return(false);}
		else{
			//pass_nsubjettiness++;
			analyse.counter.getCounter("JSS_Nsubjettiness");
		}
	}
	else{JNS=true;}

	if(JMD&&JNS){
		return(true);
	}
}



