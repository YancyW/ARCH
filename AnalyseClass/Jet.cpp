#include "AnalyseClass/Jet.h"


/*****************************************************************************************
 *
 *           AJet 
 *
 **********************************************************************i******************/

/*****************************************************************************************
 * initialization 
 *****************************************************************************************/

AJet::AJet(){
	Init();
}

AJet::~AJet(){
	Clear();
}

/*****************************************************************************************
 * @Name: Init 
 *****************************************************************************************/
void AJet::Init(){
	_Has_Jet.Set();

	_num_consituents = 0;
	_num_jets        = 0;
	_num_tjet        = 0;
	_num_bjet        = 0;
	_num_cjet        = 0;
	_num_qjet        = 0;
	_num_tau         = 0;
	_num_gluon       = 0;

}


/*****************************************************************************************
 * @Name: Clear 
 *****************************************************************************************/
void AJet::Clear(){
	_fp_constituents.clear();
	_bquark.clear();
	_cquark.clear();
	_jet_vec.clear();
	_jets.clear();
	_tjet.clear();
	_bjet.clear();
	_cjet.clear();
	_qjet.clear();
	_taujet.clear();
	_gluonjet.clear();


	_jets_pool.Clear();
	_tjet_pool.Clear();
	_bjet_pool.Clear();
	_cjet_pool.Clear();
	_qjet_pool.Clear();
	_tau_pool.Clear();
	_gluon_pool.Clear();

}



void AJet::Clear_Ptr(){
	for(int i=0;i<_jets_pool.Pool_Num();i++){
		if(_jets_pool.Pool()[i]!=NULL) {_jets_pool.Pool()[i]->Rid_Instruct_ID();delete _jets_pool.Pool()[i];}
	}

}





/*****************************************************************************************
 * private function
 **********************************************************************i******************/

/*****************************************************************************************
 * @Name: findJetSpecies  
 **********************************************************************i******************/
void AJet::Find_Jet_Species(CDraw &para){
	para.debug.Message(2,98,"in AJet::Find_Jet_Species, begin");
	para.debug.Message(2,98,"in AJet::Find_Jet_Species, all bquark",_bquark);
	para.debug.Message(2,98,"in AJet::Find_Jet_Species, all cquark",_cquark);
	int k=0;
	for(int i=0;i<_jet_vec.size();i++){
		AParticle* par_tmp = new AParticle(_jet_vec[i],0.0,100);
		par_tmp->Get_Instruct_ID();
		if(Cut(par_tmp,para.jet.jets)){
			_jets_pool.Add_Pool(par_tmp);
		}
		else{
			delete par_tmp;
		}
	}


	for(int i=0;i<_jets_pool.Pool_Num();i++){
		_jets_pool._pool[i]->Set_Jet(_bquark,_cquark,para.jet.coneR,para.tag);

		if(_jets_pool._pool[i]->What_Jet_Name()=="Tjet"){
			if(Cut(_jets_pool._pool[i],para.jet.tjet)){
				_tjet_pool.Add_Pool(_jets_pool._pool[i]);
			}
		}
		else if(_jets_pool._pool[i]->What_Jet_Name()=="Bjet"){
			if(Cut(_jets_pool._pool[i],para.jet.bjet)){
				_bjet_pool.Add_Pool(_jets_pool._pool[i]);
			}
		}
		else if(_jets_pool._pool[i]->What_Jet_Name()=="Cjet"){
			if(Cut(_jets_pool._pool[i],para.jet.cjet)){
				_cjet_pool.Add_Pool(_jets_pool._pool[i]);
			}
		}
		else if(_jets_pool._pool[i]->What_Jet_Name()=="Qjet"){
			if(Cut(_jets_pool._pool[i],para.jet.qjet)){
				_qjet_pool.Add_Pool(_jets_pool._pool[i]);
			}
		}
		else if(_jets_pool._pool[i]->What_Jet_Name()=="Taujet"){
			if(Cut(_jets_pool._pool[i],para.jet.taujet)){
				_tau_pool.Add_Pool(_jets_pool._pool[i]);
			}
		}
		else if(_jets_pool._pool[i]->What_Jet_Name()=="Gluonjet"){
			if(Cut(_jets_pool._pool[i],para.jet.gluonjet)){
				_gluon_pool.Add_Pool(_jets_pool._pool[i]);
			}
		}
		else{
			ShowMessage(2,"Error: wrong jet type",i, _jets_pool._pool[i]->What_Jet_Name());
			exit(EXIT_FAILURE);
		}
	}
	_num_jets   = _jets_pool.Pool_Num();
	_num_tjet   = _tjet_pool.Pool_Num();
	_num_bjet   = _bjet_pool.Pool_Num();
	_num_cjet   = _cjet_pool.Pool_Num();
	_num_qjet   = _qjet_pool.Pool_Num();
	_num_tau    = _tau_pool .Pool_Num();
	_num_gluon  = _gluon_pool.Pool_Num();

	_jets_pool.Get_SS_Pairs();


	para.debug.Message(2,98,"in AJet::Find_Jet_Species, end");
}




