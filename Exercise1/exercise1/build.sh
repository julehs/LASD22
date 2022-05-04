#! /bin/bash

g++ -O3 -o main -g \
  zlasdtest/exercise1/simpletest.cpp zlasdtest/exercise1/fulltest.cpp \
  zlasdtest/container/container.cpp \
  zlasdtest/test.cpp zmytest/test.cpp zmytest/menu.cpp \
	zmytest/ex1.cpp zmytest/list/list.cpp zmytest/vector/vector.cpp main.cpp
