
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
   ulong operator() (const Data&) const noexcept;
  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)

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
   using HashTable<Data>; //??

  //TODO aggiunta di un hash<data>
  // ...

public:

  // Destructor

    virtual ~HashTable() = default;
  // ~HashTable() specifiers

  /* ************************************************************************ */

  // Copy assignment

   HashTable& operator = (const HashTable&) = delete; 
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
    HashTable& operator = (HashTable&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators

    bool operator == (const HashTable&) const noexcept = delete;
    bool operator != (const HashTable&) const noexcept = delete;
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member function

    void Resize(const ulong);
  // type Resize(argument) specifiers; // Resize the hashtable to a given size

protected:

  // Auxiliary member functions

    void HashKey(ulong) noexcept;
  // type HashKey(argument) specifiers;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
