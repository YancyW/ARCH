#include "Book_single.h"
//------------------------------------------------------------------------------
void BookHistograms_single(CDraw &para, ExRootResult *result, MyPlots *plots, std::string name)
{
	std::string plot_filter=para.path.single_plot;
	std::string signal_name=plot_filter+name;

	std::string title,descrip,desnum;
	std::string fname,fnum,basic_name,class_name,observe_name;
	int array_num = 5;
	std::string filter_name[1];
	filter_name[0] = name;


	// book normal jets
	if(para.jet.SWITCH && para.jet.jets.SWITCH){

		class_name="jet";

		if(para.signal.NUM_jets!=0){
			BookH_single_number(result,&(plots->fJetnum),signal_name,class_name);
		}

		observe_name="pt";

		BookH_single_observable(result, plots->fJetPT, para.signal.NUM_jets, signal_name, class_name, observe_name, 50, 0.0, 800.0);

		observe_name="y";
		BookH_single_observable(result, plots->fJetY , para.signal.NUM_jets, signal_name, class_name, observe_name, 60, -3.0, 3.0);


		if (para.signal.NUM_jets>=2){
			observe_name="pt";
			BookH_single_same_class(result, plots->fJetPT, para.signal.NUM_jets, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fJetY , para.signal.NUM_jets, signal_name,class_name,observe_name);
		}
	}

	// book bjet 

	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.bjet.SWITCH){
		class_name="bjet";

		if(para.signal.NUM_bjet!=0){
			BookH_single_number(result,&(plots->fBJetnum),signal_name,class_name);
		}

		observe_name="pt";

		BookH_single_observable(result, plots->fBJetPT, para.signal.NUM_bjet, signal_name, class_name, observe_name, 50, 0.0, 100.0);

		observe_name="y";
		BookH_single_observable(result, plots->fBJetY , para.signal.NUM_bjet, signal_name, class_name, observe_name, 60, -3.0, 3.0);

		if (para.signal.NUM_bjet>=2){
			BookH_single_same_class(result, plots->fBJetPT, para.signal.NUM_bjet, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fBJetY , para.signal.NUM_bjet, signal_name,class_name,observe_name);
		}
	}

	// book cjet 
	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.bjet.SWITCH){
		class_name="cjet";

		if(para.signal.NUM_cjet!=0){
			BookH_single_number(result,&(plots->fCJetnum),signal_name,class_name);
		}

		observe_name="pt";
		BookH_single_observable(result, plots->fCJetPT, para.signal.NUM_cjet, signal_name, class_name, observe_name, 50, 0.0, 100.0);

		observe_name="y";
		BookH_single_observable(result, plots->fCJetY , para.signal.NUM_cjet, signal_name, class_name, observe_name, 60, -3.0, 3.0);

		if (para.signal.NUM_cjet>=2){
			BookH_single_same_class(result, plots->fCJetPT, para.signal.NUM_cjet, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fCJetY , para.signal.NUM_cjet, signal_name,class_name,observe_name);
		}
	}
	// book qjet 

	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.bjet.SWITCH){
		class_name="qjet";

		if(para.signal.NUM_qjet!=0){
			BookH_single_number(result,&(plots->fQJetnum),signal_name,class_name);
		}

		observe_name="pt";
		BookH_single_observable(result, plots->fQJetPT, para.signal.NUM_qjet, signal_name, class_name, observe_name, 50, 0.0, 100.0);

		observe_name="y";
		BookH_single_observable(result, plots->fQJetY , para.signal.NUM_qjet, signal_name, class_name, observe_name, 60, -3.0, 3.0);

		if (para.signal.NUM_qjet>=2){
			BookH_single_same_class(result, plots->fQJetPT, para.signal.NUM_qjet, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fQJetY , para.signal.NUM_qjet, signal_name,class_name,observe_name);
		}

	}

	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.taujet.SWITCH){
		class_name="taujet";

		if(para.signal.NUM_taujet!=0){
			BookH_single_number(result,&(plots->fTauJetnum),signal_name,class_name);
		}

		observe_name="pt";

		BookH_single_observable(result, plots->fTauJetPT, para.signal.NUM_taujet, signal_name, class_name, observe_name, 50, 0.0, 100.0);

		observe_name="y";
		BookH_single_observable(result, plots->fTauJetY , para.signal.NUM_taujet, signal_name, class_name, observe_name, 60, -3.0, 3.0);

		if (para.signal.NUM_taujet>=2){
			BookH_single_same_class(result, plots->fTauJetPT, para.signal.NUM_taujet, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fTauJetY , para.signal.NUM_taujet, signal_name,class_name,observe_name);
		}
	}

	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.untagjet.SWITCH){
		class_name="untagjet";

		if(para.signal.NUM_untagjet!=0){
			BookH_single_number(result,&(plots->fUJetnum),signal_name,class_name);
		}

		observe_name="pt";

		BookH_single_observable(result, plots->fUJetPT, para.signal.NUM_untagjet, signal_name, class_name, observe_name, 50, 0.0, 100.0);

		observe_name="y";
		BookH_single_observable(result, plots->fUJetY , para.signal.NUM_untagjet, signal_name, class_name, observe_name, 60, -3.0, 3.0);

		if (para.signal.NUM_untagjet>=2){
			BookH_single_same_class(result, plots->fUJetPT, para.signal.NUM_untagjet, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fUJetY , para.signal.NUM_untagjet, signal_name,class_name,observe_name);
		}

	}
	// book lepton 

	if(para.lep.SWITCH && !para.lep.elec.SWITCH && !para.lep.muon.SWITCH){
		class_name="lep";

		if(para.signal.NUM_lep!=0){
			BookH_single_number(result,&(plots->fLepnum),signal_name,class_name);
		}

		observe_name="pt";

		BookH_single_observable(result, plots->fLepPT, para.signal.NUM_lep, signal_name, class_name, observe_name, 50, 0.0, 800.0);

		observe_name="y";
		BookH_single_observable(result, plots->fLepY, para.signal.NUM_lep, signal_name, class_name, observe_name, 60, -3.0, 3.0);
		if (para.signal.NUM_lep>=2){
			BookH_single_same_class(result, plots->fLepPT, para.signal.NUM_lep, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fLepY, para.signal.NUM_lep, signal_name,class_name,observe_name);
		}

	}


	// book electron 

	if(para.lep.SWITCH && para.lep.elec.SWITCH){
		class_name="elec";

		if(para.signal.NUM_elec!=0){
			BookH_single_number(result,&(plots->fElecnum),signal_name,class_name);
		}

		observe_name="pt";

		BookH_single_observable(result, plots->fElectronPT, para.signal.NUM_elec, signal_name, class_name, observe_name, 50, 0.0, 800.0);

		observe_name="y";
		BookH_single_observable(result, plots->fElectronY, para.signal.NUM_elec, signal_name, class_name, observe_name, 60, -3.0, 3.0);
		if (para.signal.NUM_elec>=2){
			BookH_single_same_class(result, plots->fElectronPT, para.signal.NUM_elec, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fElectronY, para.signal.NUM_elec, signal_name,class_name,observe_name);
		}
	}

	// book muon 

	if(para.lep.SWITCH && para.lep.muon.SWITCH){
		class_name="muon";

		if(para.signal.NUM_muon!=0){
			BookH_single_number(result,&(plots->fMuonnum),signal_name,class_name);
		}

		observe_name="pt";

		BookH_single_observable(result, plots->fMuonPT, para.signal.NUM_muon, signal_name, class_name, observe_name, 50, 0.0, 700.0);

		observe_name="y";
		BookH_single_observable(result, plots->fMuonY, para.signal.NUM_muon, signal_name, class_name, observe_name, 60, -3.0, 3.0);
		if (para.signal.NUM_muon>=2){
			BookH_single_same_class(result, plots->fMuonPT, para.signal.NUM_muon, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fMuonY, para.signal.NUM_muon, signal_name,class_name,observe_name);
		}
	}

	// book tau 

	if(para.lep.SWITCH && para.lep.tau.SWITCH){
		class_name="tau";

		if(para.signal.NUM_tau!=0){
			BookH_single_number(result,&(plots->fTaunum),signal_name,class_name);
		}

		observe_name="pt";

		BookH_single_observable(result, plots->fTauPT, para.signal.NUM_tau, signal_name, class_name, observe_name, 50, 0.0, 700.0);

		observe_name="y";
		BookH_single_observable(result, plots->fMuonY, para.signal.NUM_tau, signal_name, class_name, observe_name, 60, -3.0, 3.0);
		if (para.signal.NUM_tau>=2){
			BookH_single_same_class(result, plots->fTauPT, para.signal.NUM_tau, signal_name,class_name,observe_name);

			observe_name="y";
			BookH_single_same_class(result, plots->fMuonY, para.signal.NUM_tau, signal_name,class_name,observe_name);
		}
	}


	// book MET 
	if(para.met.SWITCH){
		class_name="met";
		observe_name="et";
		BookH_single_observable(result, &(plots->fMissingET), -1, signal_name, class_name, observe_name, 100, 0.0, 100.0);
	}

	if(para.comb.SWITCH){
		class_name="combined";
		observe_name="mA";
		BookH_single_observable(result, &(plots->fcomb1M), -1, signal_name, class_name, observe_name, 150, 0.0, 150.0);

		class_name="combined";
		observe_name="mW";
		BookH_single_observable(result, &(plots->fcomb2M), -1, signal_name, class_name, observe_name, 100, 50.0, 150.0);

		class_name="combined";
		observe_name="mH+-";
		BookH_single_observable(result, &(plots->fcomb3M), -1, signal_name, class_name, observe_name, 400, 100.0, 500.0);

		class_name="combined";
		observe_name="mt";
		BookH_single_observable(result, &(plots->fcomb4M), -1, signal_name, class_name, observe_name, 100, 130.0, 2300.0);

		class_name="combined";
		observe_name="pt_tj";
		BookH_single_observable(result, &(plots->fcomb5M), -1, signal_name, class_name, observe_name, 100, 0.0, 500.0);

		class_name="combined";
		observe_name="theta_tj";
		BookH_single_observable(result, &(plots->fcomb6M), -1, signal_name, class_name, observe_name, 100, -1.0, 1.0);

	}

	if(para.recoil.SWITCH){
		class_name="recoil";
		observe_name="mass";
		BookH_single_observable(result, &(plots->frecoilmass), -1, signal_name, class_name, observe_name, 50, 110.0, 200.0);
	}

	if(para.recoil.comb_SWITCH){
		class_name="combined";
		observe_name="mh";
		BookH_single_observable(result, &(plots->fcomb1M), -1, signal_name, class_name, observe_name, 50, 0.0, 100.0);

		class_name="combined";
		observe_name="mz";
		BookH_single_observable(result, &(plots->fcomb2M), -1, signal_name, class_name, observe_name, 50, 100.0, 200.0);

		class_name="recoil";
		observe_name="mass";
		BookH_single_observable(result, &(plots->frecoilmass), -1, signal_name, class_name, observe_name, 50, 110.0, 200.0);
	}

	if(para.jep.SWITCH){
		class_name="JEP";
		observe_name="r";
		BookH_single_observable(result, &(plots->fJEPr) , -1, signal_name, class_name, observe_name, 10, 0.0, 1.0);

		observe_name="r2";
		BookH_single_observable(result, &(plots->fJEPr2), -1, signal_name, class_name, observe_name, 10, 0.0, 1.0);

		class_name="JEP";
		observe_name="R";
		BookH_single_observable(result, &(plots->fJEPR) , -1, signal_name, class_name, observe_name, 10, 0.0, 1.0);

		observe_name="R2";
		BookH_single_observable(result, &(plots->fJEPR2), -1, signal_name, class_name, observe_name, 10, 0.0, 1.0);
		////	plots->fJEPr= result->AddHist1D(
		////			"./plot/JEPr", "JEPr(r)",
		////			"r", "JEPr(r)",
		////			10, -100.0, 100.0,
		////			10, -100.0, 100.0);
		////	
		////	plots->fJEPR= result->AddHist1D(
		////			"./plot/JEPR", "JEPR(r)",
		////			"r", "JEPR(r)",
		////			10, -100.0, 100.0,
		////			10, -100.0, 100.0);

		////	plots->fJEPr2= result->AddHist2D(
		////			"./plot/JEPr2", "JEPr(r)",
		////			"r", "JEPr(r)",
		////			10, -100.0, 100.0,
		////			10, -100.0, 100.0);
		////	
		////	plots->fJEPR2= result->AddHist2D(
		////			"./plot/JEPR2", "JEPR(r)",
		////			"r", "JEPR(r)",
		////			10, -100.0, 100.0,
		////			10, -100.0, 100.0);
	}

	if(para.MassDrop.SWITCH){
		class_name="MassDrop";
		observe_name="mbb";
		para.debug.Message(3,61,"set book for",class_name,observe_name);
		//BookH_single_observable(result, &(para.MassDrop.fmbb) , -1, signal_name, class_name, observe_name, 50, 0.0, 500.0);
		BookH_single_observable(result, &(plots->fmassdrop) , -1, signal_name, class_name, observe_name, 50, 0.0, 500.0);
	}
}
