#include <stdexcept>

namespace lasd {

/* ************************************************************************** */

//Specific constructors
template <typename Data>
BST<Data>::BST(const LinearContainer<Data> &con){
    for(ulong i = 0; i< con.Size(); i++){
        Insert(con[i]);
    }
}



//Copy constructor
template <typename Data>
BST<Data>::BST(const BST<Data> &bt): BinaryTreeLnk<Data>(bt){}

//Move constructor
template <typename Data>
BST<Data>::BST(BST<Data> &&bt) noexcept : BinaryTreeLnk<Data>(std::move(bt)){}



//Copy assignment
template <typename Data>
BST<Data>& BST<Data>::operator=(const BST &bt){
    BinaryTreeLnk<Data>::operator=(bt);
    return *this;
}

//Move assignment
template<typename Data>
BST<Data>& BST<Data>::operator=(BST &&bt) noexcept{
    BinaryTreeLnk<Data>::operator=(std::move(bt));
    return *this;
}

//Comparision operators
template <typename Data>
bool BST<Data>::operator==(const BST &bt) const noexcept{
    if(dim==bt.dim){
        if(dim==0)
            return true;


    BTInOrderIterator<Data> iterThis(*this);
    BTInOrderIterator<Data> iterOther(bt);
    while(!iterThis.Terminated() && !iterOther.Terminated()){
        if(*iterThis != *iterOther)
            return false;
        ++iterThis;
        ++iterOther;
    }template <typename Data>
    if(iterThis.Terminated() && iterOther.Terminated())
        return true;

    }
    return false;

    
}

template <typename Data>
bool BST<Data>::operator!=(const BST &bt) const noexcept{
    return !(*this == bt);
}
/* ************************************************************************** */

}
