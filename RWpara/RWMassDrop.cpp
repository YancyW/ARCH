#include "Class/MassDrop.h"

void CMassDrop:: Read_MassDrop(CPath path){
	ShowMessage(3, "read MassDrop");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_MassDrop"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_folder+"switch.dat";
	YAML::Node switch_node = YAML::LoadFile(switch_name);
	RW_element("SWITCH_MassDrop"  ,switch_node,this->SWITCH);

	std::string file_name=path.cut_folder+"massdrop.dat";
	YAML::Node md_node = YAML::LoadFile(file_name);

	RW_element("JCUT"          ,md_node,this->JCUT          );
	RW_element("CUT_mu"        ,md_node,this->CUT_mu        );
	RW_element("CUT_y"         ,md_node,this->CUT_y         );
	RW_element("coneR"         ,md_node,this->coneR         );
	RW_element("Rmin"          ,md_node,this->Rmin          );
	RW_element("nfilt"         ,md_node,this->nfilt         );

	for(int i=0;i<1;i++){
		RW_vector_element("JCUT_pt"          ,i,md_node,this->JCUT_pt          );
		RW_vector_element("CUT_ptd"          ,i,md_node,this->CUT_ptd          );
		RW_vector_element("CUT_ptu"          ,i,md_node,this->CUT_ptu          );

		RW_vector_element("JCUT_eta"         ,i,md_node,this->JCUT_eta         );
		RW_vector_element("CUT_etad"         ,i,md_node,this->CUT_etad         );
		RW_vector_element("CUT_etau"         ,i,md_node,this->CUT_etau         );

		RW_vector_element("JCUT_mass"        ,i,md_node,this->JCUT_mass        );
		RW_vector_element("CUT_massd"        ,i,md_node,this->CUT_massd         );
		RW_vector_element("CUT_massu"        ,i,md_node,this->CUT_massu         );

	}
}

