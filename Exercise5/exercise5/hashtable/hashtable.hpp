
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
   ulong operator() (const Data&) const noexcept;  // (concrete function should not throw exceptions)
  
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
   using HashTable<Data>::dim; 

  

public:

  // Destructor
    virtual ~HashTable() = default;

//TODO indirizzamento con gen. random di valori per le funzioni universali (valore A,primo, sarà un numero che va da 1 a un certo numero scelto. B,uno escluso, da 0 a numero scelto )
// mettere un numero primo e def come const

  // void srand(uint);
  // bool isPrime(const ulong &p);

  
  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const HashTable&) const noexcept = delete; // Comparison of abstract binary tree is possible.
    bool operator != (const HashTable&) const noexcept = delete; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member function
    void Resize(const ulong); // Resize the hashtable to a given size
 

protected:

  // Copy assignment
    HashTable& operator = (const HashTable&) = delete; // Copy assignment of abstract types should not be possible.
  

  // Move assignment
    HashTable& operator = (HashTable&&) noexcept = delete; // Move assignment of abstract types should not be possible.
 

 /* ************************************************************************ */

  // Auxiliary member functions
    void HashKey(ulong) noexcept;
  
  //TODO si potrebbe dividere l'hashkey in due passando anche il dato

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
