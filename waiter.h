/* Waiter Header File */
#pragma once
#include <iostream>
#include "employee.h"

using namespace std;

class Waiter : public Employee {
    int empWorkExp;

   public:
    Waiter(istream &in);

    void print(ostream &out) const override;
    void calcSalary(double profit);

    int getEmpWorkExp() { return empWorkExp; }
    void setEmpWorkExp(int _work_exp) { empWorkExp = _work_exp; }
};

Waiter::Waiter(istream &in) : Employee(in) {
    empClass = 'W';
    empSalary = 1000;

    cout << "Waiter's work experience (in years): ";
    in >> empWorkExp;

    cout << "*New waiter created*\n\n";
}

void Waiter::print(ostream &out) const {
    Employee::print(out);
    out << "Employee Class: Chef\n"
        << "Salary: " << empSalary << " GEL\n"
        << "Work Experience: " << empWorkExp << " year(s)\n\n";
}

void Waiter::calcSalary(double profit) { empSalary += profit; }