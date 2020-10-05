#include "Acomb_func.h"

bool Find_ximin(float *xi_min,float input1,float obj1,float input2,float obj2, 
		float *output1,float *output2)
{
	float xi=sqrt(pow(input1-obj1,2)+pow(input2-obj2,2));

	if(xi<*xi_min){
		*xi_min = xi;
		*output1 = input1;
		*output2 = input2;
		return(true);
	}
	return(false);

}
bool Combine2_direct(TLorentzVector mom1, TLorentzVector mom2,float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, float *mass_re){

	TLorentzVector addm(0,0,0,0);

	addm = mom1+mom2;
	float mass_comb=addm.M();
	float pt_comb  =addm.Pt();

	// mass window cut
	if( mass_comb< cut_mlow  || mass_comb > cut_mup ){
		return(false); 
	}
	if( pt_comb  < cut_ptlow || pt_comb   > cut_ptup ){
		return(false); 
	}
	*mass_re=mass_comb;
	return(true);
}



bool Combine2SameFS_TLorentzvector(CDraw &para, TH1 *comb, std::vector<TLorentzVector> &in,float obj_mass, float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, TLorentzVector &choosed){

	int num = in.size();
	int loop1,loop2;
	int count1 = -10,count2 = -10;
	float massclose=100000;
	float re_mass=100000.0;
	TLorentzVector mom1,mom2;
	bool judge;

	for(loop1=0;loop1<num-1;loop1++){
		for(loop2=loop1+1;loop2<num;loop2++){

			mom1 = in[loop1];
			mom2 = in[loop2];
			judge=Combine2_direct(mom1, mom2,cut_mlow,cut_mup, cut_ptlow, cut_ptup, &re_mass);
			if(judge && std::abs(re_mass-obj_mass)<std::abs(massclose-obj_mass)){
				count1 = loop1;
				count2 = loop2;
				massclose = re_mass;
			}
		}
	} 
	if(count1!=-10&& count2!=-10){
		std::vector<TLorentzVector> left;
		for(int i=0;i<num;i++){
			if(i!=count1&&i!=count2){
				left.push_back(in[i]);
			}
		}
		choosed=in[count1]+in[count2];
		in.clear();
		in=left;
	}
	else{return(false);}

	AFill_Plot(para,comb,massclose);
	return(true);
}


bool Combine2DifferentFS_TLorentzvector(CDraw &para, TH1 *comb, std::vector<TLorentzVector> in1,std::vector<TLorentzVector> &in2,float obj_mass, float cut_mlow, float cut_mup, float cut_ptlow, float cut_ptup, TLorentzVector &choosed){

	int num1 = in1.size(), num2=in2.size();
	int loop1,loop2;
	int count1 = -10,count2 = -10;
	float massclose=100000;
	float re_mass=100000.0;
	TLorentzVector mom1,mom2;
	bool judge;

	for(loop1=0;loop1<num1;loop1++){
		for(loop2=0;loop2<num2;loop2++){

			mom1 = in1[loop1];
			mom2 = in2[loop2];
			judge=Combine2_direct(mom1, mom2,cut_mlow,cut_mup, cut_ptlow, cut_ptup, &re_mass);
			if(judge && std::abs(re_mass-obj_mass)<std::abs(massclose-obj_mass)){
				count1 = loop1;
				count2 = loop2;
				massclose = re_mass;
			}
		}
	} 
	if(count1!=-10&& count2!=-10){
		choosed=in1[count1]+in2[count2];
	}
	else{return(false);}

	AFill_Plot(para,comb,massclose);
	return(true);
}
