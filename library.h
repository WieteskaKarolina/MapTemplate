#include <iostream>
#include <string>
using namespace std;

class Library{
public:
    string Author;
    string Category;
    int Pages;
    int Status;
    Library(): Author(), Category(), Pages(0), Status(1){};
    Library(const string & a,const string & c, int p, int s): Author(a), Category(c), Pages(p), Status(s){};
    ~Library(){
       Author.clear();
       Category.clear();
    };
   Library & operator =(const Library & a){
       if(&a==this)return  *this;
       else{
           Author= a.Author;
           Category = a.Category;
           Pages = a.Pages;
           Status = a.Status;
       }

       return  *this;

    }
    friend ostream& operator<<(ostream& o, const Library& v) {
            o << "---> ";
            o << "autor: " << v.Author << ", kategoria: " << v.Category;
            o << ", liczba stron: " << v.Pages << endl;
            o << "ksiazka aktualnie jest: ";
            if(v.Status == 1)o << "DOSTEPNA" << endl;
            if(v.Status == 0)o << "WYPOZYCZONA" << endl;
        return o;
    }


};
