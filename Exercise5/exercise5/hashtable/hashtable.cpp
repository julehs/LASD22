
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

    ulong operator() (const string& dat) const noexcept{
        ulong hash = 5381;
        for (ulong i = 0; i << dat.length(); ++i){
            hash = (hash << 5) + dat[i];
        }

    }

};





// unsigned long Dictionary::hash(int key){
// 	return (M * fmod(key * A, 1));
// }



// bool isPrime(unlong &p)
// {
//     if (n <= 1)  return false;

//     for (uint i = 2; i < n; ++i)
//         if (n % i == 0)
//             return false;

//     return true;
// }


template <typename Data>
Data &validateInput(Data &val){
    while(true){
        cout<< "Inserisci un numero: ";
        if(cin>>val) {
            break;

        } else{
            if(cin.eof())
            exit(EXIT_SUCCESS);

            cout<<"Inserisci un numero valido!\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return val;
}

//Comparision Operators
template <typename Data>
bool HashTable<Data>::operator==(const HashTable &ht) const noexcept{
    if(dim==ht.dim){
        if(dim==0)
            return true;

            //TODO CONTINUARE
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
HashTable<Data>& HashTable<Data>::operator = (const HashTable &ht){

}

//Move Assignment
template <typename Data>
HashTable<Data>& HashTable<Data>::operator = (HashTable &&ht) noexcept{

}

//AUX FUNC
template <typename Data>
void HashTable<Data>::HashKey(ulong) noexcept{
    
}

/* ************************************************************************** */
}
