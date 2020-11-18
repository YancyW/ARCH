#include "Class/file.h"
#include "Class/debug.h"
void CPath::Read_Path(std::string steering_file){
	YAML::Node path_node = YAML::LoadFile(steering_file);
	RW_element("INPUT_FOLDER"   ,path_node,this->input_folder                  );
	RW_element("OUTPUT_FOLDER"  ,path_node,this->output_folder                 );
	RW_element("RECORD_FILE"    ,path_node,this->record_file   );
	if(this->output_folder != "NULL"){
		this->record_file= this->output_folder+"/"+this->record_file;
	}
	Create_File_Folder(this->record_file);

	ShowMessage(4,"Please check the RECORD_FILE for detail arguments setting!" );
	ShowMessage(1);
  	freopen(this->record_file.c_str(),"w",stdout);

	ShowMessage(2, "read path");
	RW_element("PROCESS"        ,path_node,this->process       );

	RW_element("DATA_FOLDER"    ,path_node,this->data_folder );
	RW_element("EVENT_FOLDER"   ,path_node,this->event_folder  );
	RW_element("SINGLE_PLOT"    ,path_node,this->single_plot   );
	RW_element("COMBINE_PLOT"   ,path_node,this->combine_plot  );
	ShowMessage(1);

	if(this->output_folder != "NULL" || this->output_folder != ""){
		this->data_folder             = this->output_folder+"/"+this->data_folder+"/";
		this->event_folder            = this->output_folder+"/"+this->event_folder+"/";
		this->single_plot             = this->output_folder+"/"+this->single_plot+"/";
		this->combine_plot            = this->output_folder+"/"+this->combine_plot+"/";
	}

	this->Create_Folder();
	this->event_file = this->event_folder + this->process + ".root";


	RW_element("ANALYSIS_FILE"  ,path_node,this->analyse_file  );
	RW_element("DETECTOR_FILE"  ,path_node,this->detector_file );
	RW_element("FLOW_FILE"      ,path_node,this->flow_file     );
	RW_element("SIGNAL_FILE"    ,path_node,this->signal_file   );

	RW_element("INPUT_FILE"     ,path_node,this->input_file    );
	RW_element("VAR_FILE"       ,path_node,this->var_file      );
	RW_element("CUT_FOLDER"     ,path_node,this->cut_folder    );

	RW_element("DEBUG_FILE"     ,path_node,this->debug_file    );
	RW_element("PLOT_FILE"      ,path_node,this->plot_file     );

	if(this->input_folder != "NULL" || this->input_folder != ""){
		this->analyse_file              = this->input_folder+"/"+this->analyse_file     ;
		this->debug_file                = this->input_folder+"/"+this->debug_file       ;
		this->flow_file                 = this->input_folder+"/"+this->flow_file        ;
		this->plot_file                 = this->input_folder+"/"+this->plot_file        ;
		this->input_file                = this->input_folder+"/"+this->input_file       ;
		this->cut_folder                = this->input_folder+"/"+this->cut_folder+"/"   ;
		this->var_file                  = this->input_folder+"/"+this->var_file         ;
		this->signal_file               = this->cut_folder+"/"+this->signal_file        ;
		this->detector_file             = this->input_folder+"/"+this->detector_file    ;
	}
}

void CFile::  Read_File(CPath path){
	YAML::Node file_node = YAML::LoadFile(path.input_file);
	ShowMessage(4);

	RW_element("FILE_NUM"           ,file_node,this->file_num          );
	RW_element("CHANNEL_NUM"        ,file_node,this->channel_num       );
	RW_element("Root_Head_Name"     ,file_node,this->root_head_name    );
	RW_element("Root_Head_BDT_Name" ,file_node,this->root_head_BDT_name);
	RW_element("CROSS_SECTION"      ,file_node,this->xection           );


	this->file= file_node["FILE"].as<std::vector<std::string> >();
	this->file_descrip= file_node["FILE_DESCRIP"].as<std::vector<std::string> >();
	//for(int i=0;i<file_num;i++){
	//	RW_vector_element("FILE"         , i, file_node, this->file);
	//}
	//for(int i=0;i<channel_num;i++){
	//	RW_vector_element("FILE_DESCRIP" , i, file_node, this->file_descrip);
	//}
	ShowMessage(3, "finish reading file.");
};

