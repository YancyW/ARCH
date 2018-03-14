#include "AnalyseClass/Stdhep.h"
void AStdhep::Init(std::string filename, bool judge){
	////		FILE *inputFile=0;
	////		Long64_t length, eventCounter = 0;
	////		TStopwatch readStopWatch, procStopWatch;


	////		inputFile = fopen(filename.c_str(),"r");
	////		reader = new DelphesSTDHEPReader;
	////		reader->SetInputFile(inputFile);
	////		ExRootProgressBar progressBar(-1);
	////		eventCounter = 0;

	////		reader->Clear();
	////		while(reader->ReadBlock(factory, allParticleOutputArray,stableParticleOutputArray, partonOutputArray) && !interrupted)
	////		{
	////			if(reader->EventReady())
	////			{
	////				++eventCounter;

	////				reader->AnalyzeEvent(branchEvent, eventCounter);

	////			}

	////			reader->Clear();
	////		}
}

void AStdhep::Clear(){

}
