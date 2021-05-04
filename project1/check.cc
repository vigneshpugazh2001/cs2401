/*******************************************************************
    This is the implementation file for the Check class. For more 
information about the class see check.h.
    Students are expected to implement some of the functions shown 
below.
	John Dolan	Ohio University		September 2019
******************************************************************/
#include "check.h"
using namespace std;

Check::Check(Date d, string p, int num, double amt)
{
    checknum = num;
    date = d;
    payto = p;
    amount = amt;
}
// Input and output functions
void Check::write_check(std::istream &ins)
{
    string trash;
    if (&ins == &cin)
    {

        cout << "Enter the Check Date:";
        ins >> date;
        cout << "Enter who the check goes out to: ";
        trash = getchar();
        getline(ins, payto);
        cout << "Enter the amount: ";
        ins >> amount;
    }

    else
    {
        //double junk;
        //ins >> junk;
        ins >> checknum;
        ins >> date;

        getline(ins, payto);
        if (ins.peek() == '\n' || ins.peek() == '\r')
        {
            ins.ignore();
        }
        getline(ins, payto);
        ins >> amount;
    }
}

void Check::output(std::ostream &outs) const
{
    /* You are to write the implementation of this function to write 
	to the monitor or to a file. Remember not to put labels into the 
	file.*/
    if (&outs == &cout)
    {
        outs << "Check number: \t\t" << checknum << endl;
        outs << "Date: \t\t" << date << endl;
        outs << "Payto \t\t" << payto << endl;
        outs << "Amount: \t\t" << amount << endl;
    }
    else
    {
        outs << checknum << endl;
        outs << date << endl;
        outs << payto << endl;
        outs << amount << endl;
    }
}

ostream &operator<<(ostream &outs, const Check &c)
{
    c.output(outs);
    return outs;
}

istream &operator>>(istream &ins, Check &c)
{
    c.write_check(ins);
    return ins;
}
