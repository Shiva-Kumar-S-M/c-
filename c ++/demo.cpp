#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>

using namespace std;

//creation of class and objects...
class teacher {
    // properties / attributes
public:
    // // non parameterized constructor  
    // teacher() {
    //     cout << "Hi i am constructor";
    // }
    string name ;
    string dept;
    string subject;
    double salary;

    //parametraized constructor
    teacher(string name,string dept,string subject,double salary){
        this->name=name;
        this->dept=dept;
        this->subject=subject;
        this->salary=salary;
    }
    
    //methods/member function
    void changeDept( string newDept){
        dept=newDept;
    }

    void getinfo(){
        cout << "Name:"<<name <<endl;
        cout <<"department:"<<dept;
    }
};

// int main() {
//     // cout << "Enter a value:";
//     // int number;
//     // cin >> number;
//     // cout << "Entered value is :" << number;

//     teacher t1;  //calls atomatically
//     t1.name="Shivu";
//     t1.dept="computer science";
//     t1.subject="C++";
//     t1.salary=25000;

//     cout << t1.name << endl;

// }


int main() {
    

    teacher t1("Shivu","CSDS","DBMS",25100);
    // t1.getinfo();
    teacher t2(t1);
    t2.getinfo();

}
//encapsulation  is wrapping up of data and member function in a single unit called class..

// class account {

// private:
//     double balance;
//     string password; //data hiding 
// public :
//     string username;
//     string accountid;
// };


// constructor its a special method invoked automatically at the time of object creation .used for initialisation...
// same name as class
//constructor doesnt have return type
// only called once(automatically) at the time of object creation
// memory allocation happens when constructor is called 
// types 1.non parameteraized ,2.parameteraized,3. copy








// copy contructor is special constructor used to cpoy properties of one object into another.