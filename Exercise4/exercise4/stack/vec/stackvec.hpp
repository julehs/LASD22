
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: public virtual Stack<Data>, 
                protected virtual Vector<Data> {
                  // Must extend Stack<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::dim;
  using Vector<Data>::elem;
  ulong top = 0;

  // ...

public:

  // Default constructor
    StackVec();

  /* ************************************************************************ */

  // Specific constructor
    StackVec(const LinearContainer<Data>&); // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
    StackVec(const StackVec&);

  // Move constructor
    StackVec(StackVec&&);

  /* ************************************************************************ */

  // Destructor
    ~StackVec() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
    StackVec& operator = (const StackVec&);

  // Move assignment
    StackVec& operator = (StackVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const StackVec&) const noexcept;
    bool operator != (const StackVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)
    virtual const Data& Top() override; // Override Stack member (constant version; must throw std::length_error when empty)
    virtual Data& Top() const override; // Override Stack member (must throw std::length_error when empty)
    virtual void Pop() override; // Override Stack member (must throw std::length_error when empty)
    virtual Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
    virtual void Push(const Data&) override; // Override Stack member (copy of the value)
    virtual void Push(Data&&) override; // Override Stack member (move of the value)
                                        //noexc?



  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    virtual bool Empty() const noexcept override; // Override Container member

    virtual ulong Size() const noexcept override; // Override Container member

    virtual void Clear() noexcept override; // Override Container member

protected:

  // Auxiliary member functions

    void Expand();
    void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