/*****************************************************************************************
 * public function
 **********************************************************************i******************/



/*****************************************************************************************
 * output function
 **********************************************************************i******************/
int AJet::Num_Jets(){
	if(_Has_Jet.Exist()){return(_num_jets);}
	else{return(-100);}
}

int AJet::Num_TJet(){
	if(_Has_Jet.Exist()){return(_num_tjet);}
	else{return(-100);}
}

int AJet::Num_BJet(){
	if(_Has_Jet.Exist()){return(_num_bjet);}
	else{return(-100);}
}

int AJet::Num_CJet(){
	if(_Has_Jet.Exist()){return(_num_cjet);}
	else{return(-100);}
}

int AJet::Num_QJet(){
	if(_Has_Jet.Exist()){return(_num_qjet);}
	else{return(-100);}
}

int AJet::Num_Tau(){
	if(_Has_Jet.Exist()){return(_num_tau);}
	else{return(-100);}
}

int AJet::Num_Gluon(){
	if(_Has_Jet.Exist()){return(_num_gluon);}
	else{return(-100);}
}

PseudoJetVec  AJet::Jet_Vec(){
	return(_jet_vec);
}

AParticleType AJet::Jets(){
	return(_jets);
}

AParticleType AJet::Tjet(){
	return(_tjet);
}

AParticleType AJet::Bjet(){
	return(_bjet);
}

AParticleType AJet::Cjet(){
	return(_cjet);
}

AParticleType AJet::Qjet(){
	return(_qjet);
}

AParticleType AJet::Taujet(){
	return(_taujet);
}

AParticleType AJet::Gluonjet(){
	return(_gluonjet);
}


APool AJet::Jets_Pool(){
	return(_jets_pool);
}

APool AJet::TJet_Pool(){
	return(_tjet_pool);
}

APool AJet::BJet_Pool(){
	return(_bjet_pool);
}

APool AJet::CJet_Pool(){
	return(_cjet_pool);
}

APool AJet::QJet_Pool(){
	return(_qjet_pool);
}

APool AJet::Tau_Pool(){
	return(_tau_pool);
}

APool AJet::Gluon_Pool(){
	return(_gluon_pool);
}

bool AJet::Has_Jet(){
	return(_Has_Jet.Exist());
}

/*****************************************************************************************
 *  character   
 **********************************************************************i******************/

std::vector<float> AJet::Px(){
	std::vector<float> var;
	for(int i=0;i<_num_jets;i++){
		var.push_back(_jets_pool.Pool()[i]->Px());
	}
	return(var);
}

std::vector<float> AJet::Py(){
	std::vector<float> var;
	for(int i=0;i<_num_jets;i++){
		var.push_back(_jets_pool.Pool()[i]->Py());
	}
	return(var);
}

