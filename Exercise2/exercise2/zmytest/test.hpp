#ifndef TEST2_FUNCTIONS
#define TEST2_FUNCTIONS

#include <iostream>
#include <string>

struct pos{ 
	int x; int y; 
	bool operator ==(const pos& rhs) const noexcept{
		return (this->x == rhs.x && this->y == rhs.y);
	}
};


template <typename Data>
void MapPrint(const Data& dat, void* _) {
  std::cout << dat << " ";
}

void MapDouble(int&, void*);
void MapSquare(float&, void*);
void MapToUpper(std::string&, void*);
void MapPrintPosition(pos&, void*);
void FoldAdd(const int&, const void *, void*);
void FoldMultiply(const float&, const void *, void*);
void FoldConcat(const std::string&, const void *, void*);

#endif

