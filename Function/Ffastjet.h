#pragma once
#ifndef FUNCTION_FASTJET
#define FUNCTION_FASTJET
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <vector>

#include "TSystem.h"
#include "TStyle.h"

#include "fastjet/PseudoJet.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/ClusterSequence.hh"

#include "fastjet/contribs/Nsubjettiness/Nsubjettiness.hh"
#include "fastjet/contribs/Nsubjettiness/Njettiness.hh"
#include "fastjet/contribs/Nsubjettiness/NjettinessPlugin.hh"
#include "Class/JetSubStructure.h"


#include <fastjet/tools/JHTopTagger.hh>

std::ostream & operator<< (std::ostream &, const fastjet::PseudoJet & jet);
std::ostream & operator<<(std::ostream & ostr, const std::vector<fastjet::PseudoJet> & jet);
void PrintTopJets(const fastjet::PseudoJet tagged) ;
bool JudgeBtag(fastjet::PseudoJet jet);
void PrintJetsWithComponents(const std::vector < fastjet::PseudoJet >& jets) ;
void PrintAxes(const std::vector <fastjet::PseudoJet >& jets) ;
void PrintJets(const std::vector <fastjet::PseudoJet >& jets) ;
#endif
