/***********************************************************************
	The implementation file for the waiting class that allows 
    all the main including the functions that the user uses.
	
	Vignesh Pugazhenthi			3/9/2021
		
*************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "waiting.h"
#include "appointment.h"
#include "node.h"

Waiting::Waiting()
{
    head = NULL;
}
Waiting::~Waiting()
{
    node *removepointer;
    while (head != NULL)
    {
        removepointer = head;
        head = head->link();
        delete removepointer;
    }
}
Waiting::Waiting(const Waiting &other)
{
    if (other.head == NULL)
    {
        head = NULL;
    }
    else
    {
        head = new node(other.head->data());
        node *dest = other.head->link(); //destination
        node *srcptr = head;             //source ptr
        while (dest != NULL)
        {
            srcptr->set_link(new node(dest->data()));
            srcptr = srcptr->link();
            dest = dest->link();
        }
    }
}
Waiting Waiting::operator=(const Waiting &other)
{
    if (this == &other)
    {
        return *this;
    }

    if (other.head == NULL)
    {
        head = NULL;
    }

    else
    {
        head = new node(other.head->data());
        node *dest = other.head->link(); //destination
        node *srcptr = head;             //source ptr
        while (dest != NULL)
        {
            srcptr->set_link(new node(dest->data()));
            srcptr = srcptr->link();
            dest = dest->link();
        }
        delete dest;
    }
}

void Waiting::add(Appointment item)
{
    if (head == NULL)
        head = new node(item);
    else
    {
        node *cursor = head;
        while (cursor->link() != NULL)
        {
            cursor = cursor->link();
        }
        cursor->set_link(new node(item));
    }
}
void Waiting::display(std::ostream &outs)
{
    node *cursor = head;
    if (head == NULL)
    {
        cout << "List does not exist" << endl;
    }

    while (cursor != NULL)
    {
        cout << cursor->data() << endl; //output cursor data
        cursor = cursor->link();
    }
}
void Waiting::remove(string name)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->data().get_name() == name)
    {
        node *temp;
        temp = head;
        head = head->link();
        delete temp;
    }
    else
    {
        node *cursor = head->link();
        node *prev = head;

        while (cursor != NULL && cursor->data().get_name() != name)
        {
            prev = cursor;
            cursor = cursor->link();
        }
        if (cursor != NULL)
        {
            prev->set_link(cursor->link());
            delete cursor;
        }
    }
}
node *Waiting::find(string name)
{
    node *cursor = head;
    while (cursor != NULL)
    {
        if (cursor->data().get_name() == name)
        {
            return cursor;
        }
        cursor = cursor->link();
    }
    return NULL;
}

int Waiting::waiting()
{
    node *cursor = head;
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    while (cursor != NULL)
    {
        count++;
        cursor = cursor->link();
    }
    return count;
}
unsigned Waiting::longest_wait() const
{
    unsigned num;
    num = head->data().minutes_waiting();
    return num;
}
unsigned Waiting::average_wait() const
{
    unsigned patients = 0;
    unsigned num = 0;

    node *cursor = head;
    while (cursor != NULL)
    {
        num += cursor->data().minutes_waiting();
        patients++;
        cursor = cursor->link();
    }
    num = num / patients;
    return num;
}
int Waiting::oldest() const
{
    Date tday;
    tday.make_today();
    int old = INT_MIN;
    for (node *cursor = head; cursor != NULL; cursor = cursor->link())
    {
        if (cursor->data().age(tday) > old)
        {
            old = cursor->data().age(tday);
        }
    }
    return old;
}

int Waiting::youngest() const
{
    Date tday;
    tday.make_today();
    int min = INT_MAX;
    for (node *cursor = head; cursor != NULL; cursor = cursor->link())
    {
        if (cursor->data().age(tday) < min)
        {
            min = cursor->data().age(tday);
        }
    }
    return min;
}

unsigned Waiting::average_age() const
{
    Date tday;
    node *cursor = head;
    tday.make_today();
    int count = 0;
    int avg = 0;
    while (cursor != NULL)
    {
        avg += cursor->data().age(tday);
        count++;
        cursor = cursor->link();
    }
    avg = avg / count;
    return avg;
}

void Waiting::load(istream &ins)
{
    Appointment tmp;
    node *cursor;
    int i = 0;

    ins >> tmp;
    while (!ins.eof())
    {
        while (ins.peek() == '\r' || ins.peek() == '\n')
        {
            ins.ignore();
        }

        if (head == NULL)
        {
            head = new node;
            cursor = head;
            cursor->set_data(tmp);
        }
        else
        {
            cursor->set_link(new node);
            cursor = cursor->link();
            cursor->set_data(tmp);
        }
        ins >> tmp;
        i++;
    }
}

void Waiting::save(ostream &outs)
{
    node *cursor;
    cursor = head;

    if (head == NULL)
    {
        cout << "Cannot be saved" << endl;
    }

    while (cursor != NULL)
    {
        outs << cursor->data();
        outs;
        cursor = cursor->link();
    }
}