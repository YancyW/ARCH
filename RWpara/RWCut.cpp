#include "Class/Cut.h"
#include "Function/Fbasic.h"

void CCut:: Read_Cut(CPath path,CFlow flow){
	ShowMessage(3, "read Cut");
	YAML::Node cut_node = YAML::LoadFile(path.cut_file);

	RW_element("CUT_num" ,cut_node,this->CUT_num);
	RW_element("cut_level" ,cut_node,this->cut_level);
	if(flow.cut){
		for(int i=0;i<CUT_num;i++){
			RW_vector_element("min"          ,i,cut_node,this->min);
			RW_vector_element("max"          ,i,cut_node,this->max);
		}
	}
	else{
		for(int i=0;i<CUT_num;i++){
			this->min.push_back(-10000);
			this->max.push_back( 10000);
		}
	}
}

