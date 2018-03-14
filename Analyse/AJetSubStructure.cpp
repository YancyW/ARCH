#include "AJetSubStructure.h"


bool AJetSubStructure(CDraw &para, MyPlots *plots,std::vector<Jet*> Vjet,
		std::vector<fastjet::PseudoJet> VPseudoJet, std::vector<fastjet::PseudoJet> Vbquark, std::vector<fastjet::PseudoJet> Vcquark, 
		std::vector<Jet*> Vbjet, std::vector<Jet*> Vcjet, std::vector<Jet*> Vqjet,std::vector<Electron*> Velec,std::vector<Muon*> Vmuon,
		std::vector<Jet*> &Vcombined_jet1, std::vector<Jet*> &Vcombined_jet2, std::vector<Electron*> &Vcombined_elec1, std::vector<Electron*> &Vcombined_elec2, 
		std::vector<Muon*> &Vcombined_muon1, std::vector<Muon*> &Vcombined_muon2,
		float *Phi_r, float *Phi_r_test, int nr,AnalyseClass& analyse){

	bool JHiggsTag, Jjep;
	Jet* jet_findsub;

	bool Jjetsub1=AJetSubStructure_SingleJet(para,plots, VPseudoJet, Vbquark, Vcquark, Phi_r,Phi_r_test,nr,analyse);
	if(Jjetsub1 ){
		//pass_jetsub++;
		analyse.counter.getCounter("JSS");
		return(true);}
	else{return(false);}

}


bool AJetSubStructure_SingleJet(CDraw &para, MyPlots *plots,std::vector<fastjet::PseudoJet> VPseudoJet,std::vector<fastjet::PseudoJet> Vbquark,std::vector<fastjet::PseudoJet> Vcquark,
		float *Phi_r, float *Phi_r_test, int nr,AnalyseClass& analyse){

	bool JHiggsTag, Jjep;


	//std::vector<fastjet::PseudoJet> jet_constituents  = make_PseudoJet_constituents(jet_findsub);
	std::vector<fastjet::PseudoJet> jet_constituents  = VPseudoJet;

	para.debug.Message(6,5,"begin SubStructure_SingleJet: input constructor",jet_constituents);
	para.debug.Message(6,5,"begin SubStructure_SingleJet: input constructor",jet_constituents.size());

	FlavourRecombiner flav_recombiner;

	para.debug.Message(6,5,"jet coneR",para.jetsub.coneR);
	para.debug.Message(6,5,"jet algorithms",para.jetsub.jet_alg);
	fastjet::JetDefinition jet_def(para.jetsub.jet_alg, para.jetsub.coneR);
	para.debug.Message(6,5,"complete jet def");
	fastjet::ClusterSequence cs( jet_constituents, jet_def );
	para.debug.Message(6,5,"complete cluster");

	std::vector<fastjet::PseudoJet> subjets= fastjet::sorted_by_pt(cs.inclusive_jets(20.0));
	para.debug.Message(3,5,"complete sort by pt");
	if( subjets.size() == 0 ) {
		para.debug.Message(3,5,"the subjets size is 0");
		return(false);
	}
	if(subjets[0].perp()<200.0){
		para.debug.Message(3,5,"the subjet 1 pt < 200.0");
		return(false);
	}

	para.debug.Message(6,5,"re cluster jet",subjets);

	for(int i=0;i<subjets.size();i++){
		para.debug.Message(6,5,"subjet pieces",subjets[i].constituents());
	}

	// Tag Higgs
	fastjet::PseudoJet HiggsJet(0,0,0,0);

	if(para.BoostTag.SWITCH){
		para.debug.Message(3,5,"beginHiggsTag");

		JHiggsTag = AHiggsTag(para,plots, cs, subjets, Vbquark, Vcquark, HiggsJet,analyse);
		if(!JHiggsTag) { return(false); }
		else{
			analyse.counter.getCounter("JSS_BoostTag");
			//	pass_boosttag++;
		}
	}
	else{
		JHiggsTag=true;
		HiggsJet =subjets[0];
	}

	if(para.jep.SWITCH){
////	para.debug.Message(3,5,"begin JEP");
////	fastjet::JetDefinition jet_def(fastjet::cambridge_algorithm, para.jetsub.coneR);
////	fastjet::ClusterSequence cs( HiggsJet.constituents(), jet_def );

////	std::vector<fastjet::PseudoJet> subjets_jep= fastjet::sorted_by_pt(cs.inclusive_jets());
////	if( subjets_jep.size() == 0 ) {
////		para.debug.Message(3,5,"the subjets size is 0");
////		return(false);
////	}
		para.debug.Message(3,5,"in JetSubstructure: begin jep ");
		para.debug.Message(3,5,"the higgs jet constituents",HiggsJet.constituents());

		Jjep=JEP(para,plots->fJEPr ,plots->fJEPR , HiggsJet.constituents(), HiggsJet.constituents()[0],Phi_r , Phi_r_test,  para.jetsub.coneR,nr);
		if(!Jjep){return(false);}
		else{
			//	pass_jep++; 
			analyse.counter.getCounter("JES_JEP");
		}
	}
	else{Jjep=true;}

	return(true);
}
