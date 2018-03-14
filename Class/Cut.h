#pragma once
#ifndef GLOBAL_PARA_CUT_H
#define GLOBAL_PARA_CUT_H
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/file.h"


class CCut{
	private:
	public:
		int              CUT_num;
		int              cut_level;
		std::vector<float> min;
		std::vector<float> max;

		void Read_Cut(CPath path,CFlow flow);
};

#endif
