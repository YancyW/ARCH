#pragma once
#ifndef APARTICLE_H 
#define APARTICLE_H
#include <vector>
#include <math.h>
#include "TSystem.h"
#include "TLorentzVector.h"
#include "fastjet/PseudoJet.hh"
#include "Lib/MessageFormat.h"
#include "AnalyseClass/Judge.h"
#include "Class/Tag.h"
#include "Analyse/Ajet_function.h"
#include "Analyse/Ajep.h"
#include "Lib/Define.h"


typedef std::vector<fastjet::PseudoJet>                    PseudoJetVec;


class AParticle{

	/*****************************************************************************************
	* @name basic ID  
	******************************************************************************************/

	private:
		int          _ID         ; // unique id for judgement when +-*/
		int          _PID        ; // particle HEP ID number | hepevt.idhep[number]
		static int   _global_id  ; // used for judge whether two particle equal
		static int   _instruct_id; // used for counter how many Aparticle generated; 

	public:

		/*****************************************************************************************
		 * variable output function
		 **********************************************************************i******************/

		int ID();

		int PID();

		static int Get_Global_ID(){
			_global_id++;
			return(_global_id);
		}

		void Get_Instruct_ID(){
			_instruct_id++;
		}

		void Rid_Instruct_ID(){
			_instruct_id--;
		}

		static int Global_ID(){
			return(_global_id);
		}

		static int Instruct_ID(){
			return(_instruct_id);
		}

		/*****************************************************************************************
		 * variable setting function
		 **********************************************************************i******************/

		static void Reset_Global_ID(){
			_global_id=0;
		}

		static void Reset_Instruct_ID(){
			_instruct_id=0;
		}

		void Set_ID(int num);

		void Set_PID(int in);

	/*****************************************************************************************
	* @name normal particle information 
	******************************************************************************************/

	private:

		/*****************************************************************************************
		 * private variable 
		 **********************************************************************i******************/

		TLorentzVector       _P          ;
		TVector3             _V          ;

		float                _Charge     ; // particle charge
		float                _Mass       ; // particle mass

		fastjet::PseudoJet   _fp         ;

		float                _E          ; // particle energy | hepevt.phep[number][3]
		float                _Px         ; // particle momentum vector (x component) | hepevt.phep[number][0]
		float                _Py         ; // particle momentum vector (y component) | hepevt.phep[number][1]
		float                _Pz         ; // particle momentum vector (z component) | hepevt.phep[number][2]

		float                _Mom        ; // particle momentum
		float                _Mom2       ; // particle momentum
		float                _Pt         ; // particle transverse momentum
		float                _Eta        ; // particle pseudorapidity
		float                _Theta      ; // particle cos of theta
		float                _Phi        ; // particle azimuthal angle

		float                _Y          ; // particle rapidity
		float                _CosTheta   ; // particle cos of theta

		int                  _Status     ; // particle status     | hepevt.isthep[number]
		std::vector<int>     _Mother     ; // particle 1st mother | hepevt.jmohep[number][0] - 1
		std::vector<int>     _Daughter   ; // particle 1st mother | hepevt.jmohep[number][0] - 1

		/*****************************************************************************************
		 * judgement parameter
		 **********************************************************************i******************/


		/*****************************************************************************************
		 * private function 
		 **********************************************************************i******************/

		void _Init_Particle();

		void _Init_Reconstruction();

	public:

		/*****************************************************************************************
		 * public function 
		 **********************************************************************i******************/

		AParticle();

		AParticle(float inx,float iny,float inz,float ine, float inCharge=0.0, int inPID=0); 

		AParticle(TLorentzVector Pin, float inCharge=0.0, int inPID=0);

		AParticle(fastjet::PseudoJet Pin, float inCharge=0.0, int inPID=0);

		AParticle(AParticle *Pin);

		~AParticle();

		void Init();

		/*****************************************************************************************
		 * variable output function
		 **********************************************************************i******************/

		float Charge();

		float M();

		TLorentzVector P() ;

		TVector3 V();

		fastjet::PseudoJet FP();

		float E();

		float Px();

		float Py();

		float Pz();

		float Mom();

		float Mom2();

		float Pt();

		float Eta();

		float Y();

		float Theta();

		float Phi();

		float CosTheta();

		int Status();

		std::vector<int> Mother();

		std::vector<int> Daughter();

		/*****************************************************************************************
		 * variable setting function
		 **********************************************************************i******************/

		void Set_Charge(float in);

		void Set_Mass(float in);

		void Set_P(float inx,float iny,float inz,float ine);

		void Set_P(TLorentzVector Pin);

		void Set_P(fastjet::PseudoJet Pin);

		void Set_P();


