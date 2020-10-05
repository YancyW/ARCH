#include "Class/Detector.h"
void CDetector::   Read_Detector(CPath path){
	ShowMessage(3, "read Detector");
	YAML::Node de_node = YAML::LoadFile(path.detector_file);
	RW_element("name"           ,de_node,this->name          );
	RW_element("energy"         ,de_node,this->energy        );

	RW_element("luminosity"     ,de_node,this->lumi          );
	RW_element("collider_angle" ,de_node,this->collider_angle);
  	RW_element("elec_pol"       ,de_node,this->elec_pol      );
  	RW_element("posi_pol"       ,de_node,this->posi_pol      );

    Cal_Pol();
}

