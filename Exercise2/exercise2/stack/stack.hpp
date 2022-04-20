
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack: virtual public Container {
              // Must extend Container

private:

  // ...

protected:

  unsigned int index = 0;

public:

  // Destructor
    virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
    Stack& operator = (const Stack&) = delete;// Copy assignment of abstract types should not be possible.

  // Move assignment
    Stack& operator = (Stack&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const Stack&) const noexcept = delete;  // Comparison of abstract types might not be possible.
    bool operator != (const Stack&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions
  //constant version?
  virtual Data& Top() const = 0; //concrete func...
  virtual void Pop() = 0; // concrete func..
  virtual Data TopNPop() = 0; // concrete func
  virtual void Push(const Data&) = 0;
  virtual void Push(Data&&) noexcept = 0; 

  // type Top() specifiers; // (constant version; concrete function must throw std::length_error when empty)
  // type Top() specifiers; // (concrete function must throw std::length_error when empty)
  // type Pop() specifiers; // (concrete function must throw std::length_error when empty)
  // type TopNPop() specifiers; // (concrete function must throw std::length_error when empty)
  // type Push(argument) specifiers; // Copy of the value
  // type Push(argument) specifiers; // Move of the value

};

/* ************************************************************************** */

}

#endif
