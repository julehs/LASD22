
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../queue/lst/queuelst.hpp"

#include "../stack/lst/stacklst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree: virtual public PreOrderMappableContainer<Data>,
                  virtual public PostOrderMappableContainer<Data>,
                  virtual public InOrderMappableContainer<Data>,
                  virtual public BreadthMappableContainer<Data>,
                  virtual public PreOrderFoldableContainer<Data>,
                  virtual public PostOrderFoldableContainer<Data>,
                  virtual public InOrderFoldableContainer<Data>,
                  virtual public BreadthFoldableContainer<Data> {
                   // Must extend PreOrderMappableContainer<Data>,
                   //             PostOrderMappableContainer<Data>,
                   //             InOrderMappableContainer<Data>,
                   //             BreadthMappableContainer<Data>,
                   //             PreOrderFoldableContainer<Data>,
                   //             PostOrderFoldableContainer<Data>,
                   //             InOrderFoldableContainer<Data>,
                   //             BreadthFoldableContainer<Data>

private:

  // ...

protected:

   using InOrderMappableContainer<Data>::dim;

  // ...

public:

  struct Node {

  private:

    // ...

  protected:

    //Comparision operators
    bool operator == (const Node&) const noexcept;
    bool operator != (const Node&&) const noexcept;

  public:

     friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
       virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
       Node& operator = (const Node&); // Copy assignment of abstract types should not be possible.

    // Move assignment
      Node& operator = (Node&&) noexcept; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Comparison operators
    bool operator == (const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.
    bool operator != (const Node&) const noexcept;// Comparison of abstract types is possible, but should not be visible.

    /* ********************************************************************** */

    // Specific member functions

      virtual Data& Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)
      virtual const Data& Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)
    

      virtual bool IsLeaf() const noexcept = 0; // (concrete function should not throw exceptions)
      virtual bool HasLeftChild() const noexcept = 0; // (concrete function should not throw exceptions)
      virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)
  
    
      virtual Node& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
      virtual Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
    

  };

  /* ************************************************************************ */

  // Destructor
    virtual ~BinaryTree() default;

  /* ************************************************************************ */

  // Copy assignment
    BinaryTree& operator = (const BinaryTree&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    BinaryTree& operator = (BinaryTree&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
    bool operator != (const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

    virtual Node& Root() const = 0 ; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

   using typename MappableContainer<Data>::MapFunctor;

   void Map(MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

   using typename FoldableContainer<Data>::FoldFunctor;

   void Fold(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

   void MapPreOrder(const MapFunctor, void*) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

   void FoldPreOrder(const FoldFunctor, const void*, void*) const override; // Override PreOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

   void MapPostOrder(const MapFunctor, void*) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

   void FoldPostOrder(const FoldFunctor, const void*, void*) const override; // Override PostOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)

   void MapInOrder(const MapFunctor, void*) override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)

   void FoldInOrder(const FoldFunctor, const void*, void*) const override; // Override InOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

   void MapBreadth(const MapFunctor, void*) override; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

   void FoldBreadth(const FoldFunctor, const void*, void*) const override; // Override BreadthFoldableContainer member

protected:

  // Auxiliary member functions (for PreOrderMappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderFoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderMappableContainer)

  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderFoldableContainer)

  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)

  // type MapInOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)

  // type FoldInOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthMappableContainer)

  // type MapBreadth(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthFoldableContainer)

  // type FoldBreadth(arguments) specifiers; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator {
                           // Must extend ForwardIterator<Data>,
                           //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator {
                            // Must extend ForwardIterator<Data>,
                            //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;

  // Move constructor
  // BTInOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;

  // Move constructor
  // BTBreadthIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
