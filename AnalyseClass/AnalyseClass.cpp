
#include "AnalyseClass/AnalyseClass.h"
void AnalyseClass::Init(CDraw &para, ExRootTreeReader* treeReader, TChain* tree){
	counter.Init(para);
	if((para.flow.begin_object=="slcio_particle")||(para.flow.begin_object=="slcio_equipment")){
		slcio  .Init(tree      ,true );
		delphes.Init(treeReader,false);
		stdhep .Init(para.file.file[0],false);
	}
	else if((para.flow.begin_object=="delphes_particle")||(para.flow.begin_object=="delphes_equipment")||(para.flow.begin_object=="delphes_detector")){
		slcio  .Init(tree      ,false);
		delphes.Init(treeReader,true );
		stdhep .Init(para.file.file[0],false);
	}
	else if((para.flow.begin_object=="stdhep_particle")){
		slcio  .Init(tree      ,false);
		delphes.Init(treeReader,false);
		stdhep .Init(para.file.file[0],true );
	}
	else{
		return;
	}
	var.Read_Var(para);
	IsRecord = false;
	IsBDTTrain = false;
	out_weight = 0.0;


	para.debug.Message(1,90,"in AnalyseClass::Init, para.flow.record_event",para.flow.record_event);
	if(para.flow.record_event){
		IsRecord = true;
		otfile = TFile::Open( para.path.event_file.c_str(), "RECREATE" );
		para.debug.Message(1,90, "in AnalyseClass::Init para.path.event_file",para.path.event_file);
		if (!otfile) {
			std::cout << "ERROR: could not open data file" << std::endl;
			exit(1);
		}

		para.debug.Message(1,90, "in AnalyseClass::Init,para.file.root_head_name",para.file.root_head_name);
		datatrain= new TTree( para.file.root_head_name.c_str() , "events" );

		datatrain->Branch( "weight"              , &out_weight );        
		para.debug.Message(1,90, "in AnalyseClass::Init, out_weight",out_weight);
		for(int i=0;i<var.num;i++){
			datatrain->Branch( var.var[i].title_name.c_str(), &var.var[i].variable );        
		}
		for(int i=0;i<var.num_vec;i++){
			datatrain->Branch( var.vec[i].title_name.c_str(), &var.vec[i].variable );        
		}

		para.debug.Message(1,90, "in AnalyseClass::Init, para.flow.BDT_training",para.flow.BDT_training);
		if(para.flow.BDT_training){
			IsBDTTrain = true;
			datatest= new TTree( para.file.root_head_BDT_name.c_str() , "events" );
			para.debug.Message(1,90, "in AnalyseClass::Init, para.file.root_head_BDT_name",para.file.root_head_BDT_name);
			datatest->Branch( "weight"              , &out_weight );        
			for(int i=0;i<var.num;i++){
				datatest->Branch( var.var[i].title_name.c_str(), &var.var[i].variable );        
			}
			for(int i=0;i<var.num_vec;i++){
				datatest->Branch( var.vec[i].title_name.c_str(), &var.vec[i].variable );        
			}
		}
	}
}
