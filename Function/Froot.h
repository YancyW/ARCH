#pragma once
#ifndef FUNCTION_ROOT
#define FUNCTION_ROOT
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <vector>

#include "TSystem.h"
#include "TLorentzVector.h"


std::ostream & operator<< (std::ostream &, const TLorentzVector &p);
std::ostream & operator<<(std::ostream & ostr, const std::vector<TLorentzVector> & p);
std::ostream & operator<< (std::ostream &, const TVector3&p);
std::ostream & operator<<(std::ostream & ostr, const std::vector<TVector3> & p);
#endif
