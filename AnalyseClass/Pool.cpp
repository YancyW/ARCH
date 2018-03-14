#include "AnalyseClass/Pool.h"


/*****************************************************************************************
 * @name basic class operator  
 ******************************************************************************************/

void APool::Init(){
	_detector_energy        = 0;
	_detector_angle         = 0;
	_Has_Detector_Para      = false;

	_num_first              = 0;
	_num_second             = 0;
	_num_pool               = 0;

	_IsDSUsed               = false;
	_HasDSBest              = false;
	_num_ds_pair            = 0;

	_IsSSUsed               = false;
	_HasSSBest              = false;

	_num_ss_pair            = 0;
	_num_ds_best            = 0;
	_num_ss_best            = 0;
}




void APool::Clear(){
	_detector_energy        = 0;
	_detector_angle         = 0;
	_Has_Detector_Para      = false;

	_num_first              = 0;
	_num_second             = 0;
	_num_pool               = 0;

	_first                  .clear();
	_second                 .clear();
	_pool                   .clear();


	_num_ds_pair            = 0;

	_pool_ds_left           .clear();
	if(_IsDSUsed){
		for(int i=0;i<_ds_pair.size();i++){
			_ds_pair[i].Clear();
		}
	}
	_ds_pair                .clear();
	_IsDSUsed               = false;
	if(_HasDSBest){
		for(int i=0;i<_ds_pair_choosed.size();i++){
			_ds_pair_choosed[i].Clear();
		}
		_ds_pair_choosed    .clear();
	}
	_HasDSBest              = false;




	_num_ss_pair            = 0;
	if(_IsSSUsed){
		for(int i=0;i<_ss_pair.size();i++){
			_ss_pair[i].Clear();
		}
	}
	_ss_pair                .clear();
	if(_HasSSBest){
		for(int i=0;i<_ss_pair_choosed.size();i++){
			_ss_pair_choosed[i].Clear();
		}
		_ss_pair_choosed    .clear();
	}
	_IsSSUsed               = false;
	_HasSSBest              = false;
	_pool_ss_left           .clear();
}




void APool::Clear_Ptr(){
	if(_IsDSUsed){
		for(int i=0;i<_ds_pair.size();i++){
			_ds_pair[i].Clear_Ptr();
		}
	}
	if(_HasDSBest){
		for(int i=0;i<_num_ds_best;i++){
			_ds_pair_choosed[i].Clear_Ptr();
		}
	}
	if(_IsSSUsed){
		for(int i=0;i<_ss_pair.size();i++){
			_ss_pair[i].Clear_Ptr();
		}
	}
	if(_HasSSBest){
		for(int i=0;i<_num_ss_best;i++){
			_ss_pair_choosed[i].Clear_Ptr();
		}
	}
}

/*****************************************************************************************
 * @name basic change  
 ******************************************************************************************/


void APool::Add_First(AParticle* input){
	_first.push_back(input);
	Set_First_Num();
}

void APool::Add_First(AParticleType input){
	AParticleType pnew=_first+input;
	_first=pnew;
	Set_First_Num();
}

void APool::Add_Second(AParticle* input){
	_second.push_back(input);
	Set_Second_Num();
}

void APool::Add_Second(AParticleType input){
	AParticleType pnew=_second+input;
	_second=pnew;
	Set_Second_Num();
}

void APool::Add_Pool(AParticle* input){
	_pool.push_back(input);
	Set_Pool_Num();
}

void APool::Add_Pool(AParticleType input){
	AParticleType pnew=_pool+input;
	_pool= pnew;
	Set_Pool_Num();
}

void APool::Set_DS_Pool(){
	if(_first.size()==0||_second.size()==0){return;}
	if(_pool.size()!=0){ShowMessage(2,"Error: in APool::Set_Pool","_pool size is not 0!",_pool.size());return;}
	;
	AParticleType pnew=_first+_second;
	_pool = _pool + pnew;

	Set_Pool_Num();
}


/*****************************************************************************************
 * @name set ds pair 
 ******************************************************************************************/


/*****************************************************************************************
 * @Name: Set_DS_Pair 
 *****************************************************************************************/
void APool::Set_DS_Pair(){
	if(_num_first<=0 || _num_second<=0){
		return;
	}
	if(_ds_pair.size()!=0){
		_ds_pair.clear();
	}

	int k=0;
	for(int i=0;i<_num_first;i++){
		for(int j=0;j<_num_second;j++){
			k++;
			APair ds_pair_aux(_first[i],_second[j]);
			ds_pair_aux.Add_Pair_Aux(i,j,k);
			_ds_pair.push_back(ds_pair_aux);
		}
	}
	Set_DS_Pair_Num();
}




/**********************************************************************
 * @Name: Set_Best_DS_Pair 
 *
 * @Param: in_value
 * @Param: property
 * @Param: sort
 **********************************************************************/
void APool::Set_Best_DS_Pair(FloatVecVec &in_value, std::string property, std::string sort){
	if(_ds_pair.size()<=0){
		return;
	}

	FloatVec  real_value;
	FloatVec  aux_value;
	IntVec    choosed_p;
	float     total_dis=-0.000000000000001;
	float     min_dis  =1000000000.0;


	for(int j=0;j<_num_ds_best;j++){
		choosed_p.push_back(-1);
	}


	IntVecVec out_comb;
	out_comb=Get_Nature_Combination(_ds_pair.size(),_num_ds_best);
	IntVecVec non_repeat_comb;

	for(int i=0;i<out_comb.size();i++){
		bool duplicate=false;
		for(int j=0;j<_num_ds_best;j++){
			for(int l=0;l<j;l++){
			    if(_ds_pair[out_comb[i][j]].First()->ID()== _ds_pair[out_comb[i][l]].First()->ID()){
			    	duplicate = true;
			    	break;
			    }
			    if(_ds_pair[out_comb[i][j]].First()->ID()== _ds_pair[out_comb[i][l]].Second()->ID()){
			    	duplicate = true;
			    	break;
			    }
			    if(_ds_pair[out_comb[i][j]].Second()->ID()== _ds_pair[out_comb[i][l]].First()->ID()){
			    	duplicate = true;
			    	break;
			    }
			    if(_ds_pair[out_comb[i][j]].Second()->ID()== _ds_pair[out_comb[i][l]].Second()->ID()){
			    	duplicate = true;
			    	break;
			    }
			}
			if(duplicate){
				break;
			}
		}
		if(duplicate){
			continue;
		}
		else{
			non_repeat_comb.push_back(out_comb[i]);
		}
	}
        
	for(int i=0;i<non_repeat_comb.size();i++){
		total_dis=-0.000000000000001;
		for(int j=0;j<_num_ds_best;j++){
			if(property=="mass"){
				real_value.push_back(_ds_pair[non_repeat_comb[i][j]].Combine()->M());
                float last_real=*(real_value.end()-1);
				total_dis += std::pow(last_real-in_value[0][j],2);
			}
			else if(property=="mass_recoil"){
				real_value.push_back(_ds_pair[non_repeat_comb[i][j]].Combine()->M());
				_ds_pair[non_repeat_comb[i][j]].Set_Recoil(_detector_energy,_detector_angle);
				aux_value.push_back(_ds_pair[non_repeat_comb[i][j]].Recoil()->M());
				float last_real=*(real_value.end()-1);
                float last_aux =*(aux_value.end()-1);
				total_dis += std::pow(last_real-in_value[0][j],2)+ std::pow(last_aux-in_value[1][j],2);
			}
                        
		}

        if(total_dis<min_dis && total_dis > 0){
            choosed_p=non_repeat_comb[i];
			min_dis=total_dis-0.000000000000001;
        }
	}

	bool has_best=true;
	for(int j=0;j<_num_ds_best;j++){
		if(choosed_p[j]==-1){has_best=false;break;};
	}

	if(has_best){
		for(int j=0;j<_num_ds_best;j++){
			_ds_pair_choosed.push_back(APair(_ds_pair[choosed_p[j]].First (),_ds_pair[choosed_p[j]].Second())); 
			_ds_pair_choosed[j].Add_Pair_Aux(_ds_pair[choosed_p[j]].Pair_Aux().first,_ds_pair[choosed_p[j]].Pair_Aux().second,_ds_pair[choosed_p[j]].Pair_Pos());
			_ds_pair_choosed[j].Set_Recoil(_detector_energy,_detector_angle);
		}
		_HasDSBest                = true;
	}

}




/**********************************************************************
 * @Name: Get_Best_DS_Pair 
 *
 * @Param: in_value
 * @Param: property
 * @Param: sort
 **********************************************************************/
void APool::Get_Best_DS_Pair(FloatVecVec &in_value, std::string property, std::string sort){
	//ShowMessage(2,"APool::Get_Best_DS_Pair, begin");
	_num_ds_best = in_value[0].size();
	if(_num_first<_num_ds_best||_num_second<_num_ds_best){
		return;
	}
	Set_Best_DS_Pair(in_value,property,sort);
	if(_HasDSBest){
		std::vector<int> best_pos;
		for(int j=0;j<_num_ds_best;j++){
			best_pos.push_back(_ds_pair_choosed[j].Pair_Aux().first);
			best_pos.push_back(_num_first+_ds_pair_choosed[j].Pair_Aux().second);
		}

		Get_Best_Pair_Left(_pool,_pool_ds_left,best_pos);
	}
}


AParticle APool::Best_DS_Recoil(){

	AParticle recoil;
	if(_HasDSBest){
		if(_Has_Detector_Para){
			recoil=Get_Left(_detector_energy, _detector_angle,_ds_pair_choosed[0].Combine());
		}
		else{
			ShowMessage(2,"APool::Best_DS_Recoil,don't have detector energy!");
		}
	}
	return(recoil);
}



/**********************************************************************
 * @Name: Set_Best_SS_Pair 
 *
 * @Param: in_value
 * @Param: property
 * @Param: sort
 **********************************************************************/
void APool::Set_Best_SS_Pair(FloatVecVec &in_value, std::string property, std::string sort){
	if(_ss_pair.size()<=0){
		return;
	}

	IntVec   choosed_p;
	FloatVec real_value;
	FloatVec  aux_value;
	float     total_dis=-0.0000000000001;
	float     min_dis  =1000000000.0;

	for(int j=0;j<_num_ss_best;j++){
		choosed_p.push_back(-1);
	}

	IntVecVec out_comb;
	out_comb=Get_Nature_Combination(_ss_pair.size(),_num_ss_best);
	IntVecVec non_repeat_comb;

	for(int i=0;i<out_comb.size();i++){
		bool duplicate=false;
		for(int j=0;j<_num_ss_best;j++){
			for(int l=0;l<j;l++){
			    if(_ss_pair[out_comb[i][j]].First()->ID()== _ss_pair[out_comb[i][l]].First()->ID()){
			    	duplicate = true;
			    	break;
			    }
			    if(_ss_pair[out_comb[i][j]].First()->ID()== _ss_pair[out_comb[i][l]].Second()->ID()){
			    	duplicate = true;
			    	break;
			    }
			    if(_ss_pair[out_comb[i][j]].Second()->ID()== _ss_pair[out_comb[i][l]].First()->ID()){
			    	duplicate = true;
			    	break;
			    }
			    if(_ss_pair[out_comb[i][j]].Second()->ID()== _ss_pair[out_comb[i][l]].Second()->ID()){
			    	duplicate = true;
			    	break;
			    }
			}
			if(duplicate){
				break;
			}
		}
		if(duplicate){
			continue;
		}
		else{
			non_repeat_comb.push_back(out_comb[i]);
		}
	}




	for(int i=0;i<non_repeat_comb.size();i++){
		total_dis=-0.0000000000001;
		for(int j=0;j<_num_ss_best;j++){
			if(property=="mass"){
				real_value.push_back(_ss_pair[non_repeat_comb[i][j]].Combine()->M());
                                float last_real=*(real_value.end()-1);
				total_dis += std::pow(last_real-in_value[0][j],2);
			}
			else if(property=="mass_recoil"){
				real_value.push_back(_ss_pair[non_repeat_comb[i][j]].Combine()->M());
				_ss_pair[non_repeat_comb[i][j]].Set_Recoil(_detector_energy,_detector_angle);
				aux_value.push_back(_ss_pair[non_repeat_comb[i][j]].Recoil()->M());
                                float last_real=*(real_value.end()-1);
                                float last_aux =*(aux_value.end()-1);
				total_dis += std::pow(last_real-in_value[0][j],2)+ std::pow(last_aux-in_value[1][j],2);
			}
		}

		if(total_dis<min_dis){
			choosed_p=non_repeat_comb[i];
			min_dis=total_dis-0.000000000000000001;
		}

	}

	bool has_best=true;
	for(int j=0;j<_num_ds_best;j++){
		if(choosed_p[j]==-1){has_best=false;break;};
	}

	if(has_best){

		//sort in_value  -> sort  choosed_p;
		FloatVec sort_in_value  = in_value[0];
		IntVec   sort_choosed_p = choosed_p;
    	std::sort(sort_in_value.begin(),sort_in_value.end());

    	for(int k=0;k<sort_in_value.size();k++){
    		for(int j=0;j<in_value.size();j++){
    			if(sort_in_value[k]==in_value[0][j]){
    				sort_choosed_p[k]=choosed_p[j];
    			    continue;
    			}
    		}
    	}
		// now sort_choosed_p  store the value that need to be combined by the down sequence;
		// then we can put reconstructed value sort by down sequence and find correspoding choosed_p

		//sort combine_value -> real   choosed_p;
		FloatVec combine_value;
		FloatVec sort_combine_value ;
		// init combine_value/ sort_combine_value with   choosed pair invariant mass
    	for(int j=0;j<_num_ss_best;j++){
			combine_value.push_back(_ss_pair[choosed_p[j]].Combine()->M());
			sort_combine_value.push_back(_ss_pair[choosed_p[j]].Combine()->M());
		}

		IntVec   real_choosed_p = sort_choosed_p;
    	std::sort(sort_combine_value.begin(),sort_combine_value.end());

    	for(int k=0;k<sort_combine_value.size();k++){
    		for(int j=0;j<combine_value.size();j++){
    			if(sort_combine_value[k]==combine_value[j]){
    				real_choosed_p[k]=sort_choosed_p[j];
    			    continue;
    			}
    		}
    	}

    	for(int j=0;j<_num_ss_best;j++){
    		_ss_pair_choosed.push_back(APair(_ss_pair[real_choosed_p[j]].First (),_ss_pair[real_choosed_p[j]].Second())); 
    		_ss_pair_choosed[j].Add_Pair_Aux(_ss_pair[real_choosed_p[j]].Pair_Aux().first,_ss_pair[real_choosed_p[j]].Pair_Aux().second,_ss_pair[real_choosed_p[j]].Pair_Pos());
			_ss_pair_choosed[j].Set_Recoil(_detector_energy,_detector_angle);
		}
		_HasSSBest                = true;
	}

}




/**********************************************************************
 * @Name: Get_Best_SS_Pair 
 *
 * @Param: in_value
 * @Param: property
 * @Param: sort
 **********************************************************************/
void APool::Get_Best_SS_Pair(FloatVecVec &in_value, std::string property, std::string sort){
	//ShowMessage(2,"APool::Get_Best_SS_Pair, begin");
	_num_ss_best = in_value[0].size();
	if(_num_pool<2*_num_ss_best){
		return;
	}
	Set_Best_SS_Pair(in_value,property,sort);
	//ShowMessage(2,"APool::Get_Best_SS_Pair, finish Set_Best_SS_Pair");
	if(_HasSSBest){
		std::vector<int> best_pos;
		for(int j=0;j<_num_ss_best;j++){
			best_pos.push_back(_ss_pair_choosed[j].Pair_Aux().first);
			best_pos.push_back(_ss_pair_choosed[j].Pair_Aux().second);
		}

		//ShowMessage(2,"APool::Get_Best_SS_Pair, before Get_Best_Pair_Left");
		Get_Best_Pair_Left(_pool,_pool_ss_left,best_pos);
		//ShowMessage(2,"APool::Get_Best_SS_Pair, finish Get_Best_Pair_Left");
	}
	//ShowMessage(2,"APool::Get_Best_SS_Pair, end");
}


AParticle APool::Best_SS_Recoil(){

	AParticle recoil;
	if(_HasSSBest){
		if(_Has_Detector_Para){
			recoil=Get_Left(_detector_energy, _detector_angle,_ss_pair_choosed[0].Combine());
		}
		else{
			ShowMessage(2,"APool::Best_DS_Recoil,don't have detector energy!");
		}
	}
	return(recoil);
}



void APool::Get_SS_Choosed_JEP(){
	for(int i=0;i<_ss_pair_choosed.size();i++){
		_ss_pair_choosed[i].Get_JEP();
	}
}



/*****************************************************************************************
 * @name set ss pair 
 ******************************************************************************************/


void APool::Set_SS_Pair(){
	if(Pool_Num()<=0){
		return;
	}
	if(_ss_pair.size()!=0){
		_ss_pair.clear();
	}

	int k = 0;
	for(int i=0;i<_num_pool-1;i++){
		for(int j=i+1;j<_num_pool;j++){
			k++;
			APair ss_pair_aux(_pool[i],_pool[j]);
			ss_pair_aux.Add_Pair_Aux(i,j,k);
			_ss_pair.push_back(ss_pair_aux);
		}
	}
	Set_SS_Pair_Num();
}


/**********************************************************************
 * @Name: Get_Pool 
 **********************************************************************/
void APool::Get_DS_Pairs(){

	if( _num_first!=0 && _num_second!=0 ){
		Set_DS_Pair();
		_IsDSUsed=true;
	}
}

void APool::Get_SS_Pairs(){

	if( _num_pool!=0 ){
		Set_SS_Pair();
		_IsSSUsed=true;
	}
}




/*****************************************************************************************
 * @Name: Get_Best_Pair_Left 
 *
 * @Param: in
 * @Param: left
 * @Param: best1
 * @Param: best2
 *****************************************************************************************/
void APool::Get_Best_Pair_Left(AParticleType &in, AParticleType &left, std::vector<int> best_pos){
	//ShowMessage(2,"APool::Get_Best_Pair_Left, begin");
	left = in;

	//ShowMessage(2,"APool::Get_Best_Pair_Left, left size",left.size());
	std::stable_sort(best_pos.begin(),best_pos.end());
	reverse(best_pos.begin(),best_pos.end());

	//ShowMessage(2,"APool::Get_Best_Pair_Left, best_pos",best_pos.size());

	for(int i=0; i<best_pos.size();i++){
		//ShowMessage(2,"APool::Get_Best_Pair_Left, best_pos",i,best_pos[i]);
		left.erase(left.begin()+best_pos[i]);
	}
	//ShowMessage(2,"APool::Get_Best_Pair_Left, end");
}






std::ostream & operator<<(std::ostream & ostr, APool &pool){
	ostr<<"\n pool First is";
	ostr<<pool.First();
	ostr<<"pool Second is";
	ostr<<pool.Second();
	ostr<<"pool Pool is";
	ostr<<pool.Pool();
	if(pool.Is_DS_Used()){
		ostr<<"pair DS_Pair is";
		ostr<<pool.DS_Pair();
	}
	if(pool.Has_DS_Best()){
		ostr<<"pair Best_Pair is";
		ostr<<pool.Best_DS_Pair()[0];
		ostr<<"pair Best_Combine is";
		ostr<<pool.Best_DS_Combine();
	}


	if(pool.Is_SS_Used()){
		ostr<<"pair SS_Pair is";
		ostr<<pool.SS_Pair();
	}
	if(pool.Has_SS_Best()){
		ostr<<"pair Best_Pair is";
		ostr<<pool.Best_SS_Pair()[0];
		ostr<<"pair Best_Combine is";
		ostr<<pool.Best_SS_Combine();
	}
	return ostr;
}




std::ostream & operator<<(std::ostream & ostr, APool* pool){
	ostr<<"\npool First is";
	ostr<<pool->First();
	ostr<<"pool Second is";
	ostr<<pool->Second();
	ostr<<"pool Pool is";
	ostr<<pool->Pool();
	if(pool->Is_DS_Used()){
		ostr<<"pair DS_Pair is";
		ostr<<pool->DS_Pair();
	}
	if(pool->Is_SS_Used()){
		ostr<<"pair SS_Pair is";
		ostr<<pool->SS_Pair();
	}
	if(pool->Has_DS_Best()){
		ostr<<"pair Best_Pair is";
		ostr<<pool->Best_DS_Pair()[0];
		ostr<<"pair Best_Combine is";
		ostr<<pool->Best_DS_Combine();
	}
	if(pool->Has_SS_Best()){
		ostr<<"pair Best_Pair is";
		ostr<<pool->Best_SS_Pair()[0];
		ostr<<"pair Best_Combine is";
		ostr<<pool->Best_SS_Combine();
	}
	return ostr;
}

