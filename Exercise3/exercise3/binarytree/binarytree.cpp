
// #include "..."

namespace lasd {

/* ************************************************************************** */


//Node


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

/* ************************************************************************** */

}
