#pragma once
#ifndef ACOBJECT_H
#define ACOBJECT_H
#include "TStyle.h"
#include "TClonesArray.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "fastjet/PseudoJet.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/tools/MassDropTagger.hh"
#include "fastjet/tools/Filter.hh"

#include "classes/DelphesClasses.h"

#include "Lib/MessageFormat.h"
#include "Lib/libstructure.h"
#include "Function/Fbasic.h"
#include "Function/Fdelphes.h"
#include "RWpara/RWbasic.h"
#include "Class/file.h"
#include "Class/DrawClass.h"
#include "Class/Event.h"

#include "Particle.h"
#include "ParticleFunction.h"
#include "Stdhep.h"
#include "Slcio.h"
#include "Delphes.h"
#include "AnalyseClass.h"
#include "Lepton.h"
#include "Jet.h"
#include "Pool.h"
#include "Species.h"
#include "Information.h"


class AObject{
	private:
	public:
		std::vector<Jet*>                Vneutralhad;
		std::vector<Jet*>                Vjet;
		std::vector<fastjet::PseudoJet>  VPseudoJet;
		std::vector<fastjet::PseudoJet>  Vbquark,Vcquark;
		std::vector<Jet*>                Vbjet,Vcjet,Vqjet,Vtaujet, Vtagjet,Vuntagjet;
		std::vector<fastjet::PseudoJet>  VPseudoElec;
		std::vector<fastjet::PseudoJet>  VPseudoMuon;
		std::vector<fastjet::PseudoJet>  VPseudoMet;
		std::vector<fastjet::PseudoJet>  VPseudoPhoton;
		std::vector<Electron*>           Velec;
		std::vector<Muon*>               Vmuon;
		std::vector<Jet*>                Vtau;
		std::vector<Photon*>             Vphoton;
		std::vector<MissingET*>          Vmet;

		std::vector<TLorentzVector>      Vcombine1,Vcombine2,Vcombine3,Vcombine4, Vcombine5, Vcombine6;
		TLorentzVector                   Vre_met;
		std::vector<Jet*>                Vcombine_jet1   ,Vcombine_jet2   ;
		std::vector<Electron*>           Vcombine_elec1  ,Vcombine_elec2  ;
		std::vector<Muon*>               Vcombine_muon1  ,Vcombine_muon2  ;
		std::vector<Photon*>             Vcombine_photon1,Vcombine_photon2;







		/**********************************************************************
		 * @name variable from reading the file 
		**********************************************************************/


		std::vector<AParticle>           OMCParticle_ori;
		AParticleType                    OMCParticle;
		bool                             IsReadMCPar;

		std::vector<AParticle>           OMCbquark_ori;
		AParticleType                    OMCbquark;

		std::vector<AParticle>           OMCcquark_ori;
		AParticleType                    OMCcquark;

		ASpecies                         OMCSpecies;

		AParticleType                    OMCWOIsoLep;

		AParticleType                    OMCWOBestLep;
		AParticleType                    OMCCombinedPhoton;

		/**********************************************************************
		 * @name variable new generated 
		**********************************************************************/

		AParticleType                    OMCVisible_Vec;
		AParticle                        OMCVisible_ori;
		AParticle*                       OMCVisible;

		AParticle                        OMCInvisible_ori;
		AParticle*                       OMCInvisible;

		AParticleType                    OMCVisibleWOBestElec_Vec;
		AParticle                        OMCVisibleWOBestElec_ori;
		AParticle*                       OMCVisibleWOBestElec;

		AParticleType                    OMCVisibleWOBestMuon_Vec;
		AParticle                        OMCVisibleWOBestMuon_ori;
		AParticle*                       OMCVisibleWOBestMuon;

		AParticleType                    OMCVisibleWOBestLep_Vec;
		AParticle                        OMCVisibleWOBestLep_ori;
		AParticle*                       OMCVisibleWOBestLep;

		/**********************************************************************
		 * @name variable mixed   
		**********************************************************************/

		ALepton                          OMCLep;

