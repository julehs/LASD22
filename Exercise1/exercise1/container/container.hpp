
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

  ulong dim =0;


public:
  // Destructor

    virtual ~Container() = default;



  // Copy assignment

    Container& operator = (const Container&) = delete; // il copy assignment di un tipo astratto non è possibile



  // Move assignment

    Container& operator = (Container&&) noexcept = delete;
 

  // Comparison operators

    bool operator==(const Container&) const noexcept = delete;
    bool operator!=(const Container&) const noexcept = delete;
  

  // Specific member functions

    virtual bool Empty() const noexcept{

      return (dim==0);
}
  

virtual ulong Size() const noexcept{

  return dim;
}
  
virtual void Clear() = 0;


};

/* ************************************************************************** */

template <typename Data>
class LinearContainer :virtual public Container { // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~LinearContainer() = default;

  

  // Copy assignment

    LinearContainer& operator = (const LinearContainer&)= delete;


  // Move assignment
  
    LinearContainer& operator = (LinearContainer&&) noexcept = delete;

  

  // Comparison operators

    bool operator==(const LinearContainer&) const noexcept = delete;
    bool operator!=(const LinearContainer&) const noexcept = delete;

  

  // Specific member functions
  // Front: returns the first element
  // throws std::length_error when empty
  // pure virtual function, defined later


    virtual Data& Front() = 0; 

  // Back: returns the last element
  // throws std::length_error when empty
  // pure virtual function, defined later


    virtual Data& Back() = 0;
  

  // operator[]: returns the i-th element
  // throws std::out_of_range when out of out_of_range
  // pure virtual function, defined later

    virtual Data&[] operator (const ulong) const = 0;
  
};



template <typename Data>
class TestableContainer :virtual public Container { // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~TestableContainer() = default;


  // Copy assignment

    TestableContainer& operator = (const TestableContainer&)= delete;


  // Move assignment

    TestableContainer& operator = (TestableContainer&&) = delete;
  

  // Comparison operators

    bool operator == (const TestableContainer&) const noexcept = delete;
    bool operator != (const TestableContainer&) const noexcept = delete;


  // Specific member functions
 
  // Exists(): returns true if the container exists, false otherwise
  // pure virtual function, defined later


    virtual bool Exists(const Data&) const noexcept = 0;
  
};


template <typename Data>
class MappableContainer :virtual public Container { // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~MappableContainer() = default;


  // Copy assignment

   MappableContainer& operator = (const MappableContainer&) = delete;
  

  // Move assignment

    MappableContainer& operator = (MappableContainer&&) = delete;

  // Comparison operators

    bool operator == (const MappableContainer&) const noexcept = delete;
    bool operator != (const MappableContainer&) const noexcept = delete;


  // Specific member functions

   typedef std::function<void(Data&, void*)> MapFunctor;

  // type Map(arguments) specifiers;

    virtual void Map(MapFunctor, void*) = 0; 

};


template <typename Data>
class FoldableContainer :virtual public TestableContainer<Data> { // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~FoldableContainer() = default;


  // Copy assignment

    FoldableContainer& operator = (const FoldableContainer&) = delete;


  // Move assignment

    FoldableContainer& operator = (FoldableContainer&&) = delete;


  // Comparison operators

    bool operator == (const FoldableContainer&) const noexcept = delete;
    bool operator != (const FoldableContainer&) const noexcept = delete;
  


  // Specific member functions

     typedef std::function<void(const Data&, const void*, void*)> FoldFunctor;

     virtual void Fold (FoldFunctor, void*) = 0;

  

  // Specific member functions (inherited from TestableContainer)

    bool Exists(const Data&) const noexcept = 0; //l' override di un metodo non necessita del virtual
  
};


template <typename Data>
class PreOrderMappableContainer :virtual public MappableContainer { // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~PreOrderMappableContainer() = default;


  // Copy assignment

    PreOrderMappableContainer& operator = (const PreOrderMappableContainer&) = delete;


  // Move assignment

    PreOrderMappableContainer& operator = (PreOrderMappableContainer&&) = delete;


  // Comparison operators

