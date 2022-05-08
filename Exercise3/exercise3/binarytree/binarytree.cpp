
#include <stdexcept>

namespace lasd {

/* ************************************************************************** */
/*                                  NODE                                      */
/* ************************************************************************** */


//Comparision operators
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node &compareNode) const noexcept{

    if (compareNode.Element() == this->Element()){
        bool thisRC = this->HasRightChild();
        bool thisLC = this->HasLeftChild();

        bool hisRC = compareNode.HasRightChild();
        bool hisLC = compareNode.HasLeftChild();

        bool right = (thisRC == hisLC);
        bool left = (thisLC == hisRC);

        if(left && right){
            if(thisLC && thisRC){
                return ((compareNode.LeftChild() == LeftChild()) && (compareNode.RightChild() == RightChild()));
            }
            else if(thisLC){
                return(compareNode.LeftChild() == LeftChild());
            }
            else if(thisRC){
                return(compareNode.RightChild()== RightChild()); 
            }else{
                return true;
            }

        }
    }
    return false;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node &compareNode) const noexcept{
    return !(*this == compareNode);

}


/* ************************************************************************** */
/*                              BINARY TREE                                   */
/* ************************************************************************** */


//Comparision operators
template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data> &compareBT) const noexcept{
    if(dim == compareBT.dim){
        if(dim != 0)
            return Root() == compareBT.Root();
        else
            return true;
    }else{
        return false;
    }
} 


template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data> &compareBT) const noexcept{
    return !(*this == compareBT);
}



/* ************************************************************************** */
/*                              SPECIFIC FUNCTION                             */
/* ************************************************************************** */



//Specific member function (inherited from MappableContainer,FoldableContainer)

//Map,Fold,MapPreOrder,FoldPreOrder,MapPostOrder,FoldPostOrder,MapInOrder,FoldInOrder,MapBreadth,FoldBreadth

template <typename Data>
void BinaryTree<Data>::Map(const MapFunctor fun, void* par){
    if(dim!=0)
        Map(fun,par,&(Root()));

}

template <typename Data>
void BinaryTree<Data>::Fold(const FoldFunctor fun, const void* par, void* acc) const{
    if(dim!=0)
        Fold(fun,par,acc,&(Root()));

}
 
/* ************************************************************************** */
// Specific member functions (inherited from PreOrderMappableContainer, PreOrderFoldableContainer)

template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* par){
    if (dim!=0)
        MapPreOrder(fun, par, &(Root()));
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const{
    if(dim!=0)
        FoldPreOrder(fun,par,acc,&(Root()));
}


/* ************************************************************************** */
//Specific member functions (inherited from PostOrderMappableContainer,PostOrderFoldableContainer)

template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* par){
    if(dim!=0)
        MapPostOrder(fun,par, &(Root()));

}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const{
    if(dim!=0)
        FoldPostOrder(fun, par, acc, &(Root()));
}


/* ************************************************************************** */
//Specific member functions (inherited from InOrderMappableContainer,InOrderFoldableContainer)

template <typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* par){
    if(dim!=0)
        MapInOrder(fun, par, &(Root()));
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* par, void* acc) const{
    if(dim!=0)
        FoldInOrder(fun, par, acc, &(Root()));
}
 /* ************************************************************************ */
// Specific member functions (inherited from BreadthMappableContainer, BreadthFoldableContainer)

template <typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* par){
    if(dim!=0)
        MapBreadth(fun, par, &(Root()));
}


template <typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* par, void* acc)const{
    if(dim!=0)
        FoldBreadth(fun, par, acc, &(Root()));
}

/* ************************************************************************** */
/*                            AUXILIARY FUNCTION                              */
/* ************************************************************************** */


//MapPreOrder,FoldPreOrder,MapPostOrder,FoldPostOrder,MapInOrder,FoldInOrder,MapBreadth,FoldBreadth

template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* par, Node* node){
    if(node!=nullptr){
        fun(node->Element(), par);


        if(node->HasLeftChild())
            MapPreOrder(fun, par, &(node->LeftChild()));


        if(node->HasRightChild())
            MapPreOrder(fun, par, &(node->RightChild()));

    }
}


template<typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc, Node* node)const{
    if(node != nullptr){
        fun(node->Element(), par, acc);

        if(node->HasLeftChild())
            FoldPreOrder(fun, par, acc, &(node->LeftChild()));

        if (node->HasRightChild())
            FoldPreOrder(fun, par, acc, &(node->RightChild()));
    }
}

 /* ************************************************************************ */

template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun,void* par, Node* node){
    if(node!=nullptr){
        if(node->HasLeftChild())
            MapPostOrder(fun, par, &(node->LeftChild()));

        
        if(node->HasRightChild())
            MapPostOrder(fun,par,&(node->RightChild()));

        
        fun(node->Element(),par);
    }
}



template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc, Node* node) const{
    if(node!=nullptr){
        
        if(node->HasLeftChild())
            FoldPostOrder(fun, par, acc, &(node->LeftChild()));

        if(node->HasRightChild())
            FoldPostOrder(fun, par, acc, &(node->RightChild()));

       
       fun(node->Element(), par, acc);

    }

 }

 /* ************************************************************************ */

