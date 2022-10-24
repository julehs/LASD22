
namespace lasd {


/* ************************************************************************** */

//Specific Constructor

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong newsize){
 sizeHT = newsize;
 table.Resize(sizeHT);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data> &lc) {
  table.Resize(lc.Size());
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
    size = htClsAdr.size;
    sizeHT = htClsAdr.sizeHT;
    a = htClsAdr.a;
    b = htClsAdr.b;
}


//Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&htc) noexcept{
    std::swap(table, htClsAdr.table);
    std::swap(size, htClsAdr.size);
    std::swap(sizeHT, htClsAdr.sizeHT);
    std::swap(a, htClsAdr.a);
    std::swap(b, htClsAdr.b);

}


/* ************************************************************************ */

//Copy Assignment
template <typename Data> 
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> &htClsAdr) noexcept {
    table = htClsAdr.table;
    size = htClsAdr.table;
    sizeHT = htClsAdr.sizeHT;
    a=htClsAdr.a;
    b=htClsAdr.b;

    return *this;
}


//Move Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr &&htClsAdr) noexcept{
  std::swap(table,htClsAdr.table);
  std::swap(size,htClsAdr.size);
  std::swap(sizeHT,htClsAdr.sizeHT);
  std::swap(a,htClsAdr.a);
  std::swap(b,htClsAdr.b);

  return *this;

}



/* ************************************************************************ */


//Comparision operators
template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &htClsAdr) const noexcept{
   if ((size = 0) && (htClsAdr.size == 0)){
      return true;
   }

  if(size == htClsAdr.size) {
    for(ulong i = 0; i < size; i++){
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
  
  
  
  for (ulong i= 0; i < size; i++) {
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
void HashTableClsAdr<Data>::Insert(const Data &dato) noexcept { 
     VecSupport[this->HashKey(dato)].Insert(dato);
     ++dim;
}


//Insert Move
template <typename Data>
void HashTableClsAdr<Data>::Insert(Data &&dato) noexcept{
     VecSupport[this->HashKey(dato)].Insert(std::move(dato));
     ++dim;

}

//Remove
template <typename Data>
void HashTableClsAdr<Data>::Remove(const Data &dato) noexcept {
     VecSupport[this->HashKey(dato)].Remove(dato); 
     --dim; 
    
}

//Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& dato) const noexcept{
    return(VecSupport[this->HashKey(dato)].Exists(dato));
    
}


//Map & Fold
template <typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor fun, void* par){
  for(ulong i=0; i< this->p;i++){
    VecSupport[i].Map(fun,par);
  }
}

template <typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc)const{
  for(ulong i=0; i< this->p;i++){
    VecSupport[i].Fold(fun,par,acc);
  }
}




//Clear
template <typename Data>
void HashTableClsAdr<Data>::Clear() noexcept {
    HashTableClsAdr<Data> newHashTable = new HashTableClsAdr<Data>();
    std::swap(this, *newHashTable);
    this->dim = 0;
    delete newHashTable;
}
/* ************************************************************************** */



}
