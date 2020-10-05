#include "AnalyseClass/Particle.h"

/*****************************************************************************************
 * @name basic ID  
 ******************************************************************************************/

/*****************************************************************************************
 * variable output function
 **********************************************************************i******************/

int AParticle::ID(){
	if(_Is_Ready.Exist())	return(_ID);
	else{return(-100);}
}

int AParticle::PID(){
	if(_Is_Ready.Exist()	)	return(_PID);
	else{return(0);}
}

/*****************************************************************************************
 * variable setting function
 **********************************************************************i******************/

void AParticle::Set_ID(int num){
	_ID=num;
}

void AParticle::Set_PID(int in){
	_PID=in;
}






/*****************************************************************************************
 * @name normal particle information 
 ******************************************************************************************/

/*****************************************************************************************
 * private function 
 **********************************************************************i******************/

void AParticle::_Init_Particle(){
	_ID                 =-1     ;
	_PID                = 0     ;
	_Is_Ready.Clear()           ;
	_Is_MC_Particle.Clear()     ;
	_Is_Reco_Particle.Clear()   ;
	_Is_Constituent.Clear()     ;
	_Is_PU.Clear()              ;
	_Charge             =-100.0 ;
	_Mass               =-100.0 ;
	_E                  =-100.0 ;
	_Px                 =-100.0 ;
	_Py                 =-100.0 ;
	_Pz                 =-100.0 ;
	_P                  =TLorentzVector(-100.0,-100.0,-100.0,-100.0);
	_Mom                =-100.0 ;
	_Pt                 =-100.0 ;
	_Y                  =-100.0 ;
	_Eta                =-100.0 ;
	_Theta              =-100.0 ;
	_Phi                =-100.0 ;
	_CosTheta           =-100.0 ;
	_Status             =-100.0 ;
}

void AParticle::_Init_Reconstruction(){
	////	    SumPT2(0), 
	////		Flavor(0), FlavorAlgo(0), FlavorPhys(0),
	////		BTag(0), CTag(0),QTagAlgo(0), QTagPhys(0),
	////		TauTag(0), 
	////		Eem(0.0), Ehad(0.0),
	////		DeltaEta(0.0), DeltaPhi(0.0),
	////		Momentum(0.0, 0.0, 0.0, 0.0),
	////		Position(0.0, 0.0, 0.0, 0.0),
	////		PositionError(0.0, 0.0, 0.0, 0.0),
	////		InitialPosition(0.0, 0.0, 0.0, 0.0),
	////		Area(0.0, 0.0, 0.0, 0.0),
	////		L(0),
	////		D0(0), ErrorD0(0), 
	////		DZ(0), ErrorDZ(0), 
	////		P(0),  ErrorP(0), 
	////		PT(0), ErrorPT(0), 
	////		CtgTheta(0), ErrorCtgTheta(0), 
	////		Phi(0), ErrorPhi(0),  
	////		Xd(0), Yd(0), Zd(0), 
	////		TrackResolution(0),
	////		NCharged(0),
	////		NNeutrals(0),
	////		Beta(0),
	////		BetaStar(0),
	////		MeanSqDeltaR(0),
	////		PTD(0),
	////		NTimeHits(-1),
	////		IsolationVar(-999),
	////		IsolationVarRhoCorr(-999),
	////		SumPtCharged(-999),
	////		SumPtNeutral(-999),
	////		SumPtChargedPU(-999),
	////		SumPt(-999),
	////		NSubJetsTrimmed(0),
	////		NSubJetsPruned(0),
	////		NSubJetsSoftDropped(0),
	////		fFactory(0),
	////		fArray(0),
	////			Edges .push_back(0.0);
	////			FracPt.push_back(0.0);
	////			Tau   .push_back(0.0);
}
/*****************************************************************************************
 * public function 
 **********************************************************************i******************/

AParticle::AParticle(){
	Init();
} 

AParticle::AParticle(float inx,float iny,float inz,float ine, float inCharge, int inPID){ 
	Init();
	_ID=Get_Global_ID();	
	Set_P(inx,iny,inz,ine);
	_Charge=inCharge;
	_PID   =inPID;
	_fp.set_user_index(inPID);
}

AParticle::AParticle(TLorentzVector Pin, float inCharge, int inPID){
	Init();
	_ID=Get_Global_ID();	
	Set_P(Pin);
	_Charge=inCharge;
	_PID   =inPID;
	_fp.set_user_index(inPID);
}

