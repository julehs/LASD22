
// #include "..."

namespace lasd {

/* ************************************************************************** */


//NODE


//Comparision operators
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node &compareNode) const noexcept{

    if (compareNode.Element()== this->Element()){
        bool thisRC = this->HasRightChild();
        bool thisLC = this->HasLeftChild();

        bool hisRC = compareNode.HasRightChild();
        bool hisLF = compareNode.HasLeftChild();

        bool right = (thisRC == thisLC);
        bool left = (thisLC == thisRC);

        if(left && right){
            if(thisLC && thisRC){
                return ((compareNode.LeftChild()== LeftChild()) && (compareNode.RightChild()==RightChild()));
            }
            else if(thisLC){
                return(compareNode.LeftChild()== LeftChild());
            }
            else if(thisRC){
                return(compareNode.RightChild()==RightChild()); 
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

//BINARY TREE

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


//SPECIFIC FUNCTION

//Specific member function
//Map,Fold,MapPreOrder,FoldPreOrder,MapPostOrder,FoldPostOrder,MapInOrder,FoldInOrder,MapBreadth,FoldBreadth

template <typename Data>
void BinaryTree<Data>::Map(MapFunctor fun, void* par){
    if(dim!=0)
        Map(fun,par,&(Root()));

}

template <typename Data>
void BinaryTree<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const{
    if(dim!=0)
        Fold(fun,par,acc,&(Root()));

}


template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor fun, void* par){
    if (dim!=0)
        MapPreOrder(fun, par, &(Root()));
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const{
    if(dim!=0)
        FoldPreOrder(fun,par,acc,&(Root()));
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor fun, void* par){
    if(dim!=0)
        MapPostOrder(fun,par, &(Root()));
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const{
    if(dim!=0)
        FoldPostOrder(fun, par, acc, &(Root()));
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor fun, void* par){
    if(size!=0)
        MapInOrder(fun, par, &(Root()));
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor fun, const void* par, void* acc) const{
    if(dim!=0)
        FoldInOrder(fun, par, acc, &(Root()));
}


template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor fun, void* par){
    if(dim!=0)
        MapBreadth(fun, par, &(Root()));
}


template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor fun, const void* par, void* acc)const{
    if(dim!=0)
        FoldBreadth(fun, par, acc, &(Root()));
}

//AUXILIARY FUNCTIONS

//MapPreOrder,FoldPreOrder,MapPostOrder,FoldPostOrder,MapInOrder,FoldInOrder,MapBreadth,FoldBreadth

template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor fun, void* par, Node* node){
    if(node!=nullptr){
        fun(node->Element(), par);


        if(node->HasLeftChild())
            MapPreOrder(fun, par, &(node->LeftChild()));


        if(node->HasRightChild())
            MapPreOrder(fun, par, &(node->RightChild()));

    }
}


template<typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void*)const{
    if(node!=nullptr){
        fun(node->Element(),par,acc);

        if(node->HasLeftChild())
            FoldPreOrder(fun, par, acc, &(node->LeftChild()));

        if (node->HasRightChild())
            FoldPreOrder(fun, par, acc, &(node->RightChild()));
    }
}
/* ************************************************************************** */

}
