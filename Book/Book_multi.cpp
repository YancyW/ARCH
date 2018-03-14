#include "Book_multi.h"
void BookHistograms_multi(CDraw &para, ExRootResult *result, MyPlots *plots, int num, std::vector<std::string> sampledescrip)
{
	THStack *stack;
	TLegend *legend;

	std::string filter_name=para.path.combine_plot;
	std::string class_name,observe_name;
	// book normal jets

	int plot_num = num;

	if(para.jet.SWITCH && para.jet.jets.SWITCH){
		class_name = "jet";

		para.debug.Message(1,1,"book multi jet num");
		if(para.signal.NUM_jets!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}

		para.debug.Message(1,1,"book multi jet pt");
		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name,para.signal.NUM_jets, sampledescrip);

		para.debug.Message(1,1,"book multi jet y");
		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name,para.signal.NUM_jets, sampledescrip);
	}


	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.bjet.SWITCH){
		class_name = "bjet";

		if(para.signal.NUM_bjet!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}

		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_bjet, sampledescrip);

		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_bjet, sampledescrip);
	}

	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.cjet.SWITCH){
		class_name = "cjet";

		if(para.signal.NUM_cjet!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}

		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_cjet, sampledescrip);

		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_cjet, sampledescrip);
	}

	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.qjet.SWITCH){
		class_name = "qjet";

		if(para.signal.NUM_qjet!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}


		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_qjet,sampledescrip);

		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_qjet, sampledescrip);
	}

	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.taujet.SWITCH){
		class_name = "taujet";

		if(para.signal.NUM_taujet!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}


		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_taujet,sampledescrip);

		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_taujet,sampledescrip);
	}

	if(para.jet.SWITCH && para.jet.jets.SWITCH && para.jet.untagjet.SWITCH){
		class_name = "untagjet";

		if(para.signal.NUM_untagjet!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}


		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_untagjet,sampledescrip);

		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_untagjet, sampledescrip);
	}

	if(para.lep.SWITCH && !para.lep.elec.SWITCH && !para.lep.muon.SWITCH){
		class_name = "lep";

		if(para.signal.NUM_lep!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}

		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_lep,sampledescrip);

		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name,para.signal.NUM_lep, sampledescrip);

	}

	if(para.lep.SWITCH && para.lep.elec.SWITCH){
		class_name = "elec";

		if(para.signal.NUM_elec!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}

		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_elec,sampledescrip);

		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name,para.signal.NUM_elec, sampledescrip);
	}

	if(para.lep.SWITCH && para.lep.muon.SWITCH){
		class_name = "muon";

		if(para.signal.NUM_muon!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}

		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_muon,sampledescrip);

		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name,para.signal.NUM_muon, sampledescrip);
	}

	if(para.lep.SWITCH && para.lep.tau.SWITCH){
		class_name = "tau";

		if(para.signal.NUM_tau!=0){
			observe_name = "number";
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
		}

		observe_name = "pt";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name, para.signal.NUM_tau,sampledescrip);

		observe_name = "y";
		BookH_multi_observable_loop(para, result,plots,plot_num,filter_name,class_name,observe_name,para.signal.NUM_tau, sampledescrip);
	}

	if(para.met.SWITCH){
		class_name = "met";

		observe_name = "et";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
	}

	if(para.comb.SWITCH){
		class_name = "comb";

		observe_name = "1m";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);

		observe_name = "2m";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);

		observe_name = "3m";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);

		observe_name = "4m";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
	}

	if(para.recoil.SWITCH){
		class_name = "recoil";

		observe_name = "mass";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
	}

	if(para.recoil.comb_SWITCH){
		class_name = "comb";
		observe_name = "1m";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);

		class_name = "comb";
		observe_name = "2m";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);

		class_name = "comb";
		observe_name = "3m";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);

		class_name = "comb";
		observe_name = "4m";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);

		class_name = "recoil";
		observe_name = "mass";
		BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
	}

////if(para.MassDrop.SWITCH){
////	class_name = "MassDrop";

////	observe_name = "mbb";
////	BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, 0,sampledescrip);
////}

}


