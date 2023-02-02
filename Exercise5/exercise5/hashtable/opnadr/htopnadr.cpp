
namespace lasd {



/* ************************************************************************** */

//Specific Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newdim) noexcept {
  sizeHT = newdim;
  table.Resize(sizeHT);
  controllerTable.Resize(sizeHT);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data> &lc) noexcept{
  table.Resize(lc.Size());
  controllerTable.Resize(lc.Resize());

  for(ulong i = 0; i < lc.Size(); i++){
    Insert(lc[i]);
   }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newdim, const LinearContainer<Data> &lc) noexcept{
  sizeHT = newdim;
  table.Resize(sizeHT);
  controllerTable.Resize(sizeHT);

  for(ulong i = 0; i < lc.Size(); i++){
    Insert(lc[i]);
  }
}

/* ************************************************************************** */
//Copy Constructor 
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data> &htOpnAdr) noexcept{
  table = htOpnAdr.table;
  controllerTable = htOpnAdr.controllerTable;
  dim = htOpnAdr.dim;
  sizeHT = htOpnAdr.sizeHT;
  a = htOpnAdr.a;
  b = htOpnAdr.b;

}

//Move Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data> &&htOpnAdr) noexcept{
     std::swap(table, htOpnAdr.table);
     std::swap(controllerTable, htOpnAdr.controllerTable);
     std::swap(dim, htOpnAdr.dim);
     std::swap(sizeHT, htOpnAdr.sizeHT);
     std::swap(a, htOpnAdr.a);
     std::swap(b, htOpnAdr.b);
} 

//Copy Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data> &htOpnAdr) noexcept{

  HashTableOpnAdr<Data> *tmp = new HashTableOpnAdr(htOpnAdr);
  std::swap(*this, *tmp);
  delete tmp;

  return *this;
}

//Move Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data> &&htOpnAdr) noexcept{
  std::swap(table, htOpnAdr.table);
  std::swap(controllerTable, htOpnAdr.controllerTable);
  std::swap(dim, htOpnAdr.dim);
  std::swap(sizeHT, htOpnAdr.sizeHT);
  std::swap(a, htOpnAdr.a);
  std::swap(b, htOpnAdr.b);

  return *this;
}

//Comparision operators
template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data> &htOpnAdr) const noexcept{
  if ((dim == 0) && (htOpnAdr.dim == 0)){
    return true;
  }

  if(dim == htOpnAdr.dim){
    for(ulong i = 0; i < dim; i++){
      if((int)controllerTable[i] == 1){
        if(!(htOpnAdr.Exists(table[i]))){
          return false;
        }
      }
    }
    return true;
  }
  
  return false;

}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data> &htOpnAdr) const noexcept{
    return (*this == htOpnAdr);
}


/* ************************************************************************** */
// Specific member functions (inherited from HashTable)


template <typename Data>
void HashTableOpnAdr<Data>::Resize(const ulong newdim) noexcept{
  HashTableOpnAdr<Data> ht(newdim);

  for (ulong i = 0; i < sizeHT; i++) {
    if((int)controllerTable[i] == 1) {
      ht.Insert(table[i]);
    }
  }
  *this = std::move(ht);

}

/* ************************************************************************** */

// Specific member functions (inherited from DictionaryContainer)


//Insert Copy
template <typename Data>
void HashTableOpnAdr<Data>::Insert(const Data &data) {
  ulong index = FindEmpty(data);
  if(index < sizeHT){
    table[index] = data;
    controllerTable[index] = (char)1;
    dim++;
  }

}



//Insert Move
template <typename Data>
void HashTableOpnAdr<Data>::Insert(Data &&data) noexcept {
  ulong index = FindEmpty(data);

if(index < sizeHT) {
  table[index] = std::move(data);
  controllerTable[index] = (char)1;
  dim++;
  }

}


//Remove
template <typename Data>
void HashTableOpnAdr<Data>::Remove(const Data &data) {
  ulong index = Find(data);


  if(index!= sizeHT){
    controllerTable[index] = (char)2;
    dim--;
  }
}

/* ************************************************************************** */

// Specific member functions (inherited from TestableContainer)

//Exists
template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data &data) const noexcept {
  if(dim == 0){
    return false;
  }
  ulong index = Find(data);

  return (index != sizeHT);

}

/* ************************************************************************** */

// Specific member functions (inherited from MappableContainer)

template<typename Data>
void HashTableOpnAdr<Data>::Map(MapFunctor fun, void* par){
    for(ulong i = 0; i < dim; i++){
        if((int)controllerTable[i]==1) {
            table.MapPreOrder(fun, par);
        }
    }
}

/* ************************************************************************** */

// Specific member functions (inherited from FoldableContainer)


//Fold
template<typename Data>
void HashTableOpnAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const{
    for(ulong i = 0; i < dim; i++){
        if((int)controllerTable[i] == 1){
          table.FoldPreOrder(fun, par, acc);
        }
    }
}

/* ************************************************************************** */

// Specific member functions (inherited from Container)

template <typename Data>
void HashTableOpnAdr<Data>::Clear(){
  table.Clear();
  controllerTable.Clear();
  dim = 0;
  sizeHT = 256;
  table.Resize(sizeHT);
  controllerTable.Resize(sizeHT);
} 

/* ************************************************************************** */

// Auxiliary member functions
//TODO Find

template <typename Data>
ulong HashTableOpnAdr<Data>::Find(const Data& data) const noexcept{
  ulong base = HashKey(hash(data));
  ulong tempIndex = base;

  bool test = controllerTable[tempIndex] == 1 && table[tempIndex] == data;
  if(test){
    return tempIndex;
  }
  else{
    for (ulong i = 1; (int)controllerTable[tempIndex] != 0 && !test; i++) {
      tempIndex = (base + ProbFun(1)) % sizeHT;
      test = controllerTable[tempIndex] == 1 && table[tempIndex] == data;
    }

    if (test){
      return tempIndex;
    }
    else {
      return sizeHT; //valore gia esistente
    }
  }
}

//FindEmpty
template <typename Data>
ulong HashTableOpnAdr<Data>::FindEmpty(const Data data) noexcept{
  if (dim >= (sizeHT / 2)){
    Resize(sizeHT * 2);
  }
  ulong base = HashKey(hash(data));
  ulong tempIndex = base;

  if((int)controllerTable[tempIndex] == 0){
    return tempIndex;
  }
  else{
    bool test = controllerTable[tempIndex] == 1 && table [tempIndex] == data;
    for(ulong i = 1; (int)controllerTable[tempIndex] != 0 && !test; i++){
      tempIndex = (base + ProbFun(i)) % sizeHT;
      // test = controllerTable[tempIndex] == 1 && table[tempIndex] == data;
    }

    if(test){
      return sizeHT;
    }
    else{
      return tempIndex;
    }
  }
}



/* ************************************************************************** */



}
