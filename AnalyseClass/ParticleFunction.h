#pragma once
#ifndef APARTICLE_FUNCTION_H
#define APARTICLE_FUNCTION_H
#include "TStyle.h"
#include <vector>

#include "Particle.h"
#include "Class/DrawClass.h"

AParticle Get_Sum(AParticleType in);
AParticle Get_SumSpecific(AParticleType in, AParticleType choosed);
AParticle Get_Left(float energy, float angle, AParticle* in);
AParticle Get_Left(float energy, float angle, AParticleType in);
#endif
