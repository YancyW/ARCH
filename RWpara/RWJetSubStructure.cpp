#include "Class/JetSubStructure.h"

void CJetSubStructure:: Read_JetSubStructure(CPath path){
	ShowMessage(3, "read JetSubStructure");

	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_JetSubStructure"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_file+"switch.dat";
	YAML::Node switch_node = YAML::LoadFile(switch_name);
	RW_element("SWITCH_JetSubStructure"  ,switch_node,this->SWITCH);

	std::string file_name=path.cut_file+"jetsubstructure.dat";
	YAML::Node md_node = YAML::LoadFile(file_name);

	RW_element("JCUT"          ,md_node,this->JCUT          );
	RW_element("coneR"         ,md_node,this->coneR         );
	RW_element("JetAlgorithms" ,md_node,this->jet_alg_name  );
	Get_Jet_Alg();
}

