
namespace lasd {

/* ************************************************************************** */

//Specific Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong){}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data> &con){}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong LinearContainer<Data> &con){}
Schermata del 2022-06-07 16-02-57

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
void HashTableOpnAdr<Data>::Insert(const Data &dato){ 
    //TODO scegli struttura dati!!
    ulong tmp = HashTable<Data>::HashKey(hash.operator()(dato));
    if(!Exists(data)){
        ulong tmp = HashTable<Data>::HashKey(hash.operator()(dato));
        if(existVector.operator[](tmp)=='E' || existVector.operator[](tmp)== 'R'){ //when empty
            vector.operator[](tmp) = dato;
            existVector.operator[](tmp) = 'F';
            dim++;
            return true; 

        }
        else if (existVector.operator[](tmp) == 'F'){ //collision
            ulong tmp_collision = FindEmpty(tmp);
            vector.operator[](tmp_collision) = dato;
            existVector.operator[](tmp_collision) = 'F';
            dim++;
            return true;

        }
    }
    return false;
    
}


//Insert Move
template <typename Data>
void HashTableOpnAdr<Data>::Insert(Data &&dato) noexcept{
    if(!Exists(dato)) {
        ulong tmp = HashTable<Data>::HashKey(hash.operator()(dato));
        if(existVector.operator[](tmp)=='E' || existVector.operator[](tmp)== 'R'){ //when empty
        //std::swap
    }

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
void HashTableOpnAdr<Data>::Map(MapFunctor fun, void* par){
    vector.Map(fun,par);
}

template <typename Data>
void HashTableOpnAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc)const{
    vector.Fold(fun,par,acc);
}




//Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear(){
    vector.Clear();
    existVector.Clear();
    dim = 0;
}

//TODO HASHKEY,FIND,FINDEMPTY,REMOVE

template <typename Data>
ulong& HashTableOpnAdr<Data>::FindEmpty(ulong& collisionIndex) noexcept{
    ulong tmp = collisionIndex;
    ulong increment = 1;
    collisionIndex = HashKey(collisionIndex, increment);
    while(collisionIndex != tmp){
        if(existVector.operator[](collisionIndex)=='E'){
            return collisionIndex;
        }
        else{
            increment++;
            collisionIndex = HashKey(collisionIndex, increment);
        }
    }
    Resize(tableSize * 2);
    FindEmpty(tmp);
}

/* ************************************************************************** */

}
