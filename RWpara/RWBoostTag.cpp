#include "Class/BoostTag.h"

void CBoostTag:: Read_BoostTag(CPath path){
	ShowMessage(3, "read BoostTag");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_BoostTag"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_file+"switch.dat";
    YAML::Node switch_node = YAML::LoadFile(switch_name);
    RW_element("SWITCH_BoostTag"  ,switch_node,this->SWITCH);
}