		void Set_Mother(int inM);

		void Set_Mother(std::vector<int> inM);

		void Set_Daughter(int inD);

		void Set_Daughter(std::vector<int> inD);

		/*****************************************************************************************
		 * judge variable output function
		 **********************************************************************i******************/

		AJudge               _Is_MC_Particle    ;
		AJudge               _Is_Reco_Particle  ;
		AJudge               _Is_Constituent    ;
		AJudge               _Is_PU             ; // F or T for particles from pile-up interactions
		AJudge               _Is_Ready          ; //whether initialized for this particle


		bool Is_Reco_Particle();

		bool Is_Constituent();

		bool Is_PU();

		bool Is_MC_Particle();

		bool Is_Ready();


	/*****************************************************************************************
	* @name reconstructed particle information 
	******************************************************************************************/




		////	//detector simulation parameter
		////	TLorentzVector Position;
		////	TLorentzVector InitialPosition;
		////	float Eem                ; // calorimeter tower electromagnetic energy
		////	float Ehad               ; // calorimeter tower hadronic energy
		////	float Time               ; // particle arrival time of flight
		////	float EhadOverEem        ; // ratio of the hadronic versus electromagnetic energy deposited in the calorimeter
		////	float IsolationVar       ; // isolation variable
		////	float IsolationVarRhoCorr; // isolation variable
		////	float SumPtCharged       ; // isolation variable
		////	float SumPtNeutral       ; // isolation variable
		////	float SumPtChargedPU     ; // isolation variable
		////	float SumPt              ; // isolation variable

		////	int   NTimeHits          ; // number of hits contributing to time measurement

		////	std::vector<float> Edges ; // calorimeter tower edges
		////	float TOuter             ; // track position (t component) at the tracker edge
		////	float XOuter             ; // track position (x component) at the tracker edge
		////	float YOuter             ; // track position (y component) at the tracker edge
		////	float ZOuter             ; // track position (z component) at the tracker edge

		////	float Xd                 ; // X coordinate of point of closest approach to vertex
		////	float Yd                 ; // Y coordinate of point of closest approach to vertex
		////	float Zd                 ; // Z coordinate of point of closest approach to vertex

		////	float L                  ; // track path length

		////	float D0                 ; // particle transverse impact parameter
		////	float DZ                 ; // particle longitudinal impact parameter

		////	float T                  ; // particle vertex position (t component) | hepevt.vhep[number][3]
		////	float X                  ; // particle vertex position (x component) | hepevt.vhep[number][0]
		////	float Y                  ; // particle vertex position (y component) | hepevt.vhep[number][1]
		////	float Z                  ; // particle vertex position (z component) | hepevt.vhep[number][2]
		////	float S                  ; // distance to the interaction point [m]
		////	float Tx                 ; // angle of the momentum in the horizontal (x,z) plane [urad]
		////	float Ty                 ; // angle of the momentum in the verical (y,z) plane [urad]
		////	float CtgTheta           ; // particle cotangent of theta

		////	float ErrorT             ; // path length
		////	float ErrorP             ; // track momentum error
		////	float ErrorPT            ; // track transverse momentum error
		////	float ErrorPhi           ; // track azimuthal angle error
		////	float ErrorCtgTheta      ; // track cotangent of theta error
		////	float ErrorD0            ; // track transverse impact parameter error
		////	float ErrorDZ            ; // track longitudinal impact parameter error


		////	int VertexIndex          ; // reference to vertex

	/*****************************************************************************************
	* @name jet and jet substructure 
	******************************************************************************************/

	private:

		/*****************************************************************************************
		 * private variable 
		 **********************************************************************i******************/

		std::pair<float,std::string>                      _WhatJet    ;
		std::vector<std::pair<float,std::string> >        _JetSort    ; // _JetSort[n].first  is the probability of being that jet 
		int                                               _jet_num    ;

		int                                               _nr         ;
		std::vector<float>                                _pTr        ; 
		std::vector<float>                                _pTr_fit    ; 
		std::vector<float>                                _smallr     ; 
		float                                             _pTR        ;

		/*****************************************************************************************
		 * judgement parameter
		 **********************************************************************i******************/

		AJudge                                            _Is_Jet            ; //whether initialized for this particle
		AJudge                                            _Has_JEP            ;

		////	//clustered particle parameter
		////	float R         ; // jet radius in pseudorapidity
		////	float subR      ; // jet radius in pseudorapidity
		////	float DeltaEta  ; // jet radius in pseudorapidity
		////	float DeltaPhi  ; // jet radius in azimuthal angle

		////	Uint  Flavor    ; // jet flavor
		////	Uint  FlavorAlgo; // jet flavor
		////	Uint  FlavorPhys; // jet flavor

