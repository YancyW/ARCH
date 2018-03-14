#include "Class/jep.h"

void CJEP::Read_JEP(CPath path){
	ShowMessage(3, "read jep");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_JEP"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_file+"switch.dat";
    YAML::Node switch_node = YAML::LoadFile(switch_name);
    RW_element("SWITCH_JEP"  ,switch_node,this->SWITCH);

}


