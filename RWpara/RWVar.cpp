#include "AnalyseClass/Variable.h"

void AVariable::Read_Var(CDraw &para){
  	freopen(para.path.record_file.c_str(),"a",stdout);
	ShowMessage(3, "read Var");
	std::string file_name=para.path.var_file;
	ShowMessage(3, "variable",file_name);
	YAML::Node var_node = YAML::LoadFile(file_name);

	ShowMessage(3, "find var file");
	YAML::Node nodes = var_node["variable"];
	for(YAML::const_iterator it=nodes.begin(); it != nodes.end(); ++it){
		ShowMessage(3, "Var name",it->first.as<std::string>());
		this->var.push_back(it->second.as<Avariable>());
	}
	num = var.size();
	for(int i=0;i<num;i++){
		if(var[i].BDT_switch){
			numBDT++;
			BDT.push_back(var[i]);
		}
	}
	YAML::Node nodes_vec = var_node["variable_vec"];
	for(YAML::const_iterator it=nodes_vec.begin(); it != nodes_vec.end(); ++it){
		ShowMessage(3, "Vec name",it->first.as<std::string>());
		this->vec.push_back(it->second.as<Avariable_vec>());
	}
	num_vec = vec.size();
	if(!para.flow.record_output){
		fclose(stdout);
		freopen("/dev/tty","w",stdout);
	}
}

