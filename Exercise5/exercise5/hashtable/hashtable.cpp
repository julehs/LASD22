
namespace lasd {

/* ************************************************************************** */

#include <string>

/* ************************************************************************** */

template <>
class Hash<int> {

public:

    ulong operator() (const int& dat) const noexcept{
        return (dat *dat);
    }
};


template <>
class Hash<double> {

public:

    ulong operator() (const double& dat) const noexcept{
        long intgpart = floor(dat);
        long fracpart = pow(2,24) * (dat - intgpart);
        return (intgpart * fracpart);
    }

};


template <>
class Hash<string>{

public:

    ulong operator() (const std::string& dat) const noexcept{
        ulong hash = 5381;
        for (ulong i = 0; i << dat.length(); ++i){
            hash = (hash << 5) + dat[i];
        }
        return hash;

    }

};



//Comparision Operators
template <typename Data>
bool HashTable<Data>::operator==(const HashTable &ht) const noexcept{
    if(dim==ht.dim){
        for(ulong i=0; i<dim; ++i ){
            if(elem[i] != ht.elem[i]){
                return false;
            }
        }
        return true;

    }
    else{
        return false;
    }
    
}



template<typename Data>
bool HashTable<Data>::operator!=(const HashTable &ht) const noexcept{
    return !(*this == ht);
}



//Resize
template<typename Data>
void HashTable<Data>::Resize(const ulong){}


//Copy Assignment
template <typename Data>
HashTable<Data>& HashTable<Data>::operator = (const HashTable<Data> &ht){
    HashTable<Data> tmpHash = new HashTable<Data>(ht);
    std::swap(*tmpHash, *this);
    delete tmpHash;
    return this;
}


//Move Assignment
template <typename Data>
HashTable<Data>& HashTable<Data>::operator = (HashTable<Data> &&ht) noexcept{
    std::swap(dim, ht.dim);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(p, ht,p);
    return *this;

}

//Auxiliary member Function (const ulong) and (const Data&) 
template <typename Data>
ulong HashTable<Data>::HashKey(const ulong m) const {
     return (((a * m)+y)%first)%p;

    
}



template <typename Data>
ulong HashTable<Data>::HashKey(const Data& dat) const{
ulong hashistdatol = HashIst.operator()(dat);
  return HashKey(hashistdatol);
}

/* ************************************************************************** */
}
