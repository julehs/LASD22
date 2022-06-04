
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
   using HashTable<Data>::dim; //??

  //TODO aggiunta di un hash<data>
  // ...

public:

  // Destructor

    virtual ~HashTable() = default;
//TODO indirizzamento con gen. random di valori per le funzioni universali (valore A,primo, sarà un numero che va da 1 a un certo numero scelto. B,uno escluso, da 0 a numero scelto )
// mettere un numero primo e def come const



  
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

// Copy assignment

   HashTable& operator = (const HashTable&) = delete; 
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
    HashTable& operator = (HashTable&&) noexcept = delete;
  // type operator=(argument); // Move assignment of abstract types should not be possible.



  // Auxiliary member functions

    void HashKey(ulong) noexcept;
  // type HashKey(argument) specifiers;
  //TODO si potrebbe dividere l'hashkey in due passando anche il dato

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
