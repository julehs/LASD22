
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "list.hpp"
#include "bst.hpp"
#include "container.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr: virtual public HashTable<Data> { // Must extend HashTable<Data>

private:

  // ...

protected:

   using HashTable<Data>::dim;

  // ...

public:

  // Default constructor
     HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
    HashTableOpnAdr (const ulong); //void?
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size

    HashTableOpnAdr(const LinearContainer<Data>&);
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a LinearContainer
  
    HashTableOpnAdr(const ulong LinearContainer<Data>&);
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
    HashTableOpnAdr (const HashTableOpnAdr&);
  // HashTableOpnAdr(argument) specifiers;

  // Move constructor
    HashTableOpnAdr (HashTableOpnAdr&&) noexcept;
  // HashTableOpnAdr(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
    HashTableOpnAdr& operator = (const HashTableOpnAdr&) = delete;
  // type operator=(argument) specifiers;

  // Move assignment
    HashTableOpnAdr& operator = (HashTableOpnAdr&&) noexcept = delete;
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const HashTableOpnAdr&) const noexcept;
    bool operator != (const HashTableOpnAdr&) const noexcept;
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)
    void Resize(const ulong);
  // type Resize(argument) specifiers; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)
    virtual void Insert(const Data&) override;
    virtual void Insert(Data&&) noexcept override;
    virtual void Remove(const Data&) override;
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  // type Remove(argument) specifiers; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  virtual bool Exists(const Data&) const noexcept override;

  // type Exists(argument) specifiers; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

    virtual void Map(MapFunctor, void*) override;
  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

    virtual void Fold(FoldFunctor, const void*, void*) const override;

  // type Fold(argument) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    virtual void Clear() override;
  // type Clear() specifiers; // Override Container member

public:

  // Auxiliary member functions

  void HashKey(ulong) noexcept;
  void Find();
  ulong& FindEmpty(ulong& collisionIndex)noexcept; //ulong
  void Remove();
  
  // type HashKey(argument)specifiers;
  // type Find(argument) specifiers;
  // type FindEmpty(argument) specifiers;
  // type Remove(argument) specifiers;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
