#include "closet_item.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <list>
using namespace std;

int menu();

int main()
{
    ifstream ins;
    ofstream outs;
    string username;
     int choice;
    int code;

    cout << "Enter your username " << endl;
    getline(cin, username);
    username += ".txt";

    ins.open(username.c_str());
    if (ins.fail())
    {
        cout << "New user choose your options: " << endl;
    }

     Closet_item* tmp;
     list <Closet_item*> closet_item;
     
//loading the file

if (!ins.fail())
{
    while (ins >> code)
    {
        switch(code)
        {
            case 1:
            {
                tmp = new Pants;
                tmp->input(ins);
                closet_item.push_back(tmp);
            }
            break;

            case 2:
            {
                tmp = new Shirt;
                tmp->input(ins);
                closet_item.push_back(tmp);
            }
            break;

            case 3:
            {
                 tmp = new Sock;
                tmp->input(ins);
                closet_item.push_back(tmp);
            }
            break;

            case 4:
            {
                tmp = new Shoes;
             tmp->input(ins);
            closet_item.push_back(tmp);
            }
            break;

            case 5:
            {
             tmp = new Companion;
            tmp->input(ins);
            closet_item.push_back(tmp);   
            }
            break;

            default: ins.ignore();
        }
    }
}


 choice = menu();

//user inputs 
     while (choice != 7)
     {

     if (choice == 1){
         tmp = new Pants;
         tmp->input(cin);
         closet_item.push_back(tmp);
     }
     else if (choice == 2){
         tmp = new Shirt;
         tmp->input(cin);
         closet_item.push_back(tmp);
     }
     else if (choice == 3)
     {
         tmp = new Sock;
         tmp->input(cin);
         closet_item.push_back(tmp);
     }
     else if (choice == 4)
     {
         tmp = new Shoes;
         tmp->input(cin);
         closet_item.push_back(tmp);
     }
     else if (choice == 5)
     {
         tmp = new Companion;
         tmp->input(cin);
         closet_item.push_back(tmp);

     }
     else if (choice == 6)
     {
      list<Closet_item*>::iterator it;
      it = closet_item.begin();
      while (it != closet_item.end())
      {
         cout << "\n";
          (*it)->output(cout);
          ++it;
      }
     }
      choice = menu();

     }

     //output to a file
     outs.open(username.c_str());
     list<Closet_item*>::iterator it2;
     it2 = closet_item.begin();
     while (it2 != closet_item.end())
     {
         (*it2)->output(outs);
         ++it2;
     }

    
 }
int menu(){
	int ans;
        cout<<"Enter 1 for Pants\n";
        cout<<"Enter 2 for Shirts\n";
        cout<<"Enter 3 for Socks \n";
        cout<<"Enter 4 for Shoes \n";
        cout<<"Enter 5 for Companion \n";
        cout<<"Enter 6 to show all \n";
        cout <<"Enter 7 to exit program \n";
	cin>>ans;
	return ans;
}
