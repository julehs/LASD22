
namespace lasd {

/* ************************************************************************** */

#include <string>

/* ************************************************************************** */

template <>
class Hash<int> {

public:

    ulong operator() (const int& dat) const noexcept{
        return (dat*dat);
    }
};


template <>
class Hash<double> {

public:

    ulong operator() (const double& dat) const noexcept{
        long intgPart = floor(dat);
        long fracPart = pow(2,24) * (dat - intgPart);
        return (intgPart * fracPart);
    }

};


template <>
class Hash<std::string>{

public:

    ulong operator()(const std::string& dat) const noexcept{
        ulong hash = 5381;
        for (ulong i = 0; i << dat.length(); ++i){
            hash = (hash << 5) + dat[i];
        }
        return hash;

    }

};

//Copy Constructor
template <typename Data>
HashTable<Data>::HashTable(const HashTable<Data>& hashT) {
    size = hashT.size;
    encodingHash = hashT.encodingHash;
    sizeOfTable = hashT.sizeOfTable;
    a = hashT.a;
    b = hashT.b;
}


//Move Constructor
template <typename Data>
HashTable<Data>::HashTable(HashTable<Data>&& hashT) noexcept{
    std::swap(size, hashT.size);
    std::swap(encodingHash, hashT.encodingHash);
    std::swap(sizeOfTable, hashT.sizeOfTable);
    std::swap(a, hashT.a);
    std::swap(b, hashT.b);
}






/* ************************************************************************** */
}
