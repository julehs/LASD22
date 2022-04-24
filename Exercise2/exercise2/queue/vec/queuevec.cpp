
namespace lasd {

/* ************************************************************************** */
//Default constructor
template<typename Data>
QueueVec<Data>::QueueVec(){
  dim = 4;
  elem = new Data[dim] {};
}

//Specific constructor
template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& Container): Vector<Data>::Vector(Container){
    dim = Container.Size();
    elem = new Data[dim];
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
QueueVec<Data>::QueueVec(QueueVec&& Tail) noexcept :Vector<Data>(std::move(Tail)) {
    testa = Tail.testa;
    coda = Tail.coda;

    Tail.Clear();
}

//Copy assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (const QueueVec& Tail){
    Vector<Data>::operator=(Tail);
    testa = Tail.testa;
    coda = Tail.coda;

    return *this;
}

//Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (QueueVec&& Tail) noexcept{
   Vector<Data>::operator=(std::move(Tail));
   std::swap(testa, Tail.testa);
   std::swap(coda, Tail.coda); 
   return *this;
}

//Comparision
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& Tail) const noexcept{
    
    if(this == &Tail)
      return true;

    if(Size() != Tail.Size())
      return false;

    ulong i = testa;
    ulong j = Tail.testa;
    ulong compares = 0;
    while(i != coda && Vector<Data>::operator[](i) == Tail.Vector<Data>::operator[](j) ){
      i = (i+1) % dim;
      j = (j+1) % Tail.dim;
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
const Data& QueueVec<Data>::Head(){
    if(Empty())
  	throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

    return Vector<Data>::operator[](testa);

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
  testa = (testa+1) % dim;
  if(Size() < dim/4)
    Reduce();
}

//HeadNDequeue
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){ 
  if(Empty())
  	throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

  Data ret = std::move(Vector<Data>::operator[](testa));

  testa = (testa+1) % dim;
  if(Size() < dim/4)
    Reduce();

  return ret;
}


//Enqueue copy
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& d){  
  Vector<Data>::operator[](coda) = d;
  coda = (coda+1) % dim;

  if(coda == testa)
    Expand();
}


//Enqueue move
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& d){ 
  Vector<Data>::operator[](coda) = std::move(d);
  coda = (coda+1) % dim;

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
  return (dim -  testa + coda) % dim;
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
  Vector<Data>::Resize(dim*2);

  ulong j;
  for(j = 0; j < coda; j++)
    Vector<Data>::operator[](j+dim/2) = std::move(Vector<Data>::operator[](j));

  coda = j + dim/2;
}


//Reduce function
template <typename Data>
void QueueVec<Data>::Reduce(){ 
  Vector<Data> d(dim/2);

  ulong p = 0;
  ulong j = testa;
  while(j != coda){
      d[p++] = std::move(Vector<Data>::operator[](j));
      j = (j+1) % dim;
  }

  testa = 0;
  coda = p;
  Vector<Data>::operator=(std::move(d));
}

/* ************************************************************************** */

}
