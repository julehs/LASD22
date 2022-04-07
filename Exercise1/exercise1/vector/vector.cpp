
namespace lasd {

/* ************************************************************************** */

//Constructor
template <typename Data>
Vector<Data>::Vector(const ulong newdim){
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
Vector<Data>::~Vector(){
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


}
