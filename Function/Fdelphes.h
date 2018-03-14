#pragma once
#ifndef FUNCTION_DELPHES
#define FUNCTION_DELPHES
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <vector>

#include "classes/DelphesClasses.h"

#include "ExRootTreeReader.h"
#include "ExRootResult.h"

std::ostream & operator<< (std::ostream & ostr, Jet* jet);
std::ostream & operator<<(std::ostream & ostr, const std::vector<Jet*> jet);
std::ostream & operator<< (std::ostream & ostr, Electron* particle);
std::ostream & operator<<(std::ostream & ostr, const std::vector<Electron*> particles);
std::ostream & operator<< (std::ostream & ostr, Muon* particle);
std::ostream & operator<<(std::ostream & ostr, const std::vector<Muon*> particles);
std::ostream & operator<< (std::ostream & ostr, Photon* particle);
std::ostream & operator<<(std::ostream & ostr, const std::vector<Photon*> particles);
std::ostream & operator<< (std::ostream & ostr, MissingET* particle);
std::ostream & operator<<(std::ostream & ostr, const std::vector<MissingET*> particles);

std::ostream & operator<<(std::ostream & ostr,  GenParticle* particles);
std::ostream & operator<< (std::ostream & ostr, std::vector<GenParticle*> particle);
#endif
