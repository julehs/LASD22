#include <iostream>
#include "../../list/list.hpp"
#include "../menu.hpp"
#include "../ex1.hpp"
#include <random>
#include <string>
#include <ctime>
#include <unistd.h>
#include <bits/stdc++.h>


using namespace std;

/* Prototipi */
void ListInt(){
  default_random_engine gen(random_device{}()); 
  uniform_int_distribution<unsigned int> dist(10000, 80000); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del lista
  int index, value;

  std::cout<< "Inserire la dimensione del lista: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::List<int> lst; // Inizializziamo il lista
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del lista
    lst.InsertAtBack(dist(gen));
  }

	std::cout << "Elemento\tin testa: " << lst.Front() << "\tin coda: " << lst.Back() << "\n";	
 
  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    std::cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      std::cout << "L'indice scelto " << index << " contiene il valore " << lst[i] << std::endl;
    }
  }

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori presenti nel lista<int>:\n";
  lst.MapPreOrder(&MapPrint<int>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
  
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  bool test = lst.Exists(value);
	if(test) std::cout<< "il valore " << value << " e' stato trovato!\n";
	else  std::cout<< "il valore " << value << " NON e' stato trovato!\n";

	std::cout << "~~~ Effettuare la sommatoria per n<";
	std::cin>> value;
	int sommatoria=0;
	lst.FoldPreOrder(&FoldAdd, &value, &sommatoria);
	std::cout << "\nIl risultato della sommatoaria e' " << sommatoria;


  lst.MapPreOrder(&MapDouble, 0);
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori dopo MapDouble\n";
  lst.MapPreOrder(&MapPrint<int>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
}

void ListFloat(){
  default_random_engine gen(random_device{}()); 
  uniform_real_distribution<float> dist(1.0, -1.0); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del lista
  int index;
	float value;

  std::cout<< "Inserire la dimensione del lista: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::List<float> lst; // Inizializziamo il lista
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del lista
    lst.InsertAtBack(dist(gen));
  }

	std::cout << "Elemento\tin testa: " << lst.Front() << "\tin coda: " << lst.Back() << "\n";	
 
  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    std::cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      std::cout << "L'indice scelto " << index << " contiene il valore " << lst[i] << std::endl;
    }
  }

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori presenti nel lista<float>:\n";
  lst.MapPreOrder(&MapPrint<float>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
  
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  bool test = lst.Exists(value);
	if(test) std::cout<< "il valore " << value << " e' stato trovato!\n";
	else  std::cout<< "il valore " << value << " NON e' stato trovato!\n";

	std::cout << "~~~ Effettuare la produttoria per n<";
	std::cin>> value;
	float produttoria=0;
	lst.FoldPreOrder(&FoldMultiply, &value, &produttoria);
	std::cout << "\nIl risultato della produttoria e' " << produttoria;


  lst.MapPreOrder(&MapSquare, 0);
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori dopo MapSquare\n";
  lst.MapPreOrder(&MapPrint<float>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
}

void ListString(){
  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del lista
  int index;
	string value;

  std::cout<< "Inserire la dimensione del lista: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::List<string> lst; // Inizializziamo il lista

  std::size_t length;
  std::mt19937 mt(std::random_device{}());
  std::string characters =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::uniform_int_distribution<int> dist(0, characters.length() - 1);
  std::string randStr;

  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del lista
		randStr = characters[dist(mt)];
    lst.InsertAtBack(randStr);
  }

	std::cout << "Elemento\tin testa: " << lst.Front() << "\tin coda: " << lst.Back() << "\n";	
 
  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    std::cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      std::cout << "L'indice scelto " << index << " contiene il valore " << lst[i] << std::endl;
    }
  }

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori presenti nel lista<float>:\n";
  lst.MapPreOrder(&MapPrint<string>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
  
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  bool test = lst.Exists(value);
	if(test) std::cout<< "il valore " << value << " e' stato trovato!\n";
	else  std::cout<< "il valore " << value << " NON e' stato trovato!\n";

	std::cout << "~~~ Effettuare la concatenazione di stringhe di lunghezza n<=";
	std::cin>> value;
	string concat="";
	lst.FoldPreOrder(&FoldConcat, &value, &concat);
	std::cout << "\nIl risultato della concatenazione e' '" << concat << "'\n";


  lst.MapPreOrder(&MapToUpper, 0);
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori dopo MapSquare\n";
  lst.MapPreOrder(&MapPrint<string>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
}

void ListStruct(){

  default_random_engine gen(random_device{}()); 
  uniform_int_distribution<unsigned int> dist(10, 100); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del lista
  int index, value;

  std::cout<< "Inserire la dimensione del lista: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::List<pos> lst; // Inizializziamo il lista
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del lista
		int a = dist(gen);
		int b = dist(gen);

    lst.InsertAtBack({ .x = a, .y = b});
  }

	pos front = lst.Front();
	pos back = lst.Back();

	std::cout << "Elemento\tin testa: " << front.x << " " << front.y << 
	"\tin coda: " << back.x << " " << back.y << "\n";	
 
  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    std::cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      std::cout << "L'indice scelto " << index << " contiene il valore\n";
			std::cout << "{" << lst[i].x << " " << lst[i].y << "}\n";
    }
  }

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori presenti nel lista<int>:\n";
  lst.MapPreOrder(&MapPrintPosition, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
  
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento:";
	pos p;
	std::cout << "x: ";
	std::cin >> p.x;
	std::cout << ", y: ";
	std::cin >> p.y;

  bool test = lst.Exists(p);
	if(test) std::cout<< "il valore {" << p.x << "," << p.y << "} e' stato trovato!\n";
	else  std::cout<< "il valore {" << p.x << "," << p.y << "} NON e' stato trovato!\n";
}
