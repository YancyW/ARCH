#include "Ffastjet.h"



std::ostream & operator<<(std::ostream & ostr, const fastjet::PseudoJet & jets){
	double r=pow(jets.rap(),2)+pow(jets.phi(),2);
	printf("\n"); // ]label the columns
	if (jets.has_area()) {
		if (jets.has_user_info()) {
			printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s \n","PID","charge", "x","y","z","e", "rapidity", "phi", "pt","m", "btag","area","R"); // label the columns
			printf("%12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  %12i %12.5f %12.5f\n", jets.user_info<PseudoJetInfo>().PID, jets.user_info<PseudoJetInfo>().Charge, jets.px(),jets.py(),jets.pz(),jets.e(), jets.rap(),jets.phi(),jets.perp(),jets.m(),0,(jets.has_area() ? jets.area() : 0.0 ),r);
		}
		else{
			printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s\n","PID","charge", "x","y","z","e", "rapidity", "phi", "pt","m","btag","area","R"); // label the columns
			printf("%12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  %12i %12.5f %12.5f\n", 0, 0, jets.px(),jets.py(),jets.pz(),jets.e(), jets.rap(),jets.phi(),jets.perp(),jets.m(),0,(jets.has_area() ? jets.area() : 0.0 ),r);
		}
	}
	else{
		if (jets.has_user_info()) {
			printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s\n","PID","charge", "x","y","z","e", "rapidity", "phi", "pt","m","btag","area","R"); // label the columns
			printf("%12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  %12i %12.5f %12.5f\n", jets.user_info<PseudoJetInfo>().PID, jets.user_info<PseudoJetInfo>().Charge, jets.px(),jets.py(),jets.pz(),jets.e(), jets.rap(),jets.phi(),jets.perp(),jets.m(),0,0.0,r);
		}
		else{
			printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s\n","PID","charge", "x","y","z","e", "rapidity", "phi", "pt","m","btag","area","R"); // label the columns
			printf("%12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %12.5f %12.5f\n", 0, 0, jets.px(),jets.py(),jets.pz(),jets.e(), jets.rap(),jets.phi(),jets.perp(),jets.m(),0,0.0,r);
		}

	}
	return ostr;
}












