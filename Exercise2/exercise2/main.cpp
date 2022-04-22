#include "zlasdtest/test.hpp" 
#include "zmytest/menu.hpp"



/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2022" << std::endl;

//menu();

  int scelta; 
  std::cout<<"Seleziona il tipo di test da eseguire:"<<std::endl; 
   std::cout<<"\tTest professore (1)\tTest Studente(2)"<<std::endl; 
  std::cin>>scelta; 
  if(scelta == 1){ 
     std::cout<<""<<std::endl; 
     lasdtest(); // To call in the menu of your library test! 
   } 
   if(scelta == 2){ 
     std::cout<<""<<std::endl; 
    menu(); 
   } 
   

  return 0;
}
