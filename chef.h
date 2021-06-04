/* Chef Header File */
#pragma once

#include <iostream>

#include "employee.h"

using namespace std;

class Chef : public Employee {
    string empCookExp;

   public:
    Chef(istream &in);
    void calcSalary(double profit);
    void print(ostream &out) const override;

    string getEmpCookExp() { return empCookExp; }
    void setEmpCookExp(string _cook_exp) { empCookExp = _cook_exp; }
};

Chef::Chef(istream &in) : Employee(in) {
    empClass = 'C';
    empSalary = 3000;

    cout << "Chef's cooking experience: ";
    in >> empCookExp;
    cout << endl;
}

void Chef::calcSalary(double profit) { empSalary += profit * 0.2; }

void Chef::print(ostream &out) const {
    Employee::print(out);
    out << "Cooking Experience: " << empCookExp << endl << endl;
}