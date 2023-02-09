
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"
#include "../../binarytree/binarytree.hpp"

/* ************************************************************************** */

namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  class HashTableOpnAdr : virtual public HashTable<Data>
  { // Must extend HashTable<Data>

  private:
    // ...

  protected:
    using HashTable<Data>::dim;
    using HashTable<Data>::sizeHT;
    using HashTable<Data>::hash;
    using HashTable<Data>::a;
    using HashTable<Data>::removed;
    using HashTable<Data>::b;
    using HashTable<Data>::HashKey;

    Vector<Data> table;
    Vector<char> controllerTable; // vettore tombstone utile nella ricerca con indice eliminato

  public:
    // Default constructor
    HashTableOpnAdr() noexcept;

    /* ************************************************************************ */

    // Specific constructors
    HashTableOpnAdr(const ulong) noexcept; // A hash table of a given size

    HashTableOpnAdr(const LinearContainer<Data> &) noexcept; // A hash table obtained from a LinearContainer

    HashTableOpnAdr(const ulong, const LinearContainer<Data> &) noexcept; // A hash table of a given size obtained from a LinearContainer

    /* ************************************************************************ */

    // Copy constructor
    HashTableOpnAdr(const HashTableOpnAdr<Data> &) noexcept;

    // Move constructor
    HashTableOpnAdr(HashTableOpnAdr<Data> &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~HashTableOpnAdr() = default;

    /* ************************************************************************ */

    // Copy assignment
    HashTableOpnAdr<Data> &operator=(const HashTableOpnAdr<Data> &) noexcept;

    // Move assignment
    HashTableOpnAdr<Data> &operator=(HashTableOpnAdr<Data> &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const HashTableOpnAdr<Data> &) const noexcept;
    bool operator!=(const HashTableOpnAdr<Data> &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from HashTable)
    void Resize(const ulong) noexcept override; // Resize the hashtable to a given size

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)
    virtual void Insert(const Data &) noexcept override; // Override DictionaryContainer member (Copy of the value)
    virtual void Insert(Data &&) noexcept override;      // Override DictionaryContainer member (Move of the value)
    virtual void Remove(const Data &) noexcept override; // Override DictionaryContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from TestableContainer)

    virtual bool Exists(const Data &) const noexcept override; // Override TestableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from MappableContainer)
    using typename MappableContainer<Data>::MapFunctor;
    void Map(MapFunctor, void *) override; // Override MappableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from FoldableContainer)
    using typename FoldableContainer<Data>::FoldFunctor;
    void Fold(FoldFunctor, const void *, void *) const override; // Override FoldableContainer member

    /* ************************************************************************ */

    // Specific member functions (inherited from Container)

    void Clear() override; // Override Container member

  public:
    // Auxiliary member functions

    ulong Find(const Data &) const noexcept;
    ulong FindEmpty(const Data) noexcept;
  };

  /* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
