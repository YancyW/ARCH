#ifndef GLOBAL_PARA_MASSDROP
#define GLOBAL_PARA_MASSDROP
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/file.h"
#include "Class/kinematic.h"

class CMassDrop: public CPT, public CETA, public CMASS{
	private:
	public:
		bool    SWITCH;
		bool    PLOT  ;
        TH1       *fmbb ;

		bool    JCUT  ;
		float  CUT_mu;
		float  CUT_y ;

		float  coneR ;
		float  Rmin  ;
		int     nfilt ;


		void Read_MassDrop(CPath path)                    ;
		void Plot(float data){
			if(this->PLOT){
				this->fmbb->Fill(data);
			}
		}
};

#endif
