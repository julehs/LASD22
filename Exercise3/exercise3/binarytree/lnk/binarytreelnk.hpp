
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: virtual public BinaryTree<Data> {
                      // Must extend BinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::Node::isLeaf; //credo

  // ...

  struct NodeLnk: virtual public Node { // Must extend Node

  private:

    // ...

  protected:

    // ...

  public:

    // ...

  };

public:

  // Default constructor
    BinaryTreeLnk() noexcept = default;

  /* ************************************************************************ */

  // Specific constructors
    BinaryTreeLnk(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
    BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
    BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
    virtual ~BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Copy assignment
    BinaryTreeLnk& operator = (const BinaryTreeLnk&);// type operator=(argument) specifiers;

  // Move assignment
    BinaryTreeLnk& operator = (BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const BinaryTreeLnk&) const noexcept;
    bool operator != (const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
