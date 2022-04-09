
namespace lasd {
/* ************************************************************************** */
/*                              NODE                                          */                     
/* ************************************************************************** */
//Specific constructor
template<typename Data>
List<Data>::Node::Node(const Data& valore){
    elemento = valore;
    next = nullptr;
}



template<typename Data>
List<Data>::Node::Node(Data&& valore){
    std::swap(elemento, valore);
    next = nullptr;

}

//Copy Constructor
template<typename Data>
List<Data>::Node::Node(const Data& nodo){
    this->elemento = nodo.elemento;
    this->next = nodo.next;
}

//Move Constructor
template<typename Data>
List<Data>::Node::Node(Node&& nodo) noexcept{
    std::swap(elemento, nodo.elemento);
    std::swap(next, nodo.next);
}


//Comparison Constructor
template<typename Data>
bool List<Data>::Node::operator==(const Node& nodo) const noexcept{
    if (elemento != nodo.elemento){
        return false;
    }
    return true;
}

template<typename Data>
bool List<Data>::Node::operator!=(const Node& nodo) const noexcept{
    return !(*this == nodo);
}


/* ************************************************************************** */
/*                              LIST                                          */
/* ************************************************************************** */

//Default Constructor
template<typename Data>
List<Data>::List(){
    First = nullptr;
    Last = nullptr;

}


//Specific Constructor
template<typename Data>
List<Data>::List(const LinearContainer<Data>& con){

    if(con.Size()==0){
        First = nullptr;
        Last = nullptr;
    }
    else{
        First = nullptr;
        Last = nullptr;

        for (unsigned long i = 0; i < con.Size(); ++i) {
            InsertAtBack(con[i]);
        }
        
    }
}

//Copy Constructor
template <typename Data>
List<Data>::List(const List<Data>& otherList){
    if(this != &otherList){

        if (otherList.First == nullptr){
            First = nullptr;
            Last = nullptr;
            dim = 0;
        }
        else{
            struct Node* current;
            current = otherList.First;
            struct Node* node = new Node(current->elemento);
            First = node;
            Last = First;

            current = current->next;
            while (current != nullptr) {
                struct Node* newnode = new Node(current->elemento);
                Last->next = newnode;
                Last = newnode;
                current = current->next;
            }
            dim = otherList.dim;
        }
        
    }
}

//Move Constructor
template<typename Data>
List<Data>::List(List<Data>&& otherList) noexcept{
    dim = otherList.dim;
    otherList.dim = 0;
    First = otherList.First;
    otherList.First = nullptr;
}

//Destructor
template<typename Data>
List<Data>::~List(){
    Node* current = First:
    while(current != nullptr){
        Node* to_delete = current;
        current = current -> next;
        delete to_delete;

    }
}

//Copy assignment 


/* ************************************************************************** */

}
