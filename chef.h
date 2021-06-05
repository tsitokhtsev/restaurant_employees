/* Chef Header File */
#pragma once
#include <iostream>
#include "employee.h"

using namespace std;

class Chef : public Employee {
    string empCookExp;

   public:
    Chef(istream &in);

    void print(ostream &out) const override;
    void calcSalary(double profit);

    string getEmpCookExp() { return empCookExp; }
    void setEmpCookExp(string _cook_exp) { empCookExp = _cook_exp; }
};

Chef::Chef(istream &in) : Employee(in) {
    empClass = 'C';
    empSalary = 3000;

    cout << "Chef's cooking experience: ";
    in >> empCookExp;

    cout << "*New chef created*\n\n";
}

void Chef::print(ostream &out) const {
    Employee::print(out);
    out << "Employee Class: Chef\n"
        << "Salary: " << empSalary << " GEL\n"
        << "Cooking Experience: " << empCookExp << "\n\n";
}

void Chef::calcSalary(double profit) { empSalary += profit * 0.2; }