#pragma once
#ifndef CLASS_DRAW 
#define CLASS_DRAW 
#include "TStyle.h"
#include "TTree.h"
#include "TChain.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "Class/file.h"
#include "Class/debug.h"
#include "Class/Event.h"
#include "Class/Jet.h"
#include "Class/lepton.h"
#include "Class/photon.h"
#include "Class/met.h"
#include "Class/combine.h"
#include "Class/recoil.h"

#include "Class/Tag.h"
#include "Class/jep.h"
#include "Class/global.h"
#include "Class/MassDrop.h"
#include "Class/NSubjettiness.h"
#include "Class/JetSubStructure.h"
#include "Class/BoostTag.h"
#include "Class/Detector.h"

//#include "AnalyseClass/Particle.h"
//-----------------------------------------------------

class CDraw{
	public:
		std::string      steering_file;

		bool             Jpath        ;
		bool             Jfile        ;
		bool             Jdebug       ;
		bool             Jflow        ;
		bool             Jsignal      ;
		bool             Jevent       ;
		bool             Jjet         ;
		bool             Jlepton      ;
		bool             Jmet         ;
		bool             Jphoton      ;
		bool             Jcombine     ;
		bool             Jrecoil      ;
		bool             Jtag         ;
		bool             Jglobal      ;
		bool             Jjetsub      ;
		bool             Jjep         ;
		bool             JMassDrop    ;
		bool             JNSubjettiness;
		bool             JBoostTag    ;
		bool             JDetector    ;

		CPath              path         ;
		CFile              file         ;
		CDebug             debug        ;
		CFlow              flow         ;
		CSignal            signal       ;
		CEvent             event        ;
		CJet               jet          ;
    	CPhoton            photon       ;
    	CLepton            lep          ;
    	CMet               met          ;
    	CCombine           comb         ;
    	CRecoil            recoil       ;
    	CGlobal            global       ;
    	CTag               tag          ;
    	CJetSubStructure   jetsub       ;
    	CJEP               jep          ;
    	CMassDrop          MassDrop     ;
    	CNSubjettiness     NSubjettiness;
		CBoostTag          BoostTag     ;
		CDetector          detector     ;

		void Read()         ;
		void Init(ExRootTreeReader* treeReader){
			event.Init(treeReader);
		}

		void Get_Event(long long int num){
			event.Get_Event(num);
		};

		long long int Event(){
			return(event.Event());
		};

		long long int Total_Event(){
			return(event.Total_Event());
		}

};
#endif
