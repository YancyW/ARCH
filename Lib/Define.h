#pragma once
#ifndef DEFINE_H
#define DEFINE_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef std::vector<int>                   IntVec;
typedef std::vector<int>::iterator         IntVecIter;
typedef std::vector<float>                 FloatVec;
typedef std::vector<float>::iterator       FloatVecIter;
typedef std::vector<std::string>           StringVec;
typedef std::vector<std::string>::iterator StringVecIter;

typedef std::vector<std::vector<int> >                   IntVecVec;
typedef std::vector<std::vector<int> >::iterator         IntVecVecIter;
typedef std::vector<std::vector<float> >                 FloatVecVec;
typedef std::vector<std::vector<float> >::iterator       FloatVecVecIter;
typedef std::vector<std::vector<std::string> >           StringVecVec;
typedef std::vector<std::vector<std::string> >::iterator StringVecVecIter;


std::ostream & operator<<(std::ostream & ostr, IntVec &vec);
std::ostream & operator<<(std::ostream & ostr, IntVecVec &vec);
#endif
