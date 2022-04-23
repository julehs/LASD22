
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: virtual public Queue<Data>
                virtual protected Vector<Data> {
                  // Must extend Queue<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::elemento;
  using Vector<Data>::dimensione;
  ulong testa = 0;
  ulong coda = 0;
  // ...

public:

  // Default constructor
    QueueVec();

  /* ************************************************************************ */

  // Specific constructor
    QueueVec(const LinearContainer<Data>& ); // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
    QueueVec(const QueueVec&);

  // Move constructor
    QueueVec(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
    ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
    QueueVec& operator = (const QueueVec&);

  // Move assignment
    QueueVec& operator = (QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const QueueVec<Data>&) const noexcept;
    bool operator != (const QueueVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

    const Data& Head() const override = 0; // Override Queue member (constant version; must throw std::length_error when empty)
    Data& Head() const override; // Override Queue member (must throw std::length_error when empty)
    void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
    Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
    void Enqueue(const Data&) override; // Override Queue member (copy of the value)
    void Enqueue(Data&&) override; // Override Queue member (move of the value)



  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    bool Empty() const noexcept override; // Override Container member

    ulong Size() const noexcept override; // Override Container member

    void Clear() noexcept override; // Override Container member

protected:

  // Auxiliary member functions

    void Expand();
    void Reduce();
    void SwapVectors(unit newSize) noexcept;

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
