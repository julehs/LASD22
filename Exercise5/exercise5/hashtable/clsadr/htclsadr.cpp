
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
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> &htc){}


//Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&htc) noexcept{}


/* ************************************************************************ */

//Copy Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr &htc){}


//Move Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr &&htc) noexcept{}



/* ************************************************************************ */


//Comparision operators
template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr &htc) const noexcept{}

template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr &htc) const noexcept{}


//Specific Member Function
template <typename Data>
void HashTableClsAdr<Data>::Resize(ulong newSize) noexcept{
    HashTableClsAdr<Data> newTable(newSize);
    for (ulong index = 0; index < tableSize; index++) {
        newTable.Insert(vector[index]);
        index++;
    }
    std::swap(*this, newTable);
}


//Insert Copy
template <typename Data>
void HashTableClsAdr<Data>::Insert(const Data &dato){ 
    
}


//Insert Move
template <typename Data>
void HashTableClsAdr<Data>::Insert(Data &&dato) noexcept{

}

//Remove
template <typename Data>
void HashTableClsAdr<Data>::Remove(const Data &dato){
    delete Detach(FindPointerTo(root, dato));
}

//Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& dato) const noexcept{
    return (FindPointerTo(root,dato)!=nullptr);
}


//Map & Fold
template <typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor fun, void* par){
    vector.Map(fun,par);
}

template <typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc)const{
    vector.Fold(fun,par,acc);
}




//Clear
template <typename Data>
void HashTableClsAdr<Data>::Clear(){
    vector.Clear();
    existVector.Clear();
    dim = 0;
}
/* ************************************************************************** */

}
