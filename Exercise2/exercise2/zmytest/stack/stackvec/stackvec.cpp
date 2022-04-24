#include <iostream>
#include <random>
//#include "../../container/container.hpp"
#include "../../../container/container.hpp"
#include "../../stack/stack.hpp"
#include "../../../stack/vec/stackvec.hpp"
#include "../stack.hpp"


void StackVecInt(){
  uint dim, elemento;
  uint j = 0;
  bool quit = false;
  char opzione;
  std::cout << "Inserire la dimensione dello stack di interi" << std::endl;
  std::cin >> dim;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<unsigned int> dist(1, 100);
  lasd::StackVec<int> StackVecInt;
  while (j < dim){
    StackVecInt.Push(dist(gen));
    j++;
  }
  OperazioniDaEseguire();

  while (opzione != 'q'){
    std::cin >> opzione;

    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
	(opzione != '4') && (opzione != '5') && (opzione != '6') &&
	(opzione != '7') && opzione != 'q') {
      std::cout << "ERRORE: opzione non valida\n";
    }
    if (opzione == '1') { // Inserimento
     
      std::cout<< "Digita l'elemento da inserire nella struttura"<< std::endl;
      std::cin >> elemento;
      StackVecInt.Push(elemento);
      OperazioniDaEseguire();
    }
    if (opzione == '2') { // Rimozione
    
      StackVecInt.Pop();
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '3') { // Rimozione con lettura
      
      std::cout << "L'elemento rimosso è " <<  StackVecInt.TopNPop() << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '4') { // Lettura non distruttiva
 
      elemento = StackVecInt.Top();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
      
      if (StackVecInt.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
      
      elemento = StackVecInt.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '7') { // Svuotamento
      
      quit = true;
      StackVecInt.Clear();
      std::cout<< "Struttura svuotata" << std::endl;
      OperazioniDaEseguire();
    }
    if (opzione == 'q') { // Uscita

	std::cout << "Scegli il tipo di struttura: "<< std::endl;
	std::cout<<"Stack implementato con vettori (1 -> int; 2 -> float; 3 -> string)"<< std::endl;
	std::cout<<"Stack implementato con lista (4 -> int; 5 -> float; 6 -> string)"<< std::endl;
	std::cout<<"Queue implementata con vettori (a -> int; b -> float; c -> string)"<< std::endl;
	std::cout<<"Queue implementato con lista (d -> int; e -> float; f -> string)"<< std::endl;
	std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
    }
  }
}

//Float
void StackVecFloat(){
  ulong dim, elemento;
  ulong j = 0;
  bool quit = false;
  char opzione;
  std::cout << "Inserire la dimensione dello stack di float" << std::endl;
  std::cin >> dim;


  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<float> dist(1.0, 100.0);
  lasd::StackVec<float> StackVecFloat;
  while (j < dim){
    StackVecFloat.Push(dist(gen));
    j++;
  }
  OperazioniDaEseguire();

  while (opzione != 'q'){
    std::cin >> opzione;

    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
	(opzione != '4') && (opzione != '5') && (opzione != '6') &&
	(opzione != '7') && opzione != 'q') {
      std::cout << "ERRORE: opzione non valida\n";
    }
    if (opzione == '1') { // Inserimento
     
      std::cout<< "Digita l'elemento da inserire nella struttura"<< std::endl;
      std::cin >> elemento;
      StackVecFloat.Push(elemento);
      OperazioniDaEseguire();
    }
    if (opzione == '2') { // Rimozione
   
      StackVecFloat.Pop();
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '3') { // Rimozione con lettura
     
      std::cout<< "L'elemento rimosso è " << StackVecFloat.TopNPop() << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '4') { // Lettura non distruttiva
   
      elemento = StackVecFloat.Top();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
     
      if (StackVecFloat.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
     
      elemento = StackVecFloat.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '7') { // Svuotamento
      
      quit = true;
      StackVecFloat.Clear();
      std::cout<< "Struttura svuotata" << std::endl;
      OperazioniDaEseguire();
    }
    if (opzione == 'q') { // Uscita

	std::cout << "Scegli il tipo di struttura: "<< std::endl;
	std::cout<<"Stack implementato con vettori (1 -> int; 2 -> float; 3 -> string)"<< std::endl;
	std::cout<<"Stack implementato con lista (4 -> int; 5 -> float; 6 -> string)"<< std::endl;
	std::cout<<"Queue implementata con vettori (a -> int; b -> float; c -> string)"<< std::endl;
	std::cout<<"Queue implementato con lista (d -> int; e -> float; f -> string)"<< std::endl;
	std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
    }
  }
}

//String

void StackVecString(){
  ulong dim;
  std::string elemento;
  ulong j = 0;
  bool quit = false;
  char opzione;
  std::cout << "Inserire la dimensione dello stack di stringhe" << std::endl;
  std::cin >> dim;

  std::size_t length;
  std::mt19937 mt(std::random_device{}());
  std::string characters =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::uniform_int_distribution<int> dist(0, characters.length() - 1);
  std::string randStr;

  lasd::StackVec<std::string> StackVecString;
  while (j < dim){
    randStr = characters[dist(mt)];
    StackVecString.Push(randStr);
    j++;
  }
  OperazioniDaEseguire();

  while (opzione != 'q'){
    std::cin >> opzione;

    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
	(opzione != '4') && (opzione != '5') && (opzione != '6') &&
	(opzione != '7') && opzione != 'q') {
      std::cout << "ERRORE: opzione non valida\n";
    }
    if (opzione == '1') { // Inserimento
  
      std::cout<< "Digita l'elemento da inserire nella struttura"<< std::endl;
      std::cin >> elemento;
      StackVecString.Push(elemento);
      OperazioniDaEseguire();
    }
    if (opzione == '2') { // Rimozione
      
      StackVecString.Pop();
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '3') { // Rimozione con lettura
    
      std::cout<< "L'elemento rimosso è " << StackVecString.TopNPop() << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '4') { // Lettura non distruttiva
      
      elemento = StackVecString.Top();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
    
      if (StackVecString.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
    
      elemento = StackVecString.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '7') { // Svuotamento
     
      quit = true;
      StackVecString.Clear();
      std::cout<< "Struttura svuotata" << std::endl;
      OperazioniDaEseguire();
    }
    if (opzione == 'q') { // Uscita

	std::cout << "Scegli il tipo di struttura: "<< std::endl;
	std::cout<<"Stack implementato con vettori (1 -> int; 2 -> float; 3 -> string)"<< std::endl;
	std::cout<<"Stack implementato con lista (4 -> int; 5 -> float; 6 -> string)"<< std::endl;
	std::cout<<"Queue implementata con vettori (a -> int; b -> float; c -> string)"<< std::endl;
	std::cout<<"Queue implementato con lista (d -> int; e -> float; f -> string)"<< std::endl;
	std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
    }
  }
}
