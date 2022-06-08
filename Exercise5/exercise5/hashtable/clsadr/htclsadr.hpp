
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"
#include "../../binarytree/binarytree.hpp"




/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr: virtual public HashTable<Data> { // Must extend HashTable<Data>

private:

  // ...

protected:
  
   using HashTable<Data>::dim;
   using HashTable<Data>::a;
   using HashTable<Data>::b;
   using HashTable<Data>::p;
   lasd::Vector<lasd::BST<Data>> ArraySupporter;
  // ...

public:

  // Default constructor
    HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Specific constructors

    HashTableClsAdr(size_t); // A hash table of a given size

    HashTableClsAdr(const LinearContainer<Data>&); // A hash table obtained from a LinearContainer

    HashTableClsAdr(size_t, const LinearContainer<Data>&); // A hash table of a given size obtained from a LinearContainer
 

  /* ************************************************************************ */

  // Copy constructor
    HashTableClsAdr (const HashTableClsAdr&);
  
  // Move constructor
    HashTableClsAdr (HashTableClsAdr&&) noexcept;
  
  /* ************************************************************************ */

  // Destructor
   virtual ~HashTableClsAdr() = default; 
   
  /* ************************************************************************ */

  // Copy assignment
    HashTableClsAdr& operator = (const HashTableClsAdr&);
  
  // Move assignment
    HashTableClsAdr& operator = (HashTableClsAdr&&) noexcept;
  
  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const HashTableClsAdr&) const noexcept;
    bool operator != (const HashTableClsAdr&) const noexcept;
  
  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)
    void Resize(ulong) noexcept override; // Resize the hashtable to a given size

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
    virtual void Map(MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)
    using typename FoldableContainer<Data>::FoldFunctor;
    virtual void Fold(FoldFunctor, const void*, void* ) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
    virtual void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
