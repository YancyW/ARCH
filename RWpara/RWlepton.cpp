#include "Class/lepton.h"
void CLepton::Read_Lepton_particle(CPath path, std::string particle_name,CLepton_cut &lep, bool flag_detector){
	ShowMessage(4);
	ShowMessage(4, "read "+particle_name);
	if(particle_name!="basic_elec"&&particle_name!="basic_muon"){
		YAML::Node plot_node = YAML::LoadFile(path.plot_file);
		RW_element(particle_name,"PLOT_e"     ,plot_node  ,lep.PLOT_e    );
		RW_element(particle_name,"PLOT_pt"    ,plot_node  ,lep.PLOT_pt    );
		RW_element(particle_name,"PLOT_eta"   ,plot_node  ,lep.PLOT_eta   );
		RW_element(particle_name,"PLOT_r_lep" ,plot_node  ,lep.PLOT_r_lep );

		std::string switch_name=path.cut_file+"switch.dat";
		YAML::Node switch_node = YAML::LoadFile(switch_name);
		RW_element(particle_name,"SWITCH"  ,switch_node,lep.SWITCH);
	}

	std::string file_name=path.cut_file+particle_name+".dat";
	YAML::Node lep_node = YAML::LoadFile(file_name);




	if(flag_detector){
		RW_element(particle_name,"MinTrackEnergy"            ,lep_node,lep.MinTrackEnergy             );
		RW_element(particle_name,"MaxTrackEnergy"            ,lep_node,lep.MaxTrackEnergy             );
		RW_element(particle_name,"MinEnergyDepositByMomentum",lep_node,lep.MinEnergyDepositByMomentum );
		RW_element(particle_name,"MaxEnergyDepositByMomentum",lep_node,lep.MaxEnergyDepositByMomentum );
		RW_element(particle_name,"MinEcalToHcalFraction"     ,lep_node,lep.MinEcalToHcalFraction      );
		RW_element(particle_name,"MaxEcalToHcalFraction"     ,lep_node,lep.MaxEcalToHcalFraction      );
		RW_element(particle_name,"MinEyoke"                  ,lep_node,lep.MinEyoke                   );
		RW_element(particle_name,"MaxEyoke"                  ,lep_node,lep.MaxEyoke                   );

		RW_element(particle_name,"MinD0"                     ,lep_node,lep.MinD0                      );
		RW_element(particle_name,"MaxD0"                     ,lep_node,lep.MaxD0                      );
		RW_element(particle_name,"MinZ0"                     ,lep_node,lep.MinZ0                      );
		RW_element(particle_name,"MaxZ0"                     ,lep_node,lep.MaxZ0                      );
		RW_element(particle_name,"MinR0"                     ,lep_node,lep.MinR0                      );
		RW_element(particle_name,"MaxR0"                     ,lep_node,lep.MaxR0                      );
		RW_element(particle_name,"MinD0Sig"                  ,lep_node,lep.MinD0Sig                   );
		RW_element(particle_name,"MaxD0Sig"                  ,lep_node,lep.MaxD0Sig                   );
		RW_element(particle_name,"MinZ0Sig"                  ,lep_node,lep.MinZ0Sig                   );
		RW_element(particle_name,"MaxZ0Sig"                  ,lep_node,lep.MaxZ0Sig                   );
		RW_element(particle_name,"MinR0Sig"                  ,lep_node,lep.MinR0Sig                   );
		RW_element(particle_name,"MaxR0Sig"                  ,lep_node,lep.MaxR0Sig                   );

		RW_element(particle_name,"cosConeAngle"              ,lep_node,lep.cosConeAngle               );
	}





	ShowMessage(4);

	RW_element(particle_name,"CUT_num"                  ,lep_node,lep.CUT_num                 );
	RW_element(particle_name,"ISOLATE_cone_lep"         ,lep_node,lep.ISOLATE_cone_lep        );
	RW_element(particle_name,"ISOLATE_cone_had"         ,lep_node,lep.ISOLATE_cone_had        );
	RW_element(particle_name,"ISOLATE_cone_photon"      ,lep_node,lep.ISOLATE_cone_photon     );
	RW_element(particle_name,"ISOLATE_coef_lep"         ,lep_node,lep.ISOLATE_coef_lep        );
	RW_element(particle_name,"ISOLATE_coef_had"         ,lep_node,lep.ISOLATE_coef_had        );
	RW_element(particle_name,"ISOLATE_coef_photon"      ,lep_node,lep.ISOLATE_coef_photon     );
	RW_element(particle_name,"ISOLATE_remainder_photon" ,lep_node,lep.ISOLATE_remainder_photon);
	RW_element(particle_name,"ISOLATE_min_pt"           ,lep_node,lep.ISOLATE_min_pt          );

	for(int i=0;i<lep.CUT_num;i++){

		RW_vector_element(particle_name,"JCUT_e"           ,i,lep_node,lep.JCUT_e             );
		RW_vector_element(particle_name,"CUT_ed"           ,i,lep_node,lep.CUT_ed             );
		RW_vector_element(particle_name,"CUT_eu"           ,i,lep_node,lep.CUT_eu             );

		RW_vector_element(particle_name,"JCUT_pt"          ,i,lep_node,lep.JCUT_pt            );
		RW_vector_element(particle_name,"CUT_ptd"          ,i,lep_node,lep.CUT_ptd            );
		RW_vector_element(particle_name,"CUT_ptu"          ,i,lep_node,lep.CUT_ptu            );

		RW_vector_element(particle_name,"JCUT_theta"       ,i,lep_node,lep.JCUT_theta         );
		RW_vector_element(particle_name,"CUT_thetad"       ,i,lep_node,lep.CUT_thetad         );
		RW_vector_element(particle_name,"CUT_thetau"       ,i,lep_node,lep.CUT_thetau         );

		RW_vector_element(particle_name,"JCUT_eta"         ,i,lep_node,lep.JCUT_eta           );
		RW_vector_element(particle_name,"CUT_etad"         ,i,lep_node,lep.CUT_etad           );
		RW_vector_element(particle_name,"CUT_etau"         ,i,lep_node,lep.CUT_etau           );

		RW_vector_element(particle_name,"JCUT_r_lep"       ,i,lep_node,lep.JCUT_r_lep         );
		RW_vector_element(particle_name,"CUT_cone_lep"     ,i,lep_node,lep.CUT_cone_lep       );
		RW_vector_element(particle_name,"CUT_cone_elec"    ,i,lep_node,lep.CUT_cone_elec      );
		RW_vector_element(particle_name,"CUT_cone_muon"    ,i,lep_node,lep.CUT_cone_muon      );
		RW_vector_element(particle_name,"CUT_cone_tau"     ,i,lep_node,lep.CUT_cone_tau       );
	}



}

void CLepton::Read_Lepton(CPath path){
	ShowMessage(3, "read lepton");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_lepton"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_file+"switch.dat";
	YAML::Node switch_node = YAML::LoadFile(switch_name);
	RW_element("SWITCH_lep"  ,switch_node,this->SWITCH);

	ShowMessage(4);

	Read_Lepton_particle(path, "lep"    ,this->lep, false);

	ShowMessage(4);

	Read_Lepton_particle(path, "basic_elec"   ,this->elec, true);
	Read_Lepton_particle(path, "elec"   ,this->elec, false);

	ShowMessage(4);

	Read_Lepton_particle(path, "basic_muon"   ,this->muon, true);
	Read_Lepton_particle(path, "muon"   ,this->muon, false);

	ShowMessage(4);

	Read_Lepton_particle(path, "tau"    ,this->tau, false );
}


