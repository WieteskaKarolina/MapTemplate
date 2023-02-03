
#include <iostream>
#include <string>
using namespace std;

class Employee {

    string Name;
    public:
    string Position;
    int Age;
    Employee(): Name(), Position(),Age(0){};
    Employee(const string & n,const string & p, int a): Name(n), Position(p), Age(a){};
    ~Employee(){
       Name.clear();
       Position.clear();
    };
   Employee & operator =(const Employee & a){
       if(&a==this)return  *this;
       else{
           Name= a.Name;
           Position = a.Position;
           Age = a.Age;
       }

       return  *this;

    }
    friend ostream& operator<<(ostream& o, const Employee& v) {

            o << v.Name << ", " << v.Position << ", " << v.Age << endl;


        return o;
    }


};


