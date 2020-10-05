#include "AnalyseClass/Pair.h"


void APair::Init(){
	_detector_energy = 0;
	_detector_angle  = 0;
	_Has_Detector_Para = false;


	_pair.first  = NULL  ;
	_pair.second = NULL  ;
	_vec.clear();
	_first       = NULL  ;
	_second      = NULL  ;
	_combine     = NULL  ;
	_recoil      = NULL  ;

	_HasFirst    = false ;
	_HasSecond   = false ;
	_HasPair     = false ;
	_HasCombine  = false ;
	_HasRecoil   = false ;

	_HasAngle    = false ;
}


void APair::Clear_Ptr(){
	if(_first   != NULL) {_first  ->Rid_Instruct_ID(); delete _first  ;_first  =NULL;}
	if(_second  != NULL) {_second ->Rid_Instruct_ID(); delete _second ;_second =NULL;}
	if(_combine != NULL) {_combine->Rid_Instruct_ID(); delete _combine;_combine=NULL;}
	if(_recoil  != NULL) {_recoil ->Rid_Instruct_ID(); delete _recoil ;_recoil =NULL;}
}



void APair::Clear(){
	_detector_energy = 0;
	_detector_angle  = 0;
	_Has_Detector_Para = false;

	_pair.first  = NULL  ;
	_pair.second = NULL  ;
	_vec.clear();
	_first       = NULL  ;
	_second      = NULL  ;
	_combine     = NULL  ;
	_recoil      = NULL  ;

	_HasFirst    = false ;
	_HasSecond   = false ;
	_HasPair     = false ;
	_HasCombine  = false ;
	_HasRecoil   = false ;

	_HasAngle    = false ;
}





void APair::Add_First(AParticle* input){
	AParticle* Ppast_first  =NULL;
	AParticle* Ppast_combine=NULL;
	if(_first  !=NULL){ Ppast_first  =_first  ;}
	if(_combine!=NULL){ Ppast_combine=_combine;}
	AParticle* Pnew = new AParticle(input);
	_first= Pnew;
	_first->Get_Instruct_ID();
    _HasFirst = true;
	if(Ppast_first  !=NULL) {Ppast_first  ->Rid_Instruct_ID(); delete Ppast_first  ;}
	if(Ppast_combine!=NULL) {Ppast_combine->Rid_Instruct_ID(); delete Ppast_combine;}
}

void APair::Add_Second(AParticle* input){
	AParticle* Ppast=NULL;
	if(_second!=NULL){Ppast=_second;}
	AParticle* Pnew = new AParticle(input);
	_second=Pnew;
	_second->Get_Instruct_ID();
	_HasSecond= true;
	if(Ppast!=NULL) {Ppast->Rid_Instruct_ID(); delete Ppast;}
}


void APair::Add_Pair_Aux(int in1,int in2,int in3){
	_pair_aux.first = in1;
	_pair_aux.second= in2;
	_pair_pos  = in3;
}


void APair::Set_Pair(){
	_HasPair=true;
	_pair.first = _first;
	_pair.second= _second;
	_vec.clear();
	_vec.push_back(_first );
	_vec.push_back(_second);
}

void APair::Set_Combine(){
	_HasCombine=true;
	_combine = _first->Add(_second);
}


void APair::Set_Recoil(float energy, float angle){
	_detector_energy = energy;
	_detector_angle  = angle;
	_Has_Detector_Para = true;

	if(_Has_Detector_Para){
		AParticle  Collider = AParticle(_detector_energy*std::sin(_detector_angle),0,0,_detector_energy);
		_recoil   = Collider.Minus(_combine);
	}
	else{
		ShowMessage(2,"in APair::Set_Recoil, no detector energy");
	}
	_HasRecoil=true;
}

void APair::Get_JEP(){
	if(!_HasPair) return;
	_first ->Get_JEP(1);
    _second->Get_JEP(2);
	return;
}


void APair::Set_Angle(){
	if(!_HasPair) return;

	_angle = _first->P().Angle(_second->P().Vect());
	_HasAngle = true;
	return;
}


void APair::Set(){
	Set_Pair();
	Set_Combine();
	Set_Angle();
}



void APair::Add_Pair(AParticle* input1, AParticle* input2){
    Add_First (input1);
    Add_Second(input2);
    Set();
}


void APair::Add_Pair(AParticleType input){
	if(input.size()!=2){
		ShowMessage(2,"Error: in APair::addPair, the input particle size not equal to 2",input.size(),input);
	}
	for(int i=0;i<2;i++){
		if(input[i]->Charge()>0){
    		Add_First (input[i]);
		}
		else{
    		Add_Second(input[i]);
		}
	}
	Set();
}




std::ostream & operator<<(std::ostream & ostr, APairType  pair){
	printf("\n"); 
	ostr << "pair first" << *(pair.first);
	ostr << "pair second" << *(pair.second);
	ostr << "pair end" ;
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, APair &pair){
	printf("\n"); 
	ostr<<"pair first       :" << *(pair.First());
	ostr<<"pair second      :" << *(pair.Second());
	ostr<<"pair pair        :" << pair.Pair();
	ostr<<"pair combine     :" << *(pair.Combine());
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, APair* pair){
	printf("\n"); 
	ostr<<"pair first       :" << *(pair->First());
	ostr<<"pair second      :" << *(pair->Second());
	ostr<<"pair pair        :" << pair->Pair();
	ostr<<"pair combine     :" << *(pair->Combine());
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, APairVec  pair){
	printf("\n"); 
	for (unsigned int i = 0; i < pair.size(); i++) {
		ostr<<" pair ith " << i << "\n";
		ostr << pair[i];
	}
	return ostr;
}


