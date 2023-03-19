#include <stdexcept>

namespace lasd
{

    /* ************************************************************************** */

    // Specific constructors
    //inizializza la dimensione del linear container e con il for e inserire l'elemento
    //in una specifica posizione del container
    template <typename Data>
    BST<Data>::BST(const LinearContainer<Data> &con)
    {
        for (ulong i = 0; i < con.Size(); i++)
        {
            Insert(con[i]);
        }
    }

    // Copy constructor
    //prendo un Data template utilizzo di binarytreelnk per sottoalb. sx e dx
    template <typename Data>
    BST<Data>::BST(const BST<Data> &bt) : BinaryTreeLnk<Data>(bt) {}

    // Move constructor
    template <typename Data>
    BST<Data>::BST(BST<Data> &&bt) noexcept : BinaryTreeLnk<Data>(std::move(bt)) {}

    // Copy assignment
    // con l'operatore di assegnamento prendo del bt e lo metto nel binary tree link
    template <typename Data>
    BST<Data> &BST<Data>::operator=(const BST &bt)
    {
        BinaryTreeLnk<Data>::operator=(bt);
        return *this;
    }

    // Move assignment
    template <typename Data>
    BST<Data> &BST<Data>::operator=(BST &&bt) noexcept
    {
        BinaryTreeLnk<Data>::operator=(std::move(bt));
        return *this;
    }

    // Comparision operators
    template <typename Data>
    bool BST<Data>::operator==(const BST &bt) const noexcept
    {
        if (dim == bt.dim)
        {
            if (dim == 0)
                return true;

            BTInOrderIterator<Data> iterThis(*this);
            BTInOrderIterator<Data> iterOther(bt);
            while (!iterThis.Terminated() && !iterOther.Terminated())
            {
                if (*iterThis != *iterOther)
                    return false;
                ++iterThis;
                ++iterOther;
            }
            if (iterThis.Terminated() && iterOther.Terminated())
                return true;
        }
        return false;
    }

    template <typename Data>
    bool BST<Data>::operator!=(const BST &bt) const noexcept
    {
        return !(*this == bt);
    }

    // Specific member functions
    // Min function

    template <typename Data>
    const Data &BST<Data>::Min() const
    {
        if (root == nullptr)
            throw std::length_error("Access to an empty BST.");

        return FindPointerToMin(root)->elem;
    }

    template <typename Data>
    Data BST<Data>::MinNRemove()
    {
        if (root == nullptr)
            throw std::length_error("Access to an empty BST.");

        return DataNDelete(DetachMin(root));
    }

    template <typename Data>
    void BST<Data>::RemoveMin()
    {
        if (root == nullptr)
            throw std::length_error("Access to an empty BST.");

        delete DetachMin(root);
    }

    // Max function
    template <typename Data>
    const Data &BST<Data>::Max() const
    {
        if (root == nullptr)
            throw std::length_error("Access to an empty BST.");

        return FindPointerToMax(root)->elem;
    }

    template <typename Data>
    Data BST<Data>::MaxNRemove()
    {
        if (root == nullptr)
            throw std::length_error("Access to an empty BST.");

        return DataNDelete(DetachMax(root));
    }

    template <typename Data>
    void BST<Data>::RemoveMax()
    {
        if (root == nullptr)
            throw std::length_error("Access to an empty BST.");

        delete DetachMax(root);
    }

    // Predecessor function
    template <typename Data>
    const Data &BST<Data>::Predecessor(const Data &dato) const
    {
        struct BST<Data>::NodeLnk *const *pointer = &FindPointerToPredecessor(root, dato);
        if (*pointer == nullptr)
            throw std::length_error("Predecessor not found.");

        return (*pointer)->elem;
    }

    template <typename Data>
    Data BST<Data>::PredecessorNRemove(const Data &dato)
    {
        struct BST<Data>::NodeLnk **pointer = &FindPointerToPredecessor(root, dato);
        if (&pointer == nullptr)
            throw std::length_error("Predecessor not found.");

        return DataNDelete(Detach(*pointer));
    }

    template <typename Data>
    void BST<Data>::RemovePredecessor(const Data &dato)
    {
        struct BST<Data>::NodeLnk **pointer = &FindPointerToPredecessor(root, dato);
        if (pointer == nullptr)
            throw std::length_error("Predecessor not found.");

        delete Detach(*pointer);
    }

    // Successor function
    template <typename Data>
    const Data &BST<Data>::Successor(const Data &dato) const
    {
        struct BST<Data>::NodeLnk *const *pointer = &FindPointerToSuccessor(root, dato);
        if (pointer == nullptr)
            throw std::length_error("Successor not found.");

        return (*pointer)->elem;
    }

