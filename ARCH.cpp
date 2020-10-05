
#include "Fram/Fsection.h"
#include "Fram/Fram.h"
#include "Lib/MessageFormat.h"
#include "Function/Fvector.h"
#include "Class/DrawClass.h"
#include "AnalyseClass/AnalyseClass.h"
#include "Function/Ftest.h"

int AParticle::_global_id  =0;
int AParticle::_instruct_id=0;

int main(int argc, char*argv[]) {

 	CDraw para;

	if(argc==2){
		para.steering_file = argv[1];
	}
	else{
		para.steering_file = "control/path.dat";
	}

	StartProcess();

	LoadFile(para);

	LoadLibrary(para);

	SetPlot();

	if(para.flow.begin_object=="test"){
		Test_Function(para);
	}
	else{
		Fram(para);
	}

	EndProcess();

    return 0;
}
