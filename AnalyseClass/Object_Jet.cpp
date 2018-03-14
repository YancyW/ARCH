#include "AnalyseClass/Object.h"

bool AObject::Fill_Jet(CDraw &para, AnalyseClass &analyse){
	analyse.out_weight = 1;

	para.debug.Message(2,99,"in AObject::Fill, begin");
	para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Has_DS_Best()",OMCLep.Muon_Pool().Has_DS_Best());
	if(OMCLep.Muon_Pool().Has_DS_Best()){
		analyse.var.var[0].variable  = OMCLep.Muon_Pool().Best_DS_Combine()[0]->M();
		analyse.var.var[1].variable  = OMCLep.Muon_Pool().Best_DS_Combine()[0]->Pt();
		analyse.var.var[2].variable  = OMCLep.Muon_Pool().Best_DS_Combine()[0]->CosTheta();
		analyse.var.var[4].variable  = OMCLep.Muon_Pool().Best_DS_Recoil().M();
		analyse.var.var[5].variable  = OMCVisibleWOBestMuon->E();
		analyse.var.var[6].variable  = OMCLep.Muon_Pool().Choosed_DS_Pair()[0].CosTheta();
		analyse.var.var[10].variable = OMCLep.Muon_Pool().Best_DS_First()[0]->Pt();
		analyse.var.var[11].variable = OMCLep.Muon_Pool().Best_DS_First()[0]->E();
		analyse.var.var[12].variable = OMCLep.Muon_Pool().Best_DS_First()[0]->CosTheta();
		analyse.var.var[13].variable = OMCLep.Muon_Pool().Best_DS_Second()[0]->Pt();
		analyse.var.var[14].variable = OMCLep.Muon_Pool().Best_DS_Second()[0]->E();
		analyse.var.var[15].variable = OMCLep.Muon_Pool().Best_DS_Second()[0]->CosTheta();
	}

	analyse.var.var[3].variable = OMCInvisible->CosTheta();
	analyse.var.var[7].variable = OMCLep.Muon_Pool().Pool_Num();
	analyse.var.var[8].variable = OMCLep.Muon_Pool().First_Num();
	analyse.var.var[9].variable = OMCLep.Muon_Pool().Second_Num();




	if(OMCLep.Elec_Pool().Has_DS_Best()){
		analyse.var.var[16].variable = OMCLep.Elec_Pool().Best_DS_Combine()[0]->M();
		analyse.var.var[17].variable = OMCLep.Elec_Pool().Best_DS_Combine()[0]->Pt();
		analyse.var.var[18].variable = OMCLep.Elec_Pool().Best_DS_Combine()[0]->CosTheta();
		analyse.var.var[19].variable = OMCLep.Elec_Pool().Best_DS_Recoil().M();
		analyse.var.var[20].variable = OMCVisibleWOBestElec->E();
		analyse.var.var[21].variable = OMCLep.Elec_Pool().Choosed_DS_Pair()[0].CosTheta();
		analyse.var.var[25].variable = OMCLep.Elec_Pool().Best_DS_First()[0]->Pt();
		analyse.var.var[26].variable = OMCLep.Elec_Pool().Best_DS_First()[0]->E();
		analyse.var.var[27].variable = OMCLep.Elec_Pool().Best_DS_First()[0]->CosTheta();
		analyse.var.var[28].variable = OMCLep.Elec_Pool().Best_DS_Second()[0]->Pt();
		analyse.var.var[29].variable = OMCLep.Elec_Pool().Best_DS_Second()[0]->E();
		analyse.var.var[30].variable = OMCLep.Elec_Pool().Best_DS_Second()[0]->CosTheta();
	}

	analyse.var.var[22].variable = OMCLep.Elec_Pool().Pool_Num();
	analyse.var.var[23].variable = OMCLep.Elec_Pool().First_Num();
	analyse.var.var[24].variable = OMCLep.Elec_Pool().Second_Num();
	analyse.var.var[31].variable = OMCJet.Num_Jets();


	if(OMCJet.Num_Jets()>=4 && OMCJet.Jets_Pool().Has_SS_Best()){
		analyse.var.var[32].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->E();
		analyse.var.var[33].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->CosTheta();
		analyse.var.var[34].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->Pt();
		analyse.var.var[35].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->M();
		analyse.var.var[36].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->What_Jet_Type();

		analyse.var.var[37].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->E();
		analyse.var.var[38].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->CosTheta();
		analyse.var.var[39].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->Pt();
		analyse.var.var[40].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->M();
		analyse.var.var[41].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->What_Jet_Type();

		analyse.var.var[42].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->E();
		analyse.var.var[43].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->CosTheta();
		analyse.var.var[44].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->Pt();
		analyse.var.var[45].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->M();
		analyse.var.var[46].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->What_Jet_Type();

		analyse.var.var[47].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->E();
		analyse.var.var[48].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->CosTheta();
		analyse.var.var[49].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->Pt();
		analyse.var.var[50].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->M();
		analyse.var.var[51].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->What_Jet_Type();

		if(OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->Has_JEP()){
			analyse.var.var[52].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->JEP()[0];
			analyse.var.var[53].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->JEP()[1];
			analyse.var.var[54].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->JEP()[2];
			analyse.var.var[55].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->JEP()[3];
			analyse.var.var[56].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->JEP()[4];
			analyse.var.var[57].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->JEP()[5];
			analyse.var.var[58].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First ()->JEP()[6];
		}
		if(OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->Has_JEP()){
			analyse.var.var[59].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[0];
			analyse.var.var[60].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[1];
			analyse.var.var[61].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[2];
			analyse.var.var[62].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[3];
			analyse.var.var[63].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[4];
			analyse.var.var[64].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[5];
			analyse.var.var[65].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[6];
		}
		if(OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First()->Has_JEP()){
			analyse.var.var[66].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->JEP()[0];
			analyse.var.var[67].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->JEP()[1];
			analyse.var.var[68].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->JEP()[2];
			analyse.var.var[69].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->JEP()[3];
			analyse.var.var[70].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->JEP()[4];
			analyse.var.var[71].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->JEP()[5];
			analyse.var.var[72].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First ()->JEP()[6];
		}
		if(OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->Has_JEP()){
			analyse.var.var[73].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->JEP()[0];
			analyse.var.var[74].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->JEP()[1];
			analyse.var.var[75].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->JEP()[2];
			analyse.var.var[76].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->JEP()[3];
			analyse.var.var[77].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->JEP()[4];
			analyse.var.var[78].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->JEP()[5];
			analyse.var.var[79].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->JEP()[6];
		}

	    analyse.var.var[80].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Combine()->M();
	    analyse.var.var[81].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Combine()->Pt();
	    analyse.var.var[82].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Combine()->CosTheta();
	    analyse.var.var[83].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Recoil ()->M();
	    analyse.var.var[84].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].CosTheta();

	    analyse.var.var[85].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Combine()->M();
	    analyse.var.var[86].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Combine()->Pt();
	    analyse.var.var[87].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Combine()->CosTheta();
	    analyse.var.var[88].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Recoil ()->M();
	    analyse.var.var[89].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[1].CosTheta();
	}
	else{
		//ShowMessage(2,"no jet");
	}



	analyse.var.var[91].variable = para.Event();

	if(OMCJet.Has_Jet()&&OMCJet.Num_Jets()>=4 && OMCJet.Jets_Pool().Has_SS_Best()){
		analyse.var.vec[0].variable=OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First() ->JEP();
		analyse.var.vec[1].variable=OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First() ->JEP_Fit();
		analyse.var.vec[2].variable=OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP();
		analyse.var.vec[3].variable=OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP_Fit();
		
		analyse.var.vec[4].variable=OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First() ->JEP();
		analyse.var.vec[5].variable=OMCJet.Jets_Pool().Choosed_SS_Pair()[1].First() ->JEP_Fit();
		analyse.var.vec[6].variable=OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->JEP();
		analyse.var.vec[7].variable=OMCJet.Jets_Pool().Choosed_SS_Pair()[1].Second()->JEP_Fit();
		
		analyse.var.vec[8].variable=OMCJet.Pt();
		analyse.var.vec[9].variable=OMCJet.E();
		analyse.var.vec[10].variable=OMCJet.CosTheta();
		analyse.var.vec[11].variable=OMCJet.PID();
	}


	return(true);

}
