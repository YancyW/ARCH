#ifndef GLOBAL_PARA_RECOIL
#define GLOBAL_PARA_RECOIL
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/kinematic.h"
#include "Class/file.h"

class CRecoil_cut: public CMASS{
	private:
	public:
		int                   CUT_num ;
};

class CRecoil{
	private:
	public:
		bool    SWITCH     ;
		bool    comb_SWITCH     ;
		bool    PLOT       ;

		CRecoil_cut     jets;
		CRecoil_cut     bjet;
		CRecoil_cut     cjet;
		CRecoil_cut     qjet;
		CRecoil_cut   tagjet;
		CRecoil_cut untagjet;

		CRecoil_cut      lep;
		CRecoil_cut     elec;
		CRecoil_cut     muon;
		CRecoil_cut      tau;

		CRecoil_cut   photon;

		void Read_Recoil(CPath path)  ;
		void Read_Recoil_particle(CPath path,std::string particle_name, CRecoil_cut  &recoil);
};

#endif
