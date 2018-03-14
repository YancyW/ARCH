#include "libstructure.h" 

TH1* Get_Class_ptr(CDraw &para, MyPlots *plots,std::string class_name, std::string observe_name,int array_num){
	TH1* h1;

	if(class_name=="jet"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fJetnum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_jets){
			h1 = plots->fJetPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_jets){
			h1 = plots->fJetY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr jet");
			exit(0);
		}
	}

	if(class_name=="bjet"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fBJetnum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_bjet){
			h1 = plots->fBJetPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_bjet){
			h1 = plots->fBJetY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr bjet");
			exit(0);
		}
	}

	if(class_name=="cjet"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fCJetnum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_cjet){
			h1 = plots->fCJetPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_cjet){
			h1 = plots->fCJetY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr cjet");
			exit(0);
		}
	}


	if(class_name=="qjet"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fQJetnum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_qjet){
			h1 = plots->fQJetPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_qjet){
			h1 = plots->fQJetY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr qjet");
			exit(0);
		}
	}

	if(class_name=="taujet"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fTauJetnum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_taujet){
			h1 = plots->fTauJetPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_taujet){
			h1 = plots->fTauJetY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr taujet");
			exit(0);
		}
	}

	if(class_name=="untagjet"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fUJetnum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_jets){
			h1 = plots->fUJetPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_jets){
			h1 = plots->fUJetY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr utagjet");
			exit(0);
		}
	}

	if(class_name=="lep"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fLepnum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_lep){
			h1 = plots->fLepPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_lep){
			h1 = plots->fLepY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr elec");
			exit(0);
		}
	}


	if(class_name=="elec"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fElecnum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_elec){
			h1 = plots->fElectronPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_elec){
			h1 = plots->fElectronY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr elec");
			exit(0);
		}
	}

	if(class_name=="muon"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fMuonnum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_muon){
			h1 = plots->fMuonPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_muon){
			h1 = plots->fMuonY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr muon");
			exit(0);
		}
	}

	if(class_name=="tau"){
		if(observe_name=="number" && array_num==0){
			h1 = plots->fTaunum;
		}
		else if(observe_name=="pt" && array_num<=para.signal.NUM_tau){
			h1 = plots->fTauPT[array_num];
		}
		else if(observe_name=="y" && array_num<=para.signal.NUM_tau){
			h1 = plots->fTauY[array_num];
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr tau");
			exit(0);
		}
	}

	if(class_name=="met"){
		if(observe_name=="et" && array_num<=0){
			h1 = plots->fMissingET;
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr met");
			exit(0);
		}
	}

	if(class_name=="ht"){
		if(observe_name=="" && array_num<=0){
			h1 = plots->fHT;
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr ht");
			exit(0);
		}
	}

	if(class_name=="comb"){
		if(observe_name=="1m" && array_num<=0){
			h1 = plots->fcomb1M;
		}
		else if(observe_name=="2m" && array_num<=0){
			h1 = plots->fcomb2M;
		}
		else if(observe_name=="3m" && array_num<=0){
			h1 = plots->fcomb3M;
		}
		else if(observe_name=="4m" && array_num<=0){
			h1 = plots->fcomb4M;
		}
		else if(observe_name=="5m" && array_num<=0){
			h1 = plots->fcomb5M;
		}
		else if(observe_name=="6m" && array_num<=0){
			h1 = plots->fcomb6M;
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr comb");
			exit(0);
		}
	}

	if(class_name=="recoil"){
		if(observe_name=="mass" && array_num<=0){
			h1 = plots->frecoilmass;
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr recoil");
			exit(0);
		}
	}

	if(class_name=="MassDrop"){
		if(observe_name=="mbb" && array_num<=0){
			h1 = para.MassDrop.fmbb;
		}
		else
		{
			ShowMessage(3,"wrong para in Get_Class_ptr met");
			exit(0);
		}
	}
	return(h1);
}
