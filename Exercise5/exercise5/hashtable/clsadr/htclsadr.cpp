
namespace lasd {


/* ************************************************************************** */

//Specific Constructor

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(size_t){}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data> &con){}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(size_t, const LinearContainer<Data> &con){}


/* ************************************************************************ */

 
//Copy Constructor 
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> &htc){
    ulong a,b,p,dim;
    Vector<Data>::ArraySupporter();


    ArraySupporter=htc.ArraySupporter;
    p=htc.p;
    dim=htc.dim;
    a=htc.a;
    b=htc.b;
}


//Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&htc) noexcept{
    std::swap(ArraySupporter, htc.ArraySupporter);
    std::swap(dim, htc.dim);
    std::swap(a, htc.a);
    std::swap(b, htc.b);

}


/* ************************************************************************ */

//Copy Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr &htc){
    ArraySupporter=htc.ArraySupporter;
    p=htc.p;
    dim=htc.dim;
    a=htc.a;
    b=htc.b;

    return this;
}


//Move Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr &&htc) noexcept{
     ArraySupporter=htc.ArraySupporter;
     p=htc.p;
     dim=htc.dim;
     a=htc.a;
     b=htc.b;

    return this;

}



/* ************************************************************************ */


//Comparision operators
template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &htc) const noexcept{
    bool supp = true;
    if(dim!=htc.dim)
        return false;
        Fold([htc, &supp](const Data &dato,const void* par, void* acc)){
            if(!htc.Exists(dato)){
                supp = false;
            }
        }

        (0,0);
        return supp;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr &htc) const noexcept{
    return !(*this == htc);
}


//Specific Member Function
template <typename Data>
void HashTableClsAdr<Data>::Resize(ulong newSize) noexcept{
    HashTableClsAdr<Data> newTable(newSize);
    for (ulong i= 0; i < dim; i++) {
        newTable.Insert(ArraySupporter[i]);
        i++;
    }
    std::swap(*this, newTable);
}


//Insert Copy
template <typename Data>
void HashTableClsAdr<Data>::Insert(const Data &dato){ 
     ArraySupporter[this->HashKey(dato)].Insert(dato);
     ++dim;
    
}


//Insert Move
template <typename Data>
void HashTableClsAdr<Data>::Insert(Data &&dato) noexcept{
     ArraySupporter[this->HashKey(dato)].Insert(std::move(dato));
     ++dim;

}

//Remove
template <typename Data>
void HashTableClsAdr<Data>::Remove(const Data &dato){
     ArraySupporter[this->HashKey(dato)].Remove(dato);
     --dim; 
    
}

//Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& dato) const noexcept{
    return(ArraySupporter[this->HashKey(dato)].Exists(dato));
    
}


//Map & Fold
template <typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor fun, void* par){
    for(ulong i=0; i< this->p;i++){
    ArraySupporter[i].Map(fun,par);
    }
}

template <typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc)const{
    for(ulong i=0; i< this->p;i++){
    ArraySupporter[i].Fold(fun,par,acc);
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
