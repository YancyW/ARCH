#include "Class/photon.h"

void CPhoton:: Read_Photon(CPath path){
	ShowMessage(3, "read photon");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_photon"           ,plot_node  ,this->PLOT         );
	RW_element("PLOT_pt_photon"        ,plot_node  ,this->PLOT_pt      );
	RW_element("PLOT_eta_photon"       ,plot_node  ,this->PLOT_eta     );
	RW_element("PLOT_r_photon_photon"  ,plot_node  ,this->PLOT_r_photon);
	RW_element("PLOT_r_lep_photon"     ,plot_node  ,this->PLOT_r_lep   );
	RW_element("PLOT_r_jet_photon"     ,plot_node  ,this->PLOT_r_jet   );

	std::string switch_name=path.cut_file+"switch.dat";
    YAML::Node switch_node = YAML::LoadFile(switch_name);
    RW_element("SWITCH_photon"  ,switch_node,this->SWITCH);

	std::string file_name=path.cut_file+"photon.dat";
	YAML::Node A_node = YAML::LoadFile(file_name);
	RW_element("CUT_num"                  ,A_node,this->CUT_num);
	RW_element("ISOLATE_cone_lep"         ,A_node,this->ISOLATE_cone_lep        );
	RW_element("ISOLATE_cone_had"         ,A_node,this->ISOLATE_cone_had        );
	RW_element("ISOLATE_cone_photon"      ,A_node,this->ISOLATE_cone_photon     );
	RW_element("ISOLATE_coef_lep"         ,A_node,this->ISOLATE_coef_lep        );
	RW_element("ISOLATE_coef_had"         ,A_node,this->ISOLATE_coef_had        );
	RW_element("ISOLATE_coef_photon"      ,A_node,this->ISOLATE_coef_photon     );
	RW_element("ISOLATE_remainder_photon" ,A_node,this->ISOLATE_remainder_photon);
	RW_element("ISOLATE_min_pt"           ,A_node,this->ISOLATE_min_pt          );

	for(int i=0;i<this->CUT_num;i++){
		RW_vector_element("JCUT_theta"       ,i,A_node,this->JCUT_theta         );
		RW_vector_element("CUT_thetad"       ,i,A_node,this->CUT_thetad         );
		RW_vector_element("CUT_thetau"       ,i,A_node,this->CUT_thetau         );

		RW_vector_element("JCUT_eta"         ,i,A_node,this->JCUT_eta           );
		RW_vector_element("CUT_etad"         ,i,A_node,this->CUT_etad           );
		RW_vector_element("CUT_etau"         ,i,A_node,this->CUT_etau           );

		RW_vector_element("JCUT_e"           ,i,A_node,this->JCUT_e             );
		RW_vector_element("CUT_ed"           ,i,A_node,this->CUT_ed             );
		RW_vector_element("CUT_eu"           ,i,A_node,this->CUT_eu             );

		RW_vector_element("JCUT_pt"          ,i,A_node,this->JCUT_pt            );
		RW_vector_element("CUT_ptd"          ,i,A_node,this->CUT_ptd            );
		RW_vector_element("CUT_ptu"          ,i,A_node,this->CUT_ptu            );

		RW_vector_element("JCUT_r_photon"    ,i,A_node,this->JCUT_r_photon      );
		RW_vector_element("CUT_cone_photon"  ,i,A_node,this->CUT_cone_photon    );
		RW_vector_element("JCUT_r_lep"       ,i,A_node,this->JCUT_r_lep         );
		RW_vector_element("CUT_cone_lep"     ,i,A_node,this->CUT_cone_lep       );
		RW_vector_element("JCUT_r_jet"       ,i,A_node,this->JCUT_r_jet         );
		RW_vector_element("CUT_cone_jet"     ,i,A_node,this->CUT_cone_jet       );
	}
}

