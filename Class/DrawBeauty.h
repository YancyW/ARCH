#pragma once
#ifndef CLASS_DRAW_BEAUTY
#define CLASS_DRAW_BEAUTY
#include "TStyle.h"
#include "TTree.h"
#include "TChain.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "Class/DrawClass.h"
//-----------------------------------------------------

class CDrawBeauty{
	public:
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
};
#endif
