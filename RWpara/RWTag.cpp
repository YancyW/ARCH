#include "Class/Tag.h"

void CTag::Read_Tag_Particle(CPath path, std::string particle_name,CTag_Particle &particle){
	std::string switch_name=path.cut_file+"switch.dat";
    YAML::Node switch_node = YAML::LoadFile(switch_name);
    RW_element(particle_name,"SWITCH"  ,switch_node,particle.SWITCH);

	std::string file_name=path.cut_file+particle_name+".dat";
	YAML::Node tag_node = YAML::LoadFile(file_name);

		RW_element("coneR"              ,tag_node,particle.coneR);
		RW_element("bquark_ratio"       ,tag_node,particle.bquark_ratio);
		RW_element("cquark_ratio"       ,tag_node,particle.cquark_ratio);
		RW_element("lightquark_ratio"   ,tag_node,particle.lightquark_ratio);
}

void CTag::Read_Tag(CPath path){
	ShowMessage(3, "read tag");

	ShowMessage(4);

	Read_Tag_Particle(path, "btag"      ,this->btag  );
	
	ShowMessage(4);

	Read_Tag_Particle(path, "ctag"      ,this->ctag  );
	
	ShowMessage(4);

	Read_Tag_Particle(path, "tautag"    ,this->tautag);
}