    template <typename Data>
    Data BST<Data>::SuccessorNRemove(const Data &dato)
    {
        struct BST<Data>::NodeLnk **pointer = &FindPointerToSuccessor(root, dato);
        if (pointer == nullptr)
            throw std::length_error("Successor not found.");

        return DataNDelete(Detach(*pointer));
    }

    template <typename Data>
    void BST<Data>::RemoveSuccessor(const Data &dato)
    {
        struct BST<Data>::NodeLnk **pointer = &FindPointerToSuccessor(root, dato);
        if (pointer == nullptr)
            throw std::length_error("Successor not found.");

        delete Detach(*pointer);
    }

    // Specific member function (inherited from DictionaryContainer)

    // Insert Copy
    template <typename Data>
    void BST<Data>::Insert(const Data &dato) noexcept
    {
        struct BST<Data>::NodeLnk *&pointer = FindPointerTo(root, dato);
        if (pointer == nullptr)
        {
            pointer = new struct BST<Data>::NodeLnk(dato);
            dim++;
        }
    }

    // Insert Move
    template <typename Data>
    void BST<Data>::Insert(Data &&dato) noexcept
    {
        struct BST<Data>::NodeLnk *&pointer = FindPointerTo(root, dato);
        if (pointer == nullptr)
        {
            pointer = new struct BST<Data>::NodeLnk(std::move(dato));
            dim++;
        }
    }

    // Remove
    template <typename Data>
    void BST<Data>::Remove(const Data &dato) noexcept
    {
        struct BST<Data>::NodeLnk *&pointer = FindPointerTo(root, dato);
        if (pointer != nullptr)
        {
            delete Detach(FindPointerTo(root, dato));
        }
    }

    // Specific member functions (inherited from TestableContainer)
    template <typename Data>
    bool BST<Data>::Exists(const Data &dato) const noexcept
    {
        return (FindPointerTo(root, dato) != nullptr);
    }

    // Auxiliary member functions
    template <typename Data>
    Data BST<Data>::DataNDelete(struct BST<Data>::NodeLnk *node)
    {
        Data dato;
        std::swap(dato, node->elem);
        delete node;
        return dato;
    }

    template <typename Data>
    struct BST<Data>::NodeLnk *BST<Data>::Detach(struct BST<Data>::NodeLnk *&node) noexcept
    {
        if (node != nullptr)
        {
            if (node->leftchild == nullptr)
                return Skip2Right(node);
            else if (node->rightchild == nullptr)
                return Skip2Left(node);
            else
            {
                struct BST<Data>::NodeLnk *detach = DetachMax(node->leftchild);
                std::swap(node->elem, detach->elem);
                return detach;
            }
        }
        return nullptr;
    }

    template <typename Data>
    struct BST<Data>::NodeLnk *BST<Data>::DetachMin(struct BST<Data>::NodeLnk *&node) noexcept
    {
        return Skip2Right(FindPointerToMin(node));
    }

    template <typename Data>
    struct BST<Data>::NodeLnk *BST<Data>::DetachMax(struct BST<Data>::NodeLnk *&node) noexcept
    {
        return Skip2Left(FindPointerToMax(node));
    }

//SKIP2



    template <typename Data>
    struct BST<Data>::NodeLnk *BST<Data>::Skip2Left(struct BST<Data>::NodeLnk *&node) noexcept
    {
        struct BST<Data>::NodeLnk *skip_left = nullptr;
        if (node != nullptr)
        {
            std::swap(skip_left, node->leftchild);
            std::swap(skip_left, node);
            dim--;
        }
        return skip_left;
    }

    template <typename Data>
    struct BST<Data>::NodeLnk *BST<Data>::Skip2Right(struct BST<Data>::NodeLnk *&node) noexcept
    {
        struct BST<Data>::NodeLnk *skip_right = nullptr;
        if (node != nullptr)
        {
            std::swap(skip_right, node->rightchild);
            std::swap(skip_right, node);
            dim--;
        }
        return skip_right;
    }

    template <typename Data>
    struct BST<Data>::NodeLnk *const &BST<Data>::FindPointerToMin(struct BST<Data>::NodeLnk *const &node) const noexcept
    { // nodelnk const& ??

        struct BST<Data>::NodeLnk *const *pointer = &node;
        struct BST<Data>::NodeLnk *current = node;

        if (current != nullptr)
        {
            while (current->HasLeftChild())
            {
                pointer = &current->leftchild;
                current = current->leftchild;
            }
        }
        return *pointer;

    }

