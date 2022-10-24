
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

   using HashTable<Data>::size;
   using HashTable<Data>::sizeHT;
   using HashTable<Data>::hash;
   using HashTable<Data>::a;
   using HashTable<Data>::b;

   Vector<Data> table;
   Vector<char> controllerTable;

   using HashTable<Data>::HashKey;



public:

  // Default constructor
     HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
    HashTableOpnAdr(const ulong);  // A hash table of a given size
  
    HashTableOpnAdr(const LinearContainer<Data>&); // A hash table obtained from a LinearContainer
  
    HashTableOpnAdr(const ulong, const LinearContainer<Data>&); // A hash table of a given size obtained from a LinearContainer


  /* ************************************************************************ */

  // Copy constructor
    HashTableOpnAdr(const HashTableOpnAdr<Data>&);

  // Move constructor
    HashTableOpnAdr(HashTableOpnAdr<Data>&&) noexcept;
  
  /* ************************************************************************ */

  // Destructor
    virtual ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
    HashTableOpnAdr<Data>& operator = (const HashTableOpnAdr<Data>&);

  // Move assignment
    HashTableOpnAdr<Data>& operator = (HashTableOpnAdr<Data>&&) noexcept;
  

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const HashTableOpnAdr<Data>&) const noexcept;
    bool operator != (const HashTableOpnAdr<Data>&) const noexcept;


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
