#include "Bfunc_single.h"
void BookH_single_number(ExRootResult *result, TH1 **h1, std::string signal_name, std::string class_name){
	std::string title,descrip,axis_x,axis_y;

	title = signal_name + "_" + class_name + "_number";

	descrip = "total "+class_name+" number";

	axis_x = class_name + " Number";
	axis_y = "number of events";

	*h1 = result->AddHist1D(
			title.c_str(), descrip.c_str(),
			axis_x.c_str(), axis_y.c_str(),
			20, 0.0, 20.0);
}

void BookH_single_observable(ExRootResult *result, TH1 **h2, int plotnum, std::string signal_name, std::string class_name, std::string observe_name, int bin, float low_limit, float high_limit){
	std::string fnum,desnum;
	std::string title,descrip;
	std::string x_name,y_name;
	std::string unit;

	unit=GetUnit(observe_name);

	x_name = class_name + " " + observe_name + " " + unit;
	y_name = "number of events";

	if (plotnum>0){
		for (int i=0;i<plotnum;i++){

			fnum=std::to_string(i);
			title=signal_name + "_"+class_name + "_" + observe_name + "_" + fnum;
			desnum=Int_to_String_descrip(i);
			descrip = desnum + "_" + class_name + " " + observe_name;


			h2[i] = result->AddHist1D(
					title.c_str(), descrip.c_str(),
					x_name.c_str(), y_name.c_str(),
					bin, low_limit, high_limit);
		}
	}
	else if (plotnum==-1){
		title=signal_name+"_"+class_name + "_" + observe_name;
		descrip = class_name + " " + observe_name;

		*h2 = result->AddHist1D(
				title.c_str(), descrip.c_str(),
				x_name.c_str(), y_name.c_str(),
				bin, low_limit, high_limit);
	}
	else{
		return;
	}
}



void BookH_single_same_class(ExRootResult *result, TH1 **h3, int num, std::string signal_name, std::string class_name, std::string observe_name){

	THStack *stack;
	TLegend *legend;
	std::string title,descrip,desnum;

	title = signal_name + "_" + class_name + "_" + observe_name + "_all"; 
	descrip = "all_"+class_name+" "+observe_name; 

	stack = result->AddHistStack(title.c_str(), descrip.c_str());

	legend = result->AddLegend(0.57, 0.88-num*0.05, 0.88, 0.88);

	// book 1 stack of some histograms
	for (int i=0;i<num;i++){

//		h3[i]->SetLineColor(1);
		stack->Add(h3[i]);

		desnum=Int_to_String_descrip(i);
		descrip = desnum + "_" + class_name + " " + observe_name;
		legend->AddEntry(h3[i],descrip.c_str(), "l");
	}

	// attach legend to stack (legend will be printed over stack in .eps file)
	result->Attach(stack, legend);
}

void PrintHistograms(ExRootResult *result, MyPlots *plots)
{
	result->Print("png");
}



void BookH_single_observable_loop(CDraw &para, ExRootResult *result, MyPlots *plots,int plot_num,
		std::string filter_name, std::string class_name, 
		std::string observe_name,int observe_num){

	THStack *stack;
	TLegend *legend;
	TH1     *h1;
	std::string title,descrip;
	int color;

	if (observe_num>=1){
		title = filter_name + "_" + class_name+"_" + observe_name +"_all";
		descrip = class_name+ " " + observe_name;

		stack = result->AddHistStack(title.c_str(), descrip.c_str());

		legend = result->AddLegend(0.57, 0.88-observe_num*0.05, 0.88, 0.88);
		for (int i=0;i<observe_num;i++){
			// book 1 stack of some histograms
			h1= Get_Class_ptr(para, plots,class_name,observe_name,i);
			h1->SetLineColor(i);
			stack->Add(h1);

			legend->AddEntry(h1,descrip.c_str(), "l");

			// attach legend to stack (legend will be printed over stack in .eps file)

		}
		result->Attach(stack, legend);
	}
}

