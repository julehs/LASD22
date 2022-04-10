#include "menu.hpp"
#include "vector/vector.hpp"
#include "list/list.hpp"
#include <iostream>

void menu(){
  bool quit = false;
  //int opzione(0);
  char opzione;

  std::cout<<"Seleziona il tipo di struttura\n\tVettore di interi (1)\tVettore di Float(2)\tVettore di Stringhe(3)\tVettore di Struct(4)\t\n"<< std::endl;
  std::cout<<"\tLista di interi (5)\tLista di Float(6)\tListe di Stringhe(7)\tLista di Struct(8)\n"<< std::endl;
  std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
  while (opzione != 'q'){
    std::cin >> opzione;

      if ((opzione !='1') && (opzione != '2')  && (opzione != '3') && (opzione != '4') && (opzione != '5') && (opzione !='6') && (opzione !='7') && (opzione !='8') && (opzione !='q')){
	std::cout << "ERRORE: scelta non valida\nLe strutture valide sono i Vettori(1-2-3) e le Liste(4-5-6)\n";
	}

      if (opzione == '1'){
	VectorInt();
      }
      if (opzione == '2'){
	VectorFloat();
	quit = true;
      }
      if (opzione == '3'){
	VectorString();
	quit = true;
      }
      if (opzione == '4'){
	VectorStruct();
	quit = true;
      }
      if (opzione == '5'){
	ListInt();
	quit = true;
      }
      if (opzione == '6'){
	ListFloat();
	quit = true;
      }
      if (opzione == '7'){
	ListString();
	quit = true;
      }
      if (opzione == '8'){
	ListStruct();
	quit = true;
      }
      if (opzione == 'q'){
	std::cout<< "Goodbye!"<< std::endl;
	quit = true;
      }
    }
}
