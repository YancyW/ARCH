#pragma once
#ifndef GLOBAL_PARA_KINEMATIC 
#define GLOBAL_PARA_KINEMATIC
#include "TStyle.h"
#include <vector>
class CENERGY{
	public:
		bool                  PLOT_e            ;
		std::vector <bool>    JCUT_e            ;
		std::vector <float>   CUT_ed            ;
		std::vector <float>   CUT_eu            ;

		float                 e                 ;
};


class CPT{
	public:
		bool                  PLOT_pt           ;
		std::vector <bool>    JCUT_pt           ;
		std::vector <float>   CUT_ptd           ;
		std::vector <float>   CUT_ptu           ;

		float                 pt                ;
};

class CETA{
	public:
		bool                  PLOT_eta          ;
		std::vector <bool>    JCUT_eta          ;
		std::vector <float>   CUT_etad          ;
		std::vector <float>   CUT_etau          ;

		float                 eta               ;
};

class CTHETA{
	public:
		bool                  PLOT_theta        ;
		std::vector <bool>    JCUT_theta        ;
		std::vector <float>   CUT_thetad        ;
		std::vector <float>   CUT_thetau        ;

		float                 theta             ;
};

class CMASS{
	public:
		bool                  PLOT_mass         ;
		std::vector <bool>    JCUT_mass         ;
		std::vector <float>   CUT_massr         ;
		std::vector <float>   CUT_mass_relate   ;
		std::vector <float>   CUT_massbin       ;
		std::vector <float>   CUT_massd         ;
		std::vector <float>   CUT_massu         ;

		float                 mass              ;
};

class CCONE_LEP{
	public:
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
