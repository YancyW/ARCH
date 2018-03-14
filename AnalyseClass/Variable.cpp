#include "AnalyseClass/Variable.h"
void Avariable::Clear(){
			variable    =-100.1  ;
			cut_min     =-10000 ;
			cut_max     = 10000 ;
			cut_min1    =-10000 ;
			cut_max1    = 10000 ;

		    c_name      = ""    ;
		    c_width     = 1.0   ;
		    c_height    = 1.0   ;
		    leg_left    = 1.0   ;
		    leg_up      = 1.0   ;
		    leg_right   = 1.0   ;
		    leg_down    = 1.0   ;
		    leg_header  = ""    ;
		    title_name  = ""    ;
		    latex_name  = ""    ;
		    x_name      = ""    ;
		    x_bin       = 1     ;
		    x_min       = 0     ;
		    x_max       = 1     ;
		    y_name      = ""    ;
		    y_bin       = 1     ;
		    y_min       = 0     ;
		    y_max       = 1     ;
		    cut_switch  = false ;
		    plot_switch = false ;
		    log_switch  = false ;
		    norm_switch = false ;
		    BDT_switch  = false ;
}

void Avariable::Init_Value(){
			variable    =-100.1  ;
}

void Avariable_vec::Clear(){
	variable.clear();
	title_name = "";
}

void Avariable_vec::Init_Value(){
	variable.clear();
}

void AVariable::Clear(){
	for(int i=0;i<var.size();i++){
		var[i].Clear();
	}
	for(int i=0;i<vec.size();i++){
		vec[i].Clear();
	}
	for(int i=0;i<BDT.size();i++){
		BDT[i].Clear();
	}
}

void AVariable::Init_Value(){
	for(int i=0;i<var.size();i++){
		var[i].Init_Value();
	}
	for(int i=0;i<vec.size();i++){
		vec[i].Init_Value();
	}
	for(int i=0;i<BDT.size();i++){
		BDT[i].Init_Value();
	}
}
