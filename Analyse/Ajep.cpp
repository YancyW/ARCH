#include "Ajep.h"

bool JEP(CDraw &para, TH1 *hr, TH1 *hR, std::vector<fastjet::PseudoJet> jet_constituents, fastjet::PseudoJet input_jet, float *Phir, float *Phir_test, float coneR ,int nr){

	para.debug.Message(4,9,"begin JEP");
	para.debug.Message(4,9,"the input jet_constituents",jet_constituents);
	para.debug.Message(4,9,"the input jet",input_jet);
	float pTR=0.0;
	float value= 0;
	float pTr[nr];    
	for( size_t r_Cindex = 0; r_Cindex < nr; ++r_Cindex ) {
		pTr[r_Cindex] = 0;
	}//endfor r_Cindex

	float smallr[nr];
	for( size_t Cindex = 0; Cindex < nr; ++Cindex ) {
		smallr[Cindex] = (Cindex+1)*0.1;
	}//endfor Cindex

	fastjet::PseudoJet  fast_leading_jet = input_jet;

////if( fast_leading_jet.constituents().size() <= 1 ) {
////	para.debug.Message(3,9,"warning: leading jet constituents size is 1");
////	return(false);
////}//endif


	for( size_t consti_Cindex = 0; consti_Cindex < jet_constituents.size(); ++consti_Cindex ) {
		pTR = pTR + jet_constituents[consti_Cindex].pt();
	}//endfor consti_Cindex

	for( size_t consti_Cindex = 0; consti_Cindex < jet_constituents.size(); ++consti_Cindex ) {
		fastjet::PseudoJet component = jet_constituents[consti_Cindex];
		//int pid = component.user_info<PseudoJetInfo>().PID;
		float dR = DeltaR( fast_leading_jet, component );
		for( size_t r_Cindex = 0; r_Cindex < nr; ++r_Cindex ) {
			if( dR <= smallr[r_Cindex] ) {
				pTr[r_Cindex] = pTr[r_Cindex]+ component.pt()/pTR;
				hr->Fill(smallr[r_Cindex] ,component.pt()/pTR);
			}//endif
		}//endfor
	}//endfor consti_Cindex


	
	if( pTR > 0.0 ) {
		for( size_t r_Cindex = 0; r_Cindex < nr; ++r_Cindex ) {
			value=JEP_quark_1(pTR,r_Cindex);
			Phir     [r_Cindex]=Phir     [r_Cindex] + pTr[r_Cindex] ;
			Phir_test[r_Cindex]=Phir_test[r_Cindex] + value ;
			hR->Fill(smallr[r_Cindex] ,Phir[r_Cindex]-Phir_test[r_Cindex]);
		}//endfor r_Cindex
	}//endif
	else{return(false);}
	return(true);
}

float JEP_quark_1(float pt, int r){
	float value;

	switch(r){
		case 0:  value=0.182516 + 0.0199027*pt -0.000286074*pow(pt,2) + 1.613e-6*pow(pt,3);break;
		case 1:  value=0.580078 + 0.0115199*pt -0.000173929*pow(pt,2) + 0.999e-6*pow(pt,3);break;
		case 2:  value=0.794194 + 0.0047353*pt -0.000057837*pow(pt,2) + 2.599e-7*pow(pt,3);break;
		case 3:  value=0.897877 + 0.0019823*pt -0.000020366*pow(pt,2) + 7.599e-8*pow(pt,3);break;
		case 4:  value=0.951949 + 0.0010706*pt -0.000016390*pow(pt,2) + 1.613e-7*pow(pt,3);break;
		case 5:  value=0.991990 - 0.0001841*pt +6.550820e-6*pow(pt,2) + 1.613e-8*pow(pt,3);break;
		case 6:  value=1.0;break; 
		default: value=0.0;break;
	}
	return(value);
}

float JEP_quark_2(float pt, int r){
	float value;

	switch(r){
		case 0:  value=0.182516 + 0.0199027*pt -0.000286074*pow(pt,2) + 1.613e-6*pow(pt,3);break;
		case 1:  value=0.580078 + 0.0115199*pt -0.000173929*pow(pt,2) + 0.999e-6*pow(pt,3);break;
		case 2:  value=0.794194 + 0.0047353*pt -0.000057837*pow(pt,2) + 2.599e-7*pow(pt,3);break;
		case 3:  value=0.897877 + 0.0019823*pt -0.000020366*pow(pt,2) + 7.599e-8*pow(pt,3);break;
		case 4:  value=0.951949 + 0.0010706*pt -0.000016390*pow(pt,2) + 1.613e-7*pow(pt,3);break;
		case 5:  value=0.991990 - 0.0001841*pt +6.550820e-6*pow(pt,2) + 1.613e-8*pow(pt,3);break;
		case 6:  value=1.0;break; 
		default: value=0.0;break;
	}
	return(value);
}
