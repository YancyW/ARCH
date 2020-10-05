#ifndef GLOBAL_PARA_MET 
#define GLOBAL_PARA_MET
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/kinematic.h"
#include "Class/file.h"

class CMet: public CENERGY, public CPT, public CETA, public CTHETA, public CCONE_LEP, public CCONE_JET, public CCONE_PHOTON{
	private:
	public:
		bool    SWITCH     ;
		bool    PLOT       ;
		void Read_Met(CPath path)      ;
};

#endif
