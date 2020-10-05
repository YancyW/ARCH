#pragma once
#ifndef GLOBAL_PARA_DETECTOR 
#define GLOBAL_PARA_DETECTOR
#include "TStyle.h"
#include "Class/file.h"
class CDetector{
	public:
		std::string                 name                     ;

		float                energy                   ;
		float                lumi                     ;
		float                collider_angle           ;

		float                elec_pol                 ;
		float                posi_pol                 ;
		std::vector<float>   pol                      ;
		void                 Cal_Pol()                ;
		void                 Read_Detector(CPath path);
};
#endif
