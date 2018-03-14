#include "Fram/Fsection.h"
//------------------------------------------------------------------------------
//
void StartProcess(){
	ShowMessage();
	ShowMessage(1,"--------------------------------------------------------------------------------------------------------------------");
    ShowMessage(1,"-                                          DrawBeauty release 0.14                                                 -");
    ShowMessage(1,"-                                                  Yan Wang                                                        -");
    ShowMessage(1,"-                                        email:wangyan728@ihep.ac.cn                                               -");
    ShowMessage(1,"-                                           or:yan.wang@desy.de                                                    -");
	ShowMessage(1,"-                                                                                                                  -");
    ShowMessage(1,"-                                 A software package for analysis and plot at colliders.                           -");
	ShowMessage(1,"-                                                                                                                  -");
    ShowMessage(1,"-                                Please cite if you use this package or part of my code.                           -");
	ShowMessage(1,"-                                                                                                                  -");
    ShowMessage(1,"-                     DrawBeauty is provided without warranty under the terms of the GNU GPLv2.                    -");
    ShowMessage(1,"-                                      It uses Delphes ,ExRoot and Root lib.                                       -");
    ShowMessage(1,"-                     Part of the code follow others' sample (in README), Thanks to them.                          -");
	ShowMessage(1,"-                                                                                                                  -");
	ShowMessage(1,"-                                      For checking what's new, please README.                                     -");
	ShowMessage(1,"-                                                                                                                  -");
	ShowMessage(1,"--------------------------------------------------------------------------------------------------------------------");
	ShowMessage();
}



//------------------------------------------------------------------------------
//
void LoadFile(CDraw &para){
	ShowMessage(1, "load para");
	ShowMessage();
	YAML::Node basic_node = YAML::LoadFile("control/basic.dat");

//	CLoad para;

	para.Jpath = basic_node["FILE_filepath"].as<bool>();	
	ShowMessage(2, "Reading the file path   ",para.Jpath);

	para.Jdebug = basic_node["FILE_debug"].as<bool>();	
	ShowMessage(2, "Reading the file debug  ",para.Jdebug);

	para.Jflow = basic_node["FILE_flow"].as<bool>();	
	ShowMessage(2, "Reading the file flow   ",para.Jflow);

	para.Jsignal = basic_node["FILE_signal"].as<bool>();	
	ShowMessage(2, "Reading the file signal ",para.Jsignal);

	para.Jjet = basic_node["FILE_jet"].as<bool>();	
	ShowMessage(2, "Reading the file jet    ",para.Jjet);

	para.Jlepton = basic_node["FILE_lepton"].as<bool>();	
	ShowMessage(2, "Reading the file lepton ",para.Jlepton);

	para.Jmet = basic_node["FILE_mEt"].as<bool>();	
	ShowMessage(2, "Reading the file mEt    ",para.Jmet);

	para.Jphoton = basic_node["FILE_photon"].as<bool>();	
	ShowMessage(2, "Reading the file photon ",para.Jphoton);

	para.Jcombine = basic_node["FILE_recombine"].as<bool>();	
	ShowMessage(2, "Reading the file combine",para.Jcombine);

	para.Jrecoil = basic_node["FILE_recoil"].as<bool>();	
	ShowMessage(2, "Reading the file recoil",para.Jrecoil);

	para.Jglobal = basic_node["FILE_global"].as<bool>();	
	ShowMessage(2, "Reading the file global ",para.Jglobal);
	ShowMessage();

  	para.Read();
	ShowMessage();
}

//------------------------------------------------------------------------------
//
void LoadLibrary(CDraw &para){

	ShowMessage(1,"load libraray"); 
	ShowMessage();

  	ShowMessage(2,"load delphes"); 
  	gSystem->Load("./libDelphes");

	ShowMessage(2,"load fastjet"); 

	std::vector<fastjet::PseudoJet> jet_constituents;
	fastjet::JetDefinition jet_def(fastjet::antikt_algorithm, 0.7);
	fastjet::ClusterSequence cs( jet_constituents, jet_def );
	if(!para.flow.record_output){
		fclose(stdout);
		freopen("/dev/tty","w",stdout);
	}

	gErrorIgnoreLevel = kWarning, kError, kBreak, kSysError, kFatal;
}


//------------------------------------------------------------------------------
//
void SetPlot(){
	ShowMessage(1,"set plot style");
	ShowMessage();
	gStyle->SetOptStat(0);
	clock_t start, finish; 
	SetSgStyle();
}

//------------------------------------------------------------------------------
//
void EndProcess(){
	ShowMessage();
	ShowMessage(1,"end");
}
