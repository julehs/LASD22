
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

#include <stdexcept>
#include <functional>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  ulong dim = 0;

public:

  // Destructor
    virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
    Container& operator = (const Container&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    Container& operator = (Container&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.
    bool operator != (const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Empty() const noexcept{  // (concrete function should not throw exceptions)
      return (dim == 0);
  }


virtual ulong Size() const noexcept{  // (concrete function should not throw exceptions)
  
  return dim;
}


  virtual void Clear() = 0;


};

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public Container { // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
    LinearContainer& operator = (const LinearContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    LinearContainer& operator = (LinearContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const LinearContainer&) const noexcept = delete; // Comparison of abstract types is possible.
    bool operator != (const LinearContainer&) const noexcept = delete; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions
    virtual Data& Front() const = 0; // (concrete function must throw std::length_error when empty)
    virtual Data& Back() const = 0;  // (concrete function must throw std::length_error when empty)
    virtual Data& operator[] (const ulong) const = 0; // (concrete function must throw std::out_of_range when out of range)
  

};

/* ************************************************************************** */

template <typename Data>
class TestableContainer: virtual public Container { // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
    TestableContainer& operator = (const TestableContainer& ) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    TestableContainer& operator = (TestableContainer&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const TestableContainer&) const noexcept = delete;// Comparison of abstract types might not be possible.
    bool operator != (const TestableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

    virtual bool Exists(const Data&) const noexcept = 0;  // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class MappableContainer: virtual public Container { // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
    MappableContainer& operator = (const MappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    MappableContainer& operator = (MappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
    bool operator != (const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

   typedef std::function<void(Data&, void*)> MapFunctor;

  // type Map(arguments) specifiers;
    virtual void Map(MapFunctor, void*) = 0;

};

/* ************************************************************************** */

template <typename Data>
class FoldableContainer: virtual public TestableContainer<Data> { // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
    FoldableContainer& operator = (const FoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    FoldableContainer& operator = (FoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
    bool operator != (const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

   typedef std::function<void(const Data&, const void*, void*)> FoldFunctor;

   virtual void Fold(FoldFunctor, const void*, void*) const = 0 ;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

    virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer: virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignmnt
    PreOrderMappableContainer& operator = (const PreOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    PreOrderMappableContainer& operator = (PreOrderMappableContainer&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const PreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
    bool operator != (const PreOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPreOrder(MapFunctor, void*) = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

    virtual void Map(MapFunctor, void*) override; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer: virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
    PreOrderFoldableContainer& operator = (const PreOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    PreOrderFoldableContainer& operator = (PreOrderFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const PreOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
    bool operator != (const PreOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

    using typename FoldableContainer<Data>::FoldFunctor;

    virtual void FoldPreOrder(FoldFunctor, const void*, void*) const = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

    virtual void Fold(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer: MappableContainer<Data> { // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
    PostOrderMappableContainer& operator = (const PostOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    PostOrderMappableContainer& operator = (PostOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const PostOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
    bool operator != (const PostOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPostOrder (MapFunctor, void*) = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

    virtual Map(MapFunctor, void*) override; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer:virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
    PostOrderFoldableContainer& operator = (const PostOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldPostOrder(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // type Fold(argument) specifiers; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer { // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename MappableContainer<Data>::MapFunctor;

  // type MapInOrder(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer { // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderFoldableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldInOrder(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // type Fold(argument) specifiers; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer { // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename MappableContainer<Data>::MapFunctor;

  // type MapBreadth(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer { // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthFoldableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldBreadth(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // type Fold(argument) specifiers; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "container.cpp"

#endif