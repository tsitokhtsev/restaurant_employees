/* Employee Header File */
#pragma once

#include <iostream>
using namespace std;

class Employee {
   protected:
    string empName;
    int empID;
    char empClass;
    double empSalary;

   public:
    Employee(istream &in);

    virtual void print(ostream &out) const;
    virtual void calcSalary(double profit) = 0;

    /* Getters */
    string getEmpName() const { return empName; }
    int getEmpID() const { return empID; }
    char getEmpClass() const { return empClass; }
    double getEmpSalary() const { return empSalary; }

    /* Setters */
    void setEmpName(string _name) { empName = _name; }
    void setEmpID(int _id) { empID = _id; }
    void setEmpClass(char _class) { empClass = _class; }
    void setEmpSalary(double _salary) { empSalary = _salary; }
};

Employee::Employee(istream &in) {
    cout << "Employee's name: ";
    in >> empName;

    cout << "Employee's ID: ";
    in >> empID;
}

void Employee::print(ostream &out) const {
    out << "Name: " << empName << endl
        << "Employee ID: " << empID << endl;
}