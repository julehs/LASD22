
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

    const  Data& Min() const;
    Data MinNRemove();
    void RemoveMin();

    const Data& Max() const;
    Data MaxNRemove();
    void RemoveMax();

    const Data& Predecessor(const Data&) const;
    Data PredecessorNRemove(const Data&);
    void RemovePredecessor(const Data&);

    const Data& Successor(const Data&) const;
    Data SuccessorNRemove (const Data&);
    void RemoveSuccessor(const Data&);

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)

  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)

  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)

  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

    void Insert(const Data&) noexcept override;
    void Insert(Data&&) noexcept override;
    void Remove (const Data&) noexcept override;
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  // type Remove(argument) specifiers; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

    bool Exists(const Data&) const noexcept override;
  // type Exists(argument) specifiers; // Override TestableContainer member

protected:

  // Auxiliary member functions
    Data DataNDelete(struct BST<Data>::NodeLnk*);
  // type DataNDelete(argument) specifiers;

  // type Detach(argument) specifiers;
    struct BST<Data>::NodeLnk* Detach(struct BST<Data>::NodeLnk*&) noexcept;

  // type DetachMin(argument) specifiers;
    struct BST<Data>::NodeLnk* DetachMin(struct BST<Data>::NodeLnk*&) noexcept;
  // type DetachMax(argument) specifiers;
    struct BST<Data>::NodeLnk* DetachMax(struct BST<Data>::NodeLnk*&) noexcept;



  // type Skip2Left(argument) specifiers;
    struct BST<Data>::NodeLnk* Skip2Left(struct BST<Data>::NodeLnk*&) noexcept;
  // type Skip2Right(argument) specifiers;
    struct BST<Data>::NodeLnk* Skip2Right(struct BST<Data>::NodeLnk*&) noexcept; 

//FindPointerToMin mutable NOT CONST
  struct BST<Data>::NodeLnk*& FindPointerToMin(struct BST<Data>::NodeLnk*&) noexcept;

//FindPointerToMin unmutable
struct BST<Data>::NodeLnk* FindPointerToMin (struct BST<Data>::NodeLnk* const&) const noexcept;

//FindPointerToMax mutable NOT CONST
struct BST<Data>::NodeLnk*& FindPointerToMax (struct BST<Data>)

//FindPointerToMax unmutable
struct BST<Data>::NodeLnk*

//FindPointerTo mutable NOT CONST
struct BST<Data>::NodeLnk*&

//FindPointerTo unmutable
struct BST<Data>::NodeLnk*


//FindPointerToPredecessor mutable NOT CONST
struct BST<Data>::NodeLnk*&


//FindPointerToPredecessor unmutable
struct BST<Data>::NodeLnk*


//FindPointerToSuccessor mutable NOT CONST
struct BST<Data>::NodeLnk*&



//FindPointerToSuccessor unmutable
struct BST<Data>::NodeLnk*










  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions

  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions

  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
