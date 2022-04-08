
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

  // Copy assignment

    Container& operator = (const Container&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment

    Container& operator = (Container&&) noexcept = delete; // Move assignment of abstract types should not be possible.
 
  // Comparison operators
  //of abstract types might not be possible.

    bool operator == (const Container&) const noexcept = delete;
    bool operator != (const Container&) const noexcept = delete;
  

  // Specific member functions

    virtual bool Empty() const noexcept{

      return (dim == 0);
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

    LinearContainer& operator = (const LinearContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  
    LinearContainer& operator = (LinearContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  //of abstract types might not be possible.

    bool operator == (const LinearContainer&) const noexcept = delete;
    bool operator != (const LinearContainer&) const noexcept = delete;

  // Specific member functions

    virtual Data& Front() const = 0; // Front: returns the first element, throws std::length_error when empty

    virtual Data& Back() const = 0; // Back: returns the last element, throws std::length_error when empty
  
    virtual Data&[] operator (const ulong) const = 0; // operator[]: returns the i-th element, throws std::out_of_range when out of out_of_range
  
  
};

/* ************************************************************************** */

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

    TestableContainer& operator = (const TestableContainer&)= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment

    TestableContainer& operator = (TestableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.
  
  // Comparison operators
  //of abstract types might not be possible.

    bool operator == (const TestableContainer&) const noexcept = delete;
    bool operator != (const TestableContainer&) const noexcept = delete;

  // Specific member functions
 
    virtual bool Exists(const Data&) const noexcept = 0; // Exists(): returns true if the container exists, false otherwise
  
};

/* ************************************************************************** */


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

    MappableContainer& operator = (const MappableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  
  // Move assignment

    MappableContainer& operator = (MappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  //of abstract types might not be possible.

    bool operator == (const MappableContainer&) const noexcept = delete;
    bool operator != (const MappableContainer&) const noexcept = delete;

  // Specific member functions

   typedef std::function<void(Data&, void*)> MapFunctor;

  // type Map(arguments) specifiers;

    virtual void Map(MapFunctor, void*) = 0; 

};

/* ************************************************************************** */


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

    FoldableContainer& operator = (const FoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment

    FoldableContainer& operator = (FoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  //of abstract types might not be possible.

    bool operator == (const FoldableContainer&) const noexcept = delete;
    bool operator != (const FoldableContainer&) const noexcept = delete;
  
  // Specific member functions

     typedef std::function<void(const Data&, const void*, void*)> FoldFunctor;

     virtual void Fold (FoldFunctor, void*) = 0;

  // Specific member functions (inherited from TestableContainer)

    virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member
  
};

/* ************************************************************************** */


template <typename Data>
class PreOrderMappableContainer :virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~PreOrderMappableContainer() = default;

  // Copy assignment

    PreOrderMappableContainer& operator = (const PreOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment

    PreOrderMappableContainer& operator = (PreOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  //of abstract types might not be possible.

    bool operator == (const PreOrderMappableContainer&) const noexcept = delete;
    bool operator != (const PreOrderMappableContainer&) const noexcept = delete;
  

  // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPreOrder (MapFunctor, void*) = 0;
  
  // Specific member functions (inherited from MappableContainer)

    virtual void Map (MapFunctor, void*) const noexcept override; // Override MappableContainer member

};

/* ************************************************************************** */


template <typename Data>
class PreOrderFoldableContainer :virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
    virtual ~PreOrderFoldableContainer() = default;

  // Copy assignment
    PreOrderFoldableContainer& operator = (const PreOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
    PreOrderFoldableContainer& operator = (PreOrderFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  //of abstract types might not be possible.
  
    bool operator == (const PreOrderFoldableContainer&) const noexcept = delete;
    bool operator != (const PreOrderFoldableContainer&) const noexcept = delete;
  
  // Specific member functions

     using typename FoldableContainer<Data>::FoldFunctor;

     virtual void FoldPreOrder(FoldFunctor, void*) = 0;

  // Specific member functions (inherited from FoldableContainer)

    virtual void Fold (FoldFunctor, void*) const noexcept override; //Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer :virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~PostOrderMappableContainer() = default;

  // Copy assignment

    PostOrderMappableContainer& operator = (const PostOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment

    PostOrderMappableContainer& operator = (PostOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  //of abstract types might not be possible.

    bool operator == (const PostOrderMappableContainer&) const noexcept = delete;
    bool operator != (const PostOrderMappableContainer&) const noexcept = delete;

  // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPostOrder(MapFunctor, void*) = 0;

  // Specific member functions (inherited from MappableContainer)

    virtual void Map (MapFunctor, void*) const noexcept override; //Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer :virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor

    virtual ~PostOrderFoldableContainer() = default;

  // Copy assignment

    PostOrderFoldableContainer& operator = (const PostOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment

    PostOrderFoldableContainer& operator = (PostOrderFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  //of abstract types might not be possible.

    bool operator == (const PostOrderFoldableContainer&) const noexcept = delete;
    bool operator != (const PostOrderFoldableContainer&) const noexcept = delete;

  // Specific member functions

     using typename FoldableContainer<Data>::FoldFunctor;

     virtual void FoldPostOrder(FoldFunctor, void*) = 0;

  // Specific member functions (inherited from FoldableContainer)

    virtual void Fold (FoldFunctor, void*) const noexcept override; //Override FoldableContainer member

};

/* ************************************************************************** */


// template <typename Data>
// class InOrderMappableContainer :virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>

// private:

//   // ...

// protected:

//   // ...

// public:

//   // Destructor

//     virtual ~InOrderMappableContainer() = default;

//   // Copy assignment

//     InOrderMappableContainer& operator = (const InOrderMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  
//   // Move assignment

//     InOrderMappableContainer& operator = (InOrderMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

//   // Comparison operators
//   //of abstract types might not be possible.
    
//     bool operator == (const InOrderMappableContainer&) const noexcept = delete;
//     bool operator != (const InOrderMappableContainer&) const noexcept = delete;


//   // Specific member functions

//      using typename MappableContainer<Data>::MapFunctor;

//      virtual void MapInOrder(MapFunctor, void*) = 0;

//   // Specific member functions (inherited from MappableContainer)

//     virtual void Map (MapFunctor, void*) const noexcept override; //Override MappableContainer member

// };

/* ************************************************************************** */


// template <typename Data>
// class InOrderFoldableContainer :virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>

// private:

//   // ...

// protected:

//   // ...

// public:

//   // Destructor
//     virtual ~InOrderFoldableContainer() = default;

//   // Copy assignment
    
//     InOrderFoldableContainer& operator = (const InOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  
//   // Move assignment

//     InOrderFoldableContainer& operator = (InOrderFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.
  
//   // Comparison operators
//   //of abstract types might not be possible.
    
//     bool operator == (const InOrderFoldableContainer&) const noexcept =  delete;
//     bool operator != (const InOrderFoldableContainer&) const noexcept = delete;
  
//   // Specific member functions

//      using typename FoldableContainer<Data>::FoldFunctor;

//      virtual void FoldInOrder (FoldFunctor, void*) = 0;

//   // Specific member functions (inherited from FoldableContainer)

//     virtual void Fold(FoldFunctor, void*) const noexcept override; //Override MappableContainer member

// };

/* ************************************************************************** */

// template <typename Data>
// class BreadthMappableContainer :virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>

// private:

//   // ...

// protected:

//   // ...

// public:

//   // Destructor
//     virtual ~BreadthMappableContainer() = default;

//   // Copy assignment

//     BreadthMappableContainer& operator = (const BreadthMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  
//   // Move assignment

//     BreadthMappableContainer& operator = (BreadthMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.
  
//   // Comparison operators
//   //of abstract types might not be possible.
  
//      bool operator == (const BreadthMappableContainer&) const noexcept = delete;
//      bool operator != (const BreadthMappableContainer&) const noexcept = delete;

//   // Specific member functions

//     using typename MappableContainer<Data>::MapFunctor;

//     virtual void MapBreadth(MapFunctor, void*) = 0;

//   // Specific member functions (inherited from MappableContainer)

//     virtual void Map (MapFunctor, void*) const noexcept override; //Override MappableContainer member


// };

/* ************************************************************************** */

// template <typename Data>
// class BreadthFoldableContainer :virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>

// private:

//   // ...

// protected:

//   // ...

// public:

//   // Destructor

//     virtual ~BreadthFoldableContainer() = default;

//   // Copy assignment
    
//     BreadthFoldableContainer& operator = (const BreadthFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  
//   // Move assignment

//     BreadthFoldableContainer& operator = (BreadthFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.
  
//   // Comparison operators
//   //of abstract types might not be possible.
  
//     bool operator == (const BreadthFoldableContainer&) const noexcept = delete;
//     bool operator != (const BreadthFoldableContainer&) const noexcept = delete;

//   // Specific member functions

//     using typename FoldableContainer<Data>::FoldFunctor;

//     virtual void FoldBreadth(FoldFunctor, void*) = 0;


//   // Specific member functions (inherited from FoldableContainer)
     
//      virtual void Fold (FoldFunctor, void*) const noexcept override; //Override FoldableContainer member
// };


}

#include "container.cpp"

#endif
