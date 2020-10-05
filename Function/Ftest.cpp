#include"Ftest.h"

void display(IntVecIter &begin, IntVecIter &end, IntVecVec &store){
//     for (vii it=begin;it!=end;++it){
//   	std::cout<<*it;
//   std::cout<<std::endl;
     IntVec tmp;
	 for (IntVecIter it=begin;it!=end;++it){
		 tmp.push_back(*it);
	 }
	 store.push_back(tmp);
}

IntVecVec Get_Nature_Combination(int tot_num, int get_num){
    IntVec tot;
    IntVec get;
	IntVecVec outcomb;
	for(int i=0;i<tot_num;i++){
		tot.push_back(i);
	}
	for(int i=0;i<get_num;i++){
		get.push_back(i);
	}
	recursive_combination(tot.begin (),tot.end(),0,
			get.begin(),get.end(),0,tot_num-get_num,display,outcomb);
	return(outcomb);
}



void Test_Function(CDraw &para){
    IntVecVec out_comb;
	out_comb=Get_Nature_Combination(6,2);
	std::cout<<out_comb<<std::endl;
}

