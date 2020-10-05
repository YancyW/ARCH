#include "Class/recoil.h"

void CRecoil::Read_Recoil_particle(CPath path , std::string particle_name,CRecoil_cut &recoil){
	ShowMessage(4);
	ShowMessage(4, "read "+particle_name);
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element(particle_name,"PLOT_recoil_mass"  ,plot_node  ,recoil.PLOT_mass  );

	std::string file_name=path.cut_file+"recoil.dat";
	YAML::Node recoil_node = YAML::LoadFile(file_name);

	RW_element(particle_name,"CUT_num" ,recoil_node, recoil.CUT_num);

	ShowMessage(4);

	std::string fname,fnum;
	for(int i=0;i<recoil.CUT_num;i++){
		RW_vector_element(particle_name,"CUT_massr"     ,i,recoil_node, recoil.CUT_massr     );
		RW_vector_element(particle_name,"CUT_massbin"   ,i,recoil_node, recoil.CUT_massbin   );
		RW_vector_element(particle_name,"CUT_massd"     ,i,recoil_node, recoil.CUT_massd     );
		RW_vector_element(particle_name,"CUT_massu"     ,i,recoil_node, recoil.CUT_massu     );
	}

}



void CRecoil::Read_Recoil(CPath path){
	ShowMessage(3, "read recoil");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_recoil"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_file+"switch.dat";
    YAML::Node switch_node = YAML::LoadFile(switch_name);
    RW_element("SWITCH_recoil"  ,switch_node,this->SWITCH);
    RW_element("SWITCH_recoil_comb"  ,switch_node,this->comb_SWITCH);
	
	ShowMessage(4);

	Read_Recoil_particle(path, "jets"    ,this->jets    );
	
	ShowMessage(4);

	Read_Recoil_particle(path, "bjet"    ,this->bjet    );
	
	ShowMessage(4);

	Read_Recoil_particle(path, "cjet"    ,this->cjet    );
	
	ShowMessage(4);

	Read_Recoil_particle(path, "qjet"    ,this->qjet    );
	
	ShowMessage(4);

	Read_Recoil_particle(path, "tagjet"  ,this->tagjet  );
	
	ShowMessage(4);

	Read_Recoil_particle(path, "untagjet",this->untagjet);
	
	ShowMessage(4);

	Read_Recoil_particle(path, "lep"     ,this->lep      );
	
	ShowMessage(4);

	Read_Recoil_particle(path, "elec"    ,this->elec     );
	
	ShowMessage(4);

	Read_Recoil_particle(path, "muon"    ,this->muon     );
	
	ShowMessage(4);

	Read_Recoil_particle(path, "tau"     ,this->tau      );
	
	ShowMessage(4);

	Read_Recoil_particle(path, "photon"  ,this->photon   );
}


