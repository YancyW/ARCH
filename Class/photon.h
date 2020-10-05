#ifndef GLOBAL_PARA_PHOTON 
#define GLOBAL_PARA_PHOTON
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/kinematic.h"
#include "Class/file.h"

class CPhoton: public CENERGY,  public CPT, public CETA, public CTHETA, public CCONE_LEP, public CCONE_JET, public CCONE_PHOTON{
	private:
	public:
		bool    SWITCH     ;
		int     CUT_num    ;
		bool    PLOT       ;

		void Read_Photon(CPath path);
};

#endif
