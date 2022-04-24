
namespace lasd {

/* ************************************************************************** */

//Dafault constructor
template <typename Data>
StackLst<Data>::StackLst(): List<Data>::List(){}


//Specific constructor
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& Container):List<Data>::List(Container){}

//Copy constructor 
template <typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& StackLst): List<Data>::List(StackLst){}


//Move constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& StackLst) noexcept: List<Data>::List(std::move(StackLst)){}

//Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator = (const StackLst& listcpy){
    List<Data>::operator =(listcpy);
    return *this;
}

//Move assignment 
template <typename Data>
StackLst<Data>& StackLst<Data>::operator = (StackLst&& listmove) noexcept {
    List<Data>::operator = (std::move(listmove));
    return *this;

}

template <typename Data>
bool StackLst<Data>::operator==(const StackLst& listcomp) const noexcept{
    return List<Data>::operator==(listcomp);
}

template <typename Data>
bool StackLst<Data>::operator!=(const StackLst& listcomp) const noexcept{
    return List<Data>::operator!=(listcomp);
}


//Top constant version
template <typename Data>
const Data& StackLst<Data>::Top(){
    if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");


}

//Top 
template<typename Data>
Data& StackLst<Data>::Top() const{
    if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");

  return List<Data>::Front();
}

//Pop
template <typename Data>
void StackLst<Data>::Pop(){
    if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");

  List<Data>::RemoveFromFront();
}

//TopNPop
template <typename Data>
Data StackLst<Data>::TopNPop(){
    if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");

  return List<Data>::FrontNRemove();
}

//Push copy
template <typename Data>
void StackLst<Data>::Push(const Data& d){
    List<Data>::InsertAtFront(d);
}

//Push move
template <typename Data>
void StackLst<Data>::Push(Data&& d){
    List<Data>::InsertAtFront(std::move(d));
}

/* ************************************************************************** */

}
