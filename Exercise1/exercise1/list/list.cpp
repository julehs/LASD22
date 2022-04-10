
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
template <typename Data>
List<Data>& List<Data>::operator=(const List<Data>& cpylist){
    List<Data>*tmplist = new List<Data>(cpylist);
    std::swap(*tmplist, *this);
    delete tmplist;
    return *this;
}


//Move assignment
template<typename Data>
List<Data>& List<Data>::operator=(List<Data>&& mvlist) noexcept{
  std::swap(First, mvlist.First);
  std::swap(Last, mvlist.Last);
  std::swap(dim, mvlist.dim);
  return *this;
}


//Comparision operator
template<typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept{

  if(dim == list.dim){
    struct Node* current = First;
    struct Node* Tmp = list.First;
    for(unsigned long i = 0; i < dim; i++){
      if(current->elemento != Tmp->elemento){
        return false;
      }
      current = current->next;
      Tmp = Tmp->next;
    }
    return true;
  }
  else{
    return false;
  }

}  


template<typename Data>
bool List<Data>::operator!=(const List<Data>& list) const noexcept{
  return !(*this == list);
}


//InsertAtFront
template<typename Data>
void List<Data>::InsertAtFront(const Data& ival)noexcept {

    struct Node* newNode;
    newNode = new Node (ival);
    newNode->next = First;
    //Last = First
    First = newNode;
    dim++;
    if(Last == nullptr)
        Last = newNode;
}

//InsertAtFront (move)
template<typename Data>
void List<Data>::InsertAtFront(Data&& ival) noexcept{
    struct Node* newNode;
    newNode = new Node(std::move(ival));
    newNode-> next = First;
    First = newNode;
    dim++;
    if (Last == nullptr) {
        Last = newNode;
    }
    
}

//RemoveFromFront

template <typename Data>
void List<Data>::RemoveFromFront(){
    struct Node* current;
    if(First == nullptr)
        throw std::length_error("Lista vuota.");
    else if (First == Last){
        dim--
        First = nullptr;
        Last = nullptr;
    }
    else{
        current = First;
        First = First->next;
        dim--;
    }
}

//FrontNRemove
template<typename Data>
Data& List<Data>::FrontNRemove(){
    struct Node* current;
    if(First == nullptr)
        throw std::length_error("Lista vuota.");
    else if (First == Last){
        dim--;
        current = First;
        First = nullptr;
        Last = nullptr;
        return current -> elemento;
    } 
}

//InsertAtBack 
template<typename Data>
void List<Data>::InsertAtBack(const Data& ival) {
    struct Node* newNode;
    newNode = new Node(ival);
    if (!First) {
        First = newNode;
        Last = newNode;
        dim++;
}
else {
    struct Node* tmp = First;
    while(tmp->next) tmp = tmp->next;
    tmp->next = newNode;
    dim++;
    Last = tmp->next;
    }

}

template<typename Data>
void List<Data>::InsertAtBack(Data&& ival) noexcept{
    struct Node* newNode;
    newNode = new Node(std::move(ival));
    if(!First){
        First = newNode;
        Last  = newNode;
        dim++;
    }  
    else{
        strunct Node* tmp = First;
        while (tmp->next) tmp = tmp->next;
        tmp->next = newNode;
        dim ++;
        Last = tmp->next;
    }

}

//Clear function
template<typename Data>
void List<Data>::Clear() noexcept{
    struct Node* tmp;
    while(First != nullptr){
        tmp = First;
        First = First->next;
    }
    Last = nullptr;
    dim = 0;
    First = nullptr; 
}

//Front function

template <typename Data>
Data& List<Data>::Front() const{
    if (First != nullptr){
        return First->elemento;
    }
    else{
        throw std::length_error("Lista vuota.");
    }
}

//Back function
template <typename Data>
Data& List<Data>::Back() const{
    if(dim != 0){
        return Last->elemento;
    }
    else{
        throw std::length_error("Lista vuota.");
    }
}

//Operator[] function

template <typename Data>
Data& List<Data>::operator[](const unsigned long index) const{
    if(index < dim){
        struct Node* current;
        current = First;
        for(unsigned long i = 0; i < index; i++){
            current = current->next;
        }
        return current -> elemento;
    }
    else{
        throw std::out_of_range("Accesso all'indice:  " +std::to_string(index) + "e di lunghezza:  " +std::to_string(dim));
    }
    
}

//Map function
template<typename Data>
void List<Data>::Map(MapFunctor fun, void* par){}

//MapPreOrder function
template<typename Data>
void List<Data>::MapPreOrder(MapFunctor fun, void* par){
    MapPreOrder(fun, par, First);
}

//MapPostOrder function
template<typename Data>
void List<Data>::MapPostOrder(MapFunctor fun, void* par){
    MapPostOrder(fun, par, First);
}

//Fold function
template<typename Data>
void List<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const{}
//FoldPreOrder function
template<typename Data>
void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const{
    FoldPreOrder(fun, par, acc, First);
}

//FoldPostOrder function
template<typename Data>
void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const{
    FoldPostOrder(fun, par, acc, First);
}


//Auxiliary member function: MapPreOrder e MapPostOrder
template<typename Data>
void List<Data>::MapPreOrder(MapFunctor fun, void* par, Node* curr){
    for (; curr!= nullptr; curr = curr ->next ){
        fun(curr->elemento, par);
    }
}

template<typename Data>
void List<Data>::MapPostOrder(MapFunctor fun, void* par, Node* curr){
    if(curr!= nullptr){
        MapPostOrder(fun, par, curr->next);
        fun(curr->elemento, par);
    }
}

//Auxiliary member function: FoldPreOrder e FoldPostOrder


/* ************************************************************************** */

}
