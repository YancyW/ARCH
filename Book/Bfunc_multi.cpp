#include "Bfunc_multi.h"
void BookH_multi_observable(CDraw &para, ExRootResult *result, MyPlots *plots,int plot_num,
		std::string filter_name, std::string class_name, 
		std::string observe_name, int observe_num, std::vector<std::string> sampledescrip){
	std::string title,descrip;
	THStack *stack;
	TLegend *legend;
	TH1     *h1;
	std::string s_obnum, s_desnum;
	int color;

	para.debug.Message(2,1,"book multi observable 1");
	if (observe_num==0){
		title = filter_name + class_name+"_" + observe_name;
		descrip = class_name+" " + observe_name;
	}
	else{
		s_obnum = std::to_string(observe_num);
		s_desnum= Int_to_String_descrip(observe_num);

		title = filter_name + class_name+"_" + observe_name +"_" + s_obnum;
		descrip = s_desnum + " " +  class_name+" " + observe_name;
	}

	para.debug.Message(2,1,"book multi observable title",title);
	para.debug.Message(2,1,"book multi observable descrip",descrip);
	stack = result->AddHistStack(title.c_str(), descrip.c_str());

	legend = result->AddLegend(0.57, 0.88-plot_num*0.05, 0.88, 0.88);

	// book 1 stack of some histograms
	for (int i=0;i<plot_num;i++){
	    para.debug.Message(2,1,"book multi observable get class ptr");
		h1= Get_Class_ptr(para, plots+i,class_name,observe_name,observe_num);
		if(i>=9){
			color=i+2;
		}
		else{
			color=i+1;
		}
		h1->SetLineColor(color);
		stack->Add(h1);

		legend->AddEntry(h1,sampledescrip[i].c_str(), "l");
	}

	para.debug.Message(2,1,"book multi observable plot");
	// attach legend to stack (legend will be printed over stack in .eps file)
	result->Attach(stack, legend);
}



void BookH_multi_observable_loop(CDraw &para, ExRootResult *result, MyPlots *plots,int plot_num,
		std::string filter_name, std::string class_name, 
		std::string observe_name,int observe_num, std::vector<std::string> sampledescrip){

	if (observe_num>=1){
		for (int i=0;i<observe_num;i++){
			BookH_multi_observable(para, result,plots,plot_num,filter_name,class_name,observe_name, i,sampledescrip);
		}

	}
}

