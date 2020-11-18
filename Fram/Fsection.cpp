#include "Fram/Fsection.h"
//------------------------------------------------------------------------------
//
void StartProcess(){
	ShowMessage();
	ShowMessage(1,"--------------------------------------------------------------------------------------------------------------------");
    ShowMessage(1,"-                                                  ARCH                                                            -");
    ShowMessage(1,"-                                          Analyse_Root_CHarmedly                                                  -");
    ShowMessage(1,"-                                                release 0.1.4                                                     -");
    ShowMessage(1,"-                                                  Yan Wang                                                        -");
    ShowMessage(1,"-                                        email:wangyan728@ihep.ac.cn                                               -");
    ShowMessage(1,"-                                           or:yan.wang@desy.de                                                    -");
	ShowMessage(1,"-                                                                                                                  -");
    ShowMessage(1,"-                                 A software package for analysis and plot at colliders.                           -");
	ShowMessage(1,"-                                                                                                                  -");
    ShowMessage(1,"-                                Please cite if you use this package or part of my code.                           -");
	ShowMessage(1,"-                                                                                                                  -");
    ShowMessage(1,"-                     ARCH is provided without warranty under the terms of the GNU GPLv2.                          -");
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
	ShowMessage(2, "load para");
	ShowMessage(3, "input path file   ",para.steering_file);
	ShowMessage();

//	CLoad para;
	para.Read();

	ShowMessage(2, "Reading the file path   ",para.Jpath);

	ShowMessage(2, "Reading the file debug  ",para.Jdebug);

	ShowMessage(2, "Reading the file flow   ",para.Jflow);

	ShowMessage(2, "Reading the file signal ",para.Jsignal);

	ShowMessage(2, "Reading the file jet    ",para.Jjet);

	ShowMessage(2, "Reading the file lepton ",para.Jlepton);

	ShowMessage(2, "Reading the file mEt    ",para.Jmet);

	ShowMessage(2, "Reading the file photon ",para.Jphoton);

	ShowMessage(2, "Reading the file combine",para.Jcombine);

	ShowMessage(2, "Reading the file recoil",para.Jrecoil);

	ShowMessage(2, "Reading the file global ",para.Jglobal);

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
