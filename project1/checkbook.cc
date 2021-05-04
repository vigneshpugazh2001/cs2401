/***********************************************************************
    This is the implementation file for the check class, it holds the
    check, the position of the array which keeps track of how many
    checks are stored, the balance and the next check 
    number. It also holds the functions used witin the main program
  	Vignesh Pugazhenthi, 2/7/2021
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "checkbook.h"
#include "check.h"
using namespace std;

Checkbook::Checkbook(){
    holderarr = 0;
    balance = 0;
    nextchecknum = 1;
}

void Checkbook::load_from_file(std::ifstream &ins){

Check temp; //its gonna take all the checks from a file

ins >> balance;
ins >> nextchecknum;


while (!ins.eof())
{
    ins >> temp;
    checks[holderarr] = temp; //put it into the check array 
   cout << checks[holderarr];
      holderarr++;
      
}

}
void Checkbook::deposit(double deposit){
    balance = deposit + balance;
    cout << balance << endl;
}

void Checkbook::write_check(std::istream &ins){
    Check checknuminsert;
    
    checknuminsert.set_check_num(nextchecknum);
    checknuminsert.write_check(ins);
    balance = balance - checks[holderarr].get_amount();
    checks[holderarr] = checknuminsert;

    cout << checks[holderarr] << endl;
    holderarr++;
    nextchecknum++;
}

double Checkbook::get_balance(){
    return balance;
}
void Checkbook::show_all(ostream &outs){
    for (int i = 0; i < holderarr; i++)
    {
        cout << checks[i];
    }
    cout << "show all checks: " << endl;
}

void Checkbook::remove(int rmnum){
    Check checknum;
    
    for (int i = 0; i < holderarr; i++)
    {
        if (checks[i].get_num() == rmnum)
        {
        holderarr = holderarr - 1;

        for (int j = i; j<holderarr; j++)
        {
          checks[j] = checks[j+1];
        }

        }
    }
}

void Checkbook::number_sort(){
    Check temp;
    int j;
    bool done = false;

    while(!done)
    {
        done = true;
        for (j = holderarr - 1; j > 0; j--)
        {
            if(checks[j].get_num() < checks[j-1].get_num())
            {
                done = false;
                temp = checks[j];
                checks[j] = checks[j-1];
                checks[j-1] = temp;
            }
        }
    }
}
void Checkbook::payto_sort(){
    Check temp;
    int j;
    bool done = false;

    while(!done)
    {
        done = true;
        for (j = holderarr - 1; j > 0; j--)
        {
            if(checks[j].get_payto() < checks[j-1].get_payto())
            {
                done = false;
                temp = checks[j];
                checks[j] = checks[j-1];
                checks[j-1] = temp;
            }
        }
    }
}
void Checkbook::date_sort(){
    Check temp;
    int j;
    bool done = false;

    while(!done)
    {
        done = true;
        for (j = holderarr - 1; j > 0; j--)
        {
            if(checks[j].get_date() < checks[j-1].get_date())
            {
                done = false;
                temp = checks[j];
                checks[j] = checks[j-1];
                checks[j-1] = temp;
            }
        }
    }
}
void Checkbook::show(std::string payto_find){
    double amount;
for (int i = 0; i < holderarr; ++i)
    {
        if (checks[i].get_payto() == payto_find)
        {
            amount += checks[i].get_amount();
            cout << checks[i];
        }
        
    }
    
}
double Checkbook::average(){
     double average;
     double amount;
    for (int i = 0; i < holderarr; ++i)
    {
        amount += checks[i].get_amount();
    }
    average = amount/holderarr;
    return average;
}
void Checkbook::save(std::ofstream &outs){
    outs << balance << endl;
    outs << nextchecknum << endl;
    for(int i = 0; i < holderarr - 1; ++i)
        {
            outs << checks[i].get_num() <<  endl;
            outs << checks[i].get_date() << endl;
            outs << checks[i].get_payto() << endl;
            outs << checks[i].get_amount() << endl;
        }
}
