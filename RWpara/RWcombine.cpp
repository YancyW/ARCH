#include "Class/combine.h"

void CCombine::Read_Combine_particle(CPath path , std::string particle_name,CCombine_cut &comb){
	ShowMessage(4);
	ShowMessage(4, "read "+particle_name);
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element(particle_name,"PLOT_comb_pt"    ,plot_node  ,comb.PLOT_pt    );
	RW_element(particle_name,"PLOT_comb_eta"   ,plot_node  ,comb.PLOT_eta   );
	RW_element(particle_name,"PLOT_comb_mass"  ,plot_node  ,comb.PLOT_mass  );

	std::string file_name=path.cut_file+"combine.dat";
	YAML::Node comb_node = YAML::LoadFile(file_name);

	RW_element(particle_name,"CUT_num" ,comb_node, comb.CUT_num);

	ShowMessage(4);

	std::string fname,fnum;
	for(int i=0;i<comb.CUT_num;i++){
		RW_vector_element(particle_name,"CUT_massr"      ,i,comb_node, comb.CUT_massr      );
		RW_vector_element(particle_name,"CUT_mass_relate",i,comb_node, comb.CUT_mass_relate);
		RW_vector_element(particle_name,"CUT_massbin"    ,i,comb_node, comb.CUT_massbin    );
		RW_vector_element(particle_name,"CUT_massd"      ,i,comb_node, comb.CUT_massd      );
		RW_vector_element(particle_name,"CUT_massu"      ,i,comb_node, comb.CUT_massu      );
		RW_vector_element(particle_name,"CUT_yu"         ,i,comb_node, comb.CUT_etau       );
		RW_vector_element(particle_name,"CUT_yd"         ,i,comb_node, comb.CUT_etad       );
		RW_vector_element(particle_name,"CUT_ptu"        ,i,comb_node, comb.CUT_ptu        );
		RW_vector_element(particle_name,"CUT_ptd"        ,i,comb_node, comb.CUT_ptd        );
	}

}



void CCombine::Read_Combine(CPath path){
	ShowMessage(3, "read combine");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_comb"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_file+"switch.dat";
    YAML::Node switch_node = YAML::LoadFile(switch_name);
    RW_element("SWITCH_comb"  ,switch_node,this->SWITCH);

	
	ShowMessage(4);

	Read_Combine_particle(path, "jets"    ,this->jets    );
	
	ShowMessage(4);

	Read_Combine_particle(path, "bjet"    ,this->bjet    );
	
	ShowMessage(4);

	Read_Combine_particle(path, "cjet"    ,this->cjet    );
	
	ShowMessage(4);

	Read_Combine_particle(path, "qjet"    ,this->qjet    );
	
	ShowMessage(4);

	Read_Combine_particle(path, "tagjet"  ,this->tagjet  );
	
	ShowMessage(4);

	Read_Combine_particle(path, "untagjet",this->untagjet);
	
	ShowMessage(4);

	Read_Combine_particle(path, "lep"     ,this->lep      );
	
	ShowMessage(4);

	Read_Combine_particle(path, "elec"    ,this->elec     );
	
	ShowMessage(4);

	Read_Combine_particle(path, "muon"    ,this->muon     );
	
	ShowMessage(4);

	Read_Combine_particle(path, "tau"     ,this->tau      );
	
	ShowMessage(4);

	Read_Combine_particle(path, "photon"  ,this->photon   );
}