AParticle::AParticle(fastjet::PseudoJet Pin, float inCharge, int inPID){
	Init();
	_ID=Get_Global_ID();	
	Set_P(Pin);
	_Charge=inCharge;
	_PID   =inPID;
	_fp.set_user_index(inPID);
}

AParticle::AParticle(AParticle *Pin){
	Init();
	this->Equal(*Pin);
}

AParticle::~AParticle(){
}

void AParticle::Init(){
	_Init_Particle();
	_Init_Reconstruction();
	_Init_Jet();
}


/*****************************************************************************************
 * variabble output function
 **********************************************************************i******************/

float AParticle::Charge(){
	if(_Is_Ready.Exist()	)	return(_Charge);
	else{return(-100.0);}
}

float AParticle::M(){
	if(_Is_Ready.Exist()	)	return(_Mass);
	else{return(-100.0);}
}

TLorentzVector AParticle::P(){
	if(_Is_Ready.Exist()	)	return(_P);
	else{return(TLorentzVector(0,0,0,-100.0));}
}

TVector3 AParticle::V(){
	if(_Is_Ready.Exist()	)	return(_V);
	else{return(TVector3(0,0,0));}
};

fastjet::PseudoJet AParticle::FP(){
	if(_Is_Ready.Exist()	)	return(_fp);
	else{return(fastjet::PseudoJet(0,0,0,-100.0));}
};

float AParticle::E(){
	if(_Is_Ready.Exist()	)	return(_E);
	else{return(-100.0);}
}

float AParticle::Px(){
	if(_Is_Ready.Exist()	)	return(_Px);
	else{return(-100.0);}
}

float AParticle::Py(){
	if(_Is_Ready.Exist()	)	return(_Py);
	else{return(-100.0);}
}

float AParticle::Pz(){
	if(_Is_Ready.Exist()	)	return(_Pz);
	else{return(-100.0);}
}

float AParticle::Mom(){
	if(_Is_Ready.Exist()	)	return(_Mom);
	else{return(-100.0);}
}

float AParticle::Mom2(){
	if(_Is_Ready.Exist()	)	return(_Mom2);
	else{return(-100.0);}
}

float AParticle::Pt(){
	if(_Is_Ready.Exist()	)	return(_Pt);
	else{return(-100.0);}
}

float AParticle::Eta(){
	if(_Is_Ready.Exist()	)	return(_Eta);
	else{return(-100.0);}
}

float AParticle::Y(){
	if(_Is_Ready.Exist()	)	return(_Y);
	else{return(-100.0);}
}

float AParticle::Theta(){
	if(_Is_Ready.Exist()	)	return(_Theta);
	else{return(-100.0);}
}

float AParticle::Phi(){
	if(_Is_Ready.Exist()	)	return(_Phi);
	else{return(-100.0);}
}

float AParticle::CosTheta(){
	if(_Is_Ready.Exist()	)	return(_CosTheta);
	else{return(-100.0);}
}

int AParticle::Status(){
	if(_Is_Ready.Exist()	)	return(_Status);
	else{return(-100);}
}

std::vector<int> AParticle::Mother(){
	if(_Is_Ready.Exist()	)	return(_Mother);
	else{return(std::vector<int> ());}
}

std::vector<int> AParticle::Daughter(){
	if(_Is_Ready.Exist()	)	return(_Daughter);
	else{return(std::vector<int> ());}
}

/*****************************************************************************************
 * variable setting function
 **********************************************************************i******************/


void AParticle::Set_Charge(float in){
	_Charge = in;
}

void AParticle::Set_Mass(float in){
	_Mass = in;
}

void AParticle::Set_P(float inx,float iny,float inz,float ine){
	_Is_Ready.Set();
	_V.SetXYZ(inx,iny,inz);
	_P.SetPxPyPzE(inx,iny,inz,ine);
	_Px=inx;
	_Py=iny;
	_Pz=inz;
	_E =ine;
	fastjet::PseudoJet  tmp(_Px,_Py,_Pz,_E);
	_fp=tmp;
	_Mom2=std::pow(_Px,2)+std::pow(_Py,2)+std::pow(_Pz,2);
	_Mom =std::sqrt(_Mom2);
	_Pt=std::sqrt(_Px*_Px+_Py*_Py);
	if(std::abs(_Mom)>std::pow(0.1,10)){
		_CosTheta=_Pz/_Mom;
		_Theta=std::acos(_Pz/_Mom);
	}
	else{
		_CosTheta=1;
		_Theta=0.0;
	}
	_Eta=_fp.eta();
	_Y=_fp.rap();
	_Phi=_fp.phi();
	_Mass=_fp.m();
}

