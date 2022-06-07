
namespace lasd {

/* ************************************************************************** */

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong){}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data> &con){}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong LinearContainer<Data> &con){}


//Copy Constructor 
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data> &hto){}

//Move Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data> &&hto) noexcept{}

//Copy Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr &hto){}

//Move Assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr &&hto) noexcept{}

//Comparision operators
template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr &hto) const noexcept{}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr &hto) const noexcept{}


//Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(ulong newSize) noexcept{
    HashTableOpnAdr<Data> newTable(newSize);
    for (ulong index = 0; index < tableSize; index++) {
        newTable.Insert(vector[index]);
        index++;
    }
    std::swap(*this, newTable);
}

//Insert Copy
template <typename Data>
void HashTableOpnAdr<Data>::Insert(const Data &dato){ //TODO scegli struttura dati!!
    
}


//Insert Move
template <typename Data>
void HashTableOpnAdr<Data>::Insert(Data &&dato) noexcept{

}

//Remove
template <typename Data>
void HashTableOpnAdr<Data>::Remove(const Data &dato){
    delete Detach(FindPointerTo(root, dato));
}

//Exists
template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& dato) const noexcept{
    return (FindPointerTo(root,dato)!=nullptr);
}


//Map & Fold
template <typename Data>
void HashTableOpnAdr<Data>::Map(MapFunctor fun, void* par){}

template <typename Data>
void HashTableOpnAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc)const{}




//Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear(){}

//TODO HASHKEY,FIND,FINDEMPTY,REMOVE


/* ************************************************************************** */

}