std::ostream & operator<<(std::ostream & ostr, const std::vector<fastjet::PseudoJet> & jets){

	printf("\n"); // label the columns
	fastjet::PseudoJet total(0,0,0,0);
	if (jets.size() == 0) return ostr;
	const fastjet::contrib::NjettinessExtras * extras = fastjet::contrib::njettiness_extras(jets[0]);

	double r;
	if (jets[0].has_area()) {
		if (extras == NULL) {
			printf("%7s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s\n","jet #", "PID","charge", "x","y","z","e", "rapidity", "phi", "pt","m","btag","area","R"); // label the columns
			for (unsigned int i = 0; i < jets.size(); i++) {
				r=pow(jets[i].rap(),2)+pow(jets[i].phi(),2);
				if (jets[i].has_user_info()) {
					printf("%7u %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  %12i %12.5f %12.5f\n", i, jets[i].user_info<PseudoJetInfo>().PID, jets[i].user_info<PseudoJetInfo>().Charge, jets[i].px(),jets[i].py(),jets[i].pz(),jets[i].e(), jets[i].rap(),jets[i].phi(),jets[i].perp(),jets[i].m(),jets[i].user_index(),(jets[i].has_area() ? jets[i].area() : 0.0 ),r);
				}
				else{
					printf("%7u %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  %12i %12.5f %12.5f\n", i, 0, 0,jets[i].px(),jets[i].py(),jets[i].pz(),jets[i].e(), jets[i].rap(),jets[i].phi(),jets[i].perp(),jets[i].m(),jets[i].user_index(),(jets[i].has_area() ? jets[i].area() : 0.0 ),r);
				}
				total += jets[i];
			}
			if(jets.size()>1){
				printf("%7s %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %12.5f  %12.5f\n", "total", 0, 0, total.px(),total.py(),total.pz(),total.e(), total.rap(),total.phi(),total.perp(),total.m(),total.user_index(),(total.has_area() ? total.area() : 0.0 ),0.0);
			}
		}
		else {
			printf("%7s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s  %12s %12s  %12s\n","jet #", "PID","charge", "x","y","z","e", "rapidity", "phi", "pt","m", "btag","subTau", "area","R"); // label the columns
			for (unsigned int i = 0; i < jets.size(); i++) {
				r=pow(jets[i].rap(),2)+pow(jets[i].phi(),2);
				if (jets[i].has_user_info()) {
					printf("%7u %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  %12i %10.6f %12.5f %12.5f\n", i, jets[i].user_info<PseudoJetInfo>().PID, jets[i].user_info<PseudoJetInfo>().Charge, jets[i].px(),jets[i].py(),jets[i].pz(),jets[i].e(), jets[i].rap(),jets[i].phi(),jets[i].perp(),jets[i].m(),jets[i].user_index(),extras->subTau(jets[i]),(jets[i].has_area() ? jets[i].area() : 0.0 ),r);
				}
				else{
					printf("%7u %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  %12i %10.6f %12.5f %12.5f\n", i, 0,0, jets[i].px(),jets[i].py(),jets[i].pz(),jets[i].e(), jets[i].rap(),jets[i].phi(),jets[i].perp(),jets[i].m(),jets[i].user_index(),extras->subTau(jets[i]),(jets[i].has_area() ? jets[i].area() : 0.0 ),r);
				}
				total += jets[i];
			}   
			if(jets.size()>1){
				printf("%7s %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  %12i %10.6f %12.5f %12.5f\n", "total", 0, 0, total.px(),total.py(),total.pz(),total.e(), total.rap(),total.phi(),total.perp(),total.m(),total.user_index(),extras->totalTau(),(total.has_area() ? total.area() : 0.0 ),0.0);
			}
		}
	} 
	else {
		if (extras == NULL) {
			printf("%7s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s\n","jet #", "PID","charge", "x","y","z","e", "rapidity", "phi", "pt","m", "btag","R"); // label the columns
			for (unsigned int i = 0; i < jets.size(); i++) {
				r=pow(jets[i].rap(),2)+pow(jets[i].phi(),2);
				if (jets[i].has_user_info()) {
					printf("%7u %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %12.5f\n", i, jets[i].user_info<PseudoJetInfo>().PID, jets[i].user_info<PseudoJetInfo>().Charge, jets[i].px(),jets[i].py(),jets[i].pz(),jets[i].e(), jets[i].rap(),jets[i].phi(),jets[i].perp(),jets[i].m(),jets[i].user_index(),r);
				}
				else{
					printf("%7u %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %12.5f\n", i, 0,0, jets[i].px(),jets[i].py(),jets[i].pz(),jets[i].e(), jets[i].rap(),jets[i].phi(),jets[i].perp(),jets[i].m(),jets[i].user_index(),r);
				}
				total += jets[i];
			}
			if(jets.size()>1){
				printf("%7s %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %12.5f\n", "total", 0, 0, total.px(),total.py(),total.pz(),total.e(), total.rap(),total.phi(),total.perp(),total.m(),total.user_index(),0.0);
			}
		}
		else {
			printf("%7s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s %12s\n","jet #", "PID","charge", "x","y","z","e", "rapidity", "phi", "pt","m", "btag","subTau","R"); // label the columns
			for (unsigned int i = 0; i < jets.size(); i++) {
				r=pow(jets[i].rap(),2)+pow(jets[i].phi(),2);
				if (jets[i].has_user_info()) {
					printf("%7u %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %10.6f %12.5f\n", i, jets[i].user_info<PseudoJetInfo>().PID, jets[i].user_info<PseudoJetInfo>().Charge, jets[i].px(),jets[i].py(),jets[i].pz(),jets[i].e(), jets[i].rap(),jets[i].phi(),jets[i].perp(),jets[i].m(),jets[i].user_index(),extras->subTau(jets[i]),r);
				}
				else{
					printf("%7u %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12i %10.6f %12.5f\n", i, 0,0, jets[i].px(),jets[i].py(),jets[i].pz(),jets[i].e(), jets[i].rap(),jets[i].phi(),jets[i].perp(),jets[i].m(),jets[i].user_index(),extras->subTau(jets[i]),r);
				}
				total += jets[i];

			}   
			if(jets.size()>1){
				printf("%7s %12i %12i %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f %12.5f  %12i %10.6f %12.5f\n", "total", 0, 0, total.px(),total.py(),total.pz(),total.e(), total.rap(),total.phi(),total.perp(),total.m(),total.user_index(),extras->totalTau(),0.0);
			}
		}
	}

	return ostr;

}


