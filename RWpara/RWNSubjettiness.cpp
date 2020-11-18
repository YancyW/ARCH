#include "Class/NSubjettiness.h"

void CNSubjettiness:: Read_NSubjettiness(CPath path){
	ShowMessage(3, "read NSubjettiness");
	YAML::Node plot_node = YAML::LoadFile(path.plot_file);
	RW_element("PLOT_NSubjettiness"    ,plot_node  ,this->PLOT  );

	std::string switch_name=path.cut_folder+"switch.dat";
    YAML::Node switch_node = YAML::LoadFile(switch_name);
    RW_element("SWITCH_NSubjettiness"  ,switch_node,this->SWITCH);

	std::string file_name=path.cut_folder+"nsubjettiness.dat";
	YAML::Node global_node = YAML::LoadFile(file_name);

	RW_element("beta"           ,global_node,this->beta       );
	RW_element("delta"          ,global_node,this->delta      );
	RW_element("p"              ,global_node,this->p          );
	RW_element("R0"             ,global_node,this->R0         );
	RW_element("Rcut"           ,global_node,this->Rcut       );
	RW_element("epsilon"        ,global_node,this->epsilon    );

	RW_element("measuretype"    ,global_node,this->measuretype);
	RW_element("axestype"       ,global_node,this->axestype   );

	RW_element("JCUT_tau1"      ,global_node,this->JCUT_tau1  );
	RW_element("CUT_tau1d"      ,global_node,this->CUT_tau1d  );
	RW_element("CUT_tau1u"      ,global_node,this->CUT_tau1u  );

	RW_element("JCUT_tau2"      ,global_node,this->JCUT_tau2  );
	RW_element("CUT_tau2d"      ,global_node,this->CUT_tau2d  );
	RW_element("CUT_tau2u"      ,global_node,this->CUT_tau2u  );

	RW_element("JCUT_tau3"      ,global_node,this->JCUT_tau3  );
	RW_element("CUT_tau3d"      ,global_node,this->CUT_tau3d  );
	RW_element("CUT_tau3u"      ,global_node,this->CUT_tau3u  );

	RW_element("JCUT_tau21"     ,global_node,this->JCUT_tau21 );
	RW_element("CUT_tau21d"     ,global_node,this->CUT_tau21d );
	RW_element("CUT_tau21u"     ,global_node,this->CUT_tau21u );

	RW_element("JCUT_tau32"     ,global_node,this->JCUT_tau32 );
	RW_element("CUT_tau32d"     ,global_node,this->CUT_tau32d );
	RW_element("CUT_tau32u"     ,global_node,this->CUT_tau32u );

}

