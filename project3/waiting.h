/***********************************************************************
	The header file for the waiting class that shows all the main including 
    thefunctions that the user uses.
	
	Vignesh Pugazhenthi			3/9/2021
		
*************************************************************************/

#ifndef WAITING_H
#define WAITING_H
#include <iostream>
#include <string>
#include "appointment.h"
#include "node.h"

class Waiting{
    public:
    Waiting(); //default constructor

    ~Waiting(); //big 3
    Waiting(const Waiting &other);
    Waiting operator = (const Waiting &other);

    void add(Appointment item); //main functions
    void display(std::ostream &outs);
    void remove(string name);
    node* find (string name);
    int waiting();
    unsigned longest_wait()const;
    unsigned average_wait()const;
    int oldest()const;
    int youngest()const;
    unsigned average_age()const;
    void load(istream& ins);
    void save(ostream& outs);





    private:
    node* head;
};

#endif