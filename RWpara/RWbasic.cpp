#include "RWbasic.h"


void RW_element(std::string name, YAML::const_iterator it, float &variable_name){
	variable_name = it->second.as<float>();	
	ShowMessage(4, name + " is         ",variable_name);
}
void RW_element(std::string name, YAML::const_iterator it, int    &variable_name){
	variable_name = it->second.as<int>();	
	ShowMessage(4, name + " is         ",variable_name);
}
void RW_element(std::string name, YAML::const_iterator it, long long int &variable_name){
	variable_name = it->second.as<long>();	
	ShowMessage(4, name + " is         ",variable_name);
}
void RW_element(std::string name, YAML::const_iterator it, bool   &variable_name){
	variable_name = it->second.as<bool>();	
	ShowMessage(4, name + " is         ",variable_name);
}
void RW_element(std::string name, YAML::const_iterator it, std::string  &variable_name){
	variable_name = it->second.as<std::string>();	
	ShowMessage(4, name + " is         ",variable_name);
}

void RW_element(std::string name, YAML::Node node_name, float &variable_name){
	variable_name = node_name[name].as<float>();	
	ShowMessage(4, name ,variable_name);
}
void RW_element(std::string name, YAML::Node node_name, int    &variable_name){
	variable_name = node_name[name].as<int>();	
	ShowMessage(4, name ,variable_name);
}
void RW_element(std::string name, YAML::Node node_name, long long int &variable_name){
	variable_name = node_name[name].as<long>();	
	ShowMessage(4, name ,variable_name);
}
void RW_element(std::string name, YAML::Node node_name, bool   &variable_name){
	variable_name = node_name[name].as<bool>();	
	ShowMessage(4, name ,variable_name);
}
void RW_element(std::string name, YAML::Node node_name, std::string  &variable_name){
	variable_name = node_name[name].as<std::string>();	
	ShowMessage(4, name ,variable_name);
}
void RW_element(std::string name, YAML::Node node_name, std::string  &variable_name, bool lower_switch){
	variable_name = node_name[name].as<std::string>();	
    if(lower_switch){
    	to_lower(variable_name);	
    }
	ShowMessage(4, name ,variable_name);
}

void RW_element(std::string particle_name, std::string name, YAML::Node node_name, float &variable_name){
	std::string fname=name+"_"+particle_name;
	variable_name = node_name[fname].as<float>();	
	ShowMessage(4, fname ,variable_name);
}
void RW_element(std::string particle_name, std::string name, YAML::Node node_name, int    &variable_name){
	std::string fname=name+"_"+particle_name;
	variable_name = node_name[fname].as<int>();	
	ShowMessage(4, fname ,variable_name);
}
void RW_element(std::string particle_name, std::string name, YAML::Node node_name, long long int &variable_name){
	std::string fname=name+"_"+particle_name;
	variable_name = node_name[fname].as<long>();	
	ShowMessage(4, fname ,variable_name);
}
void RW_element(std::string particle_name, std::string name, YAML::Node node_name, bool   &variable_name){
	std::string fname=name+"_"+particle_name;
	variable_name = node_name[fname].as<bool>();	
	ShowMessage(4, fname ,variable_name);
}
void RW_element(std::string particle_name, std::string name, YAML::Node node_name, std::string  &variable_name){
	std::string fname=name+"_"+particle_name;
	variable_name = node_name[fname].as<std::string>();	
	ShowMessage(4, fname ,variable_name);
}

void RW_element(std::string particle_name, std::string name, YAML::Node node_name, std::string  &variable_name, bool lower_switch){
	std::string fname=name+"_"+particle_name;
	variable_name = node_name[fname].as<std::string>();	
    if(lower_switch){
    	to_lower(variable_name);	
    }
	ShowMessage(4, fname ,variable_name);
}

void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<float> &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+fnum;
	variable_name.push_back(node_name[fname].as<float>());	
	ShowMessage(4, fname ,variable_name[num]);
}
void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<int>    &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+fnum;
	variable_name.push_back(node_name[fname].as<int>());	
	ShowMessage(4, fname ,variable_name[num]);
}
void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<long long int>    &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+fnum;
	variable_name.push_back(node_name[fname].as<long>());	
	ShowMessage(4, fname ,variable_name[num]);
}
void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<bool>   &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+fnum;
	variable_name.push_back(node_name[fname].as<bool>());	
	ShowMessage(4, fname ,variable_name[num]);
}
void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<std::string>  &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+fnum;
	std::string input_str=node_name[fname].as<std::string>();	
	variable_name.push_back(input_str);	
	ShowMessage(4, fname ,variable_name[num]);
}

void RW_vector_element(std::string particle_name, std::string name, int num, YAML::Node node_name, std::vector<float> &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+particle_name+"_"+fnum;
	variable_name.push_back(node_name[fname].as<float>());	
	ShowMessage(4, fname ,variable_name[num]);
}
void RW_vector_element(std::string particle_name, std::string name, int num, YAML::Node node_name, std::vector<int>    &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+particle_name+"_"+fnum;
	variable_name.push_back(node_name[fname].as<int>());	
	ShowMessage(4, fname ,variable_name[num]);
}
void RW_vector_element(std::string particle_name, std::string name, int num, YAML::Node node_name, std::vector<long long int>    &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+particle_name+"_"+fnum;
	variable_name.push_back(node_name[fname].as<long>());	
	ShowMessage(4, fname ,variable_name[num]);
}
void RW_vector_element(std::string particle_name, std::string name, int num, YAML::Node node_name, std::vector<bool>   &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+particle_name+"_"+fnum;
	variable_name.push_back(node_name[fname].as<bool>());	
	ShowMessage(4, fname ,variable_name[num]);
}
void RW_vector_element(std::string particle_name, std::string name, int num, YAML::Node node_name, std::vector<std::string>  &variable_name){
	std::string	fnum=std::to_string(num);
	std::string fname=name+"_"+particle_name+"_"+fnum;
	std::string input_str=node_name[fname].as<std::string>();	
	variable_name.push_back(input_str);	
	ShowMessage(4, fname ,variable_name[num]);
}

