
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {

  do {
      std::cout<<"===================================================== \n"<<std::endl;
      std::cout<<" \t\tEXERCISE 3- Giulia Caputo \t \n "<<std::endl;
      std::cout<<"===================================================== \n"<<std::endl;

        std::cout << "1.Test Professore" << std::endl;
        std::cout << "2.Test Mio" << std::endl;
        std::cout << "3. Chiudi programma" << std::endl;
        std::cout << ": ";
        int res = 0;

        std::cin >> res;

        if(res == 1) {
        lasdtest();
        }
        else if(res == 2){
        zmytest();
        }
        else
          break;

    }while(true);

  return 0;

}