template <typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* par, Node* node){
    if(node!= nullptr){
        if(node->HasLeftChild())
            MapInOrder(fun, par, &(node->LeftChild()));


            fun(node->Element(), par);


            if(node->HasRightChild())
                MapInOrder(fun, par, &(node->RightChild()));
        }
}


template <typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* par, void* acc, Node* node) const{
    if(node!= nullptr){
        if(node->HasLeftChild())
            FoldInOrder(fun, par, acc, &(node->LeftChild()));

        fun(node->Element(), par, acc);

        if(node->HasRightChild())
            FoldInOrder(fun, par, acc, &(node->RightChild()));
    }
}

 /* ************************************************************************ */

template <typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* par, Node* node){
    lasd::QueueLst<Node*> coda;
    coda.Enqueue(node);
    Node* tmp;


    while(!(coda.Empty())){
        tmp = coda.HeadNDequeue();
        fun(tmp->Element(), par);


        if(tmp->HasLeftChild())
            coda.Enqueue(&(tmp->LeftChild()));


        if(tmp->RightChild())
            coda.Enqueue(&(tmp->RightChild()));
    }
}



template <typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* par, void* acc, Node* node) const{
    lasd::QueueLst<const Node*> coda;
    coda.Enqueue(node);
    const Node* tmp;


    while(!(coda.Empty())){
        tmp = coda.HeadNDequeue();
        fun(tmp->Element(), par, acc);


        if(tmp->HasLeftChild())
            coda.Enqueue(&(tmp->LeftChild()));


        if(tmp->HasRightChild())
            coda.Enqueue(&(tmp->RightChild()));
    }
}
 /* ************************************************************************ */


/* ************************************************************************** */
/*                              Iterator PreOrder                             */
/* ************************************************************************** */


//Specific Constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> &bt){
    current = &bt.Root();
    refBTRoot = &bt.Root();
}


//Copy Constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data> &iter){
    current = iter.current;
    stk = iter.stk;
}


//Move Constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data> &&iter)  noexcept{
    std::swap(current, iter.current);
    stk = std::move(iter.stk);
}

//Destructor
template <typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator(){
    stk.Clear();
    delete current;
    current = nullptr;
}


//Copy assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data> &iter){
    BTPreOrderIterator<Data> *tmp = new BTPreOrderIterator<Data>(iter);
    std::swap(*tmp, *this);
    delete (tmp);
    return *this;
}


//Move assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data> &&iter) noexcept{
    std::swap(current, iter.current);
    stk = std::move(iter.stk);
    return *this;
}


//Comparision operators
template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data> &iter) const noexcept{
    if(current!=iter.current)
        return false;

    
    if(stk!=iter.stk)
        return false;

    return true;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data> &iter) const noexcept{
    return!(*this==iter);
}

 /* ************************************************************************ */

//Specific Member functions

template<typename Data>
Data& BTPreOrderIterator<Data>::operator*() const{
    if(Terminated())
        throw std::out_of_range("Terminated");

    return current->Element();
}


template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
    return (current == nullptr);
}

 /* ************************************************************************ */

template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>:: operator++() {

    if(Terminated())
        throw std::out_of_range("Iterator PreOrder terminated.");

    if(current->HasRightChild())
        stk.Push(&(current->RightChild()));

    if(current->HasLeftChild())
        stk.Push(&(current->LeftChild()));

    if(stk.Empty())
        current = nullptr; 

    else
        current = stk.TopNPop();

    return (*this);
    
}
 /* ************************************************************************ */

template <typename Data>
void BTPreOrderIterator<Data>::Reset() const noexcept {
    stk.Clear();
    current = nullptr;
    current = refBTRoot;
}









/* ************************************************************************** */
/*                              Iterator PostOrder                             */
/* ************************************************************************** */


//Function GetMostLeftLeaf
template <typename Data>
void BTPostOrderIterator<Data>::getMostLeftLeaf() {
    while (current->HasLeftChild()) {
        stk.Push(current);
        current = &(current->LeftChild());
    }

    if(current->HasRightChild()) {
        stk.Push(current);
        current = &(current->RightChild());
        getMostLeftLeaf();
    }
}
// Specific constructors
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> &bt) {
    current = &bt.Root();
    getMostLeftLeaf();
    last = current;
    refBTRoot = &bt.Root();
}

// Copy constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data> &iter) {
    current = iter.current;
    last = iter.last;
    stk = iter.stk;
}

// Move constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data> &&iter) noexcept {
    std::swap(current,iter.current);
    std::swap(last,iter.last);
    stk = std::move(iter.stk);
}

// Destructor
template <typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator() {
    stk.Clear();
    delete current;
    delete last;
    current = nullptr;
    last = nullptr;
}

// Copy assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data> &iter) {
    BTPostOrderIterator<Data> *tmp = new BTPostOrderIterator<Data>(iter);
    std::swap(*tmp, *this);
    delete (tmp);
    return *this;
}

// Move assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data> &&iter) noexcept {
    std::swap(current, iter.current);
    std::swap(last,iter.last);
    stk = std::move(iter.stk);
    return *this;
}


