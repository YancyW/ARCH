#include "Class/DrawClass.h"
void CDraw::Read(){
	ShowMessage(3, "Begin to read all input infomation.");

	ShowMessage(3, "read path.");
	this->path.Read_Path(this->steering_file);
	Jpath = true;

	ShowMessage(3, "read file.");
	this->file.Read_File(path);
	Jfile = true;

	ShowMessage(3, "read debug.");
	this->debug.Read_Debug(path);
	Jdebug = true;

	ShowMessage(3, "read flow.");
	this->flow.Read_Flow(path);
	Jflow = true;

	ShowMessage(3, "read signal.");
	this->signal.Read_Signal(path.signal_file);
	Jsignal= true;

	ShowMessage(3, "read event.");
	this->event.Read_Event(path);
	Jevent = true;
 
	ShowMessage(3, "read jet.");
  	this->jet.Read_Jet(path);
	Jjet = true;
 
	ShowMessage(3, "read lepton.");
  	this->lep.Read_Lepton(path);
	Jlepton = true;

	ShowMessage(3, "read photon.");
	this->photon.Read_Photon(path);
	Jphoton = true;

	ShowMessage(3, "read met.");
	this->met.Read_Met(path);
	Jmet = true;

	ShowMessage(3, "read combine.");
	this->comb.Read_Combine(path);
	Jcombine = true;

	ShowMessage(3, "read recoil.");
	this->recoil.Read_Recoil(path);
	Jrecoil = true;

	ShowMessage(3, "read tag.");
	this->tag.Read_Tag(path);
	Jtag = true;

	ShowMessage(3, "read global.");
	this->global.Read_Global(path);
	Jglobal = true;

	ShowMessage(3, "read jet substructure.");
	this->jetsub.Read_JetSubStructure(path);
	Jjetsub = true;

	ShowMessage(3, "read jet massdrop.");
	this->MassDrop.Read_MassDrop(path);
	JMassDrop = true;

	ShowMessage(3, "read jet nsubjettiness.");
	this->NSubjettiness.Read_NSubjettiness(path);
	JNSubjettiness = true;

	ShowMessage(3, "read jet boost tag.");
	this->BoostTag.Read_BoostTag(path);
	JBoostTag = true;

	ShowMessage(3, "read jet JEP.");
	this->jep.Read_JEP(path);
	Jjep = true;

	ShowMessage(3, "read detector simulation parameter.");
	this->detector.Read_Detector(path);
	JDetector = true;

}
