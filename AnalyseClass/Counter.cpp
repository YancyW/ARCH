#include "AnalyseClass/Counter.h"

void ACounter::Init(CDraw &para){
	AllEntries   = para.Total_Event();
	_xection     = para.file.xection;
	jetSwitch    = para.jet.SWITCH; 
	jetsSwitch   = para.jet.jets.SWITCH; 
	bjetSwitch   = para.jet.bjet.SWITCH; 
	cjetSwitch   = para.jet.cjet.SWITCH; 
	taujetSwitch = para.jet.taujet.SWITCH; 
	qjetSwitch   = para.jet.qjet.SWITCH; 
	lepSwitch    = para.lep.SWITCH; 
	elecSwitch   = para.lep.elec.SWITCH; 
	muonSwitch   = para.lep.muon.SWITCH; 
	metSwitch    = para.met.SWITCH; 
	combSwitch   = para.comb.SWITCH;
	recoilSwitch = para.recoil.SWITCH;
	recombSwitch = para.recoil.comb_SWITCH;
	mdSwitch     = para.MassDrop.SWITCH;
	nsubSwitch   = para.NSubjettiness.SWITCH;
	boostSwitch  = para.BoostTag.SWITCH;
	jetsubSwitch = para.jetsub.SWITCH;
	jepSwitch    = para.jep.SWITCH;
}


void ACounter::setWeight(float value){
	_weight = value;
}

void ACounter::setCounter(ASpecies& spe){
	for(ASpeciesType::iterator it = spe._species.begin(); it!=spe._species.end(); ++it ){
		////ShowMessage(2,"weight ",_weight);
		////ShowMessage(2,"num name",it->first);
		////ShowMessage(2,"num value",it->second);
		setCounterSingle(it->first,it->second.size()*_weight);	
		////ShowMessage(2,"next loop",0);
	}
}

void ACounter::setCounterSingle(std::string event_name,float num){
	_counter[event_name]=_counter[event_name]+num;
}


void ACounter::showCounter(){
	ShowMessage(2," OutPut --- Species for All Particle" );
	for(ACounterType::iterator it=_counter.begin(); it!= _counter.end(); ++it ){
		ShowMessage(2,"number  of "+it->first+" is" , it->second, "xection is", it->second/AllEntries*_xection);
	}
}


void ACounter::getCounter(std::string event_name){
	if(event_name=="basic"){
		pass_basic++;
	}
	else if(event_name=="basic_jet"){
		pass_basic_jet++;
	}
	else if(event_name=="basic_tagged_bjet"){
		pass_basic_bjet++;
	}
	else if(event_name=="basic_tagged_cjet"){
		pass_basic_cjet++;
	}
	else if(event_name=="basic_tagged_taujet"){
		pass_basic_taujet++;
	}
	else if(event_name=="basic_tagged_qjet"){
		pass_basic_qjet++;
	}
	else if(event_name=="basic_lep"){
		pass_basic_lep++;
	}
	else if(event_name=="basic_elec"){
		pass_basic_elec++;
	}
	else if(event_name=="basic_muon"){
		pass_basic_muon++;
	}
	else if(event_name=="basic_met"){
		pass_basic_met++;
	}
	else if(event_name=="operation_combine1"){
		pass_remass1++;
	}
	else if(event_name=="operation_combine2"){
		pass_remass2++;
	}
	else if(event_name=="operation_combine3"){
		pass_remass3++;
	}
	else if(event_name=="operation_combine4"){
		pass_remass4++;
	}
	else if(event_name=="operation_combine5"){
		pass_remass5++;
	}
	else if(event_name=="operation_combine6"){
		pass_remass6++;
	}
	else if(event_name=="operation_recoil"){
		pass_recoilmass++;
	}
	else if(event_name=="operation_recoil_comb"){
		pass_comb_recoil++;
	}
	else if(event_name=="JSS_Massdrop"){
		pass_massdrop++;
	}
	else if(event_name=="JSS_Nsubjettiness"){
		pass_nsubjettiness++;
	}
	else if(event_name=="JSS_BoostTag"){
		pass_boosttag++;
	}
	else if(event_name=="JSS"){
		pass_jetsub++;
	}
	else if(event_name=="JES_JEP"){
		pass_jep++;
	}
	else if(event_name=="All"){
		pass++;
	}
}



