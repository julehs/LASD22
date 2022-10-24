
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
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr &htc) noexcept {
    VecSupport=htc.VecSupport;
    p=htc.p;
    dim=htc.dim;
    a=htc.a;
    b=htc.b;

    return *this;
}


//Move Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr &&htc) noexcept{
  std::swap(VecSupport,htc.VecSupport);
  std::swap(p,htc.p);
  std::swap(dim,htc.dim);
  std::swap(a,htc.a);
  std::swap(b,htc.b);

  return *this;

}



/* ************************************************************************ */


//Comparision operators
template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &htc) const noexcept{
    bool supp = true;
    if(dim!=htc.dim)
        return false;
        Fold([htc, &supp](const Data &dato,const void* par, void* acc){
            if(!htc.Exists(dato)){
                supp = false;
            }
        }, 0,0);
        return supp;
}

  // TODO : Controllare la condizione
template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr &htc) const noexcept{
    return !(*this == htc);
}


//Specific Member Function
template <typename Data>
void HashTableClsAdr<Data>::Resize(ulong newSize) noexcept{
  HashTableClsAdr<Data> newTable = HashTableClsAdr(newSize);
  //for (ulong i= 0; i < dim; i++) {
  //    newTable.Insert(VecSupport[i]);
  //    i++;
  //}
  Fold([&newTable] (const Data &dato, const void* par, void* acc){
    newTable.Insert(dato);
  }, 0, 0);
    
  std::swap(*this, newTable);
}


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
