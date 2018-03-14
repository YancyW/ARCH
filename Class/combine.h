#pragma once
#ifndef GLOBAL_PARA_COMBINE
#define GLOBAL_PARA_COMBINE
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/kinematic.h"
#include "Class/file.h"

class CCombine_cut: public CPT, public CETA, public CTHETA, public CMASS{
	private:
	public:
		int                   CUT_num ;
};

class CCombine{
	private:
	public:
		bool    SWITCH     ;
		bool    PLOT       ;

		CCombine_cut     jets;
		CCombine_cut     bjet;
		CCombine_cut     cjet;
		CCombine_cut     qjet;
		CCombine_cut   tagjet;
		CCombine_cut untagjet;

		CCombine_cut      lep;
		CCombine_cut     elec;
		CCombine_cut     muon;
		CCombine_cut      tau;

		CCombine_cut   photon;

		void Read_Combine(CPath path)  ;
		void Read_Combine_particle(CPath path,std::string particle_name, CCombine_cut &comb);
};

#endif