    bool operator == (const PreOrderMappableContainer&) const noexcept = delete;
    bool operator != (const PreOrderMappableContainer&) const noexcept = delete;
  

  // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPreOrder (MapFunctor, void*) = 0;
  


  // Specific member functions (inherited from MappableContainer)

    void Map (MapFunctor, void*) = 0;

};


template <typename Data>
class PreOrderFoldableContainer { // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~PreOrderFoldableContainer() = default;


  // Copy assignment
    PreOrderFoldableContainer& operator = (const PreOrderFoldableContainer&) = delete;


  // Move assignment
    PreOrderFoldableContainer& operator = (PreOrderFoldableContainer&&) = delete;


  // Comparison operators
    bool operator == (const PreOrderFoldableContainer&) const noexcept = delete;
    bool operator != (const PreOrderFoldableContainer&) const noexcept = delete;
  
  // Specific member functions

     using typename FoldableContainer<Data>::FoldFunctor;

     virtual void FoldPreOrder(FoldFunctor, void*) = 0;


  
  // Specific member functions (inherited from FoldableContainer)

    void Fold (FoldFunctor, void*) = 0;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer :virtual public MappableContainer { // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~PostOrderMappableContainer() = default;


  // Copy assignment

    PostOrderMappableContainer operator = (const PostOrderMappableContainer&) = delete;
  
  // Move assignment

    PostOrderMappableContainer& operator = (PostOrderMappableContainer&&) = delete;

  // Comparison operators

    bool operator==(const PostOrderMappableContainer&) const noexcept = delete;
    bool operator!=(const PostOrderMappableContainer&) const noexcept = delete;
  // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPostOrder(MapFunctor, void*) = 0;



  // Specific member functions (inherited from MappableContainer)

    void Map (MapFunctor, void*) = 0;


};


template <typename Data>
class PostOrderFoldableContainer :virtual public FoldableContainer { // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~PostOrderFoldableContainer() = default;


  // Copy assignment

    PostOrderFoldableContainer operator = (const PostOrderFoldableContainer&) = delete;

  // Move assignment

    PostOrderFoldableContainer operator = (PostOrderFoldableContainer&&) = delete;

  
  
  // Comparison operators

    bool operator == (const PostOrderFoldableContainer&) const noexcept = delete;
    bool operator != (const PostOrderFoldableContainer&) const noexcept = delete;


  // Specific member functions

     using typename FoldableContainer<Data>::FoldFunctor;

     virtual void FoldPostOrder(FoldFunctor, void*) = 0;



  // Specific member functions (inherited from FoldableContainer)

    void Fold (FoldFunctor, void*) = 0;

};


template <typename Data>
class InOrderMappableContainer :virtual public MappableContainer { // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~InOrderMappableContainer() = default;


  // Copy assignment

    InOrderMappableContainer operator = (const InOrderMappableContainer&) = delete;
  
  // Move assignment

    InOrderMappableContainer operator = (InOrderMappableContainer&&) = delete;
  
  // Comparison operators
    
    bool operator == (const InOrderMappableContainer&) const noexcept = delete;
    bool operator != (const InOrderMappableContainer&) const noexcept = delete;


  // Specific member functions

     using typename MappableContainer<Data>::MapFunctor;

     virtual void MapInOrder(MapFunctor, void*) = 0;


  // Specific member functions (inherited from MappableContainer)

    void Map(MapFunctor, void*) = 0;

};



template <typename Data>
class InOrderFoldableContainer :virtual public FoldableContainer<Data>{ // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~InOrderFoldableContainer() = default;


  // Copy assignment
    
    InOrderFoldableContainer operator = (const InOrderFoldableContainer&) = delete;

  // Move assignment

    InOrderFoldableContainer operator = (InOrderFoldableContainer&&) = delete;

  // Comparison operators
    
    bool operator == (const InOrderFoldableContainer) const noexcept =  delete;
    bool operator != (const InOrderFoldableContainer) const noexcept = delete;
  
  
  // Specific member functions

     using typename FoldableContainer<Data>::FoldFunctor;

     virtual void FoldInOrder (FoldFunctor, void*) = 0;

  // Specific member functions (inherited from FoldableContainer)

    void Fold(FoldFunctor, void*) = 0

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
