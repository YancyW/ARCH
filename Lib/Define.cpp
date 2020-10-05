
#include "Define.h"
std::ostream & operator<<(std::ostream & ostr, IntVec &vec){
	printf("\n"); // ]label the columns
	for (unsigned int i = 0; i < vec.size(); i++) {
		std::cout<<vec[i]<<" ";
	}
	return ostr;
}

std::ostream & operator<<(std::ostream & ostr, IntVecVec &vec){
	printf("\n"); // ]label the columns
	for (unsigned int i = 0; i < vec.size(); i++) {
		std::cout<<vec[i];
	}
	return ostr;
}

