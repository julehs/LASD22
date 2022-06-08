
namespace lasd {



/* ************************************************************************** */

//Specific Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong sizetab) : VecSupport(sizetab), Flag(sizetab){
  p=sizetab;
  for(ulong j = 0; j < p; j++){
    Flag[j] = '0';
  }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data> &con){
  DictionaryContainer<Data>::Insert(con);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong sizetab, const LinearContainer<Data> &con): HashTableOpnAdr(sizetab){
  DictionaryContainer<Data>::Insert(con);
}

/* ************************************************************************** */
//Copy Constructor 
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data> &hto){
  VecSupport = hto.VecSupport;
  Flag = hto.Flag;
  dim = hto.dim;
  p = hto.p;
  a = hto.a;
  b = hto.b;

}

//Move Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data> &&hto) noexcept{
     std::swap(VecSupport, hto.VecSupport);
     std::swap(Flag, hto.Flag);
     std::swap(dim, hto.dim);
     std::swap(a, hto.a);
     std::swap(b, hto.b);
} 

//Copy Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr &hto){
  VecSupport = hto.VecSupport;
  Flag = hto.Flag;
  p = hto.p;
  dim = hto.dim;
  a = hto.a;
  b = hto.b;

  return *this;
}

//Move Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr &&hto) noexcept{
  std::swap(VecSupport, hto.VecSupport);
  std::swap(Flag, hto.Flag);
  std::swap(p, hto.p);
  std::swap(a, hto.a);
  std::swap(b, hto.b);

  return *this;
}

//Comparision operators
template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr &hto) const noexcept{
    bool supp = true;
    if(dim!=hto.dim)
        return false;
        Fold([hto, &supp](const Data &dato,const void* par, void* acc){
            if(!hto.Exists(dato)){
                supp = false;
            }
        }, 0,0);
        return supp;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr &hto) const noexcept{
    return (*this == hto);
}



//Insert Copy
template <typename Data>
void HashTableOpnAdr<Data>::Insert(const Data &dato) { 
    ulong tmp = HashTable<Data>::HashKey(dato);
    if(dim >= p/2){
      Resize(p*2);
    }
    if (!Exists(dato)){
      if (Flag[tmp] == '0' || Flag[tmp] == '1'){
	VecSupport[tmp] = dato;
	Flag[tmp] = '2';
	dim++;
      } else {
	ulong other_tmp = FindEmpty(tmp);
	VecSupport[other_tmp] = dato;
	Flag[other_tmp] = '2';
	dim++;
      }
    }
}


//Insert Move
template <typename Data>
void HashTableOpnAdr<Data>::Insert(Data &&dato) noexcept {
    ulong tmp = HashTable<Data>::HashKey(dato);
    if(dim >= p/2){
      Resize(p*2);
    }
    if (!Exists(dato)){
      if (Flag[tmp] == '0' || Flag[tmp] == '1'){
	std::swap(VecSupport[tmp], dato);
	Flag[tmp] = '2';
	dim++;

      } else {
	ulong other_tmp = FindEmpty(tmp);
	std::swap(VecSupport[other_tmp] , dato);
	Flag[other_tmp] = '2';
	dim++;
      }
    }
}

//Remove
template <typename Data>
void HashTableOpnAdr<Data>::Remove(const Data &dato) {
  if (Exists(dato)) {
    ulong tmp = Find(dato);
    Flag[tmp] = '1';
    if (dim > p / 2) {
      Resize(p * 2);
    }
  }
}

//Exists
template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data &dato) const noexcept {
  /*
    ulong tmp = HashTable<Data>::HashKey(std::hash.operator()(dato));
    ulong i = 1;
        ulong tmp2 = HashKey(tmp, i);
        if (existVector.operator[](tmp) == 'F' || std::vector.operator[](tmp) ==
    dato){ return  true;
        }
        i++;
        tmp2 = HashKey(tmp2, i);
        while(tmp !=tmp2 && (existVector.operator[](tmp) == 'F' ||
    existVector.operator[](tmp) == 'R')){ if(existVector.operator[](tmp) == 'F'
    || std::vector.operator[](tmp) == dato){ return true;

            }
            i++;
            tmp2 = HashKey(tmp2, i);
        }
        return false;
  */

  ulong tmp = HashTable<Data>::HashKey(dato);
  if (Flag[tmp] == '2' && VecSupport[tmp] = dato) {
    return true;
  }
  for (ulong j = tmp + 1; j < p + tmp + 1; j++) {
    if (Flag[j % p] == '2' && VecSupport[j % p] == dato) {
      return true;
    }
  }
  return false;
}

template<typename Data>
void HashTableOpnAdr<Data>::Map(MapFunctor fun, void* par){
    for(ulong i = 0; i < dim; i++){
        if(Flag[i] == '2'){
            fun(VecSupport[i], par);
        }
    }
}

//Fold
template<typename Data>
void HashTableOpnAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const{
    for(ulong j = 0; j < dim; j++){
        if(Flag[j] == '2'){
            fun(VecSupport[j], par, acc);
        }
    }
}

  // TODO: Fixare
template <typename Data>
const ulong HashTable<Data>::HashKey(const Data& value) const noexcept{
    return HashKey(hash.operator()(value));
}

//hashkey diviso in due quindi
template <typename Data>
const ulong HashTable<Data>::HashKey(const ulong &k) const noexcept{
    return ( ( ( ( a*k) +b ) % p) % m);
}


//Find

template<typename Data>
void HashTableOpnAdr<Data>::Find(const Data& dato) const noexcept{
    // ulong tmp = HashTable<Data>::lasd::Hash(std::hash.operator()(data));
    ulong tmp = HashTable<Data>::HashKey(dato);
    while (Flag[tmp] != '0') {
        if (VecSupport[tmp] == dato)
            break;
      tmp = HashTable<Data>::HashKey(tmp);
    }
}

//FindEmpty
template <typename Data>
ulong HashTableOpnAdr<Data>::FindEmpty(const ulong collisionIndex) noexcept {
  ulong tmp = HashTable<Data>::HashKey(collisionIndex);
  while (Flag[tmp] == '2') {
    tmp = HashTable<Data>::HashKey(tmp);
  }
  return tmp;
}

//Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear(){
    VecSupport.Clear();
    Flag.Clear();
    VecSupport = Vector<Data>(p);
    Flag = Vector<char>(p);
    for( ulong j = 0; j < p; j++){
      Flag[j] = '0';
    }
    dim = 0;
}

template <typename Data>
void HashTableOpnAdr<Data>::Remove(Data &dato, const ulong id) {
  if (!(VecSupport.Empty())) {
    if (Exists(dato)) {
      ulong indice = id;
      for (; indice < p; indice++) {
	if (VecSupport[indice] == dato && Flag[indice] == '2') {
	  Flag[indice] = '1';
	}
      }
    }
  }
}

//Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(ulong newSize) {
HashTableOpnAdr<Data> newTable = HashTableOpnAdr(newSize);
    for (ulong i = 0; i < newSize; i++) {
	    newTable.VecSupport[i] = VecSupport[i];
	    newTable.Flag[i] = Flag[i];
	    newTable.dim++;
        }
    std::swap(*this, newTable);
};


/* ************************************************************************** */



}
