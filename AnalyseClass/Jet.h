#pragma once
#ifndef AJET_H
#define AJET_H  
#include "Particle.h"
#include "TSystem.h"
#include "Class/debug.h"
#include "Class/Jet.h"
#include "Analyse/ABTag.h"
#include "Class/DrawClass.h"
#include "Analyse/Ajet_function.h"
#include "Analyse/Ajep.h"
#include "AnalyseClass/Pool.h"
#include "fastjet/PseudoJet.hh"




class AJet{
	private:
		AParticleType                   _constituents    ;
		int                             _num_consituents ;


		PseudoJetVec                    _fp_constituents ;
		PseudoJetVec                    _bquark          ;
		PseudoJetVec                    _cquark          ;

		FlavourRecombiner               _flav_recombiner ;
		fastjet::JetDefinition          _jet_def         ;
		fastjet::ClusterSequence        _cs              ;

		int                             _num_jets        ;
		int                             _num_tjet        ;
		int                             _num_bjet        ;
		int                             _num_cjet        ;
		int                             _num_qjet        ;
		int                             _num_tau         ;
		int                             _num_gluon       ;

	    PseudoJetVec                    _jet_vec         ;
	    AParticleType                   _jets            ;

	    AParticleType                   _tjet            ;
	    AParticleType                   _bjet            ;
	    AParticleType                   _cjet            ;
	    AParticleType                   _qjet            ;
	    AParticleType                   _taujet          ;
	    AParticleType                   _gluonjet        ;


		AJudge                          _Has_Jet          ;

		APool                           _jets_pool       ;
		APool                           _tjet_pool       ;
		APool                           _bjet_pool       ;
		APool                           _cjet_pool       ;
		APool                           _qjet_pool       ;
		APool                           _tau_pool     ;
		APool                           _gluon_pool      ;

/*****************************************************************************************
 * private function
 **********************************************************************i******************/

		void                            Find_Jet_Species(CDraw &para) ;

	public:


		AJet();

		~AJet();

		void Clear();

		void Init();

		void Clear_Ptr();




/*****************************************************************************************
 * output function
 **********************************************************************i******************/
		int Num_Jets();

		int Num_TJet();

		int Num_BJet();

		int Num_CJet();

		int Num_QJet();

		int Num_Tau();

		int Num_Gluon();

	    PseudoJetVec   Jet_Vec();

		AParticleType  Jets();

		AParticleType  Tjet();

		AParticleType  Bjet();

		AParticleType  Cjet();

		AParticleType  Qjet();

		AParticleType  Taujet();

		AParticleType  Gluonjet();

		APool Jets_Pool();

		APool TJet_Pool();

		APool BJet_Pool();

		APool CJet_Pool();

		APool QJet_Pool();

		APool Tau_Pool();

		APool Gluon_Pool();

		bool Has_Jet();

		void Set_Has_Jet();

		void Clear_Has_Jet();



/*****************************************************************************************
 *  character   
 **********************************************************************i******************/

		std::vector<float>       Px();
		std::vector<float>       Py();
		std::vector<float>       Pz();
		std::vector<float>       E();
		std::vector<float>       Pt();
		std::vector<float>       Mass();
		std::vector<float>       CosTheta();
		std::vector<float>       Rap();
		std::vector<float>       PID();


/*****************************************************************************************
 * normal function 
 **********************************************************************i******************/

		void Init_Jet_Constituents(AParticleType &in, AParticleType &_input_bquark, AParticleType &_input_cquark);

		void Set_Jet(CDraw &para,  AParticleType &in, AParticleType &_input_bquark, AParticleType &_input_cquark);

		bool Cut(AParticle* par, CJet_cut &cut);

//		bool Cut(fastjet::PseudoJet* par, CJet_cut &cut);

		void Set_Jets_Pool   (AParticleType &in_events,  CJet_cut &para_jet);

	    void Find_All_Best_Jet(CCombine &para_comb);

		bool Set_Cut(AParticle* par, CLepton_cut &lep_cut);
};


/*****************************************************************************************
 *  print 
 **********************************************************************i******************/
std::ostream & operator<<(std::ostream & ostr, AJet& jet);
std::ostream & operator<<(std::ostream & ostr, AJet* jet);


#endif
