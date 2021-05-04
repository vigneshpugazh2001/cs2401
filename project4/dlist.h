//vignesh pugazhenthi
//d list class


#ifndef DLIST_H
#define DLIST_H
#include "dnode.h"
#include "iterator.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

template <class T>
class dlist{

    public:
        //constructor
        dlist();

        //big 3
        ~dlist();
        dlist(const T& other); 
        dlist operator = (const T& other);

        //iterator
        typedef node_iterator<T> iterator;
        iterator begin(){return iterator(head);}
        iterator end(){return iterator();}
        iterator r_begin(){return iterator(tail);}
        iterator r_end(){return iterator();}
        void remove(iterator it);
        void insert_before(iterator& it, T item);
        void insert_after(iterator& it, T item);


        //functions
        void front_insert(T item);
        void rear_insert(T item);
        void front_remove();
        void rear_remove();
        void show();
        void reverse_show();
        int size(){return listcounter;}





    private:
        Dnode<T>* head;
        Dnode<T>* tail;
        int listcounter = 0;





};



#include "dlist.template"
#endif