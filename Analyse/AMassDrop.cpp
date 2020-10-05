#include "AMassDrop.h"

bool  AMassDrop(CDraw &para, MyPlots *plots, fastjet::ClusterSequence &cs, fastjet::PseudoJet subjet, std::vector<fastjet::PseudoJet> Vbquark,std::vector<fastjet::PseudoJet> Vcquark,  fastjet::PseudoJet &tagjet){

	para.debug.Message(6,7,"input subjet piece size",subjet.constituents().size());
	//para.debug.Message(5,8,"input subjet ",subjet);
	MassDropTagger mdtagger(para.MassDrop.CUT_mu,para.MassDrop.CUT_y);

	PseudoJet tagged_jet = mdtagger(subjet);

	if(tagged_jet == 0){
		para.debug.Message(3,7,"tagsize = 0");return(false);
	}
	std::vector<PseudoJet> tagged_pieces = tagged_jet.pieces();

	para.debug.Message(6,7,"tagged piece size 0",tagged_pieces[0].constituents().size());
	para.debug.Message(6,7,"tagged piece size 1",tagged_pieces[1].constituents().size());

	para.debug.Message(6,7,"tagged piece 0",tagged_pieces[0]);
	para.debug.Message(6,7,"tagged piece 1",tagged_pieces[1]);
	para.debug.Message(6,7,"tagged total ",tagged_jet);

	float Rbb = 0.5*tagged_pieces[0].delta_R(tagged_pieces[1]);
	float Rfilt = std::min(para.MassDrop.Rmin, Rbb);
	FlavourRecombiner flav_recombiner;

	//Filter filter(JetDefinition(para.jetsub.jet_alg,Rfilt, &flav_recombiner), SelectorNHardest(para.MassDrop.nfilt));
	Filter filter(JetDefinition(para.jetsub.jet_alg,Rfilt), SelectorNHardest(para.MassDrop.nfilt));

	PseudoJet filtered_tagged_jet = filter(tagged_jet);

	if(filtered_tagged_jet == 0){
		para.debug.Message(3,7,"filter size=0");return(false);
	}

	para.debug.Message(6,7,"filtered_tagged_jet constituents size",filtered_tagged_jet.constituents().size());
	para.debug.Message(6,7,"filtered_tagged_jet ",filtered_tagged_jet);

	//set higgs from b quark tagging 
	std::vector<fastjet::PseudoJet> filter_jets_piece=filtered_tagged_jet.pieces();
    if(std::abs(filter_jets_piece[0].eta())>2.5||filter_jets_piece[0].perp()<20.0){
        para.debug.Message(3,7,"Tagged jet  piece 1 doesn't pass basic cut",filter_jets_piece[0]);
    	return(false);
    }
	
    if(std::abs(filter_jets_piece[1].eta())>2.5||filter_jets_piece[1].perp()<20.0){
        para.debug.Message(3,7,"Tagged jet  piece 2 doesn't pass basic cut",filter_jets_piece[1]);
    	return(false);
    }
    bool JH1=ATagBJet(para,Vbquark,Vcquark,filter_jets_piece[0]);
    bool JH2=ATagBJet(para,Vbquark,Vcquark,filter_jets_piece[1]);
    if(!JH1||!JH2){
        para.debug.Message(3,7,"Tagged jet  piece is not bquark, JH1",JH1);
        para.debug.Message(3,7,"Tagged jet  piece is not bquark, JH2",JH2);
    	return(false);
    }

////// this is Higgs jet
      tagjet = filtered_tagged_jet;

//////set higgs mass cut
    float mass = tagjet.m();
    para.debug.Message(6,7,"get a proper higgs mass",mass);
    if(mass<para.MassDrop.CUT_massd[0] || mass>para.MassDrop.CUT_massu[0]){
    	para.debug.Message(3,7,"tagged jet mass is not in the Higgs mass window",mass);
		return(false);
    }



	para.debug.Message(2,7,"final higgs jet constituents size",tagjet.constituents().size());
	para.debug.Message(2,7,"final higgs jet",tagjet);
	return(true);
}



