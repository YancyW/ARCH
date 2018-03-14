#pragma once
#ifndef ANALYSE_CLASS_SLCIO_H
#define ANALYSE_CLASS_SLCIO_H
#include "TStyle.h"
#include <string> 
#include <vector>
#include "yaml-cpp/yaml.h"

#include "Lib/MessageFormat.h"
#include "Function/Fbasic.h"
#include "RWpara/RWbasic.h"
#include "Class/file.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TTree.h"
#include "TChain.h"

class ASlcio{
	private:
	public:
		//for ilcsoft 
		//These arraies are need for the MonteCarlo Particles
		int nmcp,  mcori[500],mcpdg[500], mcgst[500], mcsst[500];
		float mcvtx[500], mcvty[500], mcvtz[500], mcepx[500], mcepy[500];
		float mcepz[500], mcmox[500], mcmoy[500], mcmoz[500], mcmas[500];
		float mcene[500], mccha[500], mctim[500];
		float mcspx[500], mcspy[500], mcspz[500];
		int mccf0[500], mccf1[500], mcpa0[500], mcpa1[500];
		int mcda0[500], mcda1[500], mcda2[500], mcda3[500], mcda4[500];

////	// In these arries all the Tracker Calorimeter Hits are stored 
////	int nsth, stori[500], stci0[500], stci1[500];
////	float stpox[500], stpoy[500], stpoz[500];
////	float stedp[500], sttim[500];
////	float stmox[500], stmoy[500], stmoz[500], stptl[500];
////	int stmcp[500];


		//In these arries the the Simulated Calorimeter Hits are stored
////	int nsch, scori[500], scci0[500], scci1[500] ;
////	float scpox[500], scpoy[500], scpoz[500],  scene[500] ;


		int    nrec ;
		int    rcori[ 500 ] ;
		int    rccid[ 500 ] ;
		int    rctyp[ 500 ] ;
		float  rccov[ 500 ][10] ;
		float  rcrpx[ 500 ] ;
		float  rcrpy[ 500 ] ;
		float  rcrpz[ 500 ] ;
		float  rcgpi[ 500 ] ;
		int    rcpiu[ 500 ] ;
		int    rcnpi[ 500 ] ;
		int    rcfpi[ 500 ] ;
		float  rcmox[ 500 ] ;
		float  rcmoy[ 500 ] ;
		float  rcmoz[ 500 ] ;
		float  rcmas[ 500 ] ;
		float  rcene[ 500 ] ;
		float  rccha[ 500 ] ;
		int    rcntr[ 500 ] ;
		int    rcncl[ 500 ] ;
		int    rcftr[ 500 ] ;

		int    rcvts[ 500 ] ;
		int    rcvte[ 500 ] ;
		int    rccom[ 500 ] ;

		int    npid   ;
		int    pityp[ 500 ] ;
		int    pipdg[ 500 ] ;
		float  pillh[ 500 ] ;
		int    pialg[ 500 ] ;

		int	 r2mnrel;
		int	 r2mf[ 500  ];
		int	 r2mt[ 500  ];
		float  r2mw[ 500  ];
		int	 r2cnrel;
		int	 r2cf[ 500 ];
		int	 r2ct[ 500 ];
		float  r2cw[ 500 ];
		int	 r2tnrel;
		int	 r2tf[ 500 ];
		int	 r2tt[ 500 ];
		float  r2tw[ 500 ];
		int	 r2rnrel;
		int	 r2rf[ 500 ];
		int	 r2rt[ 500 ];
		float  r2rw[ 500 ];


		void Clear();

		void Init(TChain* tree,bool judge);
};


#endif
