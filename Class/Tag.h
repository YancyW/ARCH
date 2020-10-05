#ifndef GLOBAL_PARA_TAG
#define GLOBAL_PARA_TAG
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/file.h"

class CTag_Particle {
	private:
	public:
		bool        SWITCH        ;

		float coneR;
		float bquark_ratio;
		float cquark_ratio;
		float lightquark_ratio;
};

class CTag{
	private:
	public:

		CTag_Particle btag;
		CTag_Particle ctag;
		CTag_Particle tautag;

		void Read_Tag(CPath path);
		void Read_Tag_Particle(CPath path, std::string particle_name, CTag_Particle &particle);

};




#endif
