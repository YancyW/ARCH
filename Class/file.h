#ifndef GLOBAL_PARA_FILE 
#define GLOBAL_PARA_FILE
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Function/Ffile.h"


class CPath{
	private:
	public:
		std::string   process      ;
		std::string   output_folder    ;
		std::string   input_folder     ;

		std::string   record_file  ;

		std::string   data_folder  ;
		std::string   event_folder ;
		std::string   single_plot  ;
		std::string   combine_plot ;
		std::string   event_file   ;

		std::string   input_file   ;
		std::string   debug_file   ;
		std::string   analyse_file ;
		std::string   detector_file;
		std::string   flow_file    ;
		std::string   cut_folder     ;
		std::string   plot_file    ;
		std::string   signal_file  ;
		std::string   var_file     ;

		void          Read_Path(std::string steering_file)  ;
		void          Create_Folder()  ;
};

class CFile{
	private:
	public:
		int                    file_num               ;
		int                    channel_num            ;
		float                  xection                ;
		std::vector<std::string>     file                   ;
		std::vector<std::string>     file_descrip           ;
		void                     Read_File(CPath path)  ;
		std::string                  root_head_name         ;
		std::string                  root_head_BDT_name     ;
};


class CFlow{
	private:
	public:
		bool                  cut                  ;
		bool                  plot                 ;
		bool                  record_output        ;
		int                   level                ;
		std::string           begin_object         ;
		std::string           record_object        ;
		bool                  record_event         ;
		bool                  BDT_training         ;
		int                   BDT_level            ;
		void                  Read_Flow(CPath path);
};




class CSignal{
	private:
	public:
		int  NUM_jets      ;
		int  NUM_bjet      ;
		int  NUM_cjet      ;
		int  NUM_qjet      ;
		int  NUM_taujet    ;
		int  NUM_tagjet    ;
		int  NUM_untagjet  ;
		int  NUM_lep       ;
		int  NUM_elec      ;
		int  NUM_muon      ;
		int  NUM_tau       ;
		int  NUM_met       ;
		int  NUM_photon    ;


		bool VETO_jets     ;
		bool VETO_bjet     ;
		bool VETO_cjet     ;
		bool VETO_qjet     ;
		bool VETO_taujet   ;
		bool VETO_tagjet   ;
		bool VETO_untagjet ;
		bool VETO_lep      ;
		bool VETO_elec     ;
		bool VETO_muon     ;
		bool VETO_tau      ;
		bool VETO_met      ;
		bool VETO_photon   ;
		void Read_Signal(std::string file_name) ;
};


#endif
