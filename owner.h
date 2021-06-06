/* Owner Header File */
#pragma once
#include "employee.h"

class Owner : public Employee {
   public:
    Owner(istream &in);

    void print(ostream &out) const override;
    void calcSalary(const double budget, const double profit) override;
};

Owner::Owner(istream &in) : Employee(in) {
    empClass = 'O';
    empSalary = 5000;

    cout << "*New owner created*\n" << endl;
}

void Owner::print(ostream &out) const {
    Employee::print(out);

    if (moneyGained > 0) {
        out << " + " << moneyGained
            << " GEL (profit) = " << empSalary + moneyGained << " GEL\n\n";
    } else
        out << "\n\n";
}

void Owner::calcSalary(const double budget, const double profit) {
    if (budget < SALARY_BUDGET || profit < 0) {
        Employee::calcSalary(budget, profit);
    } else {
        moneyGained = profit * 0.6;
    }
}