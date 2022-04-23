
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


 


/* ************************************************************************** */

}
