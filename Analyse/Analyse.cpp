#include "Analyse.h" 
//------------------------------------------------------------------------------


void AnalyseEvents(CDraw &para, ExRootTreeReader *treeReader, TChain* tree, MyPlots *plots)
{
	para.debug.Message(1,1,"enter analyse");

	para.Init(treeReader);

	bool Jparticle    = false;
	bool Jcombine     = false;
	bool Jjetsub      = false;


	//defined jep variables
	size_t nr = int(para.jet.jets.CUT_cone_jet[0]/0.1)+1;//number of bins for r-axis
	//cut on jet invariant mass
	//**********************************************************

	float  Phi_r[nr];
	float  Phi_r_test[nr];
	float  Phi2_r[nr];
	float  Phi2_r_test[nr];
	float  smallr[nr];
	for( size_t Cindex = 0; Cindex < nr; ++Cindex ) {
		Phi_r      [Cindex] = 0.0;
		Phi_r_test [Cindex] = 0.0;
		Phi2_r     [Cindex] = 0.0;
		Phi2_r_test[Cindex] = 0.0;
		smallr     [Cindex] = (Cindex+1)*0.1;
	}//endfor Cindex



	AnalyseClass analyse(para,treeReader,tree);
	// Loop over all events

	para.debug.Message(1,1,"in AnalyseEvents: begin loop event, totally Event number is:",para.event.Begin_Event(),para.event.End_Event());
	for(long long int entry = para.event.Begin_Event(); entry < para.event.End_Event(); ++entry)
	{
		para.Get_Event(entry);
		para.debug.Message(2,1,"event num",para.Event());
		CountNumber(entry,para.Total_Event(),1000,"has dealed with number are");

		para.debug.Message(1,2,"in AnalyseEvents: load data to tree.");
		if((para.flow.begin_object=="slcio_particle")||(para.flow.begin_object=="slcio_equipment")){
			tree->GetEntry(entry);
		}
		else if((para.flow.begin_object=="delphes_particle")||(para.flow.begin_object=="delphes_equipment")||(para.flow.begin_object=="delphes_detector")){
			treeReader->ReadEntry(entry);
		}
		else if((para.flow.begin_object=="stdhep_particle")){
		}
		else{
			return;
		}

		// clear std::vector before each loop
		para.debug.Message(1,2,"in AnalyseEvents: load data to object.");
		AObject object(analyse,para);

		// Analyse jets
		para.debug.Message(1,2,"in AnalyseEvents: enter GetFinalState.");
		if(para.flow.begin_object=="delphes_detector"){
			para.debug.Message(2,2,"begin detector");
			Jparticle=GetFinalState(para, analyse.delphes.branchJet, analyse.delphes.branchElectron, analyse.delphes.branchMuon,analyse.delphes.branchPhoton, analyse.delphes.branchMissingET,analyse.delphes.branchParticle,plots,
					object.Vjet,object.Vbjet,object.Vcjet,object.Vqjet,object.Vtaujet, object.Vtagjet,object.Vuntagjet,object.Velec,object.Vmuon,object.Vtau,object.Vphoton,object.Vmet,analyse);
			para.debug.Message(2,2,"end detector",Jparticle);
			if(!Jparticle){continue;}
		}
		else if(para.flow.begin_object=="delphes_equipment"){
			para.debug.Message(2,2,"begin equipment");
			Jparticle=GetFinalState(para, analyse.delphes.branchEFlowTrack, analyse.delphes.branchEFlowNeutralHadron, analyse.delphes.branchEFlowPhoton,analyse.delphes.branchElectron, analyse.delphes.branchMuon, analyse.delphes.branchMissingET,plots,
					analyse.delphes.branchParticle,
					object.VPseudoJet,object.Vbquark,object.Vcquark,object.Velec,object.Vmuon,object.Vphoton,object.Vmet,analyse);
			para.debug.Message(2,2,"end equipment",Jparticle);
			if(!Jparticle){continue;}
		}
		else if(para.flow.begin_object=="delphes_particle"){
			para.debug.Message(2,2,"begin particle");
			Jparticle=GetFinalState(para, analyse, object,  plots);
			para.debug.Message(2,2,"end particle",Jparticle);
			if(!Jparticle){continue;}
		}
		else if(para.flow.begin_object=="slcio_particle"){
			para.debug.Message(2,2,"begin slcio_particle");
			Jparticle=GetFinalState(para, analyse, object,  plots);
			para.debug.Message(2,2,"end slcio particle",Jparticle);
			if(!Jparticle){continue;}
		}
		else{Jparticle=true;}

        if(para.flow.begin_object=="delphes_detector"){
    		para.debug.Message(2,2,"		begin combine");
			Jcombine=GetCombine(para,plots,object,analyse);
    		para.debug.Message(2,2,"end combine",Jcombine);
    		if(!Jcombine){continue;}
    	}
    	else{Jcombine=true;}


    	if(para.jetsub.SWITCH){
    		para.debug.Message(2,2,"begin Jet SubStructure");
    		Jjetsub=AJetSubStructure(para,plots,object.Vjet,object.VPseudoJet,object.Vbquark,object.Vcquark,object.Vbjet,object.Vcjet, object.Vqjet,object.Velec,object.Vmuon,object.Vcombine_jet1,object.Vcombine_jet2, object.Vcombine_elec1, object.Vcombine_elec2, object.Vcombine_muon1, object.Vcombine_muon2,Phi_r,Phi_r_test,nr,analyse);
    		para.debug.Message(2,2,"end Jet SubStructure",Jjetsub);
    		if(!Jjetsub){continue;}
    		para.debug.Message(2,2,"the entry is ",entry);
    	}
    	else{Jjetsub=true;}

    	para.debug.Message(2,2,"finish all cut.");
    	if(Jparticle&&Jcombine&&Jjetsub){
    		analyse.counter.getCounter("All");
    	}
    	else{continue;}

    	para.debug.Message(2,2,"finish one loop.");
	}


    if(para.jep.SWITCH ){
    	ShowMessage();
    	ShowMessage(2,"JEP1");

    	for( size_t r_Cindex = 0; r_Cindex < nr; ++r_Cindex ) {
    		Phi_r     [r_Cindex] = Phi_r     [r_Cindex]/ Phi_r     [nr-1];
    		Phi_r_test[r_Cindex] = Phi_r_test[r_Cindex]/ Phi_r_test[nr-1];
    		ShowMessage(2, (r_Cindex+1)*0.1, Phi_r[r_Cindex]);
    		//	ShowMessage(2, (r_Cindex+1)*0.1, Phi_r[r_Cindex]-Phi_r_test[r_Cindex]);
    	}//endfor r_Cindex

    }

    analyse.counter.showCounter();
    analyse.counter.sendCounter();
}




