#ifndef ANALYSIS_CLASS_COUNTER_H
#define ANALYSIS_CLASS_COUNTER_H
#include "Lib/MessageFormat.h"
#include "Class/DrawClass.h"
#include "AnalyseClass/Species.h"

typedef std::map<std::string,float>            ACounterType;
class ACounter{ 
	private:
		float                _weight;
		ACounterType         _counter;
		float                _xection;
	public:
		int pass_basic        ;
		int pass_basic_jet    ,pass_basic_bjet,pass_basic_cjet,pass_basic_qjet,pass_basic_taujet;
		int pass_basic_lep    ,pass_basic_elec,pass_basic_muon,pass_basic_met ;
		int pass_basic_photon ;
		int pass_combine      ;
		int pass_remass1      ,pass_remass2   , pass_remass3, pass_remass4, pass_remass5, pass_remass6,pass_recoilmass;
		int pass_comb_recoil  ;
		int pass_jetsub       ;
		int pass_boosttag     , pass_massdrop , pass_nsubjettiness;
		int pass_jeteventshape;
		int pass_jep          ;
		int pass;
		int AllEntries;

		bool jetSwitch    ;
		bool jetsSwitch   ;
		bool bjetSwitch   ;
		bool cjetSwitch   ;
		bool taujetSwitch ;
		bool qjetSwitch   ;
		bool lepSwitch    ;
		bool elecSwitch   ;
		bool muonSwitch   ;
		bool metSwitch    ;
		bool combSwitch   ;
		bool recoilSwitch ;
		bool recombSwitch ;
		bool mdSwitch     ;
		bool nsubSwitch   ;
		bool boostSwitch  ;
		bool jetsubSwitch ;
		bool jepSwitch    ;
		bool jesSwitch    ;



		ACounter(){
			Clear();
		}

		~ACounter(){
			Clear();
		}

		void Init(CDraw &para);

		void getCounter(std::string event_name);

		void sendCounter(std::string event_name);

		void sendCounter();

		void Clear();



		void setWeight(float value);

		void setCounterSingle(std::string event_name,float num);

		void setCounter(ASpecies& spe);

		void showCounter();



};


#endif
