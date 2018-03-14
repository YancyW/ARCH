#include "Class/DrawClass.h"
void CDraw::Read(){
	ShowMessage(3, "Begin to read all input infomation.");

	this->path.Read_Path(this->steering_file);
	Jpath = true;

	this->file.Read_File(path);
	Jfile = true;

	this->debug.Read_Debug(path);
	Jdebug = true;

	this->flow.Read_Flow(path);
	Jflow = true;

	this->signal.Read_Signal(path);
	Jsignal= true;

	this->event.Read_Event(path);
	Jevent = true;
 
  	this->jet.Read_Jet(path);
	Jjet = true;
 
  	this->lep.Read_Lepton(path);
	Jlepton = true;

	this->photon.Read_Photon(path);
	Jphoton = true;

	this->met.Read_Met(path);
	Jmet = true;

	this->comb.Read_Combine(path);
	Jcombine = true;

	this->recoil.Read_Recoil(path);
	Jrecoil = true;

	this->tag.Read_Tag(path);
	Jtag = true;

	this->global.Read_Global(path);
	Jglobal = true;

	this->jetsub.Read_JetSubStructure(path);
	Jjetsub = true;

	this->MassDrop.Read_MassDrop(path);
	JMassDrop = true;

	this->NSubjettiness.Read_NSubjettiness(path);
	JNSubjettiness = true;

	this->BoostTag.Read_BoostTag(path);
	JBoostTag = true;

	this->jep.Read_JEP(path);
	Jjep = true;

	this->detector.Read_Detector(path);
	JDetector = true;

}
