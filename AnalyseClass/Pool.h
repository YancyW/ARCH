#pragma once
#ifndef APOOL_H
#define APOOL_H  
#include "AnalyseClass/Particle.h"
#include "AnalyseClass/ParticleFunction.h"
#include "AnalyseClass/Pair.h"
#include "TSystem.h"
#include <vector> 
#include "Function/Fvector.h" 
#include "Class/DrawClass.h" 
#include "Function/Ftest.h" 

class APool{
	private:
		float                 _detector_energy;
		float                 _detector_angle;
		bool                  _Has_Detector_Para;

		int                   _num_first;
		int                   _num_second;
		int                   _num_pool;

		int                   _num_ds_pair;
		int                   _num_ds_best;
		bool                  _IsDSUsed ;
		bool                  _HasDSBest;


		int                   _num_ss_pair;
		int                   _num_ss_best;
		bool                  _IsSSUsed ;
		bool                  _HasSSBest;

		APairVec              _ds_pair;//ds means different sign
		AParticleType         _pool_ds_left;

		APairVec              _ss_pair;//ss means same sign
		AParticleType         _pool_ss_left;


	public:
		AParticleType         _pool;
		AParticleType         _first;
		AParticleType         _second;

		APairVec              _ds_pair_choosed;
		APairVec              _ss_pair_choosed;

		/*****************************************************************************************
		 * @name basic construction/destruction function 
		 ******************************************************************************************/

		void Init();

		void Clear();

		void Clear_Ptr();


		APool(){
			Init();
		}

		~APool(){
			Clear();
		}



		/*****************************************************************************************
		 * @name basic private output 
		 ******************************************************************************************/
		int Pool_Num(){
			return(_num_pool);
		}

		int First_Num(){
			return(_num_first);
		}

		int Second_Num(){
			return(_num_second);
		}



		/*****************************************************************************************
		 * @name ds pair 
		 ******************************************************************************************/
		int DS_Pair_Num(){
			return(_num_ds_pair);
		}

		int Is_DS_Used(){
			return(_IsDSUsed);
		}

		int Has_DS_Best(){
			return(_HasDSBest);
		}




		/*****************************************************************************************
		 * @name ss pair 
		 ******************************************************************************************/

		int SS_Pair_Num(){
			return(_num_ss_pair);
		}

		int Is_SS_Used(){
			return(_IsSSUsed);
		}

		int Has_SS_Best(){
			return(_HasSSBest);
		}



		/*****************************************************************************************
		 * @name public basic output 
		 ******************************************************************************************/


		AParticleType Pool(){
			return(_pool);
		}

		AParticleType First(){
			return(_first);
		}

		AParticleType Second(){
			return(_second);
		}



		/*****************************************************************************************
		 * @name public basic ds output 
		 ******************************************************************************************/

		APairVec DS_Pair(){//ds means different sign
			return(_ds_pair);
		}

		AParticleType Best_DS_Combine(){
			AParticleType out;
			for(int i=0;i<_num_ds_best;i++){
				out.push_back(_ds_pair_choosed[i].Combine());
			}
			return(out);
		}

		AParticleType Best_DS_First(){
			AParticleType out;
			for(int i=0;i<_num_ds_best;i++){
				out.push_back(_ds_pair_choosed[i].First());
			}
			return(out);
		}

		AParticleType Best_DS_Second(){
			AParticleType out;
			for(int i=0;i<_num_ds_best;i++){
				out.push_back(_ds_pair_choosed[i].Second());
			}
			return(out);
		}

		std::vector<AParticleType> Best_DS_PairVec(){
			std::vector<AParticleType> out;
			for(int i=0;i<_num_ds_best;i++){
				out.push_back(_ds_pair_choosed[i].PairVec());
			}
			return(out);
		}

		APairTypeVec Best_DS_Pair(){
			APairTypeVec out;
			for(int i=0;i<_num_ds_best;i++){
				out.push_back(_ds_pair_choosed[i].Pair());
			}
			return(out);
		}

		std::vector<AParticleType> Best_DS_Pair_ori(){
			std::vector<AParticleType> Pnew_all;
			if(_IsDSUsed==true){
				for(int i=0;i<_num_ds_best;i++){
					AParticleType Pnew;
					Pnew.push_back(_first [_ds_pair_choosed[i].Pair_Aux().first] );
					Pnew.push_back(_second[_ds_pair_choosed[i].Pair_Aux().second]);
					Pnew_all.push_back(Pnew);
				}
			}
			return(Pnew_all);
		}

		APairVec Choosed_DS_Pair(){
			return(_ds_pair_choosed);
		}


		/*****************************************************************************************
		 * @name public basic ss output 
		 ******************************************************************************************/

		APairVec SS_Pair(){//ds means different sign
			return(_ss_pair);
		}

		AParticleType Best_SS_Combine(){
			AParticleType out;
			for(int i=0;i<_num_ss_best;i++){
				out.push_back(_ss_pair_choosed[i].Combine());
			}
			return(out);
		}

		AParticleType Best_SS_First(){
			AParticleType out;
			for(int i=0;i<_num_ss_best;i++){
				out.push_back(_ss_pair_choosed[i].First());
			}
			return(out);
		}

		AParticleType Best_SS_Second(){
			AParticleType out;
			for(int i=0;i<_num_ss_best;i++){
				out.push_back(_ss_pair_choosed[i].Second());
			}
			return(out);
		}