		////	Uint  BTag      ; // 0 or 1 for a jet that has been tagged as containing a heavy quark
		////	Uint  CTag      ; // 0 or 1 for a jet that has been tagged as containing a heavy quark
		////	Uint  TauTag    ; // 0 or 1 for a jet that has been tagged as a tau
		////	Uint  QTagAlgo  ; // 0 or 1 for a jet that has been tagged as containing a heavy quark
		////	Uint  QTagPhys  ; // 0 or 1 for a jet that has been tagged as containing a heavy quark



		////	TLorentzVector Area ;

		////	int   NCharged    ; // number of charged constituents
		////	int   NNeutrals   ; // number of neutral constituents
		////	float Beta        ; // (sum pt of charged pile-up constituents)/(sum pt of charged constituents)
		////	float BetaStar    ; // (sum pt of charged constituents coming from hard interaction)/(sum pt of charged constituents)
		////	float MeanSqDeltaR; // average distance (squared) between constituent and jet weighted by pt (squared) of constituent
		////	float PTD         ; // average pt between constituent and jet weighted by pt of constituent


		////    std::vector<float>        FracPt       ; // (sum pt of constituents within a ring 0.1*i < DeltaR < 0.1*(i+1))/(sum pt of constituents)
		////    std::vector<float>        Tau          ; // N-subjettiness
		////    std::vector<TLorentzVector> TrimmedP4    ; // first entry (i = 0) is the total Trimmed Jet 4-momenta and from i = 1 to 4 are the trimmed subjets 4-momenta
		////    std::vector<TLorentzVector> PrunedP4     ; // first entry (i = 0) is the total Pruned Jet 4-momenta and from i = 1 to 4 are the pruned subjets 4-momenta
		////    std::vector<TLorentzVector> SoftDroppedP4; // first entry (i = 0) is the total SoftDropped Jet 4-momenta and from i = 1 to 4 are the pruned subjets 4-momenta

		////	int NSubJetsTrimmed      ; // number of subjets trimmed
		////	int NSubJetsPruned       ; // number of subjets pruned
		////	int NSubJetsSoftDropped  ; // number of subjets soft-dropped

		////	TRefArray Constituents     ; // references to constituents
		////	TRefArray Particles        ; // references to generated particles
		////	TRef      Particle         ; // reference to generated particle

		/*****************************************************************************************
		 * private function
		 **********************************************************************i******************/
		void _Init_Jet();
		void _Find_What_Jet();


	public:

		/*****************************************************************************************
		 * public function
		 **********************************************************************i******************/

		void Set_Jet(PseudoJetVec &bquark, PseudoJetVec &cquark, float coneR, CTag tag);

		void Get_JEP(int which_jep_fit);

		bool Set_Tag(CTag_Particle &tag, std::vector<fastjet::PseudoJet> bquark, std::vector<fastjet::PseudoJet> cquark);

		/*****************************************************************************************
		 * variable output function
		 **********************************************************************i******************/

		std::vector<float> JEP();

		int JEP_Num();

		std::vector<float> JEP_Fit();

		float Pt_SUM();


		AParticle*         Jet();

		std::string What_Jet_Name();
		float       What_Jet_Type();

		/*****************************************************************************************
		 * judge variable output function
		 **********************************************************************i******************/

		bool Is_Jet();

		bool Has_JEP();


	/*****************************************************************************************
	* @name normal operation 
	******************************************************************************************/
	public:

		inline AParticle& operator += (const AParticle&  P1);
		inline void       AddEqual    (const AParticle*  P1);

		inline AParticle& operator -= (const AParticle&  P1);

		inline AParticle  operator +  (const AParticle&  P1);
		inline AParticle* Add         (const AParticle*  P1);

		inline AParticle  operator -  (const AParticle&  P1);
		inline AParticle* Minus       (const AParticle*  P1);

		inline AParticle  operator =  (const AParticle&  P1);
		inline AParticle  Equal       (const AParticle&  P1);
		inline bool       operator == (const AParticle&  P1);

};



inline AParticle& AParticle::operator += (const AParticle& P1){
	_P+=P1._P;
	Set_P();
	return(*this);
}

inline void       AParticle::AddEqual    (const AParticle* P1){
	_P+=P1->_P;
	Set_P();
}

inline AParticle& AParticle::operator -= (const AParticle& P1){
	_P-=P1._P;
	if(_P[3]<0.0){
		Set_P(0.0,0.0,0.0,0.0);
	}
	else{
		Set_P();
	}
	return(*this);
}


inline AParticle  AParticle::operator + (const AParticle& P1){
	TLorentzVector Vnew=_P+P1._P;
	AParticle Pnew(Vnew);
	return(Pnew);
}

