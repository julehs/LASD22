#include <iostream>
#include "menu.hpp"
#include "test.hpp"
#include "stack/stack.hpp"
#include "queue/queue.hpp"
#include "../zlasdtest/test.hpp"

void menu(){
	bool quit = false;
	char opzione;
	std::cout<<"Seleziona il tipo di struttura: "<<std::endl;
	std::cout<<"Stack implementato con vettori (1 -> int; 2 -> float; 3 -> string)"<< std::endl;
	std::cout<<"Stack implementato con lista (4 -> int; 5 -> float; 6 -> string)"<< std::endl;
	std::cout<<"Queue implementata con vettori (7 -> int; 8 -> float; 9 -> string)"<< std::endl;
	std::cout<<"Queue implementato con lista (10 -> int; 11 -> float; 12 -> string)"<< std::endl;
  std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;


while (opzione != 'q'){
    std::cin >> opzione;

      if ((opzione !='1') && (opzione != '2')  && (opzione != '3') && (opzione != '4') && (opzione != '5') && (opzione !='6') && (opzione !='7') && (opzione !='8') && (opzione !='9') && (opzione !='10') && (opzione !='11') && (opzione !='12') && (opzione !='q')){
	std::cout << "ERRORE: scelta non valida\nLe strutture valide sono gli Stack(1-6) e le Queue(7-12)\n";
	}



if (opzione == '1') {
      StackVecInt();
    }
    if (opzione == '2') {
      StackVecFloat();
      quit = true;
    }

    if (opzione == '3') {
      StackVecString();
      quit = true;
    }
    if (opzione == '4') {
      StackListInt();
      quit = true;
    }

    if (opzione == '5') {
      StackListFloat();
      quit = true;
    }
    if (opzione == '6') {
      StackListString();
      quit = true;
    }
    if (opzione == '7') {
      QueueVecInt();
      quit = true;
    }
    if (opzione == '8') {
      QueueVecFloat();
      quit = true;
    }
    if (opzione == '9') {
      QueueVecString();
      quit = true;
    }
    if (opzione == '10') {
      QueueListInt();
      quit = true;
    }
    if (opzione == '11') {
      QueueListFloat();
      quit = true;
    }
    if (opzione == '12') {
      QueueListString();
      quit = true;
    }

if (opzione == 'q'){
	std::cout<< "Goodbye!"<< std::endl;
	quit = true;
      }

}