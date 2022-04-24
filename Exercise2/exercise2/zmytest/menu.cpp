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
	std::cout<<"Queue implementato con lista (a -> int; b -> float; c -> string)"<< std::endl;
  std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;

  while (opzione != 'q') {
    std::cin >> opzione;

    // TODO: Ti conviene utilizzare le lettere dopo il nome
    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
	(opzione != '4') && (opzione != '5') && (opzione != '6') &&
	(opzione != '7') && (opzione != '8') && (opzione != '9') &&
	(opzione != 'a') && (opzione != 'b') && (opzione != 'c') &&
	(opzione != 'd') && (opzione != 'q')) {
      std::cout << "ERRORE: scelta non valida\nLe strutture valide sono gli "
		   "Stack(1-6) e le Queue(7-d)\n";
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
    if (opzione == 'a') {
      QueueListInt();
      quit = true;
    }
    if (opzione == 'b') {
      QueueListFloat();
      quit = true;
    }
    if (opzione == 'c') {
      QueueListString();
      quit = true;
    }

    if (opzione == 'q') {
      std::cout << "Goodbye!" << std::endl;
      quit = true;
    }
  }
}
