//vignesh pugazhenthi
//external iterator class

#include "dnode.h"
template <class T> class dlist;

template<class T>
class node_iterator{
    public:

    friend class dlist<T>;
    node_iterator(Dnode<T>* init = NULL) {current = init;}
    T operator*() {return current->data();}
    bool operator != (const node_iterator& other) {return current != other.current;}
    bool operator == (const node_iterator& other) {return current == other.current;}

    node_iterator operator ++(){current = current->next(); return *this;}

    node_iterator operator ++(int)
    {node_iterator original(*this);
    current = current->link();
    return original;
    }

    node_iterator operator --(){current = current->previous(); return *this;}

    node_iterator operator --(int)
    {node_iterator original(*this);
    current = current->previous();
    return original;}




    private:
    Dnode<T>* current;

};