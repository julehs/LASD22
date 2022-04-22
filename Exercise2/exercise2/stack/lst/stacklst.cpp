
namespace lasd {

/* ************************************************************************** */

//Dafault constructor
// template <typename Data>
// StackLst<Data>::StackLst(): List<Data>::List(){}


//Specific constructor
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& Container):List<Data>::List::(Container){

}

//Copy constructor 
template <typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& StackLst): List<Data>::List(StackList){}


//Move constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& StackList) noexcept: List<Data>::List(std::move(StackList)){}

//Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& listcpy){
    List<Data>::operator =(listcpy);
    return *this;
}

//Move assignment 
template <typename Data>
StackLst<Data>& StackLst<Data>::operator = (StackLst&& listmove) noexcept {
    List<Data>::operator = (std::move(listmove));
    return *this;

}

/* ************************************************************************** */

}
