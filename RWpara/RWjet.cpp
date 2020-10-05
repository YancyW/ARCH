#include "Class/Jet.h"

void CJet::Read_Jet_particle(CPath path, std::string particle_name,CJet_cut &jet){
	ShowMessage(4);
	ShowMessage(4, "read "+particle_name);
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element(particle_name,"PLOT_e"     ,plot_node  ,jet.PLOT_e     );
	RW_element(particle_name,"PLOT_pt"    ,plot_node  ,jet.PLOT_pt    );
	RW_element(particle_name,"PLOT_eta"   ,plot_node  ,jet.PLOT_eta   );
	RW_element(particle_name,"PLOT_mass"  ,plot_node  ,jet.PLOT_mass  );
	RW_element(particle_name,"PLOT_r_jet" ,plot_node  ,jet.PLOT_r_jet );

	std::string switch_name=path.cut_file+"switch.dat";
	YAML::Node switch_node = YAML::LoadFile(switch_name);
	RW_element(particle_name,"SWITCH"  ,switch_node,jet.SWITCH);

	std::string file_name=path.cut_file+particle_name+".dat";
	YAML::Node jet_node = YAML::LoadFile(file_name);

	ShowMessage(4);
	if(particle_name=="jets"){
		RW_element(particle_name,"coneR"         ,jet_node,this->coneR         );
		RW_element(particle_name,"sort_method"   ,jet_node,this->sort_method   , true);
		RW_element(particle_name,"JetAlgorithms" ,jet_node,this->jet_alg_name  , true);
		Get_Jet_Alg();
	}

	RW_element(particle_name,"CUT_num" ,jet_node,jet.CUT_num);

	for(int i=0;i<jet.CUT_num;i++){

		RW_vector_element(particle_name,"JCUT_e"           ,i,jet_node,jet.JCUT_e           );
		RW_vector_element(particle_name,"CUT_ed"           ,i,jet_node,jet.CUT_ed           );
		RW_vector_element(particle_name,"CUT_eu"           ,i,jet_node,jet.CUT_eu           );

		RW_vector_element(particle_name,"JCUT_pt"          ,i,jet_node,jet.JCUT_pt          );
		RW_vector_element(particle_name,"CUT_ptd"          ,i,jet_node,jet.CUT_ptd          );
		RW_vector_element(particle_name,"CUT_ptu"          ,i,jet_node,jet.CUT_ptu          );

		RW_vector_element(particle_name,"JCUT_eta"         ,i,jet_node,jet.JCUT_eta         );
		RW_vector_element(particle_name,"CUT_etad"         ,i,jet_node,jet.CUT_etad         );
		RW_vector_element(particle_name,"CUT_etau"         ,i,jet_node,jet.CUT_etau         );

		RW_vector_element(particle_name,"JCUT_theta"       ,i,jet_node,jet.JCUT_theta       );
		RW_vector_element(particle_name,"CUT_thetad"       ,i,jet_node,jet.CUT_thetad       );
		RW_vector_element(particle_name,"CUT_thetau"       ,i,jet_node,jet.CUT_thetau       );

		RW_vector_element(particle_name,"JCUT_mass"        ,i,jet_node,jet.JCUT_mass        );
		RW_vector_element(particle_name,"CUT_massd"        ,i,jet_node,jet.CUT_massd        );
		RW_vector_element(particle_name,"CUT_massu"        ,i,jet_node,jet.CUT_massu        );

		RW_vector_element(particle_name,"JCUT_r_lep"       ,i,jet_node,jet.JCUT_r_lep       );
		RW_vector_element(particle_name,"CUT_cone_lep"     ,i,jet_node,jet.CUT_cone_lep     );
		RW_vector_element(particle_name,"CUT_cone_elec"    ,i,jet_node,jet.CUT_cone_elec    );
		RW_vector_element(particle_name,"CUT_cone_muon"    ,i,jet_node,jet.CUT_cone_muon    );
		RW_vector_element(particle_name,"CUT_cone_tau"     ,i,jet_node,jet.CUT_cone_tau     );

		RW_vector_element(particle_name,"JCUT_r_jet"       ,i,jet_node,jet.JCUT_r_jet       );
		RW_vector_element(particle_name,"CUT_cone_alljet"  ,i,jet_node,jet.CUT_cone_jet     );
		RW_vector_element(particle_name,"CUT_cone_jets"    ,i,jet_node,jet.CUT_cone_jets    );
		RW_vector_element(particle_name,"CUT_cone_bjet"    ,i,jet_node,jet.CUT_cone_bjet    );
		RW_vector_element(particle_name,"CUT_cone_cjet"    ,i,jet_node,jet.CUT_cone_cjet    );
		RW_vector_element(particle_name,"CUT_cone_qjet"    ,i,jet_node,jet.CUT_cone_qjet    );
		RW_vector_element(particle_name,"CUT_cone_tagjet"  ,i,jet_node,jet.CUT_cone_tagjet  );
		RW_vector_element(particle_name,"CUT_cone_untagjet",i,jet_node,jet.CUT_cone_untagjet);
	}

}

void CJet::Read_Jet(CPath path){
	ShowMessage(3, "read jet");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_jet"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_file+"switch.dat";
	YAML::Node switch_node = YAML::LoadFile(switch_name);
	RW_element("SWITCH_jet"  ,switch_node,this->SWITCH);

	ShowMessage(4);

	Read_Jet_particle(path, "jets"    ,this->jets    );

	ShowMessage(4);

	Read_Jet_particle(path, "tjet"    ,this->tjet    );

	ShowMessage(4);

	Read_Jet_particle(path, "bjet"    ,this->bjet    );

	ShowMessage(4);

	Read_Jet_particle(path, "cjet"    ,this->cjet    );

	ShowMessage(4);

	Read_Jet_particle(path, "qjet"    ,this->qjet    );

	ShowMessage(4);

	Read_Jet_particle(path, "taujet"  ,this->taujet  );

	ShowMessage(4);

	Read_Jet_particle(path, "gluonjet",this->gluonjet);

	ShowMessage(4);

	Read_Jet_particle(path, "tagjet"  ,this->tagjet  );

	ShowMessage(4);

	Read_Jet_particle(path, "untagjet",this->untagjet);
}
