#include <iostream>
#include <random>
#include "../../../container/container.hpp"
#include "../../stack/stack.hpp"
#include "../../../stack/lst/stacklst.hpp"
#include "../stack.hpp"

void StackListInt(){
  
  uint dim, elemento;
  uint j = 0;
  bool quit = false;
  char opzione;
  std::cout << "Inserire la dimensione dello stack di interi" << std::endl;
  std::cin >> dim;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<unsigned int> dist(1, 100);
  lasd::StackLst<int> StackListInt;
  while (j < dim){
    StackListInt.Push(dist(gen));
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
      StackListInt.Push(elemento);
      OperazioniDaEseguire();
    }
    if (opzione == '2') { // Rimozione
    
      StackListInt.Pop();
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '3') { // Rimozione con lettura
     
      std::cout<< "L'elemento rimosso è " << StackListInt.TopNPop() << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '4') { // Lettura non distruttiva
     
      elemento = StackListInt.Top();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
      
      if (StackListInt.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
      
      elemento = StackListInt.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '7') { // Svuotamento
    
      quit = true;
      StackListInt.Clear();
      std::cout<< "Struttura svuotata" << std::endl;
      OperazioniDaEseguire();
    }
    if (opzione == 'q') { // Uscita
      std::cout << "Scegli il tipo di struttura: " << std::endl;
      std::cout << "Stack implementato con vettori (1 -> int; 2 -> float; 3 "
                   "-> string)"
                << std::endl;
      std::cout
          << "Stack implementato con lista (4 -> int; 5 -> float; 6 -> string)"
          << std::endl;
      std::cout << "Queue implementata con vettori (a -> int; b -> float; c "
                   "-> string)"
                << std::endl;
      std::cout
          << "Queue implementato con lista (d -> int; e -> float; f -> string)"
          << std::endl;
      std::cout << "\t\t\t(premi q per uscire)" << std::endl;
    }
  }
}

//Float

void StackListFloat(){
  ulong dim, elemento;
  ulong j = 0;
  bool quit = false;
  char opzione;
  std::cout << "Inserire la dimensione dello stack di float" << std::endl;
  std::cin >> dim;


  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<float> dist(1.0, 100.0);
  lasd::StackLst<float> StackListFloat;
  while (j < dim){
    StackListFloat.Push(dist(gen));
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
      StackListFloat.Push(elemento);
      OperazioniDaEseguire();
    }
    if (opzione == '2') { // Rimozione
      
      StackListFloat.Pop();
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '3') { // Rimozione con lettura
      
      std::cout<< "L'elemento rimosso è " << StackListFloat.TopNPop() << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '4') { // Lettura non distruttiva
     
      elemento = StackListFloat.Top();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
   
      if (StackListFloat.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
      
      elemento = StackListFloat.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '7') { // Svuotamento
      
      quit = true;
      StackListFloat.Clear();
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

//List

void StackListString(){
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

  lasd::StackLst<std::string> StackListString;
  while (j < dim){
    randStr = characters[dist(mt)];
    StackListString.Push(randStr);
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
      StackListString.Push(elemento);
      OperazioniDaEseguire();
    }
    if (opzione == '2') { // Rimozione
      
      StackListString.Pop();
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '3') { // Rimozione con lettura
  
      std::cout<< "L'elemento rimosso è " << StackListString.TopNPop() << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '4') { // Lettura non distruttiva
     
      elemento = StackListString.Top();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
  
      if (StackListString.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
      
      elemento = StackListString.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '7') { // Svuotamento
     
      quit = true;
      StackListString.Clear();
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