    //il massimo è la foglia a più a destra (ricorda che siamo in un bst)
    template <typename Data>
    struct BST<Data>::NodeLnk *const &BST<Data>::FindPointerToMax(struct BST<Data>::NodeLnk *const &node) const noexcept
    {
        struct BST<Data>::NodeLnk *const *pointer = &node;
        struct BST<Data>::NodeLnk *current = node;

        if (current != nullptr)
        {
            while (current->HasRightChild())
            {
                pointer = &current->rightchild;
                current = current->rightchild;
            }
        }
        return *pointer;
    }

    // unmutable
    template <typename Data>
    struct BST<Data>::NodeLnk *&BST<Data>::FindPointerToMin(struct BST<Data>::NodeLnk *&node) noexcept
    {
        return const_cast<struct BST<Data>::NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
    }

    template <typename Data>
    struct BST<Data>::NodeLnk *&BST<Data>::FindPointerToMax(struct BST<Data>::NodeLnk *&node) noexcept
    {
        return const_cast<struct BST<Data>::NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
    }

    /* ************************************************************************ */

    template <typename Data>
    struct BST<Data>::NodeLnk *const &BST<Data>::FindPointerTo(struct BST<Data>::NodeLnk *const &node, const Data &dato) const noexcept
    { // const&
        struct BST<Data>::NodeLnk *const *pointer = &node;
        struct BST<Data>::NodeLnk *current = node;

        if (current != nullptr)
        {
            while (current != nullptr && current->elem != dato)
            {
                if (current->elem > dato)
                {
                    pointer = &current->leftchild;
                    current = current->leftchild;
                }
                else if (current->elem < dato)
                {
                    pointer = &current->rightchild;
                    current = current->rightchild;
                }
            }
        }
        return *pointer;
    }

    template <typename Data>
    struct BST<Data>::NodeLnk *&BST<Data>::FindPointerTo(struct BST<Data>::NodeLnk *&node, const Data &dato) noexcept
    {
        return const_cast<struct BST<Data>::NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, dato));
    }

    /* ************************************************************************ */
//prendendo due puntatori a nodo uno current e uno canditato controlla se 
// i due nodi sono minori/maggiori e se sono uguali mi riporta alal definizione di predecessore
// ovvero: il più grande del sottoalbero sx (analogamente per successor che sarà il più piccolo a dx)
    template <typename Data>
    struct BST<Data>::NodeLnk *const &BST<Data>::FindPointerToPredecessor(struct BST<Data>::NodeLnk *const &node, const Data &dato) const noexcept
    {

        struct BST<Data>::NodeLnk *const *candidate = nullptr;
        struct BST<Data>::NodeLnk *const *current = &node;

        while (*current != nullptr && (*current)->elem != dato)
        {
            if ((*current)->elem < dato)
            {
                candidate = current;
                current = &((*current)->rightchild);
            }
            else if ((*current)->elem > dato)
                current = &((*current)->leftchild);
        }

        if (*current != nullptr && (*current)->HasLeftChild())
            return FindPointerToMax((*current)->leftchild);

        return *candidate;
    }

    template <typename Data>
    struct BST<Data>::NodeLnk *const &BST<Data>::FindPointerToSuccessor(struct BST<Data>::NodeLnk *const &node, const Data &dato) const noexcept
    {

        struct BST<Data>::NodeLnk *const *candidate = nullptr;
        struct BST<Data>::NodeLnk *const *current = &node;

        while (*current != nullptr && (*current)->elem != dato)
        {
            if ((*current)->elem < dato)
                current = &((*current)->rightchild);
            else if ((*current)->elem > dato)
            {
                candidate = current;
                current = &((*current)->leftchild);
            }
        }

        if (*current != nullptr && (*current)->HasRightChild())
            return FindPointerToMin((*current)->rightchild);

        return *candidate;
    }


// si utilizza lo static cast per castare il risultato ad un riferimento non costante ad un puntatore al nodo di un bst
// il const cast invece per per rimuovere il fatto che sia constante il riferimento 
// cio permette di modificare il nodo 
    template <typename Data>
    struct BST<Data>::NodeLnk *&BST<Data>::FindPointerToPredecessor(struct BST<Data>::NodeLnk *&node, const Data &dato) noexcept
    {
        return const_cast<struct BST<Data>::NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node, dato));
    }

    template <typename Data>
    struct BST<Data>::NodeLnk *&BST<Data>::FindPointerToSuccessor(struct BST<Data>::NodeLnk *&node, const Data &dato) noexcept
    {
        return const_cast<struct BST<Data>::NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, dato));
    }

    /* ************************************************************************** */

}
