#ifndef ELEMENT_DATATYPE_H
#define ELEMENT_DATATYPE_H  
#include "TTree.h"
#include "AnalyseClass/Variable.h"

//Stored data 
class Variable{
	public:
		//************************
		//inserted by process file
		//************************
		Avariable  recoil_mass                ;
		Avariable  kcut_zmass                 ;
		Avariable  kcut_zpt                   ;
		Avariable  kcut_invis_costheta        ;
		Avariable  kcut_mva                   ;
		Avariable  kcut_recoil_mass           ;
		Avariable  kcut_vis_e                 ;
		Avariable  lep_pair_costheta          ;
		Avariable  lep_pair_costheta_pair     ;
		Avariable  lep_pair_costheta_track1   ;        
		Avariable  lep_pair_costheta_track2   ;        

		void init(){
		}
};

class Number{
	public:
		int num                           ;
		int num_plus                      ;
		int num_minus                     ;

		void init(){
		    num                = -1       ;
		    num_plus           = -1       ;
		    num_minus          = -1       ;
		}

};


class Infomation{
	public:
		float                           init_energy        ;
		Variable                        data_muon_gen      ;
		Variable                        data_muon          ;
		Variable                        data_muon_recovery ;
		Variable                        data_elec_gen      ;
		Variable                        data_elec          ;
		Variable                        data_elec_recovery ;

		std::vector<float>              Lepton_cosTheta    ;

		Number                          num_lep           ;
		Number                          num_lep_gen       ;
		Number                          num_lep_recovery  ;
		Number                          num_muon           ;
		Number                          num_muon_gen       ;
		Number                          num_muon_recovery  ;
		Number                          num_elec           ;
		Number                          num_elec_gen       ;
		Number                          num_elec_recovery  ;


		Infomation(){
		}


		void Init(){
			init_energy             =-10.1;
			data_muon.init();
			data_muon_gen.init();
			data_muon_recovery.init();
			data_elec.init();
			data_elec_gen.init();
			data_elec_recovery.init();
			Lepton_cosTheta.clear();
			num_muon.init();
			num_muon_gen.init();
			num_muon_recovery.init();
			num_elec.init();
			num_elec_gen.init();
			num_elec_recovery.init();
		}


		~Infomation(){
		}
}; 

#endif
