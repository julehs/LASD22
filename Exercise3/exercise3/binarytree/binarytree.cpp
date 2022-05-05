
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



/* ************************************************************************** */

}
