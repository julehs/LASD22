#include <stdexcept>

namespace lasd {

/* ************************************************************************** */

//NodeLink

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data &dato){
    elem = dato;
    leftchild = nullptr;
    rightchild = nullptr;
}

//Destructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
    delete leftchild;
    delete rightchild;
}

//Specific member functions
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
    return elem;
}

template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
    return elem;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return (leftchild!=nullptr);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return (rightchild!=nullptr);
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if(leftchild==nullptr)
        throw std::out_of_range("Access to an empty child.");

    return *leftchild;
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if(rightchild==nullptr)
        throw std::out_of_range("Access to an empty child.");

    return *rightchild;
}

//TreeLink
template <typename Data>
void BinaryTreeLnk<Data>::funBuild(int indice, struct BinaryTreeLnk<Data>::NodeLnk *nodo, const LinearContainer<Data> &con) {
     if( (indice*2 + 1) <= (con.Size()-1)){
        nodo->leftchild = new NodeLnk(con[indice*2 + 1]);
        funBuild(indice*2 + 1, nodo->leftchild,con);
    }

     if( (indice*2 + 2) <= (con.Size()-1)){
        nodo->rightchild = new NodeLnk(con[indice*2 + 2]);
        funBuild(indice*2 + 2, nodo->rightchild, con);
    }
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::copyTree(NodeLnk *toBeCopied) {
    NodeLnk* nodo = nullptr;

    if(toBeCopied!=nullptr){
        nodo = new NodeLnk(toBeCopied->element);

        if(toBeCopied->leftchild!=nullptr)
            nodo->leftchild = copyTree(toBeCopied->leftchild);

        if(toBeCopied->rightchild!=nullptr)
            nodo->rightchild = copyTree(toBeCopied->rightchild);
    }

    return nodo;
}


//Specific constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data> &con) {
    dim = con.Size();
    root = new BinaryTreeLnk<Data>::NodeLnk(con[0]);
    funBuild(0, root, con);
}

//Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data> &bt) {
    dim=bt.dim;

    if(dim>0)
        root = copyTree(bt.root);
}

//Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data> &&bt) noexcept : BinaryTreeLnk<Data>()  {
    std::swap(root,bt.root);
    std::swap(dim,bt.dim);
}


//Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}


//Copy assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> &bt) {
    if(bt.dim!=0){
        BinaryTreeLnk<Data>* tmp_bt = new BinaryTreeLnk<Data>(bt);
	    std::swap(*tmp_bt, *this);
	    delete tmp_bt;
    }else{
        Clear();
    }
    return *this;
}


//Move assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data> &&bt) noexcept {
    std::swap(root,bt.root);
    std::swap(dim,bt.dim);
    return *this;
}


//Comparision operators
template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data> &bt) const noexcept {
    return BinaryTree<Data>::operator==(bt);
}


template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data> &bt) const noexcept {
    return !(*this == bt);
}


//Specific member functions
template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const {
    if(root==nullptr)
        throw std::length_error("Access to an empty tree.");

    return *root;
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    dim=0;
    delete root;
    root = nullptr;
}
/* ************************************************************************** */

}