void PrintTopJet(const fastjet::PseudoJet tagged) {
	printf("\n"); // label the columns
	std::cout << "Found top substructure from the hardest jet:"                                       << std::endl;
	std::cout << "  top candidate:     " << tagged                                                    << std::endl;
	std::cout << "  |_ W   candidate:  " << tagged.structure_of<fastjet::JHTopTagger>().W()           << std::endl;
	std::cout << "  |  |_  W subjet 1: " << tagged.structure_of<fastjet::JHTopTagger>().W1()          << std::endl;
	std::cout << "  |  |_  W subjet 2: " << tagged.structure_of<fastjet::JHTopTagger>().W2()          << std::endl;
	std::cout << "  |  cos(theta_W) =  " << tagged.structure_of<fastjet::JHTopTagger>().cos_theta_W() << std::endl;
	std::cout << "  |_ non-W subjet:   " << tagged.structure_of<fastjet::JHTopTagger>().non_W()       << std::endl;
}



void PrintJets(const std::vector <fastjet::PseudoJet >& jets) {

	std::string commentStr = "";
	// gets extras information
	if (jets.size() == 0) return;
	const fastjet::contrib::NjettinessExtras * extras = fastjet::contrib::njettiness_extras(jets[0]);

	// bool useExtras = true;
	bool useExtras = (extras != NULL);
	bool useArea = jets[0].has_area();
	bool useConstit = jets[0].has_constituents();

	// define nice tauN header
	int N = jets.size();
	std::stringstream ss(""); 
	ss << "tau" << N; 
	std::string tauName = ss.str();

	std::cout  <<  std::fixed <<  std::right;

	std::cout  << commentStr 
		<<   std::setw(5)  << "jet #" << "   "
		<<   std::setw(10) << "rap"
		<<   std::setw(10) << "phi"
		<<   std::setw(11) << "pt"
		<<   std::setw(11) << "m"
		<<   std::setw(11) << "e";
	if (useConstit)  std::cout  <<  std::setw(11) << "constit";
	if (useExtras)   std::cout  <<  std::setw(14) << tauName;
	if (useArea)     std::cout  <<  std::setw(10) << "area";
	std::cout  <<  std::endl;

	fastjet::PseudoJet  total(0,0,0,0);
	int total_constit = 0;

	// print out individual jet information
	for (unsigned i = 0; i < jets.size(); i++) {
		std::cout  << commentStr     <<  std::setw(5)  << i+1  << "   "
			<<   std::setprecision(4) <<  std::setw(10) << jets[i].rap()
			<<   std::setprecision(4) <<  std::setw(10) << jets[i].phi()
			<<   std::setprecision(4) <<  std::setw(11) << jets[i].perp()
			<<   std::setprecision(4) <<  std::setw(11) <<  std::max(jets[i].m(),0.0) // needed to fix -0.0 issue on some compilers.
			<<   std::setprecision(4) <<  std::setw(11) << jets[i].e();
		if (useConstit)  std::cout  <<  std::setprecision(4) <<  std::setw(11) << jets[i].constituents().size();
		if (useExtras)   std::cout  <<  std::setprecision(6) <<  std::setw(14) <<  std::max(extras->subTau(jets[i]),0.0);
		if (useArea)     std::cout  <<  std::setprecision(4) <<  std::setw(10) << (jets[i].has_area() ? jets[i].area() : 0.0 );
		std::cout  <<  std::endl;
		total += jets[i];
		if (useConstit) total_constit += jets[i].constituents().size();
	}

	// print out total jet
	if (useExtras) {
		double beamTau = extras->beamTau();

		if (beamTau > 0.0) {
			std::cout  << commentStr <<  std::setw(5) << " beam" << "   "
				<<  std::setw(10) << ""
				<<  std::setw(10) << ""
				<<  std::setw(11) << ""
				<<  std::setw(11) << ""
				<<  std::setw(11) << ""
				<<  std::setw(11) << ""
				<<  std::setw(14) <<  std::setprecision(6) << beamTau
				<<  std::endl;
		}

		std::cout  << commentStr <<  std::setw(5) << "total" << "   "
			<<  std::setprecision(4) <<  std::setw(10) << total.rap()
			<<  std::setprecision(4) <<  std::setw(10) << total.phi()
			<<  std::setprecision(4) <<  std::setw(11) << total.perp()
			<<  std::setprecision(4) <<  std::setw(11) <<  std::max(total.m(),0.0) // needed to fix -0.0 issue on some compilers.
			<<  std::setprecision(4) <<  std::setw(11) << total.e();
		if (useConstit)  std::cout  <<  std::setprecision(4) <<  std::setw(11) << total_constit;
		if (useExtras)   std::cout  <<  std::setprecision(6) <<  std::setw(14) << extras->totalTau();
		if (useArea)     std::cout  <<  std::setprecision(4) <<  std::setw(10) << (total.has_area() ? total.area() : 0.0);
		std::cout  <<  std::endl;
	}

}


