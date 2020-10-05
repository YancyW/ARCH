#pragma once
#ifndef GLOBAL_PARA_BoostTag 
#define GLOBAL_PARA_BoostTag
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/file.h"

class CBoostTag{
	private:
	public:
		bool    SWITCH     ;
		bool    PLOT       ;

		void Read_BoostTag(CPath path)                    ;
};

#endif
