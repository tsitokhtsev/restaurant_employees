/* Waiter Header File */
#pragma once

#include <iostream>

#include "employee.h"

using namespace std;

class Waiter : public Employee {
    int empWorkExp;

   public:
    Waiter(istream &in);
    void calcSalary(double profit);
    void print(ostream &out) const override;

    int getEmpWorkExp() { return empWorkExp; }
    void setEmpWorkExp(int _work_exp) { empWorkExp = _work_exp; }
};

Waiter::Waiter(istream &in) : Employee(in) {
    empClass = 'W';
    empSalary = 1000;

    cout << "Waiter's work experience (in years): ";
    in >> empWorkExp;
    cout << endl;
}

void Waiter::calcSalary(double profit) { empSalary += profit; }

void Waiter::print(ostream &out) const {
    Employee::print(out);
    out << "Work Experience: " << empWorkExp << " year(s)" << endl << endl;
}