void PrintAxes(const std::vector <fastjet::PseudoJet >& jets) {

	std::string commentStr = "";

	// gets extras information
	if (jets.size() == 0) return;
	const fastjet::contrib::NjettinessExtras * extras = fastjet::contrib::njettiness_extras(jets[0]);

	// bool useExtras = true;
	bool useExtras = (extras != NULL);
	bool useArea = jets[0].has_area();

	// define nice tauN header
	int N = jets.size();
	std::stringstream ss(""); 
	ss << "tau" << N; 
	std::string tauName = ss.str();

	std::cout  <<  std::fixed <<  std::right;

	std::cout  << commentStr <<  std::setw(5) << "jet #" << "   "
		<<   std::setw(10) << "rap"
		<<   std::setw(10) << "phi"
		<<   std::setw(11) << "pt"
		<<   std::setw(11) << "m"
		<<   std::setw(11) << "e";
	if (useExtras)  std::cout  <<  std::setw(14) << tauName;
	if (useArea)  std::cout  <<  std::setw(10) << "area";
	std::cout  <<  std::endl;

	fastjet::PseudoJet  total(0,0,0,0);

	// print out individual jet information
	for (unsigned i = 0; i < jets.size(); i++) {
		std::cout  << commentStr <<  std::setw(5) << i+1  << "   "
			<<  std::setprecision(4) <<   std::setw(10) << jets[i].rap()
			<<  std::setprecision(4) <<   std::setw(10) << jets[i].phi()
			<<  std::setprecision(4) <<   std::setw(11) << jets[i].perp()
			<<  std::setprecision(4) <<   std::setw(11) <<  std::max(jets[i].m(),0.0) // needed to fix -0.0 issue on some compilers.
			<<  std::setprecision(4) <<   std::setw(11) << jets[i].e();
		if (useExtras)  std::cout  <<  std::setprecision(6) <<   std::setw(14) <<  std::max(extras->subTau(jets[i]),0.0);
		if (useArea)  std::cout  <<  std::setprecision(4) <<  std::setw(10) << (jets[i].has_area() ? jets[i].area() : 0.0 );
		std::cout  <<  std::endl;
		total += jets[i];
	}

	// print out total jet
	if (useExtras) {
		double beamTau = extras->beamTau();

		if (beamTau > 0.0) {
			std::cout  << commentStr <<  std::setw(5) << " beam" << "   "
				<<   std::setw(10) << ""
				<<   std::setw(10) << ""
				<<   std::setw(11) << ""
				<<   std::setw(11) << ""
				<<   std::setw(11) << ""
				<<   std::setw(14) <<  std::setprecision(6) << beamTau
				<<  std::endl;
		}

		std::cout  << commentStr <<  std::setw(5) << "total" << "   "
			<<   std::setprecision(4) <<  std::setw(10) << total.rap()
			<<   std::setprecision(4) <<  std::setw(10) << total.phi()
			<<   std::setprecision(4) <<  std::setw(11) << total.perp()
			<<   std::setprecision(4) <<  std::setw(11) <<  std::max(total.m(),0.0) // needed to fix -0.0 issue on some compilers.
			<<   std::setprecision(4) <<  std::setw(11) << total.e()
			<<   std::setprecision(6) <<  std::setw(14) << extras->totalTau();
		if (useArea)  std::cout  <<  std::setprecision(4) <<  std::setw(10) << (total.has_area() ? total.area() : 0.0);
		std::cout  <<  std::endl;
	}

}

