
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst: virtual public Queue<Data> 
                virtual public List<Data> {
                  // Must extend Queue<Data>,
                  //             List<Data>

private:

  // ...

protected:

   using List<Data>::dimensione;

  // ...

public:

  // Default constructor
    QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
    QueueLst(const LinearContainer<Data>&); // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
    QueueLst(const QueueLst<Data>&);

  // Move constructor
    QueueLst(QueueLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
    ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
    QueueLst& operator = (const QueueLst&);

  // Move assignment
    QueueLst& operator = (QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const QueueLst&) const noexcept;
    bool operator != (const QueueLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data& Head() const override; // Override Queue member (constant version; must throw std::length_error when empty)
  Data& Head() const override; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  void Enqueue(Data&&) override; // Override Queue member (move of the value)
                                          // noexc?
  
  

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  

  inline void Clear() override{   // Override Container member
    List<Data>::Clear();
  } 


};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
