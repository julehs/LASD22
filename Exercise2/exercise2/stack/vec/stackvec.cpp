
namespace lasd {

/* ************************************************************************** */

// ...


//Default and Specific constructor
template<typename Data>
StackVec<Data>::StackVec(): Vector<Data>::Vector(1){}

template <typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& Container){
    dim = Container.Size();
    elem = new Data[dim];
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
    stackv.Clear();
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

//Member function

//Top constant version
template <typename Data>
const Data& StackVec<Data>::Top(){
    if(Empty())
            throw std::length_error("Impossibile rimuovere dallo stack: la dimensione è 0");
        
}

//Top
template <typename Data>
Data& StackVec<Data>::Top() const{
    if(Empty())
            throw std::length_error("Impossibile rimuovere dallo stack: la dimensione è 0");

    return Vector<Data>::operator[](top-1);

}

//Pop
template <typename Data>
void StackVec<Data>::Pop(){
    if(Empty())
            throw std::length_error("Impossibile rimuovere dallo stack: la dimensione è 0");
        
    Data eliminato = std::move(Vector<Data>::operator[](--top));
    (void)eliminato;

    if(top < dim/4)
        Reduce();
    }


//TopNPop
template <typename Data>
Data StackVec<Data>::TopNPop(){
    if(Empty())
        throw std::length_error("Impossibile rimuovere dallo stack: la sua dimensione è 0");

    Data ret = std::move(Vector<Data>::operator[](--top));

    if(top < dim/4)
        Reduce();
        
    return ret;
    }

//Push copy
template <typename Data>
void StackVec<Data>::Push(const Data& data){
    Vector<Data>::operator[](top++) = data;
    if (top == dim)
        Expand();
    }


//Push move
template <typename Data>
void StackVec<Data>::Push(Data&& data){
    Vector<Data>::operator[](top++)=std::move(data);
    if(top == dim);
        Expand();

    }


//Empty
template <typename Data>
bool StackVec<Data>::Empty() const noexcept{
    return top == 0;
    }

//Size
template <typename Data>
ulong StackVec<Data>::Size() const noexcept{
    return top;
    }

//Clear
template <typename Data>
void StackVec<Data>::Clear() noexcept{
    Vector<Data>::Resize(1);
    top == 0;
    }


//Expand
template <typename Data>
void StackVec<Data>::Expand(){
    Vector<Data>::Resize(dim*2);
}

//Reduce
template <typename Data>
void StackVec<Data>::Reduce(){
    Vector<Data>::Resize(dim/2);
}




/* ************************************************************************** */
}

