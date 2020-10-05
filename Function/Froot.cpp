#include "Froot.h"

std::ostream & operator<<(std::ostream & ostr, const TLorentzVector &p){
	printf("\n"); // ]label the columns
	printf("%12s %12s %12s %12s %12s %12s %12s %12s \n","x","y","z","e", "rapidity", "phi", "pt","m" ); // label the columns
	printf("%12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  \n", p.Px(),p.Py(),p.Pz(),p.E(), p.Rapidity(),p.Phi(),p.Pt(),p.M());
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, const std::vector<TLorentzVector> & p){

	printf("\n"); // label the columns
	TLorentzVector total(0,0,0,0);
	if (p.size() == 0) return ostr;

	printf("%12s, %12s %12s %12s %12s %12s %12s %12s %12s \n","TLorentz#", "x","y","z","e", "rapidity", "phi", "pt","m" ); // label the columns
	for(unsigned int i=0;i<p.size();i++){
		printf("%12u, %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  \n", i, p[i].Px(),p[i].Py(),p[i].Pz(),p[i].E(), p[i].Rapidity(),p[i].Phi(),p[i].Pt(),p[i].M());
		total = total +p[i];
	}

	if(p.size()>1){
		printf("%12s, %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  \n","total", total.Px(),total.Py(),total.Pz(),total.E(), total.Rapidity(),total.Phi(),total.Pt(),total.M());
	}

	return ostr;
}


std::ostream & operator<<(std::ostream & ostr, const TVector3 &p){
	printf("\n"); // ]label the columns
	printf("%12s %12s %12s %12s \n","x","y","z","pt"); // label the columns
	printf("%12.5f %12.5f %12.5f %12.5f \n", p.Px(),p.Py(),p.Pz(),p.Pt());
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, const std::vector<TVector3> & p){

	printf("\n"); // label the columns
	TVector3 total(0,0,0);
	if (p.size() == 0) return ostr;

	printf("%12s, %12s %12s %12s %12s \n","TVector3#", "x","y","z","pt" ); // label the columns
	for(unsigned int i=0;i<p.size();i++){
		printf("%12u, %12.5f %12.5f %12.5f %12.5f \n",i, p[i].Px(),p[i].Py(),p[i].Pz(),p[i].Pt());
		total = total +p[i];
	}

	if(p.size()>1){
		printf("%12s, %12.5f %12.5f %12.5f %12.5f \n","total", total.Px(),total.Py(),total.Pz(),total.Pt());
	}

	return ostr;
}
