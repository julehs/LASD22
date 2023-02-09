
namespace lasd
{

  /* ************************************************************************** */

  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr() noexcept
  {
    table.Resize(sizeHT);
    controllerTable.Resize(sizeHT);
    for (ulong i = 0; i < sizeHT; ++i)
    {
      controllerTable[i] = 'E';
    }
  }

  // Specific Constructor
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newdim) noexcept
  {
    sizeHT = newdim;
    table.Resize(sizeHT);
    controllerTable.Resize(sizeHT);
    for (ulong i = 0; i < sizeHT; ++i)
    {
      controllerTable[i] = 'E';
    }
  }

  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data> &lc) noexcept
  {
    sizeHT = lc.Size();
    table.Resize(sizeHT);
    controllerTable.Resize(sizeHT);
    for (ulong i = 0; i < sizeHT; ++i)
    {
      controllerTable[i] = 'E';
    }
    for (ulong i = 0; i < sizeHT; i++)
    {
      Insert(lc[i]);
    }
  }

  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newdim, const LinearContainer<Data> &lc) noexcept
  {
    sizeHT = newdim;
    table.Resize(sizeHT);
    controllerTable.Resize(sizeHT);
    for (ulong i = 0; i < sizeHT; ++i)
    {
      controllerTable[i] = 'E';
    }
    for (ulong i = 0; i < lc.Size(); i++)
    {
      Insert(lc[i]);
    }
  }

  /* ************************************************************************** */
  // Copy Constructor
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data> &htOpnAdr) noexcept
  {

    dim = htOpnAdr.dim;
    sizeHT = htOpnAdr.sizeHT;
    removed = htOpnAdr.removed;
    table.Resize(sizeHT);
    controllerTable.Resize(sizeHT);
    a = htOpnAdr.a;
    b = htOpnAdr.b;
    for (ulong i = 0; i < htOpnAdr.table.Size(); ++i)
    {
      table[i] = htOpnAdr.table[i];
    }
    for (ulong i = 0; i < htOpnAdr.controllerTable.Size(); ++i)
    {
      controllerTable[i] = htOpnAdr.controllerTable[i];
    }
  }

  // Move Constructor
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data> &&htOpnAdr) noexcept
  {
    std::swap(table, htOpnAdr.table);
    std::swap(controllerTable, htOpnAdr.controllerTable);
    std::swap(dim, htOpnAdr.dim);
    std::swap(sizeHT, htOpnAdr.sizeHT);
    std::swap(a, htOpnAdr.a);
    std::swap(b, htOpnAdr.b);
    std::swap(removed, htOpnAdr.removed);
  }

  // Copy Assignment
  template <typename Data>
  HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data> &htOpnAdr) noexcept
  {

    HashTableOpnAdr<Data> *tmp = new HashTableOpnAdr(htOpnAdr);
    std::swap(*this, *tmp);
    delete tmp;

    return *this;
  }

  // Move Assignment
  template <typename Data>
  HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data> &&htOpnAdr) noexcept
  {
    std::swap(table, htOpnAdr.table);
    std::swap(controllerTable, htOpnAdr.controllerTable);
    std::swap(dim, htOpnAdr.dim);
    std::swap(sizeHT, htOpnAdr.sizeHT);
    std::swap(a, htOpnAdr.a);
    std::swap(b, htOpnAdr.b);
    std::swap(removed, htOpnAdr.removed);

    return *this;
  }

  // Comparision operators
  template <typename Data>
  bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data> &htOpnAdr) const noexcept
  {

    if (dim != htOpnAdr.dim)
      return false;
    else
    {
      for (ulong i = 0; i < sizeHT; i++)
      {
        if (controllerTable[i] == 'F')
          if (!(htOpnAdr.Exists(table[i])))
          {
            return false;
          }
      }
    }
    return true;
  }

  template <typename Data>
  bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data> &htOpnAdr) const noexcept
  {
    return !(*this == htOpnAdr);
  }

  /* ************************************************************************** */
  // Specific member functions (inherited from HashTable)

  template <typename Data>
  void HashTableOpnAdr<Data>::Resize(const ulong newdim) noexcept
  {
    HashTableOpnAdr<Data> ht(newdim);

    for (ulong i = 0; i < sizeHT; i++)
    {
      if (controllerTable[i] == 'F')
      {
        ht.Insert(table[i]);
      }
    }
    *this = std::move(ht);
  }

  /* ************************************************************************** */

  // Specific member functions (inherited from DictionaryContainer)

  // Insert Copy
  template <typename Data>
  void HashTableOpnAdr<Data>::Insert(const Data &data) noexcept
  {
    if (dim >= sizeHT / 2)
      Resize(sizeHT * 2);

    // ulong tmp = HashTable<Data>::HashKey(data);
    if (!Exists(data))
    {
      ulong tmp = HashTable<Data>::HashKey(hash(data));
      if (controllerTable[tmp] == 'E' || controllerTable[tmp] == 'R')
      { // if the bucket is empty
        table[tmp] = data;
        controllerTable[tmp] = 'F';
        dim++;
      }
      else if (controllerTable[tmp] == 'F')
      { // collision
        ulong tmp2 = FindEmpty(data);
        table[tmp2] = data;
        controllerTable[tmp2] = 'F';
        dim++;
      }
    }
  }

  // Insert Move
  template <typename Data>
  void HashTableOpnAdr<Data>::Insert(Data &&data) noexcept
  {
    if (dim >= sizeHT / 2)
      Resize(sizeHT * 2);
    if (!Exists(data))
    {
      ulong tmp = HashTable<Data>::HashKey(hash(data));
      if (controllerTable[tmp] == 'E' || controllerTable[tmp] == 'R')
      { // if the bucket is empty
        std::swap(table[tmp], data);
        controllerTable[tmp] = 'F';
        dim++;
      }
      else if (controllerTable[tmp] == 'F')
      { // collision
        ulong tmp2 = FindEmpty(data);
        std::swap(table[tmp2], data);
        controllerTable[tmp2] = 'F';
        dim++;
      }
    }
  }

  // Remove
  template <typename Data>
  void HashTableOpnAdr<Data>::Remove(const Data &data) noexcept
  {
    if (Exists(data))
    {
      ulong tmp = Find(data);
      controllerTable[tmp] = 'R';
      dim--;
      removed++;
      if (removed >= sizeHT / 2)
      {
        Resize(sizeHT / 2);
        removed = 0;
      }
    }
  }

  /* ************************************************************************** */

  // Specific member functions (inherited from TestableContainer)

  // Exists
  template <typename Data>
  bool HashTableOpnAdr<Data>::Exists(const Data &data) const noexcept
  {
    ulong tmp = HashTable<Data>::HashKey(hash(data));
    if (controllerTable[tmp] == 'F' && table[tmp] == data)
    {
      return true;
    }
    ulong offset = tmp + 1;
    for (ulong i = offset; i < sizeHT + offset; i++)
    {
      if (controllerTable[i % sizeHT] == 'F' && table[i % sizeHT] == data)
      {
        return true;
      }
    }
    return false;
  }

  /* ************************************************************************** */

  // Specific member functions (inherited from MappableContainer)

  template <typename Data>
  void HashTableOpnAdr<Data>::Map(MapFunctor fun, void *par)
  {
    for (ulong i = 0; i < dim; i++)
    {
      if (controllerTable[i] == 'F')
      {
        table.MapPreOrder(fun, par);
      }
    }
  }

  /* ************************************************************************** */

  // Specific member functions (inherited from FoldableContainer)

  // Fold
  template <typename Data>
  void HashTableOpnAdr<Data>::Fold(FoldFunctor fun, const void *par, void *acc) const
  {
    for (ulong i = 0; i < dim; i++)
    {
      if (controllerTable[i] == 'F')
      {
        table.FoldPreOrder(fun, par, acc);
      }
    }
  }

  /* ************************************************************************** */

  // Specific member functions (inherited from Container)

  template <typename Data>
  void HashTableOpnAdr<Data>::Clear()
  {
    table.Clear();
    controllerTable.Clear();
    dim = 0;
    table.Resize(sizeHT);
    controllerTable.Resize(sizeHT);
    for (ulong i = 0; i < sizeHT; ++i)
    {
      controllerTable[i] = 'E';
    }
    dim = 0;
  }

  /* ************************************************************************** */

  // Auxiliary member functions
  // TODO Find

  template <typename Data>
  ulong HashTableOpnAdr<Data>::Find(const Data &data) const noexcept
  {
    ulong start = HashTable<Data>::HashKey(hash(data));
    for (ulong i = start; i < sizeHT + start; i++)
    {
      if (controllerTable[i % sizeHT] == 'F' && table[i % sizeHT] == data)
      {
        return i % sizeHT;
      }
    }
    return 0;
  }

  // FindEmpty
  template <typename Data>
  ulong HashTableOpnAdr<Data>::FindEmpty(const Data data) noexcept
  {
    ulong collisionIndex = HashKey(hash(data));
    ulong offset = collisionIndex + 1;
    for (int i = offset; i < sizeHT + offset; i++)
    {
      if (controllerTable[i % sizeHT] == 'E' || controllerTable[i % sizeHT] == 'R')
      {
        return i % sizeHT;
      }
    }
    return collisionIndex;
  }

  /* ************************************************************************** */

}
