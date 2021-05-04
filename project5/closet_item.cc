#include "closet_item.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

void Pants::input(istream& ins){
    if (&cin == &ins)
    {
        cout << "What fabric do you want for your pants? (enter a string)" << endl;
        cin >> fabric;
        cout << "What size of pants do you want (enter a number)" << endl;
        cin >> size;
        cout << "What type of pants do you want to wear (enter a string)" << endl;
        cin >> pants;


    }
    else{
        ins >> fabric;
        ins >> size;
        ins >> pants;
    }
}
void Pants::output(ostream& outs){
    if(&cout == &outs)
    {
    outs << "The fabric you chose was " << fabric << endl;
    outs << "The size of pants you want to wear is " << size << endl;
    outs << "The type of pants you want to wear is " << pants << endl;
    }
    else{
        outs << "1" << endl;
        outs << fabric << endl;
        outs << size << endl;
        outs << pants << endl;
    }
    }

void Shirt::input(istream& ins){
    if (&cin == &ins)
    {
        cout << "What type of fabric do you want for your shirt? (Enter a string) " << endl;
        cin >> fabric;
        cout << "What size shirt do you want? (Small, Medium, Large) " << endl;
        cin >> size;
        cout << "What type of sleeve do you want? (Short sleeve, Long sleeve)" << endl;
        cin >> sleeve;
        cout << "How many shirts do you want? " << endl;
        cin >> amount;

    }
    else {
        ins >> fabric;
        ins >> size;
        ins >> sleeve;
        ins >> amount;
    }
}

void Shirt::output(ostream& outs){
    if (&cout == &outs)
    {
    outs << "The fabric you chose for your shirt was " << fabric << endl;
    outs << "The size of the shirt you want to wear is " << size << endl;
    outs << "The type of sleeve you chose to wear is " << sleeve << endl;
    outs << "The amount of shirts you want is " << amount << endl;
    }

    else{
        outs << "2" << endl;
        outs << fabric << endl;
        outs << size << endl;
        outs << sleeve << endl;
        outs << amount << endl;
    }
}

void Sock::input(istream& ins){
    if (&cin == &ins)
    {
        cout << "What brand of socks do you want to wear " <<  endl;
        cin >> brand;
        cout << "What size socks do you wear (enter a string)" << endl;
        cin >> size;
        cout << "How many socks do you want to wear (enter an integer) " << endl;
        cin >> amount;
    }
    else{
        ins >> brand;
        ins >> size;
        ins >> amount;
    }
}

void Sock::output(ostream& outs){
    if (&cout == &outs)
    {
    outs << "The brand of socks you want to wear is " << brand << endl;
    outs << "The size of socks you want to wear is " << size << endl;
    outs << "The amount of socks you want to wear " << amount << endl;
    }

    else {
        outs << "3" << endl;
        outs << brand << endl;
        outs << size << endl;
        outs << amount << endl;
    }

}

void Shoes::input(istream& ins){
    if (&cin == &ins)
    {
        cout << "What brand of shoes do you want to wear? " << endl;
        cin >> brand;
        cout << "What color do you want your shoes to be? " << endl;
        cin >> color;
        cout << "What size shoes do you wear? (Enter an integer) " << endl;
        cin >> size;
    }
    else{
        ins >> brand;
        ins >> color;
        ins >> size;
    }
}

void Shoes::output(ostream& outs){
    if (&cout == &outs)
    {
    outs << "The brand of shoes you want to wear is " << brand << endl;
    outs << "The color of shoes you want to wear is " << color << endl;
    outs << "The size of shoes you chose is " << size << endl;
    }

    else{
        outs << "4" << endl;
        outs << brand << endl;
        outs << color << endl;
        outs << size << endl;
    }
}

void Companion::input(istream& ins){
    if (&cin == &ins)
    {
        cout << "What's your companion's name? " << endl;
        cin >> name;
        cout << "What type of creature is your companion? (Enter a string) " << endl;
        cin >> creature;
        cout << "How old is your companion? " << endl;
        cin >> age;
    }
    else{
        ins >> name;
        ins >> creature;
        ins >> age;
    }
}

void Companion::output(ostream& outs){
    if (&cout == &outs)
    {
    outs << "The name of your companion is " << name << endl;
    outs << "The type of creature your companion is " << creature << endl;
    outs << "Your companion's age is " << age << " years old" << endl;
    }

    else{
        outs << "5" << endl;
        outs << name << endl;
        outs << creature << endl;
        outs << age << endl;
    }
}