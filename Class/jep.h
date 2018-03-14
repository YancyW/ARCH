#ifndef GLOBAL_PARA_JEP
#define GLOBAL_PARA_JEP
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/file.h"

class CJEP{
	private:
	public:
		bool    SWITCH     ;
		bool    PLOT       ;

		void Read_JEP(CPath path)  ;
};

#endif
