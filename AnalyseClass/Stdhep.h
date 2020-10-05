#pragma once
#ifndef ANALYSE_CLASS_STDHEP_H
#define ANALYSE_CLASS_STDHEP_H
#include <string> 
#include <vector>
#include "TSystem.h" 

class AStdhep{
	private:
	public:
		void Init(std::string filename, bool judge);

		void Clear();
};


#endif
