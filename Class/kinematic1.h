#pragma once
#ifndef GLOBAL_PARA_KINEMATIC 
#define GLOBAL_PARA_KINEMATIC
#include "TStyle.h"
#include <vector>
class CKINEMATIC_BASIC{
	public:
		bool     JCUT            ;
		float    CUT_d           ;
		float    CUT_u           ;

		float    var             ;
		float    var_relate      ;
};

class CENERGY{
	public:
		bool                  PLOT_energy     ;
		std::vector <CKINEMATIC_BASIC>    cut_energy ;
};


class CPT{
	public:
		bool                  PLOT_pt           ;
		std::vector <CKINEMATIC_BASIC>    cut_pt   ;
};

class CETA{
	public:
		bool                  PLOT_eta          ;
		std::vector <CKINEMATIC_BASIC>    cut_eta  ;
};

class CTHETA{
	public:
		bool                  PLOT_theta        ;
		std::vector <CKINEMATIC_BASIC>    cut_theta;
};

class CMASS{
	public:
		bool                  PLOT_mass         ;
		std::vector <CKINEMATIC_BASIC>    cut_mass ;
};

class CCONE_LEP{
	public:
		std::vector <CENERGY_Basic>    cut_mass ;
		bool                   PLOT_r_lep       ;
		float                 ISOLATE_cone_lep  ;
		float                 ISOLATE_coef_lep  ;
		float                 ISOLATE_min_pt_lep;
		std::vector <bool>     JCUT_r_lep       ;
		std::vector <float>   CUT_cone_lep      ;
		std::vector <float>   CUT_cone_elec     ;
		std::vector <float>   CUT_cone_muon     ;
		std::vector <float>   CUT_cone_tau      ;
};

class CCONE_JET{
	public:
		bool                   PLOT_r_jet       ;
		float                 ISOLATE_cone_had  ;
		float                 ISOLATE_coef_had  ;
		float                 ISOLATE_min_pt    ;
		std::vector <bool>     JCUT_r_jet       ;
		std::vector <float>   CUT_cone_jet      ;
		std::vector <float>   CUT_cone_jets     ;
		std::vector <float>   CUT_cone_bjet     ;
		std::vector <float>   CUT_cone_cjet     ;
		std::vector <float>   CUT_cone_qjet     ;
		std::vector <float>   CUT_cone_tagjet   ;
		std::vector <float>   CUT_cone_untagjet ;
};

class CCONE_PHOTON{
	public:
		bool                   PLOT_r_photon          ;
		float                 ISOLATE_cone_photon     ;
		float                 ISOLATE_coef_photon     ;
		float                 ISOLATE_remainder_photon;
		std::vector <bool>     JCUT_r_photon          ;
		std::vector <float>   CUT_cone_photon         ;
};




#endif
