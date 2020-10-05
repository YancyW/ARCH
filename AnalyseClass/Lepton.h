/**********************************************************************
 * @file Lepton.h
 * @Name: DrawBeauty
 * @Author:Yan Wang - yan.wang@desy.de
 * @version:1
 * @Created:2017-08-08
 **********************************************************************/
#pragma once
#ifndef ALEPTON_H
#define ALEPTON_H  
#include "Particle.h"
#include "Pair.h"
#include "Pool.h"
#include "TSystem.h"
#include "Class/lepton.h"
#include "Class/combine.h"
#include "Class/debug.h"



class ALepton{
	private:
	public:
		APool _elec_pool;
		APool _muon_pool;
		APool _tau_pool;
		APool _lep_pool;

		ALepton(){
			Init();
		}

		~ALepton(){
			Clear();
		}


		APool Elec_Pool(){
			return(_elec_pool);
		}

		APool Muon_Pool(){
			return(_muon_pool);
		}

		APool Tau_Pool(){
			return(_tau_pool);
		}

		APool Lep_Pool(){
			return(_lep_pool);
		}


		/**********************************************************************
		 * @Name: setChargeParticle 
		 *
		 * @Param: input
		 * @Param: PDG
		 * @Param: lep_cut
		 * @Param: left_events
		 *
		 * @Returns: 
		 **********************************************************************/
		APool Set_Charge_Particle(AParticleType &input, int PDG, CLepton_cut  &lep_cut, AParticleType &left_events);

		void Set_Elec_Pool   (AParticleType &in_events,  CLepton_cut &para_lep, AParticleType &left_events);

		void Set_Muon_Pool   (AParticleType &in_events,  CLepton_cut &para_lep, AParticleType &left_events);

		void Set_Tau_Pool    (AParticleType &in_events,  CLepton_cut &para_lep, AParticleType &left_events);

		void Set_Lep_Pool    (AParticleType &in_events,  CLepton_cut &para_lep, AParticleType &left_events);

		void Set_All_Lep_Pool(AParticleType &in_events,  CLepton &para_lep, AParticleType &left_events);


		void Find_All_Best_Lep    (CDraw& para);

		void All_Photon_Recovery(CLepton     &lep_info, AParticleType &WOIsoLep, AParticleType &CombinedPhoton);
		void Photon_Recovery    (CLepton_cut &lep_info, APair &lepton,  AParticleType &WOIsoLep, AParticleType &CombinedPhoton);
		bool Is_In_Lep_Cone     (CLepton_cut &info,AParticle* lep, AParticle* pfo ) ;


		void Clear();

		void Init();

		/**********************************************************************
		 * @Name: Cut 
		 *
		 * @Param: par
		 * @Param: lep_cut
		 *
		 * @Returns: 
		 **********************************************************************/
		bool Cut(AParticle* par, CLepton_cut &lep_cut);

};


std::ostream & operator<<(std::ostream & ostr, ALepton& lep);
std::ostream & operator<<(std::ostream & ostr, ALepton* lep);

#endif
