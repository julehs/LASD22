
namespace lasd {



/* ************************************************************************** */

//Specific Constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong){}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data> &con){}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(size_t, const LinearContainer<Data> &con){}


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



//Insert Copy
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data &dato) noexcept{ 
    ulong tmp = HashTable<Data>::HashKey(std::hash.operator()(dato));
    if(!Exists(dato)){
        ulong tmp = HashTable<Data>::HashKey(hash.operator()(dato));
        if(existVector.operator[](tmp)=='E' || existVector.operator[](tmp)== 'R'){ //when empty
            std::vector.operator[](tmp) = dato;
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
bool HashTableOpnAdr<Data>::Insert(Data &&dato) noexcept {
    if(!Exists(dato)) {
        ulong tmp = HashTable<Data>::HashKey(std::hash.operator()(dato));
        if(existVector.operator[](tmp)=='E' || existVector.operator[](tmp)== 'R'){ //when empty
            std::vector.operator[](tmp) = dato;  
            existVector.operator[](tmp) = 'F';
            dim++;
            return true;
    }
    else if (existVector.operator[](tmp)=='F'){
        ulong tmp2 = FindEmpty(tmp);
        std::vector.operator[](tmp2) = dato;
        existVector.operator[](tmp2) = 'F';
        dim++;
        return true; 
        
    }
}
return false;

}

//Remove
template <typename Data>
void HashTableOpnAdr<Data>::Remove(const Data &dato){
    // delete Detach(FindPointerTo(root, dato)); //??
}


//Exists
template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& dato) const noexcept{
    ulong tmp = HashTable<Data>::HashKey(std::hash.operator()(dato));
    ulong i = 1;
        ulong tmp2 = HashKey(tmp, i);
        if (existVector.operator[](tmp) == 'F' || std::vector.operator[](tmp) == dato){
            return  true;
        }
        i++;
        tmp2 = HashKey(tmp2, i);
        while(tmp !=tmp2 && (existVector.operator[](tmp) == 'F' || existVector.operator[](tmp) == 'R')){
            if(existVector.operator[](tmp) == 'F' || std::vector.operator[](tmp) == dato){
                return true;

            } 
            i++;
            tmp2 = HashKey(tmp2, i);
        }
        return false;
}




//Map & Fold
template <typename Data>
void HashTableOpnAdr<Data>::Map(MapFunctor fun, void* par){
    std::vector.Map(fun,par);
}

template <typename Data>
void HashTableOpnAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc)const{
    std::vector.Fold(fun,par,acc);
}






//TODO HASHKEY,FIND,FINDEMPTY,REMOVE

//dato chiama l'hash di econding e chiama l'altra versione di hashkey
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




//Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear(){
    std::vector.Clear();
    existVector.Clear();
    dim = 0;
}

//FindEmpty
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



//Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(ulong newSize) noexcept{
HashTableOpnAdr<Data> newTable(newSize);
    for (ulong i = 0; i < tableSize; i++) {
            newTable.Insert(std::vector[i]);
            i++;
        }
    std::swap(*this, newTable);
};

//Remove



/* ************************************************************************** */



}