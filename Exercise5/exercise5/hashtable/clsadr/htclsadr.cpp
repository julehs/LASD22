
namespace lasd {


/* ************************************************************************** */

//Specific Constructor

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong newsize){
 sizeHT = newsize;
 table.Resize(sizeHT);
}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data> &lc){
  table.Resize(lc.Size());

  for(ulong i=0; i<lc.Size(); i++){
    Insert(lc[i]);
  }
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong newsize, const LinearContainer<Data> &lc){
  sizeHT = newsize;
  table.Resize(sizeHT);


  for(ulong i=0; i< lc.Size(); i++){
    Insert(lc[i]);
  }
}


/* ************************************************************************ */

 
//Copy Constructor 
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> &htClsAdr) noexcept {
    table = htClsAdr.table;
    dim = htClsAdr.dim;
    sizeHT = htClsAdr.sizeHT;
    a = htClsAdr.a;
    b = htClsAdr.b;
}


//Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&htClsAdr) noexcept{
    std::swap(table, htClsAdr.table);
    std::swap(dim, htClsAdr.dim);
    std::swap(sizeHT, htClsAdr.sizeHT);
    std::swap(a, htClsAdr.a);
    std::swap(b, htClsAdr.b);

}


/* ************************************************************************ */

//Copy Assignment
template <typename Data> 
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> &htClsAdr) noexcept {
    table = htClsAdr.table;
    dim = htClsAdr.dim;
    sizeHT = htClsAdr.sizeHT;
    a=htClsAdr.a;
    b=htClsAdr.b;

    return *this;
}


//Move Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr &&htClsAdr) noexcept{
  std::swap(table,htClsAdr.table);
  std::swap(dim,htClsAdr.dim);
  std::swap(sizeHT,htClsAdr.sizeHT);
  std::swap(a,htClsAdr.a);
  std::swap(b,htClsAdr.b);

  return *this;

}



/* ************************************************************************ */


//Comparision operators
template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &htClsAdr) const noexcept{
   if ((dim == 0) && (htClsAdr.dim == 0)){
      return true;
   }

  if(dim == htClsAdr.dim) {
    for(ulong i = 0; i < dim; i++){
      BTInOrderIterator<Data> itThis(table[i]);
      while (!itThis.Terminated()) {
        if (!(htClsAdr.Exists(*itThis))){
          return false;
        }
        ++itThis;
      }
      return true;
      
    }
  }

return false;
}

  
template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data> &htClsAdr) const noexcept{
    return !(*this == htClsAdr);
}


//Specific Member Function (inherited from HashTable)

template <typename Data>
void HashTableClsAdr<Data>::Resize(const ulong newdim) noexcept{
  HashTableClsAdr<Data> ht(newdim); 
  
  
  
  for (ulong i= 0; i < dim; i++) {
    BTInOrderIterator<Data> itThis(table[i]);
    while (!itThis.Terminated()){
      ht.Insert(*itThis);
      ++itThis;
    }  
  }
  
  *this = std::move(ht);
}
/* ************************************************************************** */
// Specific member functions (inherited from DictionaryContainer)

//TODO



//Insert Copy
template <typename Data>
void HashTableClsAdr<Data>::Insert(const Data &data) noexcept { 
     ulong key = hash(data);

     if(!table[HashKey(key)].Exists(data)) {
        table[HashKey(key)].Insert(data);
        dim++;
     }
}


//Insert Move
template <typename Data>
void HashTableClsAdr<Data>::Insert(Data &&data) noexcept{
    ulong key = hash(data);

    if(!table[HashKey(key)].Exists(data)) {
      table[HashKey(key)].Insert(std::move(data));
      dim++;
    }
}

//Remove
template <typename Data>
void HashTableClsAdr<Data>::Remove(const Data &data) noexcept {
     ulong key = hash(data);
     if(table[HashKey(key)].Exists(data)){
      table[HashKey(key)].Remove(data);
      dim--;
     }
     
    
}

/* ************************************************************************** */

// Specific member functions (inherited from TestableContainer)

//Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept{
    if(dim == 0){
      return false;
    }

    ulong key = hash(data);

    return table[HashKey(key)].Exists(data);
    
}

/* ************************************************************************** */

// Specific member functions (inherited from MappableContainer & FoldableContainer)

//Map 
template <typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor fun, void* par){
  for(ulong i = 0; i < sizeHT;i++) {
    table[i].MapPreOrder(fun,par);
  }
}

//Fold

template <typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc)const{
  for(ulong i = 0; i < sizeHT; i++) {
    table[i].FoldPreOrder(fun, par, acc);
  }
}


// Specific member functions (inherited from Container)


//Clear
template <typename Data>
void HashTableClsAdr<Data>::Clear() noexcept {
   table.Clear();
   sizeHT = 256;
   dim = 0;
   table.Resize(sizeHT);
}
/* ************************************************************************** */



}
