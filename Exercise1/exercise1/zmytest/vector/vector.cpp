#include <iostream>
#include "../../vector/vector.hpp"
#include "../menu.hpp"
#include "../ex1.hpp"
#include <random>
#include <string>
#include <ctime>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

/* Prototipi */
void VectorInt(){
  default_random_engine gen(random_device{}()); 
  uniform_int_distribution<unsigned int> dist(10000, 80000); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del vettore
  int index, value;

  std::cout<< "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::Vector<int> vec(dim); // Inizializziamo il vettore
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    vec[i] = dist(gen);
  }

	std::cout << "Elemento\tin testa: " << vec.Front() << "\tin coda: " << vec.Back() << "\n";	
 
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
      std::cout << "L'indice scelto " << index << " contiene il valore " << vec[i] << std::endl;
    }
  }

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori presenti nel vettore<int>:\n";
  vec.MapPreOrder(&MapPrint<int>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
  
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  bool test = vec.Exists(value);
	if(test) std::cout<< "il valore " << value << " e' stato trovato!\n";
	else  std::cout<< "il valore " << value << " NON e' stato trovato!\n";

	std::cout << "~~~ Effettuare la sommatoria per n<";
	std::cin>> value;
	int sommatoria=0;
	vec.FoldPreOrder(&FoldAdd, &value, &sommatoria);
	std::cout << "\nIl risultato della sommatoaria e' " << sommatoria;


  vec.MapPreOrder(&MapDouble, 0);
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori dopo MapDouble\n";
  vec.MapPreOrder(&MapPrint<int>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
}

void VectorFloat(){
  default_random_engine gen(random_device{}()); 
  uniform_real_distribution<float> dist(1.0, -1.0); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del vettore
  int index;
	float value;

  std::cout<< "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::Vector<float> vec(dim); // Inizializziamo il vettore
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    vec[i] = dist(gen);
  }

	std::cout << "Elemento\tin testa: " << vec.Front() << "\tin coda: " << vec.Back() << "\n";	
 
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
      std::cout << "L'indice scelto " << index << " contiene il valore " << vec[i] << std::endl;
    }
  }

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori presenti nel vettore<float>:\n";
  vec.MapPreOrder(&MapPrint<float>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
  
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  bool test = vec.Exists(value);
	if(test) std::cout<< "il valore " << value << " e' stato trovato!\n";
	else  std::cout<< "il valore " << value << " NON e' stato trovato!\n";

	std::cout << "~~~ Effettuare la produttoria per n<";
	std::cin>> value;
	float produttoria=0;
	vec.FoldPreOrder(&FoldMultiply, &value, &produttoria);
	std::cout << "\nIl risultato della produttoria e' " << produttoria;


  vec.MapPreOrder(&MapSquare, 0);
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori dopo MapSquare\n";
  vec.MapPreOrder(&MapPrint<float>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
}

void VectorString(){
  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del vettore
  int index;
	string value;

  std::cout<< "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::Vector<string> vec(dim); // Inizializziamo il vettore

  std::size_t length;
  std::mt19937 mt(std::random_device{}());
  std::string characters =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::uniform_int_distribution<int> dist(0, characters.length() - 1);
  std::string randStr;

  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
		randStr = characters[dist(mt)];
    vec[i] = randStr;	
  }

	std::cout << "Elemento\tin testa: " << vec.Front() << "\tin coda: " << vec.Back() << "\n";	
 
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
      std::cout << "L'indice scelto " << index << " contiene il valore " << vec[i] << std::endl;
    }
  }

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori presenti nel vettore<float>:\n";
  vec.MapPreOrder(&MapPrint<string>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
  
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  bool test = vec.Exists(value);
	if(test) std::cout<< "il valore " << value << " e' stato trovato!\n";
	else  std::cout<< "il valore " << value << " NON e' stato trovato!\n";

	std::cout << "~~~ Effettuare la concatenazione di stringhe di lunghezza n<=";
	std::cin>> value;
	string concat="";
	vec.FoldPreOrder(&FoldConcat, &value, &concat);
	std::cout << "\nIl risultato della concatenazione e' '" << concat << "'\n";


  vec.MapPreOrder(&MapToUpper, 0);
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori dopo MapSquare\n";
  vec.MapPreOrder(&MapPrint<string>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
}

void VectorStruct(){

  default_random_engine gen(random_device{}()); 
  uniform_int_distribution<unsigned int> dist(10, 100); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del vettore
  int index, value;

  std::cout<< "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::Vector<pos> vec(dim); // Inizializziamo il vettore
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
		int a = dist(gen);
		int b = dist(gen);

    vec[i] = { .x = a, .y = b};
  }

	pos front = vec.Front();
	pos back = vec.Back();

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
			std::cout << "{" << vec[i].x << " " << vec[i].y << "}\n";
    }
  }

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Visualizzazione dei valori presenti nel vettore<int>:\n";
  vec.MapPreOrder(&MapPrintPosition, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!\n" << std::endl;
  
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento:";
	pos p;
	std::cout << "x: ";
	std::cin >> p.x;
	std::cout << ", y: ";
	std::cin >> p.y;

  bool test = vec.Exists(p);
	if(test) std::cout<< "il valore {" << p.x << "," << p.y << "} e' stato trovato!\n";
	else  std::cout<< "il valore {" << p.x << "," << p.y << "} NON e' stato trovato!\n";
}
