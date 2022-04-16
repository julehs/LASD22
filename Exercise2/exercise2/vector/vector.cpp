
namespace lasd {

/* ************************************************************************** */

//Constructor
template <typename Data>
Vector<Data>::Vector(const unsigned long newdim){
    elem = new Data[newdim] {};
    dim = newdim;

}


template <typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& lcon){
    dim = lcon.Size();
    elem = new Data[dim];

    for (ulong i = 0; i < dim; i++)
    {
        elem[i] = lcon[i];
    }
    
}


/* ************************************************************************** */

//Copy Constructor
template<typename Data>
Vector<Data>::Vector(const Vector<Data>& vec){
    elem = new Data[vec.dim];
    std::copy(vec.elem, vec.elem + vec.dim, elem);
    dim = vec.dim;
}

//Move Constructor
template<typename Data>
Vector<Data>::Vector (Vector<Data>&& vec) noexcept{
    std::swap(elem, vec.elem);
    std::swap(dim, vec.dim);

}

//Destructor
template<typename Data>
Vector<Data>::~Vector() noexcept {
    delete[] elem;
}

//Copy assignment
template<typename Data>
Vector<Data>& Vector<Data>::operator = (const Vector<Data>& vec) {
    Vector<Data>* newvec = new Vector<Data>(vec);
    std::swap(*newvec, *this);
    delete newvec;
    return this;
}

//Move assignment
template<typename Data>
Vector<Data>& Vector<Data>::operator= (Vector <Data>&& vec) noexcept {
    std::swap(elem, vec.elem);
    std::swap(dim, vec.dim);
    return *this;

} 

//Comparision operators
template<typename Data>
bool Vector<Data>::operator == (const Vector<Data>& vec) const noexcept {
    if(dim == vec.dim){
        for(ulong i=0; i < dim; ++i) {
            if(elem[i] != vec.elem[i]){
                return false;
            }
            
        }
         return true;
    }
   else{
       return false;
   }

}

template<typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& vec) const noexcept{
    return !(*this == vec);
}

// Resize function
template<typename Data>
void Vector<Data>::Resize(const unsigned long newdim){
    if(newdim == 0){
        Clear();
    }
    else if (dim != newdim) {
        unsigned long limit = (dim < newdim) ? dim : newdim;
        Data* tmp_elem = new Data[newdim] {};
        for (unsigned long i = 0; i < limit; ++i) {
            std::swap(elem[i], tmp_elem[i]);
        }
        std::swap(elem, tmp_elem);
        dim = newdim;
        delete[] tmp_elem;
    }

}

//Clear function
template<typename Data>
void Vector<Data>::Clear() noexcept {
    delete[]elem;
    elem = nullptr;
    dim = 0;
}

//Front function
template<typename Data>
Data& Vector<Data>::Front()const {
    if (dim != 0) {
        return elem[0];
    }
    else{
        throw std::length_error ("Array vuoto.");

    }

}
//Back function
template<typename Data>
Data& Vector<Data>::Back() const{
    if(dim != 0){
        return elem[dim-1];
    } 
    else{
        throw std::length_error("Array vuoto.");
    }

}

//operator [] function

template<typename Data>
Data& Vector<Data>::operator[](const ulong i) const{
    if(i < dim){
        return elem[i];
    }
    else {
        throw std::out_of_range("Indice:" + std::to_string(i) + "; lunghezza del vettore: " +std::to_string(dim) + ".");
    }

}


//Map function, PreOrder, PostOrder
template<typename Data>
void Vector<Data>::Map(MapFunctor fun,void* par){
    MapPreOrder(fun, par);
}


template<typename Data>
void Vector<Data>::MapPreOrder(MapFunctor fun,void* par){
    for(unsigned long i = 0; i < dim; ++i){
        fun(elem[i],par);
    }
}

template<typename Data>
void Vector<Data>::MapPostOrder(MapFunctor fun,void* par){
    unsigned long i = dim;
    while (i>0) {
        fun(elem[--i], par);
    }
    
}

//Fold function, PreOrder, PostOrder

template<typename Data>
void Vector<Data>::Fold(FoldFunctor fun,const void* par, void* acc) const{
    FoldPreOrder(fun, par, acc);
}

template<typename Data>
void Vector<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const{
    for (unsigned long i = 0; i < dim; ++i) {
        fun(elem[i], par, acc);
    }
    
}

template<typename Data>
void Vector<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const{
    unsigned long i = dim;
    while (i > 0){
        fun(elem[--i], par, acc);
    }
}

/* template<typename Data> */
/* void Vector<Data>::PostOrderFoldableContainer(FoldFunctor fun, const void* par, void* acc) const {} */




/* ************************************************************************** */

}
