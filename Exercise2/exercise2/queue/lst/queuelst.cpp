
namespace lasd {

/* ************************************************************************** */

//Default constructor
template <typename Data>
QueueLst<Data>::QueueLst():List<Data>(){}


//Specific constructor
template <typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data>& con): List<Data>::List(con){}

//Copy constructor
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst& q): List<Data>(q){}

//Move constructor
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst&& q) noexcept: List<Data>(std::move(q)){}

//Copy assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator = (const QueueLst& q){
    List<Data>::operator=(q);
    return *this; 
}

//Move assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator = (QueueLst&& q) noexcept {
    List<Data>::operator=(std::move(q));
    return *this;

 }

//Comparison operators
template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst& q) const noexcept{
    return List<Data>::operator==(q);

}

template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& q) const noexcept{
    return List<Data>::operator!=(q);

}


//Specific member
//Head constant version
template <typename Data>
const Data& QueueLst<Data>::Head(){
     if(Empty())
	    throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

        return List<Data>::Front();
}

//Head
template <typename Data>
Data& QueueLst<Data>::Head() const{
     if(Empty())
	    throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

        return List<Data>::Front();
}

//Dequeue
template <typename Data>
void QueueLst<Data>::Dequeue(){
     if(Empty())
	    throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

        return List<Data>::RemoveFromFront();
} 


//HeadNDequeue
template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
     if(Empty())
	    throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

        return List<Data>::FrontNRemove();
}



//Enqueue copy
template <typename Data>
void QueueLst<Data>::Enqueue(const Data& d){
    List<Data>::InsertAtBack(d);

} 


//Enqueue move
template <typename Data>
void QueueLst<Data>::Enqueue(Data&& d){
    List<Data>::InsertAtBack(std::move(d));
}

/* ************************************************************************** */

}
