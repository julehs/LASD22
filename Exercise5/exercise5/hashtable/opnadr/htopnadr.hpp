
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "list.hpp"
#include "bst.hpp"
#include "container.hpp"


/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr: virtual public HashTable<Data> { // Must extend HashTable<Data>

private:

  // ...

protected:

   using HashTable<Data>::dim;


public:

  // Default constructor
     HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
    HashTableOpnAdr (const ulong);  // A hash table of a given size
  
    HashTableOpnAdr(const LinearContainer<Data>&); // A hash table obtained from a LinearContainer
  
    HashTableOpnAdr(size_t,const LinearContainer<Data>&); // A hash table of a given size obtained from a LinearContainer


  /* ************************************************************************ */

  // Copy constructor
    HashTableOpnAdr (const HashTableOpnAdr&);

  // Move constructor
    HashTableOpnAdr (HashTableOpnAdr&&) noexcept;
  
  /* ************************************************************************ */

  // Destructor
    virtual ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
    HashTableOpnAdr& operator = (const HashTableOpnAdr&) = delete;

  // Move assignment
    HashTableOpnAdr& operator = (HashTableOpnAdr&&) noexcept = delete;
  

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const HashTableOpnAdr&) const noexcept;
    bool operator != (const HashTableOpnAdr&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)
    void Resize(const ulong); // Resize the hashtable to a given size
  
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)
    virtual bool Insert(const Data&) noexcept override; // Override DictionaryContainer member (Copy of the value)
    virtual bool Insert(Data&&) noexcept override; // Override DictionaryContainer member (Move of the value)
    virtual void Remove(const Data&) override; // Override DictionaryContainer member
 

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

    virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

    virtual void Map(MapFunctor, void*) override; // Override MappableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

    virtual void Fold(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    virtual void Clear() override; // Override Container member
 

public:

  // Auxiliary member functions

    void HashKey(ulong) noexcept;
    void Find();
    ulong& FindEmpty(ulong& collisionIndex)noexcept; 
    void Remove();
  

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
