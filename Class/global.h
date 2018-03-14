#ifndef GLOBAL_PARA_GLOBAL 
#define GLOBAL_PARA_GLOBAL
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/kinematic.h"
#include "Class/file.h"

class CGlobal{
	private:
	public:
		bool    SWITCH                      ;
		bool    PLOT                        ;

		float   CUT_bw                     ;

		float   CUT_vis_d		          ;
		float   CUT_vis_u	              ;

		float   CUT_visWOChoosed_d		  ;
		float   CUT_visWOChoosed_u	      ;

		float   CUT_invis_d		          ;
		float   CUT_invis_u	              ;

		float   CUT_ht_d		              ;
		float   CUT_ht_u	                  ;

		int      CUT_num                    ;
		std::vector <float>  CUT_global_d  ;
		std::vector <float>  CUT_global_u  ;
		std::vector <float>  CUT_global_bin;
		void Read_Global(CPath path)          ;
};

#endif
