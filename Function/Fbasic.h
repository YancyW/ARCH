#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Lib/MessageFormat.h" 

void to_lower(std::string &str);
std::string Int_to_String(int i);
std::string Int_to_String_descrip(int i);

std::string NameHistogram(std::string signal_name, std::string class_name, std::string observable_name, int i);
std::string NameDescrip(std::string class_name, std::string observable_name, int i);

std::string GetUnit(std::string observe_name);

#define Get_VarName(x) #x


template <typename TTname>
std::string Get_ClassName(TTname x){

	std::string tname;
	tname = typeid(x).name();

	return(tname);
}


void CountNumber(int variable, int tot_num, int slot,std::string  Message);
