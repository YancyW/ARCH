#pragma once
#ifndef AVARIABLE_H
#define AVARIABLE_H
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/DrawClass.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TSystem.h"


class Avariable{
	private:
	public:

		float         variable   ;
		float         cut_min    ;
		float         cut_max    ;
		float         cut_min1   ;
		float         cut_max1   ;

		TCanvas*      c          ;
		std::string   c_name     ;
		float         c_width    ;
		float         c_height   ;
		TLegend*      leg        ;
		float         leg_left   ;
		float         leg_up     ;
		float         leg_right  ;
		float         leg_down   ;
		std::string   leg_header ;
		std::string   title_name ;
		std::string   latex_name ;
		std::string   x_name     ;
		int           x_bin      ;
		float         x_min      ;
		float         x_max      ;
		std::string   y_name     ;
		int           y_bin      ;
		float         y_min      ;
		float         y_max      ;
		bool          cut_switch ;
		bool          plot_switch;
		bool          log_switch ;
		bool          norm_switch;
		bool          BDT_switch ;

		Avariable(){
			Clear();
		}

		void Clear();

		void Init(){
			//c=new TCanvas(c_name.c_str()," ",c_width,c_height);
			leg=new TLegend(leg_left,leg_up,leg_right,leg_down);
			leg->SetHeader(leg_header.c_str(),"C");
		}

		void Init_Value();

};



class Avariable_vec{
	private:
	public:

		std::vector<float>         variable   ;

		std::string   title_name ;

		Avariable_vec(){
		    title_name  = ""    ;
		}

		void Clear();

		void Init_Value();

};



class AVariable{
	public:
		int num;
		int num_vec;
		int numBDT;
		int cut_level;
		std::vector<Avariable> var;
		std::vector<Avariable_vec> vec;
		std::vector<Avariable> BDT;
		void Read_Var(CDraw &para);

		AVariable(){
			num=0;
			num_vec=0;
			numBDT=0;
			var.clear();
			vec.clear();
			BDT.clear();
		}

		void Clear();

		void Init_Value();
};


namespace YAML{
	template<>
		struct convert<Avariable>{
			static bool decode(const Node& node, Avariable& var){ 
				for(YAML::const_iterator it=node.begin(); it != node.end(); ++it){
					if(it->first.as<std::string>()=="Canvas_name"){
						RW_element(it->first.as<std::string>(), it, var.c_name);
					}
					else if(it->first.as<std::string>()=="Canvas_width"){
						RW_element(it->first.as<std::string>(), it, var.c_width);
					}
					else if(it->first.as<std::string>()=="Canvas_height"){
						RW_element(it->first.as<std::string>(), it, var.c_height);
					}
					else if(it->first.as<std::string>()=="leg_left"){
						RW_element(it->first.as<std::string>(), it, var.leg_left);
					}
					else if(it->first.as<std::string>()=="leg_up"){
						RW_element(it->first.as<std::string>(), it, var.leg_up);
					}
					else if(it->first.as<std::string>()=="leg_right"){
						RW_element(it->first.as<std::string>(), it, var.leg_right);
					}
					else if(it->first.as<std::string>()=="leg_down"){
						RW_element(it->first.as<std::string>(), it, var.leg_down);
					}
					else if(it->first.as<std::string>()=="leg_header"){
						RW_element(it->first.as<std::string>(), it, var.leg_header);
					}
					else if(it->first.as<std::string>()=="title_name"){
						RW_element(it->first.as<std::string>(), it, var.title_name);
					}
					else if(it->first.as<std::string>()=="latex_name"){
						RW_element(it->first.as<std::string>(), it, var.latex_name);
					}
					else if(it->first.as<std::string>()=="xaxis_name"){
						RW_element(it->first.as<std::string>(), it, var.x_name);
					}
					else if(it->first.as<std::string>()=="xaxis_bin"){
						RW_element(it->first.as<std::string>(), it, var.x_bin);
					}
					else if(it->first.as<std::string>()=="xaxis_min"){
						RW_element(it->first.as<std::string>(), it, var.x_min);
					}
					else if(it->first.as<std::string>()=="xaxis_max"){
						RW_element(it->first.as<std::string>(), it, var.x_max);
					}
					else if(it->first.as<std::string>()=="yaxis_name"){
						RW_element(it->first.as<std::string>(), it, var.y_name);
					}
					else if(it->first.as<std::string>()=="yaxis_bin"){
						RW_element(it->first.as<std::string>(), it, var.y_bin);
					}
					else if(it->first.as<std::string>()=="yaxis_min"){
						RW_element(it->first.as<std::string>(), it, var.y_min);
					}
					else if(it->first.as<std::string>()=="yaxis_max"){
						RW_element(it->first.as<std::string>(), it, var.y_max);
					}
					else if(it->first.as<std::string>()=="cut_min"){
						RW_element(it->first.as<std::string>(), it, var.cut_min);
					}
					else if(it->first.as<std::string>()=="cut_max"){
						RW_element(it->first.as<std::string>(), it, var.cut_max);
					}
					else if(it->first.as<std::string>()=="cut_min1"){
						RW_element(it->first.as<std::string>(), it, var.cut_min1);
					}
					else if(it->first.as<std::string>()=="cut_max1"){
						RW_element(it->first.as<std::string>(), it, var.cut_max1);
					}
					else if(it->first.as<std::string>()=="cut_switch"){
						RW_element(it->first.as<std::string>(), it, var.cut_switch);
					}
					else if(it->first.as<std::string>()=="plot_switch"){
						RW_element(it->first.as<std::string>(), it, var.plot_switch);
					}
					else if(it->first.as<std::string>()=="log_yaxis"){
						RW_element(it->first.as<std::string>(), it, var.log_switch);
					}
					else if(it->first.as<std::string>()=="normalization_switch"){
						RW_element(it->first.as<std::string>(), it, var.norm_switch);
					}
					else if(it->first.as<std::string>()=="BDT"){
						RW_element(it->first.as<std::string>(), it, var.BDT_switch);
					}
					else{
						ShowMessage(2,"wrong input when load class Variable");
					}
				}
				var.Init();
				return true;
			}
		};
};



namespace YAML{
	template<>
		struct convert<Avariable_vec>{
			static bool decode(const Node& node, Avariable_vec& vec){ 
				for(YAML::const_iterator it=node.begin(); it != node.end(); ++it){
					if(it->first.as<std::string>()=="title_name"){
						RW_element(it->first.as<std::string>(), it, vec.title_name);
					}
					else{
						ShowMessage(2,"wrong input when load class Variable");
					}
				}
				return true;
			}
		};
};
#endif