void AParticle::Set_P(TLorentzVector Pin){
	Set_P(Pin[0],Pin[1],Pin[2],Pin[3]);
}

void AParticle::Set_P(fastjet::PseudoJet Pin){
	Set_P(Pin.px(),Pin.py(),Pin.pz(),Pin.e());
	_fp = Pin;
}

void AParticle::Set_P(){
	if(_P(0)==-100.0&&_P(1)==-100.0&&_P(2)==-100.0&&_P(3)==-100.0){return;}
	_Px=_P(0);
	_Py=_P(1);
	_Pz=_P(2);
	_E =_P(3);
	fastjet::PseudoJet  tmp(_Px,_Py,_Pz,_E);
	_fp=tmp;
	_Mom2=std::pow(_Px,2)+std::pow(_Py,2)+std::pow(_Pz,2);
	_Mom =std::sqrt(_Mom2);
	_Pt=std::sqrt(_Px*_Px+_Py*_Py);
	if(std::abs(_Mom)>std::pow(0.1,10)){
		_CosTheta=_Pz/_Mom;
		_Theta=std::acos(_Pz/_Mom);
	}
	else{
		_CosTheta=1;
		_Theta=0.0;
	}
	_Eta=_fp.eta();
	_Y=_fp.rap();
	_Phi=_fp.phi();
	_Mass=_fp.m();
} 

void AParticle::Set_Mother(int inM){
	_Mother.push_back(inM);
}

void AParticle::Set_Mother(std::vector<int> inM){
	if(!_Mother   .empty()){
		_Mother=inM;
	}
	else{
		for(int i=0;i<inM.size();i++){
			_Mother.push_back(inM[i]);
		}
	}
}

void AParticle::Set_Daughter(int inD){
	_Daughter.push_back(inD);
}

void AParticle::Set_Daughter(std::vector<int> inD){
	if(!_Daughter.empty()){
		_Daughter=inD;
	}
	else{
		for(int i=0;i<inD.size();i++){
			_Daughter.push_back(inD[i]);
		}
	}
}


/*****************************************************************************************
 * judge variable output function
 **********************************************************************i******************/

bool AParticle::Is_Reco_Particle(){
	if(_Is_Ready.Exist()	)	return(_Is_Reco_Particle.Exist());
	else{return(false);}
}

bool AParticle::Is_Constituent(){
	if(_Is_Ready.Exist()	)	return(_Is_Constituent.Exist());
	else{return(false);}
}


bool AParticle::Is_PU(){
	if(_Is_Ready.Exist()	)	return(_Is_PU.Exist());
	else{return(false);}
}

bool AParticle::Is_MC_Particle(){
	if(_Is_Ready.Exist()	)	return(_Is_MC_Particle.Exist());
	else{return(false);}
}


bool AParticle::Is_Ready(){
	return(_Is_Ready.Exist());
}




/*****************************************************************************************
 * @name reconstructed particle information 
 ******************************************************************************************/


/*****************************************************************************************
 * @name jet and jet substructure 
 ******************************************************************************************/

/*****************************************************************************************
 * private function
 **********************************************************************i******************/
void AParticle::_Init_Jet(){
	// if just create a AJetType, it is a Qjet
	_JetSort.push_back(std::make_pair(0.0,"Tjet"  ));
	_JetSort.push_back(std::make_pair(0.0,"Bjet"  ));
	_JetSort.push_back(std::make_pair(0.0,"Cjet"  ));
	_JetSort.push_back(std::make_pair(1.0,"Qjet"  ));
	_JetSort.push_back(std::make_pair(0.0,"Taujet"));
	_JetSort.push_back(std::make_pair(0.0,"Gluonjet"));
	_Is_Jet.Clear();
	_Has_JEP.Clear();
	_WhatJet.second = "Qjet";
	_WhatJet.first  = 1,0;
	_nr             = 1; 
	_pTr            . resize(_nr);
	_pTr_fit        . resize(_nr);
	_smallr         . resize(_nr);
	_pTR            = 0.0;
	for( int i= 0; i< _nr; ++i) {
		_pTr[i]     = 0.0;
		_pTr_fit[i] = 0.0;
		_smallr[i]  = (i+1)*0.1;
	}
}


