#include <stdio.h>
#include <iostream>
using namespace std;

class Employee{
protected:
    int Salary;
};

class People: public Employee{
public:
    int age;

    People(int n){
        age=n;
    }
     void setSalary(int n){
        Salary=n;
    }
    int getSalary(){
        return Salary;
    }
};

int main(){
    People myob(5);
    myob.setSalary(2000);
    cout<<myob.getSalary()+myob.age;
    return 0;
}
