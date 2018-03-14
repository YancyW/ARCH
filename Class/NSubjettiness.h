#ifndef GLOBAL_PARA_NSUBJETTINESS
#define GLOBAL_PARA_NSUBJETTINESS
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "fastjet/PseudoJet.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/contribs/Nsubjettiness/Nsubjettiness.hh"
#include "fastjet/contribs/Nsubjettiness/Njettiness.hh"
#include "fastjet/contribs/Nsubjettiness/NjettinessPlugin.hh"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/file.h"

class CNSubjettiness{
	private:
	public:

		// Simple class to store Axes along with a name for display
		class CAxesStruct {

			private:
				// Shared Ptr so it handles memory management
				fastjet::SharedPtr<fastjet::contrib::AxesDefinition> _axes_def;

			public:
				CAxesStruct(const fastjet::contrib::AxesDefinition & axes_def)
					: _axes_def(axes_def.create()) {}

				// Need special copy constructor to make it possible to put in a std::vector
				CAxesStruct(const CAxesStruct& myStruct)
					: _axes_def(myStruct._axes_def->create()) {}

				const fastjet::contrib::AxesDefinition & def() const {return *_axes_def;}
				std::string description() const {return _axes_def->description();}
				std::string short_description() const {return _axes_def->short_description();}

		};



		// Simple class to store Measures to make it easier to put in std::vector
		class CMeasureStruct {

			private:
				// Shared Ptr so it handles memory management
				fastjet::SharedPtr<fastjet::contrib::MeasureDefinition> _measure_def;

			public:
				CMeasureStruct(const fastjet::contrib::MeasureDefinition& measure_def)
					: _measure_def(measure_def.create()) {}

				// Need special copy constructor to make it possible to put in a std::vector
				CMeasureStruct(const CMeasureStruct& myStruct)
					: _measure_def(myStruct._measure_def->create()) {}

				const fastjet::contrib::MeasureDefinition & def() const {return *_measure_def;}
				std::string description() const {return _measure_def->description();}

		};


		bool     SWITCH       ;
		bool     PLOT         ;

		float   beta         ;
		float   delta        ;
		float   p            ;
		float   R0           ;
		float   Rcut         ;

		std::string    measuretype  ;
		std::string    axestype     ;

		float   epsilon      ;

		bool     JCUT_tau1    ;
		float   CUT_tau1d    ;
		float   CUT_tau1u    ;

		bool     JCUT_tau2    ;
		float   CUT_tau2d    ;
		float   CUT_tau2u    ;

		bool     JCUT_tau3    ;
		float   CUT_tau3d    ;
		float   CUT_tau3u    ;

		bool     JCUT_tau21   ;
		float   CUT_tau21d   ;
		float   CUT_tau21u   ;

		bool     JCUT_tau32   ;
		float   CUT_tau32d   ;
		float   CUT_tau32u   ;

		void Read_NSubjettiness(CPath path)   ;

		CAxesStruct    GetAxes(){
			if(this->axestype=="kt"){
				return(fastjet::contrib::KT_Axes());
			}
			else if(this->axestype=="ca"){
				return(fastjet::contrib::CA_Axes());
			}
			else if(this->axestype=="antikt"){
				return(fastjet::contrib::AntiKT_Axes(this->R0));
			}
			else if(this->axestype=="wta_kt"){
				return(fastjet::contrib::WTA_KT_Axes());
			}
			else if(this->axestype=="wta_ca"){
				return(fastjet::contrib::WTA_CA_Axes());
			}
			else if(this->axestype=="wta_genkt"){
				return(fastjet::contrib::WTA_GenKT_Axes(this->p,this->R0));
			}
			else if(this->axestype=="wta_genkt"){
				return(fastjet::contrib::GenET_GenKT_Axes(this->delta,this->p,this->R0));
			}

			else if(this->axestype=="onepass_kt"){
				return(fastjet::contrib::OnePass_KT_Axes());
			}
			else if(this->axestype=="onepass_antikt"){
				return(fastjet::contrib::OnePass_AntiKT_Axes(this->R0));
			}
			else if(this->axestype=="onepass_wta_kt"){
				return(fastjet::contrib::OnePass_WTA_KT_Axes());
			}
			else if(this->axestype=="onepass_genkt"){
				return(fastjet::contrib::OnePass_GenKT_Axes(this->p,this->R0));
			}
			else if(this->axestype=="onepass_wta_genkt"){
				return(fastjet::contrib::OnePass_WTA_GenKT_Axes(this->p,this->R0));
			}
			else if(this->axestype=="onepass_genet_genkt"){
				return(fastjet::contrib::OnePass_GenET_GenKT_Axes(this->delta,this->p,this->R0));
			}
			else{
				ShowMessage(1,"not define this axestype in CNSubjettiness class");
				exit(0);
			}

		} ;

		CMeasureStruct GetMeasure()             
		{
			if(this->measuretype=="Normalized"){
				return(fastjet::contrib::  NormalizedMeasure(this->beta,1.0));
			}
			else if(this->measuretype=="UnNormalized"){
				return(fastjet::contrib::UnnormalizedMeasure(this->beta));
			}
			else{
				ShowMessage(1,"not define this measuretype in CNSubjettiness class");
				exit(0);
			}
		};
};
#endif

