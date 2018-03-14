#ifndef GLOBAL_PARA_JETSUBSTRUCTURE
#define GLOBAL_PARA_JETSUBSTRUCTURE
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "fastjet/PseudoJet.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/tools/MassDropTagger.hh"
#include "fastjet/tools/Filter.hh"

#include "Lib/MessageFormat.h" 
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/file.h"

class PseudoJetInfo: public fastjet::PseudoJet::UserInfoBase
{
	public:

		PseudoJetInfo( int PID_, int Charge_, int Status_, int IsPU_, float Mass_ )
			: PID(PID_), Charge(Charge_), Status(Status_), IsPU(IsPU_), Mass(Mass_) 
		{}

		int PID;
		int Charge;
		int Status;
		int IsPU;
		float Mass;

};//end class PseudoJetInfo


typedef fastjet::JetDefinition::DefaultRecombiner DefRecomb;
class FlavourRecombiner : public  DefRecomb {
	public:
		FlavourRecombiner(fastjet::RecombinationScheme recomb_scheme =fastjet::E_scheme) : 
			DefRecomb(recomb_scheme) {};

		virtual std::string description() const {
			return DefRecomb::description()+" (with user index addition)";
		}


		/// recombine pa and pb and put result into pab
		virtual void recombine(const fastjet::PseudoJet & pa, const fastjet::PseudoJet & pb, 
				fastjet::PseudoJet & pab) const {
			DefRecomb::recombine(pa,pb,pab);
			// Note: see the above discussion for the fact that we consider
			// negative user indices as "0"
			pab.set_user_index(std::max(pa.user_index(),0) + std::max(pb.user_index(),0));
			//  		pab.set_user_info(combine_user_info(pa.user_info(),pb.user_info());
		}

		////PseudoJetInfo combine_user_info(fastjet::PseudoJet & pa, fastjet::PseudoJet & pb){
		////	new PseudoJetInfo newinfo(0,0,0,0,(pa+pb).m());
		////	return(newinfo);
		////}
};

class CJetSubStructure : public FlavourRecombiner{
	private:
	public:
		bool    SWITCH     ;
		bool    PLOT       ;
		bool    JCUT       ;
		float  coneR      ;
		std::string   jet_alg_name;
		fastjet::JetAlgorithm jet_alg;

		void Read_JetSubStructure(CPath path)                    ;
		void Get_Jet_Alg(){
			if     (jet_alg_name =="C/A")           {jet_alg = fastjet::cambridge_algorithm;}
			else if(jet_alg_name =="kt")            {jet_alg = fastjet::kt_algorithm;}
			else if(jet_alg_name =="antikt")        {jet_alg = fastjet::antikt_algorithm;}
			else if(jet_alg_name =="genkt")         {jet_alg = fastjet::genkt_algorithm;}
			else if(jet_alg_name =="C/A_passive")   {jet_alg = fastjet::cambridge_for_passive_algorithm;}
			else if(jet_alg_name =="genkt_passive") {jet_alg = fastjet::genkt_for_passive_algorithm;}
			else if(jet_alg_name =="eekt")          {jet_alg = fastjet::ee_kt_algorithm;}
			else if(jet_alg_name =="eegenkt")       {jet_alg = fastjet::ee_genkt_algorithm;}
			else if(jet_alg_name =="plugin")        {jet_alg = fastjet::plugin_algorithm;}
			else if(jet_alg_name =="undefined")     {jet_alg = fastjet::undefined_jet_algorithm;}
			else{ShowMessage(3,"wrong input for jet algorithm");}
		}
};

#endif
