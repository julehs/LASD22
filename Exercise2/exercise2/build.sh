#!/bin/bash

g++ -O3 -o main \
  zlasdtest/exercise1/simpletest.cpp zlasdtest/exercise1/fulltest.cpp \
  zlasdtest/exercise2/simpletest.cpp zlasdtest/exercise2/fulltest.cpp \
  zlasdtest/container/container.cpp \
  zlasdtest/test.cpp zmytest/test.cpp zmytest/menu.cpp \
  zmytest/stack/stackvec/stackvec.cpp zmytest/stack/stacklst/stacklst.cpp \
  zmytest/stack/OperazioniDaEseguire.cpp \
  zmytest/queue/OperazioniQueue.cpp \
  zmytest/queue/queuevec/queuevec.cpp zmytest/queue/queuelst/queuelst.cpp \
  main.cpp