inline AParticle* AParticle::Add(const AParticle* P1){
	TLorentzVector Vnew=P1->_P+_P;
	AParticle*  Pnew= new AParticle(Vnew);
	Get_Instruct_ID();	
	return(Pnew);
}


inline AParticle  AParticle::operator - (const AParticle& P1){
	TLorentzVector Vnew=_P-P1._P;
	AParticle Pnew;
	if(Vnew[3]>=0.0){
		Pnew.Set_P(Vnew);
	}
	else{
		Pnew.Set_P(0.0,0.0,0.0,0.0);
	}
	return(Pnew);
}

inline AParticle* AParticle::Minus(const AParticle* P1){
	TLorentzVector Vnew=_P-P1->_P;
	AParticle*  Pnew= new AParticle(Vnew);
	Get_Instruct_ID();	
	if(Vnew[3]>=0.0){
		Pnew->Set_P(Vnew);
	}
	else{
		Pnew->Set_P(0.0,0.0,0.0,0.0);
	}
	return(Pnew);
}

inline AParticle  AParticle::Equal(const AParticle& P1){
	this->Set_P(P1._P);
	this->Set_PID(P1._PID);
	this->Set_Charge(P1._Charge);
	this->Set_ID(P1._ID);
	this->_fp=P1._fp;
	this->_Status   =P1._Status; // particle status     | hepevt.isthep[number]
	this->_Mother   =P1._Mother; // particle 1st mother | hepevt.jmohep[number][0] - 1
	this->_Daughter =P1._Daughter; // particle 1st mother | hepevt.jmohep[number][0] - 1
	this->_Is_MC_Particle   =P1._Is_MC_Particle;
	this->_Is_Reco_Particle =P1._Is_Reco_Particle;
	this->_Is_Constituent   =P1._Is_Constituent;
	this->_Is_PU            =P1._Is_PU; // F or T for particles from pile-up interactions
	this->_Is_Ready         =P1._Is_Ready; //whether initialized for this particle

	this->_WhatJet          =P1._WhatJet;
	this->_JetSort          =P1._JetSort; // _JetSort[n].first  is the probability of being that jet 
	this->_jet_num          =P1._jet_num;

	this->_nr               =P1._nr;
	this->_pTr              =P1._pTr; 
	this->_pTr_fit          =P1._pTr_fit; 
	this->_smallr           =P1._smallr; 
	this->_pTR              =P1._pTR;
	this->_Is_Jet           =P1._Is_Jet; //whether initialized for this particle
	this->_Has_JEP          =P1._Has_JEP;

	return(*this);
}


inline AParticle  AParticle::operator = (const AParticle& P1){
	this->Set_P(P1._P);
	this->Set_PID(P1._PID);
	this->Set_Charge(P1._Charge);
	this->Set_ID(P1._ID);
	this->_fp=P1._fp;
	this->_Status   =P1._Status; // particle status     | hepevt.isthep[number]
	this->_Mother   =P1._Mother; // particle 1st mother | hepevt.jmohep[number][0] - 1
	this->_Daughter =P1._Daughter; // particle 1st mother | hepevt.jmohep[number][0] - 1
	this->_Is_MC_Particle   =P1._Is_MC_Particle;
	this->_Is_Reco_Particle =P1._Is_Reco_Particle;
	this->_Is_Constituent   =P1._Is_Constituent;
	this->_Is_PU            =P1._Is_PU; // F or T for particles from pile-up interactions
	this->_Is_Ready         =P1._Is_Ready; //whether initialized for this particle
	this->_WhatJet          =P1._WhatJet;
	this->_JetSort          =P1._JetSort; // _JetSort[n].first  is the probability of being that jet 
	this->_jet_num          =P1._jet_num;

	this->_nr               =P1._nr;
	this->_pTr              =P1._pTr; 
	this->_pTr_fit          =P1._pTr_fit; 
	this->_smallr           =P1._smallr; 
	this->_pTR              =P1._pTR;
	this->_Is_Jet           =P1._Is_Jet; //whether initialized for this particle
	this->_Has_JEP          =P1._Has_JEP;
	return(*this);
}

inline bool AParticle::operator == (const AParticle& P1){
	if(_ID == P1._ID){
		return(true);
	}
	else{
		return(false);
	}
}

typedef std::vector<AParticle*>  AParticleType;

std::ostream & operator<<(std::ostream & ostr, AParticle& particle);
//std::ostream & operator<<(std::ostream & ostr, AParticle* particle);
std::ostream & operator<<(std::ostream & ostr, std::vector<AParticle> &particle);
std::ostream & operator<<(std::ostream & ostr, AParticleType particle);

#endif
