
#include "test.hpp"

#include "../stack/lst/stacklst.hpp"
#include "../queue/lst/queuelst.hpp"

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

#include <iostream>

//#include "../stack/lst/stacklst.hpp"
//#include "../queue/lst/queuelst.hpp"
//#include "../queue/vec/queuevec.hpp"

void zmytest(){
    lasd::List<int> lista;
    lasd::Vector<int> vettore;
   for (int i=0; i<10; i++) {
       lista[i]=i;
   }
   lasd::BinaryTreeLnk<int> binarytree {vettore};
}