void ACounter::sendCounter(std::string event_name){
	if(event_name=="basic_jet"&& jetSwitch && jetsSwitch){
		ShowMessage(2,"number    passed cut basic  jet is        " , pass_basic_jet);
		float num=float(pass_basic_jet     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut basic  jet is        " , num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic_jet));
	}
	if(event_name=="basic_tagged_bjet"&& jetSwitch && jetsSwitch &&  bjetSwitch){
		float num=float(pass_basic_bjet     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut tagged bjet is       ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic_bjet));
	}
	if(event_name=="basic_tagged_cjet"&& jetSwitch && jetsSwitch &&  cjetSwitch){
		float num=float(pass_basic_cjet     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut tagged cjet is       ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic_cjet));
	}
	if(event_name=="basic_tagged_taujet"&& jetSwitch && jetsSwitch &&  taujetSwitch){
		float num=float(pass_basic_taujet     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut tagged taujet is     ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic_taujet));
	}
	if(event_name=="basic_tagged_qjet"&& jetSwitch && jetsSwitch &&  qjetSwitch){
		float num=float(pass_basic_qjet     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut tagged qjet is       ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic_qjet));
	}
	if(event_name=="basic_lep"&& lepSwitch && !elecSwitch && !muonSwitch ){
		float num=float(pass_basic_lep     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut baisc lep  is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic_lep));
	}
	if(event_name=="basic_elec"&& lepSwitch && elecSwitch && !muonSwitch ){
		float num=float(pass_basic_elec     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut baisc elec is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic_elec));
	}
	if(event_name=="basic_muon"&& lepSwitch && !elecSwitch && muonSwitch ){
		float num=float(pass_basic_muon     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut basic muon is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic_muon));
	}
	if(event_name=="basic_met"&& metSwitch){
		float num=float(pass_basic_met     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut basic  met is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic_met));
	}
	if(event_name=="basic" ){
		float num=float(pass_basic     )/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut basic is             ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_basic));
	}
	if(event_name=="operation_combine1"&& combSwitch){
		float num=float(pass_remass1)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut remass1    is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_remass1));
	}
	if(event_name=="operation_combine2"&& combSwitch){
		float num=float(pass_remass2)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut remass2    is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_remass2));
	}
	if(event_name=="operation_combine3"&& combSwitch){
		float num=float(pass_remass3)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut remass3    is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_remass3));
	}
	if(event_name=="operation_combine4"&& combSwitch){
		float num=float(pass_remass4)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut remass4    is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_remass4));
	}
	if(event_name=="operation_combine5"&& combSwitch){
		float num=float(pass_remass5)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut remass5    is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_remass5));
	}
	if(event_name=="operation_combine6"&& combSwitch){
		float num=float(pass_remass6)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut remass6    is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_remass6));
	}
	if(event_name=="operation_recoil"&& recoilSwitch){
		float num=float(pass_recoilmass)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut recoilmass is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_recoilmass));
	}
	if(event_name=="operation_recoil_comb"&& recombSwitch){
		float num=float(pass_comb_recoil)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut comb recoil is       ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_comb_recoil));
	}
	if(event_name=="JSS_Massdrop"&& mdSwitch){
		float num=float(pass_massdrop)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut MassDrop   is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_massdrop));
	}
	if(event_name=="JSS_Nsubjettiness"&& nsubSwitch){
		float num=float(pass_nsubjettiness)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut NSubjettiness is     ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_nsubjettiness));
	}
	if(event_name=="JSS_BoostTag"&& boostSwitch){
		float num=float(pass_boosttag)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut BoostTag   is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_boosttag));
	}
	if(event_name=="JSS"&& jetsubSwitch){
		float num=float(pass_jetsub)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut JetSubStructure is   " ,num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_jetsub));
	}
	if(event_name=="JES_JEP"&& jepSwitch){
		float num=float(pass_jep)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut JEP        is        ", num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass_jep));
	}
	if(event_name=="All"){
		float num=float(pass)/float(AllEntries);
		float cut_xection=num *_xection;
		ShowMessage(2,"efficient passed cut all        is        " ,num, "xection is", cut_xection);
		setCounterSingle(event_name,float(pass));
	}
}
void ACounter::sendCounter(){
	ShowMessage(2," OutPut --- Efficience for Cut" );
	ShowMessage(2,"all entries are                      " , AllEntries);
	ShowMessage(2,"total cross section is               " , _xection);
	sendCounter("basic_jet");
	sendCounter("basic_tagged_bjet");
	sendCounter("basic_tagged_cjet");
	sendCounter("basic_tagged_taujet");
	sendCounter("basic_tagged_qjet");
	sendCounter("basic_lep");
	sendCounter("basic_elec");
	sendCounter("basic_muon");
	sendCounter("basic_met");
	sendCounter("basic");
	sendCounter("operation_combine1");
	sendCounter("operation_combine2");
	sendCounter("operation_combine3");
	sendCounter("operation_combine4");
	sendCounter("operation_combine5");
	sendCounter("operation_combine6");
	sendCounter("operation_recoil");
	sendCounter("operation_recoil_comb");
	sendCounter("JSS_Massdrop");
	sendCounter("JSS_Nsubjettiness");
	sendCounter("JSS_BoostTag");
	sendCounter("JSS");
	sendCounter("JSS_JEP");
	sendCounter("All");
	ShowMessage();
	ShowMessage(2,"");
}

void ACounter::Clear(){
	pass_basic        =0;
	pass_basic_jet    =0, pass_basic_bjet=0,pass_basic_cjet=0,pass_basic_qjet=0,pass_basic_taujet=0;
	pass_basic_lep    =0, pass_basic_elec=0,pass_basic_muon=0,pass_basic_met =0;
	pass_basic_photon =0;
	pass_combine      =0;
	pass_remass1      =0, pass_remass2   =0, pass_remass3   =0, pass_remass4   =0, pass_remass5   =0, pass_remass6   =0, pass_recoilmass=0;
	pass_comb_recoil  =0;
	pass_jetsub       =0;
	pass_boosttag     =0, pass_massdrop=0, pass_nsubjettiness=0;
	pass_jeteventshape=0, pass_jep          =0;
	pass              =0;

	jetSwitch         = false;
	jetsSwitch        = false;
	bjetSwitch        = false;
	cjetSwitch        = false;
	taujetSwitch      = false;
	lepSwitch         = false;
	elecSwitch        = false;
	muonSwitch        = false;
	metSwitch         = false;
	combSwitch        = false;
	recoilSwitch      = false;
	recombSwitch      = false;
	mdSwitch          = false;
	nsubSwitch        = false;
	boostSwitch       = false;
	jetsubSwitch      = false;
	jepSwitch         = false;
	jesSwitch         = false;

	_counter          .clear();
	_weight           = 1;
	_xection          = 0;
}