std::vector<float> AJet::Pz(){
	std::vector<float> var;
	for(int i=0;i<_num_jets;i++){
		var.push_back(_jets_pool.Pool() [i]->Pz());
	}
	return(var);
}

std::vector<float> AJet::E(){
	std::vector<float> var;
	for(int i=0;i<_num_jets;i++){
		var.push_back(_jets_pool.Pool() [i]->E());
	}
	return(var);
}

std::vector<float> AJet::Pt(){
	std::vector<float> var;
	for(int i=0;i<_num_jets;i++){
		var.push_back(_jets_pool.Pool() [i]->Pt());
	}
	return(var);
}

std::vector<float> AJet::Mass(){
	std::vector<float> var;
	for(int i=0;i<_num_jets;i++){
		var.push_back(_jets_pool.Pool() [i]->M());
	}
	return(var);
}
std::vector<float> AJet::CosTheta(){
	std::vector<float> var;
	for(int i=0;i<_num_jets;i++){
		var.push_back(_jets_pool.Pool() [i]->CosTheta());
	}
	return(var);
}


std::vector<float> AJet::Rap(){
	std::vector<float> var;
	for(int i=0;i<_num_jets;i++){
		var.push_back(_jets_pool.Pool() [i]->Y());
	}
	return(var);
}

std::vector<float> AJet::PID(){
	std::vector<float> var;
	for(int i=0;i<_num_jets;i++){
		var.push_back(_jets_pool.Pool() [i]->What_Jet_Type());
	}
	return(var);
}



/*****************************************************************************************
 * normal function 
 **********************************************************************i******************/


void AJet::Init_Jet_Constituents(AParticleType &in, AParticleType &_input_bquark, AParticleType &_input_cquark){
	_constituents = in;
	_num_consituents = _constituents.size();
	Clear();
	for(int i=0; i<_num_consituents;i++){
		_fp_constituents.push_back(_constituents[i]->FP());
	}
	for(int i=0; i<_input_bquark.size();i++){
		_bquark.push_back(_input_bquark[i]->FP());
	}
	for(int i=0; i<_input_cquark.size();i++){
		_cquark.push_back(_input_cquark[i]->FP());
	}
}

void AJet::Set_Jet(CDraw &para, AParticleType &in, AParticleType &_input_bquark, AParticleType &_input_cquark){
	Init_Jet_Constituents(in,_input_bquark, _input_cquark);

	para.debug.Message(2,98,"in AJet::setJet, the in particle number", in.size());
	if(para.jet.jet_alg_name=="eekt"){
		_jet_def = fastjet::JetDefinition(para.jet.jet_alg);
	}
	else if(para.jet.jet_alg_name=="eegenkt"){
		_jet_def = fastjet::JetDefinition(para.jet.jet_alg, para.jet.coneR,1);
	}
	else if(para.jet.jet_alg_name=="eegenantikt"){
		_jet_def = fastjet::JetDefinition(para.jet.jet_alg, para.jet.coneR,-1);
	}
	else{
		_jet_def = fastjet::JetDefinition(para.jet.jet_alg, para.jet.coneR);
	}
	para.debug.Message(2,98,"in AJet::setJet, jet para algorithm name", para.jet.jet_alg_name);
	para.debug.Message(2,98,"in AJet::setJet, jet para algorithm", para.jet.jet_alg);
	para.debug.Message(2,98,"in AJet::setJet, jet para coneR", para.jet.coneR);
	fastjet::ClusterSequence _cs( _fp_constituents, _jet_def );

	if(para.jet.sort_method=="pt"){
		if(para.jet.jets.JCUT_pt[0]){
			_jet_vec = fastjet::sorted_by_pt(_cs.inclusive_jets(para.jet.jets.CUT_ptd[0]));
		}
		else{
			_jet_vec = fastjet::sorted_by_pt(_cs.inclusive_jets(1.0));
		}
	}
	else if(para.jet.sort_method=="e"){
		if(para.jet.jets.JCUT_e[0]){
			_jet_vec = fastjet::sorted_by_E(_cs.inclusive_jets(para.jet.jets.CUT_ed[0]));
		}
		else{
			_jet_vec = fastjet::sorted_by_E(_cs.inclusive_jets(1.0));
		}
	}
	else if(para.jet.sort_method=="rap"){
		if(para.jet.jets.JCUT_eta[0]){
			_jet_vec = fastjet::sorted_by_rapidity(_cs.inclusive_jets(para.jet.jets.CUT_etad[0]));
		}
		else{
			_jet_vec = fastjet::sorted_by_E(_cs.inclusive_jets(-5.0));
		}
	}
	else{
		if(para.jet.jets.JCUT_pt[0]){
			_jet_vec = fastjet::sorted_by_pt(_cs.inclusive_jets(para.jet.jets.CUT_ptd[0]));
		}
		else{
			_jet_vec = fastjet::sorted_by_pt(_cs.inclusive_jets(1.0));
		}
	}

	para.debug.Message(2,98,"in AJet::setJet, jet size", _jet_vec.size());

	if(_jet_vec.size()>0){
		_Has_Jet.Set();
		Find_Jet_Species(para);
	}

	_jets_pool.Set_Detector_Para(para.detector.energy,para.detector.collider_angle);
	Find_All_Best_Jet(para.comb);
	return;
}


