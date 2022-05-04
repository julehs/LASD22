
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data> {
                      // Must extend BinaryTree<Data>

private:

  // ...

protected:

    using BinaryTree<Data>::dim;

  // ...

  struct NodeVec: virtual public BinaryTree<Data>::Node { // Must extend Node

  private:

    // ...

  protected:

    // ...

  public:

    Vector<NodeVec*> *vectorPointer = nullptr;
    Data elem;
    ulong indexNode;


    //Constructor
    NodeVec() = default;

    NodeVec(Data&, ulong, Vector<NodeVec*>*);


    //Destructor
    virtual ~NodeVec = default;


    //Specific member functions

    Data& Element() noexcept override; //mutable access
    const Data& Element() const noexcept override; //immutable


    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    NodeVec& LeftChild() const override;
    NodeVec& RightChild() const override;

  };

  Vector<NodeVec*> *treevector = nullptr;

public:

  // Default constructor
  
    BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
    BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
    BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
    BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
    virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
    BinaryTreeVec<Data>& operator = (const BinaryTreeVec<Data>&);

  // Move assignment
    BinaryTreeVec<Data>& operator = (BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const BinaryTreeVec<Data>&) const noexcept;
    bool operator != (const BinaryTreeVec<Data>&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

    NodoVec& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    void Clear () override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

    using typename BreadthMappableContainer<Data>::MapFunctor;
    void MapBreadth(const MapFunctor, void*) override; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)
    using typename BreadthFoldableContainer<Data>::FoldFunctor;
    void MapBreadth(const MapFunctor, void*) override; // Override BreadthFoldableContainer member

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
