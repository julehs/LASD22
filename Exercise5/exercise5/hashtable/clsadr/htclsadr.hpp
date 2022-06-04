
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "list.hpp"
// #include ... list,vector o bst

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr: virtual public HashTable<Data> { // Must extend HashTable<Data>

private:

  // ...

protected:

   using HashTable<Data>::dim;

  // ...

public:

  // Default constructor
    HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Specific constructors

    HashTableClsAdr(const ulong); //utile per resize

    HashTableClsAdr(const LinearContainer<Data>&);

    HashTableClsAdr(const ulong LinearContainer<Data>&); //unione di entrambi i costruttori
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a LinearContainer
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor

    HashTableClsAdr (const HashTableClsAdr&);
  // HashTableClsAdr(argument) specifiers;



  // Move constructor

    HashTableClsAdr (HashTableClsAdr&&) noexcept;
  // HashTableClsAdr(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
   virtual ~HashTableClsAdr() = default; 
   

  /* ************************************************************************ */

  // Copy assignment
    HashTableClsAdr& operator = (const HashTableClsAdr&) = delete;
  // type operator=(argument) specifiers;

  // Move assignment
    HashTableClsAdr& operator = (HashTableClsAdr&&) noexcept = delete;
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const HashTableClsAdr&) const noexcept;
    bool operator != (const HashTableClsAdr&) const noexcept;
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size  
    void Resize(const ulong);

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  // type Remove(argument) specifiers; // Override DictionaryContainer member

    virtual void Insert(const Data&) override;
    virtual void Insert(Data&&) noexcept override;
    virtual void Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
    virtual bool Exists(const Data&) const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
    virtual void Map(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // type Fold(argument) specifiers; // Override FoldableContainer member
    virtual void Fold(FoldFunctor, const void*, void* ) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
    virtual void Clear() override;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
