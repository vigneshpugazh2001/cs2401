/***********************************************************************
    This is the headerfile for the checkbook class. This file holds
    the information for a checkbook. It consists of the main functions
    that the user will use and private values that are needed for 
    the program.
  	Vignesh Pugazhenthi, 2/7/2021
************************************************************************/

#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include "check.h"



class Checkbook{

    public:
    //global
    static const size_t CHECKSIZE = 200;

    void load_from_file(std::ifstream &ins);
    void deposit (double deposit);
    void write_check(std::istream &ins);
    double get_balance();
    void show_all (std::ostream &outs);
    void remove (int rmnum);
    void number_sort();
    void payto_sort();
    void date_sort();
    void show(std::string payto_find);
    double average();
    void save(std::ofstream &outs);
    //constructor
    Checkbook();



    private:
    Check checks[CHECKSIZE];
    int holderarr;
    double balance;
    int nextchecknum;
};