		AJet                             OMCJet;

		Infomation                       info;





		//Method
		/**********************************************************************
		 * @name  Reading data 
		**********************************************************************/
		/**********************************************************************
		 * @Name: Read_SLCIO_MCParticle 
		 *
		 * @Param: para
		 * @Param: var
		 **********************************************************************/
		void Read_SLCIO_MCParticle(CDraw &para, ASlcio &var);

		/**********************************************************************
		 * @Name: Read_SLCIO_ReconstructedParticle 
		 *
		 * @Param: para
		 * @Param: var
		 **********************************************************************/
		void Read_SLCIO_ReconstructedParticle(CDraw &para, ASlcio &var);

		/**********************************************************************
		 * @Name: Read_STDHep_Particle 
		 *
		 * @Param: para
		 * @Param: var
		 **********************************************************************/
		void Read_STDHep_Particle(CDraw &para, AStdhep &var);

		/**********************************************************************
		 * @Name: Read_Delphes_MCParticle 
		 *
		 * @Param: para
		 * @Param: var
		 **********************************************************************/
		void Read_Delphes_MCParticle(CDraw &para, ADelphes &var);

		/**********************************************************************
		 * @Name: Read_Delphes_ReconstructedParticle 
		 *
		 * @Param: para
		 * @Param: var
		 **********************************************************************/
		void Read_Delphes_ReconstructedParticle(CDraw &para, ADelphes &var);

		/**********************************************************************
		 * @Name: Read_Delphes_AnalysedParticle 
		 *
		 * @Param: para
		 * @Param: var
		 **********************************************************************/
		void Read_Delphes_AnalysedParticle(CDraw &para, ADelphes &var);

		/**********************************************************************
		 * @name initialization 
		**********************************************************************/
		/**********************************************************************
		 * @Name: Clear 
		 **********************************************************************/
		void Clear();

		/**********************************************************************
		 * @Name: Init 
		 *
		 * @Param: analysis
		 * @Param: para
		 **********************************************************************/
		void Init(AnalyseClass &analysis, CDraw &para);

		/**********************************************************************
		 * @Name: AObject 
		 *
		 * @Param: analysis
		 * @Param: para
		 **********************************************************************/
		AObject(AnalyseClass &analysis, CDraw &para){
			Init(analysis,para);
		}

		/**********************************************************************
		 * @Name: ~AObject 
		 **********************************************************************/
		~AObject(){
			Clear();
		}

		/**********************************************************************
		 * @Name: Read_Object 
		 *
		 * @Param: path
		 **********************************************************************/
		void Read_Object(CPath &path);




		/*****************************************************************************************
		 * @Name: setParticleSpecies 
		 *
		 * @Param: para
		 **********************************************************************i******************/
		void setParticleSpecies(CDraw &para);

		/**********************************************************************
		 * @Name: getVisible 
		 *
		 * @Param: para
		 **********************************************************************/
	    void getVisible(CDraw &para);

		/**********************************************************************
		 * @Name: getInVisible 
		 *
		 * @Param: para
		 **********************************************************************/
	    void getInVisible(CDraw &para);

		/**********************************************************************
		 * @Name: getVisibleWOBestLep 
		 *
		 * @Param: para
		 **********************************************************************/
	    void getVisibleWOBestLep(CDraw &para);

		/**********************************************************************
		 * @name  functions for leptons
		**********************************************************************/



		/**********************************************************************
		 * @Name: setAllLepPool 
		 *
		 * @Returns: 
		 **********************************************************************/
		void setAllLepPool(CDraw &para);
		/**********************************************************************
		 * @Name: findBestLep 
		 *
		 * @Param: para
		 **********************************************************************/
		void findBestLep(CDraw &para);


		void setJet(CDraw & para);

		bool Fill(CDraw &para, AnalyseClass &analyse);


		bool  Fill_Jet(CDraw &para, AnalyseClass &analyse);
		bool  Fill_Lepton(CDraw &para, AnalyseClass &analyse);

};



#endif
