#include "Fdelphes.h"

std::ostream & operator<< (std::ostream & ostr, Jet* particle){
	printf("\n"); // label the columns
	printf("%12s %12s %12s %12s %12s \n", "rapidity", "phi", "pt","m","btag"); // label the columns
	printf("%12.5f %12.5f %12.5f %12.5f  %12i\n",  particle->Eta,particle->Phi,particle->PT,particle->Mass,particle->BTag);
	return ostr;
}


std::ostream & operator<<(std::ostream & ostr, const std::vector<Jet*> particles){

	if (particles.size() == 0) return ostr;

	printf("\n"); // label the columns
	printf("%7s %12s %12s %12s %12s %12s \n","jet #",  "rapidity", "phi", "pt","m","btag"); // label the columns
	for (unsigned int i = 0; i < particles.size(); i++) {
		printf("%5u %12.5f %12.5f %12.5f %12.5f %12i\n", i,  particles[i]->Eta,particles[i]->Phi,particles[i]->PT,particles[i]->Mass,particles[i]->BTag);

	}
	return ostr;
}



std::ostream & operator<< (std::ostream & ostr, Electron* particle){
	printf("\n"); // label the columns
	printf("%12s %12s %12s %12s  \n", "rapidity", "phi", "pt","charge"); // label the columns
	printf("%12.5f %12.5f %12.5f  %12i\n",  particle->Eta,particle->Phi,particle->PT,particle->Charge);
	return ostr;
}


std::ostream & operator<<(std::ostream & ostr, const std::vector<Electron*> particles){

	if (particles.size() == 0) return ostr;

	printf("\n"); // label the columns
	printf("%7s %12s %12s %12s %12s \n","jet #",  "rapidity", "phi", "pt","charge"); // label the columns
	for (unsigned int i = 0; i < particles.size(); i++) {
		printf("%5u %12.5f %12.5f %12.5f %12i\n", i,  particles[i]->Eta,particles[i]->Phi,particles[i]->PT,particles[i]->Charge);

	}
	return ostr;
}

std::ostream & operator<< (std::ostream & ostr, Muon* particle){
	printf("\n"); // label the columns
	printf("%12s %12s %12s %12s  \n", "rapidity", "phi", "pt","charge"); // label the columns
	printf("%12.5f %12.5f %12.5f  %12i\n",  particle->Eta,particle->Phi,particle->PT,particle->Charge);
	return ostr;
}


std::ostream & operator<<(std::ostream & ostr, const std::vector<Muon*> particles){

	if (particles.size() == 0) return ostr;

	printf("\n"); // label the columns
	printf("%7s %12s %12s %12s %12s \n","jet #",  "rapidity", "phi", "pt","charge"); // label the columns
	for (unsigned int i = 0; i < particles.size(); i++) {
		printf("%5u %12.5f %12.5f %12.5f %12i\n", i,  particles[i]->Eta,particles[i]->Phi,particles[i]->PT,particles[i]->Charge);

	}
	return ostr;
}

std::ostream & operator<< (std::ostream & ostr, Photon* particle){
	printf("\n"); // label the columns
	printf("%12s %12s %12s %12s  \n", "rapidity", "phi", "pt","E"); // label the columns
	printf("%12.5f %12.5f %12.5f  %12.5f\n",  particle->Eta,particle->Phi,particle->PT,particle->E);
	return ostr;
}


std::ostream & operator<<(std::ostream & ostr, const std::vector<Photon*> particles){

	if (particles.size() == 0) return ostr;

	printf("\n"); // label the columns
	printf("%7s %12s %12s %12s %12s \n","jet #",  "rapidity", "phi", "pt","E"); // label the columns
	for (unsigned int i = 0; i < particles.size(); i++) {
		printf("%5u %12.5f %12.5f %12.5f %12.5f\n", i,  particles[i]->Eta,particles[i]->Phi,particles[i]->PT,particles[i]->E);

	}
	return ostr;
}


std::ostream & operator<< (std::ostream & ostr, MissingET* particle){
	printf("\n"); // label the columns
	printf("%12s %12s %12s \n", "rapidity", "phi", "MET"); // label the columns
	printf("%12.5f %12.5f %12.5f  \n",  particle->Eta,particle->Phi,particle->MET);
	return ostr;
}


std::ostream & operator<<(std::ostream & ostr, const std::vector<MissingET*> particles){

	if (particles.size() == 0) return ostr;

	printf("\n"); // label the columns
	printf("%7s %12s %12s %12s  \n","jet #",  "rapidity", "phi", "pt"); // label the columns
	for (unsigned int i = 0; i < particles.size(); i++) {
		printf("%5u %12.5f %12.5f %12.5f \n", i,  particles[i]->Eta,particles[i]->Phi,particles[i]->MET);

	}
	return ostr;
}


std::ostream & operator<<(std::ostream & ostr, GenParticle* particles){

	printf("\n"); // label the columns
	printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s \n",  "Status", "PID", "px","py","pz","e", "rapidity", "phi", "pt","m","father","mother","son","daughter"); // label the columns
	printf("%12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %12i %12i %12i \n", particles->Status, particles->PID, particles->Px,particles->Py,particles->Pz,particles->E,particles->Eta,particles->Phi,particles->PT,particles->Mass,particles->M1,particles->M2,particles->D1,particles->D2);
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, const std::vector<GenParticle*> particles){

	if (particles.size() == 0) return ostr;

	printf("\n"); // label the columns
	printf("%7s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s \n","particle #","Status", "PID", "px","py","pz","e", "rapidity", "phi", "pt","m","father","mother","son","daughter"); //  
	for (unsigned int i = 0; i < particles.size(); i++) {
		printf("%5u %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %12i %12i %12i \n", i,particles[i]->Status, particles[i]->PID, particles[i]->Px,particles[i]->Py,particles[i]->Pz,particles[i]->E,particles[i]->Eta,particles[i]->Phi,particles[i]->PT,particles[i]->Mass,particles[i]->M1,particles[i]->M2,particles[i]->D1,particles[i]->D2);
	}
	return ostr;
}
