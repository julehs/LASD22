
namespace lasd {

/* ************************************************************************** */

//LinearContainer
template<typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer<Data>& lc) const noexcept{
    if(dim == lc.dim){
        for(unsigned long i; i < dim; ++i){
            if (operator[][i] != lc[i])
            {
                return false;
            }
            return true;
        }
        else{
            return false;
        }
    }
}

template<typename Data> 
bool LinearContainer<Data>::operator==(const LinearContainer<Data>& lc) const noexcept{
    return !(*this == lc);

}

template <typename Data>
Data& LinearContainer<Data>::Front()const {
    if(dim == 0)
            throw std::length_error("Array vuoto.");
    else return operator[](0);
}

template <typename Data>
Data& LinearContainer<Data>::Back() const {
    if(dim == 0)
            throw std::length_error("Array vuoto.");
    else{
        return operator[](size - 1);
    } 
}

/* ************************************************************************** */

}
