/***********************************************************************
Vignesh Pugazhenthi
*************************************************************************/

#include "friend.h"

using namespace std;
// default constructor
Friend::Friend(){
name = "N/A";
bday = Date(1,1,0000);
}
string Friend::get_name() const{
    return name;
}
Date Friend::get_bday() const{
    return bday;
}
bool Friend::operator == (const Friend& other) const{
    if (name == other.get_name() && bday == other.get_bday() )
    {
        return true;
    }

}
bool Friend::operator != (const Friend& other) const{
    if (name == other.get_name() && bday == other.get_bday() )
    {
        return false;
    }
}
void Friend::input(std::istream& ins){

    if (&ins == &cin)
    {
        cout << "Enter the facebook friend name";
        cin >> name;
        cout << "Enter the friends bday";
        cin >> bday;
    }
    else{
        if (ins.peek() == '\n' || ins.peek() == '\r')
        {
            ins.ignore();
        }
    }

}
void Friend::output(std::ostream& outs) const{
    if (&outs == &cout)
    {
        outs << "Facebook Friend: \t\t" << name << endl;
        outs << "Birthday Date: \t\t" << bday << endl;
    }
    else {
        outs << name << endl;
        outs << bday << endl;
    }
}
