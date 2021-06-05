/* Owner Header File */
#pragma once
#include <iostream>
#include "employee.h"

using namespace std;

class Owner : public Employee {
   public:
    Owner(istream &in);

    void print(ostream &out) const override;
    void calcSalary(double profit);
};

Owner::Owner(istream &in) : Employee(in) {
    empClass = 'O';
    empSalary = 5000;

    cout << "*New owner created*\n" << endl;
}

void Owner::print(ostream &out) const {
    Employee::print(out);
    out << "Employee Class: Owner\n"
        << "Salary: " << empSalary << " GEL\n\n";
}

void Owner::calcSalary(double profit) { empSalary += profit * 0.6; }