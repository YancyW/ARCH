#pragma once
#ifndef GLOBAL_PARA_JET 
#define GLOBAL_PARA_JET
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/kinematic.h"
#include "Class/file.h"
#include "Class/JetSubStructure.h"

class CJet_cut : public CENERGY, public CPT, public CETA, public CTHETA,  public CMASS, public CCONE_JET, public CCONE_LEP{
	private:
	public:
		int         CUT_num       ;
		bool        SWITCH        ;
};

class CJet : public FlavourRecombiner{
	private:
	public:
		bool                    SWITCH         ;
		bool                    PLOT           ;
		float                   coneR          ;
		std::string             jet_alg_name   ;
		std::string             sort_method    ;
		fastjet::JetAlgorithm   jet_alg        ;

		CJet_cut     jets;
		CJet_cut     tjet;
		CJet_cut     bjet;
		CJet_cut     cjet;
		CJet_cut     qjet;
		CJet_cut   taujet;
		CJet_cut gluonjet;
		CJet_cut   tagjet;
		CJet_cut untagjet;

		void Read_Jet(CPath path);
		void Read_Jet_particle(CPath path, std::string particle_name, CJet_cut &jet);

		void Get_Jet_Alg(){
			if     (jet_alg_name =="C/A")           {jet_alg = fastjet::cambridge_algorithm;}
			else if(jet_alg_name =="kt")            {jet_alg = fastjet::kt_algorithm;}
			else if(jet_alg_name =="antikt")        {jet_alg = fastjet::antikt_algorithm;}
			else if(jet_alg_name =="genkt")         {jet_alg = fastjet::genkt_algorithm;}
			else if(jet_alg_name =="C/A_passive")   {jet_alg = fastjet::cambridge_for_passive_algorithm;}
			else if(jet_alg_name =="genkt_passive") {jet_alg = fastjet::genkt_for_passive_algorithm;}
			else if(jet_alg_name =="eekt")          {jet_alg = fastjet::ee_kt_algorithm;}
			else if(jet_alg_name =="eegenkt")       {jet_alg = fastjet::ee_genkt_algorithm;}
			else if(jet_alg_name =="eegenantikt")   {jet_alg = fastjet::ee_genkt_algorithm;}
			else if(jet_alg_name =="plugin")        {jet_alg = fastjet::plugin_algorithm;}
			else if(jet_alg_name =="undefined")     {jet_alg = fastjet::undefined_jet_algorithm;}
			else{ShowMessage(3,"wrong input for jet algorithm");exit(EXIT_FAILURE);}
		}
};


#endif
