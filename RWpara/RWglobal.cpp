#include "Class/global.h"

void CGlobal:: Read_Global(CPath path){
	ShowMessage(3, "read global");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_global"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_file+"switch.dat";
    YAML::Node switch_node = YAML::LoadFile(switch_name);
    RW_element("SWITCH_global"  ,switch_node,this->SWITCH);

	std::string file_name=path.cut_file+"global.dat";
	YAML::Node global_node = YAML::LoadFile(file_name);

	RW_element("CUT_bw"              ,global_node,this->CUT_bw             );
	RW_element("CUT_vis_d"           ,global_node,this->CUT_vis_d          );
	RW_element("CUT_vis_u"           ,global_node,this->CUT_vis_u          );

	RW_element("CUT_visWOChoosed_d"  ,global_node,this->CUT_visWOChoosed_d );
	RW_element("CUT_visWOChoosed_u"  ,global_node,this->CUT_visWOChoosed_u );

	RW_element("CUT_invis_d"         ,global_node,this->CUT_invis_d        );
	RW_element("CUT_invis_u"         ,global_node,this->CUT_invis_u        );

	RW_element("CUT_ht_d"            ,global_node,this->CUT_ht_d           );
	RW_element("CUT_ht_u"            ,global_node,this->CUT_ht_u           );

	RW_element("CUT_num" ,global_node, this->CUT_num);
	for(int i=0;i<this->CUT_num;i++){
		RW_vector_element("CUT_global_d"  , i,global_node,this->CUT_global_d  );
		RW_vector_element("CUT_global_u"  , i,global_node,this->CUT_global_u  );
		RW_vector_element("CUT_global_bin", i,global_node,this->CUT_global_bin);

	}
}