void PrintJetsWithComponents(const std::vector < fastjet::PseudoJet >& jets) {

	std::string commentStr = "";

	bool useArea = jets[0].has_area();

	// define nice tauN header
	int N = jets.size();
	std::stringstream ss(""); 
	ss << "tau" << N; 
	std::string tauName = ss.str();

	std::cout  <<  std::fixed <<  std::right;

	std::cout  << commentStr <<  std::setw(5) << "jet #" << "   "
		<<   std::setw(10) << "rap"
		<<   std::setw(10) << "phi"
		<<   std::setw(11) << "pt"
		<<   std::setw(11) << "m"
		<<   std::setw(11) << "e";
	if (jets[0].has_constituents())  std::cout  <<   std::setw(11) << "constit";
	std::cout  <<  std::setw(14) << tauName;
	if (useArea)  std::cout  <<  std::setw(10) << "area";
	std::cout  <<  std::endl;

	fastjet::PseudoJet  total(0,0,0,0);
	double total_tau = 0;
	int total_constit = 0;


	// print out individual jet information
	for (unsigned i = 0; i < jets.size(); i++) {
		double thisTau = jets[i].structure_of<fastjet::contrib::TauComponents>().tau();

		std::cout << commentStr     <<  std::setw(5)  << i+1  << "   "
			<< std::setprecision(4) <<  std::setw(10) << jets[i].rap()
			<< std::setprecision(4) <<  std::setw(10) << jets[i].phi()
			<< std::setprecision(4) <<  std::setw(11) << jets[i].perp()
			<< std::setprecision(4) <<  std::setw(11) << std::max(jets[i].m(),0.0) // needed to fix -0.0 issue on some compilers.
			<< std::setprecision(4) <<  std::setw(11) << jets[i].e();
		if (jets[i].has_constituents()) std::cout << std::setprecision(4) << std::setw(11) << jets[i].constituents().size();
		std::cout << std::setprecision(6) <<  std::setw(14) << std::max(thisTau,0.0);
		if (useArea) std::cout << std::setprecision(4) << std::setw(10) << (jets[i].has_area() ? jets[i].area() : 0.0 );
		std::cout << std::endl;
		total += jets[i];
		total_tau += thisTau;
		if (jets[i].has_constituents()) total_constit += jets[i].constituents().size();
	}

	std::cout << commentStr << std::setw(5) << "total" << "   "
		<< std::setprecision(4) << std::setw(10) << total.rap()
		<< std::setprecision(4) << std::setw(10) << total.phi()
		<< std::setprecision(4) << std::setw(11) << total.perp()
		<< std::setprecision(4) << std::setw(11) << std::max(total.m(),0.0) // needed to fix -0.0 issue on some compilers.
		<< std::setprecision(4) << std::setw(11) << total.e();
	if (jets[0].has_constituents()) std::cout << std::setprecision(4)  <<  std::setw(11) << total_constit;
	std::cout <<  std::setprecision(6) << std::setw(14) << total_tau;
	if (useArea) std::cout << std::setprecision(4) << std::setw(10) << (total.has_area() ? total.area() : 0.0);
	std::cout << std::endl;

}




bool JudgeBtag(fastjet::PseudoJet jet){
	int PID= std::abs(jet.user_info<PseudoJetInfo>().PID);
	if(PID>500 && PID <600){
		return(true);
	}
	if(PID>5000 && PID <6000){
		return(true);
	}
	//choose 1500-1600
	if((PID%1000)>500 && (PID%1000) <600){
		return(true);
	}
	//choose 11500-1600
	if((PID%10000)>5000 && (PID%10000) <6000){
		return(true);
	}
	return(false);
}