bool AJet::Cut(AParticle* par, CJet_cut &cut){
	if(cut.JCUT_pt.size()>0){
		float pt = par->Pt();
		if( cut.JCUT_pt  [0] == true ){
			if( pt     < cut.CUT_ptd  [0] || pt     > cut.CUT_ptu  [0] ){return(false);}
		}
	}
	if(cut.JCUT_e.size()>0){
		float e  = par->E();
		if( cut.JCUT_e   [0] == true ){
			if( e      < cut.CUT_ed   [0] || e      > cut.CUT_eu   [0] ){return(false);}
		} 
	}
	if(cut.JCUT_eta.size()>0){
		float eta= std::abs(par->Eta());
		if( cut.JCUT_eta [0] == true ){
			if( eta    < cut.CUT_etad [0] || eta    > cut.CUT_etau [0] ){return(false);}
		}
	}
	if(cut.JCUT_theta.size()>0){
		float costheta= std::abs(par->CosTheta());
		if( cut.JCUT_theta[0] == true ){
			if( costheta< cut.CUT_thetad [0] || costheta > cut.CUT_thetau [0] ){return(false);}
		}
	}
	return(true);
}

/*
   bool AJet::Cut(fastjet::PseudoJet* par, CJet_cut &cut){
   float pt = par->pt();
   if( cut.JCUT_pt  [0] == true && ( pt     < cut.CUT_ptd  [0] || pt     > cut.CUT_ptu  [0] )){return(false);}
   float e  = par->e();
   if( cut.JCUT_e   [0] == true && ( e      < cut.CUT_ed   [0] || e      > cut.CUT_eu   [0] )){return(false);}
   float eta= std::abs(par->eta());
   if( cut.JCUT_eta [0] == true && ( eta    < cut.CUT_etad [0] || eta    > cut.CUT_etau [0] )){return(false);}
   return(true);
   }
   */



void AJet::Find_All_Best_Jet(CCombine &para_comb){

	//ShowMessage(2,"in AJet::Find_All_Best_Jet, begin");
	FloatVecVec in_value;
	in_value.push_back(para_comb.jets.CUT_massr);
	in_value.push_back(para_comb.jets.CUT_mass_relate);
	_jets_pool.Get_Best_SS_Pair(in_value,"mass_recoil","sort");
	_jets_pool.Get_SS_Choosed_JEP();
	//ShowMessage(2,"in AJet::Find_All_Best_Jet, end");
}

/*****************************************************************************************
 *  print 
 **********************************************************************i******************/

std::ostream & operator<<(std::ostream & ostr, AJet& jet){
	//	ostr << jet.Jets();
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, AJet* jet){
	//	ostr << jet->Jets();
	return ostr;
}

