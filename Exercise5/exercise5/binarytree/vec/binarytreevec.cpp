#include <stdexcept>

namespace lasd {

/* ************************************************************************** */
//NodeVec

//Constructor
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data &dato,ulong indice, Vector<NodeVec*> *vec){
    elem = dato;
    indexNode = indice;
    vectorPointer = vec;
}

//Specific member function
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{
    return elem;
}

template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
    return elem;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
    return(indexNode*2+1) <= (vectorPointer->Size() - 1);
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
    return(indexNode*2+2) <= (vectorPointer->Size() - 1);
}

template <typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if(!HasLeftChild())
        throw std::out_of_range("Access to an empty child.");

    return *(vectorPointer->operator[](indexNode*2+1));
}

template <typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild()const{
    if(!HasRightChild())
        throw std::out_of_range("Access to an empty child.");

    return *(vectorPointer->operator[](indexNode*2+2));
}


//TreeVec
//Specific Constructor
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data> &con){
    if(con.Size()){
        dim = con.Size();
        treevector = new Vector<NodeVec*>(dim);

        for(uint i = 0; i<dim; i++){
            NodeVec* node = new NodeVec(con[i],i,treevector);
            treevector->operator[](i)=node;
        }
    }
}


//Copy Constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data> &bt){
    dim = bt.dim;
    treevector = new Vector<NodeVec*>(dim);
    for(uint i = 0; i<dim; i++){
        NodeVec* node = new NodeVec(bt.treevector->operator[](i)->Element(), i,treevector);
        treevector->operator[](i) = node;
    
    }
}


//Move Constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data> &&bt) noexcept{
    treevector = new Vector<NodeVec*>();
    std::swap(dim,bt.dim);
    std::swap(treevector, bt.treevector);
}


//Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
    Clear();

    delete treevector;
    treevector = nullptr;
}

//Copy assignment
template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data> &bt){
    BinaryTreeVec<Data>* tmpbt = new BinaryTreeVec<Data>(bt);
    std::swap(*this,*tmpbt);
    delete tmpbt;

return *this;
}


//Move assignment
template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data> &&bt) noexcept{
    std::swap(dim, bt.dim);
    std::swap(treevector, bt.treevector);
    return *this;
}



//Comparision operators
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data> &bt) const noexcept{
    return BinaryTree<Data>::operator==(bt);

}

template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data> &bt) const noexcept{
    return!(*this == bt);
}



//Specific member functions
template<typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const {
    if(dim==0)
        throw std::length_error("Access to an empty binary tree.");

    return *(treevector->operator[](0));
}

template <typename Data>
void BinaryTreeVec<Data>::Clear() {
    if(dim > 0) {
        for(uint i = 0; i < dim; i++) {
            delete (*treevector)[i];
        }
        treevector->Clear();
        dim = 0;
    }
}

//MapBreadth
template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(const MapFunctor fun, void *par) {
    for(uint i = 0; i < dim; i++) {
        fun(treevector->operator[](i)->Element(), par);
    }
}

//FoldBreadth
template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(const FoldFunctor fun, const void *par, void *acc) const {
    for(uint i = 0; i < dim; i++) {
        fun(treevector->operator[](i)->Element(), par, acc);
    }
}
/* ************************************************************************** */

}
