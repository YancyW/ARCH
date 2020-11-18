#include "Class/met.h"

void CMet::    Read_Met(CPath path){
	ShowMessage(3, "read met");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_met"           ,plot_node  ,this->PLOT         );
	RW_element("PLOT_pt_met"        ,plot_node  ,this->PLOT_pt        );
	RW_element("PLOT_eta_met"       ,plot_node  ,this->PLOT_eta       );
	RW_element("PLOT_r_photon_met"  ,plot_node  ,this->PLOT_r_photon);
	RW_element("PLOT_r_lep_met"     ,plot_node  ,this->PLOT_r_lep   );
	RW_element("PLOT_r_jet_met"     ,plot_node  ,this->PLOT_r_jet   );

	std::string switch_name=path.cut_folder+"switch.dat";
    YAML::Node switch_node = YAML::LoadFile(switch_name);
    RW_element("SWITCH_met"  ,switch_node,this->SWITCH);

	std::string file_name=path.cut_folder+"met.dat";
	YAML::Node met_node = YAML::LoadFile(file_name);

	RW_vector_element("JCUT_e"         ,0 ,met_node,this->JCUT_e         );
	RW_vector_element("CUT_ed"         ,0 ,met_node,this->CUT_ed         );
	RW_vector_element("CUT_eu"         ,0 ,met_node,this->CUT_eu         );

	RW_vector_element("JCUT_pt"        ,0 ,met_node,this->JCUT_pt        );
	RW_vector_element("CUT_ptd"        ,0 ,met_node,this->CUT_ptd        );
	RW_vector_element("CUT_ptu"        ,0 ,met_node,this->CUT_ptu        );

	RW_vector_element("JCUT_eta"       ,0 ,met_node,this->JCUT_eta       );
	RW_vector_element("CUT_etad"       ,0 ,met_node,this->CUT_etad       );
	RW_vector_element("CUT_etau"       ,0 ,met_node,this->CUT_etau       );

	RW_vector_element("JCUT_theta"     ,0 ,met_node,this->JCUT_theta     );
	RW_vector_element("CUT_thetad"     ,0 ,met_node,this->CUT_thetad     );
	RW_vector_element("CUT_thetau"     ,0 ,met_node,this->CUT_thetau     );

	RW_vector_element("JCUT_r_jet"     ,0 ,met_node,this->JCUT_r_jet     );
	RW_vector_element("CUT_cone_jet"   ,0 ,met_node,this->CUT_cone_jet   );
	RW_vector_element("JCUT_r_lep"     ,0 ,met_node,this->JCUT_r_lep     );
	RW_vector_element("CUT_cone_lep"   ,0 ,met_node,this->CUT_cone_lep   );
	RW_vector_element("JCUT_r_photon"  ,0 ,met_node,this->JCUT_r_photon  );
	RW_vector_element("CUT_cone_photon",0 ,met_node,this->CUT_cone_photon);
}


