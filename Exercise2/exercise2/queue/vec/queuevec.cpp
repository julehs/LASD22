
namespace lasd {

/* ************************************************************************** */
//Default constructor
template<typename Data>
QueueVec<Data>::QueueVec():Vector<Data>(){}

//Specific constructor
template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& Container): Vector<Data>::Vector(Container){
    dimensione = Container.Size();
    elemento = new Data[dimensione];
    for (ulong i = 0; i < Container.Size(); ){
        Enqueue(Container[i]);
    }
}

//Copy constructor
template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec& Tail): Vector<Data>(Tail){
    testa = Tail.testa;
    coda = Tail.coda;
} 

//Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& Tail):Vector<Data>(std::move(Tail)) noexcept{
    testa = Tail.testa;
    coda = Tail.coda;

    Coda.Clear();
}

//Copy assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (const QueueVec& Tail){
    Vector<Data>::operator=(Tail);
    testa = Tail.testa;
    coda = Coda.coda;

    return *this;
}

//Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (QueueVec&& Tail) noexcept{
   Vector<Data>::operator=(std::move(Tail));
   std::swap(testa, Tail.testa);
   std::swap(coda, Tail.coda); 
}

//Comparision
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& Tail) const noexcept{
    if(this == &Coda)
      return true;

    if(Size() != Tail.Size())
      return false;

    ulong i = testa;
    ulong j = Tail.testa;
    ulong compares = 0;
    while(i != coda && Vector<Data>::operator[](i) == Tail.Vector<Data>::operator[](j) ){
      i = (i+1) % dimensione;
      j = (j+1) % Tail.dimensione;
      compares++;
    }

    return compares == Size();

}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& Tail) const noexcept{
  return !(*this == Tail);
}



//Member function
//Head constant version
template <typename Data>
const Data& QueueVec<Data>::Head() const{
    if(Empty())
  	throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

}

//Head
template <typename Data>
Data& QueueVec<Data>::Head() const{
    if(Empty())
  	throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

  return Vector<Data>::operator[](testa);
}

//Dequeue
template <typename Data>
void QueueVec<Data>::Dequeue(){ 
  if(Empty())
  	throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

//Moving to an internal variable that will be deleted upon exiting the scope
  Data del = std::move(Vector<Data>::operator[](testa));
  (void)del;
  testa = (testa+1) % dimensione;
  if(Size() < dimensione/4)
    Reduce();
}

//HeadNDequeue
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){ 
  if(Empty())
  	throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

  Data ret = std::move(Vector<Data>::operator[](testa));

  testa = (testa+1) % dimensione;
  if(Size() < dimensione/4)
    Reduce();

  return ret;
}


//Enqueue copy
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& d){  
  Vector<Data>::operator[](coda) = d;
  coda = (coda+1) % dimensione;

  if(coda == testa)
    Expand();
}


//Enqueue move
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& d){ 
  Vector<Data>::operator[](coda) = std::move(d);
  coda = (coda+1) % dimensione;

  if(coda == testa)
    Expand();
}


//Empty, Size, Clear
template <typename Data>
inline bool QueueVec<Data>::Empty() const noexcept { 
  return testa == coda;
}
template <typename Data>
inline ulong QueueVec<Data>::Size() const noexcept { 
  return (dimensione -  testa + coda) % dimensione;
}
template <typename Data>
void QueueVec<Data>::Clear() noexcept { 
  Vector<Data>::Resize(2);
  testa = coda = 0;
}

//Auxiliary member function
//Expand function
template <typename Data>
void QueueVec<Data>::Expand(){ 
  Vector<Data>::Resize(dimensione*2);

  ulong j;
  for(j = 0; j < coda; j++)
    Vector<Data>::operator[](j+dimensione/2) = std::move(Vector<Data>::operator[](j));

  coda = j + dimensione/2;
}


//Reduce function
template <typename Data>
void QueueVec<Data>::Reduce(){ 
  Vector<Data> d(dimensione/2);

  ulong p = 0;
  ulong j = testa;
  while(j != coda){
      d[p++] = std::move(Vector<Data>::operator[](j));
      j = (j+1) % dimensione;
  }

  testa = 0;
  coda = p;
  Vector<Data>::operator=(std::move(d));
}

/* ************************************************************************** */

}
