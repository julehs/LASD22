#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hash {

public:
    ulong operator() (const int&) const noexcept;  // (concrete function should not throw exceptions)
    ulong operator() (const double&) const noexcept; // (concrete function should not throw exceptions)
    ulong operator() (const std::string&) const noexcept; // (concrete function should not throw exceptions)
};

/* ************************************************************************** */

template <typename Data>
class HashTable:virtual public DictionaryContainer,
                virtual public MappableContainer,
                virtual public FoldableContainer { // Must extend DictionaryContainer<Data>,
                                                   //             MappableContainer<Data>,
                                                   //             FoldableContainer<Data>

private:

  // ...

protected:

   using DictionaryContainer<Data>::dim;
   using HashTable<Data>::size_t; 

  

public:

  // Destructor
    virtual ~HashTable() = default;

  
  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const HashTable&) const noexcept; // Comparison of abstract binary tree is possible.
    bool operator != (const HashTable&) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member function
    virtual void Resize(const ulong) = 0; // Resize the hashtable to a given size
 

protected:

  // Copy assignment
    HashTable<Data>& operator = (const HashTable&); // Copy assignment of abstract types should not be possible.
  

  // Move assignment
    HashTable<Data>& operator = (HashTable&&) noexcept; // Move assignment of abstract types should not be possible.
 

 /* ************************************************************************ */

  // Auxiliary member functions
    void HashKey(const ulong) const;
    void HashKey(const Data&) const;
  

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif