#include <stdexcept>

namespace lasd {

/* ************************************************************************** */

//Specific constructors
template <typename Data>
BST<Data>::BST(const LinearContainer<Data> &con){
    for(ulong i = 0; i < con.Size(); i++){
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



//Specific member functions
//Min function

template<typename Data>
const Data& BST<Data>::Min() const{
    if(root==nullptr)
        throw std::length_error("Access to an empty BST.");
    
    return FindPointerToMin(root)->elem;
}


template <typename Data>
Data BST<Data>::MinNRemove(){
    if(root==nullptr)
        throw std::length_error("Access to an empty BST.")
    
    return DataNDelete(DetachMin(root));
}


template <typename Data>
void BST<Data>::RemoveMin(){
    if(root==nullptr)
        throw std::length_error("Access to an empty BST.");

   delete DetachMin(root); 
}


//Max function
template <typename Data>
const Data& BST<Data>::Max() const{
    if(root==nullptr)
        throw std::length_error("Access to an empty BST.");
    
    return FindPointerToMax(root)->elem;
}

template <typename Data>
Data BST<Data>::MaxNRemove(){
    if(root == nullptr)
        throw std::length_error("Access to an empty BST.");

    return DataNDelete(DetachMax(root));
}

template <typename Data>
void BST<Data>::RemoveMax(){
    if(root == nullptr)
        throw std::length_error("Access to an empty BST.");
    
    delete DetachMax(root);
}


//Predecessor function
template<typename Data>
const Data& BST<Data>::Predecessor(const Data &dato) const{
    struct BST<Data>::NodeLnk* const* pointer = &FindPointerToPredecessor(root, dato);
    if(*pointer == nullptr)
        throw std::length_error("Predecessor not found.");
    
    return DataNDelete(Detach(*pointer));
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data &dato){
    struct BST<Data>::NodeLnk
}
/* ************************************************************************** */

}
