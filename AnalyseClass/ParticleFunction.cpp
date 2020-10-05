#include "AnalyseClass/ParticleFunction.h"

AParticle Get_Sum(AParticleType in){
	int num=in.size();
	TLorentzVector VS(0,0,0,0);

	for(int i=0;i<num;i++){
		VS += in[i]->P(); 
	}
	AParticle pnew(VS,0,0);
	return(pnew);
}

AParticle Get_SumSpecific(AParticleType in, AParticleType choosed){
	AParticleType need;
	int num1=in.size();
	int num2=choosed.size();
	for(int i=0;i<num1;i++){
		bool judge=false;
		for(int j=0;j<num2;j++){
			if(in[i]==choosed[j]){
				judge = true;
				break;
			}
		}
		if(judge == false){
			need.push_back(in[i]);
		}
	}
	return(Get_Sum(need));
}

AParticle Get_Left(float energy, float angle, AParticle* in){
	AParticle  Collider = AParticle(energy*std::sin(angle),0,0,energy);
	AParticle  Left = Collider-*in;
	return(Left);
}

AParticle Get_Left(float energy, float angle, AParticleType in){
	AParticle  sum = Get_Sum(in);
	AParticle  Collider = AParticle(energy*std::sin(angle),0,0,energy);
	AParticle  Left = Collider-sum;
	return(Left);
}