void CDebug::  Read_Debug(CPath path){
	YAML::Node debug_node = YAML::LoadFile(path.debug_file);

	RW_element("Debug_mode"                 ,debug_node,this->mode );
	RW_element("Debug_mode_num"             ,debug_node,this->num_debug_mode  );
	RW_element("Debug_level"                ,debug_node,this->level);

	ShowMessage(4);

	for(int i=0;i<this->num_debug_mode;i++){
		RW_vector_element("Debug"       , i, debug_node,  this->debug);
	}
	ShowMessage(3, "finish reading debug.");
}

void CFlow::   Read_Flow(CPath path){
	ShowMessage(3, "read flow");
	YAML::Node flow_node = YAML::LoadFile(path.flow_file);
	RW_element("cut"            ,flow_node,this->cut          );
	RW_element("plot"           ,flow_node,this->plot         );
	RW_element("record_output"  ,flow_node,this->record_output);
	RW_element("level"          ,flow_node,this->level        );

	RW_element("BeginObject"    ,flow_node,this->begin_object , true);
	RW_element("RecordObject"   ,flow_node,this->record_object , true);
	RW_element("record_event"   ,flow_node,this->record_event );
	RW_element("BDT_training"   ,flow_node,this->BDT_training );
	RW_element("BDT_level"      ,flow_node,this->BDT_level    );
}

void CSignal::Read_Signal(std::string file_name){
	ShowMessage(3, "read signal");
	YAML::Node signal_node = YAML::LoadFile(file_name);
	RW_element("NUM_jets"        ,signal_node,this->NUM_jets     );
	RW_element("NUM_bjet"        ,signal_node,this->NUM_bjet     );
	RW_element("NUM_cjet"        ,signal_node,this->NUM_cjet     );
	RW_element("NUM_qjet"        ,signal_node,this->NUM_qjet     );
	RW_element("NUM_taujet"      ,signal_node,this->NUM_taujet   );
	RW_element("NUM_tagjet"      ,signal_node,this->NUM_tagjet   );
	RW_element("NUM_untagjet"    ,signal_node,this->NUM_untagjet );
	RW_element("NUM_lep"         ,signal_node,this->NUM_lep      );
	RW_element("NUM_elec"        ,signal_node,this->NUM_elec     );
	RW_element("NUM_muon"        ,signal_node,this->NUM_muon     );
	RW_element("NUM_tau"         ,signal_node,this->NUM_tau      );
	RW_element("NUM_photon"      ,signal_node,this->NUM_photon   );
	RW_element("NUM_met"         ,signal_node,this->NUM_met      );

	RW_element("VETO_jets"       ,signal_node,this->VETO_jets    );
	RW_element("VETO_bjet"       ,signal_node,this->VETO_bjet    );
	RW_element("VETO_cjet"       ,signal_node,this->VETO_cjet    );
	RW_element("VETO_qjet"       ,signal_node,this->VETO_qjet    );
	RW_element("VETO_taujet"     ,signal_node,this->VETO_taujet  );
	RW_element("VETO_tagjet"     ,signal_node,this->VETO_tagjet  );
	RW_element("VETO_untagjet"   ,signal_node,this->VETO_untagjet);
	RW_element("VETO_lep"        ,signal_node,this->VETO_lep     );
	RW_element("VETO_elec"       ,signal_node,this->VETO_elec    );
	RW_element("VETO_muon"       ,signal_node,this->VETO_muon    );
	RW_element("VETO_tau"        ,signal_node,this->VETO_tau     );
	RW_element("VETO_photon"     ,signal_node,this->VETO_photon  );
	RW_element("VETO_met"        ,signal_node,this->VETO_met     );
}

