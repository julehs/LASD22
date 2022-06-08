
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"
#include "../../binarytree/binarytree.hpp"


/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr: virtual public HashTable<Data> { // Must extend HashTable<Data>

private:

  // ...

protected:

   using HashTable<Data>::dim;
   using HashTable<Data>::a;
   using HashTable<Data>::b;
   using HashTable<Data>::p;
   lasd::Vector<Data> VecSupport;
   lasd::Vector<char> Flag;



public:

  // Default constructor
     HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
    HashTableOpnAdr(const ulong sizetab);  // A hash table of a given size
  
    HashTableOpnAdr(const LinearContainer<Data>&); // A hash table obtained from a LinearContainer
  
    HashTableOpnAdr(const ulong sizetab, const LinearContainer<Data>&); // A hash table of a given size obtained from a LinearContainer


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
    HashTableOpnAdr& operator = (const HashTableOpnAdr&);

  // Move assignment
    HashTableOpnAdr& operator = (HashTableOpnAdr&&) noexcept;
  

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const HashTableOpnAdr&) const noexcept;
    bool operator != (const HashTableOpnAdr&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)
    void Resize(const ulong) override; // Resize the hashtable to a given size
  
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)
    virtual void Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
    virtual void Insert(Data&&) noexcept override; // Override DictionaryContainer member (Move of the value)
    virtual void Remove(const Data&) override; // Override DictionaryContainer member
 

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

    virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
    using typename MappableContainer<Data>::MapFunctor;
    void Map(MapFunctor, void*) override; // Override MappableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)
    using typename FoldableContainer<Data>::FoldFunctor;
    void Fold(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    void Clear() override; // Override Container member
 

public:

  // Auxiliary member functions

    const ulong HashKey(Data&,const ulong) const;
    void Find(const Data&) const noexcept;
    ulong FindEmpty(const ulong) noexcept; 
    void Remove(Data&, const ulong);
  

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