void AParticle::_Find_What_Jet(){
	std::sort(_JetSort.begin(),_JetSort.end());
	_WhatJet.second= _JetSort[5].second;
	if(_WhatJet.second=="Tjet"){
		_WhatJet.first=6.0;
	}
	else if(_WhatJet.second=="Bjet"){
		_WhatJet.first=5.0;
	}
	else if(_WhatJet.second=="Cjet"){
		_WhatJet.first=4.0;
	}
	else if(_WhatJet.second=="Qjet"){
		_WhatJet.first=1.0;
	}
	else if(_WhatJet.second=="Taujet"){
		_WhatJet.first=13.0;
	}
	else if(_WhatJet.second=="Gluonjet"){
		_WhatJet.first=0.0;
	}
}

/*****************************************************************************************
 * public function
 **********************************************************************i******************/

void AParticle::Set_Jet(PseudoJetVec &bquark, PseudoJetVec &cquark, float coneR, CTag tag){
	_nr        = std::floor((coneR+0.005)/0.1);
	_pTr       . resize(_nr);
	_pTr_fit   . resize(_nr);
	_smallr    . resize(_nr);

	for( int i= 0; i< _nr; ++i) {
		_pTr[i]    = 0.0;
		_pTr_fit[i]= 0.0;
		_smallr[i] = (i+1)*0.1;
	}
	if(Set_Tag(tag.btag,bquark,cquark)){
		_JetSort[1].first = 1.0;
		_JetSort[3].first = 0.0;
	}
	else if(Set_Tag(tag.ctag, bquark,cquark)){
		_JetSort[2].first = 1.0;
		_JetSort[3].first = 0.0;
	};

	_Find_What_Jet();

	return;
}



void AParticle::Get_JEP(int which_jep_fit){

	int consti_num = _fp.constituents().size();

	if( consti_num <= 1 ) {
		return;
	}


	for( int i= 0; i < consti_num; i++) {
            float const_pt =  _fp.constituents()[i].pt();
		_pTR = _pTR + const_pt;
	}

	if(_pTR==0){
		for(int j=0;j<_nr;j++){
			_pTr[j]     = 0;
			_pTr_fit[j] = 0;
		}
		_Has_JEP.Set();
		return;
	}
	for( int i= 0; i < consti_num; i++) {
		fastjet::PseudoJet component = _fp.constituents()[i];
		float dR = DeltaR( _fp, component );
		for( int j = 0; j < _nr; j++) {
			if( dR <= _smallr[j] ) {
				_pTr[j] = _pTr[j]+ component.pt()/_pTR;
				if(which_jep_fit==1){
					_pTr_fit[j] = JEP_quark_1(_pTR,j);
				}
				else if(which_jep_fit!=1){
					_pTr_fit[j] = JEP_quark_2(_pTR,j);
				}
			}
		}
	}
	_Has_JEP.Set()    ;
	return;
}


bool AParticle::Set_Tag(CTag_Particle &tag, std::vector<fastjet::PseudoJet> bquark, std::vector<fastjet::PseudoJet> cquark){
	float random;
	int j;

	for(j=0;j<bquark.size();j++){
		if(this->_fp.delta_R(bquark[j])<tag.coneR)
		{
			random=std::rand()%10000;
			if(random<tag.bquark_ratio*10000){
				return(true);
			}
		}
	}

	//for a  c-quark to be regonized as a b quark
	for(j=0;j<cquark.size();j++){
		if(this->_fp.delta_R(cquark[j])<tag.coneR)
		{
			random=std::rand()%10000;
			if(random<tag.cquark_ratio*10000){
				return(true);
			}
		}
	}

	//for a  light-quark to be regonized as a b quark
	random=std::rand()%10000;
	if(random<tag.lightquark_ratio*10000){
		return(true);
	}
	return(false);
}


/*****************************************************************************************
 * output function
 **********************************************************************i******************/
int AParticle::JEP_Num(){
	if(_Is_Ready.Exist()	)	return(_nr);
	else{return(0);}

}

std::vector<float> AParticle::JEP(){
	if(_Is_Ready.Exist()	)	return(_pTr);
	else{return(std::vector<float> ());}
}

std::vector<float> AParticle::JEP_Fit(){
	if(_Is_Ready.Exist()	)	return(_pTr_fit);
	else{return(std::vector<float> ());}

}

float AParticle::Pt_SUM(){
	if(_Is_Ready.Exist()	)	return(_pTR);
	else{return(0);}

}



std::string AParticle::What_Jet_Name(){
	if(_Is_Ready.Exist()	)	return(_WhatJet.second);
	else{return("");}
}

float       AParticle::What_Jet_Type(){
	if(_Is_Ready.Exist()	)	return(_WhatJet.first);
	else{return(0.0);}
}

/*****************************************************************************************
 * judge variable output function
 **********************************************************************i******************/

bool AParticle::Is_Jet(){
	if(_Is_Ready.Exist()	)	return(_Is_Jet.Exist());
	else{return(false);}
}

bool AParticle::Has_JEP(){
	if(_Is_Ready.Exist()	)	return(_Has_JEP.Exist());
	else{return(false);}
}




std::ostream & operator<<(std::ostream & ostr, AParticle& particle){
	printf("\n"); // ]label the columns
	printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s \n",   "ID"         ,"PID"          ,"charge"          , "px"         ,"py"         ,"pz"         ,"e"         , "rapidity"  ,"CosTheta"         ,"phi"         , "pt"        ,"m"); // label the columns
	printf("%12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  \n", particle.ID(), particle.PID(), particle.Charge(), particle.Px(),particle.Py(),particle.Pz(),particle.E(), particle.Y(),particle.CosTheta(),particle.Phi(),particle.Pt(),particle.M());
	return ostr;
}









/*
   std::ostream & operator<<(std::ostream & ostr, AParticle* particle){
   printf("\n"); // ]label the columns
   printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s \n","ID" ,"PID","charge", "px","py","pz","e", "rapidity","CosTheta","phi", "pt","m"); // label the columns
   printf("%12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  \n",particle->ID(), particle->PID(), particle->Charge(), particle->Px(),particle->Py(),particle->Pz(),particle->E(), particle->Y(),particle->CosTheta(),particle->Phi(),particle->Pt(),particle->M());
   return ostr;
   }
   */

std::ostream & operator<<(std::ostream & ostr, std::vector<AParticle> &particle){
	printf("\n"); // ]label the columns


	printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s \n","ith", "ID" ,"PID","charge", "px","py","pz","e", "rapidity","CosTheta","phi", "pt","m","M1","M2","D1","D2"); // label the columns
	for (unsigned int i = 0; i < particle.size(); i++) {
		int parent1, parent2;
		int daughter1,daughter2;
		AParticle* in=&particle[i];
		if(in->Mother().size()==0){
		    parent1 = -1;
		    parent2 = -1;
		}
		else if(in->Mother().size()==1){
		    parent1 = in->Mother()[0];
		    parent2 = -1;
		}
		else if(in->Mother().size()>=2){
		    parent1 = in->Mother()[0];
		    parent2 = in->Mother()[1];
		}
		
		if(in->Daughter().size()==0){
		    daughter1 = -1;
		    daughter2 = -1;
		}
		else if(in->Daughter().size()==1){
		    daughter1 = in->Daughter()[0];
		    daughter2 = -1;
		}
		else if(in->Daughter().size()>=2){
		    daughter1 = in->Daughter()[0];
		    daughter2 = in->Daughter()[1];
		}


		printf("%12i %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %12i %12i %12i   \n",i+1, particle[i].ID(), particle[i].PID(), particle[i].Charge(), particle[i].Px(),particle[i].Py(),particle[i].Pz(),particle[i].E(), particle[i].Y(),particle[i].CosTheta(),particle[i].Phi(),particle[i].Pt(),particle[i].M(),parent1,parent2,daughter1,daughter2);

	}
	return ostr;
}




std::ostream & operator<<(std::ostream & ostr, AParticleType particle){
	printf("\n"); // ]label the columns
	printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s \n","ith", "ID" ,"PID","charge", "px","py","pz","e", "rapidity","CosTheta","phi", "pt","m"); // label the columns
	for (unsigned int i = 0; i < particle.size(); i++) {
		printf("%12i %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  \n", i+1, particle[i]->ID(), particle[i]->PID(), particle[i]->Charge(), particle[i]->Px(),particle[i]->Py(),particle[i]->Pz(),particle[i]->E(), particle[i]->Y(),particle[i]->CosTheta(),particle[i]->Phi(),particle[i]->Pt(),particle[i]->M());
	}
	return ostr;
}