		std::vector<AParticleType> Best_SS_PairVec(){
			std::vector<AParticleType> out;
			for(int i=0;i<_num_ss_best;i++){
				out.push_back(_ss_pair_choosed[i].PairVec());
			}
			return(out);
		}

		APairTypeVec Best_SS_Pair(){
			APairTypeVec out;
			for(int i=0;i<_num_ss_best;i++){
				out.push_back(_ss_pair_choosed[i].Pair());
			}
			return(out);
		}

		std::vector<AParticleType> Best_SS_Pair_ori(){
			std::vector<AParticleType> Pnew_all;
			if(_IsDSUsed==true){
				for(int i=0;i<_num_ds_best;i++){
					AParticleType Pnew;
					Pnew.push_back(_pool[_ss_pair_choosed[i].Pair_Aux().first] );
					Pnew.push_back(_pool[_ss_pair_choosed[i].Pair_Aux().second]);
					Pnew_all.push_back(Pnew);
				}
			}
			return(Pnew_all);
		}

		APairVec Choosed_SS_Pair(){
			return(_ss_pair_choosed);
		}


		/*****************************************************************************************
		 * @name basic change  
		 ******************************************************************************************/


		void Add_First(AParticle* input);

		void Add_First(AParticleType input);


		void Add_Second(AParticle* input);

		void Add_Second(AParticleType input);


		void Add_Pool(AParticle* input);

		void Add_Pool(AParticleType input);

		/*****************************************************************************************
		 * @name set basic para 
		 ******************************************************************************************/

		void Set_First_Num(){
			_num_first=_first.size();
		}

		void Set_Second_Num(){
			_num_second=_second.size();
		}

		void Set_Pool_Num(){
			_num_pool=_pool.size();
		}

		void Set_Num(){
			Set_First_Num();
			Set_Second_Num();
			Set_Pool_Num();
		}

		void Set_Detector_Para(float energy, float angle){
			_detector_energy = energy;
			_detector_angle  = angle;
			_Has_Detector_Para = true;

		}
		/*****************************************************************************************
		 * @name set ds pair 
		 ******************************************************************************************/

		void Set_DS_Pair_Num(){
			_num_ds_pair=_ds_pair.size();
		}

		int Set_Is_DS_Used(bool judge){
			_IsDSUsed = judge;
		}

		int Set_Has_DS_Best(bool judge){
			_HasDSBest = judge;
		}

		void Set_DS_Pool();

		void Get_DS_Pairs();

		void Set_DS_Pair();

		void Set_Best_DS_Pair(FloatVecVec &in_value, std::string property, std::string sort);

		void Get_Best_DS_Pair(FloatVecVec &in_value, std::string property, std::string sort);

		AParticle Best_DS_Recoil();

		/*****************************************************************************************
		 * @name set ss pair 
		 ******************************************************************************************/

		void Set_SS_Pair_Num(){
			_num_ss_pair=_ss_pair.size();
		}

		int Set_Is_SS_Used(bool judge){
			_IsSSUsed = judge;
		}

		int Set_Has_SS_Best(bool judge){
			_HasSSBest = judge;
		}

		void Get_SS_Pairs();

		void Set_SS_Pair();

		void Set_Best_SS_Pair(FloatVecVec &in_value, std::string property, std::string sort);

		void Get_Best_SS_Pair(FloatVecVec &in_value, std::string property, std::string sort);

		AParticle Best_SS_Recoil();

		void Get_SS_Choosed_JEP();


		/*****************************************************************************************
		 * @name general function 
		 ******************************************************************************************/


		void Get_Best_Pair_Left(AParticleType &in, AParticleType &left, std::vector<int> best_pos);






		/*****************************************************************************************
		 * @name basic class operator  
		 ******************************************************************************************/

		inline const  APool&  operator += (const APool& P1);
		inline const  APool&  operator -= (const APool& P1);
		inline        APool   operator +  (const APool& P1);
		inline        APool   operator -  (const APool& P1);
		inline const  APool&  operator =  (const APool& P1);
		inline        APool   Equal       (const APool& P1);

};

inline const APool& APool::operator += (const APool &P1){
	_first+=P1._first;
	_second+=P1._second;
	_pool+=P1._pool;
	return(*this);
}

inline const APool& APool::operator -= (const APool &P1){
	_first-=P1._first;
	_second-=P1._second;
	_pool-=P1._pool;
	return(*this);
}


inline APool  APool::operator + (const APool &P1){
	APool Pnew;
	Pnew._first =_first +P1._first;
	Pnew._second=_second+P1._second;
	Pnew._pool=_pool+P1._pool;
	return(Pnew);
}

inline APool  APool::operator - (const APool &P1){
	APool Pnew;
	Pnew._first  =_first +P1._first;
	Pnew._second-=_second+P1._second;
	Pnew._pool-=_pool+P1._pool;
	return(Pnew);
}

inline  APool APool::Equal(const APool& P1){
	this->Clear();
	this->_first=P1._first ;
	this->_second=P1._second;
	this->_pool=P1._pool;
	this->Set_Num();
	this->Set_Is_DS_Used(P1._IsDSUsed);
	this->Set_Is_SS_Used(P1._IsSSUsed);
	return(*this);
}


inline const APool&  APool::operator = (const APool &P1){
	this->Equal(P1);
	return(*this);
}


std::ostream & operator<<(std::ostream & ostr, APool &pool);
std::ostream & operator<<(std::ostream & ostr, APool* pool);
#endif