// Comparison operators
template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data> &iter) const noexcept {
    if(current!=iter.current)
        return false;

    if(last!=iter.last)
        return false;
    
    if(stk!=iter.stk)
        return false;
    
    return true;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data> &iter) const noexcept {
    return !(*this==iter);
}


/* ************************************************************************** */

template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const {
    if(Terminated())
        throw std::out_of_range("Terminated");

    return current->Element();
}



template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}


/* ************************************************************************** */
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if(Terminated())
        throw std::out_of_range("Iterator PostOrder terminated.");

    if(stk.Empty()){
        current = nullptr;
        last = nullptr;
    }else{
        current = stk.TopNPop();
        if(current->HasRightChild() && !(&(current->RightChild())==last)){
            stk.Push(current);
            current = &(current->RightChild());
            getMostLeftLeaf();
        }
    }
    last = current;
    return (*this);
}



template <typename Data>
void BTPostOrderIterator<Data>::Reset() const noexcept {
    stk.Clear();
    current=nullptr;
    last=nullptr;
    getMostLeftLeaf();
    last = current;
    current = refBTRoot;

}


/* ************************************************************************** */




/* ************************************************************************** */
/*                              Iterator  InOrder                             */
/* ************************************************************************** */


//Function GetMostLeftNode
template <typename Data>
void BTInOrderIterator<Data>::getMostLeftNode(){
    while (current->HasLeftChild()){
        stk.Push(current);
        current = &(current->LeftChild());
    }
}

//Specific Constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>  &bt){
    current = &bt.Root();
    getMostLeftNode();
    refBTRoot = &bt.Root();
}

//Copy Constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data> &iter){
    current = iter.current;
    stk = iter.stk;
}

//Move Constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data> &&iter) noexcept{
    std::swap(current, iter.current);
    stk = std::move(iter.stk);
}

//Destructor
template <typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator(){
    stk.Clear();
    delete current;
    current = nullptr;
}

//Copy assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data> &iter){
    BTInOrderIterator<Data> *tmp = new BTInOrderIterator<Data>(iter);
    std::swap(*tmp, *this);
    delete (tmp);
    return *this;
}

//Move assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data> &&iter) noexcept{
    std::swap(current, iter.current);
    stk = std::move(iter.stk);
    return *this;
}


//Comparision operators
template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data> &iter) const noexcept {
    if(current!=iter.current)
        return false;
    
    if(stk!=iter.stk)
        return false;
    
    return true;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data> &iter) const noexcept {
    return !(*this==iter);
}


//Specif member function

template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const {
    if(Terminated())
        throw std::out_of_range("Terminated");

    return current->Element();
}


template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if(Terminated())
        throw std::out_of_range("Iterator InOrder terminated.");
        
    if(current->HasRightChild()){
        current = &(current->RightChild());
        getMostLeftNode();
    }else{
        if(stk.Empty())
            current = nullptr;
        else
            current = stk.TopNPop(); 
    }
    return (*this);
}



template <typename Data>
void BTInOrderIterator<Data>::Reset() const noexcept {
    stk.Clear();
    current=nullptr;
    current = refBTRoot;
    getMostLeftNode();
}

/* ************************************************************************** */


/* ************************************************************************** */
/*                              Iterator Breadth                              */
/* ************************************************************************** */

// Specific constructors
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> &bt) {
    current = &bt.Root();
}


// Copy constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data> &iter) {
    current = iter.current;
    que = iter.que;
}

// Move constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data> &&iter) noexcept {
    std::swap(current,iter.current);
    que = std::move(iter.que);
}


// Destructor
template <typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator() {
    que.Clear();
    delete current;
    current = nullptr;
}


// Copy assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data> &iter) {
    BTBreadthIterator<Data> *tmp = new BTBreadthIterator<Data>(iter);
    std::swap(*tmp, *this);
    delete (tmp);
    return *this;
}

// Move assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data> &&iter) noexcept {
    std::swap(current, iter.current);
    que = std::move(iter.que);
    return *this;
}



// Comparison operators
template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data> &iter) const noexcept {
    if(current!=iter.current)
        return false;
    
    if(que!=iter.que)
        return false;
    
    return true;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data> &iter) const noexcept {
    return !(*this==iter);
}


// Specific member functions (inherited from Iterator)
template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const {
    if(Terminated())
        throw std::out_of_range("Terminated");

    return current->Element();
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    
    if(Terminated())
        throw std::out_of_range("Iterator Ampiezza terminated.");
    
    if(current->HasLeftChild())
        que.Enqueue(&(current->LeftChild()));
    
    if(current->HasRightChild())
        que.Enqueue(&(current->RightChild()));
    
    if(que.Empty())
        current = nullptr;
    else
        current = que.HeadNDequeue();

    return (*this);

}


//RESET



// template<typename Data>
// void BTBreadthIterator<Data>& BTBreadthIterator<Data>::Reset() const noexcept{
//     stk.Clear();
//     current = nullptr;
//     current = refBTRoot;
// }



/* ************************************************************************** */

}
