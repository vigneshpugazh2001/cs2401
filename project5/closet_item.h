//vignesh pugazhenthi
//header file

#ifndef CLOSET_ITEM_H
#define CLOSET_ITEM_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

class Closet_item{
    public:
        virtual void input(istream& ins) = 0;
        virtual void output(ostream& outs) = 0;

    private:

    protected:
};

class Pants:public Closet_item{
    public:
    Pants(){}
    void input(istream& ins);
    void output(ostream& outs);

    private:
    string fabric;
    int size;
    string pants;
    

    protected:
};

 class Shirt:public Closet_item{
     public:
     Shirt(){}
     void input(istream& ins);
     void output(ostream& outs);

     private:
     string fabric;
     string size;
     string sleeve;
     int amount;
 };

 class Sock:public Closet_item{
     public:
     Sock(){}
     void input(istream& ins);
     void output(ostream& outs);

     private:
     string brand;
     string size;
     int amount;
 };

 class Shoes:public Closet_item{
     public:
     Shoes(){}
     void input(istream& ins);
     void output(ostream& outs);

     private:
     string brand;
     string color;
     int size;
 };

 class Companion:public Closet_item{
     public:
     Companion(){}
     void input(istream& ins);
     void output(ostream& outs);

     private:
     string name;
     string creature;
     int age;
 };








#endif