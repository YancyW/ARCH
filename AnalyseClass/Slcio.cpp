
#include "AnalyseClass/Slcio.h"
void ASlcio::Init(TChain* tree,bool judge){
	if(!judge){
		return;
	}

	tree->SetBranchAddress( "nmcp"  , &nmcp) ;	//CollID
	tree->SetBranchAddress( "mcori" , mcori ) ;	//CollID
	tree->SetBranchAddress( "mcpdg" , mcpdg ) ;	//Particle Data Group ID of the Particle
	tree->SetBranchAddress( "mcgst" , mcgst ) ;	//GeneratorStatus
	tree->SetBranchAddress( "mcsst" , mcsst ) ;	//SimulatorStatus
	tree->SetBranchAddress( "mcvtx" , mcvtx ) ;	//X-Coordinate of the Particle Vertex (Origin of the Particle)
	tree->SetBranchAddress( "mcvty" , mcvty ) ;	//Y-Coordinate of the Particle Vertex (Origin of the Particle)
	tree->SetBranchAddress( "mcvtz" , mcvtz ) ;	//Z-Coordinate of the Particle Vertex (Origin of the Particle)
	tree->SetBranchAddress( "mcepx" , mcepx ) ;	//X-Coordinate of the Particle EndPoint
	tree->SetBranchAddress( "mcepy" , mcepy ) ;	//Y-Coordinate of the Particle EndPoint
	tree->SetBranchAddress( "mcepz" , mcepz ) ;	//Z-Coordinate of the Particle EndPoint
	tree->SetBranchAddress( "mcmox" , mcmox ) ;	//X-Coordinate of the Particle Momentum at the Vertex
	tree->SetBranchAddress( "mcmoy" , mcmoy ) ;	//Y-Coordinate of the Particle Momentum at the Vertex
	tree->SetBranchAddress( "mcmoz" , mcmoz ) ;	//Z-Coordinate of the Particle Momentum at the Vertex
	tree->SetBranchAddress( "mcmas" , mcmas ) ;	//Particle mass
	tree->SetBranchAddress( "mcene" , mcene ) ;	//Particle Energy
	tree->SetBranchAddress( "mccha" , mccha ) ;	//Particle Charge
	tree->SetBranchAddress( "mctim" , mctim ) ;	//Time
	tree->SetBranchAddress( "mcspx" , mcspx ) ;	//X-Coordinate of the Particle Spin
	tree->SetBranchAddress( "mcspy" , mcspy ) ;	//Y-Coordinate of the Particle Spin
	tree->SetBranchAddress( "mcspz" , mcspz ) ;	//Z-Coordinate of the Particle Spin
	tree->SetBranchAddress( "mccf0" , mccf0 ) ;	//ColorFlow[0]
	tree->SetBranchAddress( "mccf1" , mccf1 ) ;	//ColorFlow[0]
	tree->SetBranchAddress( "mcpa0" , mcpa0 ) ;	//1st Parant index
	tree->SetBranchAddress( "mcpa1" , mcpa1 ) ;	//2nd Parant index
	tree->SetBranchAddress( "mcda0" , mcda0 ) ;	//1st Daughter index
	tree->SetBranchAddress( "mcda1" , mcda1 ) ;	//2nd Daughter index
	tree->SetBranchAddress( "mcda2" , mcda2 ) ;	//3rd Daughter index
	tree->SetBranchAddress( "mcda3" , mcda3 ) ;	//4th Daughter index
	tree->SetBranchAddress( "mcda4" , mcda4 ) ;	//5th Daughter index

	////		tree->SetBranchAddress( "nsth"  , &nsth ) ;	//Number of Tracker Hits per Entry
	////		tree->SetBranchAddress( "stori" , stori ) ;	//CollID
	////		tree->SetBranchAddress( "stci0" , stci0 ) ;	//CellID0
	////		tree->SetBranchAddress( "stci1" , stci1 ) ;	//CellID1
	////		tree->SetBranchAddress( "stpox" , stpox ) ;	//X-Coordinate of the Position
	////		tree->SetBranchAddress( "stpoy" , stpoy ) ;	//Y-Coordinate of the Position
	////		tree->SetBranchAddress( "stpoz" , stpoz ) ;	//Z-Coordinate of the Position
	////		tree->SetBranchAddress( "stedp" , stedp ) ;	//EDep
	////		tree->SetBranchAddress( "sttim" , sttim ) ;	//Time
	////		tree->SetBranchAddress( "stmox" , stmox ) ;	//X-Coordinate of the Momentum
	////		tree->SetBranchAddress( "stmoy" , stmoy ) ;	//Y-Coordinate of the Momentum
	////		tree->SetBranchAddress( "stmoz" , stmoz ) ;	//Z-Coordinate of the Momentum
	////		tree->SetBranchAddress( "stptl" , stptl ) ;	//Tracker Path length
	////		tree->SetBranchAddress( "stmcp" , stmcp ) ;	//MC Particle index who made the Hit

	////		tree->SetBranchAddress( "nsch"  , &nsch ) ;	//Number of Calorimeter Hits per Entry	  
	////		tree->SetBranchAddress( "scori" , scori ) ;	//CollID
	////		tree->SetBranchAddress( "scci0" , scci0 ) ;	//CellID0
	////		tree->SetBranchAddress( "scci1" , scci1 ) ;	//CellID1
	////		tree->SetBranchAddress( "scpox" , scpox ) ;	//X-Coordinate of the Position
	////		tree->SetBranchAddress( "scpoy" , scpoy ) ;	//Y-Coordinate of the Positio
	////		tree->SetBranchAddress( "scpoz" , scpoz ) ;	//Z-Coordinate of the Position
	////		tree->SetBranchAddress( "scene" , scene ) ;	//Energy deposition

	//Here the Branches for the RecoParticles are set
	tree->SetBranchAddress( "nrec",  &nrec ) ;
	tree->SetBranchAddress( "rcori", rcori ) ;
	tree->SetBranchAddress( "rccid", rccid ) ;
	tree->SetBranchAddress( "rctyp", rctyp ) ;
	tree->SetBranchAddress( "rccov", rccov ) ;
	tree->SetBranchAddress( "rcrpx", rcrpx ) ;
	tree->SetBranchAddress( "rcrpy", rcrpy ) ;
	tree->SetBranchAddress( "rcrpz", rcrpz ) ;
	tree->SetBranchAddress( "rcgpi", rcgpi ) ;
	tree->SetBranchAddress( "rcpiu", rcpiu ) ;
	tree->SetBranchAddress( "rcnpi", rcnpi ) ;
	tree->SetBranchAddress( "rcfpi", rcfpi ) ;
	tree->SetBranchAddress( "rcmox", rcmox ) ;
	tree->SetBranchAddress( "rcmoy", rcmoy ) ;
	tree->SetBranchAddress( "rcmoz", rcmoz ) ;
	tree->SetBranchAddress( "rcmas", rcmas ) ;
	tree->SetBranchAddress( "rcene", rcene ) ;
	tree->SetBranchAddress( "rccha", rccha ) ;
	tree->SetBranchAddress( "rcntr", rcntr ) ;
	tree->SetBranchAddress( "rcncl", rcncl ) ;
	tree->SetBranchAddress( "rcftr", rcftr ) ;

	tree->SetBranchAddress( "rcvts", rcvts ) ;
	tree->SetBranchAddress( "rcvte", rcvte ) ;
	tree->SetBranchAddress( "rccom", rccom ) ;

	tree->SetBranchAddress( "npid",  &npid ) ;
	tree->SetBranchAddress( "pityp", pityp ) ;
	tree->SetBranchAddress( "pipdg", pipdg ) ;
	tree->SetBranchAddress( "pillh", pillh ) ;
	tree->SetBranchAddress( "pialg", pialg ) ;

	//Branches for the LCRelation are set
	tree->SetBranchAddress( "r2mnrel",	&r2mnrel ) ;
	tree->SetBranchAddress( "r2mf",		r2mf ) ;
	tree->SetBranchAddress( "r2mt",		r2mt ) ;
	tree->SetBranchAddress( "r2mw",		r2mw ) ;
	tree->SetBranchAddress( "r2cnrel",	&r2cnrel ) ;
	tree->SetBranchAddress( "r2cf",		r2cf ) ;
	tree->SetBranchAddress( "r2ct",		r2ct ) ;
	tree->SetBranchAddress( "r2cw",		r2cw ) ;
	tree->SetBranchAddress( "r2tnrel",	&r2tnrel ) ;
	tree->SetBranchAddress( "r2tf",		r2tf ) ;
	tree->SetBranchAddress( "r2tt",		r2tt ) ;
	tree->SetBranchAddress( "r2tw",		r2tw ) ;
	tree->SetBranchAddress( "r2rnrel",	&r2rnrel ) ;
	tree->SetBranchAddress( "r2rf",		r2rf ) ;
	tree->SetBranchAddress( "r2rt",		r2rt ) ;
	tree->SetBranchAddress( "r2rw",		r2rw ) ;
}

void ASlcio::Clear(){
	//in futrue, I will change this array to be allocated array, and then there will be a release operation here.
	return;
}
