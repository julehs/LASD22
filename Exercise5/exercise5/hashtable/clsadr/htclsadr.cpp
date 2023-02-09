
namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr() noexcept
  {
    table = Vector<BST<Data>>(sizeHT);
  }
  // Specific Constructor

  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(const ulong newsize)
  {
    sizeHT = newsize;
    table = Vector<BST<Data>>(sizeHT);
  }

  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data> &lc)
  {
    sizeHT = lc.Size();
    table = Vector<BST<Data>>(sizeHT);

    for (ulong i = 0; i < sizeHT; i++)
    {
      Insert(lc[i]);
    }
  }

  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(const ulong newsize, const LinearContainer<Data> &lc)
  {
    sizeHT = newsize;
    table = Vector<BST<Data>>(sizeHT);

    for (ulong i = 0; i < lc.Size(); i++)
    {
      Insert(lc[i]);
    }
  }

  /* ************************************************************************ */

  // Copy Constructor
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> &htClsAdr) noexcept
  {
    if (htClsAdr.dim != 0)
    {
      sizeHT = htClsAdr.sizeHT;
      table = Vector<BST<Data>>(sizeHT);
      a = htClsAdr.a;
      b = htClsAdr.b;
      for (ulong i = 0; i < sizeHT; i++)
      {
        if (htClsAdr.table[i].Size() != 0)
        {
          BTInOrderIterator<Data> it(htClsAdr.table[i]);
          while (!it.Terminated())
          {
            Insert(it.operator*());
            it.operator++();
          }
        }
      }
    }
    else
    {
      Clear();
    }
  }

  // Move Constructor
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data> &&htClsAdr) noexcept
  {
    std::swap(table, htClsAdr.table);
    std::swap(dim, htClsAdr.dim);
    std::swap(sizeHT, htClsAdr.sizeHT);
    std::swap(a, htClsAdr.a);
    std::swap(b, htClsAdr.b);
  }

  /* ************************************************************************ */

  // Copy Assignment
  template <typename Data>
  HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> &htClsAdr) noexcept
  {
    HashTableClsAdr<Data> *tmp = new HashTableClsAdr(htClsAdr);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
  }

  // Move Assignment
  template <typename Data>
  HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(HashTableClsAdr &&htClsAdr) noexcept
  {
    std::swap(table, htClsAdr.table);
    std::swap(dim, htClsAdr.dim);
    std::swap(sizeHT, htClsAdr.sizeHT);
    std::swap(a, htClsAdr.a);
    std::swap(b, htClsAdr.b);

    return *this;
  }

  /* ************************************************************************ */

  // Comparision operators
  template <typename Data>
  bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &htClsAdr) const noexcept
  {
    if (dim != htClsAdr.dim)
      return false;
    else
    {
      for (ulong i = 0; i < sizeHT; i++)
      {
        if (table[i].Size() != 0)
        {
          BTInOrderIterator<Data> it(table[i]);
          while (!it.Terminated())
          {
            if (!htClsAdr.Exists(it.operator*()))
              return false;

            it.operator++();
          }
        }
      }
      return true;
    }
  }

  template <typename Data>
  bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data> &htClsAdr) const noexcept
  {
    return !(*this == htClsAdr);
  }

  // Specific Member Function (inherited from HashTable)

  template <typename Data>
  void HashTableClsAdr<Data>::Resize(const ulong newdim) noexcept
  {
    HashTableClsAdr<Data> tmp(newdim);
    for (ulong i = 0; i < sizeHT; i++)
    {
      if (table[i].Size() != 0)
      {
        BTInOrderIterator<Data> it(table[i]);
        while (!it.Terminated())
        {
          tmp.Insert(it.operator*());
          it.operator++();
        }
      }
    }
    std::swap(*this, tmp);
  }
  /* ************************************************************************** */
  // Specific member functions (inherited from DictionaryContainer)

  // TODO

  // Insert Copy
  template <typename Data>
  void HashTableClsAdr<Data>::Insert(const Data &data) noexcept
  {
    ulong key = HashKey(hash(data));

    if (!Exists(data))
    {
      table[key].Insert(data);
      dim++;
    }
  }

  // Insert Move
  template <typename Data>
  void HashTableClsAdr<Data>::Insert(Data &&data) noexcept
  {
    ulong key = HashKey(hash(data));

    if (!Exists(data))
    {
      table[key].Insert(std::move(data));
      dim++;
    }
  }

  // Remove
  template <typename Data>
  void HashTableClsAdr<Data>::Remove(const Data &data) noexcept
  {
    ulong key = HashKey(hash(data));
    if (table[key].Exists(data))
    {
      table[key].Remove(data);
      dim--;
    }
  }

  /* ************************************************************************** */

  // Specific member functions (inherited from TestableContainer)

  // Exists
  template <typename Data>
  bool HashTableClsAdr<Data>::Exists(const Data &data) const noexcept
  {
    for (ulong i = 0; i < sizeHT; i++)
    {
      if (table[i].Size() != 0)
      {
        BTInOrderIterator<Data> it(table[i]);
        while (!it.Terminated())
        {
          if (it.operator*() == data)
            return true;
          else
            it.operator++();
        }
      }
    }
    return false;
  }

  /* ************************************************************************** */

  // Specific member functions (inherited from MappableContainer & FoldableContainer)

  // Map
  template <typename Data>
  void HashTableClsAdr<Data>::Map(MapFunctor fun, void *par)
  {
    for (ulong i = 0; i < sizeHT; i++)
    {
      table[i].MapPreOrder(fun, par);
    }
  }

  // Fold

  template <typename Data>
  void HashTableClsAdr<Data>::Fold(FoldFunctor fun, const void *par, void *acc) const
  {
    for (ulong i = 0; i < sizeHT; i++)
    {
      table[i].FoldPreOrder(fun, par, acc);
    }
  }

  // Specific member functions (inherited from Container)

  // Clear
  template <typename Data>
  void HashTableClsAdr<Data>::Clear() noexcept
  {
    for (ulong i = 0; i < sizeHT; i++)
    {
      if (table[i].Size() != 0)
      {
        table[i].Clear();
      }
    }
    dim = 0;
  }
  /* ************************************************************************** */
}
