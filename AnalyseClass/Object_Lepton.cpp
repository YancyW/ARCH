#include "AnalyseClass/Object.h"

bool AObject::Fill_Lepton(CDraw &para, AnalyseClass &analyse){
	analyse.out_weight = 1;

	para.debug.Message(2,99,"in AObject::Fill, begin");
	para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Has_DS_Best()",OMCLep.Muon_Pool().Has_DS_Best());
	if(OMCLep.Muon_Pool().Has_DS_Best()){
		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_Combine()->M()",OMCLep.Muon_Pool().Best_DS_Combine()[0]->M());
		analyse.var.var[0].variable  = OMCLep.Muon_Pool().Best_DS_Combine()[0]->M();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_Combine()->Pt()",OMCLep.Muon_Pool().Best_DS_Combine()[0]->Pt());
		analyse.var.var[1].variable  = OMCLep.Muon_Pool().Best_DS_Combine()[0]->Pt();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_Combine()->CosTheta()",OMCLep.Muon_Pool().Best_DS_Combine()[0]->CosTheta());
		analyse.var.var[2].variable  = OMCLep.Muon_Pool().Best_DS_Combine()[0]->CosTheta();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_Recoil().M()",OMCLep.Muon_Pool().Best_DS_Recoil().M());
		analyse.var.var[4].variable  = OMCLep.Muon_Pool().Best_DS_Recoil().M();

		para.debug.Message(2,99,"in AObject::Fill, OMCVisibleWOBestMuon->E",OMCVisibleWOBestMuon->E());
		analyse.var.var[5].variable  = OMCVisibleWOBestMuon->E();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Choosed_DS_Pair()[0].CosTheta()",OMCLep.Muon_Pool().Choosed_DS_Pair()[0].CosTheta());
		analyse.var.var[6].variable  = OMCLep.Muon_Pool().Choosed_DS_Pair()[0].CosTheta();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_First()[0].Pt()",OMCLep.Muon_Pool().Best_DS_First()[0]->Pt());
		analyse.var.var[10].variable = OMCLep.Muon_Pool().Best_DS_First()[0]->Pt();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_First()[0].E()",OMCLep.Muon_Pool().Best_DS_First()[0]->E());
		analyse.var.var[11].variable = OMCLep.Muon_Pool().Best_DS_First()[0]->E();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_First()[0].CosTheta()",OMCLep.Muon_Pool().Best_DS_First()[0]->CosTheta());
		analyse.var.var[12].variable  = OMCLep.Muon_Pool().Best_DS_First()[0]->CosTheta();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_Second()[0].Pt()",OMCLep.Muon_Pool().Best_DS_Second()[0]->Pt());
		analyse.var.var[13].variable = OMCLep.Muon_Pool().Best_DS_Second()[0]->Pt();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_Second()[0].E()",OMCLep.Muon_Pool().Best_DS_Second()[0]->E());
		analyse.var.var[14].variable = OMCLep.Muon_Pool().Best_DS_Second()[0]->E();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Best_DS_Second()[0].CosTheta()",OMCLep.Muon_Pool().Best_DS_Second()[0]->CosTheta());
		analyse.var.var[15].variable  = OMCLep.Muon_Pool().Best_DS_Second()[0]->CosTheta();
	}


	para.debug.Message(2,99,"in AObject::Fill, OMCInvisible->CosTheta",OMCInvisible->CosTheta());
	analyse.var.var[3].variable  = OMCInvisible->CosTheta();

	para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Pool_Num()",OMCLep.Muon_Pool().Pool_Num());
	analyse.var.var[7].variable  = OMCLep.Muon_Pool().Pool_Num();

	para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().First_Num()",OMCLep.Muon_Pool().First_Num());
	analyse.var.var[8].variable = OMCLep.Muon_Pool().First_Num();

	para.debug.Message(2,99,"in AObject::Fill, OMCLep.Muon_Pool().Second_Num()",OMCLep.Muon_Pool().Second_Num());
	analyse.var.var[9].variable = OMCLep.Muon_Pool().Second_Num();




	para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Has_DS_Best()",OMCLep.Elec_Pool().Has_DS_Best());
	if(OMCLep.Elec_Pool().Has_DS_Best()){

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_Combine()->M()",OMCLep.Elec_Pool().Best_DS_Combine()[0]->M());
		analyse.var.var[16].variable  = OMCLep.Elec_Pool().Best_DS_Combine()[0]->M();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_Combine()->Pt()",OMCLep.Elec_Pool().Best_DS_Combine()[0]->Pt());
		analyse.var.var[17].variable  = OMCLep.Elec_Pool().Best_DS_Combine()[0]->Pt();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_Combine()->CosTheta()",OMCLep.Elec_Pool().Best_DS_Combine()[0]->CosTheta());
		analyse.var.var[18].variable  = OMCLep.Elec_Pool().Best_DS_Combine()[0]->CosTheta();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_Recoil().M()",OMCLep.Elec_Pool().Best_DS_Recoil().M());
		analyse.var.var[19].variable  = OMCLep.Elec_Pool().Best_DS_Recoil().M();

		para.debug.Message(2,99,"in AObject::Fill, OMCVisibleWOBestElec->E",OMCVisibleWOBestElec->E());
		analyse.var.var[20].variable  = OMCVisibleWOBestElec->E();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Choosed_DS_Pair()[0].CosTheta()",OMCLep.Elec_Pool().Choosed_DS_Pair()[0].CosTheta());
		analyse.var.var[21].variable  = OMCLep.Elec_Pool().Choosed_DS_Pair()[0].CosTheta();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_First()[0].Pt()",OMCLep.Elec_Pool().Best_DS_First()[0]->Pt());
		analyse.var.var[25].variable = OMCLep.Elec_Pool().Best_DS_First()[0]->Pt();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_First()[0].E()",OMCLep.Elec_Pool().Best_DS_First()[0]->E());
		analyse.var.var[26].variable = OMCLep.Elec_Pool().Best_DS_First()[0]->E();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_First()[0].CosTheta()",OMCLep.Elec_Pool().Best_DS_First()[0]->CosTheta());
		analyse.var.var[27].variable  = OMCLep.Elec_Pool().Best_DS_First()[0]->CosTheta();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_Second()[0].Pt()",OMCLep.Elec_Pool().Best_DS_Second()[0]->Pt());
		analyse.var.var[28].variable = OMCLep.Elec_Pool().Best_DS_Second()[0]->Pt();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_Second()[0].E()",OMCLep.Elec_Pool().Best_DS_Second()[0]->E());
		analyse.var.var[29].variable = OMCLep.Elec_Pool().Best_DS_Second()[0]->E();

		para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Best_DS_Second()[0].CosTheta()",OMCLep.Elec_Pool().Best_DS_Second()[0]->CosTheta());
		analyse.var.var[30].variable  = OMCLep.Elec_Pool().Best_DS_Second()[0]->CosTheta();
	}

	para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Pool_Num()",OMCLep.Elec_Pool().Pool_Num());
	analyse.var.var[22].variable = OMCLep.Elec_Pool().Pool_Num();

	para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().First_Num()",OMCLep.Elec_Pool().First_Num());
	analyse.var.var[23].variable = OMCLep.Elec_Pool().First_Num();

	para.debug.Message(2,99,"in AObject::Fill, OMCLep.Elec_Pool().Second_Num()",OMCLep.Elec_Pool().Second_Num());
	analyse.var.var[24].variable = OMCLep.Elec_Pool().Second_Num();



	para.debug.Message(2,99,"in AObject::Fill, OMCJet.Num_Jets()",OMCJet.Num_Jets());
	analyse.var.var[31].variable = OMCJet.Num_Jets();


	if(OMCJet.Num_Jets()>=2){
		analyse.counter.getCounter("JET_NUM");
	}

	if(OMCJet.Num_Jets()>=2 && OMCJet.Jets_Pool().Has_SS_Best()){
		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[0]->E()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->E());
		analyse.var.var[32].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->E();

		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[0]->CosTheta()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->CosTheta());
		analyse.var.var[33].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->CosTheta();

		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[0]->Has_JEP()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->Has_JEP());
		if(OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->Has_JEP()){
			para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[0]->JEP()[2]",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[2]);
			analyse.var.var[34].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[2];
			para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[0]->JEP()[6]",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[6]);
			analyse.var.var[35].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP_Num()-1];
			analyse.var.var[49].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[0];
			analyse.var.var[50].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[1];
			analyse.var.var[51].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[2];
			analyse.var.var[52].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[3];
			analyse.var.var[53].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[4];
			analyse.var.var[54].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[5];
			analyse.var.var[55].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->JEP()[6];
		}
		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[0]->Pt()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->Pt());
		analyse.var.var[36].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->Pt();
		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[0]->What_Jet_Type()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->What_Jet_Type());
		analyse.var.var[37].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->What_Jet_Type();




		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[0].E()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->E());
		analyse.var.var[38].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->E();
		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[0].CosTheta()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->CosTheta());
		analyse.var.var[39].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->CosTheta();

		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[1]->Has_JEP()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->Has_JEP());
		if(OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->Has_JEP()){
			para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[1]->JEP()[2]",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[2]);
			analyse.var.var[40].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[2];
			para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[1]->JEP()[6]",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[6]);
			analyse.var.var[41].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP_Num()-1];
			analyse.var.var[56].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[0];
			analyse.var.var[57].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[1];
			analyse.var.var[58].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[2];
			analyse.var.var[59].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[3];
			analyse.var.var[60].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[4];
			analyse.var.var[61].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[5];
			analyse.var.var[62].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->JEP()[6];
		}
		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[1]->Pt()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->Pt());
		analyse.var.var[42].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->Pt();
		para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Pool()[1]->What_Jet_Type()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->What_Jet_Type());
		analyse.var.var[43].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Second()->What_Jet_Type();


	    para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Best_SS_Combine()->M()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Combine()->M());
	    analyse.var.var[44].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Combine()->M();
	    para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Best_SS_Combine()->Pt()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Combine()->Pt());
	    analyse.var.var[45].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Combine()->Pt();
	    para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Best_SS_Combine()->CosTheta()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Combine()->CosTheta());
	    analyse.var.var[46].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Combine()->CosTheta();
	    para.debug.Message(2,99,"in AObject::Fill, OMCJet.Jet_Pool().Best_SS_Recoil()->M()",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Recoil()->M());
	    analyse.var.var[47].variable = OMCJet.Jets_Pool().Choosed_SS_Pair()[0].Recoil()->M();
	}


	analyse.var.var[63].variable = para.Event();

	if(
	   analyse.var.var[31].variable > 3.99 &&
       analyse.var.var[32].variable > 30 &&
       std::abs(analyse.var.var[33].variable) < 1 &&
       analyse.var.var[37].variable < 4.9 &&
       analyse.var.var[38].variable > 10  &&
       std::abs(analyse.var.var[39].variable) < 1 &&
       analyse.var.var[43].variable < 4.9 &&
       analyse.var.var[44].variable>50 && analyse.var.var[44].variable<125 &&
       analyse.var.var[45].variable>0 && analyse.var.var[45].variable<70 && 
       analyse.var.var[47].variable>80 && analyse.var.var[47].variable<200 && 
	   analyse.var.var[55].variable>0 &&
	   analyse.var.var[62].variable>0
	   ){
		ShowMessage(2,"This event has no problem",para.Event());
//		ShowMessage(2,"This event has no problem",OMCJet.Jets_Pool().Choosed_SS_Pair()[0].First()->_fp.constituents());
	}

	if(OMCJet.Has_Jet()){
		int k=0;
		for(int i=0;i<OMCJet.Num_Jets();i++){
			k++;
			if(OMCJet.Jets_Pool().Pool()[i]->Has_JEP()){
				analyse.var.vec[i].variable=OMCJet.Jets_Pool().Pool()[i]->JEP();
				analyse.var.vec[i+2].variable=OMCJet.Jets_Pool().Pool()[i]->JEP_Fit();
			}
			if(k>=2){
				analyse.counter.getCounter("JES_JEP");
				break;
			}
		}
		
		analyse.var.vec[4].variable=OMCJet.Pt();
		analyse.var.vec[5].variable=OMCJet.E();
		analyse.var.vec[6].variable=OMCJet.CosTheta();
		analyse.var.vec[7].variable=OMCJet.PID();
	}


	return(true);

}
