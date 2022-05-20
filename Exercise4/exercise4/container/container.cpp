
namespace lasd {

/* ************************************************************************** */

//Operator function
/* template<typename Data>  */
/* bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& lc) const noexcept{ */
/*     return !(*this == lc); */
/* } */

//Front function
template <typename Data>
Data& LinearContainer<Data>::Front()const {
    if(dim == 0)
            throw std::length_error("Array vuoto.");
    else return operator[](0);
}

//Back function
template <typename Data>
Data& LinearContainer<Data>::Back() const {
    if(dim == 0)
            throw std::length_error("Array vuoto.");
    else{
        return operator[](dim - 1);
    } 
}

//ExtraFoldExist, Foldable Container
template <typename Data>
void ExtraFoldExist(const Data& data, const void* value, void* exists) {
    /* if (data == (*(Data*)value)) */
    /* *(bool*)exists = true; */

    if(data == *((Data*)value))
			*((bool*)exists) = true;
}

template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& data) const noexcept{
    bool exists = false;
    Fold(&ExtraFoldExist<Data>, &data, &exists);
    return exists;
}

//PreOrderMappableContainer

template<typename Data>
void PreOrderMappableContainer<Data>::Map(MapFunctor fun, void* par) {
    MapPreOrder(fun, par);
}

//PreOrderFoldableContainer

template<typename Data>
void PreOrderFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const{
    FoldPreOrder(fun, par, acc);

}

//PostOrderMappableContainer
	template <typename Data>
	void PostOrderMappableContainer<Data>::Map(MapFunctor fun, void* par) {
		MapPostOrder(fun, par);
	}
	/* ************************************************************************** */

	//PostOrderFoldableContainer
	template <typename Data>
	void PostOrderFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
		FoldPostOrder(fun, par, acc);
	}
	/* ************************************************************************** */

	//InOrderMappableContainer

	template <typename Data>
	void InOrderMappableContainer<Data>::Map(MapFunctor fun, void* par) {
		MapInOrder(fun, par);
	}
	/* ************************************************************************** */

	//InOrderFoldableContainer
	template <typename Data>
	void InOrderFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
		FoldInOrder(fun, par, acc);
	}
	/* ************************************************************************** */

	//BreadthMappableContainer
	template <typename Data>
	void BreadthMappableContainer<Data>::Map(MapFunctor fun, void* par) {
		MapBreadth(fun, par);
	}
	/* ************************************************************************** */
	
	//BreadthFoldableContainer
	template <typename Data>
	void BreadthFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
		FoldBreadth(fun, par, acc);
	}


//DictionaryContainer

//Insert Copy
template <typename Data>
void DictionaryContainer<Data>::Insert(const Data &dato) noexcept {
    // struct BST<Data>::NodeLnk*& pointer = FindPointerTo(root, dato);
    // if(pointer==nullptr){
    //     pointer = new struct BST<Data>::NodeLnk(dato);
    //     dim++;
    // }
}


//Insert Move
template <typename Data>
void DictionaryContainer<Data>::Insert(Data &&dato) noexcept {
    // struct BST<Data>::NodeLnk*& pointer = FindPointerTo(root, dato);
    // if(pointer==nullptr){
    //     pointer = new struct BST<Data>::NodeLnk(std::move(dato));
    //     dim++;
    // }
}


//Remove
template <typename Data>
void DictionaryContainer<Data>::Remove(const Data &dato) noexcept {
    // delete Detach(FindPointerTo(root, dato));
}

/* ************************************************************************** */

}

