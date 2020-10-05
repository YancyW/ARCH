/*****************************************************************************************
 * @file Species.h
 * @Name: 
 * @Author:Yan Wang - yan.wang@desy.de
 * Copyright (C) 2012 All rights reserved
 * @version:1
 * @Created:2017-08-17
 **********************************************************************i******************/

#pragma once
#ifndef ASPECIES_H
#define ASPECIES_H  
#include "Particle.h"
#include "TSystem.h"
#include <vector> 
#include "Function/Fvector.h" 

typedef std::map<std::string,AParticleType >  ASpeciesType;
typedef std::map<std::string,int >            ASpeciesNumType;

class ASpecies{
	private:
		bool IsUsed ;

	public:
		ASpeciesType          _species;
		ASpeciesNumType       _num;

		ASpecies(){
			Clear();
		}

		~ASpecies(){
			Clear();
		}


		// /****************************************************************************
		/// @Name: Num 
		///
		/// @Returns: 
		// ****************************************************************************/
		ASpeciesNumType Num(){
			return(_num);
		}

		// /****************************************************************************
		/// @Name: setNum 
		// ****************************************************************************/
		void setNum(){
			for(ASpeciesType::iterator it = _species.begin(); it!=_species.end(); ++it ){
				_num[it->first]=it->second.size();
			}
		}

		ASpeciesType Species(){
			return(_species);
		}

		void get_particle_species(AParticleType& allparticle);

		// /****************************************************************************
		/// @Name: Clear 
		// ****************************************************************************/
		void Clear();
		void Init ();


};

std::ostream & operator<<(std::ostream & ostr, ASpecies spe);
std::ostream & operator<<(std::ostream & ostr, ASpecies* spe);
std::ostream & operator<<(std::ostream & ostr, ASpeciesType spe);
std::ostream & operator<<(std::ostream & ostr, ASpeciesNumType spe);
#endif
