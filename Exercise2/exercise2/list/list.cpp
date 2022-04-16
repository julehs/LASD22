
namespace lasd {

/* ************************************************************************** */
/*                              NODE                                          */                     
/* ************************************************************************** */
//Specific constructor
template<typename Data>
List<Data>::Node::Node(const Data& valore){
    elemento = valore;
    this->next = nullptr;
}

template<typename Data>
List<Data>::Node::Node(Data&& valore) noexcept {
    std::swap(elemento, valore);
    this->next = nullptr;
}


//Copy Constructor
template<typename Data>
typename List<Data>::Node& List<Data>::Node::operator=(const typename List<Data>::Node& nodo){
    this->elemento = nodo.elemento;
    this->next = nodo.next;
}

//Move Constructor
template<typename Data>
typename List<Data>::Node& List<Data>::Node::operator=(typename List<Data>::Node&& nodo) noexcept{
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
/* template<typename Data> */
/* List<Data>::List(){ */
/*     /* this->First = nullptr; */
/*     /* this->Last = nullptr; */ 
/* } */
/*  */

//Specific Constructor
template<typename Data>
List<Data>::List(const LinearContainer<Data>& con){

    if(con.Size()==0){
        this->First = nullptr;
        this->Last = nullptr;
    }
    else{
        this->First = nullptr;
        this->Last = nullptr;

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
            this->First = nullptr;
            this->Last = nullptr;
            dim = 0;
        }
        else{
            struct Node* current;
            current = otherList.First;
            struct Node* node = new Node(current->elemento);
            this->First = node;
            this->Last = this->First;

            current = current->next;
            while (current != nullptr) {
                struct Node* newnode = new Node(current->elemento);
                this->Last->next = newnode;
                this->Last = newnode;
                current = current->next;
            }
            this->dim = otherList.dim;
        }
        
    }
}

//Move Constructor
template<typename Data>
List<Data>::List(List<Data>&& otherList) noexcept{
    dim = otherList.dim;
    otherList.dim = 0;
    this->First = otherList.First;
    otherList.First = nullptr;
}

//Destructor
template<typename Data>
List<Data>::~List(){
    Node* current = this->First;
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
  std::swap(this->First, mvlist.First);
  std::swap(this->Last, mvlist.Last);
  std::swap(dim, mvlist.dim);
  return *this;
}


//Comparision operator
template<typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept{

  if(dim == list.dim){
    struct Node* current = this->First;
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
    newNode->next = this->First;
    //Last = First
    this->First = newNode;
    dim++;
    if(this->Last == nullptr)
        this->Last = newNode;
}

//InsertAtFront (move)
template<typename Data>
void List<Data>::InsertAtFront(Data&& ival) noexcept{
    struct Node* newNode;
    newNode = new Node(std::move(ival));
    newNode-> next = this->First;
    this->First = newNode;
    dim++;
    if (this->Last == nullptr) {
        this->Last = newNode;
    }
    
}

//RemoveFromFront

template <typename Data>
void List<Data>::RemoveFromFront(){
    struct Node* current;
    if(this->First == nullptr)
        throw std::length_error("Lista vuota.");
    else if (this->First == this->Last){
        dim--;
        this->First = nullptr;
        this->Last = nullptr;
    }
    else{
        current = this->First;
        this->First = this->First->next;
        dim--;
    }
}

//FrontNRemove
template<typename Data>
Data List<Data>::FrontNRemove(){
    Data current;
    if(First == nullptr)
        throw std::length_error("Lista vuota.");
    else if (this->First == this->Last){
        dim--;
        current = this->First->elemento;
				delete this->First;
        this->First = nullptr;
        this->Last = nullptr;
        return current;
    } else {
				dim--;
        current = this->First->elemento;
				struct Node* toDel;
				this->First = this->First->next;
				delete toDel;
				return current;
		}
}

//InsertAtBack 
template<typename Data>
void List<Data>::InsertAtBack(const Data& ival) {
    struct Node* newNode;
    newNode = new Node(ival);
    if (!this->First) {
        this->First = newNode;
        this->Last = newNode;
        dim++;
}
else {
    struct Node* tmp = First;
    while(tmp->next) tmp = tmp->next;
    tmp->next = newNode;
    dim++;
    this->Last = tmp->next;
    }

}

template<typename Data>
void List<Data>::InsertAtBack(Data&& ival) noexcept{
    struct Node* newNode;
    newNode = new Node(std::move(ival));
    if(!this->First){
        this->First = newNode;
        this->Last  = newNode;
        dim++;
    }  
    else{
        struct Node* tmp = First;
        while (tmp->next) tmp = tmp->next;
        tmp->next = newNode;
        dim ++;
        this->Last = tmp->next;
    }

}

//Clear function
template<typename Data>
void List<Data>::Clear() noexcept{
    struct Node* tmp;
    while(First != nullptr){
        tmp = this->First;
        this->First = this->First->next;
    }
    this->Last = nullptr;
    dim = 0;
    this->First = nullptr; 
}

//Front function

template <typename Data>
Data& List<Data>::Front() const{
    if (this->First != nullptr){
        return this->First->elemento;
    }
    else{
        throw std::length_error("Lista vuota.");
    }
}

//Back function
template <typename Data>
Data& List<Data>::Back() const{
    if(this->dim != 0){
        return this->Last->elemento;
    }
    else{
        throw std::length_error("Lista vuota.");
    }
}

//Operator[] function

template <typename Data>
Data& List<Data>::operator[](const unsigned long index) const{
    if(index < this->dim){
        struct Node* current;
        current = First;
        for(unsigned long i = 0; i < index; i++){
            current = current->next;
        }
        return current -> elemento;
    }
    else{
        throw std::out_of_range("Accesso all'indice:  " +std::to_string(index) + "e di lunghezza:  " +std::to_string(this->dim));
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
template<typename Data>
void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc, Node* curr) const{
    for(; curr!= nullptr; curr = curr->next){
        fun(curr->elemento, par, acc);
    }
}

template<typename Data>
void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc, Node* curr)const{
    unsigned long index = this->dim;
    while (index > 0){
        fun((*this)[index-1], par, acc);
        index--;
    }
}

/* ************************************************************************** */

}
