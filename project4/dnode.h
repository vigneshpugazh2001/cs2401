//vignesh pugazhenthi
//node class

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#ifndef DNODE_H
#define DNODE_H

template <class T>
class Dnode{
    public:
        //constructor
        //typedef T value_type;
         Dnode(T d, Dnode* p = NULL, Dnode* n = NULL)
         {
             datafield = d;
             previousptr = p;
             nextptr = n;
         }


        Dnode* next() {return nextptr;}
        Dnode* previous() {return previousptr;}
        T data() {return datafield;}

        set_next(Dnode* n) {nextptr = n;}
        set_previous(Dnode* p) {previousptr = p;}
        set_data (T d) {datafield = d;}


    
    private:
        Dnode* nextptr;
        Dnode* previousptr;
        T datafield;
};


#endif
