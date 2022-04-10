#include "ex1.hpp"
#include <iostream>

void MapPrintPosition(pos& dat, void* _){
	std::cout << "{" << dat.x << " " << dat.y << "}\n";
}

void MapDouble(int& dat, void* _) {
  dat *= 2;
}

void MapSquare(float& dat, void* _) {
  dat *= dat;
}

void MapToUpper(std::string& dat, void* _){
	for (auto& c: dat)
		c = toupper(c);
}

void FoldAdd(const int& dat, const void* n, void* acc) {
	if(dat < *((int*)n))
		*((int*) acc) += dat;
}

void FoldMultiply(const float& dat, const void* n, void* acc) {
	if(dat < *((int*)n))
		*((float*) acc) *= dat;
}

void FoldConcat(const std::string& dat, const void* n, void* acc) {
	if(dat.length() <= *((int*)n))
		((std::string*) acc)->append(dat);
}

