#pragma once

#include <iostream>
#include <string> 
#include <complex>

#include "TCanvas.h"
#include "TChain.h"
#include "TH1.h"
#include "TH2.h"
#include "TClonesArray.h"
#include "TStyle.h"
#include "TSystem.h"

#include "classes/DelphesClasses.h"

#include "ExRootTreeReader.h"
#include "ExRootResult.h"

#include "fastjet/PseudoJet.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/ClusterSequence.hh"

#include "Lib/libstructure.h"
#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"


class ExRootResult;
class ExRootTreeReader;


double DeltaR( fastjet::PseudoJet jet1, fastjet::PseudoJet jet2);

std::vector<fastjet::PseudoJet> make_PseudoJet_constituents( Jet* jet );

int n_pos_track( const std::vector<fastjet::PseudoJet> & constituents );
int n_neg_track( const std::vector<fastjet::PseudoJet> & constituents );
int n_tower( const std::vector<fastjet::PseudoJet> & constituents );

double get_multipole_moment( fastjet::PseudoJet jet, std::vector<fastjet::PseudoJet> constituents );
double get_multipole_moment_new( fastjet::PseudoJet jet, std::vector<fastjet::PseudoJet> constituents );

std::vector<double> JeT_DeltaR( Jet* jet, std::string kind);
std::vector<double> JeT_DeltaR_central( Jet* jet);
std::vector<double> JeT_DeltaR_leading( Jet* jet);
fastjet::PseudoJet Jet_Find_LeadingConstituent(Jet* jet);
double DeltaR(double_t eta1, double_t phi1,double_t eta2, double_t phi2);
