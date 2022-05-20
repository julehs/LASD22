
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public BinaryTreeLnk<Data> { // Must extend BinaryTreeLnk<Data>

private:

  // ...

protected:

   using BinaryTreeLnk<Data>::dim;
   using BinaryTreeLnk<Data>::root;

  

public:

  // Default constructor
     BST() = default;

  /* ************************************************************************ */

  // Specific constructors  
    BST(const LinearContainer<Data>&); // A bst obtained from a LinearContainer


  /* ************************************************************************ */

  // Copy constructor
     BST(const BST&);

  // Move constructor
     BST(BST&&) noexcept;

  /* ************************************************************************ */

  // Destructor
    virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
    BST& operator =(const BST&);

  // Move assignment
    BST& operator = (BST&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const BST&) const noexcept;
    bool operator != (const BST&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions

    const  Data& Min() const; // (concrete function must throw std::length_error when empty)
    Data MinNRemove(); // (concrete function must throw std::length_error when empty)
    void RemoveMin(); // (concrete function must throw std::length_error when empty)

    const Data& Max() const; // (concrete function must throw std::length_error when empty)
    Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
    void RemoveMax(); // (concrete function must throw std::length_error when empty)

    const Data& Predecessor(const Data&) const; // (concrete function must throw std::length_error when empty)
    Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when empty)
    void RemovePredecessor(const Data&); // (concrete function must throw std::length_error when empty)

    const Data& Successor(const Data&) const; // (concrete function must throw std::length_error when empty)
    Data SuccessorNRemove (const Data&); // (concrete function must throw std::length_error when empty)
    void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

    void Insert(const Data&) noexcept override; // Override DictionaryContainer member (Copy of the value)
    void Insert(Data&&) noexcept override; // Override DictionaryContainer member (Move of the value)
    void Remove (const Data&) noexcept override; // Override DictionaryContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

    bool Exists(const Data&) const noexcept override; // Override TestableContainer member


protected:

  // Auxiliary member functions
    Data DataNDelete(struct BST<Data>::NodeLnk*);
  
  // type Detach(argument) specifiers;
    struct BST<Data>::NodeLnk* Detach(struct BST<Data>::NodeLnk*&) noexcept;

  //Detach Max/Min
    struct BST<Data>::NodeLnk* DetachMin(struct BST<Data>::NodeLnk*&) noexcept;
    struct BST<Data>::NodeLnk* DetachMax(struct BST<Data>::NodeLnk*&) noexcept;

  //Skip
    struct BST<Data>::NodeLnk* Skip2Left(struct BST<Data>::NodeLnk*&) noexcept;
    struct BST<Data>::NodeLnk* Skip2Right(struct BST<Data>::NodeLnk*&) noexcept; 


  //FindPointerToMax/Min (mutable) NOT CONST
   struct BST<Data>::NodeLnk*& FindPointerToMin(struct BST<Data>::NodeLnk*&) noexcept; // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
   struct BST<Data>::NodeLnk*& FindPointerToMax (struct BST<Data>::NodeLnk*&) noexcept; // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions


  //FindPointerToMax/Min (unmutable) CONST
    struct BST<Data>::NodeLnk* const& FindPointerToMin (struct BST<Data>::NodeLnk* const&) const noexcept; // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
    struct BST<Data>::NodeLnk* const& FindPointerToMax (struct BST<Data>::NodeLnk* const&) const noexcept; // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions



  //FindPointerTo (mutable) NOT CONST
    struct BST<Data>::NodeLnk*& FindPointerTo(struct BST<Data>::NodeLnk*&, const Data&) noexcept; // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions


  //FindPointerTo (unmutable) CONST
    struct BST<Data>::NodeLnk* const& FindPointerTo(struct BST<Data>::NodeLnk* const&, const Data&) const noexcept; // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions


  //FindPointerToPredecessor/Successor (mutable) NOT CONST
    struct BST<Data>::NodeLnk*& FindPointerToPredecessor (struct BST<Data>::NodeLnk*&, const Data&) noexcept;  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
    struct BST<Data>::NodeLnk*& FindPointerToSuccessor (struct BST<Data>::NodeLnk*&, const Data&) noexcept; // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions


  //FindPointerToPredecessor/Successor (unmutable) CONST
    struct BST<Data>::NodeLnk* const& FindPointerToPredecessor(struct BST<Data>::NodeLnk* const&, const Data&) const noexcept;  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
    struct BST<Data>::NodeLnk* const& FindPointerToSuccessor(struct BST<Data>::NodeLnk* const&, const Data&) const noexcept; // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions


  


};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
