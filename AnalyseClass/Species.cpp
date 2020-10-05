
#include "AnalyseClass/Species.h"


void ASpecies::get_particle_species(AParticleType &allparticle){
	for( int i = 0; i < allparticle.size(); i++ ){
		int    PID    = allparticle[i]->PID();
		int    aPID   = std::abs(PID); 
		if(aPID==12 || aPID==14 || aPID==16 ){   	// neutrino
			_species["inv"].push_back(allparticle[i]);
		}
		else if(PID == 11 ){  	// e-
			_species["e-"].push_back(allparticle[i]);
		}
		else if( PID == 13 ){  	// mu-
			_species["m-"].push_back(allparticle[i]);
		}
		else if( PID == 15 ){  	// tau-
			_species["tau-"].push_back(allparticle[i]);
		}
		else if( PID == -11 ){  	// e+
			_species["e+"].push_back(allparticle[i]);
		}
		else if( PID == -13 ){  	// mu+
			_species["m+"].push_back(allparticle[i]);
		}
		else if( PID == -15 ){  	// tau+
			_species["tau+"].push_back(allparticle[i]);
		}
		else if(abs(PID)==22){ 	// photon
			_species["photon"].push_back(allparticle[i]);
		}
		else if(aPID==23){  	// Z 
			_species["Z"].push_back(allparticle[i]);
		}
		else if(aPID==24){  	// W 
			_species["W"].push_back(allparticle[i]);
		}
		else if(aPID==25){  	// higgs 
			_species["Higgs"].push_back(allparticle[i]);
		}
		else if((aPID%1000>110&&aPID%1000<120)){  	// higgs 
			_species["Light I=1 Mesons, pi0"].push_back(allparticle[i]);
		}
		else if(aPID%1000>210&&aPID%1000<220){  	// higgs 
			_species["Light I=1 Mesons, pi+"].push_back(allparticle[i]);
		}
		else if((aPID%1000>220&&aPID%1000<230)||(aPID%1000>331&&aPID%1000<340)){  	// higgs 
			_species["Light I=0 Mesons, eta"].push_back(allparticle[i]);
		}
		else if((aPID%1000>310&&aPID%1000<320)){  	// higgs 
			_species["Strange Mesons, K0   "].push_back(allparticle[i]);
		}
		else if((aPID%1000>320&&aPID%1000<330)){  	// higgs 
			_species["Strange Mesons, K+   "].push_back(allparticle[i]);
		}
		else if((aPID%10000>410&&aPID%10000<420)){  	// higgs 
			_species["Charmed Mesons, D0   "].push_back(allparticle[i]);
		}
		else if((aPID%10000>420&&aPID%10000<430)){  	// higgs 
			_species["Charmed Mesons, D+   "].push_back(allparticle[i]);
		}
		else if((aPID%10000>510&&aPID%10000<520)||(aPID%10000>530&&aPID%10000<540)){  	// higgs 
			_species["Bottom Mesons, B0   "].push_back(allparticle[i]);
		}
		else if((aPID%10000>520&&aPID%10000<530)||(aPID%10000>540&&aPID%10000<550)){  	// higgs 
			_species["Bottom Mesons, B+   "].push_back(allparticle[i]);
		}
		else if((aPID%10000>441&&aPID%10000<450)){  	// higgs 
			_species["ccbar Mesons        "].push_back(allparticle[i]);
		}
		else if((aPID%10000>551&&aPID%10000<560)){  	// higgs 
			_species["ccbar Mesons        "].push_back(allparticle[i]);
		}
		else if((aPID%10000>1000&&aPID%10000<4000)){  	// higgs 
			_species["Light Baryons       "].push_back(allparticle[i]);
		}
		else if((aPID%10000>4000&&aPID%10000<5000)){  	// higgs 
			_species["Charmed Baryons     "].push_back(allparticle[i]);
		}
		else if((aPID%10000>5000&&aPID%10000<6000)){  	// higgs 
			_species["Bottom Baryons      "].push_back(allparticle[i]);
		}
		else{
			_species["other hadron"].push_back(allparticle[i]);
		}
	}

	setNum();
   // ShowMessage(2,"Species",_species);
    //ShowMessage(2,"Species num",_num);
}


void ASpecies::Init(){
	_species.clear();
	_num    .clear();
}

void ASpecies::Clear(){
	_species.clear();
	_num    .clear();
}





std::ostream & operator<<(std::ostream & ostr, ASpecies spe){
	ostr<<"\n";
	for(ASpeciesType::iterator it = spe.Species() .begin(); it!=spe.Species() .end(); ++it ){
		ostr<< it->first << " is:  " ;
		ostr<< it->second;
	}
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, ASpecies* spe){
	ostr<<"\n";
	for(ASpeciesType::iterator it = spe->Species().begin(); it!=spe->Species().end(); ++it ){
		ostr<< it->first << " is:  " << it->second;
	}
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, ASpeciesType spe){
	ostr<<"\n";
	for(ASpeciesType::iterator it = spe.begin(); it!=spe.end(); ++it ){
		ostr<< it->first << " is:  " << it->second;
	}
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, ASpeciesNumType spe){
	ostr<<"\n";
	for(ASpeciesNumType::iterator it = spe.begin(); it!=spe.end(); ++it ){
		ostr<< it->first << " num is:  " << it->second << std::endl;
	}
	return ostr;
}

