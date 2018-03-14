#pragma once
#ifndef GLOBAL_PARA_DEBUG
#define GLOBAL_PARA_DEBUG
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Function/Ffastjet.h"


class CDebug{
	private:
	public:
		bool   mode;

		int    num_debug_mode;
		int    level;
		std::vector<bool> debug;
		void Read_Debug(CPath path);

		template <typename TDebug1, typename TDebug2> 
			void Message(int itlevel, int itpos, std::string mess, TDebug1 ddata, TDebug2 ddata2){
				if(!mode){return;}
				if(itpos>=num_debug_mode) {std::cout<< "wrong itpos number in debug message" << std::endl;}
				if ((itlevel<level && debug[itpos])|| debug[0])   
				{
					ShowMessage(itlevel,"debugging  ",mess,ddata,ddata2);
				}
				//					std::cout << "debugging : " << mess  << "   " << ddata << "  " << ddata2 << std::endl;
			}
		template <typename TDebug> 
			void Message(int itlevel, int itpos, std::string mess, TDebug ddata){
				if(!mode){
					return;
				}
				if(itpos>=num_debug_mode) {
					std::cout<< "wrong itpos number in debug message" << std::endl;
				}
				if ((itlevel<level && debug[itpos])|| debug[0])   {
					ShowMessage(itlevel,"debugging  ",mess,ddata);
				}
				//std::cout << "debugging : " << mess  << "   " << ddata << std::endl;
			}

		void Message(int itlevel, int itpos,std::string mess){
			if(!mode){
				return;
			}
			if(itpos>=num_debug_mode) {
				std::cout<< "wrong itpos number in debug message" << std::endl;
			}
			if ((itlevel<level && debug[itpos])|| debug[0])  {
				ShowMessage(itlevel,"debugging  ",mess);
			}
			//std::cout << "debugging:  " << mess  << std::endl;
		}
};

#endif
