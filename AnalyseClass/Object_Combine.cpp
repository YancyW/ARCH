#include "AnalyseClass/Object.h"

bool AObject::Fill_Combine(CDraw &para, AnalyseClass &analyse){
	analyse.var.var[16].variable = Vcombine2[0].M(); 
	analyse.var.var[17].variable = Vcombine2[0].Pt(); 
	analyse.var.var[18].variable = Vcombine2[0].Eta(); 

	analyse.var.var[19].variable = Vcombine1[0].M(); 
	analyse.var.var[20].variable = Vcombine1[0].Pt(); 
	analyse.var.var[21].variable = Vcombine1[0].Eta(); 

	analyse.var.var[22].variable = Vcombine3[0].M(); 
	analyse.var.var[23].variable = Vcombine3[0].Pt(); 
	analyse.var.var[24].variable = Vcombine3[0].Eta(); 

	analyse.var.var[25].variable = Vcombine4[0].M(); 
	analyse.var.var[26].variable = Vcombine4[0].Pt(); 
	analyse.var.var[27].variable = Vcombine4[0].Eta(); 

	analyse.var.var[28].variable = Vcombine5[0].M(); 
	analyse.var.var[29].variable = Vcombine5[0].Pt(); 
	analyse.var.var[30].variable = Vcombine5[0].Eta(); 

	analyse.var.var[31].variable = Vvalue[0]; 
	return(true);
}
