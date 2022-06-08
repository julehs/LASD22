
namespace lasd {


/* ************************************************************************** */

//Specific Constructor

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong sizetab) : VecSupport(sizetab){
  this->p = sizetab;
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() : VecSupport(50){
  this->p = 50;
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data> &con): VecSupport(con.Size() * 2){
  p = con.Size() * 2;
  DictionaryContainer<Data>::Insert(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong sizetab, const LinearContainer<Data> &con): VecSupport(sizetab){
  DictionaryContainer<Data>::Insert(con);
}


/* ************************************************************************ */

 
//Copy Constructor 
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> &htc){
    VecSupport=htc.VecSupport;
    p=htc.p;
    dim=htc.dim;
    a=htc.a;
    b=htc.b;
}


//Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&htc) noexcept{
    std::swap(VecSupport, htc.VecSupport);
    std::swap(p, htc.p);
    std::swap(dim, htc.dim);
    std::swap(a, htc.a);
    std::swap(b, htc.b);

}


/* ************************************************************************ */

//Copy Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr &htc){
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
void HashTableClsAdr<Data>::Insert(const Data &dato){ 
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
void HashTableClsAdr<Data>::Remove(const Data &dato){
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
void HashTableClsAdr<Data>::Clear(){
    HashTableClsAdr<Data> newHashTable = new HashTableClsAdr<Data>();
    std::swap(this, *newHashTable);
    this->dim = 0;
    delete newHashTable;
}
/* ************************************************************************** */



}
