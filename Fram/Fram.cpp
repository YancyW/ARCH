#include "Fram.h"
void Fram(CDraw &para)
{
	//read in the cross section
	ShowMessage(1,"begin to analysis"); 

	ExRootResult *result = new ExRootResult();

	MyPlots *plot = new MyPlots [para.file.file_num] (); 
	Long64_t sample_num[para.file.file_num];

	for (int i=0;i<para.file.file_num;i++){
		Analyse_BasicInfo(para, result,para.file.file[i],para.file.file_descrip[i],sample_num[i]);
	}

	if(para.flow.level==1){
		para.debug.Message(3,70,"in Fram, Exit: only show total number of the event.");
		exit(0);
	}
	else if(para.flow.level==2){
		para.debug.Message(3,70,"in Fram, plot only one file.");
		for (int i=0;i<para.file.file_num;i++){
			Fillplot(para, plot+i,result,para.file.file[i],para.file.file_descrip[i]);
		}

		if(para.file.file_num>1 && para.flow.plot){
			BookHistograms_multi(para,result, plot,para.file.file_num,para.file.file_descrip);
		}
	}
	else if(para.flow.level==3){
		para.debug.Message(3,70,"in Fram, plot for more files.");
		Fillplot_all(para, plot,result,para.file.file,para.file.file_descrip,sample_num);
	}
	else{
		ShowMessage(1,"no such level in Fram.cpp");
	}

	if(para.flow.plot){
		para.debug.Message(3,70,"in Fram, begin to print histogram.");
		PrintHistograms(result, plot);
	}

	if(para.flow.record_event){
		para.debug.Message(3,70,"in Fram, write data to root file.");
		std::string output_name=para.path.output_file+para.path.process+".root";
		result->Write(output_name.c_str());
	}

    delete result;
    delete [] plot;
}


void Analyse_BasicInfo(CDraw &para, ExRootResult *result, std::string sigfile, std::string sampledescrip, Long64_t &sample_num)
{
	TChain chainsig;
	std::string tree_name;


	para.debug.Message(3,71,"in Analyse_BasicInfo, begin to choose input data");
	if((para.flow.begin_object=="slcio_particle")||(para.flow.begin_object=="slcio_equipment")){
		tree_name=sigfile+"/MyLCTuple";
	}
	else if((para.flow.begin_object=="delphes_particle")||(para.flow.begin_object=="delphes_equipment")||(para.flow.begin_object=="delphes_detector")){
		tree_name=sigfile+"/Delphes";
	}
	else if((para.flow.begin_object=="stdhep_particle")){
	}
	else{
		return;
	}


	para.debug.Message(3,71,"in Analyse_BasicInfo, add file to Tchain",tree_name);


	chainsig.Add(tree_name.c_str());
	para.debug.Message(3,71,"in Analyse_BasicInfo, get tree from Tchain");
	sample_num = chainsig.GetEntries();

	ShowMessage();
	ShowMessage(1,"analyse channel",sampledescrip);
	ShowMessage(1,"total number is",sample_num);
	ShowMessage(1,"");
	ShowMessage();
}


void Fillplot(CDraw &para, MyPlots *plot_ptr, ExRootResult *result, std::string sigfile, std::string sampledescrip)
{
	para.debug.Message(3,72,"in Framplot, begin to plot with one files");
	if(para.flow.plot){
		para.debug.Message(3,72,"in Framplot, book for plot");
		BookHistograms_single(para,result, plot_ptr,sampledescrip);
	}

	TChain chainsig;
	std::string tree_name;

	if((para.flow.begin_object=="slcio_particle")||(para.flow.begin_object=="slcio_equipment")){
		tree_name=sigfile+"/MyLCTuple";
	}
	else if((para.flow.begin_object=="delphes_particle")||(para.flow.begin_object=="delphes_equipment")||(para.flow.begin_object=="delphes_detector")){
		tree_name=sigfile+"/Delphes";
	}
	else if((para.flow.begin_object=="stdhep_particle")){
	}
	else{
		return;
	}

	para.debug.Message(3,72,"in Framplot, add file to Tchain",tree_name);
	chainsig.Add(tree_name.c_str());

	para.debug.Message(3,72,"in Framplot, point to TChain");
	ExRootTreeReader *treeReaderSig = new ExRootTreeReader(&chainsig);

	ShowMessage();
	ShowMessage(1,"analyse channel",sampledescrip);

	para.debug.Message(3,72,"in Framplot, begin into AnalyseEvents");
	AnalyseEvents(para, treeReaderSig, &chainsig, plot_ptr);

}


void Fillplot_all(CDraw &para, MyPlots *plot_ptr, ExRootResult *result, std::vector<std::string> sigfile, std::vector<std::string> sampledescrip, Long64_t sample_num[])
{
	para.debug.Message(3,73,"in Framplot_all, get TTree from TChain");
	if(para.flow.plot){
		para.debug.Message(3,73,"in Framplot_all, book for plot");
		BookHistograms_single(para,result, plot_ptr,sampledescrip[0]);
	}

	TChain chainsig;
	std::string tree_name;

	for(int i=0;i<sigfile.size();i++){
		if((para.flow.begin_object=="slcio_particle")||(para.flow.begin_object=="slcio_equipment")){
			tree_name=sigfile[i]+"/MyLCTuple";
		}
		else if((para.flow.begin_object=="delphes_particle")||(para.flow.begin_object=="delphes_equipment")||(para.flow.begin_object=="delphes_detector")){
			tree_name=sigfile[i]+"/Delphes";
		}
		else if((para.flow.begin_object=="stdhep_particle")){
		}
		else{
		}
		para.debug.Message(3,73,"in Framplot_all, add file to Tchain",tree_name);
		chainsig.Add(tree_name.c_str());
	}

	para.debug.Message(3,73,"in Framplot_all, point to TChain");
	ExRootTreeReader *treeReaderSig = new ExRootTreeReader(&chainsig);

	ShowMessage();
	ShowMessage(1,"analyse all channel together");


	para.debug.Message(3,73,"in Framplot_all, begin into AnalyseEvents");
	AnalyseEvents(para, treeReaderSig, &chainsig, plot_ptr);

}

