
#pragma once
#ifndef APAIR_H
#define APAIR_H  
#include "Particle.h"
#include "TSystem.h"
#include <vector> 
#include "Function/Fvector.h" 

typedef std::pair<AParticle*,AParticle*>  APairType;
typedef std::vector<std::pair<AParticle*,AParticle*> >  APairTypeVec;
typedef std::pair<int,int>                APairAuxType;
typedef std::vector<APairAuxType >   APairAuxVec;

class APair{
	private:
		float                 _detector_energy;
		float                 _detector_angle;
		bool                  _Has_Detector_Para;

		float                 _angle;

		AParticleType         _vec;
		APairType             _pair;
		APairAuxType          _pair_aux;// pair first/second position in the input pool
		int                   _pair_pos;// pair position of the input pool pair
		AParticle*            _first;
		AParticle*            _second;
		AParticle*            _combine;
		AParticle*            _recoil;

		bool        _HasFirst   ;
		bool        _HasSecond  ;
		bool        _HasPair    ;
		bool        _HasCombine ;
		bool        _HasRecoil  ;

		bool        _HasAngle   ;
	public:

		void Init();

		void Clear();

		void Clear_Ptr();

		APair(){
			Init();
		}

		APair(AParticle* first, AParticle* second){
            Init();
			Add_Pair(first,second);
		}

		~APair(){
			Clear();
		}


		AParticle* First(){
        	if(_HasFirst){
        		return(_first);
        	}
        	else{
        		return(NULL);
        	}
		}

		AParticle* Second(){
			if(_HasSecond){
				return(_second);
			}
			else{
				return(NULL);
			}
		}

		APairType Pair(){
			if(!_HasPair){
				_pair.first  = NULL;
				_pair.second = NULL;
			}
			return(_pair);
		}

		
		APairAuxType Pair_Aux(){
			if(!_HasPair){
				_pair_aux.first =-100;
				_pair_aux.second=-100;
			}
			return(_pair_aux);
		}

		int Pair_Pos(){
			if(!_HasPair){
				_pair_pos=-100;
			}
			return(_pair_pos);
		}

		AParticleType PairVec(){
			if(!_HasPair){
				_vec.push_back(NULL);
			}
			return(_vec);
		}

		AParticle* Combine(){
			if(_HasCombine){
				return(_combine);
			}
			else{
				return(NULL);
			}
		}

		AParticle* Recoil(){
			if(_HasRecoil){
				return(_recoil);
			}
			else{
				return(NULL);
			}
		}

		float CosTheta(){
			if(_HasAngle){
				return(std::cos(_angle));
			}
			else{
				return(-100.1);
			}
		}


		bool  Has_First   (){return(_HasFirst)   ;}
		bool  Has_Second  (){return(_HasSecond)  ;}
		bool  Has_Pair    (){return(_HasPair)    ;}
		bool  Has_Combine (){return(_HasCombine) ;}
		bool  Has_Recoil  (){return(_HasRecoil)  ;}

		bool  Has_Angle   (){return(_HasAngle)   ;}

		/*****************************************************************************************
		 * @Name: addFirst 
		 *
		 * @Param: input
		 **********************************************************************i******************/
		void Add_First(AParticle* input);

		/*****************************************************************************************
		 * @Name: addSecond 
		 *
		 * @Param: input
		 **********************************************************************i******************/
		void Add_Second(AParticle* input);
                                                                                            


		/*****************************************************************************************
		 * @Name: Add_Pair_Aux 
		 *
		 * @Param: in1
		 * @Param: in2
		 * @Param: in3
		 *****************************************************************************************/
		void Add_Pair_Aux(int in1,int in2,int in3);




		/*****************************************************************************************
		 * @Name: setPair 
		 **********************************************************************i******************/
		void Set_Pair();



		/*****************************************************************************************
		 * @Name: setCombine 
		 **********************************************************************i******************/
		void Set_Combine();


		/*****************************************************************************************
		 * @Name: setRecoil
		 **********************************************************************i******************/
		void Set_Recoil(float energy, float angle);


		void Get_JEP();

		/*****************************************************************************************
		 * @Name: setAngle 
		 **********************************************************************i******************/
		void Set_Angle();



		/*****************************************************************************************
		 * @Name: set 
		 **********************************************************************i******************/
		void Set();


		/*****************************************************************************************
		 * @Name: addPair 
		 *
		 * @Param: input1
		 * @Param: input2
		 **********************************************************************i******************/
		void Add_Pair(AParticle* input1, AParticle* input2);


		void Add_Pair(AParticleType input);



////////inline APair& operator += (const APair& P1);
////////inline APair& operator -= (const APair& P1);
////////inline APair  operator +  (const APair& P1);
////////inline APair  operator -  (const APair& P1);
		inline APair  operator =  (APair& P1);
		inline APair  Equal       (APair& P1);

};

/*
inline APair& APair::operator += (const APair& P1){
	_first ->AddEqual(P1.First()) ;
	_second->AddEqual(P1.Second());
	Set();
	return(*this);
}

inline APair& APair::operator -= (const APair& P1){
	_first  -= P1.First() ;
	_second -= P1.Second();
	Set();
	return(*this);
}


inline APair APair::operator + (const APair &P1){
	APair Pnew;
	Pnew._first  = _first +P1.First();
	Pnew._second = _second+P1.Second();
	Pnew.Set();
	return(Pnew);
}

inline APair APair::operator - (const APair &P1){
	APair Pnew;
	Pnew._first  = _first -P1.First();
	Pnew._second = _second-P1.Second();
	Set();
	return(Pnew);
}

*/
inline APair APair::Equal       (APair& P1){
////Add_First (P1.First() );
////Add_Second(P1.Second());
////Add_Pair_Aux(P1.Pair_Aux().first,P1.Pair_Aux().second,P1.Pair_Pos());
	_first  = P1._first;
	_second = P1._second;
	_pair_aux.first = P1._pair_aux.first;
	_pair_aux.second= P1._pair_aux.second;
	_pair_pos       = P1._pair_pos;
	std::cout << "pair equal" << std::endl;
	Set();
	return(*this);
}


inline APair  APair::operator = (APair &P1){
	_first  = P1._first;
	_second = P1._second;
	_pair_aux.first = P1._pair_aux.first;
	_pair_aux.second= P1._pair_aux.second;
	_pair_pos       = P1._pair_pos;
////Add_First (P1.First() );
////Add_Second(P1.Second());
////Add_Pair_Aux(P1.Pair_Aux().first,P1.Pair_Aux().second,P1.Pair_Pos());
	std::cout << "pair equal" << std::endl;
	Set();
	return(*this);
}


typedef std::vector<APair> APairVec;

std::ostream & operator<<(std::ostream & ostr, APairType  pair);
std::ostream & operator<<(std::ostream & ostr, APair& pair);
std::ostream & operator<<(std::ostream & ostr, APair* pair);
std::ostream & operator<<(std::ostream & ostr, APairVec   pair);

#endif
