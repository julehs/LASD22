
namespace lasd {

/* ************************************************************************** */

// ...


//Default and Specific constructor
template<typename Data>
StackVec<Data>::StackVec(): Vector<Data>::Vector(){}

template <typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& Container){
    dimensione = Container.Size();
    elemento = new Data[dimensione];
    for (ulong i=0; i<Container.Size(); ++i){
        Push(Container[i]);
    }
}

//Copy constructor
template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stackv): Vector<Data>::Vector(stackv){
    top = stackv.top;

}


//Move constructor
template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stackv) : Vector<Data>::Vector(std::move(stackv)){
    top = stackv.top;
    stackvec.Clear();
} 


//Copy assignment
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stackv){
    Vector<Data>::operator=(stackv);
    top = stackv.top;
    return *this;

}

//Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stackv) noexcept{
    Vector<Data>::operator=(std::move(stackv));
    std::swap(top, stackv.top);
    return *this;
    
}

//Comparision operators

template <typename Data>
bool StackVec<Data>::operator==(const StackVec& sv) const noexcept{
    if(this ==&sv)
    return true;

    if (top!=sv.top)
    return false;

    ulong index = 0;
    while(index < top && Vector<Data>::operator[](index) == sv.Vector<Data>::operator[](index))
    index++;

    return index == top;

}


template <typename Data>
bool StackVec<Data>::operator!=(const StackVec& sv) const noexcept{
    return!(*this == sv);
}



/* ************************************************************************** */

}
