#include <iostream>
#include <iostream>
#include <random>
#include "../../../container/container.hpp"
#include "../../queue/queue.hpp"
#include "../../../queue/vec/queuevec.hpp"
#include "../queue.hpp"

void QueueVecInt(){
  uint dim, elemento;
  uint j = 0;
  char opzione;
  bool quit = false;

  std::cout << "Inserire la dimensione della coda di interi" << std::endl;
  std::cin >> dim;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<unsigned int> dist(1, 100);
  lasd::QueueVec<int> QueueVecInt;
  while (j < dim){
    QueueVecInt.Enqueue(dist(gen));
    j++;
  }

  OperazioniQueue();
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
      QueueVecInt.Enqueue(elemento);
      OperazioniQueue();
    }
    if (opzione == '2') { // Rimozione
  
      QueueVecInt.Dequeue();
      quit = true;
      OperazioniQueue();
    }

    if (opzione == '3') { // Rimozione con lettura
     
      QueueVecInt.HeadNDequeue();
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '4') { // Lettura non distruttiva
   
      elemento = QueueVecInt.Head();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniQueue();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
    
      if (QueueVecInt.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura

      elemento = QueueVecInt.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '7') { // Svuotamento

      quit = true;
      QueueVecInt.Clear();
      std::cout<< "Struttura svuotata" << std::endl;
      OperazioniQueue();
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

void QueueVecFloat(){
  uint dim, elemento;
  uint j = 0;
  char opzione;
  bool quit = false;

  std::cout << "Inserire la dimensione della coda di float" << std::endl;
  std::cin >> dim;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<float> dist(1.0, 100.0);
  lasd::QueueVec<float> QueueVecFloat;
  while (j < dim){
    QueueVecFloat.Enqueue(dist(gen));
    j++;
  }

  OperazioniQueue();
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
      QueueVecFloat.Enqueue(elemento);
      OperazioniQueue();
    }
    if (opzione == '2') { // Rimozione
   
      QueueVecFloat.Dequeue();
      quit = true;
      OperazioniQueue();
    }

    if (opzione == '3') { // Rimozione con lettura
     
      QueueVecFloat.HeadNDequeue();
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '4') { // Lettura non distruttiva
      
      elemento = QueueVecFloat.Head();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniQueue();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
    
      if (QueueVecFloat.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
    
      elemento = QueueVecFloat.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '7') { // Svuotamento
   
      quit = true;
      QueueVecFloat.Clear();
      std::cout<< "Struttura svuotata" << std::endl;
      OperazioniQueue();
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


//String

void QueueVecString(){
  ulong dim;
  std::string elemento;
  uint j = 0;
  char opzione;
  bool quit = false;

  std::cout << "Inserire la dimensione della coda di stringhe" << std::endl;
  std::cin >> dim;

  std::size_t length;
  std::mt19937 mt(std::random_device{}());
  std::string characters =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::uniform_int_distribution<int> dist(0, characters.length() - 1);
  std::string randStr;

  lasd::QueueVec<std::string> QueueVecString;
  while (j < dim){
    randStr = characters[dist(mt)];
    QueueVecString.Enqueue(randStr);
    j++;
  }
  OperazioniQueue();
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
      QueueVecString.Enqueue(elemento);
      OperazioniQueue();
    }
    if (opzione == '2') { // Rimozione
     
      QueueVecString.Dequeue();
      quit = true;
      OperazioniQueue();
    }

    if (opzione == '3') { // Rimozione con lettura
  
      QueueVecString.HeadNDequeue();
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '4') { // Lettura non distruttiva
     
      elemento = QueueVecString.Head();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniQueue();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
     
      if (QueueVecString.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
      
      elemento = QueueVecString.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '7') { // Svuotamento
     
      quit = true;
      QueueVecString.Clear();
      std::cout<< "Struttura svuotata" << std::endl;
      OperazioniQueue();
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
