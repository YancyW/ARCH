#pragma once
#ifndef GLOBAL_PARA_LEP 
#define GLOBAL_PARA_LEP
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/kinematic.h"
#include "Class/file.h"
#include "Class/Lepton_Detector_Cut.h"

class CLepton_cut: public CENERGY, public CPT, public CETA, public CTHETA, public CCONE_LEP, public CCONE_JET , public CCONE_PHOTON, public CLepton_Detector_Cut{
	private:
	public:
		int     CUT_num           ;
		bool    SWITCH            ;
};

class CLepton{
	private:
	public:
		bool    SWITCH            ;
		bool    PLOT              ;

    	CLepton_cut basic_elec ;
    	CLepton_cut basic_muon ;

		CLepton_cut lep  ;
		CLepton_cut elec ;
		CLepton_cut muon ;
		CLepton_cut tau  ;

		void Read_Lepton(CPath path);
		void Read_Lepton_particle(CPath path,std::string particle_name, CLepton_cut &lep, bool flag_detector);
};

#endif
