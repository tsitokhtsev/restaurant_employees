/* Owner Header File */
#pragma once

#include <iostream>

#include "employee.h"

using namespace std;

class Owner : public Employee {
   public:
    Owner(istream &in);

    void virtual print(ostream &out) const;
    void calcSalary(double profit);
};

Owner::Owner(istream &in) : Employee(in) {
    empClass = 'O';
    empSalary = 5000;
    cout << endl;
}

void Owner::calcSalary(double profit) { empSalary += profit * 0.6; }

void Owner::print(ostream &out) const {
    Employee::print(out);
    out << "Employee Class: Owner" << endl
        << "Salary: " << empSalary << " GEL" << endl;
}