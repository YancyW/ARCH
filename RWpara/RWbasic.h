#include "TStyle.h"
#include <string> 
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"



void RW_element(std::string name, YAML::const_iterator it, float &variable_name);
void RW_element(std::string name, YAML::const_iterator it, int    &variable_name);
void RW_element(std::string name, YAML::const_iterator it, long long int &variable_name);
void RW_element(std::string name, YAML::const_iterator it, bool   &variable_name);
void RW_element(std::string name, YAML::const_iterator it, std::string  &variable_name);

void RW_element(std::string name, YAML::Node node_name, float &variable_name);
void RW_element(std::string name, YAML::Node node_name, int    &variable_name);
void RW_element(std::string name, YAML::Node node_name, long long int &variable_name);
void RW_element(std::string name, YAML::Node node_name, bool   &variable_name);
void RW_element(std::string name, YAML::Node node_name, std::string  &variable_name);
void RW_element(std::string name, YAML::Node node_name, std::string  &variable_name, bool lower_switch);

void RW_element(std::string particle_name, std::string name, YAML::Node node_name, float &variable_name);
void RW_element(std::string particle_name, std::string name, YAML::Node node_name, int    &variable_name);
void RW_element(std::string particle_name, std::string name, YAML::Node node_name, long long int &variable_name);
void RW_element(std::string particle_name, std::string name, YAML::Node node_name, bool   &variable_name);
void RW_element(std::string particle_name, std::string name, YAML::Node node_name, std::string  &variable_name);
void RW_element(std::string particle_name, std::string name, YAML::Node node_name, std::string  &variable_name, bool lower_switch);

void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<float> &variable_name);
void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<int>    &variable_name);
void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<long long int >&variable_name);
void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<bool>   &variable_name);
void RW_vector_element(std::string name, int num, YAML::Node node_name, std::vector<std::string>  &variable_name);

void RW_vector_element(std::string particle_name, std::string name, int num,YAML::Node node_name, std::vector<float> &variable_name);
void RW_vector_element(std::string particle_name, std::string name, int num,YAML::Node node_name, std::vector<int>    &variable_name);
void RW_vector_element(std::string particle_name, std::string name, int num,YAML::Node node_name, std::vector<long long int >&variable_name);
void RW_vector_element(std::string particle_name, std::string name, int num,YAML::Node node_name, std::vector<bool>   &variable_name);
void RW_vector_element(std::string particle_name, std::string name, int num,YAML::Node node_name, std::vector<std::string>  &variable_name);

